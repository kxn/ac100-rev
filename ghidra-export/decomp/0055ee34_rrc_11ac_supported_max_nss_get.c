// func rrc_11ac_supported_max_nss_get @ 0055ee34 size=36

undefined4 rrc_11ac_supported_max_nss_get(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x1a0);
    uVar1 = 0;
  }
  return uVar1;
}

