// func apdb_support_product_type_register @ 00606840 size=48

undefined4 apdb_support_product_type_register(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 4) {
    support_product_type_bitmap = 1 << (param_1 & 0x1f) | support_product_type_bitmap;
    uVar1 = 0;
  }
  return uVar1;
}

