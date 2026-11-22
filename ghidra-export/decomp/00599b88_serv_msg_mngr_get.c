// func serv_msg_mngr_get @ 00599b88 size=88

undefined4 serv_msg_mngr_get(int param_1)

{
  undefined4 uVar1;
  
  if (0x19 < param_1 - 1U) {
    uVar1 = 0;
    if (param_1 - 0x33dd01U < 2) {
      uVar1 = (&g_serv_ie_msg_mngr)[param_1 - 0x33dd01U];
    }
    return uVar1;
  }
  return (&g_serv_msg_mngr)[param_1 - 1U];
}

