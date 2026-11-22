// func cloud_mngt_client_events_handle @ 0049a6e0 size=1248

void cloud_mngt_client_events_handle(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  int local_a8;
  int local_a4;
  char local_a0 [20];
  char acStack_8c [100];
  
  local_a4 = 0;
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_client_handle start\n\n",
           "cloud_mngt_client_events_handle",0xb31);
  }
  if ((param_1 != 0) && (iVar1 = FUN_00407fe0(param_1), iVar1 != 0)) {
    iVar1 = FUN_004081b0(param_1);
    if (iVar1 != 0) {
      piVar11 = *(int **)(iVar1 + 0xc);
      while( true ) {
        if (piVar11 != (int *)0x0) {
          if (*piVar11 == 1) {
            if (local_a4 == 0) {
              uVar2 = apmngr_db_get_ap_max();
              local_a4 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,
                                      client_handle_hash_cmp,uVar2);
            }
            _cloud_mngt_online_client_event_object_add(local_a4,piVar11);
          }
          else if (*piVar11 == 2) {
            if (local_a4 == 0) {
              uVar2 = apmngr_db_get_ap_max();
              local_a4 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,
                                      client_handle_hash_cmp,uVar2);
            }
            iVar3 = local_a4;
            local_a8 = 0;
            local_a0[0] = '\0';
            local_a0[1] = '\0';
            local_a0[2] = '\0';
            local_a0[3] = '\0';
            local_a0[4] = '\0';
            local_a0[5] = '\0';
            local_a0[6] = '\0';
            local_a0[7] = '\0';
            local_a0[8] = '\0';
            local_a0[9] = '\0';
            local_a0[10] = '\0';
            local_a0[0xb] = '\0';
            local_a0[0xc] = '\0';
            local_a0[0xd] = '\0';
            local_a0[0xe] = '\0';
            local_a0[0xf] = '\0';
            local_a0[0x10] = '\0';
            local_a0[0x11] = '\0';
            memset(acStack_8c,0,100);
            iVar3 = _find_client_object_hash_node
                              (iVar3,piVar11 + 4,&local_a8,"eventList",0,piVar11[0x1d] & 1U ^ 1);
            if ((iVar3 == 0) && (local_a8 != 0)) {
              uVar2 = json_object_new_object();
              memset(acStack_8c,0,100);
              snprintf(acStack_8c,100,"%d",0x9ba7aa);
              uVar4 = json_object_new_string(acStack_8c);
              json_object_object_add(uVar2,"typeId",uVar4);
              memset(acStack_8c,0,100);
              snprintf(acStack_8c,100,"%llu");
              uVar4 = json_object_new_string(acStack_8c);
              json_object_object_add(uVar2,"time",uVar4);
              uVar4 = json_object_new_object();
              uVar5 = (uint)*(byte *)((int)piVar11 + 5);
              uVar6 = (uint)*(byte *)((int)piVar11 + 6);
              uVar7 = (uint)*(byte *)((int)piVar11 + 7);
              uVar8 = (uint)*(byte *)(piVar11 + 2);
              uVar9 = (uint)*(byte *)((int)piVar11 + 9);
              snprintf(local_a0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(piVar11 + 1),
                       uVar5,uVar6,uVar7,uVar8,uVar9);
              uVar10 = json_object_new_string(local_a0);
              json_object_object_add(uVar4,"clientMac",uVar10);
              if (piVar11[6] != 0) {
                memset(acStack_8c,0,100);
                snprintf(acStack_8c,100,"%d",(uint)*(ushort *)(piVar11[6] + 0xd8),uVar5,uVar6,uVar7,
                         uVar8,uVar9);
                uVar10 = json_object_new_string(acStack_8c);
                json_object_object_add(uVar4,"vlanId",uVar10);
              }
              if (*(char *)(piVar11 + 10) == '\x01') {
                local_a0[0] = '\0';
                local_a0[1] = '\0';
                local_a0[2] = '\0';
                local_a0[3] = '\0';
                local_a0[4] = '\0';
                local_a0[5] = '\0';
                local_a0[6] = '\0';
                local_a0[7] = '\0';
                local_a0[8] = '\0';
                local_a0[9] = '\0';
                local_a0[10] = '\0';
                local_a0[0xb] = '\0';
                local_a0[0xc] = '\0';
                local_a0[0xd] = '\0';
                local_a0[0xe] = '\0';
                local_a0[0xf] = '\0';
                local_a0[0x10] = '\0';
                local_a0[0x11] = '\0';
                snprintf(local_a0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",
                         (uint)*(byte *)((int)piVar11 + 0x29),(uint)*(byte *)((int)piVar11 + 0x2a),
                         (uint)*(byte *)((int)piVar11 + 0x2b),(uint)*(byte *)(piVar11 + 0xb),
                         (uint)*(byte *)((int)piVar11 + 0x2d),(uint)*(byte *)((int)piVar11 + 0x2e));
                uVar10 = json_object_new_string(local_a0);
                json_object_object_add(uVar4,"bssid",uVar10);
              }
              uVar10 = json_object_new_int(*(undefined1 *)((int)piVar11 + 0x2f));
              json_object_object_add(uVar4,"radioId",uVar10);
              uVar10 = json_object_new_int(1);
              json_object_object_add(uVar4,"offlineReason",uVar10);
              if (piVar11[0x1b] == 1) {
                uVar10 = json_object_new_int(1);
                json_object_object_add(uVar4,&DAT_0069a034,uVar10);
              }
              json_object_object_add(uVar2,"params",uVar4);
              json_object_array_add(local_a8,uVar2);
            }
          }
        }
        iVar1 = FUN_00408680(iVar1);
        if (iVar1 == 0) break;
        piVar11 = *(int **)(iVar1 + 0xc);
      }
    }
    if ((local_a4 != 0) && (iVar1 = FUN_00407ed0(), 0 < iVar1)) {
      uVar2 = json_object_new_array();
      FUN_00408570(local_a4,add_client_hash_node,uVar2);
      free_ac_cloud_mngt_hash(&local_a4,0);
      cloud_mngt_event_report_handle(uVar2);
    }
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d client cloud_mngt_obj_send_to_cloud success\n",
             "cloud_mngt_client_events_handle",0xb5f);
    }
    free_ac_cloud_mngt_hash(&local_a4,1);
  }
  return;
}

