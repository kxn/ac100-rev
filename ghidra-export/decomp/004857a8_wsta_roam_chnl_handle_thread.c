// func wsta_roam_chnl_handle_thread @ 004857a8 size=1696

undefined4 wsta_roam_chnl_handle_thread(int param_1)

{
  int iVar1;
  undefined2 uVar3;
  int iVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  reset_acs_container();
  if (param_1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x608) < 1) || (iVar1 = apmngr_db_active_ap_num_get(), iVar1 == 0))
  goto LAB_00485a8c;
  if (*(int *)(param_1 + 0x610) == 0) {
    iVar9 = 0;
    iVar1 = -1;
    iVar8 = -1;
    iVar4 = 1;
    iVar5 = param_1;
    do {
      iVar6 = *(int *)(iVar5 + 4);
      if ((iVar6 != -1) && ((iVar1 == -1 || (iVar6 < iVar1)))) {
        iVar9 = *(int *)(iVar5 + 0x308);
        iVar1 = iVar6;
        iVar8 = iVar4;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 != 0xe);
    iVar4 = 1;
    iVar5 = param_1;
    do {
      if (iVar1 == -1) break;
      if ((iVar1 == *(int *)(iVar5 + 4)) && (*(int *)(iVar5 + 0x308) < iVar9)) {
        iVar8 = iVar4;
        iVar9 = *(int *)(iVar5 + 0x308);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 != 0xf);
    uVar3 = 1;
    if (iVar8 != -1) {
      uVar3 = (short)iVar8;
    }
    *(undefined2 *)(param_1 + 0x614) = uVar3;
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d min_bss_channel:%d\n","wsta_roam_chnl_handle_thread",0x830);
    }
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d rej 2g chnl:%d\n","wsta_roam_chnl_handle_thread",0x831,
             (int)*(short *)(param_1 + 0x614));
    }
    iVar1 = -1;
    iVar8 = -1;
    iVar4 = 0xf;
    iVar5 = param_1;
    do {
      iVar6 = *(int *)(iVar5 + 0x3c);
      if ((iVar6 != -1) && ((iVar1 == -1 || (iVar6 < iVar1)))) {
        iVar9 = *(int *)(iVar5 + 0x340);
        iVar1 = iVar6;
        iVar8 = iVar4;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 != 0xc1);
    iVar4 = 0xf;
    iVar5 = param_1;
    do {
      if (iVar1 == -1) break;
      if ((iVar1 == *(int *)(iVar5 + 0x3c)) && (*(int *)(iVar5 + 0x340) < iVar9)) {
        iVar9 = *(int *)(iVar5 + 0x340);
        iVar8 = iVar4;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 != 0xc1);
    uVar3 = 0x24;
    if (iVar8 != -1) {
      uVar3 = (short)iVar8;
    }
    *(undefined2 *)(param_1 + 0x61a) = uVar3;
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d min_bss_channel:%d\n","wsta_roam_chnl_handle_thread",0x84a,
             iVar8);
    }
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d rej best 5g chnl:%d\n","wsta_roam_chnl_handle_thread",0x84b,
             (int)*(short *)(param_1 + 0x61a));
    }
    iVar4 = -1;
    iVar9 = -1;
    iVar5 = 0xf;
    iVar1 = param_1;
    do {
      if ((*(int *)(iVar1 + 0x3c) != -1) && ((iVar9 == -1 || (*(int *)(iVar1 + 0x3c) < iVar9)))) {
        iVar6 = rdmngr_db_get_band_by_channel(iVar5);
        iVar2 = rdmngr_db_get_band_by_channel((int)*(short *)(param_1 + 0x61a));
        if (iVar6 != iVar2) {
          iVar9 = *(int *)(iVar1 + 0x3c);
          iVar4 = *(int *)(iVar1 + 0x340);
          iVar8 = iVar5;
        }
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar5 != 0xc1);
    iVar5 = 0xf;
    iVar1 = param_1;
    do {
      if (iVar9 == -1) break;
      if ((iVar9 == *(int *)(iVar1 + 0x3c)) && (*(int *)(iVar1 + 0x340) < iVar4)) {
        iVar6 = rdmngr_db_get_band_by_channel(iVar5);
        iVar2 = rdmngr_db_get_band_by_channel((int)*(short *)(param_1 + 0x61a));
        if (iVar6 != iVar2) {
          iVar4 = *(int *)(iVar1 + 0x340);
          iVar8 = iVar5;
        }
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar5 != 0xc1);
    iVar1 = rdmngr_db_get_band_by_channel((int)*(short *)(param_1 + 0x61a));
    if (iVar1 == 2) {
      *(undefined2 *)(param_1 + 0x616) = *(undefined2 *)(param_1 + 0x61a);
      uVar3 = 0x95;
      if (iVar8 != -1) {
        uVar3 = (short)iVar8;
      }
      *(undefined2 *)(param_1 + 0x618) = uVar3;
    }
    else {
      *(undefined2 *)(param_1 + 0x618) = *(undefined2 *)(param_1 + 0x61a);
      uVar3 = 0x24;
      if (iVar8 != -1) {
        uVar3 = (short)iVar8;
      }
      *(undefined2 *)(param_1 + 0x616) = uVar3;
    }
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d rej 5g1 chnl:%d\n","wsta_roam_chnl_handle_thread",0x876,
             (int)*(short *)(param_1 + 0x616));
    }
    if (wsta_roam_debug_switch == '\0') {
      iVar1 = (int)*(short *)(param_1 + 0x614);
    }
    else {
      uVar7 = 0x877;
LAB_00485ca8:
      printf("[WSTA_ROAM_DEBUG]%s()/%d rej 5g2 chnl:%d\n","wsta_roam_chnl_handle_thread",uVar7,
             (int)*(short *)(param_1 + 0x618));
      iVar1 = (int)*(short *)(param_1 + 0x614);
    }
  }
  else {
    iVar9 = 1;
    iVar1 = -1;
    iVar5 = param_1;
    iVar8 = -1;
    do {
      iVar2 = *(int *)(iVar5 + 0x308);
      iVar4 = iVar1;
      iVar6 = iVar8;
      if (((iVar2 != -1) && (iVar4 = iVar2, iVar6 = iVar9, iVar1 != -1)) &&
         (iVar4 = iVar1, iVar6 = iVar8, iVar2 < iVar1)) {
        iVar4 = iVar2;
        iVar6 = iVar9;
      }
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 4;
      iVar1 = iVar4;
      iVar8 = iVar6;
    } while (iVar9 != 0xf);
    uVar3 = 1;
    if (iVar6 != -1) {
      uVar3 = (short)iVar6;
    }
    *(undefined2 *)(param_1 + 0x614) = uVar3;
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d min_load_channel:%d\n","wsta_roam_chnl_handle_thread",0x88a);
    }
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d 2g chnl:%d\n","wsta_roam_chnl_handle_thread",0x88b,
             (int)*(short *)(param_1 + 0x614));
    }
    iVar1 = 0xf;
    iVar5 = -1;
    iVar8 = param_1;
    iVar9 = -1;
    do {
      iVar2 = *(int *)(iVar8 + 0x340);
      iVar4 = iVar5;
      iVar6 = iVar9;
      if (((iVar2 != -1) && (iVar4 = iVar2, iVar6 = iVar1, iVar5 != -1)) &&
         (iVar4 = iVar5, iVar6 = iVar9, iVar2 < iVar5)) {
        iVar4 = iVar2;
        iVar6 = iVar1;
      }
      iVar1 = iVar1 + 1;
      iVar8 = iVar8 + 4;
      iVar5 = iVar4;
      iVar9 = iVar6;
    } while (iVar1 != 0xc1);
    uVar3 = 0x24;
    if (iVar6 != -1) {
      uVar3 = (short)iVar6;
    }
    *(undefined2 *)(param_1 + 0x61a) = uVar3;
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d min_load_channel:%d\n","wsta_roam_chnl_handle_thread",0x89a);
    }
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d best 5g chnl:%d\n","wsta_roam_chnl_handle_thread",0x89b,
             (int)*(short *)(param_1 + 0x61a));
    }
    iVar8 = -1;
    iVar1 = 0xf;
    iVar5 = param_1;
    do {
      if ((*(int *)(iVar5 + 0x340) != -1) && ((iVar8 == -1 || (*(int *)(iVar5 + 0x340) < iVar8)))) {
        iVar9 = rdmngr_db_get_band_by_channel(iVar1);
        iVar4 = rdmngr_db_get_band_by_channel((int)*(short *)(param_1 + 0x61a));
        if (iVar9 != iVar4) {
          iVar8 = *(int *)(iVar5 + 0x340);
        }
      }
      iVar1 = iVar1 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar1 != 0xc1);
    iVar1 = rdmngr_db_get_band_by_channel((int)*(short *)(param_1 + 0x61a));
    if (iVar1 == 2) {
      *(undefined2 *)(param_1 + 0x616) = *(undefined2 *)(param_1 + 0x61a);
      *(undefined2 *)(param_1 + 0x618) = 0x95;
    }
    else {
      *(undefined2 *)(param_1 + 0x618) = *(undefined2 *)(param_1 + 0x61a);
      *(undefined2 *)(param_1 + 0x616) = 0x24;
    }
    if (wsta_roam_debug_switch != '\0') {
      printf("[WSTA_ROAM_DEBUG]%s()/%d rej 5g1 chnl:%d\n","wsta_roam_chnl_handle_thread",0x8b6,
             (int)*(short *)(param_1 + 0x616));
    }
    if (wsta_roam_debug_switch != '\0') {
      uVar7 = 0x8b7;
      goto LAB_00485ca8;
    }
    iVar1 = (int)*(short *)(param_1 + 0x614);
  }
  if (iVar1 < 1) {
    if (*(short *)(param_1 + 0x616) < 1) {
      if (*(short *)(param_1 + 0x618) < 1) goto LAB_00485a8c;
      iVar1 = (int)*(short *)(param_1 + 0x616);
    }
    else {
      iVar1 = (int)*(short *)(param_1 + 0x616);
    }
  }
  else {
    update_high_per_ap_chn_info(1,iVar1,1);
    iVar1 = (int)*(short *)(param_1 + 0x616);
  }
  if (0 < iVar1) {
    update_high_per_ap_chn_info(2,iVar1,1);
  }
  if (0 < *(short *)(param_1 + 0x618)) {
    update_high_per_ap_chn_info(3,(int)*(short *)(param_1 + 0x618),1);
  }
  apmngr_db_foreach_proc(0x15f0000,_wsta_roam_collect_chnl_set_to_ap,param_1);
LAB_00485a8c:
  FUN_00407df0(param_1);
  return 0;
}

