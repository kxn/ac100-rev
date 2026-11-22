// func cw_priv_ap_mlo_switch_dump @ 005a6728 size=132

undefined4 cw_priv_ap_mlo_switch_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap mlo switch \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap mlo switch (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tvalue: %08x \r\n",(uint)*pbVar1);
  printf("\t\t\t\tswitch: %d \r\n",(uint)*pbVar1);
  return 0;
}

