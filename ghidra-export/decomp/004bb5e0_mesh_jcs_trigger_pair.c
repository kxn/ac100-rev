// func mesh_jcs_trigger_pair @ 004bb5e0 size=1316

void mesh_jcs_trigger_pair(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined1 auStack_5b0 [100];
  int local_54c;
  undefined1 auStack_548 [300];
  char acStack_41c [1004];
  undefined4 local_30;
  int local_2c;
  
  memset(auStack_5b0,0,0x68);
  memset(acStack_41c,0,1000);
  memset(auStack_548,0,300);
  pcVar1 = (char *)mesh_db_discover_state_get();
  if (pcVar1 == (char *)0x1) {
    iVar2 = json_object_object_get(param_1,"dev_info");
    if (((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 5)) ||
       (iVar3 = json_object_array_length(iVar2), iVar3 < 1)) {
      uVar11 = 0xffffffff;
      if (mesh_err_switch != '\0') {
        pcVar1 = "[MESH_ERROR]%s()/%d Illegal object for dev_info\n";
        uVar10 = 0x5d9;
LAB_004bb728:
        uVar11 = 0xffffffff;
        printf(pcVar1,"mesh_jcs_trigger_pair",uVar10);
      }
    }
    else {
      iVar3 = 0;
      iVar12 = 0;
      while( true ) {
        iVar4 = json_object_array_length(iVar2);
        uVar11 = 0;
        if (iVar4 <= iVar12) break;
        local_30 = json_object_array_get_idx(iVar2,iVar12);
        iVar4 = json_object_object_get(local_30,"mac");
        if (iVar4 == 0) {
          uVar11 = 0xffffffff;
          if (mesh_err_switch != '\0') {
            pcVar1 = "[MESH_ERROR]%s()/%d Illegal object for mac\n";
            uVar10 = 0x5e3;
            goto LAB_004bb728;
          }
          break;
        }
        iVar5 = json_object_get_type(iVar4);
        pcVar1 = acStack_41c;
        if (iVar5 == 5) {
          for (iVar5 = 0; iVar6 = json_object_array_length(iVar4), iVar5 < iVar6; iVar5 = iVar5 + 1)
          {
            if (iVar5 == 0x32) {
              iVar5 = 0x32;
              break;
            }
            iVar6 = json_object_array_get_idx(iVar4,iVar5);
            if ((iVar6 == 0) || (iVar7 = json_object_get_type(iVar6), iVar7 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"mesh_jcs_trigger_pair",0x5e6);
              }
              pcVar9 = "";
            }
            else {
              pcVar9 = (char *)json_object_get_string(iVar6);
            }
            strncpy(pcVar1,pcVar9,0x13);
            pcVar1[0x13] = '\0';
            pcVar1 = pcVar1 + 0x14;
          }
        }
        else {
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 4) {
            iVar4 = json_object_object_length(iVar4);
            iVar5 = 0;
            if (iVar4 == 0) goto LAB_004bb7c4;
          }
          iVar5 = 0;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get stringArray with error obj or value type is unmatch.\n"
                   ,"mesh_jcs_trigger_pair",0x5e6);
          }
        }
LAB_004bb7c4:
        pcVar1 = acStack_41c;
        iVar4 = 0;
        while (iVar4 < iVar5) {
          local_2c = iVar4 * 0x14;
          iVar6 = iVar3 * 6;
          iVar7 = sscanf(pcVar1,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",auStack_548 + iVar6,
                         auStack_548 + iVar6 + 1,auStack_548 + iVar6 + 2,auStack_548 + iVar6 + 3,
                         auStack_548 + iVar6 + 4,auStack_548 + iVar6 + 5);
          if (iVar7 != 6) {
            uVar11 = 0xffffffff;
            if (mesh_err_switch == '\0') goto LAB_004bb664;
            pcVar9 = "[MESH_ERROR]%s()/%d Mac addr(%s) is illegal!\n";
            uVar10 = 0x5ed;
            pcVar1 = acStack_41c + local_2c;
            goto LAB_004bb6c8;
          }
          iVar6 = mesh_db_discover_entry_get(auStack_548 + iVar6,auStack_5b0);
          if ((iVar6 == 0) && (local_54c == 0)) {
            iVar3 = iVar3 + 1;
LAB_004bb874:
            iVar4 = iVar4 + 1;
            pcVar1 = pcVar1 + 0x14;
          }
          else {
            if (mesh_warning_switch == '\0') goto LAB_004bb874;
            printf("[MESH_WARNING]%s()/%d Can not find discover entry or state is not right of mac addr(%s)!\n"
                   ,"mesh_jcs_trigger_pair",0x5f2,pcVar1);
            iVar4 = iVar4 + 1;
            pcVar1 = pcVar1 + 0x14;
          }
        }
        iVar4 = json_object_object_get(local_30,"cap_id");
        if (iVar4 == 0) {
LAB_004bb91c:
          if (jcs_err_switch == 0) {
            pcVar1 = (char *)0xffff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "mesh_jcs_trigger_pair",0x5f8);
            pcVar1 = (char *)0xffff;
          }
        }
        else {
          iVar6 = json_object_get_type(iVar4);
          if (iVar6 != 6) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "mesh_jcs_trigger_pair",0x5f8);
            }
            goto LAB_004bb91c;
          }
          pcVar1 = (char *)json_object_get_string(iVar4);
          uVar8 = atoi(pcVar1);
          pcVar1 = (char *)(uVar8 & 0xffff);
        }
        iVar4 = mesh_pkt_re_operation_request_send(pcVar1,iVar3,auStack_548,0);
        if (iVar4 != 0) {
          uVar11 = 0xffffffff;
          if (mesh_err_switch != '\0') {
            pcVar9 = "[MESH_ERROR]%s()/%d Send pair request to AP(%d) failed!\n";
            uVar10 = 0x5fb;
            goto LAB_004bb6c8;
          }
          break;
        }
        iVar4 = mesh_db_discover_pair_state_update(auStack_548,iVar5,1);
        if (iVar4 != 0) {
          uVar11 = 0xffffffff;
          if (mesh_err_switch != '\0') {
            pcVar1 = "[MESH_ERROR]%s()/%d Refresh discover pair state failed!\n";
            uVar10 = 0x600;
            goto LAB_004bb728;
          }
          break;
        }
        iVar12 = iVar12 + 1;
      }
    }
  }
  else {
    uVar11 = 0xfffffffe;
    if (mesh_debug_switch != '\0') {
      pcVar9 = 
      "[MESH_DEBUG]%s()/%d You can\'t do dev pair in state(%d),please trigger discover first\n";
      uVar10 = 0x5d2;
LAB_004bb6c8:
      printf(pcVar9,"mesh_jcs_trigger_pair",uVar10,pcVar1);
    }
  }
LAB_004bb664:
  uVar11 = json_object_new_int(uVar11);
  json_object_object_add(param_2,&DAT_00676a24,uVar11);
  return;
}

