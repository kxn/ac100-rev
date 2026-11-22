// func _wsta_roam_collect_chnl_set_to_ap @ 00485524 size=644

undefined4 _wsta_roam_collect_chnl_set_to_ap(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_88 [8];
  char local_80;
  int local_30;
  int local_2c;
  
  memset(auStack_88,0,0x54);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (wsta_roam_err_switch != '\0') {
      printf("[WSTA_ROAM_ERROR]%s()/%d _wsta_roam_collect_chnl_set_to_ap fail\n",
             "_wsta_roam_collect_chnl_set_to_ap",0x7d1);
    }
    return 0xffffffff;
  }
  local_30 = (int)*(short *)(param_2 + 0x614);
  iVar6 = (int)*(short *)(param_2 + 0x616);
  iVar7 = (int)*(short *)(param_2 + 0x618);
  local_2c = (int)*(short *)(param_2 + 0x61a);
  iVar5 = 1;
  iVar1 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
LAB_004855b8:
  do {
    while( true ) {
      while( true ) {
        if (iVar1 < iVar5) {
          return 0;
        }
        uVar2 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar5);
        iVar3 = rdmngr_db_rd_entry_get(uVar2,auStack_88);
        if (iVar3 == 0) break;
        iVar5 = iVar5 + 1;
      }
      if ((local_80 == '\0') && (0 < local_30)) {
        if (wsta_roam_debug_switch != '\0') {
          printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
                 "_wsta_roam_collect_chnl_set_to_ap",0x7e3,uVar2,local_30);
        }
        _uac_rdmngr_rd_chnl_bw_set(uVar2,local_30,2);
      }
      if (iVar1 != 2) break;
      if (iVar5 == 2) {
        if (local_2c == 0) {
          iVar5 = 3;
        }
        else {
          _uac_rdmngr_rd_chnl_bw_set(uVar2,local_2c,2);
          if (wsta_roam_debug_switch == '\0') {
            iVar5 = 3;
          }
          else {
            uVar4 = 0x7eb;
            iVar3 = local_2c;
LAB_00485684:
            printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
                   "_wsta_roam_collect_chnl_set_to_ap",uVar4,uVar2,iVar3);
            iVar5 = iVar5 + 1;
          }
        }
      }
      else {
        iVar5 = iVar5 + 1;
      }
    }
    if (iVar1 == 3) {
      if (((iVar6 == 0) || (iVar3 = rdmngr_db_get_band_by_channel(iVar6), iVar5 != iVar3)) ||
         (_uac_rdmngr_rd_chnl_bw_set(uVar2,iVar6,2), wsta_roam_debug_switch == '\0')) {
        if (iVar7 == 0) {
          iVar5 = iVar5 + 1;
          goto LAB_004855b8;
        }
      }
      else {
        printf("[WSTA_ROAM_DEBUG]%s()/%d rd_id:%d, set chnl:%d\n",
               "_wsta_roam_collect_chnl_set_to_ap",0x7f3,uVar2,iVar6);
        if (iVar7 == 0) {
          iVar5 = iVar5 + 1;
          goto LAB_004855b8;
        }
      }
      iVar3 = rdmngr_db_get_band_by_channel(iVar7);
      if (iVar5 == iVar3) {
        _uac_rdmngr_rd_chnl_bw_set(uVar2,iVar7,2);
        if (wsta_roam_debug_switch != '\0') {
          uVar4 = 0x7f8;
          iVar3 = iVar7;
          goto LAB_00485684;
        }
        iVar5 = iVar5 + 1;
      }
      else {
        iVar5 = iVar5 + 1;
      }
      goto LAB_004855b8;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

