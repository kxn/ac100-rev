// func radius_pair_get @ 00449b94 size=64

void radius_pair_get(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x44);
  while( true ) {
    if (((param_2 ^ uVar1) & 0xffff) == 0) {
      if (uVar1 >> 0x10 == param_3) {
        return;
      }
      param_1 = *(int *)(param_1 + 0x150);
    }
    else {
      param_1 = *(int *)(param_1 + 0x150);
    }
    if (param_1 == 0) break;
    uVar1 = *(uint *)(param_1 + 0x44);
  }
  return;
}

