// func cw_radio_operational_state_dump @ 0057f86c size=276

undefined4 cw_radio_operational_state_dump(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Radio Operational State  \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Radio Operational State  (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%02x \r\n",(uint)*pbVar3,(uint)pbVar3[1],(uint)pbVar3[2]);
  if (*pbVar3 < 0x20) {
    printf("\t\t\tRadio ID(%d) Is Wrong \r\n");
    if (pbVar3[1] == 1) {
      uVar2 = 1;
      pcVar1 = "\t\t\tSate: Enabled (%d) \r\n";
    }
    else {
      if (pbVar3[1] != 2) {
        pcVar1 = "\t\t\t***State(%d) is wrong \r\n";
        goto LAB_0057f960;
      }
      uVar2 = 2;
      pcVar1 = "\t\t\tState: Disabled (%d) \r\n";
    }
    printf(pcVar1,uVar2);
    if (pbVar3[2] < 4) {
      printf("\t\t\tCause: %d \r\n");
      return 0;
    }
    pcVar1 = "\t\t\t***Cause(%d) Is Wrong \r\n";
  }
  else {
    pcVar1 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
LAB_0057f960:
  printf(pcVar1);
  return 0xffffffff;
}

