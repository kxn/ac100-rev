// func cw_wtp_descriptor_dump @ 00584038 size=712

undefined4 cw_wtp_descriptor_dump(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar7 = 0;
  pbVar6 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Descriptor \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Descriptor (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x...\r\n",(uint)*pbVar6,(uint)pbVar6[1]);
  printf("\t\t\tMax Radios: %d \r\n",(uint)*pbVar6);
  printf("\t\t\tRadio in use: %d \r\n",(uint)pbVar6[1]);
  printf("\t\t\tEncryption Capabilities (Number): %d \r\n",*(undefined4 *)(pbVar6 + 0xc));
  iVar3 = FUN_004081b0(pbVar6 + 4);
  if (iVar3 == 0) {
LAB_00584188:
    iVar3 = FUN_004081b0(pbVar6 + 0x10);
    if (iVar3 == 0) {
      return 0;
    }
    uVar2 = *(ushort *)(iVar3 + 0x10);
    while (uVar4 = (uint)uVar2, uVar4 < 4) {
      uVar5 = (uint)*(ushort *)(iVar3 + 0x12);
      if ((uVar5 == 0) || (*(int *)(iVar3 + 0x14) == 0)) {
        __format = "\t\t\t***WTP Descriptor Subelement Length(%d) is wrong \r\n";
        uVar4 = uVar5;
        goto LAB_005842b4;
      }
      printf("\t\t\tWTP Descriptor: (t=%d,l=%d) %s \r\n",uVar4,uVar5,
             (&PTR_s_WTP_Hardware_Version_006dcf38)[uVar4]);
      printf("\t\t\t\tWTP Descriptor Vendor: Unknown (%d) \r\n",*(undefined4 *)(iVar3 + 0xc));
      printf("\t\t\t\tDescriptor Type: %s (%d) \r\n",
             (&PTR_s_WTP_Hardware_Version_006dcf38)[*(ushort *)(iVar3 + 0x10)]);
      printf("\t\t\t\tDescriptor Length: %d \r\n",(uint)*(ushort *)(iVar3 + 0x12));
      printf("\t\t\t\tDescriptor Value: ");
      uVar2 = *(ushort *)(iVar3 + 0x12);
      for (iVar7 = 0; iVar7 < (int)(uint)uVar2; iVar7 = iVar7 + 1) {
        printf("%02x",(uint)*(byte *)(*(int *)(iVar3 + 0x14) + iVar7));
        uVar2 = *(ushort *)(iVar3 + 0x12);
      }
      puts("\r");
      printf("\t\t\t\t%s: %s\r\n",(&PTR_s_WTP_Hardware_Version_006dcf38)[*(ushort *)(iVar3 + 0x10)],
             *(undefined4 *)(iVar3 + 0x14));
      iVar3 = FUN_00408680(iVar3);
      if (iVar3 == 0) {
        return 0;
      }
      uVar2 = *(ushort *)(iVar3 + 0x10);
    }
    __format = "\t\t\t***WTP Descriptor Subelement(%d) is wrong \r\n";
  }
  else {
    bVar1 = *(byte *)(iVar3 + 0xc);
    while( true ) {
      uVar4 = (uint)bVar1;
      if ((uVar4 & 0x1f) != uVar4) break;
      printf("\t\t\t\tEncryption Capabilities: (WBID %d) %d \r\n",uVar4 & 0x1f,iVar7);
      puts("\t\t\t\t\t000. .... = Reserved (Encrypt): 0 \r");
      iVar7 = iVar7 + 1;
      printf("\t\t\t\t\t...0 %s = Encrypt WBID: %s (%d)\r\n",
             (&PTR_DAT_006dcf18)[*(byte *)(iVar3 + 0xc)],
             (&PTR_s_Reserved_006dcf28)[*(byte *)(iVar3 + 0xc)]);
      printf("\t\t\t\t\tEncryption Capabilities: %d \r\n",(uint)*(ushort *)(iVar3 + 0xe));
      iVar3 = FUN_00408680(iVar3);
      if (iVar3 == 0) goto LAB_00584188;
      bVar1 = *(byte *)(iVar3 + 0xc);
    }
    __format = "\t\t\t***Encryption Capabilities - wbid(%d) is wrong \r\n";
  }
LAB_005842b4:
  printf(__format,uVar4);
  return 0xffffffff;
}

