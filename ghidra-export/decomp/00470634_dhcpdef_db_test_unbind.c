// func dhcpdef_db_test_unbind @ 00470634 size=1

void dhcpdef_db_test_unbind(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 auStack_30 [2];
  
  auStack_30[0] = 0;
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  for (iVar6 = 0; iVar6 < param_1; iVar6 = iVar6 + 1) {
    iVar5 = 100;
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
      uVar2 = rand();
      if (l_dhcpdef_profile == 0) {
        trap(7);
      }
      uVar2 = uVar2 % l_dhcpdef_profile;
      if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[%s]<%s():%d> [***UNBIND***] ap_id: %d, svr_id: %d\r\n","dhcp_defend",
               "dhcpdef_db_test_unbind",0x96c,uVar1,uVar2);
      }
      iVar5 = iVar5 + -1;
      dhcpdef_db_unbind(uVar1,uVar2,auStack_30);
    } while (iVar5 != 0);
  }
  return;
}

