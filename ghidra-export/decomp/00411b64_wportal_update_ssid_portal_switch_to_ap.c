// func wportal_update_ssid_portal_switch_to_ap @ 00411b64 size=632

int wportal_update_ssid_portal_switch_to_ap(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *__s;
  undefined1 uVar3;
  int iVar2;
  char *__format;
  undefined4 uVar4;
  undefined1 *puVar5;
  size_t __n;
  undefined1 auStack_28 [8];
  int local_20;
  
  iVar1 = FUN_00407fe0(param_2);
  __n = iVar1 * 3 + 0x19;
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Update portal_page_enable to ap: %d, len = %d\n",
           "wportal_update_ssid_portal_switch_to_ap",0x1c91,param_1,__n);
  }
  __s = (undefined4 *)FUN_00408450(__n,0x1c95);
  if (__s == (undefined4 *)0x0) {
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    printf("[WPORTAL_ERR]%s()/%d malloc buf failed\n","wportal_update_ssid_portal_switch_to_ap",
           0x1c98);
    return -1;
  }
  memset(__s,0,__n);
  *__s = 0x1d;
  puVar5 = (undefined1 *)((int)__s + 0x19);
  uVar3 = FUN_00407fe0(param_2);
  *(undefined1 *)(__s + 6) = uVar3;
  iVar1 = FUN_004081b0(param_2);
  if (iVar1 != 0) {
    uVar3 = *(undefined1 *)(iVar1 + 0xe);
    while( true ) {
      *puVar5 = uVar3;
      puVar5[1] = *(undefined1 *)(iVar1 + 0xc);
      puVar5[2] = *(undefined1 *)(iVar1 + 0xd);
      puVar5 = puVar5 + 3;
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      uVar3 = *(undefined1 *)(iVar1 + 0xe);
    }
  }
  serv_wtp_address_arg_init(auStack_28);
  iVar1 = apmngr_db_get_addr_by_sub_capacity(param_1,auStack_28,1,1,0xff7fffff,2,1,1);
  if (iVar1 == 0) {
    if (local_20 == 0) {
      iVar1 = 0;
      if ((wportal_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_00411c74;
      __format = "[WPORTAL_DBG]%s()/%d AP not support ssid portal switch\n";
      uVar4 = 0x1cbf;
    }
    else {
      iVar1 = _wportal_update_to_ap(__s,__n,auStack_28,0);
      if (((iVar1 != -1) || (wportal_err_switch == 0)) || (iVar2 = is_target_debug_ap(), iVar2 == 0)
         ) goto LAB_00411c74;
      __format = "[WPORTAL_ERR]%s()/%d _wportal_update_to_ap failed\n";
      uVar4 = 0x1cc7;
    }
  }
  else {
    iVar1 = -1;
    if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00411c74;
    __format = "[WPORTAL_ERR]%s()/%d error .\n";
    uVar4 = 0x1cb7;
  }
  printf(__format,"wportal_update_ssid_portal_switch_to_ap",uVar4);
LAB_00411c74:
  FUN_00407df0(__s);
  serv_wtp_address_arg_destroy(auStack_28);
  return iVar1;
}

