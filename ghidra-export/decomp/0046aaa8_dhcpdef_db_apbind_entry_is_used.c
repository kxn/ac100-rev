// func dhcpdef_db_apbind_entry_is_used @ 0046aaa8 size=704

undefined4 dhcpdef_db_apbind_entry_is_used(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  
  if (-1 < (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar1 + iVar2) ||
       ((49999 < (int)param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000))
       )) {
      if (param_2 == (undefined4 *)0x0) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        param_1 = "is_used";
        __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
        uVar3 = 0x48b;
        goto LAB_0046aca0;
      }
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar1 = DAT_007670a8;
      iVar2 = (int)param_1 * 0x11;
      if (49999 < (int)param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        iVar2 = (int)(param_1 + iVar4 + iVar2 + -50000) * 0x11;
      }
      iVar4 = DAT_007670a8;
      if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0046abf0:
        iVar1 = DAT_007670a8;
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar4 + iVar2 + -50000) * 0x11;
        }
        iVar4 = DAT_007670a8;
        if (*(int *)(iVar1 + iVar2) < 50000) {
          *param_2 = 0;
          goto LAB_0046ac6c;
        }
        iVar1 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
        }
        iVar2 = *(int *)(iVar4 + iVar1);
        iVar1 = apmngr_db_get_sensor_max();
        if (iVar1 + 50000 <= iVar2) {
          *param_2 = 0;
          goto LAB_0046ac6c;
        }
      }
      else {
        iVar1 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
        }
        iVar4 = *(int *)(iVar4 + iVar1);
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        if (iVar1 + iVar2 <= iVar4) goto LAB_0046abf0;
      }
      *param_2 = 1;
LAB_0046ac6c:
      FUN_00407f30(DAT_00767094);
      return 0;
    }
  }
  if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    return 0xffffffff;
  }
  __format = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar3 = 0x48a;
LAB_0046aca0:
  printf(__format,"dhcp_defend","dhcpdef_db_apbind_entry_is_used",uVar3,param_1);
  return 0xffffffff;
}

