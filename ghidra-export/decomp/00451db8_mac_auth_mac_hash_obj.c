// func mac_auth_mac_hash_obj @ 00451db8 size=96

undefined4 mac_auth_mac_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d inputs error.\n","mac_auth_mac_hash_obj",0x482);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0xa0,6,0);
  return uVar1;
}

