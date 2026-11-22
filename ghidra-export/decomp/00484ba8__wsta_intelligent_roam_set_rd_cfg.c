// func _wsta_intelligent_roam_set_rd_cfg @ 00484ba8 size=88

void _wsta_intelligent_roam_set_rd_cfg(undefined4 param_1,undefined4 param_2)

{
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d _wsta_intelligent_roam_set_rd_cfg enter\n",
           "_wsta_intelligent_roam_set_rd_cfg",0xadc);
  }
  _wsta_intelligent_roam_set_rd_info(param_1,param_2);
  return;
}

