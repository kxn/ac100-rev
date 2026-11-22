// func cw_wtp_reboot_statistics_dump @ 0058672c size=384

undefined4 cw_wtp_reboot_statistics_dump(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  puVar3 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Reboot Statistics \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Reboot Statistics (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %04x%04x%04x%04x%04x%04x%04x%02x \r\n",(uint)*puVar3,(uint)puVar3[1],
         (uint)puVar3[2],(uint)puVar3[3],(uint)puVar3[4],(uint)puVar3[5],(uint)puVar3[6],
         (uint)*(byte *)(puVar3 + 7));
  printf("\t\t\tReboot  Count: %d \r\n",(uint)*puVar3);
  printf("\t\t\tAC Initiated Count: %d \r\n",(uint)puVar3[1]);
  printf("\t\t\tLink Failure Count: %d \r\n",(uint)puVar3[2]);
  printf("\t\t\tSW Failure Count: %d \r\n",(uint)puVar3[3]);
  printf("\t\t\tHW Failure Count: %d \r\n",(uint)puVar3[4]);
  printf("\t\t\tOther Failure Count: %d \r\n",(uint)puVar3[5]);
  printf("\t\t\tUnknown Failure Count: %d \r\n",(uint)puVar3[6]);
  uVar2 = (uint)*(byte *)(puVar3 + 7);
  if ((uVar2 - 6 & 0xff) < 0xf9) {
    printf("\t\t\t***Last Failure Type(%d) is wrong \r\n",uVar2);
    uVar1 = 0xffffffff;
  }
  else if (uVar2 < 6) {
    printf("\t\t\tLast Failure Type: %s (%d) \r\n",(&PTR_s_Not_Supported_006dda50)[uVar2]);
    uVar1 = 0;
  }
  else {
    printf("\t\t\tLast Failure Type: Unknown (%d) \r\n",0xff);
    uVar1 = 0;
  }
  return uVar1;
}

