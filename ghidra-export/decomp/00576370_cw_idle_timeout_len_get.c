// func cw_idle_timeout_len_get @ 00576370 size=12

undefined4 cw_idle_timeout_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

