// func cloud_mngt_client_add_to_json @ 004937c0 size=1952

/* WARNING: Type propagation algorithm not settling */

undefined4 cloud_mngt_client_add_to_json(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int extraout_v1;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int local_c30;
  int local_c2c;
  undefined4 local_c28;
  uint local_c24 [2];
  undefined2 local_c1c;
  char local_c18 [12];
  char local_c0c [20];
  char acStack_bf8 [40];
  undefined1 auStack_bd0 [9];
  char local_bc7;
  char acStack_b7c [100];
  undefined1 auStack_b18 [104];
  undefined1 auStack_ab0 [8];
  byte local_aa8;
  byte local_aa7;
  byte local_aa6;
  byte local_aa5;
  byte local_aa4;
  byte local_aa3;
  byte local_aa2;
  undefined1 auStack_9b0 [368];
  undefined1 auStack_840 [20];
  int local_82c;
  undefined1 local_7c0;
  int local_6f4;
  undefined1 auStack_6c0 [16];
  char local_6b0;
  undefined1 auStack_500 [304];
  undefined1 auStack_3d0 [216];
  undefined1 auStack_2f8 [20];
  undefined4 local_2e4;
  undefined1 auStack_2b0 [381];
  char local_133;
  
  local_c0c[0] = '\0';
  local_c0c[1] = '\0';
  local_c0c[2] = '\0';
  local_c0c[3] = '\0';
  local_c0c[4] = '\0';
  local_c0c[5] = '\0';
  local_c0c[6] = '\0';
  local_c0c[7] = '\0';
  local_c0c[8] = '\0';
  local_c0c[9] = '\0';
  local_c0c[10] = '\0';
  local_c0c[0xb] = '\0';
  local_c0c[0xc] = '\0';
  local_c0c[0xd] = '\0';
  local_c0c[0xe] = '\0';
  local_c0c[0xf] = '\0';
  local_c0c[0x10] = '\0';
  local_c0c[0x11] = '\0';
  local_c24[1] = 0;
  local_c1c = 0;
  memset(acStack_bf8,0,0x28);
  memset(auStack_b18,0,100);
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_500,0,0x205);
  memset(auStack_bd0,0,0x54);
  memset(auStack_840,0,0x180);
  memset(auStack_9b0,0,0x16c);
  memset(acStack_b7c,0,100);
  local_c24[0] = 0xffffffff;
  local_c28 = 0;
  local_c18[0] = '\0';
  local_c18[1] = '\0';
  local_c18[2] = '\0';
  local_c18[3] = '\0';
  local_c18[4] = '\0';
  local_c18[5] = '\0';
  local_c18[6] = '\0';
  local_c18[7] = '\0';
  local_c18[8] = '\0';
  local_c18[9] = '\0';
  local_c2c = 0;
  memset(auStack_6c0,0,0x1c0);
  memset(auStack_ab0,0,0x100);
  local_c30 = 0;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_2f8);
  if (iVar1 == -1) {
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n","cloud_mngt_client_add_to_json",
           0x11ae);
    return 0xffffffff;
  }
  if (local_133 == '\0') {
    return 0;
  }
  iVar1 = _cloud_mngt_role_match(local_2e4);
  if (iVar1 == 0) {
    return 0;
  }
  iVar6 = 0;
  iVar1 = FUN_00407fa0(*(undefined4 *)(param_2 + 0x2c),auStack_2b0);
  if (iVar1 == 0) {
    iVar6 = -1;
  }
  local_c30 = 0;
  iVar1 = _find_client_object_hash_node
                    (*(undefined4 *)(param_2 + 0x2c),auStack_2b0,&local_c2c,"clients",0,0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (local_c2c == 0) {
    return 0xffffffff;
  }
  uVar7 = 0;
  if (iVar6 == -1) {
    iVar1 = FUN_00407fa0(*(undefined4 *)(param_2 + 0x2c),auStack_2b0);
    uVar7 = *(undefined4 *)(iVar1 + 0xc);
    local_c30 = 0;
  }
  iVar1 = json_object_new_object();
  uVar2 = json_object_new_string("client");
  json_object_object_add(iVar1,"clientType",uVar2);
  uVar2 = rdmngr_db_generate_rd_id(*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
  iVar6 = rdmngr_db_rd_entry_get(uVar2,auStack_bd0);
  if (iVar6 == 0) {
    iVar6 = uac_wservice_get_wserv_id
                      (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                       *(undefined1 *)(param_1 + 0x25));
    if ((iVar6 != -1) && (iVar3 = uac_wservice_get_entry_by_id(iVar6,auStack_500), iVar3 == 0)) {
      uVar2 = rdmngr_db_generate_rd_id
                        (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
      iVar3 = rdmngr_db_get_freq_band_idx(uVar2,local_c24,&local_c28);
      if (iVar3 == 0) {
        iVar3 = stats_db_ssid_get(*(undefined2 *)(param_1 + 0x22),*(undefined1 *)(param_1 + 0x24),
                                  *(undefined1 *)(param_1 + 0x25),auStack_ab0);
        if ((iVar3 == 0) && ((local_aa8 & 3) == 3)) {
          local_c0c[0] = '\0';
          local_c0c[1] = '\0';
          local_c0c[2] = '\0';
          local_c0c[3] = '\0';
          local_c0c[4] = '\0';
          local_c0c[5] = '\0';
          local_c0c[6] = '\0';
          local_c0c[7] = '\0';
          local_c0c[8] = '\0';
          local_c0c[9] = '\0';
          local_c0c[10] = '\0';
          local_c0c[0xb] = '\0';
          local_c0c[0xc] = '\0';
          local_c0c[0xd] = '\0';
          local_c0c[0xe] = '\0';
          local_c0c[0xf] = '\0';
          local_c0c[0x10] = '\0';
          local_c0c[0x11] = '\0';
          snprintf(local_c0c,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_aa7,(uint)local_aa6,
                   (uint)local_aa5,(uint)local_aa4,(uint)local_aa3,(uint)local_aa2);
          pcVar5 = local_c0c;
        }
        else {
          pcVar5 = "-1";
        }
        uVar2 = json_object_new_string(pcVar5);
        json_object_object_add(iVar1,"bssid",uVar2);
        uVar2 = json_object_new_string(auStack_3d0);
        json_object_object_add(iVar1,"ssid",uVar2);
        local_c0c[0] = '\0';
        local_c0c[1] = '\0';
        local_c0c[2] = '\0';
        local_c0c[3] = '\0';
        local_c0c[4] = '\0';
        local_c0c[5] = '\0';
        local_c0c[6] = '\0';
        local_c0c[7] = '\0';
        local_c0c[8] = '\0';
        local_c0c[9] = '\0';
        local_c0c[10] = '\0';
        local_c0c[0xb] = '\0';
        local_c0c[0xc] = '\0';
        local_c0c[0xd] = '\0';
        local_c0c[0xe] = '\0';
        local_c0c[0xf] = '\0';
        local_c0c[0x10] = '\0';
        local_c0c[0x11] = '\0';
        snprintf(local_c0c,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x68),
                 (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
                 (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
                 (uint)*(byte *)(param_1 + 0x6d));
        uVar2 = json_object_new_string(local_c0c);
        json_object_object_add(iVar1,"clientMac",uVar2);
        if (*(char *)(param_1 + 0x3c) == '\x01') {
          pcVar5 = acStack_bf8;
          FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                       *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                       *(undefined4 *)(param_1 + 0x4c),pcVar5,0x28,"0.0.0.0");
        }
        else {
          pcVar5 = "0.0.0.0";
        }
        uVar2 = json_object_new_string(pcVar5);
        json_object_object_add(iVar1,&DAT_00677c24,uVar2);
        if (*(char *)(param_1 + 0x50) == '\x02') {
          pcVar5 = acStack_bf8;
          FUN_00408190(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                       *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                       *(undefined4 *)(param_1 + 0x60),pcVar5,0x28,&DAT_00698ca0);
        }
        else {
          pcVar5 = "::";
        }
        uVar2 = json_object_new_string(pcVar5);
        json_object_object_add(iVar1,&DAT_00698ca4,uVar2);
        uVar2 = json_object_new_int(*(undefined2 *)(param_1 + 0x2e));
        json_object_object_add(iVar1,"vlanId",uVar2);
        uVar2 = cloud_mngt_radio_type_get((int)local_bc7);
        uVar2 = json_object_new_string(uVar2);
        json_object_object_add(iVar1,"mode",uVar2);
        uVar4 = local_c24[0];
        if (1 < local_c24[0]) {
          uVar4 = 0;
        }
        snprintf(local_c18,10,"%s%d",(&band_map)[uVar4],local_c28);
        uVar2 = json_object_new_string(local_c18);
        json_object_object_add(iVar1,"band",uVar2);
        memcpy(local_c24 + 1,(void *)(param_1 + 0x68),6);
        iVar3 = wportal_db_ssid_rdt_get(iVar6,auStack_9b0);
        if (iVar3 == 0) {
          iVar3 = wportal_db_aut_get(local_c24 + 1,auStack_840);
          if (((iVar3 == 0) && (local_6f4 != 0xf)) && (local_82c == iVar6)) {
            uVar2 = json_object_new_int(1);
            json_object_object_add(iVar1,"status",uVar2);
            cloud_mngt_authentication_real_type_get(local_7c0,acStack_b7c,100);
          }
          else {
            uVar2 = json_object_new_int(0);
            json_object_object_add(iVar1,"status",uVar2);
            cloud_mngt_authentication_type_get(auStack_9b0,acStack_b7c,100);
          }
        }
        else {
          strcpy(acStack_b7c,"none");
          uVar2 = json_object_new_int(1);
          json_object_object_add(iVar1,"status",uVar2);
        }
        iVar6 = stats_db_sta_get(param_1 + 0x68,auStack_6c0,0);
        if ((iVar6 == 0) && (uVar4 = (int)local_6b0 & 0xffff, (int)local_6b0 != 2)) {
          if (uVar4 < 8) {
            pcVar5 = (&PTR_DAT_0069b4b4)[uVar4];
          }
          else {
            pcVar5 = "---";
          }
          uVar2 = json_object_new_string(pcVar5);
          json_object_object_add(iVar1,&DAT_00698cb4,uVar2);
        }
        uVar2 = json_object_new_string(acStack_b7c);
        json_object_object_add(iVar1,"authentication",uVar2);
        memset(auStack_b18,0,100);
        FUN_00407e70();
        uVar2 = json_object_new_int(extraout_v1 - *(int *)(param_1 + 0x78));
        json_object_object_add(iVar1,"connectTime",uVar2);
        uVar2 = rdmngr_db_generate_rd_id
                          (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
        iVar6 = rdmngr_db_get_rd_entry_chnl(uVar2);
        if (iVar6 < 1) {
          iVar6 = -1;
        }
        uVar2 = json_object_new_int(iVar6);
        json_object_object_add(iVar1,"channel",uVar2);
        if (*(int *)(param_2 + 0xc) == 0) {
          iVar6 = json_object_new_array();
          *(int *)(param_2 + 4) = iVar6;
          if (iVar6 == 0) goto LAB_00493eb8;
        }
        iVar6 = after_handle_client_json(param_2,uVar7,&local_c30,auStack_2f8,local_c2c,iVar1);
        if (iVar6 == 0) {
          return 0;
        }
        if (iVar1 != 0) {
          json_object_put(iVar1);
        }
        if (local_c30 == 0) {
          return 0;
        }
        if (*(int *)(local_c30 + 8) != 0) {
          json_object_put();
        }
        FUN_00407df0(local_c30);
        return 0;
      }
    }
  }
LAB_00493eb8:
  json_object_put(iVar1);
  return 0xffffffff;
}

