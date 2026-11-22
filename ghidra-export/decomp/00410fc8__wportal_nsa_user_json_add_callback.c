// func _wportal_nsa_user_json_add_callback @ 00410fc8 size=860

undefined4 _wportal_nsa_user_json_add_callback(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char local_298 [20];
  char acStack_284 [32];
  char acStack_264 [32];
  char acStack_244 [32];
  undefined1 auStack_224 [304];
  char acStack_f4 [220];
  
  local_298[0] = '\0';
  local_298[1] = '\0';
  local_298[2] = '\0';
  local_298[3] = '\0';
  local_298[4] = '\0';
  local_298[5] = '\0';
  local_298[6] = '\0';
  local_298[7] = '\0';
  local_298[8] = '\0';
  local_298[9] = '\0';
  local_298[10] = '\0';
  local_298[0xb] = '\0';
  local_298[0xc] = '\0';
  local_298[0xd] = '\0';
  local_298[0xe] = '\0';
  local_298[0xf] = '\0';
  local_298[0x10] = '\0';
  local_298[0x11] = '\0';
  memset(acStack_244,0,0x20);
  memset(acStack_264,0,0x20);
  memset(acStack_284,0,0x20);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[WPORTAL_ERR]%s()/%d inputs error.\n";
    uVar2 = 0xf2f;
  }
  else {
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      snprintf(local_298,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x74),
               (uint)*(byte *)(param_1 + 0x75),(uint)*(byte *)(param_1 + 0x76),
               (uint)*(byte *)(param_1 + 0x77),(uint)*(byte *)(param_1 + 0x78),
               (uint)*(byte *)(param_1 + 0x79));
      uVar2 = json_object_new_string(local_298);
      json_object_object_add(iVar1,"mac",uVar2);
      snprintf(acStack_244,0x20,"%4u/%02u/%02u %02u:%02u:%02u",(uint)*(ushort *)(param_1 + 0x108),
               (uint)*(byte *)(param_1 + 0x10a),(uint)*(byte *)(param_1 + 0x10b),
               (uint)*(byte *)(param_1 + 0x10c),(uint)*(byte *)(param_1 + 0x10d),
               (uint)*(byte *)(param_1 + 0x10e));
      uVar2 = json_object_new_string(acStack_244);
      json_object_object_add(iVar1,"auth_time",uVar2);
      uVar2 = json_object_new_string(param_1 + 0x7a);
      json_object_object_add(iVar1,"username",uVar2);
      pcVar4 = (char *)(param_1 + 0xc);
      if (*(char *)(param_1 + 0x166) != '\0') {
        pcVar4 = "--- (CHAP)";
      }
      uVar2 = json_object_new_string(pcVar4);
      json_object_object_add(iVar1,"password",uVar2);
      uVar2 = json_object_new_string(param_1 + 0xdf);
      json_object_object_add(iVar1,&DAT_00677c24,uVar2);
      uVar2 = _wportal_auth_type_int2str(*(undefined4 *)(param_1 + 0x148));
      uVar2 = json_object_new_string(uVar2);
      json_object_object_add(iVar1,"auth_type",uVar2);
      if (g_portal_auth_mode == 1) {
        iVar3 = *(int *)(param_1 + 0x128);
        if (iVar3 == 0) {
          iVar3 = 0xfff;
        }
        snprintf(acStack_264,0x20,"%d",iVar3);
        uVar2 = json_object_new_string(acStack_264);
        pcVar4 = "vlan_id";
      }
      else {
        memset(auStack_224,0,0x205);
        iVar3 = uac_wservice_get_entry_by_id(*(undefined4 *)(param_1 + 0x128),auStack_224);
        if (iVar3 == 0) {
          snprintf(acStack_284,0x20,"%d",*(undefined4 *)(param_1 + 0x128));
          uVar2 = json_object_new_string(acStack_284);
          json_object_object_add(iVar1,"serv_id",uVar2);
          pcVar4 = acStack_f4;
        }
        else {
          uVar2 = json_object_new_string(&DAT_00677878);
          json_object_object_add(iVar1,"serv_id",uVar2);
          pcVar4 = "---";
        }
        uVar2 = json_object_new_string(pcVar4);
        pcVar4 = "ssid";
      }
      json_object_object_add(iVar1,pcVar4,uVar2);
      json_object_array_add(param_2,iVar1);
      return 0;
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[WPORTAL_ERR]%s()/%d malloc json obj failed.\n";
    uVar2 = 0xf36;
  }
  printf(pcVar4,"_wportal_nsa_user_json_add_callback",uVar2);
  return 0xffffffff;
}

