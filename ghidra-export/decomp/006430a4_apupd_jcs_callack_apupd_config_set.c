// func apupd_jcs_callack_apupd_config_set @ 006430a4 size=592

void apupd_jcs_callack_apupd_config_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__s2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callack_apupd_config_set",0x12a)
    ;
    return;
  }
  iVar1 = json_object_object_get(param_1,"state");
  if (iVar1 == 0) {
    uVar4 = 1;
    if (g_apupd_error == 0) goto LAB_00643150;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar4 = 1;
      goto LAB_00643150;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get config from json failed.\r\n";
    uVar4 = 0x131;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    iVar6 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar6) {
            if (jcs_err_switch == 0) goto LAB_00643118;
            pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_00643270;
          }
          iVar2 = iVar6 * 0x10;
          pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
          if (pcVar5 != (char *)0x0) break;
          iVar6 = iVar6 + 1;
        }
        __s2 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar5,__s2);
        iVar6 = iVar6 + 1;
      } while (iVar3 != 0);
      local_28[0] = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00643270:
        printf(pcVar5,"apupd_jcs_callack_apupd_config_set",0x134);
      }
LAB_00643118:
      if (jcs_err_switch == 0) {
        local_28[0] = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
               "apupd_jcs_callack_apupd_config_set",0x134);
        local_28[0] = 0xffffffff;
      }
    }
    iVar1 = apupd_db_config_set(local_28);
    uVar4 = 0;
    if ((iVar1 != -1) || (uVar4 = 1, g_apupd_error == 0)) goto LAB_00643150;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar4 = 1;
      goto LAB_00643150;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: set config failed.\r\n";
    uVar4 = 0x139;
  }
  printf(pcVar5,"apupd_jcs_callack_apupd_config_set",uVar4);
  uVar4 = 1;
LAB_00643150:
  uVar4 = json_object_new_int(uVar4);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return;
}

