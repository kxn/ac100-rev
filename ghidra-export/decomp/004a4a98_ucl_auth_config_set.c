// func ucl_auth_config_set @ 004a4a98 size=1952

void ucl_auth_config_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined8 uVar9;
  char local_38 [20];
  uint local_24;
  
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_24 = 0;
  iVar1 = ucl_auth_db_get_bind_status();
  iVar2 = ucl_auth_db_get_switch_status();
  iVar3 = ucl_auth_db_get_cloud_status();
  iVar4 = json_object_object_get(param_1,"type");
  if (iVar4 == 0) {
LAB_004a4b68:
    if (jcs_err_switch != 0) {
      uVar7 = 0x3ba;
      pcVar8 = "[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n";
      goto LAB_004a4d54;
    }
  }
  else {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 3) {
      iVar4 = json_object_get_int(iVar4);
    }
    else {
      iVar5 = json_object_get_type();
      if (iVar5 != 2) goto LAB_004a4b68;
      uVar9 = json_object_get_double(iVar4);
      iVar4 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
    if (iVar4 == 2) {
      iVar4 = json_object_object_get(param_1,"enable");
      if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "ucl_auth_config_set",0x3d9);
        }
        pcVar8 = "";
      }
      else {
        pcVar8 = (char *)json_object_get_string(iVar4);
      }
      strncpy(local_38,pcVar8,0x17);
      local_24 = local_24 & 0xffffff00;
      iVar4 = strcmp(local_38,"on");
      if (iVar4 == 0) {
        ucl_auth_db_set_switch_status(1);
        if (ucl_info_switch != 0) {
          uVar7 = 0x3de;
          pcVar8 = "[UCL_AUTH_INFO]%s()/%d Set ucl auth enable on.\n";
LAB_004a4d54:
          printf(pcVar8,"ucl_auth_config_set",uVar7);
        }
      }
      else {
        iVar4 = strcmp(local_38,"off");
        if (iVar4 != 0) {
          if (ucl_err_switch == 0) {
            return;
          }
          uVar7 = 999;
LAB_004a4fb0:
          printf("[UCL_AUTH_ERR]%s()/%d Param is invalid.\n","ucl_auth_config_set",uVar7);
          return;
        }
        ucl_auth_db_set_switch_status(0);
        if (ucl_info_switch != 0) {
          uVar7 = 0x3e3;
          pcVar8 = "[UCL_AUTH_INFO]%s()/%d Set ucl auth enable off.\n";
          goto LAB_004a4d54;
        }
      }
    }
    else if (iVar4 == 3) {
      iVar4 = json_object_object_get(param_1,"status");
      if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "ucl_auth_config_set",0x3f1);
        }
        pcVar8 = "";
      }
      else {
        pcVar8 = (char *)json_object_get_string(iVar4);
      }
      strncpy(local_38,pcVar8,0x17);
      local_24 = local_24 & 0xffffff00;
      iVar4 = strcmp(local_38,"online");
      if (iVar4 == 0) {
        ucl_auth_db_set_cloud_status(1);
        if (ucl_info_switch != 0) {
          uVar7 = 0x3f6;
          pcVar8 = "[UCL_AUTH_INFO]%s()/%d Set cloud online.\n";
          goto LAB_004a4d54;
        }
      }
      else {
        iVar4 = strcmp(local_38,"offline");
        if (iVar4 != 0) {
          if (ucl_err_switch == 0) {
            return;
          }
          uVar7 = 0x3ff;
          goto LAB_004a4fb0;
        }
        ucl_auth_db_set_cloud_status(0);
        if (ucl_info_switch != 0) {
          uVar7 = 0x3fb;
          pcVar8 = "[UCL_AUTH_INFO]%s()/%d Set cloud offline.\n";
          goto LAB_004a4d54;
        }
      }
    }
    else if (iVar4 == 1) {
      iVar4 = json_object_object_get(param_1,"status");
      if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "ucl_auth_config_set",0x3c1);
        }
        pcVar8 = "";
      }
      else {
        pcVar8 = (char *)json_object_get_string(iVar4);
      }
      strncpy(local_38,pcVar8,0x17);
      local_24 = local_24 & 0xffffff00;
      iVar4 = strcmp(local_38,"bind");
      if (iVar4 == 0) {
        ucl_auth_db_set_bind_status(1);
        if (ucl_info_switch != 0) {
          uVar7 = 0x3c6;
          pcVar8 = "[UCL_AUTH_INFO]%s()/%d Bind to cloud.\n";
          goto LAB_004a4d54;
        }
      }
      else {
        iVar4 = strcmp(local_38,"unbind");
        if (iVar4 != 0) {
          if (ucl_err_switch == 0) {
            return;
          }
          uVar7 = 0x3cf;
          goto LAB_004a4fb0;
        }
        ucl_auth_db_set_bind_status(0);
        if (ucl_info_switch != 0) {
          uVar7 = 0x3cb;
          pcVar8 = "[UCL_AUTH_INFO]%s()/%d Unbind to cloud.\n";
          goto LAB_004a4d54;
        }
      }
    }
  }
  iVar4 = ucl_auth_db_get_bind_status();
  iVar5 = ucl_auth_db_get_switch_status();
  iVar6 = ucl_auth_db_get_cloud_status();
  if (iVar1 == 0) {
    uVar7 = 2;
    if (iVar4 == 1) {
LAB_004a4dec:
      ucl_auth_db_set_notify_switch_report(uVar7);
    }
    else {
LAB_004a4bbc:
      uVar7 = 3;
      if (iVar4 == 0) goto LAB_004a4dec;
    }
    if (iVar1 != 0) goto LAB_004a4d34;
LAB_004a4bcc:
    if ((iVar4 != 1) || (iVar5 != 1)) goto LAB_004a4bd4;
    ucl_auth_db_set_notify_first_report(2);
    if (iVar1 != 1) {
      uVar7 = 1;
      goto LAB_004a4bf8;
    }
LAB_004a4d74:
    if (iVar2 != 1) goto LAB_004a4bdc;
    if (iVar4 == 1) {
      if ((((iVar5 == 1) && (iVar3 == 0)) && (iVar6 == 1)) &&
         ((iVar1 = ucl_auth_db_get_notify_first_report(), iVar1 == 3 ||
          (iVar1 = ucl_auth_db_get_notify_first_report(), iVar1 == 1)))) {
        ucl_auth_db_set_notify_first_report(2);
      }
      goto LAB_004a4dd8;
    }
LAB_004a4be4:
    uVar7 = 0;
    if (iVar4 == 0) goto LAB_004a4bf8;
  }
  else {
    if (iVar4 != 1) goto LAB_004a4bbc;
    uVar7 = 2;
    if (iVar2 != iVar5) goto LAB_004a4dec;
LAB_004a4d34:
    if (iVar2 == 0) goto LAB_004a4bcc;
LAB_004a4bd4:
    if (iVar1 == 1) {
      if ((iVar2 == 1) && ((iVar4 == 0 || (iVar5 == 0)))) {
        ucl_auth_db_set_notify_first_report(3);
      }
      goto LAB_004a4d74;
    }
LAB_004a4bdc:
    if (iVar4 != 1) goto LAB_004a4be4;
LAB_004a4dd8:
    uVar7 = 1;
    if (iVar5 == 1) goto LAB_004a4bf8;
  }
  uVar7 = 0;
  if (iVar5 != 0) {
    return;
  }
LAB_004a4bf8:
  ucl_auth_db_set_station_report_switch_enable(uVar7);
  return;
}

