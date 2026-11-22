// func _wsta_roam_jcs_intelligent_set @ 0047f5b0 size=4168

void _wsta_roam_jcs_intelligent_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *__src;
  char *pcVar6;
  undefined8 uVar7;
  char acStack_110 [15];
  char local_101 [17];
  undefined1 auStack_f0 [36];
  undefined1 auStack_cc [2];
  undefined1 local_ca;
  undefined1 local_c1;
  undefined1 local_c0;
  undefined1 local_bf;
  byte local_be;
  undefined1 local_bd;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8;
  byte local_b7;
  undefined1 local_b6;
  undefined1 local_b5;
  undefined1 local_b4;
  undefined1 local_b3;
  undefined1 local_b2;
  undefined1 local_b1;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  char acStack_a8 [127];
  undefined1 local_29;
  
  memset(acStack_a8,0,0x80);
  memset(acStack_110,0,0x20);
  memset(auStack_cc,0,0x22);
  memset(auStack_f0,0,0x22);
  wsta_roam_db_cfg_get(auStack_f0);
  memcpy(auStack_cc,auStack_f0,0x22);
  iVar1 = json_object_object_get(param_1,"11k_switch");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x55);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_c1 = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"11v_switch");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x59);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  local_29 = 0;
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_c0 = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"11r_switch");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x5e);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  local_29 = 0;
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_bf = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"2g_roaming_threshold_type");
  if (iVar1 == 0) {
LAB_0047f7c0:
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get stringArray with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",99);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 5) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar2 = 0;
        if (iVar1 == 0) goto LAB_0047f7d0;
      }
      goto LAB_0047f7c0;
    }
    pcVar5 = acStack_110;
    for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
      if (iVar2 == 2) {
        iVar2 = 2;
        break;
      }
      iVar3 = json_object_array_get_idx(iVar1,iVar2);
      if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
        pcVar6 = "";
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wsta_roam_jcs_intelligent_set",99);
        }
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar3);
      }
      strncpy(pcVar5,pcVar6,0xf);
      pcVar5[0xf] = '\0';
      pcVar5 = pcVar5 + 0x10;
    }
  }
LAB_0047f7d0:
  local_be = 0;
  pcVar6 = acStack_110;
  pcVar5 = pcVar6;
  for (iVar1 = 0; iVar1 < iVar2; iVar1 = iVar1 + 1) {
    iVar3 = strcmp(pcVar5,"rssi");
    if (iVar3 == 0) {
      local_be = local_be | 1;
    }
    else {
      iVar3 = strcmp(pcVar5,"rate");
      if (iVar3 == 0) {
        local_be = local_be | 2;
      }
    }
    pcVar5 = pcVar5 + 0x10;
  }
  iVar1 = json_object_object_get(param_1,"2g_rssi_trigger_threshold");
  if (iVar1 == 0) {
LAB_0047f880:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x72);
    }
    local_bd = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_bd = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047f880;
      uVar7 = json_object_get_double(iVar1);
      local_bd = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"rssi_trigger_threshold_high_performance");
  if (iVar1 == 0) {
LAB_0047f8d8:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x75);
    }
    local_ca = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_ca = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047f8d8;
      uVar7 = json_object_get_double(iVar1);
      local_ca = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"2g_low_rssi_kick");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x78);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  local_29 = 0;
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_bc = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"2g_low_rssi_threshold");
  if (iVar1 == 0) {
LAB_0047f99c:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x7c);
    }
    local_bb = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_bb = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047f99c;
      uVar7 = json_object_get_double(iVar1);
      local_bb = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"2g_rate_trigger_threshold");
  if (iVar1 == 0) {
LAB_0047f9f4:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x7f);
    }
    local_ba = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_ba = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047f9f4;
      uVar7 = json_object_get_double(iVar1);
      local_ba = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"2g_low_rate_kick");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x82);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  local_29 = 0;
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_b9 = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"2g_low_rate_threshold");
  if (iVar1 == 0) {
LAB_0047fab8:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x86);
    }
    local_b8 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_b8 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fab8;
      uVar7 = json_object_get_double(iVar1);
      local_b8 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"5g_roaming_threshold_type");
  if (iVar1 == 0) {
LAB_0047fb14:
    iVar3 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get stringArray with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x8b);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar3 = 0;
    pcVar5 = pcVar6;
    if (iVar2 != 5) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar3 = 0;
        if (iVar1 == 0) goto LAB_0047fb24;
      }
      goto LAB_0047fb14;
    }
    for (; iVar2 = json_object_array_length(iVar1), iVar3 < iVar2; iVar3 = iVar3 + 1) {
      if (iVar3 == 2) {
        iVar3 = 2;
        break;
      }
      iVar2 = json_object_array_get_idx(iVar1,iVar3);
      if ((iVar2 == 0) || (iVar4 = json_object_get_type(iVar2), iVar4 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wsta_roam_jcs_intelligent_set",0x8b);
        }
        __src = "";
      }
      else {
        __src = (char *)json_object_get_string(iVar2);
      }
      strncpy(pcVar5,__src,0xf);
      pcVar5[0xf] = '\0';
      pcVar5 = pcVar5 + 0x10;
    }
  }
LAB_0047fb24:
  local_b7 = 0;
  for (iVar1 = 0; iVar1 < iVar3; iVar1 = iVar1 + 1) {
    iVar2 = strcmp(pcVar6,"rssi");
    if (iVar2 == 0) {
      local_b7 = local_b7 | 1;
    }
    else {
      iVar2 = strcmp(pcVar6,"rate");
      if (iVar2 == 0) {
        local_b7 = local_b7 | 2;
      }
    }
    pcVar6 = pcVar6 + 0x10;
  }
  iVar1 = json_object_object_get(param_1,"5g_rssi_trigger_threshold");
  if (iVar1 == 0) {
LAB_0047fbcc:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x9a);
    }
    local_b6 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_b6 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fbcc;
      uVar7 = json_object_get_double(iVar1);
      local_b6 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"5g_low_rssi_kick");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0x9c);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  local_29 = 0;
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_b5 = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"5g_low_rssi_threshold");
  if (iVar1 == 0) {
LAB_0047fc90:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0xa0);
    }
    local_b4 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_b4 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fc90;
      uVar7 = json_object_get_double(iVar1);
      local_b4 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"5g_rate_trigger_threshold");
  if (iVar1 == 0) {
LAB_0047fce8:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0xa4);
    }
    local_b3 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_b3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fce8;
      uVar7 = json_object_get_double(iVar1);
      local_b3 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"5g_low_rate_kick");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0xa7);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_a8,pcVar5,0x7f);
  local_29 = 0;
  iVar1 = strncmp(acStack_a8,"on",0x80);
  local_b2 = iVar1 == 0;
  iVar1 = json_object_object_get(param_1,"5g_low_rate_threshold");
  if (iVar1 == 0) {
LAB_0047fdac:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0xab);
    }
    local_b1 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_b1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fdac;
      uVar7 = json_object_get_double(iVar1);
      local_b1 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"threshold_check_interval");
  if (iVar1 == 0) {
LAB_0047fe04:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0xb0);
    }
    local_b0 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_b0 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fe04;
      uVar7 = json_object_get_double(iVar1);
      local_b0 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"roaming_dif");
  if (iVar1 == 0) {
LAB_0047fe5c:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wsta_roam_jcs_intelligent_set",0xb3);
    }
    local_af = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_af = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0047fe5c;
      uVar7 = json_object_get_double(iVar1);
      local_af = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"blacklist_restrict_time");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_ae = json_object_get_int(iVar1);
      goto LAB_0047fecc;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar7 = json_object_get_double(iVar1);
      local_ae = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
      goto LAB_0047fecc;
    }
  }
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wsta_roam_jcs_intelligent_set",0xb6);
  }
  local_ae = 0xff;
LAB_0047fecc:
  iVar1 = memcmp(auStack_f0,auStack_cc,0x22);
  if (iVar1 == 0) {
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d the config is no change,return.\n",
             "_wsta_roam_jcs_intelligent_set",0xc4);
    }
  }
  else {
    wsta_roam_db_cfg_set(auStack_cc);
    iVar1 = memcmp(auStack_f0,auStack_cc,0x22);
    if (iVar1 != 0) {
      wsta_intelligent_roam_ctl_update_to_all_ap(0);
    }
  }
  return;
}

