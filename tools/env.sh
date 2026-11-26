# Source from bash: source /path/to/ac100-rev/tools/env.sh
# Keep configuration project-local; do not change the login shell or system JDK.
export AC100_REV_ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
export AC100_WORK_DIR="${AC100_WORK_DIR:-$AC100_REV_ROOT/.local/ac100}"
export AC100_ROOTFS="${AC100_ROOTFS:-${AC100_FW:-$AC100_WORK_DIR/rootfs}}"
export AC100_FW="$AC100_ROOTFS"
export AC100_FW_ROOT="${AC100_FW_ROOT:-$AC100_REV_ROOT/firmware}"
export AC100_KERNEL="${AC100_KERNEL:-$AC100_WORK_DIR/openwrt-24.10.0-malta-be-vmlinux-initramfs.elf}"
export AC100_H="${AC100_H:-$AC100_WORK_DIR/harness}"
export AC100_ASM="${AC100_ASM:-$AC100_WORK_DIR/analysis/uac-load1.asm}"
export AC100_FIELDS="${AC100_FIELDS:-$AC100_WORK_DIR/analysis/jcs-fields.tsv}"
export AC100_LUA_FIELDS="${AC100_LUA_FIELDS:-$AC100_WORK_DIR/analysis/lua-jcs-fields.jsonl}"
export CGO_ENABLED=0
export JAVA_HOME="${AC100_JAVA_HOME:-/usr/lib/jvm/java-21-openjdk-amd64}"
export GHIDRA="${GHIDRA:-$HOME/tools/ghidra}"
export PATH="$JAVA_HOME/bin:/usr/sbin:/sbin:$PATH"
mkdir -p -- "$AC100_WORK_DIR/analysis"
if [[ -f "$AC100_WORK_DIR/ap-direct/link.env" ]]; then
    source "$AC100_WORK_DIR/ap-direct/link.env"
fi
