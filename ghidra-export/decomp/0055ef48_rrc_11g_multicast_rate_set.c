// func rrc_11g_multicast_rate_set @ 0055ef48 size=24

undefined4 rrc_11g_multicast_rate_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x18c) = param_2;
  }
  return uVar1;
}

