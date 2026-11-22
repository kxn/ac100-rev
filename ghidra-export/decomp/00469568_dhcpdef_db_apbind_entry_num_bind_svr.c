// func dhcpdef_db_apbind_entry_num_bind_svr @ 00469568 size=744

undefined4 dhcpdef_db_apbind_entry_num_bind_svr(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 < 0) {
LAB_004696b0:
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_num_bind_svr",0x3bf,"(APMNGR_AP_ID_VALID(ap_id))");
    }
    return 0;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if ((iVar1 + iVar2 <= param_1) &&
     ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= param_1))))
  goto LAB_004696b0;
  FUN_004082d0(DAT_00767094,0xffffffff);
  iVar1 = DAT_007670a8;
  iVar2 = param_1 * 0x11;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x11;
  }
  iVar3 = DAT_007670a8;
  if (*(int *)(iVar1 + iVar2) < 0) {
LAB_00469704:
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x11;
    }
    iVar3 = DAT_007670a8;
    if (49999 < *(int *)(iVar1 + iVar2)) {
      iVar1 = param_1 * 0x11;
      if (49999 < param_1) {
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
      }
      iVar2 = *(int *)(iVar3 + iVar1);
      iVar1 = apmngr_db_get_sensor_max();
      if (iVar2 < iVar1 + 50000) goto LAB_00469630;
    }
    uVar4 = 0;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_num_bind_svr",0x3c2,param_1);
    }
  }
  else {
    iVar1 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
    }
    iVar3 = *(int *)(iVar3 + iVar1);
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (iVar1 + iVar2 <= iVar3) goto LAB_00469704;
LAB_00469630:
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x11;
    }
    uVar4 = *(undefined4 *)(iVar1 + iVar2 + 9);
  }
  FUN_00407f30(DAT_00767094);
  return uVar4;
}

