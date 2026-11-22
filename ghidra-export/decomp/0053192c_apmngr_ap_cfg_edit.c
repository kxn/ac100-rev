// func apmngr_ap_cfg_edit @ 0053192c size=892

/* WARNING: Type propagation algorithm not settling */

undefined4 apmngr_ap_cfg_edit(undefined2 param_1,void *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 local_3a8 [2];
  uint local_3a4;
  undefined1 auStack_3a0 [160];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  uint local_2ec;
  undefined1 auStack_2c0 [14];
  undefined1 auStack_2b2 [226];
  char local_1d0;
  char local_13b;
  uint local_ac;
  int local_78;
  int local_74;
  int local_54;
  
  memset(auStack_300,0,0x2d8);
  local_3a4 = 0;
  local_3a8[0] = param_1;
  memset(auStack_3a0,0,0x9a);
  if ((apmngr_debug_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d \napmngr_ap_cfg_edit() start\n","apmngr_ap_cfg_edit",0x72d);
  }
  if (param_2 == (void *)0x0) {
    uVar5 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Input config info is NULL.\n";
    uVar6 = 0x730;
  }
  else {
    iVar4 = apmngr_db_entry_get_by_id(param_1,auStack_300);
    if (iVar4 != 0) {
      return 0xffffffff;
    }
    iVar4 = apmngr_db_is_cfg_changed(auStack_2c0,param_2);
    if (iVar4 == 1) {
      bVar2 = false;
      memset(auStack_3a0,0,0x9a);
      memcpy(auStack_3a0,auStack_2b2,0x99);
      iVar4 = memcmp(auStack_3a0,(void *)((int)param_2 + 0xe),0x9a);
      bVar1 = iVar4 != 0;
      if (local_13b == '\0') {
        bVar2 = *(char *)((int)param_2 + 0x185) != '\0';
      }
      iVar7 = 0;
      iVar4 = strcmp("0",(char *)((int)param_2 + 0x185));
      uVar8 = (uint)(iVar4 == 0);
      iVar4 = multi_link_status_get(local_2f0);
      if ((iVar4 == 1) && (local_54 != 0)) {
        iVar7 = apmngr_db_is_led_timer_cfg_changed(auStack_2c0,param_2);
        iVar4 = apmngr_db_is_pack_cfg_changed(auStack_2c0,param_2);
        if (iVar4 != 0) {
          bVar3 = false;
          if ((((local_ac & 0x400) != 0) && (local_74 != 0)) && (local_78 == 2)) {
            bVar3 = local_1d0 != *(char *)((int)param_2 + 0xf0) &&
                    *(char *)((int)param_2 + 0xf0) != '\0';
          }
          memcpy(auStack_2c0,param_2,0x1c8);
          iVar4 = apmngr_pkt_config_update_request_pkt_send(auStack_300,1);
          if (iVar4 != 0) {
            return 0xffffffff;
          }
          if (bVar3) {
            apmngr_evt_notify(6,auStack_300);
          }
        }
      }
    }
    else {
      uVar8 = 0;
      bVar2 = false;
      bVar1 = false;
      iVar7 = 0;
    }
    apmngr_db_entry_cfg_set(param_1,param_2);
    if (iVar7 != 0) {
      if (*(char *)((int)param_2 + 0x17c) == '\0') {
        apmngr_db_ap_led_timer_stop();
        local_3a4 = (uint)(*(int *)((int)param_2 + 0x178) != 0);
      }
      else {
        apmngr_led_timer_start(param_1,&local_3a4);
      }
      uVar5 = 1;
      if (local_3a4 == 0) {
        uVar5 = 2;
      }
      apmngr_ap_led_update(local_3a8,1,uVar5);
    }
    if (bVar1) {
      apmngr_evt_notify(0xb,auStack_300);
    }
    if (bVar2) {
      apmngr_evt_notify(0xd,auStack_300);
    }
    if ((uVar8 != 0) && (((local_2ec == uVar8 || (local_2ec == 3)) || (local_2ec == 2)))) {
      apmngr_ap_cloud_config_id_re_update(param_1);
    }
    uVar5 = 0;
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0;
    }
    __format = "[APMNGR_DEBUG]%s()/%d apmngr_ap_cfg_edit() end \n\n";
    uVar6 = 0x786;
  }
  printf(__format,"apmngr_ap_cfg_edit",uVar6);
  return uVar5;
}

