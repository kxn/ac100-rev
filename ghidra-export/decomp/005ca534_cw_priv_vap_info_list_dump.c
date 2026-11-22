// func cw_priv_vap_info_list_dump @ 005ca534 size=400

undefined4 cw_priv_vap_info_list_dump(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 auStack_58 [4];
  undefined4 auStack_48 [12];
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  memcpy(auStack_48,&PTR_s_802_11a_006f11d0,0x30);
  memcpy(auStack_58,&PTR_s_AP_006f1200,0x10);
  printf("\t\t\tType: (t=%d,l=%d) private vap info list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private vap info list(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x.. \r\n",(uint)*pbVar4);
  printf("\t\t\t\tVap count: %d \r\n",(uint)*pbVar4);
  if (*pbVar4 != 0) {
    puts("\t\t\t\tvap list:bssid/radio id/mode/vap type/vap role\r");
    for (iVar5 = 0; iVar5 < (int)(uint)*pbVar4; iVar5 = iVar5 + 1) {
      pbVar1 = (byte *)(*(int *)(pbVar4 + 4) + iVar5 * 0x20);
      pcVar3 = "Unknown";
      if (pbVar1[7] < 0xc) {
        pcVar3 = (char *)auStack_48[pbVar1[7]];
      }
      pcVar2 = "Unknown";
      if (*(ushort *)(pbVar1 + 8) < 4) {
        pcVar2 = (char *)auStack_58[*(ushort *)(pbVar1 + 8)];
      }
      printf("\t\t\t\t\t%02X-%02X-%02X-%02X-%02X-%02X:%d/%s/%s/%d\r\n",(uint)*pbVar1,(uint)pbVar1[1]
             ,(uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5],(uint)pbVar1[6],pcVar3
             ,pcVar2,*(undefined4 *)(pbVar1 + 0xc));
    }
  }
  return 0;
}

