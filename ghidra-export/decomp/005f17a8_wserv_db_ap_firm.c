// func wserv_db_ap_firm @ 005f17a8 size=640

undefined4 wserv_db_ap_firm(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  
  iVar12 = 1;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  do {
    if (param_2 < iVar12) {
      uVar11 = 0;
LAB_005f1904:
      FUN_00407f30(DAT_007cbef0);
      return uVar11;
    }
    uVar1 = rdmngr_db_generate_rd_id(param_1,iVar12);
    uVar2 = rdmngr_db_generate_rd_idx_by_rd_id(uVar1);
    if ((int)uVar2 < 0) {
LAB_005f18e4:
      uVar11 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
        pcVar7 = "<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n";
        uVar9 = 0x1208;
        uVar10 = uVar1;
LAB_005f19ec:
        printf(pcVar7,"wserv_db_ap_firm",uVar9,uVar10,uVar2);
      }
      goto LAB_005f1904;
    }
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar5 = apmngr_db_get_sensor_max();
    iVar6 = rdmngr_profile_get_max_rd_per_ap();
    iVar8 = DAT_007cbf04;
    if ((uint)((iVar3 + iVar4 + iVar5) * iVar6) <= uVar2) goto LAB_005f18e4;
    pcVar7 = (char *)(DAT_007cbf04 + uVar2 * 0xc);
    uVar10 = uVar2;
    if (*pcVar7 == '\0') {
      uVar11 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
        pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] has not been used, rd_id[%d]!\r\n";
        uVar9 = 0x120e;
        uVar2 = uVar1;
        goto LAB_005f19ec;
      }
      goto LAB_005f1904;
    }
    if (pcVar7[1] != '\0') {
      uVar11 = 0;
      if ((g_wserv_warning != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
        pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] has been firm, rd_id[%d]!\r\n";
        uVar9 = 0x1213;
        uVar2 = uVar1;
        goto LAB_005f19ec;
      }
      goto LAB_005f1904;
    }
    iVar3 = rdmngr_db_generate_rd_idx_by_rd_id(uVar1);
    iVar4 = rdmngr_profile_get_max_wlan_per_rd();
    iVar8 = wserv_sqlite_notify(0,iVar8 + iVar3 * 0xc + 4,iVar4 * 6 + 4);
    if (iVar8 != 0) {
      if ((g_wserv_warning != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> wserv_sqlite_notify() fail!\r\n","wserv_db_ap_firm",
               0x121a);
      }
      _wserv_rd_del(uVar1);
      uVar11 = 0xffffffff;
      goto LAB_005f1904;
    }
    iVar12 = iVar12 + 1;
    *(undefined1 *)(DAT_007cbf04 + uVar2 * 0xc + 1) = 1;
  } while( true );
}

