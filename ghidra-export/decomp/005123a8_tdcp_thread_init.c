// func tdcp_thread_init @ 005123a8 size=224

undefined4 tdcp_thread_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = FUN_004084e0(&g_tdcp_send_thread,"tdcp_send",tdcpSendTask,0);
  if (iVar1 == 0) {
    g_tdcp_send_thread_start = 1;
    iVar1 = FUN_004084e0(&g_tdcp_receive_thread,"tdcp_receive",tdcpReceiveTask,0);
    if (iVar1 == 0) {
      g_tdcp_receive_thread_start = 1;
      return 0;
    }
    if (tdcp_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[TDCP_ERROR]%s()/%d Failed to create g_tdcp_receive_thread\n";
    uVar2 = 0x45a;
  }
  else {
    if (tdcp_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[TDCP_ERROR]%s()/%d Failed to create g_tdcp_send_thread\n";
    uVar2 = 0x453;
  }
  printf(__format,"tdcp_thread_init",uVar2);
  return 0xffffffff;
}

