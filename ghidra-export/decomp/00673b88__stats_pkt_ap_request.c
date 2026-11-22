// func _stats_pkt_ap_request @ 00673b88 size=748

undefined4 _stats_pkt_ap_request(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  byte local_440;
  undefined1 auStack_43f [8];
  byte local_437;
  undefined2 local_436;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  int local_420;
  undefined1 local_41c;
  undefined2 local_41a;
  undefined2 local_418;
  undefined2 local_416;
  undefined1 local_414;
  undefined1 local_413;
  undefined1 local_412;
  undefined1 local_411;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined1 local_400;
  undefined1 local_3ff;
  undefined1 local_3fe;
  undefined1 local_3fd;
  undefined1 auStack_3f8 [9];
  undefined1 auStack_3ef [7];
  undefined2 local_3e8;
  undefined1 local_3e6;
  undefined1 local_3e5;
  undefined4 local_3e4;
  undefined4 local_3e0;
  undefined4 local_3d8;
  undefined4 local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  
  memset(auStack_2f8,0,0x2d8);
  memset(&local_440,0,0x20);
  memset(&local_420,0,0x24);
  memset(auStack_3f8,0,0x100);
  DAT_007cca14 = DAT_007cca14 + 1;
  iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_2f8);
  if (iVar1 == 0) {
    local_440 = param_1[4];
    memcpy(auStack_43f,param_1 + 5,8);
    local_437 = param_1[0xd];
    iVar1 = 0;
    local_436 = *(undefined2 *)(param_1 + 0xe);
    local_434 = *(undefined4 *)(param_1 + 0x10);
    local_430 = *(undefined4 *)(param_1 + 0x14);
    local_42c = *(undefined4 *)(param_1 + 0x18);
    local_428 = *(undefined4 *)(param_1 + 0x1c);
    local_424 = *(undefined4 *)(param_1 + 0x20);
    stats_db_ap_global_update(local_2e8,&local_440);
    while (iVar3 = 0, iVar1 < (int)(uint)*param_1) {
      uVar2 = rdmngr_db_generate_rd_id
                        (local_2e8,*(undefined1 *)(*(int *)(param_1 + 0x2c) + iVar1 * 0x20));
      local_420 = rdmngr_db_get_rd_freq_band(uVar2);
      if (local_420 == -1) {
        if (stats_warning_switch == '\0') {
          iVar1 = iVar1 + 1;
        }
        else {
          printf("[STATISTICS_WARNING]%s()/%d rdmngr_db_get_rd_freq_band() fail.\n",
                 "_stats_pkt_ap_request",0xf0);
          iVar1 = iVar1 + 1;
        }
      }
      else {
        puVar4 = (undefined1 *)(*(int *)(param_1 + 0x2c) + iVar1 * 0x20);
        local_41c = puVar4[1];
        local_41a = *(undefined2 *)(puVar4 + 2);
        local_418 = *(undefined2 *)(puVar4 + 4);
        local_416 = *(undefined2 *)(puVar4 + 6);
        local_414 = puVar4[8];
        local_413 = puVar4[9];
        local_412 = puVar4[10];
        local_411 = puVar4[0xb];
        local_410 = *(undefined4 *)(puVar4 + 0xc);
        local_40c = *(undefined4 *)(puVar4 + 0x10);
        local_408 = *(undefined4 *)(puVar4 + 0x14);
        local_404 = *(undefined4 *)(puVar4 + 0x18);
        local_400 = puVar4[0x1c];
        local_3ff = puVar4[0x1d];
        local_3fe = puVar4[0x1e];
        local_3fd = puVar4[0x1f];
        stats_db_radio_update(local_2e8,*puVar4,&local_420);
        iVar1 = iVar1 + 1;
      }
    }
    for (; iVar3 < (int)(uint)param_1[1]; iVar3 = iVar3 + 1) {
      puVar4 = (undefined1 *)(*(int *)(param_1 + 0x30) + iVar3 * 0x1c);
      memcpy(auStack_3ef,puVar4 + 2,6);
      local_3e8 = *(undefined2 *)(puVar4 + 8);
      local_3e6 = puVar4[10];
      local_3e5 = puVar4[0xb];
      local_3e4 = *(undefined4 *)(puVar4 + 0xc);
      local_3e0 = *(undefined4 *)(puVar4 + 0x10);
      local_3d4 = *(undefined4 *)(puVar4 + 0x14);
      local_3d8 = 0;
      local_3cc = *(undefined4 *)(puVar4 + 0x18);
      local_3d0 = 0;
      stats_db_ssid_update(local_2e8,*puVar4,puVar4[1],auStack_3f8);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
             "_stats_pkt_ap_request",0xda);
    }
  }
  return uVar2;
}

