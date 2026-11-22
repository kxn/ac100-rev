// func uac_report_global_config_dump @ 004b6788 size=1

void uac_report_global_config_dump(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  printf("protocol:%d\n",(uint)server_session);
  printf("server_address:%s\n",&DAT_00767d71);
  printf("server_port:%d\n",DAT_00767e6c);
  printf("fd:%d\n",DAT_00767e70);
  printf("sock_type:%d\n",DAT_00767ea0);
  if (DAT_00767ea0 == 1) {
    printf("addr:%x\n",DAT_00767e78);
  }
  else if (DAT_00767ea0 == 2) {
    pbVar1 = &server_session;
    iVar3 = 0;
    do {
      iVar2 = iVar3 + 1;
      printf("addr:%02x\n",(uint)pbVar1[0x11c]);
      pbVar1 = &DAT_00767d71 + iVar3;
      iVar3 = iVar2;
    } while (iVar2 != 0x10);
  }
  printf("fail_time:%d\n",uRam00767ea4);
  return;
}

