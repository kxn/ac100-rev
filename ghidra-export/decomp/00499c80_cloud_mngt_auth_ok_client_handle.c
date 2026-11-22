// func cloud_mngt_auth_ok_client_handle @ 00499c80 size=1012

void cloud_mngt_auth_ok_client_handle(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int local_1a8;
  int local_1a4;
  char acStack_1a0 [20];
  char acStack_18c [100];
  char acStack_128 [256];
  
  local_1a4 = 0;
  local_1a8 = 0;
  memset(acStack_18c,0,100);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_fail_client_handle start\n\n",
           "cloud_mngt_auth_ok_client_handle",0xc08);
  }
  if ((((ap_report_switch != 0) && (client_report_switch != 0)) && (param_1 != 0)) &&
     (iVar2 = FUN_00407fe0(param_1), iVar2 != 0)) {
    uVar3 = apmngr_db_get_ap_max();
    local_1a8 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,client_handle_hash_cmp,
                             uVar3);
    iVar2 = FUN_004081b0(param_1);
    bVar1 = false;
    for (; iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      pbVar7 = *(byte **)(iVar2 + 0xc);
      if ((pbVar7 != (byte *)0x0) &&
         (iVar4 = check_stats_consumer_bit_mask(*(undefined4 *)(pbVar7 + 0x18),0), iVar4 != -1)) {
        iVar4 = json_object_new_object();
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",0x9ba7c6);
        uVar3 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"typeId",uVar3);
        memset(acStack_18c,0,100);
        time((time_t *)0x0);
        FUN_00407e70();
        snprintf(acStack_18c,100,"%llu");
        uVar3 = json_object_new_string(acStack_18c);
        json_object_object_add(iVar4,"time",uVar3);
        uVar3 = json_object_new_object();
        snprintf(acStack_1a0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*pbVar7,(uint)pbVar7[1],
                 (uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
        uVar5 = json_object_new_string(acStack_1a0);
        json_object_object_add(uVar3,"clientMac",uVar5);
        uVar5 = json_object_new_int(1);
        json_object_object_add(uVar3,"status",uVar5);
        memset(acStack_18c,0,100);
        cloud_mngt_authentication_real_type_get(pbVar7[0x13],acStack_18c,100);
        uVar5 = json_object_new_string(acStack_18c);
        json_object_object_add(uVar3,"authentication",uVar5);
        json_object_object_add(iVar4,"params",uVar3);
        iVar6 = _find_client_object_hash_node(local_1a8,pbVar7 + 6,&local_1a4,"eventList",1,1);
        if ((iVar6 != 0) || (local_1a4 == 0)) {
          if (iVar4 != 0) {
            json_object_put(iVar4);
          }
          goto LAB_00499cf8;
        }
        bVar1 = true;
        json_object_array_add(local_1a4,iVar4);
        local_1a4 = 0;
      }
    }
    if (bVar1) {
      uVar3 = json_object_new_array();
      if (local_1a8 != 0) {
        FUN_00408570(local_1a8,add_client_hash_node,uVar3);
      }
      free_ac_cloud_mngt_hash(&local_1a8,0);
      cloud_mngt_event_report_handle(uVar3);
    }
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d client cloud_mngt_send_to_cloud success\n",
             "cloud_mngt_auth_ok_client_handle",0xc4f);
    }
  }
LAB_00499cf8:
  if (local_1a4 != 0) {
    json_object_put();
  }
  free_ac_cloud_mngt_hash(&local_1a8,1);
  return;
}

