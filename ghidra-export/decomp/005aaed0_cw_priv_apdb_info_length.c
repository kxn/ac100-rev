// func cw_priv_apdb_info_length @ 005aaed0 size=20

undefined2 cw_priv_apdb_info_length(undefined2 *param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_1 != (undefined2 *)0x0) {
    uVar1 = *param_1;
  }
  return uVar1;
}

