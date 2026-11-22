// func cw_ac_name_len_get @ 0056e8e0 size=20

undefined2 cw_ac_name_len_get(undefined2 *param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_1 != (undefined2 *)0x0) {
    uVar1 = *param_1;
  }
  return uVar1;
}

