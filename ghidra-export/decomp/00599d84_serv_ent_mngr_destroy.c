// func serv_ent_mngr_destroy @ 00599d84 size=140

void serv_ent_mngr_destroy(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &g_serv_ent_mngr;
  iVar2 = g_serv_ent_mngr;
  while( true ) {
    if (iVar2 != 0) {
      while (iVar1 = FUN_004081b0(iVar2 + 4), iVar1 != 0) {
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
      }
      FUN_00407df0(*piVar3);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    if (piVar3 == &g_serv_ie_msg_mngr) break;
    iVar2 = *piVar3;
  }
  return;
}

