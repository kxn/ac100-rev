// func _dhcpdef_db_apbind_entry_del_inner @ 0046675c size=988

undefined4 _dhcpdef_db_apbind_entry_del_inner(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 < 0) {
LAB_004668d8:
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_db_apbind_entry_del_inner",0x363,param_1);
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if ((iVar1 + iVar2 <= param_1) &&
     ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= param_1))))
  goto LAB_004668d8;
  FUN_004082d0(DAT_00767094,0xffffffff);
  iVar1 = DAT_007670a8;
  iVar2 = param_1 * 0x11;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar5 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x11;
  }
  iVar5 = DAT_007670a8;
  if (*(int *)(iVar1 + iVar2) < 0) {
LAB_00466924:
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar5 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x11;
    }
    iVar5 = DAT_007670a8;
    if (49999 < *(int *)(iVar1 + iVar2)) {
      iVar1 = param_1 * 0x11;
      if (49999 < param_1) {
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
      }
      iVar2 = *(int *)(iVar5 + iVar1);
      iVar1 = apmngr_db_get_sensor_max();
      if (iVar2 < iVar1 + 50000) goto LAB_0046682c;
    }
    uVar4 = 0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046696c;
    __format = "\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
    uVar3 = 0x366;
  }
  else {
    iVar1 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
    }
    iVar5 = *(int *)(iVar5 + iVar1);
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (iVar1 + iVar2 <= iVar5) goto LAB_00466924;
LAB_0046682c:
    iVar1 = DAT_007670a8;
    if (param_2 != 0) {
      iVar2 = param_1 * 0x11;
      if (49999 < param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar5 = apmngr_db_get_template_max();
        iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x11;
      }
      if (*(int *)(iVar1 + iVar2 + 4) != 0) {
        uVar4 = 0;
        if ((g_dhcpdef_info == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046696c;
        __format = "[%s]<%s():%d> apbind entry [%d] is firmed, can NOT delete!\r\n";
        uVar3 = 0x36c;
        goto LAB_004668a0;
      }
    }
    iVar1 = DAT_007670a8;
    iVar2 = param_1 * 0x11;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar5 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x11;
    }
    uVar4 = 0;
    _dhcpdef_db_apbind_entry_init(iVar1 + iVar2);
    DAT_007670a4 = DAT_007670a4 + -1;
    if ((g_dhcpdef_info == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046696c;
    __format = "[%s]<%s():%d> apbind entry [%d] is successfully deleted.\r\n";
    uVar3 = 0x375;
  }
LAB_004668a0:
  printf(__format,"dhcp_defend","_dhcpdef_db_apbind_entry_del_inner",uVar3,param_1);
LAB_0046696c:
  FUN_00407f30(DAT_00767094);
  return uVar4;
}

