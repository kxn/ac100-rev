// func dhcpdef_db_test_svr_add @ 0046fce0 size=1

/* WARNING: Removing unreachable block (ram,0x0046fda4) */

void dhcpdef_db_test_svr_add(int param_1)

{
  uint __seed;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uStack_d8;
  char acStack_d4 [151];
  byte bStack_3d;
  undefined1 auStack_3c [20];
  
  memset(&uStack_d8,0,0xac);
  __seed = time((time_t *)0x0);
  srand(__seed);
  for (iVar5 = 0; iVar5 < param_1; iVar5 = iVar5 + 1) {
    iVar4 = 0x14;
    do {
      uStack_d8 = rand();
      if (l_dhcpdef_profile == 0) {
        trap(7);
      }
      uStack_d8 = uStack_d8 % l_dhcpdef_profile;
      snprintf(acStack_d4,0x97,"name%d");
      bStack_3d = (byte)uStack_d8 & 1;
      iVar2 = 0;
      do {
        iVar1 = rand();
        iVar3 = iVar2 + 1;
        auStack_3c[iVar2] = (char)(iVar1 % 0x100);
        iVar2 = iVar3;
      } while (iVar3 != 6);
      uStack_d8 = dhcpdef_db_svr_entry_add();
      if (((-1 < (int)uStack_d8) && (g_dhcpdef_info != 0)) &&
         (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[%s]<%s():%d> [+++ADD+++] svr_id: %d\r\n","dhcp_defend","dhcpdef_db_test_svr_add",
               0x8ba,uStack_d8);
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  dhcpdef_db_svr_entry_print_all();
  return;
}

