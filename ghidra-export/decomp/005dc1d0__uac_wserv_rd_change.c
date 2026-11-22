// func _uac_wserv_rd_change @ 005dc1d0 size=812

undefined4 _uac_wserv_rd_change(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  char *__format;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 local_320;
  undefined1 local_31c [2];
  undefined2 local_31a;
  undefined1 *local_318;
  undefined4 local_314;
  undefined4 local_310;
  code *local_30c;
  code *local_308;
  int local_304;
  undefined4 *local_300;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  int local_2e4;
  undefined2 local_2e0;
  undefined4 local_2b8;
  undefined2 local_2b2;
  undefined1 auStack_e0 [192];
  
  uVar2 = rdmngr_db_generate_ap_id();
  local_318 = (undefined1 *)0x0;
  local_314 = 0;
  local_320 = 0;
  local_310 = 0;
  local_30c = (code *)0x0;
  local_308 = (code *)0x0;
  local_304 = 0;
  local_300 = (undefined4 *)0x0;
  if (*(char *)(param_2 + 8) == *(char *)(param_3 + 8)) {
    uVar9 = 0;
    if (g_wserv_debug == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    __format = "<wserv>[debug]%s(): %d  -> freq band not changed,do nothing.\r\n";
    uVar8 = 0x1211;
  }
  else {
    iVar3 = apmngr_db_get_ap_max();
    uVar4 = apmngr_db_get_ap_max();
    iVar3 = FUN_004082a0((iVar3 >> 5) + (uint)((uVar4 & 0x1f) != 0),4,0x1214);
    if (iVar3 != 0) {
      uVar4 = uVar2 & 0xffff;
      iVar5 = apmngr_db_entry_get_by_id(uVar4,auStack_2f8);
      if (((iVar5 != 0) && (g_wserv_error != 0)) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("<wserv>[error]%s(): %d  -> _uac_wserv_rd_change() get ap entry by ap_id error\r\n",
               "_uac_wserv_rd_change",0x121d);
      }
      bVar1 = false;
      uVar10 = param_1 & 0xf;
      local_31a = local_2b2;
      iVar5 = uac_wservice_get_ap_radio_cnt(local_2b8,auStack_e0,local_31c);
      do {
        while( true ) {
          if (iVar5 < (int)uVar10) {
            puVar7 = (uint *)(iVar3 + (uVar4 >> 5) * 4);
            uVar4 = *puVar7;
            if (((int)uVar4 >> (uVar2 & 0x1f) & 1U) == 0) {
              *puVar7 = uVar4 | 1 << (uVar2 & 0x1f);
              local_320 = 1;
            }
            if (((local_2e4 == 4) || (local_2e4 == 8)) || ((local_2e4 == 6 || (local_2e4 == 5)))) {
              wserv_db_ap_sync_bind_list
                        (local_2e0,local_2e8,_uac_wserv_add_cb,_uac_wserv_del_cb,iVar3,&local_320);
            }
            else {
              local_314 = 0;
              local_318 = auStack_2f8;
              wserv_db_entry_for_each(_wserv_db_entry_auto_bind,&local_318);
              if (((local_2e4 == 1) || (local_2e4 == 3)) || (local_2e4 == 2)) {
                local_310 = CONCAT22((short)uVar2,local_310._2_2_);
                local_30c = _uac_wserv_add_cb;
                local_308 = _uac_wserv_del_cb;
                local_300 = &local_320;
                local_304 = iVar3;
                wserv_db_sync_wlan_to_re(&local_310);
              }
            }
            _uac_wserv_update_aps_md5(iVar3,local_320);
            FUN_00407df0(iVar3);
            return 0;
          }
          uVar6 = rdmngr_db_generate_rd_id(uVar4,uVar10);
          if (uVar6 != param_1) break;
          bVar1 = true;
LAB_005dc2e8:
          wserv_db_rd_unbind_due_to_freq_change(uVar6,uVar6 == param_1,_uac_wserv_del_cb);
          uVar10 = uVar10 + 1;
        }
        if (bVar1) goto LAB_005dc2e8;
        uVar10 = uVar10 + 1;
      } while( true );
    }
    uVar9 = 0xffffffff;
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n";
    uVar8 = 0x1217;
  }
  printf(__format,"_uac_wserv_rd_change",uVar8);
  return uVar9;
}

