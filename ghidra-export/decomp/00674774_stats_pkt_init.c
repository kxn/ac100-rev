// func stats_pkt_init @ 00674774 size=252

int stats_pkt_init(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char *local_20;
  undefined4 local_1c;
  code *local_18;
  undefined4 local_14;
  
  iVar1 = serv_msg_mngr_register(9,0x50,_stats_pkt_wtp_event_listener);
  if (iVar1 == 0) {
    local_14 = 0;
    local_20 = "stats_pkt";
    local_1c = 0xa000000;
    local_18 = _stats_ctl_pkt_send_cb;
    iVar2 = multi_link_reg(&local_20);
    if (iVar2 != -1) {
      return 0;
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d register callback to multi link failed.\n",
             "_stats_pkt_multilink_callback_init",0x221);
    }
    if (stats_err_switch == '\0') {
      return 0;
    }
    __format = "[STATISTICS_ERROR]%s()/%d register multilink for STATS_pkt module fail.\n";
    uVar3 = 0x25b;
  }
  else {
    if (stats_err_switch == '\0') {
      return iVar1;
    }
    __format = "[STATISTICS_ERROR]%s()/%d register wtp event req for STATS_pkt module fail.\n";
    uVar3 = 0x255;
  }
  printf(__format,"stats_pkt_init",uVar3);
  return iVar1;
}

