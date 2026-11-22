// func wportal_update_user_to_ap_by_id @ 0041b6ec size=324

undefined4 wportal_update_user_to_ap_by_id(uint param_1,void *param_2,undefined4 param_3)

{
  undefined4 *__s;
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_28 [16];
  
  if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Update user entry to ap: %d, len = %d\n",
           "wportal_update_user_to_ap_by_id",0x34db,param_1,0x44);
  }
  __s = (undefined4 *)FUN_00408450(0x44,0x34de);
  uVar1 = 0xffffffff;
  if (__s != (undefined4 *)0x0) {
    memset(__s,0,0x44);
    __s[2] = 1;
    *__s = param_3;
    __s[9] = *(undefined4 *)((int)param_2 + 8);
    memcpy(__s + 7,param_2,6);
    iVar2 = __s[9];
    __s[6] = 1;
    if (iVar2 == 0) {
      iVar2 = 0xfff;
    }
    __s[9] = iVar2;
    serv_wtp_address_arg_init(auStack_28);
    apmngr_db_get_addr_by_capacity(param_1 & 0xffff,auStack_28,1,1,0x15f0000,0);
    uVar1 = _wportal_update_to_ap(__s,0x44,auStack_28,0);
    FUN_00407df0(__s);
    serv_wtp_address_arg_destroy(auStack_28);
  }
  return uVar1;
}

