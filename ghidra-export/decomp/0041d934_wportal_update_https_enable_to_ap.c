// func wportal_update_https_enable_to_ap @ 0041d934 size=664

int wportal_update_https_enable_to_ap(undefined4 param_1,char param_2,int param_3)

{
  undefined4 *__s;
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 auStack_28 [8];
  int local_20;
  
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Update https_enable to ap: %d, len = %d\n",
           "wportal_update_https_enable_to_ap",0x3525,param_1,0x19);
  }
  __s = (undefined4 *)FUN_00408450(0x19,0x3528);
  if (__s == (undefined4 *)0x0) {
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    printf("[WPORTAL_ERR]%s()/%d malloc buf failed\n","wportal_update_https_enable_to_ap",0x352b);
    return -1;
  }
  memset(__s,0,0x19);
  *__s = 0x18;
  if (param_2 == '\0') {
    *(undefined1 *)(__s + 6) = 0;
  }
  else {
    *(undefined1 *)(__s + 6) = 1;
  }
  serv_wtp_address_arg_init(auStack_28);
  if (param_3 == 0) {
    iVar1 = apmngr_db_get_addr_by_sub_capacity(param_1,auStack_28,1,1,0xff7fffff,2,1,0);
    if (iVar1 == 0) goto LAB_0041da74;
    iVar1 = -1;
    if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0041da00;
    __format = "[WPORTAL_ERR]%s()/%d error .\n";
    uVar3 = 0x354d;
  }
  else {
    iVar1 = apmngr_db_get_all_addr_by_sub_capacity(auStack_28,1,1,0xff7fffff,2,1,0);
    if (iVar1 == 0) {
LAB_0041da74:
      if (local_20 == 0) {
        iVar1 = 0;
        if ((wportal_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0041da00;
        __format = "[WPORTAL_DBG]%s()/%d AP not support https switch\n";
        uVar3 = 0x3555;
      }
      else {
        iVar1 = _wportal_update_to_ap(__s,0x19,auStack_28,0);
        if (((iVar1 != -1) || (wportal_err_switch == 0)) ||
           (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0041da00;
        __format = "[WPORTAL_ERR]%s()/%d _wportal_update_to_ap failed\n";
        uVar3 = 0x355d;
      }
    }
    else {
      iVar1 = -1;
      if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_0041da00;
      __format = "[WPORTAL_ERR]%s()/%d error .\n";
      uVar3 = 0x3544;
    }
  }
  printf(__format,"wportal_update_https_enable_to_ap",uVar3);
LAB_0041da00:
  FUN_00407df0(__s);
  serv_wtp_address_arg_destroy(auStack_28);
  return iVar1;
}

