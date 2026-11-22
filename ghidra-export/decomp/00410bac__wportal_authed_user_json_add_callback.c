// func _wportal_authed_user_json_add_callback @ 00410bac size=1052

undefined4 _wportal_authed_user_json_add_callback(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int extraout_v1;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  char local_2b8 [20];
  char acStack_2a4 [32];
  char acStack_284 [32];
  char acStack_264 [32];
  char acStack_244 [32];
  undefined1 auStack_224 [304];
  char acStack_f4 [220];
  
  local_2b8[0] = '\0';
  local_2b8[1] = '\0';
  local_2b8[2] = '\0';
  local_2b8[3] = '\0';
  local_2b8[4] = '\0';
  local_2b8[5] = '\0';
  local_2b8[6] = '\0';
  local_2b8[7] = '\0';
  local_2b8[8] = '\0';
  local_2b8[9] = '\0';
  local_2b8[10] = '\0';
  local_2b8[0xb] = '\0';
  local_2b8[0xc] = '\0';
  local_2b8[0xd] = '\0';
  local_2b8[0xe] = '\0';
  local_2b8[0xf] = '\0';
  local_2b8[0x10] = '\0';
  local_2b8[0x11] = '\0';
  memset(acStack_244,0,0x20);
  memset(acStack_264,0,0x20);
  memset(acStack_284,0,0x20);
  memset(acStack_2a4,0,0x20);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[WPORTAL_ERR]%s()/%d inputs error.\n";
    uVar3 = 0x99a;
LAB_00410fb8:
    printf(pcVar5,"_wportal_authed_user_json_add_callback",uVar3);
    return 0xffffffff;
  }
  iVar2 = json_object_new_object();
  if (iVar2 == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[WPORTAL_ERR]%s()/%d malloc json obj failed.\n";
    uVar3 = 0x9a1;
    goto LAB_00410fb8;
  }
  snprintf(local_2b8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0xc),
           (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
           (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
           (uint)*(byte *)(param_1 + 0x11));
  uVar3 = json_object_new_string(local_2b8);
  json_object_object_add(iVar2,"mac",uVar3);
  uVar7 = *(uint *)(param_1 + 0x40);
  uVar8 = *(uint *)(param_1 + 0x44);
  uVar9 = FUN_00407e70();
  uVar4 = (uint)((ulonglong)uVar9 >> 0x20);
  if (uVar7 <= uVar4) {
    if (uVar7 != uVar4) {
      iVar6 = 0;
      goto LAB_00410cc4;
    }
    if (uVar8 <= (uint)uVar9) {
      iVar6 = 0;
      goto LAB_00410cc4;
    }
  }
  iVar6 = *(int *)(param_1 + 0x44);
  FUN_00407e70();
  iVar6 = iVar6 - extraout_v1;
LAB_00410cc4:
  snprintf(acStack_244,0x20,"%u",iVar6);
  uVar3 = json_object_new_string(acStack_244);
  json_object_object_add(iVar2,"remain_time",uVar3);
  uVar3 = _wportal_auth_type_int2str(*(undefined1 *)(param_1 + 0x80));
  uVar3 = json_object_new_string(uVar3);
  json_object_object_add(iVar2,"auth_type",uVar3);
  cVar1 = *(char *)(param_1 + 0x81);
  if (cVar1 == '\0') {
    pcVar5 = "local";
  }
  else if (cVar1 == '\x01') {
    pcVar5 = "remote";
  }
  else {
    pcVar5 = (char *)0x0;
    if (cVar1 == 'c') {
      pcVar5 = "tmp";
    }
  }
  uVar3 = json_object_new_string(pcVar5);
  json_object_object_add(iVar2,"auth_server_type",uVar3);
  snprintf(acStack_284,0x20,"%04u/%02u/%02u %02u:%02u:%02u",(uint)*(ushort *)(param_1 + 0x108),
           (uint)*(byte *)(param_1 + 0x10a),(uint)*(byte *)(param_1 + 0x10b),
           (uint)*(byte *)(param_1 + 0x10c),(uint)*(byte *)(param_1 + 0x10d),
           (uint)*(byte *)(param_1 + 0x10e));
  uVar3 = json_object_new_string(acStack_284);
  json_object_object_add(iVar2,"auth_time",uVar3);
  uVar3 = json_object_new_string(param_1 + 0xa3);
  json_object_object_add(iVar2,"username",uVar3);
  uVar3 = json_object_new_string(param_1 + 0x58);
  json_object_object_add(iVar2,&DAT_00677c24,uVar3);
  uVar3 = json_object_new_string(param_1 + 0x82);
  json_object_object_add(iVar2,"token",uVar3);
  if (g_portal_auth_mode == 1) {
    iVar6 = *(int *)(param_1 + 0x14);
    if (iVar6 == 0) {
      iVar6 = 0xfff;
    }
    snprintf(acStack_264,0x20,"%d",iVar6);
    uVar3 = json_object_new_string(acStack_264);
    pcVar5 = "vlan_id";
  }
  else {
    memset(auStack_224,0,0x205);
    iVar6 = uac_wservice_get_entry_by_id(*(undefined4 *)(param_1 + 0x14),auStack_224);
    if (iVar6 == 0) {
      snprintf(acStack_2a4,0x20,"%d",*(undefined4 *)(param_1 + 0x14));
      uVar3 = json_object_new_string(acStack_2a4);
      json_object_object_add(iVar2,"serv_id",uVar3);
      pcVar5 = acStack_f4;
    }
    else {
      uVar3 = json_object_new_string(&DAT_00677878);
      json_object_object_add(iVar2,"serv_id",uVar3);
      pcVar5 = "---";
    }
    uVar3 = json_object_new_string(pcVar5);
    pcVar5 = "ssid";
  }
  json_object_object_add(iVar2,pcVar5,uVar3);
  json_object_array_add(param_2,iVar2);
  return 0;
}

