// func uac_wservice_entry_delete_by_id @ 005dd378 size=636

int uac_wservice_entry_delete_by_id(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_228;
  undefined1 auStack_224 [283];
  int local_109;
  
  memset(auStack_224,0,0x205);
  local_228 = 0;
  iVar1 = wserv_db_get_entry_by_id(param_1,auStack_224);
  iVar5 = -1;
  if (iVar1 != 0) {
    iVar1 = 0;
    goto LAB_005dd420;
  }
  iVar5 = apmngr_db_get_ap_max();
  uVar2 = apmngr_db_get_ap_max();
  iVar1 = FUN_004082a0((iVar5 >> 5) + (uint)((uVar2 & 0x1f) != 0),4,0x14d3);
  if (iVar1 == 0) {
    iVar5 = -1;
    if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005dd420;
    __format = "<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n";
    uVar4 = 0x14d6;
LAB_005dd5a8:
    iVar5 = -1;
    printf(__format,"uac_wservice_entry_delete_by_id",uVar4);
  }
  else {
    if (local_109 != 0) {
      iVar5 = wserv_db_entry_disable(param_1,_uac_wserv_del_cb);
      if (iVar5 == -1) {
        iVar5 = -1;
        if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005dd420;
        __format = "<wserv>[error]%s(): %d  -> wserv_db_entry_disable() fail\r\n";
        uVar4 = 0x14de;
        goto LAB_005dd5a8;
      }
      iVar5 = apmngr_db_get_ap_max();
      uVar2 = apmngr_db_get_ap_max();
      iVar5 = wserv_db_entry_get_binded_ap_id_bm
                        (param_1,iVar1,(iVar5 >> 5) + (uint)((uVar2 & 0x1f) != 0),&local_228);
      if (((iVar5 != 0) && (g_wserv_error != 0)) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("<wserv>[error]%s(): %d  -> wserv_db_entry_get_binded_ap_id_bm() fail. wserv_id[%d]\r\n"
               ,"uac_wservice_entry_delete_by_id",0x14e4,param_1);
      }
      _uac_wserv_update_aps_md5(iVar1,local_228);
    }
    if ((g_wserv_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> wserv_db_entry_del() wserv_id=%d.\r\n",
             "uac_wservice_entry_delete_by_id",0x14ea,param_1);
    }
    iVar5 = wserv_db_entry_del(param_1);
    if (iVar5 == 0) {
      uac_wservice_sync_all_wlan_to_re();
    }
  }
LAB_005dd420:
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_del() finish, wserv_id=%d.\r\n",
           "uac_wservice_entry_delete_by_id",0x14f2,param_1);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return iVar5;
}

