// func tdcp_thread_fini @ 00511fac size=208

void tdcp_thread_fini(void)

{
  int iVar1;
  
  if (g_tdcp_send_thread_start != 0) {
    iVar1 = pthread_kill(g_tdcp_send_thread,3);
    if (iVar1 == 0) {
      g_tdcp_send_thread_start = 0;
    }
    else if (tdcp_err_switch == 0) {
      g_tdcp_send_thread_start = 0;
    }
    else {
      printf("[TDCP_ERROR]%s()/%d %d.\n\n","tdcp_thread_fini",0x3d4,iVar1);
      g_tdcp_send_thread_start = 0;
    }
  }
  if (g_tdcp_receive_thread_start != 0) {
    iVar1 = pthread_kill(g_tdcp_receive_thread,3);
    if (iVar1 == 0) {
      g_tdcp_receive_thread_start = 0;
    }
    else if (tdcp_err_switch == 0) {
      g_tdcp_receive_thread_start = 0;
    }
    else {
      printf("[TDCP_ERROR]%s()/%d %d.\n\n","tdcp_thread_fini",0x3de,iVar1);
      g_tdcp_receive_thread_start = 0;
    }
  }
  return;
}

