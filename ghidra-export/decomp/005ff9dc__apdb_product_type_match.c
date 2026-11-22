// func _apdb_product_type_match @ 005ff9dc size=36

uint _apdb_product_type_match(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 < 4) {
    uVar1 = support_product_type_bitmap >> (param_1 & 0x1f) & 1;
  }
  return uVar1;
}

