#!/usr/bin/env python3
"""Verify the downloaded AP reporting firmware and reviewed function anchors.

Read-only ELF/ZIP fingerprint checks; no AP, original executable, or production
log is used as a behavior oracle. Semantics are reviewed in ap-reporting-review.md.
"""
import hashlib
import json
import pathlib
import struct
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[1]


class ELF32:
    def __init__(self, path):
        self.data = path.read_bytes()
        assert self.data[:5] == b'\x7fELF\x01', path
        assert self.data[5] in (1, 2), path
        self.endian = '<' if self.data[5] == 1 else '>'
        header = struct.unpack_from(self.endian + '16sHHIIIIIHHHHHH', self.data)
        self.loads = []
        for i in range(header[10]):
            segment = struct.unpack_from(self.endian + '8I', self.data, header[5] + i * header[9])
            if segment[0] == 1:
                self.loads.append((segment[2], segment[1], segment[4]))
        sections = [struct.unpack_from(self.endian + '10I', self.data, header[6] + i * header[11]) for i in range(header[12])]
        names = sections[header[13]]
        names = self.data[names[4]:names[4] + names[5]]
        self.sections = {}
        for section in sections:
            name = names[section[0]:].split(b'\0', 1)[0].decode()
            self.sections[name] = section

    def read(self, address, size):
        for va, offset, length in self.loads:
            if va <= address and address + size <= va + length:
                return self.data[offset + address - va:offset + address - va + size]
        raise ValueError(f'Unmapped address: {address:#x}')

    def section_read(self, name, offset, size):
        section = self.sections[name]
        assert 0 <= offset and offset + size <= section[5], name
        return self.data[section[4] + offset:section[4] + offset + size]

    def u32(self, address):
        return struct.unpack(self.endian + 'I', self.read(address, 4))[0]


def verify():
    manifest = json.loads((ROOT / 'docs/ap-reporting-evidence.json').read_text())
    functions = strings = 0
    for archive in manifest['downloads']:
        data = (ROOT / archive['path']).read_bytes()
        assert hashlib.sha256(data).hexdigest() == archive['sha256'], archive['model']
        with zipfile.ZipFile(ROOT / archive['path']) as package:
            names = [n for n in package.namelist() if n.rsplit('/', 1)[-1] == archive['image_filename']]
            assert len(names) == 1, archive['model']
            image = package.read(names[0])
        assert hashlib.sha256(image).hexdigest() == archive['image_sha256'], archive['model']
        assert image.find(b'hsqs') == archive['squashfs_offset'], archive['model']
    for binary in manifest['binaries']:
        elf = ELF32(ROOT / binary['path'])
        assert hashlib.sha256(elf.data).hexdigest() == binary['sha256'], binary['id']
        for anchor in binary['functions']:
            if 'section' in anchor:
                data = elf.section_read(anchor['section'], int(anchor['offset'], 16), anchor['size'])
            else:
                data = elf.read(int(anchor['address'], 16), anchor['size'])
            assert hashlib.sha256(data).hexdigest() == anchor['sha256'], anchor['name']
            functions += 1
        for ref in binary.get('string_references', []):
            address = (elf.u32(int(ref['literal'], 16)) + int(ref['pc'], 16)) & 0xffffffff
            expected = ref['value'].encode() + b'\0'
            assert elf.read(address, len(expected)) == expected, ref
            strings += 1
    return dict(downloads=len(manifest['downloads']), binaries=len(manifest['binaries']), function_anchors=functions, resolved_field_names=strings, original_code_executed=False)


if __name__ == '__main__':
    print(json.dumps(verify()))
