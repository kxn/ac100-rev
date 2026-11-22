// func _stats_pkt_rssi_request @ 00673e74 size=636

undefined4 _stats_pkt_rssi_request(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 local_598;
  undefined4 local_594;
  undefined4 local_590;
  undefined1 auStack_58c [32];
  uint local_56c;
  byte local_568;
  undefined1 local_567;
  undefined1 auStack_50c [283];
  int local_3f1;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  memset(auStack_300,0,0x2d8);
  memset(auStack_58c,0,0x80);
  memset(auStack_50c,0,0x205);
  local_598 = 0;
  local_594 = 0;
  local_590 = 0;
  DAT_007cca18 = DAT_007cca18 + 1;
  iVar2 = apmngr_db_entry_get_by_mac(param_3,auStack_300);
  if (iVar2 == 0) {
    iVar2 = apdb_radio_count_by_id(local_2c0,auStack_e8);
    if (iVar2 != -1) {
      puVar6 = param_1;
      for (iVar8 = 1; iVar8 <= iVar2; iVar8 = iVar8 + 1) {
        uVar1 = *puVar6;
        pcVar4 = puVar6 + 8;
        puVar6 = puVar6 + 1;
        stats_db_radio_set_chload_and_nf(local_2f0,iVar8,uVar1,(int)*pcVar4);
      }
      uVar9 = 0;
LAB_00673f9c:
      do {
        if (*(uint *)(param_1 + 0x10) <= uVar9) {
          return 0;
        }
        iVar10 = uVar9 * 0xe;
        iVar8 = wsta_db_get_entry_by_mac(*(int *)(param_1 + 0x14) + iVar10,auStack_58c);
        if (iVar8 == 0) {
          local_594 = CONCAT22(local_2f0,local_594._2_2_);
          iVar8 = uac_wservice_get_wserv_id(local_56c,local_568,local_567);
          if (iVar8 != -1) {
            iVar3 = uac_wservice_get_entry_by_id(iVar8,auStack_50c);
            if (iVar3 != 0) {
              uVar9 = uVar9 + 1;
              goto LAB_00673f9c;
            }
            uVar7 = 1;
            if (local_3f1 != 0) {
LAB_00674018:
              do {
                if (iVar2 < (int)uVar7) goto LAB_00674018;
                if (local_56c != local_2f0) {
                  iVar3 = *(int *)(param_1 + 0x14);
LAB_00674034:
                  if (*(char *)(iVar3 + iVar10 + (uVar7 - 1) + 6) != '\0') {
                    iVar3 = uac_wservice_wlanid_get_by_wservid((uint)local_2f0,uVar7 & 0xff,iVar8);
                    if (iVar3 != -1) {
                      local_594 = CONCAT31(CONCAT21(local_594._0_2_,(char)uVar7),(char)iVar3);
                      local_590 = CONCAT13(*(undefined1 *)
                                            (*(int *)(param_1 + 0x14) + iVar10 + (uVar7 - 1) + 6),
                                           local_590._1_3_);
                      stats_db_sta_update_nbr(*(int *)(param_1 + 0x14) + iVar10,&local_598);
                      uVar7 = uVar7 + 1;
                      goto LAB_00674018;
                    }
                  }
                  uVar7 = uVar7 + 1;
                  goto LAB_00674018;
                }
                if (local_568 != uVar7) {
                  iVar3 = *(int *)(param_1 + 0x14);
                  goto LAB_00674034;
                }
                uVar7 = uVar7 + 1;
              } while( true );
            }
          }
        }
        uVar9 = uVar9 + 1;
      } while( true );
    }
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail.\n";
    uVar5 = 0x133;
  }
  else {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[STATISTICS_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n";
    uVar5 = 300;
  }
  printf(pcVar4,"_stats_pkt_rssi_request",uVar5);
  return 0xffffffff;
LAB_00674018:
  uVar9 = uVar9 + 1;
  goto LAB_00673f9c;
}

