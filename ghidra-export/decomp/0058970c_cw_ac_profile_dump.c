// func cw_ac_profile_dump @ 0058970c size=1

void cw_ac_profile_dump(void)

{
  if (l_profile != (undefined4 *)0x0) {
    puts("capwap profile:");
    printf("\t frag_enable: %d\n",*l_profile);
    printf("\t frag_mtu: %d\n",l_profile[1]);
    printf("\t session_num: %d\n",l_profile[2]);
    printf("\t pkt_queue_size: %d\n",l_profile[3]);
    printf("\t mngr_queue_size: %d\n",l_profile[4]);
    printf("\t timer_size: %d\n",l_profile[5]);
    printf("\t timer_max_time: %d\n",l_profile[6]);
    printf("\t timer_process_num: %d\n",l_profile[7]);
    printf("\t mngr_process_num: %d\n",l_profile[8]);
    printf("\t pkt_process_num: %d\n",l_profile[9]);
    printf("\t thread_size: %d\n",l_profile[10]);
    printf("\t cacert_file_path: %s\n",l_profile + 0xb);
    printf("\t privkey_file_path: %s\n",l_profile + 0x2b);
    printf("\t socket receive buffer size: %d\n",l_profile[0x4b]);
    printf("\t socket send buffer size: %d\n",l_profile[0x4c]);
    printf("\t default retransmit time: %d\n",l_profile[0x4e]);
    printf("\t retransmit max retries: %d\n",l_profile[0x4f]);
    printf("\t max session num: %d\n",l_profile[0x50]);
    printf("\t max pkt_snapshot mem size: %d\n",l_profile[0x51]);
    return;
  }
  return;
}

