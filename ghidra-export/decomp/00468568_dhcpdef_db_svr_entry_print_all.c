// func dhcpdef_db_svr_entry_print_all @ 00468568 size=212

void dhcpdef_db_svr_entry_print_all(void)

{
  uint uVar1;
  uint uVar2;
  
  FUN_004082d0(DAT_00767094,0xffffffff);
  if (l_dhcpdef_data != 0) {
    uVar2 = 0;
    puts("########################################################\r");
    printf("l_dhcpdef_data.svr_used = %d\r\n",DAT_0076709c);
    while (uVar2 < l_dhcpdef_profile) {
      uVar1 = *(uint *)(DAT_007670a0 + uVar2 * 0xac);
      if (((int)uVar1 < 0) || (l_dhcpdef_profile <= uVar1)) {
        uVar2 = uVar2 + 1;
      }
      else {
        uVar2 = uVar2 + 1;
        _dhcpdef_db_svr_entry_print();
      }
    }
  }
  FUN_00407f30(DAT_00767094);
  return;
}

