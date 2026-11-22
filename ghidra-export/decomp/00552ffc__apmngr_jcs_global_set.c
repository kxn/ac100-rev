// func _apmngr_jcs_global_set @ 00552ffc size=1168

void _apmngr_jcs_global_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char acStack_60 [31];
  undefined1 local_41;
  char acStack_40 [31];
  undefined1 local_21;
  
  memset(acStack_40,0,0x20);
  memset(acStack_60,0,0x20);
  iVar1 = json_object_object_get(param_1,"apmngr_status");
  if (iVar1 == 0) {
LAB_00553084:
    if (jcs_err_switch == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_global_set",
             0x9b);
      uVar5 = 0xffffffff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00553274:
        printf(pcVar6,"_apmngr_jcs_global_set",0x9b);
      }
      goto LAB_00553084;
    }
    do {
      while( true ) {
        if (onoff_map <= iVar8) {
          if (jcs_err_switch == 0) goto LAB_00553084;
          pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
          goto LAB_00553274;
        }
        iVar2 = iVar8 * 0x10;
        pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
        if (pcVar6 != (char *)0x0) break;
        iVar8 = iVar8 + 1;
      }
      pcVar3 = (char *)json_object_get_string(iVar1);
      iVar7 = strcmp(pcVar6,pcVar3);
      iVar8 = iVar8 + 1;
    } while (iVar7 != 0);
    uVar5 = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
  }
  apmngr_global_status_set(uVar5);
  iVar1 = json_object_object_get(param_1,"auto_reboot");
  if (iVar1 == 0) {
LAB_005530dc:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_global_set",
             0x9f);
    }
    iVar1 = -1;
LAB_005530f0:
    iVar2 = json_object_object_get(param_1,"reboot_day");
    if ((iVar2 == 0) || (iVar8 = json_object_get_type(iVar2), iVar8 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_global_set",0xa4);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar2);
    }
    strncpy(acStack_40,pcVar6,0x1f);
    local_21 = 0;
    iVar2 = json_object_object_get(param_1,"reboot_time");
    if ((iVar2 == 0) || (iVar8 = json_object_get_type(iVar2), iVar8 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_global_set",0xa7);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar2);
    }
    strncpy(acStack_60,pcVar6,0x1f);
    local_41 = 0;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00553290:
        printf(pcVar6,"_apmngr_jcs_global_set",0x9f);
      }
      goto LAB_005530dc;
    }
    do {
      while( true ) {
        if (onoff_map <= iVar8) {
          if (jcs_err_switch == 0) goto LAB_005530dc;
          pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
          goto LAB_00553290;
        }
        iVar2 = iVar8 * 0x10;
        pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
        if (pcVar6 != (char *)0x0) break;
        iVar8 = iVar8 + 1;
      }
      pcVar3 = (char *)json_object_get_string(iVar1);
      iVar7 = strcmp(pcVar6,pcVar3);
      iVar8 = iVar8 + 1;
    } while (iVar7 != 0);
    iVar1 = *(int *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    if (iVar1 != 0) goto LAB_005530f0;
  }
  iVar2 = json_object_object_get(param_1,"auto_firm");
  if (iVar2 != 0) {
    iVar8 = json_object_get_type(iVar2);
    iVar7 = 0;
    if (iVar8 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar7) {
            if (jcs_err_switch == 0) goto LAB_005531d4;
            pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_005532e4;
          }
          iVar8 = iVar7 * 0x10;
          pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar8);
          if (pcVar6 != (char *)0x0) break;
          iVar7 = iVar7 + 1;
        }
        pcVar3 = (char *)json_object_get_string(iVar2);
        iVar4 = strcmp(pcVar6,pcVar3);
        iVar7 = iVar7 + 1;
      } while (iVar4 != 0);
      uVar5 = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar8 + 0xc);
      goto LAB_005531e4;
    }
    if (jcs_err_switch != 0) {
      pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_005532e4:
      printf(pcVar6,"_apmngr_jcs_global_set",0xab);
    }
  }
LAB_005531d4:
  if (jcs_err_switch == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_global_set",
           0xab);
    uVar5 = 0xffffffff;
  }
LAB_005531e4:
  apmngr_global_config_set(iVar1,uVar5,acStack_40,acStack_60);
  return;
}

