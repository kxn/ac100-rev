// func rdmngr_db_uninit @ 00621204 size=300

undefined4 rdmngr_db_uninit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  if (DAT_007cc64c != 0) {
    FUN_00408360();
    DAT_007cc64c = 0;
  }
  uVar6 = 0;
  if (DAT_007cc650 != 0) {
    while( true ) {
      iVar5 = DAT_007cc65c;
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar3 = apmngr_db_get_sensor_max();
      if ((uint)((iVar1 + iVar2 + iVar3) * iVar5) <= uVar6) break;
      iVar5 = uVar6 * 8;
      piVar4 = (int *)(DAT_007cc650 + iVar5);
      uVar6 = uVar6 + 1;
      if ((*piVar4 == 0) && (piVar4[1] != 0)) {
        FUN_00407df0();
        *(undefined4 *)(DAT_007cc650 + iVar5 + 4) = 0;
      }
    }
    FUN_00407df0(DAT_007cc650);
    DAT_007cc650 = 0;
  }
  if (DAT_007cc654 != 0) {
    FUN_00407df0();
    DAT_007cc654 = 0;
  }
  if (g_rdmngr_db_ptr != 0) {
    FUN_004080b0();
    g_rdmngr_db_ptr = 0;
  }
  g_rdmngr_data = 0;
  return 0;
}

