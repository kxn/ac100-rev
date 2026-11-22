// func cloud_mngt_jcs_sync_module_config @ 0048e920 size=1220

void cloud_mngt_jcs_sync_module_config(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  void *__s;
  void *__s_00;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  char local_190 [50];
  undefined1 local_15e;
  char local_15c [50];
  undefined1 local_12a;
  undefined4 local_128 [64];
  
  memset(local_128,0,0x100);
  memset(local_15c,0,0x33);
  memset(local_190,0,0x33);
  if (ap_report_switch == 0) {
    return;
  }
  iVar2 = json_object_object_get(param_1,"config_list");
  if (iVar2 == 0) {
    return;
  }
  iVar3 = json_object_get_type(iVar2);
  puVar8 = local_128;
  if (iVar3 == 5) {
    for (iVar3 = 0; iVar4 = json_object_array_length(iVar2), iVar3 < iVar4; iVar3 = iVar3 + 1) {
      if (iVar3 == 0x40) {
        iVar3 = 0x40;
        break;
      }
      uVar9 = json_object_array_get_idx(iVar2,iVar3);
      *puVar8 = uVar9;
      puVar8 = puVar8 + 1;
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 4) {
      iVar2 = json_object_object_length(iVar2);
      iVar3 = 0;
      if (iVar2 == 0) goto LAB_0048ea0c;
    }
    iVar3 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get objectArray with error obj or value type is unmatch.\n",
             "cloud_mngt_jcs_sync_module_config",0x1f17);
    }
  }
LAB_0048ea0c:
  puVar8 = local_128;
  bVar1 = false;
  iVar2 = 0;
  pcVar10 = "";
LAB_0048ea28:
  do {
    if (iVar3 <= iVar2) {
      if (bVar1) {
        if (g_cloud_mngt_config_sync_report_timer_id != -1) {
          FUN_00408060();
          g_cloud_mngt_config_sync_report_timer_id = -1;
        }
        g_cloud_mngt_config_sync_report_timer_id =
             FUN_00408340(sync_config_report_interval,0,cloud_mngt_config_sync_report_timer_cb,0,0,
                          "cloud_mngt_jcs_sync_module_config",0x1f2b);
      }
      return;
    }
    uVar9 = *puVar8;
    iVar4 = json_object_object_get(uVar9,"module_name");
    if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
      pcVar7 = pcVar10;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "cloud_mngt_jcs_sync_module_config",0x1f1b);
      }
    }
    else {
      pcVar7 = (char *)json_object_get_string(iVar4);
    }
    strncpy(local_15c,pcVar7,0x32);
    local_12a = 0;
    iVar4 = json_object_object_get(uVar9,"config_name");
    if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
      pcVar7 = pcVar10;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "cloud_mngt_jcs_sync_module_config",0x1f1d);
      }
    }
    else {
      pcVar7 = (char *)json_object_get_string(iVar4);
    }
    strncpy(local_190,pcVar7,0x32);
    local_15e = 0;
    if ((local_15c[0] != '\0') && (local_190[0] != '\0')) {
      sVar6 = strlen(local_15c);
      bVar1 = true;
      if ((sVar6 < 0x33) && (sVar6 = strlen(local_190), sVar6 < 0x33)) {
        FUN_004082d0(cloud_mngt_data_mutex,0xffffffff);
        for (__s = (void *)FUN_004081b0(&g_cloud_mngt_sync_module_list); __s != (void *)0x0;
            __s = (void *)FUN_00408680(__s)) {
          iVar4 = strcmp((char *)((int)__s + 0xc),local_15c);
          if (iVar4 == 0) goto LAB_0048ebec;
        }
        __s = (void *)FUN_00408450(0x4c,0x1abb);
        if (__s == (void *)0x0) {
          if (cloud_mngt_err_switch != '\0') {
            uVar9 = 0x1abe;
LAB_0048ed8c:
            printf("[CLOUD_MNGT_ERROR]%s()/%d Malloc error\n","cloud_mngt_sync_module_config_add",
                   uVar9);
          }
        }
        else {
          memset(__s,0,0x4c);
          FUN_0051ad88((int)__s + 0x40);
          strcpy((char *)((int)__s + 0xc),local_15c);
          FUN_004086b0(&g_cloud_mngt_sync_module_list,__s);
LAB_0048ebec:
          for (iVar4 = FUN_004081b0((int)__s + 0x40); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
            iVar5 = strcmp((char *)(iVar4 + 0xc),local_190);
            if (iVar5 == 0) goto LAB_0048ec60;
          }
          __s_00 = (void *)FUN_00408450(0x40,0x1acf);
          if (__s_00 == (void *)0x0) {
            if (cloud_mngt_err_switch != '\0') {
              uVar9 = 0x1ad2;
              goto LAB_0048ed8c;
            }
          }
          else {
            memset(__s_00,0,0x40);
            strcpy((char *)((int)__s_00 + 0xc),local_190);
            FUN_004086b0((int)__s + 0x40,__s_00);
          }
        }
LAB_0048ec60:
        bVar1 = true;
        iVar2 = iVar2 + 1;
        puVar8 = puVar8 + 1;
        FUN_00407f30(cloud_mngt_data_mutex);
        goto LAB_0048ea28;
      }
    }
    iVar2 = iVar2 + 1;
    puVar8 = puVar8 + 1;
  } while( true );
}

