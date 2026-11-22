// func rrc_key_set @ 0055ebac size=1

undefined4 rrc_key_set(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = 0;
    *param_1 = param_2;
  }
  return uVar1;
}

