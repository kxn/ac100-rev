// func uac_mac_auth_uninit @ 00451324 size=92

undefined4 uac_mac_auth_uninit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = mac_auth_db_uninit();
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, macauth_err_switch != 0)) {
    printf("[MACAUTH_ERROR]%s()/%d mac_auth_db_uninit() error.\n","uac_mac_auth_uninit",0x59d);
  }
  return uVar2;
}

