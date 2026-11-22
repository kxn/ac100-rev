// func mac_auth_init @ 00451bf8 size=248

int mac_auth_init(void)

{
  int iVar1;
  char local_38 [32];
  undefined4 local_18;
  code *local_14;
  
  memset(local_38,0,0x2c);
  builtin_strncpy(local_38,"mac_auth",8);
  local_18 = 0x14;
  local_14 = mac_auth_wsta_callback_sta_check;
  iVar1 = wsta_assoc_check_reg(local_38);
  if (iVar1 == 0) {
    udbg_help_register("mac_auth","mac_auth_debug_help()");
    iVar1 = macauth_debug_switch;
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d mac_auth_init OK.\n","mac_auth_init",0xed);
      iVar1 = 0;
    }
  }
  else {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d register check callback to wstation  block failed \n",
             "mac_auth_wstation_callback_mac_auth_init",0xd1);
    }
    if (macauth_err_switch == 0) {
      iVar1 = -1;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d mac_auth_wstation_callback_mac_auth_init() failed.\n",
             "mac_auth_init",0xe9);
      iVar1 = -1;
    }
  }
  return iVar1;
}

