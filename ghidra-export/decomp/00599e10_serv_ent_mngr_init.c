// func serv_ent_mngr_init @ 00599e10 size=220

undefined4 serv_ent_mngr_init(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = &g_serv_ent_mngr;
  iVar3 = 0;
  iVar1 = g_serv_ent_mngr;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = FUN_00408450(0x10,0x322);
      *piVar2 = iVar1;
      if (iVar1 == 0) {
        if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[CW_ERROR]%32s():%4d memory malloc failed\n","serv_ent_mngr_init",0x325);
        }
        serv_ent_mngr_destroy();
        return 0xffffffff;
      }
    }
    memset((void *)*piVar2,0,0x10);
    *(short *)*piVar2 = (short)iVar3;
    iVar3 = iVar3 + 1;
    iVar1 = *piVar2;
    piVar2 = piVar2 + 1;
    FUN_0051ad88(iVar1 + 4);
    if (iVar3 == 4) break;
    iVar1 = *piVar2;
  }
  return 0;
}

