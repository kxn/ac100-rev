// func cw_priv_wlan_list_dump @ 005cb5a4 size=328

undefined4 cw_priv_wlan_list_dump(int param_1)

{
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wlan list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wlan list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x...\r\n",*piVar2);
  if (*piVar2 == 1) {
    pcVar1 = "AP report to AC";
  }
  else {
    pcVar1 = "AC delete on AP";
  }
  printf("\t\t\t\twlan operation: %u(%s) \r\n",*piVar2,pcVar1);
  printf("\t\t\t\twlan count: %u \r\n",piVar2[1]);
  puts("\t\t\t\twlan info: \r");
  if ((piVar2[1] != 0) && (uVar3 = 0, piVar2[2] != 0)) {
    for (; uVar3 < (uint)piVar2[1]; uVar3 = uVar3 + 1) {
      printf("\t\t\t\t\tradio id: %d ",(uint)*(byte *)(piVar2[2] + uVar3 * 0x21));
      printf("ssid: %s\r\n",piVar2[2] + uVar3 * 0x21 + 1);
    }
  }
  return 0;
}

