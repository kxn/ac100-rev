// func _uac_wserv_jcs_del @ 005e3d74 size=920

void _uac_wserv_jcs_del(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *__format;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 local_230;
  undefined1 auStack_22c [528];
  
  local_230 = 0;
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = apmngr_db_get_ap_max();
  iVar1 = FUN_004082a0((iVar1 >> 5) + (uint)((uVar2 & 0x1f) != 0),4,0xaa2);
  if (iVar1 == 0) {
    uVar6 = 0xffffffff;
    if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e3e50;
    __format = "<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n";
    uVar5 = 0xaa5;
  }
  else {
    iVar3 = json_object_object_get(param_1,"serv_id");
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_del",0xaaa,"serv_id");
      }
      goto LAB_005e3e50;
    }
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar6 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 == 2) {
        uVar7 = json_object_get_double(iVar3);
        uVar6 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
      }
      else {
        uVar6 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_del",0xaab);
        }
      }
    }
    if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_del() begin, wserv_id=%d.\r\n",
             "_uac_wserv_jcs_del",0xaad,uVar6);
    }
    memset(auStack_22c,0,0x205);
    iVar3 = wserv_db_get_entry_by_id(uVar6,auStack_22c);
    if (iVar3 != 0) goto LAB_005e3e50;
    uac_wservice_callback_proc(3,auStack_22c);
    iVar3 = wserv_db_entry_disable(uVar6,_uac_wserv_del_cb);
    if (iVar3 != -1) {
      iVar3 = apmngr_db_get_ap_max();
      uVar2 = apmngr_db_get_ap_max();
      iVar3 = wserv_db_entry_get_binded_ap_id_bm
                        (uVar6,iVar1,(iVar3 >> 5) + (uint)((uVar2 & 0x1f) != 0),&local_230);
      if (((iVar3 != 0) && (g_wserv_error != 0)) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[error]%s(): %d  -> wserv_db_entry_get_binded_ap_id_bm() fail. wserv_id[%d]\r\n"
               ,"_uac_wserv_jcs_del",0xabf,uVar6);
      }
      _uac_wserv_update_aps_md5(iVar1,local_230);
      if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> wserv_db_entry_del() wserv_id=%d.\r\n",
               "_uac_wserv_jcs_del",0xac4,uVar6);
      }
      iVar3 = wserv_db_entry_del(uVar6);
      if (iVar3 == -1) {
        uVar6 = 0xffffffff;
      }
      else {
        uac_wservice_sync_all_wlan_to_re();
      }
      goto LAB_005e3e50;
    }
    if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e3e50;
    __format = "<wserv>[error]%s(): %d  -> wserv_db_entry_disable() fail\r\n";
    uVar5 = 0xab9;
  }
  printf(__format,"_uac_wserv_jcs_del",uVar5);
LAB_005e3e50:
  uVar5 = json_object_new_int(uVar6);
  json_object_object_add(param_2,"serv_id",uVar5);
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_del() finish, wserv_id=%d.\r\n",
           "_uac_wserv_jcs_del",0xad1,uVar6);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return;
}

