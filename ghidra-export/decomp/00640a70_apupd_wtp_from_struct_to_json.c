// func apupd_wtp_from_struct_to_json @ 00640a70 size=548

undefined4 apupd_wtp_from_struct_to_json(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 local_478;
  char acStack_474 [128];
  char acStack_3f4 [260];
  undefined1 auStack_2f0 [78];
  char acStack_2a2 [654];
  
  memset(acStack_474,0,0x80);
  memset(auStack_2f0,0,0x2d8);
  local_478 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0xbb2;
  }
  else {
    iVar1 = apupd_db_config_get_without_lock(&local_478);
    if (iVar1 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar3 = "[APUPD_ERROR]%32s() %05d: get config failed.\r\n";
      uVar2 = 3000;
    }
    else {
      iVar1 = apmngr_db_entry_get_by_mac(param_1 + 0x2e,auStack_2f0);
      pcVar3 = acStack_2a2;
      if (iVar1 == -1) {
        pcVar3 = "---";
      }
      uVar2 = json_object_new_string(pcVar3);
      json_object_object_add(param_2,"name",uVar2);
      sprintf(acStack_474,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x2e),
              (uint)*(byte *)(param_1 + 0x2f),(uint)*(byte *)(param_1 + 0x30),
              (uint)*(byte *)(param_1 + 0x31),(uint)*(byte *)(param_1 + 0x32),
              (uint)*(byte *)(param_1 + 0x33));
      uVar2 = json_object_new_string(acStack_474);
      json_object_object_add(param_2,"mac",uVar2);
      iVar1 = apupd_db_wtp_real_state_get(param_1,&local_478);
      if (iVar1 != -1) {
        memset(acStack_3f4,0,0x100);
        snprintf(acStack_3f4,0x100,"%d",iVar1);
        uVar2 = json_object_new_string(acStack_3f4);
        json_object_object_add(param_2,"upgrade_status",uVar2);
        return 0;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar3 = "[APUPD_ERROR]%32s() %05d: get state failed.\r\n";
      uVar2 = 0xbcc;
    }
  }
  printf(pcVar3,"apupd_wtp_from_struct_to_json",uVar2);
  return 0xffffffff;
}

