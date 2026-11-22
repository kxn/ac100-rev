// func cw_control_header_dump @ 005a15d4 size=228

undefined4 cw_control_header_dump(int *param_1)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    puts("\tControl header \r");
    printf("\t\tMessage Type: %d \r\n",*param_1);
    puts("\t\t\tMessage Type (Enterprise Number): Reserved (0) \r");
    uVar1 = *param_1 - 1;
    if (uVar1 < 0x1a) {
      ppuVar2 = &PTR_s_Discovery_Request_006e63b8;
    }
    else {
      uVar1 = *param_1 - 0x33dd01;
      if (1 < uVar1) {
        return 0xffffffff;
      }
      ppuVar2 = &PTR_s_IEEE_802_11_WLAN_Configuration_R_006e6420;
    }
    uVar3 = 0;
    printf("\t\t\tMessage Type (Enterprise Specific): %s (%d) \r\n",ppuVar2[uVar1]);
    printf("\t\tSequence Number: %d \r\n",(uint)*(byte *)(param_1 + 1));
    printf("\t\tMessage Element Length: %d \r\n",(uint)*(ushort *)((int)param_1 + 6));
    printf("\t\tFlags: %d \r\n",(uint)*(byte *)(param_1 + 2));
  }
  return uVar3;
}

