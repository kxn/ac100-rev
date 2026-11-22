// func cw_wtp_static_ip_address_information_dump @ 00586c7c size=284

undefined4 cw_wtp_static_ip_address_information_dump(int param_1)

{
  undefined4 *puVar1;
  undefined4 local_28;
  char acStack_24 [24];
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Static IP Address Information \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Static IP Address Information (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc))
  ;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x%08x%08x%02x\r\n",*puVar1,puVar1[1],puVar1[2],(uint)*(byte *)(puVar1 + 3)
        );
  local_28 = *puVar1;
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\tIP Address: %s  \r\n",acStack_24);
  local_28 = puVar1[1];
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\tNetmask: %s \r\n",acStack_24);
  local_28 = puVar1[2];
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\tGateway: %s \r\n",acStack_24);
  printf("\t\t\tStatic: %d \r\n",(uint)*(byte *)(puVar1 + 3));
  return 0;
}

