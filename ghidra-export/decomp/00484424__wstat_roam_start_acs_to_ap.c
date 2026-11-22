// func _wstat_roam_start_acs_to_ap @ 00484424 size=392

undefined4 _wstat_roam_start_acs_to_ap(int param_1)

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
  if (param_1 == 0) {
    if (wsta_roam_err_switch != '\0') {
      __format = "[WSTA_ROAM_ERROR]%s()/%d input error\n";
      uVar2 = 0x6e4;
      goto LAB_00484520;
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
        uVar2 = 0;
        if (wsta_roam_warning_switch != '\0') {
          printf("[WSTA_ROAM_WARNING]%s()/%d AP[%d] need to send configure\n",
                 "_wstat_roam_start_acs_to_ap",0x6f2,(uint)*(ushort *)(param_1 + 0x10));
        }
      }
      else {
        iVar1 = _wsta_intelligent_roam_start_acs_send(&local_20,param_1);
        uVar2 = 0;
        if ((iVar1 == -1) && (uVar2 = 1, wsta_roam_err_switch != '\0')) {
          printf("[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n","_wstat_roam_start_acs_to_ap"
                 ,0x6f9);
        }
      }
      serv_wtp_address_arg_destroy(&local_20);
      return uVar2;
    }
    if (wsta_roam_err_switch != '\0') {
      __format = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
      uVar2 = 0x6eb;
LAB_00484520:
      printf(__format,"_wstat_roam_start_acs_to_ap",uVar2);
      return 1;
    }
  }
  return 1;
}

