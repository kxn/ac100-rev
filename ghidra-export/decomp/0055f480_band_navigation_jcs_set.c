// func band_navigation_jcs_set @ 0055f480 size=1176

/* WARNING: Type propagation algorithm not settling */

void band_navigation_jcs_set(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  undefined8 uVar8;
  int local_28 [6];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  iVar5 = json_object_object_get(param_1,"enable");
  if (iVar5 == 0) {
LAB_0055f4e8:
    iVar5 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "band_navigation_jcs_set",0xa8);
    }
  }
  else {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      iVar5 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 != 2) goto LAB_0055f4e8;
      uVar8 = json_object_get_double(iVar5);
      iVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  band_navigation_db_enable_get(local_28);
  bVar2 = local_28[0] != iVar5;
  if (bVar2) {
    band_navigation_db_enable_set(iVar5);
  }
  iVar5 = json_object_object_get(param_1,"5g_threshold");
  if (iVar5 == 0) {
LAB_0055f55c:
    iVar5 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "band_navigation_jcs_set",0xb1);
    }
  }
  else {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      iVar5 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 != 2) goto LAB_0055f55c;
      uVar8 = json_object_get_double(iVar5);
      iVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  band_navigation_db_threshold_get(local_28);
  bVar3 = local_28[0] != iVar5;
  if (bVar3) {
    band_navigation_db_threshold_set(iVar5);
  }
  iVar5 = json_object_object_get(param_1,"dif_threshold");
  if (iVar5 == 0) {
LAB_0055f5cc:
    iVar5 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "band_navigation_jcs_set",0xba);
    }
  }
  else {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      iVar5 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 != 2) goto LAB_0055f5cc;
      uVar8 = json_object_get_double(iVar5);
      iVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  band_navigation_db_differ_threshold_get(local_28);
  bVar4 = local_28[0] != iVar5;
  if (bVar4) {
    band_navigation_db_differ_threshold_set(iVar5);
  }
  iVar5 = json_object_object_get(param_1,"max_fail_num");
  if (iVar5 == 0) {
LAB_0055f63c:
    iVar5 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "band_navigation_jcs_set",0xc3);
    }
  }
  else {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      iVar5 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 != 2) goto LAB_0055f63c;
      uVar8 = json_object_get_double(iVar5);
      iVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  band_navigation_db_max_failure_get(local_28);
  bVar1 = local_28[0] == iVar5;
  if (!bVar1) {
    band_navigation_db_max_failure_set(iVar5);
  }
  if ((band_navigation_debug_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) {
    bVar2 = !bVar4 && (!bVar3 && !bVar2);
  }
  else {
    printf("[BAND_NAVIGATION_DEBUG]%s()/%d set band navigation configure to uci successfully\n",
           "band_navigation_jcs_set",0xca);
    bVar2 = !bVar4 && (!bVar3 && !bVar2);
  }
  if (bVar1 && bVar2) {
    return;
  }
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  iVar5 = serv_wtp_address_arg_init(local_28 + 1);
  if (iVar5 == -1) {
    if (band_navigation_err_switch == 0) {
      return;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return;
    }
    printf("[BAND_NAVIGATION_ERR]%s()/%d serv arg init failed\n","band_navigation_jcs_set",0xd2);
    return;
  }
  iVar5 = apmngr_db_get_all_addr_by_capacity(local_28 + 1,1,1,0x15f0000,1,3);
  if ((iVar5 == -1) || (local_28[3] == 0)) {
    if ((band_navigation_debug_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
    goto LAB_0055f72c;
    __format = "[BAND_NAVIGATION_DEBUG]%s()/%d no AP need to send configure\n";
    uVar7 = 0xd9;
  }
  else {
    iVar5 = band_navigation_packet_send(local_28 + 1);
    if (((iVar5 != -1) || (band_navigation_err_switch == 0)) ||
       (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0055f72c;
    __format = "[BAND_NAVIGATION_ERR]%s()/%d send packet to AP failed\n";
    uVar7 = 0xde;
  }
  printf(__format,"band_navigation_jcs_set",uVar7);
LAB_0055f72c:
  serv_wtp_address_arg_destroy(local_28 + 1);
  return;
}

