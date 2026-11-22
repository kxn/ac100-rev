// func stats_db_ap_init @ 0066e12c size=724

undefined4 stats_db_ap_init(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  param_2 = param_2 & 0xff;
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    uVar2 = rdmngr_profile_get_max_rd_per_ap();
    if (param_2 <= uVar2) {
      iVar9 = param_1 * 0x1e0;
      FUN_004082d0(l_stats_data,0xffffffff);
      iVar1 = DAT_007cc8ec;
      iVar3 = DAT_007cc8ec + iVar9;
      if (iVar3 != -0x18) {
        *(undefined4 *)(iVar3 + 0x88) = 0;
        *(undefined4 *)(iVar3 + 0x74) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x78) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x7c) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x80) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x84) = 0xffffffff;
      }
      *(undefined4 *)(iVar1 + 8) = 0;
      iVar1 = 0;
      iVar3 = 1;
      *(undefined4 *)(DAT_007cc8ec + 0xc) = 0;
      do {
        if ((int)param_2 < iVar3) {
          FUN_00407f30(l_stats_data);
          return 0;
        }
        pcVar6 = (char *)(*(int *)(DAT_007cc8ec + iVar9 + 0x1d8) + iVar1);
        if ((*pcVar6 == '\0') && (*(int *)(pcVar6 + 4) == 0)) {
          uVar7 = FUN_004082a0(1,0x168,0xc63);
          *(undefined4 *)(pcVar6 + 4) = uVar7;
          iVar8 = DAT_007cc8ec + iVar9;
          if (*(int *)(*(int *)(iVar8 + 0x1d8) + iVar1 + 4) == 0) {
            if (stats_err_switch != '\0') {
              printf("[STATISTICS_ERROR]%s()/%d No memory left\n","stats_db_ap_init",0xc66);
            }
LAB_0066e3ac:
            FUN_00407f30(l_stats_data);
            return 0xffffffff;
          }
          reset_stats_db_rd_sample();
          iVar8 = *(int *)(*(int *)(iVar8 + 0x1d8) + iVar1 + 4);
          uVar7 = rdmngr_profile_get_max_wlan_per_rd();
          uVar7 = FUN_004082a0(uVar7,0x100,0xc6d);
          *(undefined4 *)(iVar8 + 0x160) = uVar7;
          if (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar9 + 0x1d8) + iVar1 + 4) + 0x160) == 0) {
            FUN_00407df0();
            *(undefined4 *)(*(int *)(DAT_007cc8ec + iVar9 + 0x1d8) + iVar1 + 4) = 0;
            goto LAB_0066e3ac;
          }
          iVar8 = 0;
          uVar2 = 1;
          while (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 <= uVar4) {
            iVar5 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar9 + 0x1d8) + iVar1 + 4) + 0x160) +
                    iVar8;
            uVar2 = uVar2 + 1;
            if (iVar5 != 0) {
              *(undefined1 *)(iVar5 + 0x48) = 0;
              *(undefined4 *)(iVar5 + 0x14) = 0xffffffff;
              *(undefined4 *)(iVar5 + 0x18) = 0xffffffff;
              *(undefined4 *)(iVar5 + 0x58) = 0xffffffff;
              *(undefined4 *)(iVar5 + 0x5c) = 0xffffffff;
            }
            iVar8 = iVar8 + 0x100;
          }
        }
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + 8;
      } while( true );
    }
    if (stats_err_switch != '\0') {
      pcVar6 = "[STATISTICS_ERROR]%s()/%d radio cnt out of range[%u]\n";
      uVar7 = 0xc57;
      goto LAB_0066e1fc;
    }
  }
  else if (stats_warning_switch != '\0') {
    pcVar6 = "[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n";
    uVar7 = 0xc52;
    param_2 = param_1;
LAB_0066e1fc:
    printf(pcVar6,"stats_db_ap_init",uVar7,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

