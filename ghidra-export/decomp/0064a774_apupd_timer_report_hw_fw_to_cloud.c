// func apupd_timer_report_hw_fw_to_cloud @ 0064a774 size=148

void apupd_timer_report_hw_fw_to_cloud(undefined4 param_1)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x14,0xd49);
  if (__s != (void *)0x0) {
    memset(__s,0,0x14);
    *(undefined4 *)((int)__s + 0x10) = param_1;
    FUN_004082d0(apupd_msg_mutex,0xffffffff);
    FUN_004086b0(&g_apupd_timer_list,__s);
    FUN_004084b0(apupd_msg_cond);
    FUN_00407f30(apupd_msg_mutex);
    return;
  }
  return;
}

