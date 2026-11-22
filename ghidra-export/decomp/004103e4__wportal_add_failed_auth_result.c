// func _wportal_add_failed_auth_result @ 004103e4 size=1080

/* WARNING: Type propagation algorithm not settling */

undefined4 _wportal_add_failed_auth_result(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 local_100;
  undefined2 local_fc;
  char local_f8 [16];
  ushort local_e8;
  undefined4 local_e4 [7];
  undefined2 local_c8;
  undefined2 local_c0;
  undefined1 local_be;
  undefined1 local_bd;
  undefined2 local_bc;
  undefined1 local_ba;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 auStack_98 [32];
  uint local_78;
  undefined1 local_74;
  undefined1 local_73;
  undefined2 local_6a;
  
  local_f8[0] = '\0';
  local_f8[1] = '\0';
  local_f8[2] = '\0';
  local_f8[3] = '\0';
  local_f8[4] = '\0';
  local_f8[5] = '\0';
  local_f8[6] = '\0';
  local_f8[7] = '\0';
  local_f8[8] = '\0';
  local_f8[9] = '\0';
  local_f8[10] = '\0';
  local_f8[0xb] = '\0';
  local_f8[0xc] = '\0';
  local_f8[0xd] = '\0';
  local_f8[0xe] = '\0';
  local_f8[0xf] = '\0';
  local_e8 = 0;
  local_e4[0] = 0;
  local_e4[1] = 0;
  local_e4[2] = 0;
  local_e4[3] = 0;
  local_e4[4] = 0;
  local_e4[5] = 0;
  local_100 = 0;
  local_fc = 0;
  if (param_1 == 0) {
    uVar6 = 0xffffffff;
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[WPORTAL_ERR]%s()/%d Input param is invalid.\n";
    uVar8 = 0x2342;
    goto LAB_004106a8;
  }
  iVar1 = json_object_object_get(param_1,"fail_code");
  if (iVar1 == 0) {
LAB_0041047c:
    uVar8 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_add_failed_auth_result",0x2347);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar8 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041047c;
      uVar9 = json_object_get_double(iVar1);
      uVar8 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  iVar1 = json_object_object_get(param_1,"fail_time");
  if (iVar1 == 0) {
LAB_004104cc:
    uVar7 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_add_failed_auth_result",0x234a);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar7 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004104cc;
      uVar9 = json_object_get_double(iVar1);
      uVar7 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  iVar1 = json_object_object_get(param_1,"sta_mac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_add_failed_auth_result",0x234d);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_f8,pcVar4,0x11);
  local_e8 = local_e8 & 0xff00;
  if (local_f8[0] == '\0') {
    uVar6 = 0xffffffff;
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[WPORTAL_ERR]%s()/%d Sta mac is empty.\n";
    uVar8 = 0x2350;
  }
  else {
    sscanf(local_f8,"%2X-%2X-%2X-%2X-%2X-%2X",local_e4,local_e4 + 1,local_e4 + 2,local_e4 + 3,
           local_e4 + 4,local_e4 + 5);
    puVar3 = local_e4;
    iVar1 = 0;
    do {
      puVar5 = (undefined1 *)((int)&local_100 + iVar1);
      uVar6 = *puVar3;
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 1;
      *puVar5 = (char)uVar6;
    } while (iVar1 != 6);
    uVar6 = 0xffffffff;
    iVar1 = wsta_db_get_entry_by_mac(&local_100,auStack_98);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    local_e4[6] = local_100;
    local_c8 = local_fc;
    local_c0 = (undefined2)local_78;
    local_be = local_74;
    local_bd = local_73;
    local_bc = local_6a;
    local_ba = 5;
    local_b8 = uVar8;
    local_b4 = uVar7;
    iVar1 = stats_db_fail_sta_add(local_e4 + 6);
    if (iVar1 == 0) {
      stats_db_ap_sample_portal_update(local_78 & 0xffff,1);
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d wportal add failed auth result. send to datasync is sync:%d\n"
               ,"_wportal_add_failed_auth_result",0x2374,param_2);
      }
      uVar6 = 0;
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
      pcVar4 = "[WPORTAL_INFO]%s()/%d dump failed auth result after add:\n\n";
      uVar8 = 0x238c;
    }
    else {
      if (wportal_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar4 = "[WPORTAL_ERR]%s()/%d Add fail station entry failed.\n";
      uVar8 = 0x236e;
    }
  }
LAB_004106a8:
  printf(pcVar4,"_wportal_add_failed_auth_result",uVar8);
  return uVar6;
}

