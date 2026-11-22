// func _wportal_wserv_update_portal_page_switch @ 00411ddc size=280

undefined4 _wportal_wserv_update_portal_page_switch(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar2 = 0xffffffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if (param_3 != 0) {
    uVar2 = rdmngr_db_generate_ap_id(*param_1);
    FUN_0051ad88(&local_28);
    iVar1 = _wportal_db_support_new_portal_by_id(uVar2);
    if ((iVar1 != 0) && (g_portal_auth_mode == 0)) {
      __s = (void *)FUN_00408450(0x10,0x1cee);
      if (__s == (void *)0x0) {
        return 0xffffffff;
      }
      memset(__s,0,0x10);
      *(byte *)((int)__s + 0xc) = (byte)*param_1 & 0xf;
      *(undefined1 *)((int)__s + 0xd) = *(undefined1 *)(param_1 + 1);
      *(undefined1 *)((int)__s + 0xe) = *(undefined1 *)(param_2 + 0x127);
      FUN_004086b0(&local_28,__s);
      wportal_update_ssid_portal_switch_to_ap(uVar2,&local_28,0);
    }
    while (iVar1 = FUN_004081b0(&local_28), iVar1 != 0) {
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

