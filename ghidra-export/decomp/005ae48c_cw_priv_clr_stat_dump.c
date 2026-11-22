// func cw_priv_clr_stat_dump @ 005ae48c size=144

undefined4 cw_priv_clr_stat_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private clear state \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private capwap version (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if (*(short *)(param_1 + 0xe) != 0) {
    printf("\t\t\t\tValue: %08x \r\n",*puVar1);
    printf("\t\t\t\treserved: %d \r\n",*puVar1);
  }
  return 0;
}

