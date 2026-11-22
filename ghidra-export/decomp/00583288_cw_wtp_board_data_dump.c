// func cw_wtp_board_data_dump @ 00583288 size=496

undefined4 cw_wtp_board_data_dump(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  
  puVar7 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Board Data \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Board Data (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  puts("\t\t\tValue: \r");
  printf("\t\t\tWTP Board Data Vendor: Unknown (%d) \r\n",*puVar7);
  iVar2 = FUN_004081b0(puVar7 + 1);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 0xe);
    while( true ) {
      uVar5 = (uint)uVar1;
      if ((0x3ff < uVar5 - 1) || ((uint)*(ushort *)(param_1 + 0xe) < uVar5 + 4)) break;
      if (*(int *)(iVar2 + 0x10) == 0) {
        puts("\t\t\t***WTP Board Data Subelement Data is NULL \r");
        return 0xffffffff;
      }
      uVar4 = (uint)*(ushort *)(iVar2 + 0xc);
      pcVar6 = "Unknown";
      if (uVar4 < 0xb) {
        pcVar6 = (&PTR_s_WTP_Model_Number_006dc780)[uVar4];
      }
      printf("\t\t\tWTP Board Data: (t=%d,l=%d) %s \r\n",uVar4,uVar5,pcVar6);
      pcVar6 = "Unknown";
      if (*(ushort *)(iVar2 + 0xc) < 0xb) {
        pcVar6 = (&PTR_s_WTP_Model_Number_006dc780)[*(ushort *)(iVar2 + 0xc)];
      }
      printf("\t\t\t\tBoard Data Type: %s (%d) \r\n",pcVar6);
      printf("\t\t\t\tBoard Data Length: %d \r\n",(uint)*(ushort *)(iVar2 + 0xe));
      printf("\t\t\t\tBoard Data Value: ");
      uVar1 = *(ushort *)(iVar2 + 0xe);
      for (iVar8 = 0; iVar8 < (int)(uint)uVar1; iVar8 = iVar8 + 1) {
        printf("%02x",(uint)*(byte *)(*(int *)(iVar2 + 0x10) + iVar8));
        uVar1 = *(ushort *)(iVar2 + 0xe);
      }
      puts("\r");
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) {
        return 0;
      }
      uVar1 = *(ushort *)(iVar2 + 0xe);
    }
    printf("\t\t\t***WTP Board Data Subelement Length(%d) is wrong \r\n",
           (uint)*(ushort *)(iVar2 + 0xc));
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

