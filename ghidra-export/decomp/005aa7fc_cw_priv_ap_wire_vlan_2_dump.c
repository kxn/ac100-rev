// func cw_priv_ap_wire_vlan_2_dump @ 005aa7fc size=164

undefined4 cw_priv_ap_wire_vlan_2_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap wire vlan 2 \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap wire vlan (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x%04x%04x%04x\r\n",(uint)*puVar1,(uint)puVar1[1],(uint)puVar1[2],
         (uint)puVar1[3]);
  printf("\t\t\t\tap wire vlan: %u,%u,%u,%u\r\n",(uint)*puVar1,(uint)puVar1[1],(uint)puVar1[2],
         (uint)puVar1[3]);
  return 0;
}

