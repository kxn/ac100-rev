// func cw_priv_cwver_dump @ 005aeadc size=140

undefined4 cw_priv_cwver_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private capwap version \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private capwap version (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x%04x \r\n",(uint)*puVar1,(uint)puVar1[1]);
  printf("\t\t\t\tprivate capwap version: %d.%d \r\n",(uint)*puVar1,(uint)puVar1[1]);
  return 0;
}

