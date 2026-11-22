// func cw_priv_roaming_control_dump @ 005bc95c size=516

undefined4 cw_priv_roaming_control_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  char *local_20 [5];
  
  local_20[0] = "distributed";
  local_20[1] = "centralized";
  pbVar2 = *(byte **)(param_1 + 0x10);
  local_20[2] = "distributed and centralized";
  printf("\t\t\tType: (t=%d,l=%d) private roaming control request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private roaming control request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\t_11k_switch: %u \r\n",(uint)*pbVar2);
  printf("\t\t\t\t_11v_switch: %u \r\n",(uint)pbVar2[1]);
  printf("\t\t\t\t_11r_switch: %u \r\n",(uint)pbVar2[2]);
  printf("\t\t\t\t_2g_trigger_type: %u \r\n",(uint)pbVar2[3]);
  printf("\t\t\t\t_2g_rssi_trigger_threshold: %d \r\n",(int)(char)pbVar2[4]);
  printf("\t\t\t\t_2g_rssi_kick_switch: %u \r\n",(uint)pbVar2[5]);
  printf("\t\t\t\t_2g_rssi_kick_threshold: %d \r\n",(int)(char)pbVar2[6]);
  printf("\t\t\t\t_2g_rate_trigger_threshold: %u \r\n",(uint)pbVar2[7]);
  printf("\t\t\t\t_2g_rate_kick_switch: %u \r\n",(uint)pbVar2[8]);
  printf("\t\t\t\t_2g_rate_kick_threshold: %u \r\n",(uint)pbVar2[9]);
  printf("\t\t\t\t_5g_trigger_type: %u \r\n",(uint)pbVar2[10]);
  printf("\t\t\t\t_5g_rssi_trigger_threshold: %d \r\n",(int)(char)pbVar2[0xb]);
  printf("\t\t\t\t_5g_rssi_kick_switch: %u \r\n",(uint)pbVar2[0xc]);
  printf("\t\t\t\t_5g_rssi_kick_threshold: %d \r\n",(int)(char)pbVar2[0xd]);
  printf("\t\t\t\t_5g_rate_trigger_threshold: %u \r\n",(uint)pbVar2[0xe]);
  printf("\t\t\t\t_5g_rate_kick_switch: %u \r\n",(uint)pbVar2[0xf]);
  printf("\t\t\t\t_5g_rate_kick_threshold: %u \r\n",(uint)pbVar2[0x10]);
  printf("\t\t\t\tthreshold_check_interval: %u \r\n",(uint)pbVar2[0x11]);
  printf("\t\t\t\troaming dif: %u \r\n",(uint)pbVar2[0x12]);
  printf("\t\t\t\tblacklist restrict time: %u \r\n",(uint)pbVar2[0x13]);
  if (pbVar2[0x14] < 4) {
    pcVar1 = local_20[pbVar2[0x14]];
  }
  else {
    pcVar1 = "unknown";
  }
  printf("\t\t\t\troamint strategy: %s \r\n",pcVar1);
  puts("\r");
  return 0;
}

