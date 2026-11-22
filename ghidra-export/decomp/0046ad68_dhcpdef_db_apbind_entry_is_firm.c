// func dhcpdef_db_apbind_entry_is_firm @ 0046ad68 size=680

bool dhcpdef_db_apbind_entry_is_firm(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  
  if (param_1 < 0) {
LAB_0046aeb4:
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_is_firm",0x4a0,"(APMNGR_AP_ID_VALID(ap_id))");
    }
    return false;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if ((iVar1 + iVar2 <= param_1) &&
     ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= param_1))))
  goto LAB_0046aeb4;
  FUN_004082d0(DAT_00767094,0xffffffff);
  iVar1 = DAT_007670a8;
  iVar2 = param_1 * 0x11;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar4) * 0x11;
  }
  iVar4 = DAT_007670a8;
  if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0046af08:
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar4 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar4) * 0x11;
    }
    iVar4 = DAT_007670a8;
    bVar3 = false;
    if (*(int *)(iVar1 + iVar2) < 50000) goto LAB_0046ae5c;
    iVar1 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
    }
    bVar3 = false;
    iVar2 = *(int *)(iVar4 + iVar1);
    iVar1 = apmngr_db_get_sensor_max();
    if (iVar1 + 50000 <= iVar2) goto LAB_0046ae5c;
  }
  else {
    iVar1 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
    }
    iVar4 = *(int *)(iVar4 + iVar1);
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (iVar1 + iVar2 <= iVar4) goto LAB_0046af08;
  }
  iVar1 = DAT_007670a8;
  iVar2 = param_1 * 0x11;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar4) * 0x11;
  }
  bVar3 = *(int *)(iVar1 + iVar2 + 4) != 0;
LAB_0046ae5c:
  FUN_00407f30(DAT_00767094);
  return bVar3;
}

