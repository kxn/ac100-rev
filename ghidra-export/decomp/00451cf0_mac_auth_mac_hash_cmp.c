// func mac_auth_mac_hash_cmp @ 00451cf0 size=108

bool mac_auth_mac_hash_cmp(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d inputs error.\n","mac_auth_mac_hash_cmp",0x4b2);
    }
  }
  else {
    iVar1 = memcmp((void *)(param_1 + 0xa0),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

