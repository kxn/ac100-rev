// func _wstat_roam_check_exist_support_ap @ 00486548 size=284

undefined4 _wstat_roam_check_exist_support_ap(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar2 = 1;
    if (wsta_roam_err_switch != '\0') {
      printf("[WSTA_ROAM_ERROR]%s()/%d input error\n","_wstat_roam_check_exist_support_ap",0xfd);
    }
  }
  else {
    uVar2 = 2;
    if (*param_2 != 1) {
      if ((((*(int *)(param_1 + 0x1c) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
          (1 < *(int *)(param_1 + 0x2ac) - 2U)) ||
         (iVar1 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10)), iVar1 == 0)) {
        uVar2 = 0;
        if (wsta_roam_debug_switch != '\0') {
          printf("[WSTA_ROAM_DEBUG]%s()/%d not need check ap_id:%d.\n",
                 "_wstat_roam_check_exist_support_ap",0x10f,(uint)*(ushort *)(param_1 + 0x10));
        }
      }
      else {
        uVar2 = 0;
        iVar1 = apmngr_db_capacity_support(*(undefined2 *)(param_1 + 0x10),1,0x48);
        if (iVar1 != 0) {
          *param_2 = 1;
        }
      }
    }
  }
  return uVar2;
}

