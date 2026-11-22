// func apupd_wtp_from_struct_to_json_for_ap @ 00640e88 size=1184

undefined4 apupd_wtp_from_struct_to_json_for_ap(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 local_638;
  uint local_634;
  uint local_630;
  uint local_62c;
  undefined4 local_628;
  char acStack_624 [68];
  char acStack_5e0 [128];
  char acStack_560 [256];
  undefined1 auStack_460 [218];
  char acStack_386 [65];
  char local_345 [77];
  undefined1 auStack_2f8 [68];
  ushort local_2b4;
  ushort local_2b2;
  char acStack_2aa [458];
  undefined1 auStack_e0 [196];
  
  memset(acStack_5e0,0,0x80);
  memset(acStack_624,0,0x41);
  memset(auStack_460,0,0x168);
  local_634 = 0;
  local_630 = 0;
  local_62c = 0;
  local_628 = 0;
  memset(auStack_2f8,0,0x2d8);
  local_638 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0xbed;
LAB_00641254:
    printf(pcVar5,"apupd_wtp_from_struct_to_json_for_ap",uVar3);
    return 0xffffffff;
  }
  iVar2 = apupd_db_config_get_without_lock(&local_638);
  if (iVar2 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get config failed.\r\n";
    uVar3 = 0xbf3;
    goto LAB_00641254;
  }
  iVar2 = apmngr_db_entry_get_by_mac(param_1 + 0x2e,auStack_2f8);
  pcVar5 = acStack_2aa;
  if (iVar2 == -1) {
    pcVar5 = "---";
  }
  uVar3 = json_object_new_string(pcVar5);
  json_object_object_add(param_2,"name",uVar3);
  iVar2 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x34),auStack_e0,auStack_460);
  if (iVar2 == 0) {
    pcVar5 = local_345;
    if (local_345[0] == '\0') {
      pcVar5 = acStack_386;
    }
    uVar3 = json_object_new_string(pcVar5);
    json_object_object_add(param_2,"model",uVar3);
    memset(acStack_560,0,0x100);
    snprintf(acStack_560,0x100,"%d",*(undefined4 *)(param_1 + 0x34));
    uVar3 = json_object_new_string(acStack_560);
    json_object_object_add(param_2,"model_id",uVar3);
    bVar1 = *(byte *)(param_1 + 0x30);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x30);
  }
  sprintf(acStack_5e0,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x2e),
          (uint)*(byte *)(param_1 + 0x2f),(uint)bVar1,(uint)*(byte *)(param_1 + 0x31),
          (uint)*(byte *)(param_1 + 0x32),(uint)*(byte *)(param_1 + 0x33));
  uVar3 = json_object_new_string(acStack_5e0);
  json_object_object_add(param_2,"mac",uVar3);
  sprintf(acStack_624,"%d.%d",(uint)local_2b4,(uint)local_2b2);
  uVar3 = json_object_new_string(acStack_624);
  json_object_object_add(param_2,"hw_version",uVar3);
  memset(acStack_624,0,0x41);
  uVar4 = *(uint *)(param_1 + 0x40);
  sprintf(acStack_624,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)*(ushort *)(param_1 + 0x38),
          (uint)*(ushort *)(param_1 + 0x3a),(uint)*(ushort *)(param_1 + 0x3c),uVar4 >> 0x10,
          (uVar4 << 0x10) >> 0x18,uVar4 & 0xff,*(undefined4 *)(param_1 + 0x44));
  uVar3 = json_object_new_string(acStack_624);
  json_object_object_add(param_2,"sw_version",uVar3);
  iVar2 = apupd_db_wtp_real_state_get(param_1,&local_638);
  if (iVar2 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get state failed.\r\n";
    uVar3 = 0xc18;
    goto LAB_00641254;
  }
  memset(acStack_560,0,0x100);
  snprintf(acStack_560,0x100,"%d",iVar2);
  uVar3 = json_object_new_string(acStack_560);
  json_object_object_add(param_2,"status",uVar3);
  memset(acStack_560,0,0x100);
  snprintf(acStack_560,0x100,"%d",*(undefined4 *)(param_1 + 0x54));
  uVar3 = json_object_new_string(acStack_560);
  json_object_object_add(param_2,"upgrade_type",uVar3);
  if ((iVar2 - 6U < 2) || (iVar2 == 0x15)) {
    iVar2 = *(int *)(param_1 + 0x50);
LAB_0064129c:
    if (((*(char *)(iVar2 + 0x138) != '\x01') && (*(char *)(iVar2 + 0x138) != '\x03')) &&
       (iVar2 = apupd_db_softver_get_by_mac_without_lock(param_1 + 0x2e,&local_634), iVar2 == 0)) {
      memset(acStack_624,0,0x41);
      sprintf(acStack_624,"%d.%d.%d Build %02d%02d%02d Rel.%05d",local_634 >> 0x10,
              local_634 & 0xffff,local_630 >> 0x10,local_62c >> 0x10,(local_62c << 0x10) >> 0x18,
              local_62c & 0xff,local_628);
      pcVar5 = acStack_624;
      goto LAB_006411a8;
    }
  }
  else if (iVar2 == 0x16) {
    iVar2 = *(int *)(param_1 + 0x50);
    goto LAB_0064129c;
  }
  pcVar5 = "---";
LAB_006411a8:
  uVar3 = json_object_new_string(pcVar5);
  json_object_object_add(param_2,"new_sw_version",uVar3);
  return 0;
}

