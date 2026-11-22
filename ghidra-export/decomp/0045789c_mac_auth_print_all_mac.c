// func mac_auth_print_all_mac @ 0045789c size=184

void mac_auth_print_all_mac(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  uVar1 = 0;
  while (uVar1 < g_mac_auth_profile) {
    if (*(int *)(DAT_00767020 + uVar1 * 0xa8) == -1) {
      iVar3 = iVar3 + 1;
      uVar1 = uVar1 + 1;
    }
    else {
      iVar2 = iVar2 + 1;
      mac_auth_print_mac_entry();
      uVar1 = uVar1 + 1;
    }
  }
  printf("total mac entry number count: is %d, invalid is %d\n",iVar2,iVar3);
  return;
}

