// func _wportal_get_roam_sta_cb @ 0040fd1c size=312

undefined4 _wportal_get_roam_sta_cb(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d ori_ap_id :%d\n","_wportal_get_roam_sta_cb",0x66b,param_1);
  }
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((param_1 < iVar1 + iVar2) ||
        ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) &&
       (param_2 != (int *)0x0)) {
      *param_2 = param_1;
      uVar3 = wsta_profile_get_max_wstation();
      uVar3 = wsta_db_sta_for_each_range(0,uVar3,_wportal_sync_roam_sta_cb,param_2);
      return uVar3;
    }
  }
  if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_ERR]%s()/%d Invalid ap id[%d] or priv is null\n","_wportal_get_roam_sta_cb",
           0x66e,param_1);
  }
  return 0xffffffff;
}

