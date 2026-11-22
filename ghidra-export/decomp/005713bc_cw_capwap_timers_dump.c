// func cw_capwap_timers_dump @ 005713bc size=152

undefined4 cw_capwap_timers_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) CAPWAP Timers \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: CAPWAP Timers (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1]);
  printf("\t\t\tCAPWAP Timers Discovery (Sec): %d \r\n",(uint)*pbVar1);
  printf("\t\t\tCAPWAP Timers Echo Request (Sec): %d \r\n",(uint)pbVar1[1]);
  return 0;
}

