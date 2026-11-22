// func wserv_db_ap_enter_run @ 005f1c4c size=688

undefined4 wserv_db_ap_enter_run(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar10 = 1;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_0051ad88(&local_34);
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  do {
    uVar7 = 0;
    if (param_2 < iVar10) {
LAB_005f1d78:
      FUN_00407f30(DAT_007cbef0);
      _wserv_db_do_evt(&local_34,param_3,0);
      return uVar7;
    }
    uVar1 = rdmngr_db_generate_rd_id(param_1,iVar10);
    local_40 = 0;
    local_3c = 0;
    if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _wserv_rd_enter_run() begin, rd_id[%d] enter run.\r\n",
             "_wserv_rd_enter_run",0x6a9,uVar1);
    }
    uVar2 = rdmngr_db_generate_rd_idx_by_rd_id(uVar1);
    if ((int)uVar2 < 0) {
LAB_005f1dc8:
      if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        __format = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
        uVar7 = 0x6ad;
LAB_005f1dfc:
        printf(__format,"_wserv_rd_enter_run",uVar7,uVar1);
      }
LAB_005f1d68:
      uVar7 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> _wserv_rd_enter_run() fail!\r\n",
               "wserv_db_ap_enter_run",0x1278);
      }
      goto LAB_005f1d78;
    }
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar5 = apmngr_db_get_sensor_max();
    iVar6 = rdmngr_profile_get_max_rd_per_ap();
    if ((uint)((iVar3 + iVar4 + iVar5) * iVar6) <= uVar2) goto LAB_005f1dc8;
    if (*(char *)(DAT_007cbf04 + uVar2 * 0xc) == '\0') {
      if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        __format = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
        uVar7 = 0x6b3;
        uVar1 = uVar2;
        goto LAB_005f1dfc;
      }
      goto LAB_005f1d68;
    }
    cVar9 = '\x01';
    uVar8 = 0;
    local_40 = uVar1;
    while (uVar1 = rdmngr_profile_get_max_wlan_per_rd(), uVar8 < uVar1) {
      if (*(char *)(*(int *)(DAT_007cbf04 + uVar2 * 0xc + 8) + uVar8 * 6) == '\0') {
        uVar8 = uVar8 + 1;
        cVar9 = cVar9 + '\x01';
      }
      else {
        local_3c = CONCAT13(cVar9,local_3c._1_3_);
        uVar8 = uVar8 + 1;
        _wserv_add_wlan_db_info_collect(&local_40,&local_38);
        cVar9 = cVar9 + '\x01';
      }
    }
    iVar10 = iVar10 + 1;
  } while( true );
}

