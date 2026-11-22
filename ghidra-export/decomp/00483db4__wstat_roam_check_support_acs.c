// func _wstat_roam_check_support_acs @ 00483db4 size=348

undefined4 _wstat_roam_check_support_acs(int param_1,int *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (wsta_roam_err_switch != '\0') {
      __format = "[WSTA_ROAM_ERROR]%s()/%d input error\n";
      uVar2 = 0x70a;
      goto LAB_00483ebc;
    }
  }
  else {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    iVar1 = serv_wtp_address_arg_init(&local_20);
    if (iVar1 != -1) {
      iVar1 = apmngr_db_get_addr_by_capacity
                        (*(undefined2 *)(param_1 + 0x10),&local_20,1,1,0x15f0000,1,0x48);
      if ((iVar1 == -1) || (local_18 == 0)) {
        if (wsta_roam_warning_switch != '\0') {
          printf("[WSTA_ROAM_WARNING]%s()/%d AP[%d] need to send configure\n",
                 "_wstat_roam_check_support_acs",0x719,(uint)*(ushort *)(param_1 + 0x10));
        }
      }
      else {
        *param_2 = *param_2 + 1;
      }
      serv_wtp_address_arg_destroy(&local_20);
      return 0;
    }
    if (wsta_roam_err_switch != '\0') {
      __format = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
      uVar2 = 0x712;
LAB_00483ebc:
      printf(__format,"_wstat_roam_check_support_acs",uVar2);
      return 1;
    }
  }
  return 1;
}

