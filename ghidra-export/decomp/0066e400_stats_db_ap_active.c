// func stats_db_ap_active @ 0066e400 size=784

undefined4 stats_db_ap_active(uint param_1,void *param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  char *__format;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  
  param_3 = param_3 & 0xff;
  param_1 = param_1 & 0xffff;
  uVar12 = FUN_00524078();
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= (int)param_1) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n";
    uVar7 = 0xce3;
    param_3 = param_1;
LAB_0066e638:
    printf(__format,"stats_db_ap_active",uVar7,param_3);
    return 0xffffffff;
  }
  uVar3 = rdmngr_profile_get_max_rd_per_ap();
  if (uVar3 < param_3) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[STATISTICS_ERROR]%s()/%d radio cnt out of range[%u]\n";
    uVar7 = 0xce8;
    goto LAB_0066e638;
  }
  if (((param_2 == (void *)0x0) || (param_4 == 0)) || (param_5 == 0)) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d input is NULL !\n","stats_db_ap_active",0xcee);
    return 0xffffffff;
  }
  iVar2 = param_1 * 0x1e0;
  FUN_004082d0(l_stats_data,0xffffffff);
  pbVar6 = (byte *)(DAT_007cc8ec + iVar2);
  if (*(int *)(pbVar6 + 0x68) == *(int *)(pbVar6 + 0x58)) {
    if (*(int *)(pbVar6 + 0x6c) != *(int *)(pbVar6 + 0x5c)) {
      bVar1 = *pbVar6;
      goto LAB_0066e500;
    }
    *(undefined8 *)(pbVar6 + 0x58) = uVar12;
  }
  bVar1 = *pbVar6;
LAB_0066e500:
  pbVar6[4] = 0;
  pbVar6[5] = 0;
  pbVar6[6] = 0;
  pbVar6[7] = 0;
  pbVar6[0xc] = 0;
  pbVar6[0xd] = 0;
  pbVar6[0xe] = 0;
  pbVar6[0xf] = 0;
  *pbVar6 = bVar1 & 0xf7 | 1;
  memcpy(pbVar6 + 0x10,param_2,6);
  iVar11 = 0;
  while (iVar9 = iVar11, iVar11 = iVar9 + 1, iVar11 <= (int)param_3) {
    pbVar6 = *(byte **)(*(int *)(DAT_007cc8ec + iVar2 + 0x1d8) + iVar9 * 8 + 4);
    if (pbVar6 != (byte *)0x0) {
      if ((*(int *)(pbVar6 + 0x68) == *(int *)(pbVar6 + 0x40)) &&
         (*(int *)(pbVar6 + 0x6c) == *(int *)(pbVar6 + 0x44))) {
        *(undefined8 *)(pbVar6 + 0x40) = uVar12;
      }
      if (*(char *)(param_4 + iVar9) != '\0') {
        *pbVar6 = *pbVar6 & 0xf7 | 1;
        uVar3 = 0;
        while( true ) {
          uVar10 = uVar3 + 1;
          uVar4 = rdmngr_profile_get_max_wlan_per_rd();
          if (uVar4 < uVar10) break;
          iVar8 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar2 + 0x1d8) + iVar9 * 8 + 4) + 0x160)
                  + uVar3 * 0x100;
          iVar5 = rdmngr_profile_get_max_wlan_per_rd();
          if (*(char *)(param_5 + uVar3 + iVar5 * iVar9) == '\0') {
            iVar5 = *(int *)(iVar8 + 0x50);
          }
          else {
            *(byte *)(iVar8 + 8) = *(byte *)(iVar8 + 8) & 0xf7 | 1;
            iVar5 = *(int *)(iVar8 + 0x50);
          }
          uVar3 = uVar10;
          if ((iVar5 == *(int *)(iVar8 + 0x40)) &&
             (*(int *)(iVar8 + 0x54) == *(int *)(iVar8 + 0x44))) {
            *(undefined8 *)(iVar8 + 0x40) = uVar12;
          }
        }
      }
    }
  }
  FUN_00407f30(l_stats_data);
  return 0;
}

