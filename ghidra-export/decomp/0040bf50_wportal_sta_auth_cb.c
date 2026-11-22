// func wportal_sta_auth_cb @ 0040bf50 size=184

undefined4 wportal_sta_auth_cb(int param_1)

{
  void *__s;
  undefined4 uVar1;
  
  __s = (void *)FUN_00408450(0x18,0x30fb);
  uVar1 = 0xffffffff;
  if (__s != (void *)0x0) {
    memset(__s,0,0x18);
    memcpy((void *)((int)__s + 0xc),(void *)(param_1 + 0xc),6);
    memcpy((void *)((int)__s + 0x12),(void *)(param_1 + 0x34),6);
    FUN_004082d0(g_wportal_unauth_mutex,0xffffffff);
    FUN_004086b0(&g_wportal_unauth_msg_list,__s);
    wportal_unauth_event_count = wportal_unauth_event_count + 1;
    FUN_004084b0(g_wportal_unauth_cond);
    FUN_00407f30(g_wportal_unauth_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

