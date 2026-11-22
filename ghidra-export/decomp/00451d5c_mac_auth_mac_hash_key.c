// func mac_auth_mac_hash_key @ 00451d5c size=92

undefined4 mac_auth_mac_hash_key(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d inputs error.\n","mac_auth_mac_hash_key",0x49a);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,6,0);
  return uVar1;
}

