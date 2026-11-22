// func _wstat_roam_check_exist_unsupport_ap @ 0047f284 size=424

undefined4 _wstat_roam_check_exist_unsupport_ap(int param_1,int *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d input error\n";
    uVar2 = 0x10b;
  }
  else {
    if (*param_2 == 1) {
      return 0;
    }
    if ((((*(int *)(param_1 + 0x1c) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
        (1 < *(int *)(param_1 + 0x2ac) - 2U)) ||
       (iVar1 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10)), iVar1 == 0)) {
      if (wsta_roam_debug_switch == '\0') {
        return 0;
      }
      printf("[WSTA_ROAM_DEBUG]%s()/%d not need check ap_id:%d.\n",
             "_wstat_roam_check_exist_unsupport_ap",0x11d,(uint)*(ushort *)(param_1 + 0x10));
      return 0;
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    iVar1 = serv_wtp_address_arg_init(&local_28);
    if (iVar1 != -1) {
      iVar1 = apmngr_db_get_addr_by_capacity
                        (*(undefined2 *)(param_1 + 0x10),&local_28,1,1,0x15f0000,1,0x48);
      if ((iVar1 == -1) || (local_20 == 0)) {
        *param_2 = 1;
      }
      serv_wtp_address_arg_destroy(&local_28);
      return 0;
    }
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
    uVar2 = 0x124;
  }
  printf(__format,"_wstat_roam_check_exist_unsupport_ap",uVar2);
  return 1;
}

