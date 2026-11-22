// func uac_hash_size @ 005194c0 size=20

undefined4 uac_hash_size(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}

