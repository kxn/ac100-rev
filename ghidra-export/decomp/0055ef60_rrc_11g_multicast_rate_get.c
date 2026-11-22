// func rrc_11g_multicast_rate_get @ 0055ef60 size=36

undefined4 rrc_11g_multicast_rate_get(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x18c);
    uVar1 = 0;
  }
  return uVar1;
}

