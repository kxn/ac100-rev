// func cw_wtp_name_length @ 00585c20 size=20

undefined2 cw_wtp_name_length(undefined2 *param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_1 != (undefined2 *)0x0) {
    uVar1 = *param_1;
  }
  return uVar1;
}

