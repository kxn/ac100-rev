// func apmngr_ap_edit_new_ap_trunk @ 0052d5f0 size=1024

undefined4 apmngr_ap_edit_new_ap_trunk(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char acStack_310 [19];
  undefined1 local_2fd;
  undefined1 auStack_2f8 [689];
  byte local_47;
  byte local_46;
  byte local_45;
  char acStack_44 [36];
  
  param_1 = param_1 & 0xffff;
  uVar8 = 0;
  memset(auStack_2f8,0,0x2d8);
  iVar1 = json_object_object_get(param_2,"lag_mode");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar3 = (char *)json_object_get_string(iVar1);
      uVar8 = atoi(pcVar3);
      uVar8 = uVar8 & 0xff;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "apmngr_ap_edit_new_ap_trunk",0x7b3);
      }
      if (jcs_err_switch == 0) {
        uVar8 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
               "apmngr_ap_edit_new_ap_trunk",0x7b3);
        uVar8 = 0xff;
      }
    }
  }
  uVar7 = 0;
  iVar1 = json_object_object_get(param_2,"new_ap_trunk");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar3 = (char *)json_object_get_string(iVar1);
      uVar7 = atoi(pcVar3);
      uVar7 = uVar7 & 0xff;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "apmngr_ap_edit_new_ap_trunk",0x7b6);
      }
      if (jcs_err_switch == 0) {
        uVar7 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
               "apmngr_ap_edit_new_ap_trunk",0x7b6);
        uVar7 = 0xff;
      }
    }
  }
  uVar6 = 0;
  iVar1 = json_object_object_get(param_2,"lag_phy_num");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar3 = (char *)json_object_get_string(iVar1);
      uVar6 = atoi(pcVar3);
      uVar6 = uVar6 & 0xff;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "apmngr_ap_edit_new_ap_trunk",0x7b9);
      }
      if (jcs_err_switch == 0) {
        uVar6 = 0xff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
               "apmngr_ap_edit_new_ap_trunk",0x7b9);
        uVar6 = 0xff;
      }
    }
  }
  iVar1 = json_object_object_get(param_2,"lag_phy_list");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "apmngr_ap_edit_new_ap_trunk",0x7bc);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_310,pcVar3,0x13);
  local_2fd = 0;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f8);
  if (iVar1 == 0) {
    iVar1 = strcmp(acStack_310,acStack_44);
    if ((iVar1 == 0) && (local_47 == uVar7 && (local_45 == uVar6 && local_46 == uVar8))) {
      if (apmngr_debug_switch == '\0') {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      pcVar3 = "[APMNGR_DEBUG]%s()/%d lag phy config not changed\n";
      uVar4 = 0x7cb;
    }
    else {
      apmngr_lag_config_edit(param_1,uVar7,uVar8,uVar6,acStack_310);
      apmngr_db_set_cur_using_lag_config(uVar7,uVar8,uVar6,acStack_310,param_1);
      if (apmngr_debug_switch == '\0') {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      pcVar3 = "[APMNGR_DEBUG]%s()/%d set lag config success!\n";
      uVar4 = 0x7d6;
    }
    uVar5 = 0;
    printf(pcVar3,"apmngr_ap_edit_new_ap_trunk",uVar4);
  }
  else {
    uVar5 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n","apmngr_ap_edit_new_ap_trunk",0x7c0
             ,param_1);
    }
  }
  return uVar5;
}

