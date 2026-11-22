// func serv_msg_mngr_destroy @ 0059996c size=164

void serv_msg_mngr_destroy(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &g_serv_msg_mngr;
  iVar1 = g_serv_msg_mngr;
  while( true ) {
    if (iVar1 != 0) {
      serv_msg_destroy();
      FUN_00407df0(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    if (piVar2 == &capwap_fsm_debug_switch) break;
    iVar1 = *piVar2;
  }
  if (g_serv_ie_msg_mngr != 0) {
    serv_msg_destroy();
    FUN_00407df0(g_serv_ie_msg_mngr);
    g_serv_ie_msg_mngr = 0;
  }
  if (DAT_007c59d4 != 0) {
    serv_msg_destroy();
    FUN_00407df0(DAT_007c59d4);
    DAT_007c59d4 = 0;
  }
  return;
}

