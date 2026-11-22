// func cw_priv_sta_pmk_req_dump @ 005c6e7c size=576

undefined4 cw_priv_sta_pmk_req_dump(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private station pmk request \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private station pmk request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x.. \r\n",(uint)*pbVar3,(uint)pbVar3[1],(uint)pbVar3[2],
         (uint)pbVar3[3]);
  if (*pbVar3 < 3) {
    pcVar2 = (&PTR_s_inform_006f03c0)[*pbVar3];
  }
  else {
    pcVar2 = "unknown";
  }
  iVar4 = 0;
  printf("\t\t\t\trequest type: %s \r\n",pcVar2);
  printf("\t\t\t\tresult: %d \r\n",(uint)pbVar3[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)pbVar3[2]);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar3[3]);
  printf("\t\t\t\tpairwise: %d \r\n",*(undefined4 *)(pbVar3 + 4));
  printf("\t\t\t\tiface name: %s \r\n",pbVar3 + 8);
  printf("\t\t\t\tnonce: ");
  pbVar1 = pbVar3;
  do {
    iVar4 = iVar4 + 1;
    printf("%02x",(uint)pbVar1[0x19]);
    pbVar1 = pbVar3 + iVar4;
  } while (iVar4 != 0x10);
  iVar4 = 0;
  puts("\r");
  printf("\t\t\t\tstation mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar3[0x29],
         (uint)pbVar3[0x2a],(uint)pbVar3[0x2b],(uint)pbVar3[0x2c],(uint)pbVar3[0x2d],
         (uint)pbVar3[0x2e]);
  printf("\t\t\t\tap mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar3[0x2f],(uint)pbVar3[0x30],
         (uint)pbVar3[0x31],(uint)pbVar3[0x32],(uint)pbVar3[0x33],(uint)pbVar3[0x34]);
  printf("\t\t\t\tpmk_r0: ");
  pbVar1 = pbVar3;
  do {
    iVar4 = iVar4 + 1;
    printf("%02x",(uint)pbVar1[0x35]);
    pbVar1 = pbVar3 + iVar4;
  } while (iVar4 != 0x20);
  iVar4 = 0;
  puts("\r");
  printf("\t\t\t\tpmk_r0_name: ");
  pbVar1 = pbVar3;
  do {
    iVar4 = iVar4 + 1;
    printf("%02x",(uint)pbVar1[0x55]);
    pbVar1 = pbVar3 + iVar4;
  } while (iVar4 != 0x10);
  puts("\r");
  return 0;
}

