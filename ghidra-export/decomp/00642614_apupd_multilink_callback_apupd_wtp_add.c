// func apupd_multilink_callback_apupd_wtp_add @ 00642614 size=660

undefined4 apupd_multilink_callback_apupd_wtp_add(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 auStack_388 [24];
  undefined1 auStack_370 [20];
  undefined2 local_35c;
  undefined2 local_35a;
  undefined2 local_358;
  undefined2 local_356;
  undefined4 local_354;
  undefined2 local_350;
  undefined2 local_34e;
  undefined2 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  undefined1 auStack_330 [16];
  byte local_320;
  undefined1 auStack_31f [55];
  undefined1 auStack_2e8 [60];
  int local_2ac;
  undefined4 local_2a8;
  undefined2 local_2a0;
  undefined2 local_29e;
  undefined2 local_29c;
  undefined2 local_e0;
  undefined2 local_de;
  undefined2 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 auStack_d0 [16];
  byte local_c0;
  undefined1 auStack_bf [67];
  undefined1 auStack_7c [20];
  undefined2 local_68;
  
  memset(auStack_388,0,0xa0);
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get ap entry by id failed.\r\n";
    uVar3 = 0x11e9;
  }
  else if (local_2ac == 0) {
    if (g_apupd_debug == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: AP not firmed.\r\n";
    uVar3 = 0x11ee;
  }
  else {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar3 = FUN_00407fe0(&apupd_check_callback_list);
      printf("[APUPD_DEBUG]%32s() %05d: callback list length:%d\r\n","_apupd_upgrade_check_proc",
             0x106,uVar3);
    }
    for (iVar1 = FUN_004081b0(&apupd_check_callback_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1))
    {
      if ((*(code **)(iVar1 + 0xc) != (code *)0x0) &&
         (iVar2 = (**(code **)(iVar1 + 0xc))(param_1), iVar2 == 0)) {
        if (g_apupd_debug == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_DEBUG]%32s() %05d: AP can not upgrade now.\r\n";
        uVar3 = 0x11f3;
        goto LAB_00642818;
      }
    }
    memcpy(auStack_370,auStack_7c,0x14);
    local_35c = local_68;
    local_35a = local_2a0;
    local_358 = local_29e;
    local_356 = local_29c;
    local_354 = local_2a8;
    local_350 = local_e0;
    local_34e = local_de;
    local_34c = local_dc;
    local_348 = local_d8;
    local_344 = local_d4;
    memcpy(auStack_330,auStack_d0,0x10);
    if (2 < local_c0) {
      local_c0 = 2;
    }
    local_320 = local_c0;
    memcpy(auStack_31f,auStack_bf,(uint)local_c0 << 4);
    local_340 = 0;
    local_33c = 0;
    local_338 = 0;
    iVar1 = apupd_db_wtp_add(auStack_388);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: add wtp failed.\r\n";
    uVar3 = 0x120a;
  }
LAB_00642818:
  printf(__format,"apupd_multilink_callback_apupd_wtp_add",uVar3);
  return 0xffffffff;
}

