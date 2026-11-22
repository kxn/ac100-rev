// func cloud_mngt_fail_client_handle @ 0049a074 size=1644

void cloud_mngt_fail_client_handle(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  int local_3b8;
  undefined4 local_3b4;
  uint local_3b0;
  int local_3ac;
  char local_3a8 [20];
  char acStack_394 [100];
  char acStack_330 [256];
  undefined1 auStack_230 [304];
  undefined1 auStack_100 [216];
  
  local_3ac = 0;
  memset(auStack_230,0,0x205);
  local_3b4 = 0;
  local_3b0 = 0xffffffff;
  local_3b8 = 0;
  memset(acStack_394,0,100);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_fail_client_handle start\n\n",
           "cloud_mngt_fail_client_handle",0xb7c);
  }
  if ((((ap_report_switch != 0) && (client_report_switch != 0)) && (param_1 != 0)) &&
     (iVar2 = FUN_00407fe0(param_1), iVar2 != 0)) {
    uVar3 = apmngr_db_get_ap_max();
    local_3b8 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,client_handle_hash_cmp,
                             uVar3);
    iVar2 = FUN_004081b0(param_1);
    bVar1 = false;
    for (; iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      pbVar8 = *(byte **)(iVar2 + 0xc);
      if (((pbVar8 != (byte *)0x0) &&
          (iVar4 = check_stats_consumer_bit_mask(*(undefined4 *)(pbVar8 + 0x2c),0), iVar4 != -1)) &&
         (((*(uint *)(pbVar8 + 0x30) & 1) == 0 || (pbVar8[0x12] == 5)))) {
        iVar4 = json_object_new_object();
        memset(acStack_330,0,0x100);
        snprintf(acStack_330,0x100,"%d",0x9ba7c3);
        uVar3 = json_object_new_string(acStack_330);
        json_object_object_add(iVar4,"typeId",uVar3);
        memset(acStack_394,0,100);
        time((time_t *)0x0);
        FUN_00407e70();
        snprintf(acStack_394,100,"%llu");
        uVar3 = json_object_new_string(acStack_394);
        json_object_object_add(iVar4,"time",uVar3);
        uVar3 = json_object_new_object();
        snprintf(local_3a8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*pbVar8,(uint)pbVar8[1],
                 (uint)pbVar8[2],(uint)pbVar8[3],(uint)pbVar8[4],(uint)pbVar8[5]);
        uVar5 = json_object_new_string(local_3a8);
        json_object_object_add(uVar3,"clientMac",uVar5);
        uVar5 = json_object_new_string("client");
        json_object_object_add(uVar3,"clientType",uVar5);
        iVar6 = uac_wservice_get_wserv_id(*(undefined2 *)(pbVar8 + 0xc),pbVar8[0xe],pbVar8[0xf]);
        if ((iVar6 != -1) && (iVar6 = uac_wservice_get_entry_by_id(iVar6,auStack_230), iVar6 == 0))
        {
          uVar5 = json_object_new_string(auStack_100);
          json_object_object_add(uVar3,"ssid",uVar5);
        }
        local_3a8[0] = '\0';
        local_3a8[1] = '\0';
        local_3a8[2] = '\0';
        local_3a8[3] = '\0';
        local_3a8[4] = '\0';
        local_3a8[5] = '\0';
        local_3a8[6] = '\0';
        local_3a8[7] = '\0';
        local_3a8[8] = '\0';
        local_3a8[9] = '\0';
        local_3a8[10] = '\0';
        local_3a8[0xb] = '\0';
        local_3a8[0xc] = '\0';
        local_3a8[0xd] = '\0';
        local_3a8[0xe] = '\0';
        local_3a8[0xf] = '\0';
        local_3a8[0x10] = '\0';
        local_3a8[0x11] = '\0';
        snprintf(local_3a8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)pbVar8[6],(uint)pbVar8[7],
                 (uint)pbVar8[8],(uint)pbVar8[9],(uint)pbVar8[10],(uint)pbVar8[0xb]);
        uVar5 = json_object_new_string(local_3a8);
        json_object_object_add(uVar3,"deviceMac",uVar5);
        uVar5 = json_object_new_int(0xffffffff);
        json_object_object_add(uVar3,"result",uVar5);
        uVar5 = json_object_new_int(0);
        json_object_object_add(uVar3,"failReason",uVar5);
        uVar5 = json_object_new_int(pbVar8[0x12]);
        json_object_object_add(uVar3,"failPhase",uVar5);
        if (pbVar8[0x1c] == 1) {
          local_3a8[0x10] = '\0';
          local_3a8[0x11] = '\0';
          local_3a8[0xc] = '\0';
          local_3a8[0xd] = '\0';
          local_3a8[0xe] = '\0';
          local_3a8[0xf] = '\0';
          local_3a8[0] = '\0';
          local_3a8[1] = '\0';
          local_3a8[2] = '\0';
          local_3a8[3] = '\0';
          local_3a8[4] = '\0';
          local_3a8[5] = '\0';
          local_3a8[6] = '\0';
          local_3a8[7] = '\0';
          local_3a8[8] = '\0';
          local_3a8[9] = '\0';
          local_3a8[10] = '\0';
          local_3a8[0xb] = '\0';
          snprintf(local_3a8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)pbVar8[0x1d],
                   (uint)pbVar8[0x1e],(uint)pbVar8[0x1f],(uint)pbVar8[0x20],(uint)pbVar8[0x21],
                   (uint)pbVar8[0x22]);
          uVar5 = json_object_new_string(local_3a8);
          json_object_object_add(uVar3,"bssid",uVar5);
        }
        uVar5 = json_object_new_int(pbVar8[0xe]);
        json_object_object_add(uVar3,"radioId",uVar5);
        if (*(uint *)(pbVar8 + 0x24) == 0xffffffff) {
          uVar5 = rdmngr_db_generate_rd_id(*(undefined2 *)(pbVar8 + 0xc),pbVar8[0xe]);
          iVar6 = rdmngr_db_get_freq_band_idx(uVar5,&local_3b0,&local_3b4);
          if ((iVar6 != 0) || (local_3b0 == 0xffffffff)) {
            local_3b0 = 0;
            local_3b4 = 1;
          }
        }
        else {
          local_3b4 = *(undefined4 *)(pbVar8 + 0x28);
          local_3b0 = *(uint *)(pbVar8 + 0x24);
        }
        memset(acStack_394,0,100);
        uVar7 = local_3b0;
        if (1 < local_3b0) {
          uVar7 = 0;
        }
        snprintf(acStack_394,100,"%s%d",(&band_map)[uVar7],local_3b4);
        uVar5 = json_object_new_string(acStack_394);
        json_object_object_add(uVar3,"band",uVar5);
        json_object_object_add(iVar4,"params",uVar3);
        iVar6 = _find_client_object_hash_node(local_3b8,pbVar8 + 6,&local_3ac,"eventList",1,1);
        if ((iVar6 != 0) || (local_3ac == 0)) {
          if (iVar4 != 0) {
            json_object_put(iVar4);
          }
          goto LAB_0049a108;
        }
        json_object_array_add(local_3ac,iVar4);
        bVar1 = true;
        local_3ac = 0;
      }
    }
    if (bVar1) {
      uVar3 = json_object_new_array();
      if (local_3b8 != 0) {
        FUN_00408570(local_3b8,add_client_hash_node,uVar3);
      }
      free_ac_cloud_mngt_hash(&local_3b8,0);
      cloud_mngt_event_report_handle(uVar3);
    }
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d client cloud_mngt_send_to_cloud success\n",
             "cloud_mngt_fail_client_handle",0xbe5);
    }
  }
LAB_0049a108:
  if (local_3ac != 0) {
    json_object_put();
  }
  free_ac_cloud_mngt_hash(&local_3b8,1);
  return;
}

