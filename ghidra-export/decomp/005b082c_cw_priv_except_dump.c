// func cw_priv_except_dump @ 005b082c size=316

undefined4 cw_priv_except_dump(int param_1)

{
  undefined4 *puVar1;
  undefined4 local_28;
  char acStack_24 [24];
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private except \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private except (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x... \r\n",*puVar1);
  printf("\t\t\t\tresult: %d \r\n",*puVar1);
  local_28 = puVar1[1];
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\t\tac ip: %s \r\n",acStack_24);
  printf("\t\t\t\tac mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(puVar1 + 2),
         (uint)*(byte *)((int)puVar1 + 9),(uint)*(byte *)((int)puVar1 + 10),
         (uint)*(byte *)((int)puVar1 + 0xb),(uint)*(byte *)(puVar1 + 3),
         (uint)*(byte *)((int)puVar1 + 0xd));
  local_28 = puVar1[4];
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\t\tap ip: %s \r\n",acStack_24);
  printf("\t\t\t\tap mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(puVar1 + 5),
         (uint)*(byte *)((int)puVar1 + 0x15),(uint)*(byte *)((int)puVar1 + 0x16),
         (uint)*(byte *)((int)puVar1 + 0x17),(uint)*(byte *)(puVar1 + 6),
         (uint)*(byte *)((int)puVar1 + 0x19));
  return 0;
}

