// func dhcpdef_db_apbind_entry_unfirm @ 0046a85c size=588

undefined4 dhcpdef_db_apbind_entry_unfirm(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_res0 [4];
  
  local_res0[0] = param_1;
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_unfirm",0x475,
           "dhcpdef_db_apbind_entry_unfirm");
  }
  iVar1 = local_res0[0];
  if (-1 < local_res0[0]) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if (iVar1 < iVar2 + iVar3) goto LAB_0046a92c;
  }
  iVar1 = local_res0[0];
  if ((local_res0[0] < 50000) || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= iVar1)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n","dhcp_defend",
           "dhcpdef_db_apbind_entry_unfirm",0x476,local_res0[0]);
    return 0xffffffff;
  }
LAB_0046a92c:
  FUN_004082d0(DAT_00767094,0xffffffff);
  iVar2 = dhcpdef_sqlite_notify(1,local_res0,4);
  iVar1 = DAT_007670a8;
  if (iVar2 == 0) {
    iVar2 = local_res0[0];
    if (49999 < local_res0[0]) {
      iVar4 = local_res0[0] + -50000;
      iVar3 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar2 = iVar4 + iVar3 + iVar2;
    }
    *(undefined4 *)(iVar1 + iVar2 * 0x11 + 4) = 0;
    uVar5 = 0;
    if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[%s]<%s():%d> apbind entry [%d] is successfully unfirmed.\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_unfirm",0x480,local_res0[0]);
    }
  }
  else {
    uVar5 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> dhcpdef_sqlite_notify(DHCPDEF_SQL_OP_BIND_DELETE) fail!\x1b[0m\r\n"
             ,"dhcp_defend","dhcpdef_db_apbind_entry_unfirm",0x47b);
    }
  }
  FUN_00407f30(DAT_00767094);
  return uVar5;
}

