// func cloud_mngt_wsta_callback_sta_del @ 0048f6b4 size=1076

undefined4 cloud_mngt_wsta_callback_sta_del(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 uVar5;
  undefined4 uVar4;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined1 auStack_7d0 [8];
  byte local_7c8;
  undefined1 auStack_7c7 [247];
  undefined1 auStack_6d0 [8];
  byte local_6c8;
  undefined1 auStack_6c7 [247];
  undefined1 auStack_5d0 [20];
  undefined4 local_5bc;
  undefined1 auStack_588 [656];
  undefined1 auStack_2f8 [20];
  undefined4 local_2e4;
  undefined1 auStack_2b0 [656];
  
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_6d0,0,0x100);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_del start\n",
           "cloud_mngt_wsta_callback_sta_del",0xf83);
  }
  if (ap_report_switch == 0) {
    return 0;
  }
  iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_2f8);
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar6 = "[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar7 = 0xf8b;
    goto LAB_0048f8b8;
  }
  iVar1 = _cloud_mngt_role_match(local_2e4);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_00408450(0x14,0xf94);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar1 + 0xc) = 2;
  puVar2 = (undefined4 *)FUN_00408450(0x30,0xf9a);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00407df0(iVar1);
    return 0xffffffff;
  }
  memset(puVar2,0,0x30);
  memcpy(puVar2 + 1,(void *)(param_1 + 0x68),6);
  memcpy(puVar2 + 4,auStack_2b0,6);
  uVar8 = FUN_00407dd0();
  *(undefined8 *)(puVar2 + 8) = uVar8;
  *puVar2 = 2;
  *(undefined1 *)(puVar2 + 10) = 0;
  memset(auStack_6d0,0,0x100);
  iVar3 = stats_db_ssid_get(*(undefined2 *)(param_1 + 0x22),*(undefined1 *)(param_1 + 0x24),
                            *(undefined1 *)(param_1 + 0x25),auStack_6d0);
  if (iVar3 == 0) {
    if (*(char *)(param_1 + 0x25) != '\0') {
      if ((local_6c8 & 3) != 3) {
        *(undefined4 **)(iVar1 + 0x10) = puVar2;
        goto LAB_0048f82c;
      }
      memcpy((void *)((int)puVar2 + 0x29),auStack_6c7,6);
      *(undefined1 *)(puVar2 + 10) = 1;
    }
    *(undefined4 **)(iVar1 + 0x10) = puVar2;
  }
  else {
    *(undefined4 **)(iVar1 + 0x10) = puVar2;
  }
LAB_0048f82c:
  FUN_004082d0(cloud_mngt_msg_mutex,0xffffffff);
  FUN_004086b0(&g_cloud_mngt_msg_list,iVar1);
  FUN_004084b0(cloud_mngt_msg_cond);
  FUN_00407f30(cloud_mngt_msg_mutex);
  memset(auStack_5d0,0,0x2d8);
  memset(auStack_7d0,0,0x100);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_del start\n",
           "cloud_mngt_wsta_callback_sta_del_event",0xf45);
  }
  if (ap_report_switch != 0) {
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_5d0);
    if (iVar1 == -1) {
      if (cloud_mngt_err_switch != '\0') {
        pcVar6 = "[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n";
        uVar4 = 0xf4d;
LAB_0048fa90:
        printf(pcVar6,"cloud_mngt_wsta_callback_sta_del_event",uVar4);
      }
    }
    else {
      iVar1 = _cloud_mngt_role_match(local_5bc);
      if ((iVar1 != 0) &&
         (puVar2 = (undefined4 *)FUN_00408450(0x80,0xf56), puVar2 != (undefined4 *)0x0)) {
        memset(puVar2,0,0x80);
        memcpy(puVar2 + 1,(void *)(param_1 + 0x68),6);
        memcpy(puVar2 + 4,auStack_588,6);
        uVar8 = FUN_00407dd0();
        *(undefined8 *)(puVar2 + 8) = uVar8;
        *puVar2 = 2;
        *(undefined1 *)(puVar2 + 10) = 0;
        memset(auStack_7d0,0,0x100);
        iVar1 = stats_db_ssid_get(*(undefined2 *)(param_1 + 0x22),*(undefined1 *)(param_1 + 0x24),
                                  *(undefined1 *)(param_1 + 0x25),auStack_7d0);
        if ((iVar1 == 0) && ((*(char *)(param_1 + 0x25) != '\0' && ((local_7c8 & 3) == 3)))) {
          memcpy((void *)((int)puVar2 + 0x29),auStack_7c7,6);
          *(undefined1 *)(puVar2 + 10) = 1;
        }
        iVar1 = is_implicit_leave(param_1);
        if (iVar1 == 0) {
          puVar2[0x1b] = 1;
          uVar5 = *(undefined1 *)(param_1 + 0x24);
        }
        else {
          uVar5 = *(undefined1 *)(param_1 + 0x24);
        }
        *(undefined1 *)((int)puVar2 + 0x2f) = uVar5;
        uVar4 = get_ap_nms_mask(*(undefined4 *)(param_1 + 0x20));
        puVar2[0x1d] = uVar4;
        iVar1 = FUN_00408540(client_events_container,puVar2);
        if (iVar1 == 0) {
          if (cloud_mngt_debug_switch != '\0') {
            pcVar6 = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_del end\n";
            uVar4 = 0xf7b;
            goto LAB_0048fa90;
          }
        }
        else {
          FUN_00407df0(puVar2);
        }
      }
    }
  }
  uVar4 = 0;
  if (cloud_mngt_debug_switch == '\0') {
    return 0;
  }
  pcVar6 = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_del end\n";
  uVar7 = 0xfb6;
LAB_0048f8b8:
  printf(pcVar6,"cloud_mngt_wsta_callback_sta_del",uVar7);
  return uVar4;
}

