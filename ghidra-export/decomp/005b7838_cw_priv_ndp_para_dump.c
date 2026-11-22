// func cw_priv_ndp_para_dump @ 005b7838 size=568

undefined4 cw_priv_ndp_para_dump(int param_1)

{
  undefined *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 auStack_60 [6];
  undefined4 auStack_48 [14];
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  memcpy(auStack_48,&PTR_s_802_11a_006ecc70,0x38);
  memcpy(auStack_60,&PTR_DAT_006ecca8,0x18);
  printf("\t\t\tType: (t=%d,l=%d) private ndp para \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ndp para (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x%02x%02x...\r\n",(uint)*pbVar2,(uint)pbVar2[1],
         (uint)pbVar2[2],(uint)pbVar2[3],(uint)pbVar2[4],(uint)pbVar2[5]);
  printf("\t\t\t\tgroup id: %02x%02x%02x%02x%02x%02x \r\n",(uint)*pbVar2,(uint)pbVar2[1],
         (uint)pbVar2[2],(uint)pbVar2[3],(uint)pbVar2[4],(uint)pbVar2[5]);
  printf("\t\t\t\tradio id: %u \r\n",(uint)pbVar2[6]);
  if (pbVar2[0x10] < 0xe) {
    puVar1 = (undefined *)auStack_48[(char)pbVar2[0x10]];
  }
  else {
    puVar1 = &DAT_0068d44c;
  }
  printf("\t\t\t\tradio mode: %s \r\n",puVar1);
  if (pbVar2[0x11] < 6) {
    puVar1 = (undefined *)auStack_60[(char)pbVar2[0x11]];
  }
  else {
    puVar1 = &DAT_0068d44c;
  }
  printf("\t\t\t\tbindwidth mode: %s \r\n",puVar1);
  printf("\t\t\t\tpower: %d \r\n",(int)(char)pbVar2[0x12]);
  printf("\t\t\t\trssi threshold: %d \r\n",(int)(char)pbVar2[7]);
  printf("\t\t\t\tperiod: %u \r\n",(uint)*(ushort *)(pbVar2 + 8));
  printf("\t\t\t\tduration: %u \r\n",(uint)*(ushort *)(pbVar2 + 10));
  printf("\t\t\t\tmax neighbor count: %u \r\n",(uint)*(ushort *)(pbVar2 + 0xc));
  printf("\t\t\t\texpired time: %u \r\n",(uint)*(ushort *)(pbVar2 + 0xe));
  printf("\t\t\t\tchannel count: %u \r\n",(uint)pbVar2[0x13]);
  if (pbVar2[0x13] != 0) {
    printf("\t\t\t\tchannel list: ");
    for (iVar3 = 0; iVar3 < (int)(uint)pbVar2[0x13]; iVar3 = iVar3 + 1) {
      printf("%u ",(uint)pbVar2[iVar3 + 0x14]);
    }
    puts("\r");
  }
  return 0;
}

