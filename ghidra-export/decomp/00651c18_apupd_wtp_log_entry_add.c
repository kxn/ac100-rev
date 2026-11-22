// func apupd_wtp_log_entry_add @ 00651c18 size=212

undefined4 apupd_wtp_log_entry_add(int param_1,undefined1 param_2)

{
  void *__s;
  int iVar1;
  undefined4 uVar2;
  
  __s = (void *)FUN_00408450(0x44,0x72c);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: malloc log failed.\r\n","apupd_wtp_log_entry_add",0x72e);
    }
  }
  else {
    memset(__s,0,0x44);
    memcpy((void *)((int)__s + 0x38),(void *)(param_1 + 0x2e),6);
    apupd_local_time_get((int)__s + 0xc);
    *(undefined1 *)((int)__s + 0x3e) = param_2;
    *(undefined4 *)((int)__s + 0x40) = *(undefined4 *)(param_1 + 0x50);
    uVar2 = 0;
    FUN_004086b0(*(int *)(param_1 + 0x50) + 0x17c,__s);
  }
  return uVar2;
}

