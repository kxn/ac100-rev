// func cw_ac_thread_stat_dump @ 0058cd10 size=328

void cw_ac_thread_stat_dump(uint param_1)

{
  char *__s;
  int iVar1;
  
  if (param_1 < *(uint *)(ac + 0x18)) {
    printf("\n----------------thread %d\'s ap information-------------------\n",param_1);
    iVar1 = param_1 * 0xa0;
    printf("session_enter_join:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x5c));
    printf("session_enter_run:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x60));
    printf("wait_dtls_timeout_num:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 100));
    printf("wait_join_timeout_num:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x68));
    printf("change_state_timeout_num:\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x6c));
    printf("data_check_timeout_num:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x70));
    printf("echo_timeout_num:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x74));
    printf("retransmit_timeout_num:\t\t%d\n",*(undefined4 *)(*(int *)(ac + 0x1c) + iVar1 + 0x78));
    __s = "---------------------------end-------------------------------";
  }
  else {
    __s = "ac thread\'s index is wrong";
  }
  puts(__s);
  return;
}

