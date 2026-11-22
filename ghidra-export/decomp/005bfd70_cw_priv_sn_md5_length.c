// func cw_priv_sn_md5_length @ 005bfd70 size=12

undefined4 cw_priv_sn_md5_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x20;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

