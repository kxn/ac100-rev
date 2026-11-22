// func local_wsta_intelligent_roam_set_params_cb @ 00489ae4 size=104

undefined4 local_wsta_intelligent_roam_set_params_cb(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = FUN_004897a4(*(undefined2 *)(param_1 + 0x10)), iVar1 == 0)) {
    return 0;
  }
  if (wsta_roam_err_switch != '\0') {
    printf("[WSTA_ROAM_ERROR]%s()/%d local_wsta_intelligent_roam_set_params_cb fail\n",
           "local_wsta_intelligent_roam_set_params_cb",0xb96);
  }
  return 1;
}

