// func wips_info_dump @ 004ce724 size=320

void wips_info_dump(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  printf("id: %d\n",*(undefined4 *)(param_1 + 0xc));
  uVar1 = *(int *)(param_1 + 0x98) - 1;
  if (uVar1 < 6) {
    pcVar4 = (&PTR_DAT_006a83b8)[uVar1];
  }
  else {
    pcVar4 = "invalid type";
  }
  printf("wips_threat_class: %s\n",pcVar4);
  printf("ssid: %s[%d]\n",param_1 + 0x10,*(undefined4 *)(param_1 + 0x44));
  wips_mac2str(param_1 + 0x48,&local_20);
  printf("attacker_mac: %s\n",&local_20);
  wips_mac2str(param_1 + 0x4e,&local_20);
  printf("target_mac: %s\n",&local_20);
  if (*(int *)(param_1 + 0xa8) == 1) {
    pcVar4 = "0";
  }
  else {
    pcVar4 = "1";
  }
  printf("status: %s\n",pcVar4);
  uVar2 = wips_counter_status2str(*(undefined4 *)(param_1 + 0xac));
  printf("counter_status: %s\n",uVar2);
  for (iVar3 = FUN_004081b0(param_1 + 0x9c); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
    wips_detail_dump(iVar3);
  }
  putchar(10);
  return;
}

