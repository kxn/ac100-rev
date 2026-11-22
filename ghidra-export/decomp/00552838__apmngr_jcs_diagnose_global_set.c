// func _apmngr_jcs_diagnose_global_set @ 00552838 size=564

void _apmngr_jcs_diagnose_global_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__s2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  ushort local_28 [2];
  int local_24;
  
  local_24 = 0;
  local_28[0] = 0;
  apmngr_db_telnet_enable_get(&local_24);
  iVar1 = json_object_object_get(param_1,"enable");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar6 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar6) {
            if (jcs_err_switch == 0) goto LAB_005528b0;
            pcVar4 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_005529c8;
          }
          iVar2 = iVar6 * 0x10;
          pcVar4 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
          if (pcVar4 != (char *)0x0) break;
          iVar6 = iVar6 + 1;
        }
        __s2 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar4,__s2);
        iVar6 = iVar6 + 1;
      } while (iVar3 != 0);
      iVar1 = *(int *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar4 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_005529c8:
        printf(pcVar4,"_apmngr_jcs_diagnose_global_set",0xe5);
      }
LAB_005528b0:
      if (jcs_err_switch == 0) {
        iVar1 = -1;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
               "_apmngr_jcs_diagnose_global_set",0xe5);
        iVar1 = -1;
      }
    }
    if (local_24 != iVar1) {
      apmngr_db_telnet_enable_set(iVar1);
      apmngr_ap_telnet_enable_update(iVar1);
    }
  }
  apmngr_db_telnet_port_get(local_28);
  iVar1 = json_object_object_get(param_1,"telnet_port");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
      uVar5 = atoi(pcVar4);
      uVar5 = uVar5 & 0xffff;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_diagnose_global_set",0xf1);
      }
      if (jcs_err_switch == 0) {
        uVar5 = 0xffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
               "_apmngr_jcs_diagnose_global_set",0xf1);
        uVar5 = 0xffff;
      }
    }
    if (local_28[0] != uVar5) {
      apmngr_db_telnet_port_set(uVar5);
      apmngr_ap_telnet_port_update(uVar5);
    }
  }
  return;
}

