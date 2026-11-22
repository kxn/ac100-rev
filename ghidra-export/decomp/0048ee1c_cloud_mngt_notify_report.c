// func cloud_mngt_notify_report @ 0048ee1c size=148

void cloud_mngt_notify_report(undefined4 param_1)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x14,0x1b14);
  if (__s != (void *)0x0) {
    memset(__s,0,0x14);
    *(undefined4 *)((int)__s + 0xc) = param_1;
    FUN_004082d0(cloud_mngt_msg_report_mutex,0xffffffff);
    FUN_004086b0(&g_cloud_mngt_msg_report_list,__s);
    FUN_004084b0(cloud_mngt_msg_report_cond);
    FUN_00407f30(cloud_mngt_msg_report_mutex);
    return;
  }
  return;
}

