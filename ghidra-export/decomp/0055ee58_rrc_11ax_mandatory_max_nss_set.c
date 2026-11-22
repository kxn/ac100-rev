// func rrc_11ax_mandatory_max_nss_set @ 0055ee58 size=24

undefined4 rrc_11ax_mandatory_max_nss_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x1a8) = param_2;
  }
  return uVar1;
}

