// func stats_db_sta_update_nbr @ 0066daec size=704

undefined4 stats_db_sta_update_nbr(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int extraout_v1;
  int iVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  
  FUN_00407e70();
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d invalid para\n","stats_db_sta_update_nbr",0xb83);
    return 0xffffffff;
  }
  uVar3 = *(ushort *)(param_2 + 1);
  iVar5 = apmngr_db_get_ap_max();
  if ((((iVar5 <= (int)(uint)uVar3) || (bVar2 = *(byte *)((int)param_2 + 6), bVar2 == 0)) ||
      (uVar6 = rdmngr_profile_get_max_rd_per_ap(), uVar6 < bVar2)) ||
     ((bVar2 = *(byte *)((int)param_2 + 7), bVar2 == 0 ||
      (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar6 < bVar2)))) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_sta_update_nbr",0xb8a,
           (uint)*(ushort *)(param_2 + 1),(uint)*(byte *)((int)param_2 + 6),
           (uint)*(byte *)((int)param_2 + 7));
    return 0xffffffff;
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  iVar5 = FUN_00407fa0(DAT_007cc8e0,param_1);
  uVar13 = 1;
  if (iVar5 == 0) goto LAB_0066dcec;
  bVar2 = *(byte *)(iVar5 + 0x1b8);
  uVar6 = (uint)bVar2;
  iVar9 = -1;
  iVar7 = 0;
  bVar4 = false;
  iVar8 = iVar5;
  iVar11 = -1;
  cVar10 = '\0';
  while (iVar7 < (int)uVar6) {
    if ((*(short *)(iVar8 + 300) == *(short *)(param_2 + 1)) &&
       (*(char *)(iVar8 + 0x12e) == *(char *)((int)param_2 + 6))) {
      iVar8 = iVar5 + iVar7 * 0xc;
      *(undefined1 *)(iVar8 + 0x12f) = *(undefined1 *)((int)param_2 + 7);
      *(undefined1 *)(iVar8 + 0x130) = *(undefined1 *)(param_2 + 2);
      goto LAB_0066dcc8;
    }
    iVar12 = iVar11;
    if ((bVar4) ||
       (iVar12 = iVar7, stats_nbr_expire_time <= (uint)(extraout_v1 - *(int *)(iVar8 + 0x128)))) {
      bVar4 = true;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0xc;
      iVar11 = iVar12;
    }
    else {
      cVar1 = *(char *)(iVar8 + 0x130);
      iVar8 = iVar8 + 0xc;
      if (cVar1 < cVar10) {
        iVar9 = iVar7;
      }
      iVar7 = iVar7 + 1;
      if (cVar1 < cVar10) {
        cVar10 = cVar1;
      }
    }
  }
  if (bVar4) {
    iVar8 = iVar5 + iVar11 * 0xc;
LAB_0066dd84:
    *(undefined4 *)(iVar8 + 0x128) = *param_2;
    *(undefined4 *)(iVar8 + 300) = param_2[1];
    *(undefined4 *)(iVar8 + 0x130) = param_2[2];
LAB_0066dcc8:
    *(int *)(iVar8 + 0x128) = extraout_v1;
  }
  else {
    if (0xb < uVar6) {
      uVar13 = 0xffffffff;
      if ((iVar9 == -1) ||
         (iVar8 = iVar5 + iVar9 * 0xc, *(char *)(param_2 + 2) < *(char *)(iVar8 + 0x130)))
      goto LAB_0066dcec;
      goto LAB_0066dd84;
    }
    iVar8 = iVar5 + uVar6 * 0xc;
    *(undefined4 *)(iVar8 + 0x128) = *param_2;
    *(undefined4 *)(iVar8 + 300) = param_2[1];
    uVar13 = param_2[2];
    *(int *)(iVar8 + 0x128) = extraout_v1;
    *(undefined4 *)(iVar8 + 0x130) = uVar13;
    *(byte *)(iVar5 + 0x1b8) = bVar2 + 1;
  }
  uVar13 = 0;
  *(byte *)(iVar5 + 0x1b9) = *(byte *)(iVar5 + 0x1b9) & 0xf7 | 3;
LAB_0066dcec:
  FUN_00407f30(l_stats_data);
  return uVar13;
}

