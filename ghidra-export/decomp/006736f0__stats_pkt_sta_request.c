// func _stats_pkt_sta_request @ 006736f0 size=808

undefined4 _stats_pkt_sta_request(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  void *__src;
  undefined1 *__s2;
  int iVar6;
  uint uVar7;
  undefined1 auStack_3e0 [6];
  undefined2 local_3da;
  undefined4 local_3d8;
  char local_3d4;
  undefined1 local_3d3;
  undefined2 local_3d2;
  undefined4 local_3d0;
  undefined2 local_3cc;
  undefined1 local_3ca;
  undefined1 local_3c9;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined1 auStack_3b8 [12];
  undefined1 auStack_3ac [6];
  byte local_3a6;
  undefined1 auStack_3a2 [34];
  undefined1 auStack_380 [36];
  uint local_35c;
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  byte local_95;
  
  memset(auStack_300,0,0x2d8);
  memset(auStack_380,0,0x80);
  memset(auStack_3e0,0,0x28);
  memset(auStack_3b8,0,0x38);
  l_stats_pkt_info_stat = l_stats_pkt_info_stat + 1;
  iVar2 = apmngr_db_entry_get_by_mac(param_3,auStack_300);
  if (iVar2 != 0) {
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
             "_stats_pkt_sta_request",0x5f);
    }
    return 0xffffffff;
  }
  bVar1 = false;
  uVar7 = 0;
  local_3da = local_2f0;
LAB_006737e8:
  do {
    uVar3 = *param_1;
    while( true ) {
      if (uVar3 <= uVar7) {
        return 0;
      }
      __src = (void *)(param_1[1] + uVar7 * 0x28);
      memcpy(auStack_3e0,__src,6);
      local_3d8 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1[1] + uVar7 * 0x28 + 6),
                                             *(undefined1 *)((int)__src + 7)),
                                    *(undefined1 *)((int)__src + 8)),*(undefined1 *)((int)__src + 9)
                          );
      local_3d4 = *(char *)((int)__src + 10);
      local_3d3 = *(undefined1 *)((int)__src + 0xb);
      local_3d2 = *(undefined2 *)((int)__src + 0xc);
      local_3d0 = *(undefined4 *)((int)__src + 0x10);
      local_3cc = *(undefined2 *)((int)__src + 0x14);
      local_3ca = *(undefined1 *)((int)__src + 0x16);
      local_3c9 = *(undefined1 *)((int)__src + 0x17);
      local_3c8 = *(undefined4 *)((int)__src + 0x18);
      local_3c4 = *(undefined4 *)((int)__src + 0x1c);
      local_3c0 = *(undefined4 *)((int)__src + 0x20);
      local_3bc = *(undefined4 *)((int)__src + 0x24);
      iVar2 = wsta_db_get_entry_by_mac(auStack_3e0,auStack_380);
      if ((iVar2 == 0) && ((local_3d8 & 0xffff0000) == (local_35c & 0xffff0000))) {
        uVar5 = rdmngr_db_generate_rd_id(local_3da,local_3d8._0_1_);
        uVar5 = rdmngr_db_get_rd_freq_band(uVar5);
        wsta_db_sta_update_rssi(auStack_3e0,(int)local_3d4);
        stats_db_sta_update(auStack_3e0,uVar5);
      }
      if ((local_95 & 2) == 0) break;
      iVar2 = wsta_db_get_mac_entry_by_peer(auStack_3e0,auStack_3b8);
      if (iVar2 == 0) {
        iVar6 = 0;
      }
      else {
        iVar2 = wsta_db_get_mac_entry_by_mld(auStack_3e0,auStack_3b8);
        iVar6 = 0;
        if (iVar2 != 0) {
          uVar7 = uVar7 + 1;
          goto LAB_006737e8;
        }
      }
LAB_006738f0:
      if (iVar6 < (int)(uint)local_3a6) {
        uVar3 = 0;
        __s2 = auStack_3a2 + iVar6 * 0xc;
        iVar2 = memcmp(auStack_3ac,__s2,6);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        iVar2 = memcmp(__s2,auStack_3e0,6);
        if (iVar2 == 0) {
          iVar6 = iVar6 + 1;
        }
        else {
          uVar4 = *param_1;
          for (; uVar3 < uVar4; uVar3 = uVar3 + 1) {
            iVar2 = memcmp(__s2,(void *)(param_1[1] + uVar3 * 0x28),6);
            if (iVar2 == 0) {
              iVar6 = iVar6 + 1;
              goto LAB_006738f0;
            }
            uVar4 = *param_1;
          }
          wsta_db_sta_update_rssi(__s2,0xffffffa1);
          iVar6 = iVar6 + 1;
        }
        goto LAB_006738f0;
      }
      uVar7 = uVar7 + 1;
      if (bVar1) goto LAB_006737e8;
      wsta_db_sta_update_rssi(auStack_3ac,0xffffffa1);
      uVar3 = *param_1;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

