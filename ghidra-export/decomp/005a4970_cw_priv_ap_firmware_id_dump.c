// func cw_priv_ap_firmware_id_dump @ 005a4970 size=308

undefined4 cw_priv_ap_firmware_id_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined1 auStack_40 [44];
  
  memset(auStack_40,0,0x21);
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap firmware_id \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap firmware_id (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x.. \r\n",(uint)*pbVar1,(uint)pbVar1[1]);
  FUN_004084f0(pbVar1,0x10,auStack_40);
  printf("\t\t\t\t\tFirmware id: %s \r\n",auStack_40);
  printf("\t\t\t\t\tBL Firmware num: %d \r\n",(uint)pbVar1[0x10]);
  if ((pbVar1[0x10] != 0) && (iVar2 = 0, *(int *)(pbVar1 + 0x14) != 0)) {
    for (; iVar2 < (int)(uint)pbVar1[0x10]; iVar2 = iVar2 + 1) {
      memset(auStack_40,0,0x21);
      FUN_004084f0(*(int *)(pbVar1 + 0x14) + iVar2 * 0x10,0x10,auStack_40);
      printf("\t\t\t\t\t\t%s\r\n",auStack_40);
    }
  }
  return 0;
}

