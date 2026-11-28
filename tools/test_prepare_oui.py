#!/usr/bin/env python3
"""Brand alias boundaries, independent of any deployed network identities."""
import unittest
from prepare_oui import brand_for, normalize
from translate_oui import parts

class BrandAliases(unittest.TestCase):
    def test_registered_variants(self):
        for name in ["Beijing Xiaomi Electronics Co., Ltd.", "Beijing Xiaomi Electronics Co.,Ltd", "Xiaomi Communications Co Ltd", "XIAOMI Electronics,CO.,LTD"]:
            self.assertEqual(brand_for(name), "Xiaomi")
        self.assertEqual(brand_for("TP-LINK TECHNOLOGIES CO.,LTD."), "TP-Link")
        self.assertEqual(brand_for("TP-Link Systems Inc."), "TP-Link")
        self.assertEqual(brand_for("Hewlett Packard Enterprise "), "HPE")
        self.assertEqual(brand_for("Hewlett Packard"), "HP")

    def test_similar_names_are_not_same_brand(self):
        for name in ["Invivo Research Inc.", "ViVOtech, Inc.", "Vivotek, Inc.", "Vivo International Corporation Pty Ltd", "SHENZHEN HONOR ELECTRONIC CO.,LTD", "Digitron da Amazonia S/A", "Intelbras", "Huawei Symantec Technologies Co.,Ltd.", "Dongguan Koppo Electronic Co.,Ltd"]:
            self.assertEqual(brand_for(name), "", name)
        self.assertEqual(brand_for("vivo Mobile Communication Co., Ltd."), "vivo")
        self.assertEqual(brand_for("Honor Device Co., Ltd."), "Honor")

    def test_chinese_reference_does_not_change_organization_identity(self):
        pieces, suffix, glossary = parts("Huawei Device Co., Ltd.")
        self.assertEqual(pieces[1], "华为")
        self.assertEqual(suffix, "有限公司")
        self.assertTrue(glossary)
        pieces, suffix, glossary = parts("TAG")
        self.assertEqual(pieces, ["TAG"])
        self.assertEqual(suffix, "")
        self.assertFalse(glossary)
        self.assertEqual(parts("Apple, Inc.")[1], "公司")

if __name__ == '__main__':
    unittest.main()
