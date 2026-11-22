// func tdcp_send_to_ap @ 00510acc size=324

undefined4
tdcp_send_to_ap(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,char *param_5
               ,undefined4 param_6,undefined2 param_7,undefined4 param_8)

{
  void *__s;
  size_t sVar1;
  undefined4 uVar2;
  
  __s = (void *)FUN_00408450(0x1044,0x29e);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if (tdcp_err_switch != 0) {
      printf("[TDCP_ERROR]%s()/%d malloc error\n","tdcp_send_to_ap",0x2a0);
    }
  }
  else {
    memset(__s,0,0x1044);
    *(undefined2 *)((int)__s + 0x1038) = param_7;
    *(undefined4 *)((int)__s + 0x14) = param_3;
    *(undefined4 *)((int)__s + 0x103c) = param_8;
    *(undefined4 *)((int)__s + 0x10) = param_2;
    *(undefined4 *)((int)__s + 0xc) = param_1;
    *(undefined4 *)((int)__s + 0x1040) = param_6;
    sVar1 = strlen(param_5);
    memcpy((void *)((int)__s + 0x38),param_5,sVar1);
    sVar1 = strlen(param_4);
    memcpy((void *)((int)__s + 0x18),param_4,sVar1);
    FUN_004082d0(tdcp_to_ap_mutex,0xffffffff);
    FUN_004086b0(&g_tdcp_to_ap_list,__s);
    FUN_004084b0(tdcp_to_ap_cond);
    uVar2 = 0;
    FUN_00407f30(tdcp_to_ap_mutex);
  }
  return uVar2;
}

