// func stats_db_ssid_update @ 006702c4 size=1188

undefined4 stats_db_ssid_update(ushort param_1,byte param_2,byte param_3,int param_4)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_250;
  undefined2 local_24c;
  undefined1 auStack_248 [6];
  ushort local_242;
  byte local_240;
  byte local_23f;
  undefined1 auStack_23c [283];
  int local_121;
  int local_30;
  
  uVar10 = (uint)param_3;
  uVar9 = (uint)param_2;
  uVar8 = (uint)param_1;
  local_250 = 0;
  local_24c = 0;
  if (param_4 == 0) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_ssid_update",0x1098);
    return 0xffffffff;
  }
  iVar4 = apmngr_db_get_ap_max();
  if ((((iVar4 <= (int)uVar8) || (uVar9 == 0)) ||
      (uVar5 = rdmngr_profile_get_max_rd_per_ap(), uVar5 < uVar9)) ||
     ((uVar10 == 0 || (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar5 < uVar10)))) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_ssid_update",0x109e,uVar8
           ,uVar9,uVar10);
    return 0xffffffff;
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  iVar11 = (uVar9 - 1) * 8;
  local_30 = (uVar10 - 1) * 0x100;
  iVar4 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + uVar8 * 0x1e0 + 0x1d8) + iVar11 + 4) + 0x160) +
          local_30;
  FUN_00407f30(l_stats_data);
  memset(auStack_23c,0,0x205);
  if ((*(byte *)(iVar4 + 8) & 1) == 0) {
    uVar6 = rdmngr_db_generate_rd_id(uVar8,uVar9);
    iVar4 = wserv_db_rd_get_wserv_id(uVar6,uVar10);
    if (((iVar4 != -1) && (iVar4 = uac_wservice_get_entry_by_id(iVar4,auStack_23c), iVar4 == 0)) &&
       (local_121 == 1)) {
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d ap_id:%d radio_id:%d, self to active radio.\n",
               "stats_db_ssid_update",0x10ac,uVar8,uVar9);
      }
      stats_db_ssid_active(uVar8,uVar9,uVar10);
    }
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  puVar7 = (undefined4 *)
           (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + uVar8 * 0x1e0 + 0x1d8) + iVar11 + 4) + 0x160)
           + local_30);
  if (puVar7 != (undefined4 *)0x0) {
    bVar1 = *(byte *)(puVar7 + 2);
    if ((bVar1 & 1) != 0) {
      memcpy(&local_250,(void *)((int)puVar7 + 9),6);
      *puVar7 = 0;
      *(byte *)(puVar7 + 2) = bVar1 & 0xf7 | 0x16;
      memcpy((void *)((int)puVar7 + 9),(void *)(param_4 + 9),6);
      *(undefined2 *)(puVar7 + 4) = *(undefined2 *)(param_4 + 0x10);
      *(undefined1 *)((int)puVar7 + 0x12) = *(undefined1 *)(param_4 + 0x12);
      *(undefined1 *)((int)puVar7 + 0x13) = *(undefined1 *)(param_4 + 0x13);
      puVar7[5] = *(undefined4 *)(param_4 + 0x14);
      puVar7[6] = *(undefined4 *)(param_4 + 0x18);
      if (puVar7[8] == -1) {
        if (puVar7[9] != -1) {
          uVar9 = *(uint *)(param_4 + 0x24);
          goto LAB_00670568;
        }
        uVar6 = *(undefined4 *)(param_4 + 0x20);
        puVar7[9] = *(undefined4 *)(param_4 + 0x24);
        puVar7[8] = uVar6;
      }
      else {
        uVar9 = *(uint *)(param_4 + 0x24);
LAB_00670568:
        iVar4 = *(int *)(param_4 + 0x20);
        uVar10 = uVar9 + puVar7[9];
        puVar7[9] = uVar10;
        puVar7[8] = (uint)(uVar10 < uVar9) + iVar4 + puVar7[8];
      }
      if (puVar7[10] == -1) {
        if (puVar7[0xb] != -1) {
          uVar9 = *(uint *)(param_4 + 0x2c);
          goto LAB_00670598;
        }
        uVar6 = *(undefined4 *)(param_4 + 0x28);
        puVar7[0xb] = *(undefined4 *)(param_4 + 0x2c);
        puVar7[10] = uVar6;
      }
      else {
        uVar9 = *(uint *)(param_4 + 0x2c);
LAB_00670598:
        iVar4 = *(int *)(param_4 + 0x28);
        uVar10 = uVar9 + puVar7[0xb];
        puVar7[0xb] = uVar10;
        puVar7[10] = (uint)(uVar10 < uVar9) + iVar4 + puVar7[10];
      }
      if (puVar7[0x16] == -1) {
        puVar7[0x16] = *(int *)(param_4 + 0x24);
      }
      else {
        puVar7[0x16] = *(int *)(param_4 + 0x24) + puVar7[0x16];
      }
      if (puVar7[0x17] == -1) {
        puVar7[0x17] = *(int *)(param_4 + 0x2c);
      }
      else {
        puVar7[0x17] = *(int *)(param_4 + 0x2c) + puVar7[0x17];
      }
      memcpy(auStack_248,(void *)((int)puVar7 + 9),6);
      bVar3 = false;
      local_242 = param_1;
      local_240 = param_2;
      local_23f = param_3;
      iVar4 = memcmp(&local_250,auStack_248,6);
      if ((iVar4 != 0) && (iVar4 = memcmp(&local_250,&bssid_empty,6), iVar4 != 0)) {
        bVar3 = true;
        stats_db_bssid_del(&local_250);
      }
      bVar2 = false;
      iVar4 = memcmp(&bssid_empty,auStack_248,6);
      if (iVar4 != 0) {
        stats_db_bssid_update(auStack_248);
        iVar4 = memcmp(&local_250,&bssid_empty,6);
        bVar2 = iVar4 == 0;
      }
      goto LAB_00670464;
    }
  }
  bVar2 = false;
  bVar3 = false;
LAB_00670464:
  FUN_00407f30(l_stats_data);
  if (bVar3) {
    bssid_changed_callback_proc(1,uVar8);
  }
  if (bVar2) {
    bssid_changed_callback_proc(0,uVar8);
  }
  return 0;
}

