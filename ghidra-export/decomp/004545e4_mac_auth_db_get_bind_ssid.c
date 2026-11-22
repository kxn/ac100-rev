// func mac_auth_db_get_bind_ssid @ 004545e4 size=160

undefined4 mac_auth_db_get_bind_ssid(void *param_1)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (void *)0x0) {
    uVar2 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid params.\n","mac_auth_db_get_bind_ssid",0x5d4);
    }
  }
  else {
    FUN_004082d0(DAT_00766ff8,0xffffffff);
    __src = DAT_0076701c;
    iVar1 = wserv_profile_get_max_wservice();
    memcpy(param_1,__src,iVar1 << 2);
    uVar2 = 0;
    FUN_00407f30(DAT_00766ff8);
  }
  return uVar2;
}

