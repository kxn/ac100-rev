// func wserv_db_ap_sync_bind_list @ 005f0950 size=1580

undefined4
wserv_db_ap_sync_bind_list
          (uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,int *param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  int local_688;
  int local_684;
  undefined4 local_680;
  short sStack_67e;
  undefined2 local_67c;
  undefined4 local_678;
  undefined4 local_674;
  undefined4 local_670;
  int local_66c;
  int local_668;
  undefined4 local_664;
  int local_660 [32];
  undefined1 auStack_5e0 [20];
  int local_5cc;
  undefined4 local_5a0;
  undefined1 auStack_3c8 [192];
  undefined1 auStack_308 [728];
  int local_30;
  int local_2c;
  
  uVar15 = param_2 & 0xffff;
  param_1 = param_1 & 0xffff;
  local_684 = 0;
  local_688 = 0;
  memset(local_660,0,0x80);
  local_680 = 0;
  local_67c = 0;
  local_678 = 0;
  local_674 = 0;
  local_670 = 0;
  local_66c = 0;
  local_668 = 0;
  local_664 = 0;
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_ap_sync_bind_list: %d -> %d\r\n",
           "wserv_db_ap_sync_bind_list",0xfa9,param_1,uVar15);
  }
  iVar3 = apmngr_db_entry_get_by_id(param_1,auStack_308);
  if ((iVar3 == 0) && (iVar3 = apmngr_db_entry_get_by_id(uVar15,auStack_5e0), iVar3 == 0)) {
    iVar3 = rdmngr_db_get_radio_cnt_by_ap_id(param_1,&local_684,&local_688);
    if (iVar3 < 1) {
      uVar10 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[error]%s(): %d  -> rdmngr_db_get_radio_cnt_by_ap_id(%d) failed\r\n",
               "wserv_db_ap_sync_bind_list",0xfb5,param_1);
      }
    }
    else {
      iVar3 = 0;
      local_2c = apdb_radio_count_by_id(local_5a0,auStack_3c8);
      if (local_5cc == 5) {
        uVar17 = 0;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
LAB_005f0c50:
        if (uVar17 < l_wserv_profile) {
          iVar13 = DAT_007cbefc + uVar17 * 0x21c;
          if (*(int *)(iVar13 + 0xc) == 0) {
            uVar17 = uVar17 + 1;
          }
          else {
            if (*(int *)(iVar13 + 299) == 1) {
              iVar14 = 1;
              bVar2 = true;
              do {
                if (local_684 + local_688 < iVar14) {
                  if (bVar2) {
                    uVar17 = uVar17 + 1;
                    local_660[iVar3] = *(int *)(iVar13 + 0x90);
                    iVar3 = iVar3 + 1;
                    goto LAB_005f0c50;
                  }
                  break;
                }
                uVar10 = rdmngr_db_generate_rd_id(param_1,iVar14);
                iVar11 = 0;
                local_30 = rdmngr_db_generate_rd_idx_by_rd_id(uVar10);
                local_30 = local_30 * 0xc;
                while( true ) {
                  iVar4 = rdmngr_db_rd_entry_max_ssid_get(uVar10);
                  bVar1 = iVar11 < iVar4;
                  if ((!bVar1) ||
                     (bVar1 = true,
                     (int)*(short *)(*(int *)(DAT_007cbf04 + local_30 + 8) + iVar11 * 6 + 2) ==
                     *(int *)(iVar13 + 0x90))) break;
                  iVar11 = iVar11 + 1;
                }
                if (!bVar2) {
                  uVar17 = uVar17 + 1;
                  goto LAB_005f0c50;
                }
                iVar14 = iVar14 + 1;
                bVar2 = bVar1;
              } while (bVar1);
            }
            uVar17 = uVar17 + 1;
          }
          goto LAB_005f0c50;
        }
        iVar11 = 0;
        FUN_00407f30(DAT_007cbef0);
        uVar10 = rdmngr_db_generate_rd_id(param_1,1);
        iVar14 = rdmngr_db_generate_rd_idx_by_rd_id(uVar10);
        iVar13 = 0;
LAB_005f0d84:
        iVar4 = rdmngr_db_rd_entry_max_ssid_get(uVar10);
        if (iVar11 < iVar4) {
          iVar7 = 0;
          for (iVar4 = iVar13; iVar7 = iVar7 + 4, iVar4 < iVar3; iVar4 = iVar4 + 1) {
            iVar9 = (int)*(short *)(*(int *)(DAT_007cbf04 + iVar14 * 0xc + 8) + iVar11 * 6 + 2);
            if (iVar9 == *(int *)((int)local_660 + iVar7 + iVar13 * 4 + -4)) {
              iVar11 = iVar11 + 1;
              iVar7 = local_660[iVar13];
              local_660[iVar13] = iVar9;
              local_660[iVar4] = iVar7;
              iVar13 = iVar13 + 1;
              goto LAB_005f0d84;
            }
          }
          iVar11 = iVar11 + 1;
          goto LAB_005f0d84;
        }
        iVar13 = 1;
LAB_005f0e20:
        if (iVar13 <= local_2c) {
          uVar10 = rdmngr_db_generate_rd_id(uVar15,iVar13);
          piVar12 = local_660;
          local_30 = rdmngr_db_generate_rd_idx_by_rd_id(uVar10);
          iVar14 = 1;
          local_30 = local_30 * 0xc;
          iVar11 = 0;
          while( true ) {
            iVar4 = rdmngr_db_rd_entry_max_ssid_get(uVar10);
            if (iVar4 <= iVar11) break;
            if (iVar3 <= iVar11) {
              iVar13 = iVar13 + 1;
              goto LAB_005f0e20;
            }
            FUN_004082d0(DAT_007cbef0,0xffffffff);
            memcpy(&stack0xfffff980,(void *)(*(int *)(DAT_007cbf04 + local_30 + 8) + iVar11 * 6),6);
            FUN_00407f30(DAT_007cbef0);
            iVar4 = (int)sStack_67e;
            if (iVar4 != *piVar12) {
              if (iVar4 != -1) {
                wserv_db_rd_unbind_with_wlan_id(uVar10,iVar14,iVar4,param_4);
                local_674 = CONCAT13((char)iVar14,local_674._1_3_);
                local_678 = uVar10;
                wserv_sqlite_notify(3,&local_678,8);
              }
              wserv_db_rd_bind_with_wlan_id(uVar10,iVar14,*piVar12,0,param_3);
              local_668 = *piVar12;
              local_664 = 0;
              local_670 = uVar10;
              local_66c = iVar14;
              wserv_sqlite_notify(2,&local_670,0x10);
            }
            iVar11 = iVar11 + 1;
            iVar14 = iVar14 + 1;
            piVar12 = piVar12 + 1;
          }
          iVar13 = iVar13 + 1;
          goto LAB_005f0e20;
        }
      }
      uVar17 = 1 << (param_2 & 0x1f);
      puVar16 = (uint *)(param_5 + (uVar15 >> 5) * 4);
      iVar13 = 0;
      iVar14 = 0;
      iVar11 = 1;
      while (iVar11 <= local_2c) {
        uVar10 = rdmngr_db_generate_rd_id(uVar15,iVar11);
        iVar4 = rdmngr_db_get_rd_freq_band(uVar10);
        if (iVar4 == 0) {
          uVar5 = 0xffffffff;
          if (0 < local_684) {
            iVar4 = iVar14 + 1;
            uVar8 = 0;
            iVar14 = iVar4;
            if (local_684 < iVar4) {
              iVar4 = local_684;
              iVar14 = local_684;
            }
LAB_005f0b38:
            uVar5 = rdmngr_db_get_freq_band_rd_id(param_1,uVar8,iVar4);
          }
        }
        else {
          uVar8 = 1;
          uVar5 = 0xffffffff;
          if ((iVar4 == 1) && (0 < local_688)) {
            iVar4 = iVar13 + 1;
            iVar13 = iVar4;
            if (local_688 < iVar4) {
              iVar4 = local_688;
              iVar13 = local_688;
            }
            goto LAB_005f0b38;
          }
        }
        wserv_db_rd_entry_sync(uVar5,uVar10,local_5cc == 5,param_3,param_4,local_660,iVar3);
        if (param_5 == 0) {
          iVar11 = iVar11 + 1;
        }
        else {
          uVar6 = *puVar16;
          if ((uVar6 & uVar17) == 0) {
            *puVar16 = uVar6 | uVar17;
            if (param_6 != (int *)0x0) {
              *param_6 = *param_6 + 1;
            }
            iVar11 = iVar11 + 1;
          }
          else {
            iVar11 = iVar11 + 1;
          }
        }
      }
      uVar10 = 0;
    }
  }
  else {
    uVar10 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv_db_ap_sync_bind_list() get ap entry by ap_id error\r\n"
             ,"wserv_db_ap_sync_bind_list",0xfae);
    }
  }
  return uVar10;
}

