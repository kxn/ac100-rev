// func _audit_client_jcs_set_cb @ 005088a0 size=724

void _audit_client_jcs_set_cb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__s2;
  char *pcVar3;
  int iVar4;
  int local_90;
  undefined1 auStack_8c [32];
  int local_6c [9];
  char acStack_48 [39];
  undefined1 local_21;
  
  memset(local_6c,0,0x24);
  memset(&local_90,0,0x24);
  memset(acStack_48,0,0x28);
  memset(&local_90,0,0x24);
  iVar1 = json_object_object_get(param_1,"enable");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar4 = 0;
    if (iVar2 == 6) {
      while (iVar4 < onoff_map) {
        pcVar3 = *(char **)(PTR__mt_onoff_00731f8c + iVar4 * 0x10);
        if (pcVar3 == (char *)0x0) {
          iVar4 = iVar4 + 1;
        }
        else {
          __s2 = (char *)json_object_get_string(iVar1);
          iVar2 = strcmp(pcVar3,__s2);
          if (iVar2 == 0) {
            iVar1 = *(int *)(PTR__mt_onoff_00731f8c + iVar4 * 0x10 + 0xc);
            goto LAB_00508958;
          }
          iVar4 = iVar4 + 1;
        }
      }
      if (jcs_err_switch == 0) goto LAB_00508948;
      pcVar3 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
    }
    else {
      if (jcs_err_switch == 0) goto LAB_00508948;
      pcVar3 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
    }
    printf(pcVar3,"_audit_client_jcs_set_cb",0x58);
  }
LAB_00508948:
  if (jcs_err_switch == 0) {
    iVar1 = -1;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_audit_client_jcs_set_cb",
           0x58);
    iVar1 = -1;
  }
LAB_00508958:
  local_90 = iVar1;
  iVar2 = audit_client_use_local_server();
  if (iVar2 == 0) {
    iVar2 = json_object_object_get(param_1,"remote_ip");
    if ((iVar2 == 0) || (iVar4 = json_object_get_type(iVar2), iVar4 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_audit_client_jcs_set_cb",0x5e);
      }
      pcVar3 = "";
    }
    else {
      pcVar3 = (char *)json_object_get_string(iVar2);
    }
    strncpy(acStack_48,pcVar3,0x27);
    local_21 = 0;
  }
  else {
    snprintf(acStack_48,0x28,"127.0.0.1");
  }
  FUN_0051a7a8(acStack_48,auStack_8c);
  if (audit_debug_switch != 0) {
    printf("[AUDIT_DBG]%s()/%d Set audit server ip = %s, enable = %d\n","_audit_client_jcs_set_cb",
           0x66,acStack_48,iVar1);
  }
  audit_client_db_server_get(local_6c);
  audit_client_db_server_set(&local_90);
  if ((local_6c[0] != local_90) && (audit_client_pkt_ctl_update_to_all_ap(), local_90 == 0)) {
    audit_client_db_msg_queue_clear();
    FUN_00407ea0(audit_auth_sc);
    FUN_00407ea0(audit_sniffing_sc);
  }
  return;
}

