// func wserv_db_ap_disconnect @ 005f15a4 size=516

int wserv_db_ap_disconnect(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  iVar11 = -1;
  iVar10 = 1;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  do {
    if (param_2 < iVar10) {
      iVar11 = 0;
LAB_005f16f4:
      FUN_00407f30(DAT_007cbef0);
      return iVar11;
    }
    uVar1 = rdmngr_db_generate_rd_id(param_1,iVar10);
    uVar2 = rdmngr_db_generate_rd_idx_by_rd_id(uVar1);
    if ((int)uVar2 < 0) {
LAB_005f16e4:
      if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        pcVar7 = "<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n";
        uVar8 = 0x11d5;
        uVar9 = uVar1;
LAB_005f1798:
        printf(pcVar7,"wserv_db_ap_disconnect",uVar8,uVar9,uVar2);
      }
      goto LAB_005f16f4;
    }
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar5 = apmngr_db_get_sensor_max();
    iVar6 = rdmngr_profile_get_max_rd_per_ap();
    if ((uint)((iVar3 + iVar4 + iVar5) * iVar6) <= uVar2) goto LAB_005f16e4;
    pcVar7 = (char *)(DAT_007cbf04 + uVar2 * 0xc);
    if (*pcVar7 == '\0') {
      if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] has not been used, rd_id[%d]!\r\n";
        uVar8 = 0x11db;
        uVar9 = uVar2;
        uVar2 = uVar1;
        goto LAB_005f1798;
      }
      goto LAB_005f16f4;
    }
    if ((pcVar7[1] == '\0') && (iVar11 = _wserv_rd_del(uVar1), iVar11 != 0)) {
      if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> _wserv_rd_del() fail!\r\n","wserv_db_ap_disconnect",
               0x11e3);
      }
      goto LAB_005f16f4;
    }
    iVar10 = iVar10 + 1;
  } while( true );
}

