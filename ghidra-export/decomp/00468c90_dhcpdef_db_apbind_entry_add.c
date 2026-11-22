// func dhcpdef_db_apbind_entry_add @ 00468c90 size=824

undefined4 dhcpdef_db_apbind_entry_add(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < 0) {
LAB_00468dc8:
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_add",0x345,param_1);
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if ((iVar1 + iVar2 <= param_1) &&
     ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= param_1))))
  goto LAB_00468dc8;
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
LAB_00468e14:
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
      if (iVar2 < iVar1 + 50000) goto LAB_00468d5c;
    }
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x11;
    }
    _dhcpdef_db_apbind_entry_init(iVar1 + iVar2);
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x11;
    }
    *(int *)(iVar1 + iVar2) = param_1;
    DAT_007670a4 = DAT_007670a4 + 1;
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
    if (iVar1 + iVar2 <= iVar3) goto LAB_00468e14;
LAB_00468d5c:
    if ((g_dhcpdef_warn != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[33;49m[%s]<%s():%d> apbind entry [%d] has been used!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_add",0x34b,param_1);
    }
  }
  FUN_00407f30(DAT_00767094);
  return 0;
}

