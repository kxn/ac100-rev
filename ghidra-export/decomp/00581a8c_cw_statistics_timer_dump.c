// func cw_statistics_timer_dump @ 00581a8c size=132

undefined4 cw_statistics_timer_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Statistics Timer \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Statistics Timer (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %04x \r\n",(uint)*puVar1);
  printf("\t\t\tStatistics Timer (Sec): %d \r\n",(uint)*puVar1);
  return 0;
}

