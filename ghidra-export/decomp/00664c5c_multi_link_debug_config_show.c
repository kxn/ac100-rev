// func multi_link_debug_config_show @ 00664c5c size=164

void multi_link_debug_config_show(void)

{
  char *pcVar1;
  
  puts("======AC Multi-Link Config======");
  printf("AC name : %s \n",&g_multi_link_ac_name);
  if (g_multi_link_enable == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  printf("Global Switch : %s \n",pcVar1 + 4);
  printf("Priority      : %u \n",(uint)g_multi_link_priority);
  printf("Peer Addr(4)  : %s \n",&g_multi_link_peer_addr);
  printf("Peer Addr(6)  : %s \n",&g_multi_link_peer_addr_ipv6);
  puts("================================");
  return;
}

