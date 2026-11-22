// func stats_db_sta_update_cnt_target @ 0066d0d8 size=1016

/* WARNING: Removing unreachable block (ram,0x0066d2e0) */

undefined4 stats_db_sta_update_cnt_target(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  
  if (param_1 == (void *)0x0) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d entry is null!\n","stats_db_sta_update_cnt_target",0x9e8);
    return 0xffffffff;
  }
  uVar2 = *(ushort *)((int)param_1 + 6);
  iVar4 = apmngr_db_get_ap_max();
  if ((((iVar4 <= (int)(uint)uVar2) || (bVar1 = *(byte *)((int)param_1 + 8), bVar1 == 0)) ||
      (uVar5 = rdmngr_profile_get_max_rd_per_ap(), uVar5 < bVar1)) ||
     ((bVar1 = *(byte *)((int)param_1 + 9), bVar1 == 0 ||
      (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar5 < bVar1)))) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_sta_update_cnt_target",
           0x9ef,(uint)*(ushort *)((int)param_1 + 6),(uint)*(byte *)((int)param_1 + 8),
           (uint)*(byte *)((int)param_1 + 9));
    return 0xffffffff;
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  iVar4 = FUN_00407fa0(DAT_007cc8e0,param_1);
  if (iVar4 == 0) {
    while (iVar4 = FUN_004085b0(DAT_007cc8dc), iVar4 == -1) {
      uVar5 = 0;
      uVar11 = 0;
      uVar12 = 0xffffffff;
      while( true ) {
        uVar9 = uVar5;
        iVar4 = wsta_profile_get_max_wstation();
        uVar5 = wsta_profile_get_max_wstation();
        if (uVar5 / 10 + iVar4 <= uVar9) break;
        iVar4 = DAT_007cc8e4 + uVar9 * 0x1c0;
        if (iVar4 == 0) {
          uVar5 = uVar9 + 1;
        }
        else if (*(int *)(iVar4 + 0x40) == 0) {
          uVar5 = uVar9 + 1;
        }
        else if ((*(byte *)(iVar4 + 0xc) & 8) == 0) {
          uVar5 = uVar9 + 1;
        }
        else {
          iVar6 = FUN_00407fa0(DAT_007cc8e0,iVar4 + 2);
          if (iVar6 == 0) {
            uVar5 = uVar9 + 1;
          }
          else if ((uVar11 == 0) || (*(uint *)(iVar4 + 0x40) < uVar11)) {
            uVar5 = uVar9 + 1;
            uVar11 = *(uint *)(iVar4 + 0x40);
            uVar12 = uVar9;
          }
          else {
            uVar5 = uVar9 + 1;
          }
        }
      }
      if (uVar12 == 0xffffffff) {
        uVar8 = 2;
        goto LAB_0066d20c;
      }
      _stats_sta_free_entry(DAT_007cc8e4 + uVar12 * 0x1c0);
    }
    iVar10 = iVar4 * 0x1c0;
    memset((void *)(DAT_007cc8e4 + iVar10),0,0x1c0);
    *(short *)(DAT_007cc8e4 + iVar10) = (short)iVar4;
    memcpy((void *)(DAT_007cc8e4 + iVar10 + 2),param_1,6);
    *(undefined2 *)(DAT_007cc8e4 + iVar10 + 8) = *(undefined2 *)((int)param_1 + 6);
    *(undefined1 *)(DAT_007cc8e4 + iVar10 + 10) = *(undefined1 *)((int)param_1 + 8);
    *(undefined1 *)(DAT_007cc8e4 + iVar10 + 0xb) = *(undefined1 *)((int)param_1 + 9);
    uVar3 = DAT_007cc8e0;
    iVar6 = DAT_007cc8e4 + iVar10;
    *(undefined1 *)(iVar6 + 0x11) = 0xff;
    *(undefined1 *)(iVar6 + 0x12) = 0xff;
    *(byte *)(iVar6 + 0xc) = *(byte *)(iVar6 + 0xc) | 1;
    *(byte *)(DAT_007cc8e4 + iVar10 + 0xc) = *(byte *)(DAT_007cc8e4 + iVar10 + 0xc) & 0xf7;
    iVar7 = DAT_007cc8e4 + iVar10;
    *(undefined1 *)(iVar7 + 0xf) = 0x7f;
    iVar6 = DAT_007cc8e4;
    uVar8 = 0;
    *(undefined4 *)(iVar7 + 100) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0x60) = 0xffffffff;
    iVar6 = iVar6 + iVar10;
    *(undefined2 *)(iVar6 + 0x14) = 0xffff;
    *(undefined4 *)(iVar6 + 0x24) = 0xffffffff;
    *(undefined4 *)(iVar6 + 0x28) = 0xffffffff;
    iVar6 = FUN_00408380(uVar3);
    if (iVar6 != 0) {
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d uac_hash_add() fail, wsra_id = %d!\n",
               "stats_db_sta_update_cnt_target",0xa23,iVar4);
      }
      memset((void *)(DAT_007cc8e4 + iVar10),0,0x1c0);
      uVar8 = 0xffffffff;
      FUN_004080f0(DAT_007cc8dc,iVar4);
    }
    goto LAB_0066d20c;
  }
  *(undefined2 *)(iVar4 + 8) = *(undefined2 *)((int)param_1 + 6);
  *(undefined1 *)(iVar4 + 10) = *(undefined1 *)((int)param_1 + 8);
  *(undefined1 *)(iVar4 + 0xb) = *(undefined1 *)((int)param_1 + 9);
  if (*(int *)(iVar4 + 0x58) == *(int *)(iVar4 + 0x48)) {
    if (*(int *)(iVar4 + 0x5c) == *(int *)(iVar4 + 0x4c)) {
      uVar13 = FUN_00524078();
      *(undefined8 *)(iVar4 + 0x48) = uVar13;
      goto LAB_0066d1f0;
    }
    bVar1 = *(byte *)(iVar4 + 0xc);
  }
  else {
LAB_0066d1f0:
    bVar1 = *(byte *)(iVar4 + 0xc);
  }
  *(undefined4 *)(iVar4 + 0x40) = 0;
  *(byte *)(iVar4 + 0xc) = bVar1 & 0xf7 | 1;
  uVar8 = 0;
LAB_0066d20c:
  FUN_00407f30(l_stats_data);
  return uVar8;
}

