// func cw_priv_sta_ip_list_dump @ 005c6080 size=336

undefined4 cw_priv_sta_ip_list_dump(int param_1)

{
  uint *puVar1;
  uint uVar2;
  byte *pbVar3;
  undefined1 auStack_48 [44];
  
  puVar1 = *(uint **)(param_1 + 0x10);
  memset(auStack_48,0,0x28);
  printf("\t\t\tType: (t=%d,l=%d) private sta ip list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sta ip list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x...\r\n",*puVar1);
  printf("\t\t\t\tsta count: %u \r\n",*puVar1);
  puts("\t\t\t\tsta ip info: \r");
  if ((*puVar1 != 0) && (uVar2 = 0, puVar1[1] != 0)) {
    for (; uVar2 < *puVar1; uVar2 = uVar2 + 1) {
      cw_protocol_addr2str(puVar1[1] + uVar2 * 0x1c + 8,auStack_48,0x28);
      pbVar3 = (byte *)(puVar1[1] + uVar2 * 0x1c);
      printf("\t\t\t\t\tmac: %02x-%02x-%02x-%02x-%02x-%02x ip: %s\r\n",(uint)*pbVar3,(uint)pbVar3[1]
             ,(uint)pbVar3[2],(uint)pbVar3[3],(uint)pbVar3[4],(uint)pbVar3[5],auStack_48);
    }
  }
  return 0;
}

