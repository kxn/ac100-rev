// func _wsta_roam_rd_chnl_modify_by_manual @ 00489b60 size=160

undefined4 _wsta_roam_rd_chnl_modify_by_manual(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char local_10 [8];
  
  local_10[0] = '\0';
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d new_rd_entry->rd_cfg.chnl:%d\n",
           "_wsta_roam_rd_chnl_modify_by_manual",0xd9f,(int)*(short *)(param_3 + 0xc));
  }
  local_10[0] = rdmngr_db_get_band_by_channel((int)*(short *)(param_3 + 0xc));
  iVar1 = update_high_per_ap_chn_info((int)local_10[0],(int)*(short *)(param_3 + 0xc),1);
  if (((iVar1 == 0) && (*(short *)(param_3 + 0xc) != -1)) && (local_10[0] != '\0')) {
    wsta_intelligent_roam_update_all_ap_rd_cfg(local_10);
  }
  return 0;
}

