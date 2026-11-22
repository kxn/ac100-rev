// func _wportal_authed_user_del @ 00425098 size=1072

undefined4 _wportal_authed_user_del(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 local_358;
  undefined2 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  ushort local_340;
  undefined4 local_33c;
  undefined1 auStack_338 [4];
  undefined1 auStack_334 [4];
  undefined1 auStack_330 [4];
  undefined1 auStack_32c [4];
  undefined1 auStack_328 [4];
  char local_324 [39];
  undefined1 local_2fd;
  undefined1 auStack_2fc [356];
  int local_198;
  undefined1 auStack_190 [20];
  undefined4 local_17c;
  int local_48;
  
  local_350 = 0;
  local_34c = 0;
  local_348 = 0;
  local_344 = 0;
  local_340 = 0;
  local_358 = 0;
  local_354 = 0;
  memset(local_324,0,0x28);
  memset(auStack_190,0,0x180);
  iVar1 = json_object_object_get(param_1,&DAT_00677c24);
  if (iVar1 != 0) {
    memset(local_324,0,0x28);
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_authed_user_del",0xce2);
      }
      pcVar4 = "";
    }
    strncpy(local_324,pcVar4,0x27);
    local_2fd = 0;
  }
  iVar1 = json_object_object_get(param_1,"mac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_del",0xce6);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy((char *)&local_350,pcVar4,0x11);
  local_340 = local_340 & 0xff00;
  if (local_350._0_1_ == '\0') {
  }
  else {
    sscanf((char *)&local_350,"%2X-%2X-%2X-%2X-%2X-%2X",&local_33c,auStack_338,auStack_334,
           auStack_330,auStack_32c,auStack_328);
    puVar3 = &local_33c;
    iVar1 = 0;
    do {
      puVar5 = (undefined1 *)((int)&local_358 + iVar1);
      uVar6 = *puVar3;
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 1;
      *puVar5 = (char)uVar6;
    } while (iVar1 != 6);
  }
  if (((local_358._0_1_ == '\0') && (local_358._1_1_ == '\0')) && (local_358._2_1_ == '\0')) {
    if ((((char)local_358 != '\0') || (local_354._0_1_ != '\0')) || ((char)local_354 != '\0'))
    goto LAB_004251c8;
    if (local_324[0] == '\0') {
      if (wportal_err_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap(&local_358);
      if (iVar1 == 0) {
        return 0;
      }
      pcVar4 = "[WPORTAL_ERR]%s()/%d invalid para for _wportal_authed_user_del!\n";
      uVar6 = 0xd06;
      goto LAB_00425438;
    }
    iVar1 = wportal_db_aut_get_by_ip(local_324,auStack_190);
  }
  else {
LAB_004251c8:
    iVar1 = wportal_db_aut_get(&local_358,auStack_190);
  }
  if (iVar1 != 0) {
    return 0;
  }
  if (local_48 != -1) {
    FUN_00408060();
  }
  if (((local_358._0_1_ == '\0') && (local_358._1_1_ == '\0')) &&
     ((local_358._2_1_ == '\0' &&
      ((((char)local_358 == '\0' && (local_354._0_1_ == '\0')) && ((char)local_354 == '\0')))))) {
    wportal_db_aut_del_by_ip(local_324);
  }
  else {
    wportal_db_aut_del(&local_358);
  }
  if ((g_portal_auth_mode == 1) ||
     ((g_portal_auth_mode == 0 && (iVar1 = isStaAccess(local_17c,&local_358), iVar1 == 1)))) {
    memset(auStack_2fc,0,0x16c);
    if (g_portal_auth_mode == 1) {
      wportal_db_rdt_get_by_vlan(local_17c,auStack_2fc);
    }
    else if (g_portal_auth_mode == 0) {
      wportal_db_ssid_rdt_get(local_17c,auStack_2fc);
    }
    if (local_198 == 0) {
      wportal_update_user_to_ap(auStack_190,1);
    }
  }
  wportal_db_foreach_event_list(1,auStack_190,0);
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d wportal del auth. send to datasync is sync:%d\n",
           "_wportal_authed_user_del",0xd31,param_2);
  }
  if (param_2 != 0) {
    return 0;
  }
  if (wportal_info_switch == 0) {
    return 0;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0;
  }
  pcVar4 = "[WPORTAL_INFO]%s()/%d dump auth list after del:\n\n";
  uVar6 = 0xd49;
LAB_00425438:
  printf(pcVar4,"_wportal_authed_user_del",uVar6);
  return 0;
}

