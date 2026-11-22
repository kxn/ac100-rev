// func cw_radio_administrative_state_dump @ 0057f3bc size=252

undefined4 cw_radio_administrative_state_dump(int param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  uint uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Radio Administrative State  \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Radio Administrative State  (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x \r\n",(uint)*pbVar4,(uint)pbVar4[1]);
  uVar3 = (uint)*pbVar4;
  if (uVar3 < 0x20) {
    printf("\t\t\tRadio Administrative ID: %d \r\n");
    printf("\t\t\tRadio Administrative State: ");
    if (pbVar4[1] == 1) {
      uVar1 = 1;
      pcVar2 = "Enabled (%d) \r\n";
    }
    else {
      if (pbVar4[1] != 2) {
        uVar3 = (uint)*pbVar4;
        pcVar2 = "\t\t\t***Radio Administrative State(%d) is wrong \r\n";
        goto LAB_0057f4a0;
      }
      uVar1 = 2;
      pcVar2 = "Disabled (%d) \r\n";
    }
    printf(pcVar2,uVar1);
    uVar1 = 0;
  }
  else {
    pcVar2 = "\t\t\t***Radio Administrative ID(%d) is wrong \r\n";
LAB_0057f4a0:
    printf(pcVar2,uVar3);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

