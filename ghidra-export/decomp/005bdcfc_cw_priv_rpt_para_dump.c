// func cw_priv_rpt_para_dump @ 005bdcfc size=360

undefined4 cw_priv_rpt_para_dump(int param_1)

{
  char cVar1;
  char *pcVar2;
  ushort *puVar3;
  undefined4 local_28;
  char acStack_24 [24];
  
  puVar3 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private rpt para \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private rpt para (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x%04x... \r\n",(uint)*puVar3,(uint)puVar3[1]);
  if (*puVar3 == 1) {
    pcVar2 = "stat log";
  }
  else {
    pcVar2 = "sys log";
  }
  printf("\t\t\t\tobj type: %d(%s) \r\n ",(uint)*puVar3,pcVar2);
  printf("\t\t\t\tpara len: %d \r\n ",(uint)puVar3[1]);
  printf("\t\t\t\tdebug log para:\r\n ");
  printf("\t\t\t\t\tobj op: %d",(uint)*(byte *)(puVar3 + 2));
  cVar1 = *(char *)(puVar3 + 2);
  if (cVar1 == '\x02') {
    pcVar2 = "(stop)";
  }
  else if (cVar1 == '\x03') {
    pcVar2 = "(clear)";
  }
  else if (cVar1 == '\x01') {
    pcVar2 = "(start)";
  }
  else {
    pcVar2 = "(unknown op)";
  }
  printf(pcVar2);
  puts("\r");
  printf("\t\t\t\t\tlog period: %d \r\n ",*(undefined4 *)(puVar3 + 4));
  local_28 = *(undefined4 *)(puVar3 + 6);
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\t\t\tlog ip: %s \r\n ",acStack_24);
  return 0;
}

