// func _apmngr_jcs_aplog_set @ 00552a6c size=1424

void _apmngr_jcs_aplog_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined1 local_e8 [20];
  int local_d4;
  undefined4 local_d0;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  char acStack_ac [127];
  undefined1 local_2d;
  
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  memset(acStack_ac,0,0x80);
  iVar1 = json_object_object_get(param_1,"ac_log_switch");
  if (iVar1 == 0) {
LAB_00552b00:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_aplog_set",
             0xbd);
    }
    iVar1 = -1;
LAB_00552b14:
    iVar2 = json_object_object_get(param_1,"ac_log_level");
    if (iVar2 != 0) {
      iVar8 = json_object_get_type(iVar2);
      if (iVar8 == 6) {
        pcVar7 = (char *)json_object_get_string(iVar2);
        iVar2 = atoi(pcVar7);
        goto LAB_00552b78;
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_aplog_set",0xc1);
      }
    }
    if (jcs_err_switch == 0) {
      iVar2 = -1;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_aplog_set",
             0xc1);
      iVar2 = -1;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        pcVar7 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00552d0c:
        printf(pcVar7,"_apmngr_jcs_aplog_set",0xbd);
      }
      goto LAB_00552b00;
    }
    do {
      while( true ) {
        if (onoff_map <= iVar8) {
          if (jcs_err_switch == 0) goto LAB_00552b00;
          pcVar7 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
          goto LAB_00552d0c;
        }
        iVar2 = iVar8 * 0x10;
        pcVar7 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
        if (pcVar7 != (char *)0x0) break;
        iVar8 = iVar8 + 1;
      }
      pcVar5 = (char *)json_object_get_string(iVar1);
      iVar3 = strcmp(pcVar7,pcVar5);
      iVar8 = iVar8 + 1;
    } while (iVar3 != 0);
    iVar1 = *(int *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    iVar2 = 3;
    if (iVar1 != 0) goto LAB_00552b14;
  }
LAB_00552b78:
  iVar8 = json_object_object_get(param_1,"remote_server_switch");
  if (iVar8 == 0) {
LAB_00552bb8:
    if (jcs_err_switch == 0) {
      iVar8 = -1;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_aplog_set",
             0xc5);
      iVar8 = -1;
    }
  }
  else {
    iVar3 = json_object_get_type(iVar8);
    iVar9 = 0;
    if (iVar3 != 6) {
      if (jcs_err_switch != 0) {
        pcVar7 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00552d44:
        printf(pcVar7,"_apmngr_jcs_aplog_set",0xc5);
      }
      goto LAB_00552bb8;
    }
    do {
      while( true ) {
        if (onoff_map <= iVar9) {
          if (jcs_err_switch == 0) goto LAB_00552bb8;
          pcVar7 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
          goto LAB_00552d44;
        }
        iVar3 = iVar9 * 0x10;
        pcVar7 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
        if (pcVar7 != (char *)0x0) break;
        iVar9 = iVar9 + 1;
      }
      pcVar5 = (char *)json_object_get_string(iVar8);
      iVar4 = strcmp(pcVar7,pcVar5);
      iVar9 = iVar9 + 1;
    } while (iVar4 != 0);
    iVar8 = *(int *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
    local_d4 = 0x14;
    if (iVar8 == 0) {
      iVar3 = 0;
      goto LAB_00552dc4;
    }
  }
  iVar3 = json_object_object_get(param_1,"remote_log_level");
  if (iVar3 == 0) {
LAB_00552c20:
    if (jcs_err_switch == 0) {
      iVar3 = -1;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_aplog_set",
             0xc9);
      iVar3 = -1;
    }
  }
  else {
    iVar9 = json_object_get_type(iVar3);
    if (iVar9 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_aplog_set",0xc9);
      }
      goto LAB_00552c20;
    }
    pcVar7 = (char *)json_object_get_string(iVar3);
    iVar3 = atoi(pcVar7);
  }
  iVar9 = json_object_object_get(param_1,"remote_server");
  if ((iVar9 == 0) || (iVar4 = json_object_get_type(iVar9), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_aplog_set",0xcc);
    }
    pcVar7 = "";
  }
  else {
    pcVar7 = (char *)json_object_get_string(iVar9);
  }
  strncpy(acStack_ac,pcVar7,0x7f);
  local_2d = 0;
  iVar9 = FUN_0051a7a8(acStack_ac,&local_c0);
  if (iVar9 != 0) {
    if (apmngr_err_switch == '\0') {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APMNGR_ERROR]%s()/%d Illegal remote server:%s.\n","_apmngr_jcs_aplog_set",0xd0,
           acStack_ac);
    return;
  }
  iVar9 = json_object_object_get(param_1,"remote_report_interval");
  if (iVar9 != 0) {
    iVar4 = json_object_get_type(iVar9);
    if (iVar4 == 6) {
      pcVar7 = (char *)json_object_get_string(iVar9);
      local_d4 = atoi(pcVar7);
      goto LAB_00552dc4;
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
             "_apmngr_jcs_aplog_set",0xd5);
    }
  }
  if (jcs_err_switch == 0) {
    local_d4 = -1;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_aplog_set",0xd5
          );
    local_d4 = -1;
  }
LAB_00552dc4:
  for (uVar6 = 0; uVar6 < 0x14; uVar6 = uVar6 + 1) {
    local_e8[uVar6] = *(undefined1 *)((int)&local_c0 + uVar6);
  }
  local_d0 = 1;
  apmngr_aplog_config_set(iVar1,iVar2,iVar8,iVar3);
  return;
}

