// func cw_priv_ap_log_report_para_dump @ 005a624c size=316

undefined4 cw_priv_ap_log_report_para_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  undefined1 auStack_38 [44];
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap log report para \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap log report para (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x%02x...\r\n",(uint)*pbVar2,(uint)pbVar2[1],(uint)pbVar2[2],
         (uint)pbVar2[3],(uint)pbVar2[4]);
  if (*pbVar2 == 0) {
    pcVar1 = "close";
  }
  else {
    pcVar1 = "open";
  }
  printf("\t\t\t\tac log switch: %s \r\n",pcVar1);
  printf("\t\t\t\tac log level:  %d \r\n",(uint)pbVar2[1]);
  if (pbVar2[2] == 0) {
    pcVar1 = "close";
  }
  else {
    pcVar1 = "open";
  }
  printf("\t\t\t\tremote server switch:  %s \r\n",pcVar1);
  printf("\t\t\t\tremote log level:  %d \r\n",(uint)pbVar2[3]);
  printf("\t\t\t\tremote report interval:  %d \r\n",*(undefined4 *)(pbVar2 + 0x18));
  memset(auStack_38,0,0x28);
  cw_protocol_addr2str(pbVar2 + 4,auStack_38,0x28);
  printf("\t\t\t\tremote server addr:  %s \r\n",auStack_38);
  return 0;
}

