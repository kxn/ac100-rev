// func _cloud_mngt_online_client_info_object_add @ 0049026c size=1504

undefined4 _cloud_mngt_online_client_info_object_add(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int extraout_v1;
  char *pcVar7;
  int local_610;
  char local_60c [20];
  char local_5f8 [60];
  char acStack_5bc [100];
  undefined1 auStack_558 [32];
  undefined4 local_538;
  undefined1 local_534;
  undefined1 local_533;
  undefined4 local_51c;
  undefined4 local_518;
  undefined4 local_514;
  undefined4 local_510;
  undefined4 local_50c;
  undefined4 local_508;
  undefined4 local_504;
  undefined4 local_500;
  undefined4 local_4fc;
  undefined4 local_4f8;
  undefined1 auStack_4f0 [24];
  undefined1 auStack_4d8 [368];
  undefined1 auStack_368 [20];
  int local_354;
  undefined1 local_2e8;
  int local_21c;
  undefined1 auStack_1e8 [16];
  char local_1d8;
  
  local_610 = 0;
  memset(auStack_558,0,0x80);
  memset(auStack_4d8,0,0x16c);
  memset(auStack_368,0,0x180);
  local_5f8[0] = '\0';
  local_5f8[1] = '\0';
  local_5f8[2] = '\0';
  local_5f8[3] = '\0';
  local_5f8[4] = '\0';
  local_5f8[5] = '\0';
  local_5f8[6] = '\0';
  local_5f8[7] = '\0';
  local_5f8[8] = '\0';
  local_5f8[9] = '\0';
  local_5f8[10] = '\0';
  local_5f8[0xb] = '\0';
  local_5f8[0xc] = '\0';
  local_5f8[0xd] = '\0';
  local_5f8[0xe] = '\0';
  local_5f8[0xf] = '\0';
  local_5f8[0x10] = '\0';
  local_5f8[0x11] = '\0';
  local_5f8[0x12] = '\0';
  local_5f8[0x13] = '\0';
  local_60c[0] = '\0';
  local_60c[1] = '\0';
  local_60c[2] = '\0';
  local_60c[3] = '\0';
  local_60c[4] = '\0';
  local_60c[5] = '\0';
  local_60c[6] = '\0';
  local_60c[7] = '\0';
  local_60c[8] = '\0';
  local_60c[9] = '\0';
  local_60c[10] = '\0';
  local_60c[0xb] = '\0';
  local_60c[0xc] = '\0';
  local_60c[0xd] = '\0';
  local_60c[0xe] = '\0';
  local_60c[0xf] = '\0';
  local_60c[0x10] = '\0';
  local_60c[0x11] = '\0';
  memset(acStack_5bc,0,100);
  memset(local_5f8 + 0x14,0,0x28);
  memset(auStack_1e8,0,0x1c0);
  iVar1 = _find_client_object_hash_node(param_1,param_2 + 0x10,&local_610,"clients",0,0);
  uVar6 = 0xffffffff;
  if ((iVar1 == 0) && (local_610 != 0)) {
    strcpy(local_5f8,"none");
    uVar6 = json_object_new_object();
    snprintf(local_60c,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_2 + 4),
             (uint)*(byte *)(param_2 + 5),(uint)*(byte *)(param_2 + 6),(uint)*(byte *)(param_2 + 7),
             (uint)*(byte *)(param_2 + 8),(uint)*(byte *)(param_2 + 9));
    uVar2 = json_object_new_string(local_60c);
    json_object_object_add(uVar6,"clientMac",uVar2);
    if (*(int **)(param_2 + 0x18) != (int *)0x0) {
      if (**(int **)(param_2 + 0x18) == 0) {
        pcVar7 = "client";
      }
      else {
        pcVar7 = "guest";
      }
      uVar2 = json_object_new_string(pcVar7);
      json_object_object_add(uVar6,"clientType",uVar2);
      uVar2 = json_object_new_string(*(int *)(param_2 + 0x18) + 4);
      json_object_object_add(uVar6,"ssid",uVar2);
      uVar2 = json_object_new_int(*(undefined2 *)(*(int *)(param_2 + 0x18) + 0xd8));
      json_object_object_add(uVar6,"vlanId",uVar2);
      uVar2 = cloud_mngt_radio_type_get(*(undefined4 *)(*(int *)(param_2 + 0x18) + 0xdc));
      uVar2 = json_object_new_string(uVar2);
      json_object_object_add(uVar6,"mode",uVar2);
      memset(acStack_5bc,0,100);
      uVar3 = (uint)*(byte *)(*(int *)(param_2 + 0x18) + 0xe0);
      if (1 < uVar3) {
        uVar3 = 0;
      }
      snprintf(acStack_5bc,100,"%s%d",(&band_map)[uVar3],
               (uint)*(byte *)(*(int *)(param_2 + 0x18) + 0xe1));
      uVar2 = json_object_new_string(acStack_5bc);
      json_object_object_add(uVar6,"band",uVar2);
      FUN_00407e70();
      uVar2 = json_object_new_int(extraout_v1 - *(int *)(*(int *)(param_2 + 0x18) + 0xe4));
      json_object_object_add(uVar6,"connectTime",uVar2);
    }
    iVar1 = wsta_db_get_entry_by_mac(param_2 + 4,auStack_558);
    if (iVar1 == 0) {
      if (local_51c._0_1_ == '\x01') {
        pcVar7 = local_5f8 + 0x14;
        FUN_00408190(local_51c,local_518,local_514,local_510,local_50c,pcVar7,0x28,"0.0.0.0");
      }
      else {
        pcVar7 = "0.0.0.0";
      }
      uVar2 = json_object_new_string(pcVar7);
      json_object_object_add(uVar6,&DAT_00677c24,uVar2);
      if (local_508._0_1_ == '\x02') {
        pcVar7 = local_5f8 + 0x14;
        FUN_00408190(local_508,local_504,local_500,local_4fc,local_4f8,pcVar7,0x28,&DAT_00698ca0);
      }
      else {
        pcVar7 = "::";
      }
    }
    else {
      uVar2 = json_object_new_string("0.0.0.0");
      json_object_object_add(uVar6,&DAT_00677c24,uVar2);
      pcVar7 = "::";
    }
    uVar2 = json_object_new_string(pcVar7);
    json_object_object_add(uVar6,&DAT_00698ca4,uVar2);
    if (*(char *)(param_2 + 0x28) == '\x01') {
      local_60c[0] = '\0';
      local_60c[1] = '\0';
      local_60c[2] = '\0';
      local_60c[3] = '\0';
      local_60c[4] = '\0';
      local_60c[5] = '\0';
      local_60c[6] = '\0';
      local_60c[7] = '\0';
      local_60c[8] = '\0';
      local_60c[9] = '\0';
      local_60c[10] = '\0';
      local_60c[0xb] = '\0';
      local_60c[0xc] = '\0';
      local_60c[0xd] = '\0';
      local_60c[0xe] = '\0';
      local_60c[0xf] = '\0';
      local_60c[0x10] = '\0';
      local_60c[0x11] = '\0';
      snprintf(local_60c,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_2 + 0x29),
               (uint)*(byte *)(param_2 + 0x2a),(uint)*(byte *)(param_2 + 0x2b),
               (uint)*(byte *)(param_2 + 0x2c),(uint)*(byte *)(param_2 + 0x2d),
               (uint)*(byte *)(param_2 + 0x2e));
      pcVar7 = local_60c;
    }
    else {
      pcVar7 = "-1";
    }
    uVar2 = json_object_new_string(pcVar7);
    json_object_object_add(uVar6,"bssid",uVar2);
    uVar2 = rdmngr_db_generate_rd_id(local_538,local_534);
    iVar1 = rdmngr_db_get_rd_entry_chnl(uVar2);
    if (iVar1 < 1) {
      iVar1 = -1;
    }
    uVar2 = json_object_new_int(iVar1);
    json_object_object_add(uVar6,"channel",uVar2);
    iVar1 = stats_db_sta_get(param_2 + 4,auStack_1e8,0);
    if ((iVar1 == 0) && (uVar3 = (int)local_1d8 & 0xffff, (int)local_1d8 != 2)) {
      if (uVar3 < 8) {
        pcVar7 = (&PTR_DAT_0069b4b4)[uVar3];
      }
      else {
        pcVar7 = "---";
      }
      uVar2 = json_object_new_string(pcVar7);
      json_object_object_add(uVar6,&DAT_00698cb4,uVar2);
    }
    uVar2 = 1;
    iVar1 = uac_wservice_get_wserv_id(local_538,local_534,local_533);
    if ((iVar1 != -1) && (iVar4 = wportal_db_ssid_rdt_get(iVar1,auStack_4d8), iVar4 == 0)) {
      iVar4 = wportal_db_aut_get(auStack_4f0,auStack_368);
      if ((iVar4 == 0) && ((local_21c != 0xf && (local_354 == iVar1)))) {
        cloud_mngt_authentication_real_type_get(local_2e8,local_5f8,0x14);
      }
      else {
        uVar2 = 0;
        cloud_mngt_authentication_type_get(auStack_4d8,local_5f8,0x14);
      }
    }
    uVar5 = json_object_new_string(local_5f8);
    json_object_object_add(uVar6,"authentication",uVar5);
    uVar2 = json_object_new_int(uVar2);
    json_object_object_add(uVar6,"status",uVar2);
    json_object_array_add(local_610,uVar6);
    uVar6 = 0;
  }
  return uVar6;
}

