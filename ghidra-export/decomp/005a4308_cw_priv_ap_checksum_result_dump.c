// func cw_priv_ap_checksum_result_dump @ 005a4308 size=156

undefined4 cw_priv_ap_checksum_result_dump(int param_1)

{
  uint uVar1;
  char *pcVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap checksum result \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap checksum result (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x \r\n",(uint)*pbVar3);
  uVar1 = (uint)*pbVar3;
  if (uVar1 == 0) {
    pcVar2 = "No change";
  }
  else {
    pcVar2 = "Changed";
  }
  printf("\t\t\t\tResult: %u(%s) \r\n ",uVar1,pcVar2);
  return 0;
}

