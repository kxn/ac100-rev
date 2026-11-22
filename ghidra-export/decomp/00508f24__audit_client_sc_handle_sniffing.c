// func _audit_client_sc_handle_sniffing @ 00508f24 size=1092

void _audit_client_sc_handle_sniffing(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  char local_60 [20];
  char acStack_4c [36];
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (audit_err_switch == 0) {
      return;
    }
    printf("[AUDIT_ERR]%s()/%d Create json obj failed.\n","_audit_client_sc_handle_sniffing",0x244);
    return;
  }
  if (audit_debug_switch != 0) {
    printf("[AUDIT_DBG]%s()/%d build info begin\n","_audit_client_sc_handle_sniffing",0x248);
  }
  iVar2 = FUN_004081b0(param_1);
  iVar9 = 0;
  iVar8 = 0;
  if (iVar2 != 0) {
    iVar6 = *(int *)(iVar2 + 0xc);
    do {
      if (*(int *)(iVar6 + 0xc) == 2) {
        if (iVar8 == 0) {
          iVar8 = json_object_new_array();
          if (iVar8 == 0) goto LAB_00508fb8;
          pbVar7 = *(byte **)(iVar6 + 0x10);
        }
        else {
          pbVar7 = *(byte **)(iVar6 + 0x10);
        }
        local_60[0] = '\0';
        local_60[1] = '\0';
        local_60[2] = '\0';
        local_60[3] = '\0';
        local_60[4] = '\0';
        local_60[5] = '\0';
        local_60[6] = '\0';
        local_60[7] = '\0';
        local_60[8] = '\0';
        local_60[9] = '\0';
        local_60[10] = '\0';
        local_60[0xb] = '\0';
        local_60[0xc] = '\0';
        local_60[0xd] = '\0';
        local_60[0xe] = '\0';
        local_60[0xf] = '\0';
        local_60[0x10] = '\0';
        local_60[0x11] = '\0';
        memset(acStack_4c,0,0x20);
        if (pbVar7 == (byte *)0x0) {
          if (audit_err_switch != 0) {
            pcVar4 = "[AUDIT_ERR]%s()/%d Para is invalid.\n";
            uVar3 = 0x175;
LAB_0050924c:
            printf(pcVar4,"_audit_client_sc_json_add_sniffing_item",uVar3);
          }
        }
        else {
          iVar6 = json_object_new_object();
          if (iVar6 == 0) {
            if (audit_err_switch != 0) {
              pcVar4 = "[AUDIT_ERR]%s()/%d Create json obj failed.\n";
              uVar3 = 0x17c;
              goto LAB_0050924c;
            }
          }
          else {
            iVar9 = iVar9 + 1;
            snprintf(local_60,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*pbVar7,(uint)pbVar7[1],
                     (uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
            uVar3 = json_object_new_string(local_60);
            json_object_object_add(iVar6,"mac",uVar3);
            uVar3 = json_object_new_int((int)(char)pbVar7[6]);
            json_object_object_add(iVar6,"type",uVar3);
            snprintf(acStack_4c,0x20,"%u",*(undefined4 *)(pbVar7 + 8));
            uVar3 = json_object_new_string(acStack_4c);
            json_object_object_add(iVar6,"start_time",uVar3);
            uVar3 = json_object_new_int(*(undefined4 *)(pbVar7 + 0xc));
            json_object_object_add(iVar6,"power",uVar3);
            snprintf(local_60,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)pbVar7[0x10],
                     (uint)pbVar7[0x11],(uint)pbVar7[0x12],(uint)pbVar7[0x13],(uint)pbVar7[0x14],
                     (uint)pbVar7[0x15]);
            uVar3 = json_object_new_string(local_60);
            json_object_object_add(iVar6,"ap_mac",uVar3);
            uVar3 = json_object_new_string(pbVar7 + 0x16);
            json_object_object_add(iVar6,"ap_ssid",uVar3);
            json_object_array_add(iVar8,iVar6);
          }
        }
      }
LAB_00508fb8:
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      iVar6 = *(int *)(iVar2 + 0xc);
    } while( true );
  }
  if (iVar9 != 0) {
    if (iVar8 == 0) {
      if (audit_err_switch != 0) {
        printf("[AUDIT_ERR]%s()/%d Para is invalid.\n","_audit_client_sc_json_add_sniffing_wrapper",
               0x19a);
      }
      goto LAB_00509068;
    }
    iVar2 = json_object_new_object();
    if (iVar2 != 0) {
      uVar3 = json_object_new_int(iVar9);
      json_object_object_add(iVar2,"sta_sniffing_count",uVar3);
      json_object_object_add(iVar2,"sta_sniffing_list",iVar8);
      json_object_object_add(iVar1,"sta_sniffing_info",iVar2);
      pcVar4 = (char *)json_object_to_json_string_ext(iVar1,0);
      if (pcVar4 != (char *)0x0) {
        if (audit_debug_switch != 0) {
          printf("[AUDIT_DBG]%s()/%d Send audit sniffing info: %s \n",
                 "_audit_client_sc_handle_sniffing",0x265,pcVar4);
        }
        sVar5 = strlen(pcVar4);
        _audit_client_sc_data_send(pcVar4,sVar5);
      }
      goto LAB_00509068;
    }
    if (audit_err_switch != 0) {
      printf("[AUDIT_ERR]%s()/%d Create json obj failed.\n",
             "_audit_client_sc_json_add_sniffing_wrapper",0x1a1);
    }
  }
  if (iVar8 != 0) {
    json_object_put(iVar8);
  }
LAB_00509068:
  json_object_put(iVar1);
  return;
}

