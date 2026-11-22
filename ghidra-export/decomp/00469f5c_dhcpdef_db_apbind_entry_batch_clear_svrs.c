// func dhcpdef_db_apbind_entry_batch_clear_svrs @ 00469f5c size=800

undefined4 dhcpdef_db_apbind_entry_batch_clear_svrs(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  
  if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_batch_clear_svrs",
           0x409,"dhcpdef_db_apbind_entry_batch_clear_svrs");
  }
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar8 = "aps && ap_num";
    uVar4 = 0x40a;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {
        *param_3 = 0;
        iVar6 = DAT_007670a8;
        iVar5 = *param_1;
        if (49999 < iVar5) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar5 = iVar5 + -50000 + iVar1 + iVar2;
        }
        uVar7 = 0;
        if (*(int *)(iVar6 + iVar5 * 0x11 + 9) < 1) {
          if ((g_dhcpdef_warn != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("\x1b[33;49m[%s]<%s():%d> NO server is binded to ap_id[%d], NO need to clear!\x1b[0m\r\n"
                   ,"dhcp_defend","dhcpdef_db_apbind_entry_batch_clear_svrs",0x415,*param_1);
          }
        }
        else {
          for (; iVar5 = DAT_007670a8, uVar7 < DAT_0076708c; uVar7 = uVar7 + 1) {
            iVar6 = *param_1;
            if (49999 < iVar6) {
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar6 = iVar6 + -50000 + iVar1 + iVar2;
            }
            *(undefined4 *)(uVar7 * 4 + *(int *)(iVar5 + iVar6 * 0x11 + 0xd)) = 0xffffffff;
          }
          iVar6 = *param_1;
          if (49999 < iVar6) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar6 = iVar6 + -50000 + iVar1 + iVar2;
          }
          *(undefined4 *)(iVar5 + iVar6 * 0x11 + 9) = 0;
          *param_3 = 1;
        }
        param_3 = param_3 + 1;
        param_1 = param_1 + 1;
      }
      FUN_00407f30(DAT_00767094);
      return 0;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar8 = "batch_apconf_chg";
    uVar4 = 0x40b;
  }
  printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
         "dhcpdef_db_apbind_entry_batch_clear_svrs",uVar4,pcVar8);
  return 0xffffffff;
}

