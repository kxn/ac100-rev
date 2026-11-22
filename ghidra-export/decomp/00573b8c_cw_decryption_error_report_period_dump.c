// func cw_decryption_error_report_period_dump @ 00573b8c size=180

undefined4 cw_decryption_error_report_period_dump(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Decryption Error Report Period \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Decryption Error Report Period (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%04x \r\n",(uint)*pbVar2,(uint)*(ushort *)(pbVar2 + 2));
  if (*pbVar2 < 0x20) {
    printf("\t\t\tDecryption Error Report Period Radio ID: %d \r\n");
    printf("\t\t\tDecryption Error Report Report Interval (Sec): %d \r\n",
           (uint)*(ushort *)(pbVar2 + 2));
    uVar1 = 0;
  }
  else {
    printf("\t\t\tDecryption Error Report Period Radio ID(%d) Is Wrong \r\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

