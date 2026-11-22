// func uac_wservice_ap_del @ 005dd8b0 size=1

int uac_wservice_ap_del(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 auStack_30 [2];
  
  auStack_30[0] = 0xffffffff;
  iVar7 = -1;
  iVar6 = 1;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  do {
    if (param_2 < iVar6) {
      iVar7 = 0;
LAB_005f1b9c:
      FUN_00407f30(DAT_007cbef0);
      return iVar7;
    }
    auStack_30[0] = rdmngr_db_generate_rd_id(param_1,iVar6);
    uVar1 = rdmngr_db_generate_rd_idx_by_rd_id(auStack_30[0]);
    if ((int)uVar1 < 0) {
LAB_005f1b8c:
      if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n",
               "wserv_db_ap_del",0x1241,auStack_30[0],uVar1);
      }
      goto LAB_005f1b9c;
    }
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if ((uint)((iVar2 + iVar3 + iVar4) * iVar5) <= uVar1) goto LAB_005f1b8c;
    if (*(char *)(DAT_007cbf04 + uVar1 * 0xc + 1) != '\0') {
      iVar2 = wserv_sqlite_notify(1,auStack_30,4);
      if (iVar2 != 0) {
        if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> wserv_sqlite_notify() fail!\r\n","wserv_db_ap_del",
                 0x1249);
        }
        goto LAB_005f1b9c;
      }
      *(undefined1 *)(DAT_007cbf04 + uVar1 * 0xc + 1) = 0;
    }
    iVar7 = _wserv_rd_del(auStack_30[0]);
    if ((iVar7 == 0) || (g_wserv_warning == 0)) {
      iVar6 = iVar6 + 1;
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar6 = iVar6 + 1;
      }
      else {
        printf("<wserv>[warning]%s(): %d  -> _wserv_rd_del() fail!\r\n","wserv_db_ap_del",0x1252);
        iVar6 = iVar6 + 1;
      }
    }
  } while( true );
}

