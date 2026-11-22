// func _wsta_roam_rd_chnl_changed_by_subdev @ 00485e48 size=376

undefined4 _wsta_roam_rd_chnl_changed_by_subdev(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char local_18 [8];
  
  local_18[0] = '\0';
  if (wsta_roam_debug_switch == '\0') {
    sVar1 = *(short *)(param_3 + 0x3c);
  }
  else {
    printf("[WSTA_ROAM_DEBUG]%s()/%d new_rd_entry->rd_cfg.realChnl:%d\n",
           "_wsta_roam_rd_chnl_changed_by_subdev",0xd7a,(int)*(short *)(param_3 + 0x3c));
    sVar1 = *(short *)(param_3 + 0x3c);
  }
  iVar3 = (int)sVar1;
  if (iVar3 == -1) {
    iVar3 = (int)*(short *)(param_3 + 0xc);
  }
  local_18[0] = rdmngr_db_get_band_by_channel(iVar3);
  rdmngr_working_channel_set_update((int)*(short *)(param_2 + 0x3c),(int)*(short *)(param_3 + 0x3c))
  ;
  iVar2 = (int)*(short *)(param_3 + 0x3c);
  iVar3 = (int)*(short *)(param_3 + 0xc);
  if (((iVar2 == -1) && (iVar3 == -1)) && (local_18[0] == '\0')) {
    if (wsta_roam_debug_switch == '\0') {
      return 0;
    }
    uVar4 = 0xd88;
  }
  else {
    if ((iVar3 == -1) || (iVar3 == iVar2)) {
      if (iVar2 != -1) {
        iVar3 = iVar2;
      }
      iVar3 = update_high_per_ap_chn_info((int)local_18[0],iVar3,0);
      if (iVar3 != 0) {
        return 0;
      }
      if (wsta_roam_debug_switch != '\0') {
        printf("[WSTA_ROAM_DEBUG]%s()/%d wsta_intelligent_roam_update_all_ap_rd_info enter\n",
               "wsta_intelligent_roam_update_all_ap_rd_info",0xc19);
      }
      apmngr_db_foreach_proc(0x15f0000,_wsta_intelligent_roam_set_rd_info,local_18);
      return 0;
    }
    if (wsta_roam_debug_switch == '\0') {
      return 0;
    }
    uVar4 = 0xd8d;
  }
  printf("[WSTA_ROAM_DEBUG]%s()/%d don\'t set high chnl\n","_wsta_roam_rd_chnl_changed_by_subdev",
         uVar4);
  return 0;
}

