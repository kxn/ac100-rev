// func cw_wtp_radio_statistics_dump @ 005860ec size=480

undefined4 cw_wtp_radio_statistics_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Radio Statistics \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Radio Statistics (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%04x%04x%04x%04x%04x%04x%04x%04x%04x \r\n",(uint)*pbVar2,
         (uint)pbVar2[1],(uint)*(ushort *)(pbVar2 + 2),(uint)*(ushort *)(pbVar2 + 4),
         (uint)*(ushort *)(pbVar2 + 6),(uint)*(ushort *)(pbVar2 + 8),(uint)*(ushort *)(pbVar2 + 10),
         (uint)*(ushort *)(pbVar2 + 0xc),(uint)*(ushort *)(pbVar2 + 0xe),
         (uint)*(ushort *)(pbVar2 + 0x10),(uint)*(ushort *)(pbVar2 + 0x12));
  uVar1 = (uint)*pbVar2;
  if (uVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    uVar1 = (uint)pbVar2[1];
    if (0xfa < (uVar1 - 4 & 0xff)) {
      if (uVar1 < 4) {
        printf("\t\t\tLast Failure Type: %s (%d) \r\n",(&PTR_s_Not_Supported_006dd880)[uVar1]);
      }
      else {
        printf("\t\t\tLast Failure Type: Unknown (%d) \r\n",0xff);
      }
      printf("\t\t\tReset Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 2));
      printf("\t\t\tSW Failure Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 4));
      printf("\t\t\tHW Failure Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 6));
      printf("\t\t\tOther Failure Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 8));
      printf("\t\t\tUnknown Failure Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 10));
      printf("\t\t\tConfig Update Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 0xc));
      printf("\t\t\tChannel Change Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 0xe));
      printf("\t\t\tBand Change Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 0x10));
      printf("\t\t\tCurrent Noise Count: %d \r\n",(uint)*(ushort *)(pbVar2 + 0x12));
      return 0;
    }
    __format = "\t\t\t***Last Failure Type(%d) is wrong \r\n";
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format,uVar1);
  return 0xffffffff;
}

