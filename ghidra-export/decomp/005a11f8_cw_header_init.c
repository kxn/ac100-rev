// func cw_header_init @ 005a11f8 size=112

undefined4 cw_header_init(undefined1 *param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (undefined1 *)0x0) {
    memset(param_1,0,0x10);
    *param_1 = 0;
    param_1[2] = 2;
    param_1[1] = 0;
    param_1[5] = 1;
    uVar1 = 0;
    param_1[3] = param_2;
    param_1[4] = param_3;
  }
  return uVar1;
}

