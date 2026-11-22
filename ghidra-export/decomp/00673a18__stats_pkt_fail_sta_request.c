// func _stats_pkt_fail_sta_request @ 00673a18 size=368

undefined4 _stats_pkt_fail_sta_request(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint extraout_v1;
  undefined4 uVar2;
  void *__src;
  uint uVar3;
  undefined1 auStack_330 [12];
  undefined2 local_324;
  undefined1 local_322;
  undefined1 local_321;
  undefined1 auStack_320 [2];
  undefined1 local_31e;
  undefined4 local_31c;
  int local_318;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_330,0,0x34);
  FUN_00407e70();
  l_stats_pkt_info_stat = l_stats_pkt_info_stat + 1;
  iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_2f8);
  if (iVar1 == 0) {
    uVar3 = 0;
    local_324 = local_2e8;
    while (iVar1 = uVar3 * 0x14, uVar3 < *param_1) {
      uVar3 = uVar3 + 1;
      __src = (void *)(param_1[1] + iVar1);
      memcpy(auStack_330,__src,6);
      local_322 = *(undefined1 *)(param_1[1] + iVar1 + 6);
      local_321 = *(undefined1 *)((int)__src + 7);
      local_31e = *(undefined1 *)((int)__src + 8);
      local_31c = *(undefined4 *)((int)__src + 0xc);
      local_318 = extraout_v1 - *(uint *)((int)__src + 0x10);
      if (extraout_v1 <= *(uint *)((int)__src + 0x10)) {
        local_318 = 0;
      }
      uac_wservice_get_vlan(local_324,local_322,local_321,auStack_320);
      stats_db_fail_sta_add(auStack_330);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
             "_stats_pkt_fail_sta_request",0xb6);
    }
  }
  return uVar2;
}

