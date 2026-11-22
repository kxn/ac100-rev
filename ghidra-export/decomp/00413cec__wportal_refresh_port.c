// func _wportal_refresh_port @ 00413cec size=192

undefined4 _wportal_refresh_port(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  undefined1 auStack_20 [16];
  
  uVar1 = g_portal_port;
  __s = (undefined4 *)FUN_00408450(0x18,0x1929);
  uVar2 = 0xffffffff;
  if (__s != (undefined4 *)0x0) {
    memset(__s,0,0x18);
    __s[1] = uVar1;
    *__s = 8;
    serv_wtp_address_arg_init(auStack_20);
    apmngr_db_get_addr_by_capacity(param_1,auStack_20,1,1,0x15f0000,0);
    uVar2 = _wportal_update_to_ap(__s,0x18,auStack_20,1);
    FUN_00407df0(__s);
    serv_wtp_address_arg_destroy(auStack_20);
  }
  return uVar2;
}

