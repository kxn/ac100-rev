// func stats_db_uninit @ 0066aef0 size=552

undefined4 stats_db_uninit(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  FUN_00408060(DAT_007cc8e8);
  DAT_007cc8e8 = 0xffffffff;
  if (DAT_007cc8e0 != 0) {
    FUN_00408310();
    DAT_007cc8e0 = 0;
  }
  if (DAT_007cc8e4 != 0) {
    FUN_00407df0();
    DAT_007cc8e4 = 0;
  }
  if (DAT_007cc8dc != 0) {
    FUN_00408160();
    DAT_007cc8dc = 0;
  }
  iVar6 = 0;
  if (DAT_007cc8ec != 0) {
    while (iVar1 = apmngr_db_get_ap_max(), iVar6 < iVar1) {
      iVar1 = iVar6 * 0x1e0;
      if (*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) == 0) {
        iVar6 = iVar6 + 1;
      }
      else {
        iVar5 = 0;
        uVar7 = 1;
        while (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar7 <= uVar2) {
          iVar3 = *(int *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar5 + 4);
          if (iVar3 == 0) {
LAB_0066b02c:
            uVar7 = uVar7 + 1;
            iVar5 = iVar5 + 8;
          }
          else {
            if (*(int *)(iVar3 + 0x160) != 0) {
              FUN_00407df0();
            }
            pcVar4 = (char *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar5);
            if (*pcVar4 != '\0') goto LAB_0066b02c;
            uVar7 = uVar7 + 1;
            FUN_00407df0(*(undefined4 *)(pcVar4 + 4));
            iVar3 = *(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar5;
            iVar5 = iVar5 + 8;
            *(undefined4 *)(iVar3 + 4) = 0;
          }
        }
        FUN_00407df0(*(undefined4 *)(DAT_007cc8ec + iVar1 + 0x1d8));
        iVar6 = iVar6 + 1;
      }
    }
    FUN_00407df0(DAT_007cc8ec);
    DAT_007cc8ec = 0;
  }
  if (DAT_007cc8f0 != 0) {
    FUN_00407df0();
    DAT_007cc8f0 = 0;
  }
  if (l_stats_data != 0) {
    FUN_00408360();
    l_stats_data = 0;
  }
  if (stat_gloabl_data_mutex != 0) {
    FUN_00408360();
    stat_gloabl_data_mutex = 0;
  }
  if (DAT_007cc8f4 != 0) {
    FUN_00408310();
    DAT_007cc8f4 = 0;
  }
  return 0;
}

