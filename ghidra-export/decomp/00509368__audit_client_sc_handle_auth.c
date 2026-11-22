// func _audit_client_sc_handle_auth @ 00509368 size=992

void _audit_client_sc_handle_auth(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  char local_40 [24];
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (audit_err_switch == 0) {
      return;
    }
    printf("[AUDIT_ERR]%s()/%d Create json obj failed.\n","_audit_client_sc_handle_auth",0x1fd);
    return;
  }
  if (audit_debug_switch != 0) {
    printf("[AUDIT_DBG]%s()/%d build info begin\n","_audit_client_sc_handle_auth",0x201);
  }
  iVar2 = FUN_004081b0(param_1);
  iVar9 = 0;
  iVar8 = 0;
  if (iVar2 != 0) {
    iVar6 = *(int *)(iVar2 + 0xc);
    do {
      if (*(int *)(iVar6 + 0xc) == 1) {
        if (iVar8 == 0) {
          iVar8 = json_object_new_array();
          if (iVar8 == 0) goto LAB_005093fc;
          puVar7 = *(undefined4 **)(iVar6 + 0x10);
        }
        else {
          puVar7 = *(undefined4 **)(iVar6 + 0x10);
        }
        local_40[0] = '\0';
        local_40[1] = '\0';
        local_40[2] = '\0';
        local_40[3] = '\0';
        local_40[4] = '\0';
        local_40[5] = '\0';
        local_40[6] = '\0';
        local_40[7] = '\0';
        local_40[8] = '\0';
        local_40[9] = '\0';
        local_40[10] = '\0';
        local_40[0xb] = '\0';
        local_40[0xc] = '\0';
        local_40[0xd] = '\0';
        local_40[0xe] = '\0';
        local_40[0xf] = '\0';
        local_40[0x10] = '\0';
        local_40[0x11] = '\0';
        if (puVar7 == (undefined4 *)0x0) {
          if (audit_err_switch != 0) {
            pcVar4 = "[AUDIT_ERR]%s()/%d Para is invalid.\n";
            uVar3 = 0x139;
LAB_0050962c:
            printf(pcVar4,"_audit_client_sc_json_add_auth_item",uVar3);
          }
        }
        else {
          iVar6 = json_object_new_object();
          if (iVar6 == 0) {
            if (audit_err_switch != 0) {
              pcVar4 = "[AUDIT_ERR]%s()/%d Create json obj failed.\n";
              uVar3 = 0x140;
              goto LAB_0050962c;
            }
          }
          else {
            iVar9 = iVar9 + 1;
            uVar3 = json_object_new_int(*puVar7);
            json_object_object_add(iVar6,"auth_mode",uVar3);
            uVar3 = json_object_new_string(puVar7 + 1);
            json_object_object_add(iVar6,"account",uVar3);
            uVar3 = json_object_new_int((int)*(char *)(puVar7 + 0x11));
            json_object_object_add(iVar6,"ip_type",uVar3);
            uVar3 = json_object_new_string((int)puVar7 + 0x45);
            json_object_object_add(iVar6,&DAT_00677c24,uVar3);
            snprintf(local_40,0x12,"%02X:%02X:%02X:%02X:%02X:%02X",
                     (uint)*(byte *)((int)puVar7 + 0x6d),(uint)*(byte *)((int)puVar7 + 0x6e),
                     (uint)*(byte *)((int)puVar7 + 0x6f),(uint)*(byte *)(puVar7 + 0x1c),
                     (uint)*(byte *)((int)puVar7 + 0x71),(uint)*(byte *)((int)puVar7 + 0x72));
            uVar3 = json_object_new_string(local_40);
            json_object_object_add(iVar6,"usr_mac",uVar3);
            uVar3 = json_object_new_int((int)*(char *)((int)puVar7 + 0x73));
            json_object_object_add(iVar6,"onoff_flag",uVar3);
            json_object_array_add(iVar8,iVar6);
          }
        }
      }
LAB_005093fc:
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      iVar6 = *(int *)(iVar2 + 0xc);
    } while( true );
  }
  if (iVar9 != 0) {
    if (iVar8 == 0) {
      if (audit_err_switch != 0) {
        printf("[AUDIT_ERR]%s()/%d Para is invalid.\n","_audit_client_sc_json_add_auth_wrapper",
               0x15a);
      }
      goto LAB_005094ac;
    }
    iVar2 = json_object_new_object();
    if (iVar2 != 0) {
      uVar3 = json_object_new_int(iVar9);
      json_object_object_add(iVar2,"sta_auth_count",uVar3);
      json_object_object_add(iVar2,"sta_auth_list",iVar8);
      json_object_object_add(iVar1,"sta_auth_info",iVar2);
      pcVar4 = (char *)json_object_to_json_string_ext(iVar1,0);
      if (pcVar4 != (char *)0x0) {
        if (audit_debug_switch != 0) {
          printf("[AUDIT_DBG]%s()/%d Send audit auth info: %s \n","_audit_client_sc_handle_auth",
                 0x21e,pcVar4);
        }
        sVar5 = strlen(pcVar4);
        _audit_client_sc_data_send(pcVar4,sVar5);
      }
      goto LAB_005094ac;
    }
    if (audit_err_switch != 0) {
      printf("[AUDIT_ERR]%s()/%d Create json obj failed.\n","_audit_client_sc_json_add_auth_wrapper"
             ,0x161);
    }
  }
  if (iVar8 != 0) {
    json_object_put(iVar8);
  }
LAB_005094ac:
  json_object_put(iVar1);
  return;
}

