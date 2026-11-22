// func cloud_mngt_bssid_callback_del @ 00497d8c size=368

undefined4 cloud_mngt_bssid_callback_del(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *__s;
  undefined4 uVar3;
  
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_bssid_callback_del start\n",
           "cloud_mngt_bssid_callback_del",0xd0e);
  }
  uVar3 = 0xffffffff;
  if ((((param_1 != 0) && (uVar3 = 0, *(int *)(param_1 + 0xc) != 0)) &&
      (iVar2 = _cloud_mngt_role_match(*(undefined4 *)(param_1 + 0x14)), iVar2 != 0)) &&
     (ap_report_switch != 0)) {
    uVar3 = 0xffffffff;
    iVar2 = FUN_00408450(0x14,0xd18);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0xc) = 0x14;
      __s = (undefined4 *)FUN_00408450(0xc,0xd1e);
      if (__s == (undefined4 *)0x0) {
        FUN_00407df0(iVar2);
      }
      else {
        memset(__s,0,0xc);
        uVar3 = 0;
        memcpy(__s + 1,(void *)(param_1 + 0x48),6);
        uVar1 = cloud_mngt_msg_mutex;
        *__s = 2;
        *(undefined4 **)(iVar2 + 0x10) = __s;
        FUN_004082d0(uVar1,0xffffffff);
        FUN_004086b0(&g_cloud_mngt_msg_list,iVar2);
        FUN_004084b0(cloud_mngt_msg_cond);
        FUN_00407f30(cloud_mngt_msg_mutex);
        if (cloud_mngt_debug_switch != '\0') {
          printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_bssid_callback_del end\n",
                 "cloud_mngt_bssid_callback_del",0xd2d);
        }
      }
    }
  }
  return uVar3;
}

