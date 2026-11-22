// func mac_auth_print_all_group @ 00457954 size=400

void mac_auth_print_all_group(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  uVar2 = 0;
  while (uVar2 < DAT_00766fe8) {
    if (*(int *)(DAT_00767024 + uVar2 * 0x188 + 0xc) == -1) {
      iVar4 = iVar4 + 1;
      uVar2 = uVar2 + 1;
    }
    else {
      iVar3 = iVar3 + 1;
      mac_auth_print_group_entry();
      uVar2 = uVar2 + 1;
    }
  }
  puts("++++++++++bind_vlan++++++++++");
  for (uVar2 = 0; uVar2 < DAT_00766fec + 1U; uVar2 = uVar2 + 1) {
    if (*(int *)(DAT_00767018 + uVar2 * 4) != -1) {
      printf("%d:%d,",uVar2);
    }
  }
  puts("\n++++++++++bind_ssid++++++++++");
  for (uVar2 = 0; uVar1 = wserv_profile_get_max_wservice(), uVar2 < uVar1; uVar2 = uVar2 + 1) {
    if (*(int *)(DAT_0076701c + uVar2 * 4) != -1) {
      printf("%d:%d,",uVar2);
    }
  }
  puts("\n+++++++++++++++++++++++++++++\n");
  printf("total group entry number count: is %d, invalid is %d\n",iVar3,iVar4);
  return;
}

