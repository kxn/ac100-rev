// func cw_capwap_control_ipv4_address_dump @ 0057068c size=188

undefined4 cw_capwap_control_ipv4_address_dump(int param_1)

{
  undefined4 *puVar1;
  undefined4 local_28;
  char acStack_24 [24];
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) CAPWAP Control IPv4 Address \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: CAPWAP Control IPv4 Address (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  local_28 = *puVar1;
  inet_ntop(2,&local_28,acStack_24,0x14);
  printf("\t\t\tValue: %08x%04x\r\n",*puVar1,(uint)*(ushort *)(puVar1 + 1));
  printf("\t\t\tCAPWAP Control IP Address: %s (%s) \r\n",acStack_24,acStack_24);
  printf("\t\t\tCAPWAP Control WTP Count: %d \r\n",(uint)*(ushort *)(puVar1 + 1));
  return 0;
}

