// func dhcpdef_db_test_bind @ 00470268 size=972

/* WARNING: Removing unreachable block (ram,0x004704cc) */

void dhcpdef_db_test_bind(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 local_d8;
  undefined1 auStack_d4 [4];
  char acStack_d0 [151];
  byte local_39;
  undefined1 local_38 [16];
  
  memset(auStack_d4,0,0xac);
  local_d8 = 0;
  puVar1 = (undefined4 *)FUN_004082a0(param_1,4,0x919);
  if (puVar1 == (undefined4 *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","dhcpdef_db_test_bind",0x91a,"ap_list");
  }
  else {
    puVar2 = (undefined4 *)FUN_004082a0(param_2,4,0x91b);
    if (puVar2 != (undefined4 *)0x0) {
      iVar10 = 0;
      uVar3 = time((time_t *)0x0);
      srand(uVar3);
      iVar6 = 0;
      while (iVar10 < param_1) {
        uVar3 = rand();
        uVar4 = dhcpdef_db_get_max_ap();
        if (uVar4 == 0) {
          trap(7);
        }
        iVar11 = apmngr_db_get_ap_max();
        iVar12 = apmngr_db_get_template_max();
        if (uVar3 % uVar4 < (uint)(iVar11 + iVar12)) {
          uVar3 = rand();
          uVar4 = dhcpdef_db_get_max_ap();
          if (uVar4 == 0) {
            trap(7);
          }
          uVar3 = uVar3 % uVar4;
        }
        else {
          uVar3 = rand();
          uVar4 = dhcpdef_db_get_max_ap();
          if (uVar4 == 0) {
            trap(7);
          }
          iVar11 = apmngr_db_get_ap_max();
          iVar12 = apmngr_db_get_template_max();
          uVar3 = ((uVar3 % uVar4 - iVar11) + 50000) - iVar12;
        }
        if ((g_dhcpdef_info != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
          printf("[%s]<%s():%d> [+++ADD+++] ap_id: %d\r\n","dhcp_defend","dhcpdef_db_test_bind",
                 0x927,uVar3);
        }
        iVar11 = dhcpdef_db_apbind_entry_add(uVar3);
        iVar10 = iVar10 + 1;
        if (iVar11 == 0) {
          puVar1[iVar6] = uVar3;
          iVar6 = iVar6 + 1;
        }
      }
      iVar10 = 0;
      for (iVar11 = 0; iVar11 < param_2; iVar11 = iVar11 + 1) {
        uVar3 = rand();
        if (l_dhcpdef_profile == 0) {
          trap(7);
        }
        uVar3 = uVar3 % l_dhcpdef_profile;
        snprintf(acStack_d0,0x97,"name%d",uVar3);
        iVar12 = 0;
        local_39 = (byte)uVar3 & 1;
        do {
          iVar5 = rand();
          iVar8 = iVar12 + 1;
          local_38[iVar12] = (char)(iVar5 % 0x100);
          iVar12 = iVar8;
        } while (iVar8 != 6);
        iVar12 = dhcpdef_db_svr_entry_add(auStack_d4);
        if ((g_dhcpdef_info != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[%s]<%s():%d> [+++ADD+++] svr_id: %d\r\n","dhcp_defend","dhcpdef_db_test_bind",
                 0x93c,iVar12);
        }
        iVar5 = iVar10;
        if (-1 < iVar12) {
          iVar5 = iVar10 + 1;
          puVar2[iVar10] = iVar12;
        }
        iVar10 = iVar5;
      }
      puVar13 = puVar1;
      for (iVar11 = 0; iVar11 < iVar6; iVar11 = iVar11 + 1) {
        puVar9 = puVar2;
        for (iVar12 = 0; iVar12 < iVar10; iVar12 = iVar12 + 1) {
          uVar7 = *puVar9;
          puVar9 = puVar9 + 1;
          dhcpdef_db_bind(*puVar13,uVar7,&local_d8);
        }
        puVar13 = puVar13 + 1;
      }
      if ((g_dhcpdef_info != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
        printf("[%s]<%s():%d> ################ADD %d AP IDs################\r\n","dhcp_defend",
               "dhcpdef_db_test_bind",0x94c,iVar6);
      }
      if ((g_dhcpdef_info != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("[%s]<%s():%d> ################ADD %d SERVER IDs################\r\n","dhcp_defend",
               "dhcpdef_db_test_bind",0x94d,iVar10);
      }
      FUN_00407df0(puVar1);
      puVar1 = puVar2;
    }
    FUN_00407df0(puVar1);
  }
  return;
}

