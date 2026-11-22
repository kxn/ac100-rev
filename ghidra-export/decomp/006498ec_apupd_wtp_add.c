// func apupd_wtp_add @ 006498ec size=480

undefined4 apupd_wtp_add(undefined2 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_380 [24];
  undefined1 auStack_368 [20];
  undefined2 local_354;
  undefined2 local_352;
  undefined2 local_350;
  undefined2 local_34e;
  undefined4 local_34c;
  undefined2 local_348;
  undefined2 local_346;
  undefined2 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined1 auStack_328 [16];
  byte local_318;
  undefined1 auStack_317 [55];
  undefined1 auStack_2e0 [60];
  int local_2a4;
  undefined4 local_2a0;
  undefined2 local_298;
  undefined2 local_296;
  undefined2 local_294;
  undefined2 local_d8;
  undefined2 local_d6;
  undefined2 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 auStack_c8 [16];
  byte local_b8;
  undefined1 auStack_b7 [67];
  undefined1 auStack_74 [20];
  undefined2 local_60;
  int local_34;
  
  memset(auStack_380,0,0xa0);
  memset(auStack_2e0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get ap entry by id failed.\r\n";
    uVar2 = 0x1338;
  }
  else if ((local_2a4 == 0) || (local_34 != 2)) {
    if (g_apupd_debug == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: AP not firmed or not running.\r\n";
    uVar2 = 0x133d;
  }
  else {
    memcpy(auStack_368,auStack_74,0x14);
    local_354 = local_60;
    local_352 = local_298;
    local_350 = local_296;
    local_34e = local_294;
    local_34c = local_2a0;
    local_348 = local_d8;
    local_346 = local_d6;
    local_344 = local_d4;
    local_340 = local_d0;
    local_33c = local_cc;
    memcpy(auStack_328,auStack_c8,0x10);
    if (2 < local_b8) {
      local_b8 = 2;
    }
    local_318 = local_b8;
    memcpy(auStack_317,auStack_b7,(uint)local_b8 << 4);
    local_338 = 0;
    local_334 = 0;
    local_330 = 0;
    iVar1 = apupd_db_wtp_add(auStack_380);
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
    uVar2 = 0x1354;
  }
  printf(__format,"apupd_wtp_add",uVar2);
  return 0xffffffff;
}

