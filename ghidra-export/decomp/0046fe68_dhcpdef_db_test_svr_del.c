// func dhcpdef_db_test_svr_del @ 0046fe68 size=264

void dhcpdef_db_test_svr_del(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
    iVar3 = 0x14;
    do {
      uVar1 = rand();
      if (l_dhcpdef_profile == 0) {
        trap(7);
      }
      uVar1 = uVar1 % l_dhcpdef_profile;
      if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[%s]<%s():%d> [---DEL---] random svr_id: %d\r\n","dhcp_defend",
               "dhcpdef_db_test_svr_del",0x8d0,uVar1);
      }
      iVar3 = iVar3 + -1;
      dhcpdef_db_svr_entry_del(uVar1);
    } while (iVar3 != 0);
  }
  dhcpdef_db_svr_entry_print_all();
  return;
}

