// func cw_wtp_fallback_dump @ 00585088 size=192

undefined4 cw_wtp_fallback_dump(int param_1)

{
  byte bVar1;
  char *__format;
  undefined4 uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Fallback  \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Fallback  (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x \r\n",(uint)*pbVar3);
  bVar1 = *pbVar3;
  if (bVar1 == 1) {
    uVar2 = 1;
    __format = "\t\t\tWTP Fallback: Enabled (%d) \r\n";
  }
  else {
    if (bVar1 != 2) {
      printf("\t\t\t***WTP Fallback(%d) is wrong \r\n");
      return 0xffffffff;
    }
    uVar2 = 2;
    __format = "\t\t\tWTP Fallback: Disabled (%d) \r\n";
  }
  printf(__format,uVar2);
  return 0;
}

