// func _cloud_mngt_online_client_event_object_add @ 0049084c size=1948

undefined4 _cloud_mngt_online_client_event_object_add(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *__s;
  ushort uVar10;
  int local_498;
  char local_494 [20];
  char acStack_480 [100];
  undefined1 auStack_41c [37];
  byte local_3f7;
  char local_3e7;
  undefined1 auStack_398 [360];
  char local_230 [300];
  int local_104;
  undefined1 auStack_100 [220];
  
  local_498 = 0;
  local_494[0] = '\0';
  local_494[1] = '\0';
  local_494[2] = '\0';
  local_494[3] = '\0';
  local_494[4] = '\0';
  local_494[5] = '\0';
  local_494[6] = '\0';
  local_494[7] = '\0';
  local_494[8] = '\0';
  local_494[9] = '\0';
  local_494[10] = '\0';
  local_494[0xb] = '\0';
  local_494[0xc] = '\0';
  local_494[0xd] = '\0';
  local_494[0xe] = '\0';
  local_494[0xf] = '\0';
  local_494[0x10] = '\0';
  local_494[0x11] = '\0';
  memset(acStack_480,0,100);
  memset(auStack_41c,0,0x80);
  memset(local_230,0,0x205);
  memset(auStack_398,0,0x168);
  iVar3 = _find_client_object_hash_node
                    (param_1,param_2 + 0x10,&local_498,"eventList",0,
                     *(uint *)(param_2 + 0x74) & 1 ^ 1);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (local_498 == 0) {
    return 0xffffffff;
  }
  uVar4 = json_object_new_object();
  memset(acStack_480,0,100);
  snprintf(acStack_480,100,"%d",0x9ba7c2);
  uVar5 = json_object_new_string(acStack_480);
  json_object_object_add(uVar4,"typeId",uVar5);
  memset(acStack_480,0,100);
  snprintf(acStack_480,100,"%llu");
  uVar5 = json_object_new_string(acStack_480);
  json_object_object_add(uVar4,"time",uVar5);
  uVar5 = json_object_new_object();
  snprintf(local_494,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_2 + 4),
           (uint)*(byte *)(param_2 + 5),(uint)*(byte *)(param_2 + 6),(uint)*(byte *)(param_2 + 7),
           (uint)*(byte *)(param_2 + 8),(uint)*(byte *)(param_2 + 9));
  uVar6 = json_object_new_string(local_494);
  json_object_object_add(uVar5,"clientMac",uVar6);
  uVar6 = json_object_new_string("client");
  json_object_object_add(uVar5,"clientType",uVar6);
  if (*(int *)(param_2 + 0x18) == 0) {
    uVar10 = 0;
    iVar3 = wsta_db_get_entry_by_mac(param_2 + 4,auStack_41c);
    if (iVar3 == 0) {
      uVar6 = json_object_new_int((int)local_3e7);
      json_object_object_add(uVar5,"rssi",uVar6);
      uVar10 = (ushort)local_3f7;
      goto LAB_00490b44;
    }
    uVar2 = *(undefined2 *)(param_2 + 0x70);
  }
  else {
    uVar6 = json_object_new_string(*(int *)(param_2 + 0x18) + 4);
    json_object_object_add(uVar5,"ssid",uVar6);
    uVar6 = cloud_mngt_radio_type_get(*(undefined4 *)(*(int *)(param_2 + 0x18) + 0xdc));
    uVar6 = json_object_new_string(uVar6);
    json_object_object_add(uVar5,"mode",uVar6);
    uVar6 = json_object_new_int(*(undefined2 *)(*(int *)(param_2 + 0x18) + 0xd8));
    json_object_object_add(uVar5,"vlanId",uVar6);
    memset(acStack_480,0,100);
    uVar7 = (uint)*(byte *)(*(int *)(param_2 + 0x18) + 0xe0);
    if (1 < uVar7) {
      uVar7 = 0;
    }
    snprintf(acStack_480,100,"%s%d",(&band_map)[uVar7],
             (uint)*(byte *)(*(int *)(param_2 + 0x18) + 0xe1));
    uVar6 = json_object_new_string(acStack_480);
    json_object_object_add(uVar5,"band",uVar6);
    uVar6 = json_object_new_int(*(undefined4 *)(*(int *)(param_2 + 0x18) + 0xd4));
    json_object_object_add(uVar5,"rssi",uVar6);
    uVar10 = *(ushort *)(*(int *)(param_2 + 0x18) + 0xd8);
LAB_00490b44:
    uVar2 = *(undefined2 *)(param_2 + 0x70);
  }
  uVar6 = rdmngr_db_generate_rd_id(uVar2,*(undefined1 *)(param_2 + 0x2f));
  iVar3 = wserv_db_rd_get_wserv_id(uVar6,uVar10 & 0xff);
  if (iVar3 != -1) {
    iVar3 = uac_wservice_get_entry_by_id(iVar3,local_230);
    if (iVar3 != 0) {
      iVar3 = *(int *)(param_2 + 0x18);
      goto LAB_00490bdc;
    }
    if (local_230[0] == '\0') {
      uVar6 = json_object_new_string(auStack_100);
      json_object_object_add(uVar5,"ssid",uVar6);
      if (local_104 - 1U < 2) {
        pcVar9 = (&PTR_s_unknown_0069b874)[local_104];
      }
      else {
        pcVar9 = "unknown";
      }
      uVar6 = json_object_new_string(pcVar9);
      pcVar9 = "ssidEncode";
    }
    else {
      uVar6 = json_object_new_string(local_230);
      pcVar9 = "ssidId";
    }
    json_object_object_add(uVar5,pcVar9,uVar6);
  }
  iVar3 = *(int *)(param_2 + 0x18);
LAB_00490bdc:
  if (iVar3 != 0) {
    local_3e7 = *(char *)(iVar3 + 0xd7);
  }
  uVar6 = estimate_snr_from_rssi((int)local_3e7,0);
  memset(auStack_398,0,0x168);
  iVar3 = stats_db_radio_get_total
                    (*(undefined2 *)(param_2 + 0x70),*(undefined1 *)(param_2 + 0x2f),auStack_398,1);
  if (iVar3 == 0) {
    uVar8 = json_object_new_int(uVar6);
    json_object_object_add(uVar5,&DAT_00698ce4,uVar8);
    iVar3 = get_estimate_by_stat
                      (param_2 + 4,(int)local_3e7,*(undefined2 *)(param_2 + 0x70),
                       *(undefined1 *)(param_2 + 0x2f),auStack_398);
    uVar8 = json_object_new_int(iVar3 << 10);
    json_object_object_add(uVar5,"rxRate",uVar8);
    uVar8 = json_object_new_int(iVar3 << 10);
    json_object_object_add(uVar5,"txRate",uVar8);
  }
  uVar6 = json_object_new_int(uVar6);
  json_object_object_add(uVar5,&DAT_00698ce4,uVar6);
  local_494[0] = '\0';
  local_494[1] = '\0';
  local_494[2] = '\0';
  local_494[3] = '\0';
  local_494[4] = '\0';
  local_494[5] = '\0';
  local_494[6] = '\0';
  local_494[7] = '\0';
  local_494[8] = '\0';
  local_494[9] = '\0';
  local_494[10] = '\0';
  local_494[0xb] = '\0';
  local_494[0xc] = '\0';
  local_494[0xd] = '\0';
  local_494[0xe] = '\0';
  local_494[0xf] = '\0';
  local_494[0x10] = '\0';
  local_494[0x11] = '\0';
  snprintf(local_494,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_2 + 0x10),
           (uint)*(byte *)(param_2 + 0x11),(uint)*(byte *)(param_2 + 0x12),
           (uint)*(byte *)(param_2 + 0x13),(uint)*(byte *)(param_2 + 0x14),
           (uint)*(byte *)(param_2 + 0x15));
  uVar6 = json_object_new_string(local_494);
  json_object_object_add(uVar5,"deviceMac",uVar6);
  uVar6 = json_object_new_int(0);
  json_object_object_add(uVar5,"result",uVar6);
  uVar6 = json_object_new_int(*(undefined1 *)(param_2 + 0x2f));
  json_object_object_add(uVar5,"radioId",uVar6);
  if (*(char *)(param_2 + 0x28) == '\x01') {
    local_494[0] = '\0';
    local_494[1] = '\0';
    local_494[2] = '\0';
    local_494[3] = '\0';
    local_494[4] = '\0';
    local_494[5] = '\0';
    local_494[6] = '\0';
    local_494[7] = '\0';
    local_494[8] = '\0';
    local_494[9] = '\0';
    local_494[10] = '\0';
    local_494[0xb] = '\0';
    local_494[0xc] = '\0';
    local_494[0xd] = '\0';
    local_494[0xe] = '\0';
    local_494[0xf] = '\0';
    local_494[0x10] = '\0';
    local_494[0x11] = '\0';
    snprintf(local_494,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_2 + 0x29),
             (uint)*(byte *)(param_2 + 0x2a),(uint)*(byte *)(param_2 + 0x2b),
             (uint)*(byte *)(param_2 + 0x2c),(uint)*(byte *)(param_2 + 0x2d),
             (uint)*(byte *)(param_2 + 0x2e));
    uVar6 = json_object_new_string(local_494);
    json_object_object_add(uVar5,"bssid",uVar6);
    uVar1 = *(undefined1 *)(param_2 + 0x2f);
  }
  else {
    uVar1 = *(undefined1 *)(param_2 + 0x2f);
  }
  uVar6 = json_object_new_int(uVar1);
  json_object_object_add(uVar5,"radioId",uVar6);
  memset(acStack_480,0,100);
  if (*(char *)(param_2 + 0x30) == '\x01') {
    FUN_00408190(*(undefined4 *)(param_2 + 0x30),*(undefined4 *)(param_2 + 0x34),
                 *(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_2 + 0x3c),
                 *(undefined4 *)(param_2 + 0x40),acStack_480,0x28,"0.0.0.0");
    pcVar9 = acStack_480;
    if (*(char *)(param_2 + 0x30) != '\x01') {
      pcVar9 = "0.0.0.0";
    }
  }
  else {
    pcVar9 = "0.0.0.0";
  }
  __s = acStack_480;
  uVar6 = json_object_new_string(pcVar9);
  json_object_object_add(uVar5,&DAT_00677c24,uVar6);
  memset(__s,0,100);
  if (*(char *)(param_2 + 0x44) == '\x02') {
    FUN_00408190(*(undefined4 *)(param_2 + 0x44),*(undefined4 *)(param_2 + 0x48),
                 *(undefined4 *)(param_2 + 0x4c),*(undefined4 *)(param_2 + 0x50),
                 *(undefined4 *)(param_2 + 0x54),__s,0x28,&DAT_00698ca0);
  }
  else {
    __s = "::";
  }
  uVar6 = json_object_new_string(__s);
  json_object_object_add(uVar5,&DAT_00698ca4,uVar6);
  uVar6 = json_object_new_int(*(undefined4 *)(param_2 + 0x78));
  json_object_object_add(uVar5,"authStatus",uVar6);
  uVar6 = json_object_new_string(param_2 + 0x58);
  json_object_object_add(uVar5,"authentication",uVar6);
  json_object_object_add(uVar4,"params",uVar5);
  json_object_array_add(local_498,uVar4);
  return 0;
}

