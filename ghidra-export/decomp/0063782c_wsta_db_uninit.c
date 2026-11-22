// func wsta_db_uninit @ 0063782c size=816

undefined4 wsta_db_uninit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (l_wsta_data == 0) {
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> wsta data has not been inited yet!\r\n","wsta_db_uninit",
             0x433);
    }
  }
  else {
    FUN_00408060(DAT_007cc70c);
    iVar1 = FUN_004081b0(&DAT_007cc6e8);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      FUN_00408500(iVar1);
      wsta_free(iVar1);
      iVar1 = iVar2;
    }
    iVar1 = FUN_004081b0(&DAT_007cc6f4);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      FUN_00408500(iVar1);
      wsta_free(iVar1);
      iVar1 = iVar2;
    }
    iVar1 = FUN_004081b0(&DAT_007cc700);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      FUN_00408500(iVar1);
      wsta_free(iVar1);
      iVar1 = iVar2;
    }
    if (DAT_007cc6cc != 0) {
      FUN_00408310();
      DAT_007cc6cc = 0;
    }
    if (DAT_007cc6d0 != 0) {
      FUN_00408310();
      DAT_007cc6d0 = 0;
    }
    if (DAT_007cc6d4 != 0) {
      FUN_00408310();
      DAT_007cc6d4 = 0;
    }
    if (DAT_007cc718 != 0) {
      FUN_00408310();
      DAT_007cc718 = 0;
    }
    FUN_00408060(DAT_007cc714);
    if (DAT_007cc728 != 0) {
      FUN_00408310();
      DAT_007cc728 = 0;
    }
    if (DAT_007cc72c != 0) {
      FUN_00408310();
      DAT_007cc72c = 0;
    }
    if (DAT_007cc6e4 != 0) {
      iVar1 = 0;
      iVar2 = 0;
      while (iVar3 = apmngr_db_get_ap_max(), iVar2 < iVar3) {
        uVar5 = 0;
        while (uVar4 = rdmngr_profile_get_max_rd_per_ap(), uVar5 < uVar4) {
          if (*(int *)(DAT_007cc6e4 + iVar1) == 0) {
LAB_00637ab8:
            uVar5 = uVar5 + 1;
          }
          else {
            if (*(int *)(*(int *)(DAT_007cc6e4 + iVar1) + uVar5 * 4) != 0) {
              wsta_free();
              *(undefined4 *)(*(int *)(DAT_007cc6e4 + iVar1) + uVar5 * 4) = 0;
              goto LAB_00637ab8;
            }
            uVar5 = uVar5 + 1;
          }
        }
        iVar2 = iVar2 + 1;
        if (*(int *)(DAT_007cc6e4 + iVar1) != 0) {
          wsta_free();
          *(undefined4 *)(DAT_007cc6e4 + iVar1) = 0;
        }
        iVar1 = iVar1 + 4;
      }
      wsta_free(DAT_007cc6e4);
      DAT_007cc6e4 = 0;
    }
    if (DAT_007cc6c8 != 0) {
      wsta_free();
      DAT_007cc6c8 = 0;
    }
    if (DAT_007cc6c0 != 0) {
      FUN_00408160();
      DAT_007cc6c0 = 0;
    }
    if (DAT_007cc6bc != 0) {
      FUN_00408360();
      DAT_007cc6bc = 0;
    }
    l_wsta_data = 0;
    DAT_007cc6c4 = 0;
  }
  return 0;
}

