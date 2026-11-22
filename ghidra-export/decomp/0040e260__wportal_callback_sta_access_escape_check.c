// func _wportal_callback_sta_access_escape_check @ 0040e260 size=564

bool _wportal_callback_sta_access_escape_check(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  char *__format;
  undefined4 uVar4;
  bool bVar5;
  short local_180 [2];
  undefined1 auStack_17c [308];
  int local_48;
  int local_18;
  
  local_180[0] = 0;
  if (param_1 == 0) {
    bVar5 = false;
    if (wportal_err_switch == 0) {
      return false;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return false;
    }
    __format = "[WPORTAL_ERR]%s()/%d inputs error.\n";
    uVar4 = 0x3056;
  }
  else {
    if (g_portal_auth_mode != 0) {
      if (g_portal_auth_mode != 1) {
        return false;
      }
      uac_wservice_get_vlan
                (*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 6),
                 *(undefined1 *)(param_1 + 7),local_180);
      memset(auStack_17c,0,0x16c);
      sVar3 = local_180[0];
      if (local_180[0] == 0) {
        sVar3 = 0xfff;
      }
      iVar1 = wportal_db_rdt_get_by_vlan(sVar3,auStack_17c);
      if (iVar1 != 0) {
        return false;
      }
      if (local_48 == 0) {
        return false;
      }
      return local_18 == 1;
    }
    iVar1 = uac_wservice_get_wserv_id
                      (*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 6),
                       *(undefined1 *)(param_1 + 7));
    if (iVar1 == -1) {
      if (wportal_debug_switch == 0) {
        return false;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return false;
      }
      printf("[WPORTAL_DBG]%s()/%d Get wserv id error, arg->ap_id[%d], arg->rd_id[%d], arg->wlan_id[%d] invalid!\n"
             ,"_wportal_callback_sta_access_escape_check",0x305f,*(undefined4 *)(param_1 + 8),
             (uint)*(byte *)(param_1 + 6),(uint)*(byte *)(param_1 + 7));
      return false;
    }
    memset(auStack_17c,0,0x16c);
    iVar2 = wportal_db_ssid_rdt_get(iVar1,auStack_17c);
    if (iVar2 != 0) {
      if (wportal_debug_switch == 0) {
        return false;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return false;
      }
      printf("[WPORTAL_DBG]%s()/%d wportal_db_ssid_rdt_get failed wserv_id is %d \n",
             "_wportal_callback_sta_access_escape_check",0x3067,iVar1);
      return false;
    }
    if (local_18 == 1) {
      bVar5 = true;
      if (wportal_debug_switch == 0) {
        return true;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return true;
      }
      __format = "[WPORTAL_DBG]%s()/%d 1 == rdtEntry.is_escape return OK!\n";
      uVar4 = 0x306d;
    }
    else {
      bVar5 = false;
      if (wportal_debug_switch == 0) {
        return false;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return false;
      }
      __format = "[WPORTAL_DBG]%s()/%d 1 == rdtEntry.is_escape return false!\n";
      uVar4 = 0x3072;
    }
  }
  printf(__format,"_wportal_callback_sta_access_escape_check",uVar4);
  return bVar5;
}

