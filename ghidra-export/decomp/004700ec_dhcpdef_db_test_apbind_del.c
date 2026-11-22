// func dhcpdef_db_test_apbind_del @ 004700ec size=380

void dhcpdef_db_test_apbind_del(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  for (iVar6 = 0; iVar6 < param_1; iVar6 = iVar6 + 1) {
    iVar5 = 0x14;
    do {
      uVar1 = rand();
      uVar2 = dhcpdef_db_get_max_ap();
      if (uVar2 == 0) {
        trap(7);
      }
      iVar3 = apmngr_db_get_ap_max();
      iVar4 = apmngr_db_get_template_max();
      if (uVar1 % uVar2 < (uint)(iVar3 + iVar4)) {
        uVar1 = rand();
        uVar2 = dhcpdef_db_get_max_ap();
        if (uVar2 == 0) {
          trap(7);
        }
        uVar1 = uVar1 % uVar2;
      }
      else {
        uVar1 = rand();
        uVar2 = dhcpdef_db_get_max_ap();
        if (uVar2 == 0) {
          trap(7);
        }
        iVar3 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        uVar1 = ((uVar1 % uVar2 - iVar4) + 50000) - iVar3;
      }
      if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[%s]<%s():%d> [---DEL---] random ap_id: %d\r\n","dhcp_defend",
               "dhcpdef_db_test_apbind_del",0x8fd,uVar1);
      }
      iVar5 = iVar5 + -1;
      dhcpdef_db_apbind_entry_del_force(uVar1);
    } while (iVar5 != 0);
  }
  dhcpdef_db_apbind_entry_print_all();
  return;
}

