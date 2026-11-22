// func dhcpdef_db_apbind_entry_batch_able @ 004690a8 size=1144

undefined4
dhcpdef_db_apbind_entry_batch_able(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_batch_able",0x392,
           "dhcpdef_db_apbind_entry_batch_able");
  }
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "aps && ap_num";
    uVar4 = 0x393;
  }
  else {
    if (param_4 != (undefined4 *)0x0) {
      iVar3 = 0;
      FUN_004082d0(DAT_00767094,0xffffffff);
      do {
        if (param_3 <= iVar3) {
          FUN_00407f30(DAT_00767094);
          return 0;
        }
        *param_4 = 0;
        iVar1 = DAT_007670a8;
        iVar5 = *param_2;
        if (49999 < iVar5) {
          iVar6 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar5 = iVar5 + -50000 + iVar6 + iVar2;
        }
        iVar6 = DAT_007670a8;
        if (*(int *)(iVar1 + iVar5 * 0x11) < 0) {
LAB_0046922c:
          iVar1 = DAT_007670a8;
          iVar5 = *param_2;
          if (49999 < iVar5) {
            iVar6 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar5 = iVar5 + -50000 + iVar6 + iVar2;
          }
          iVar6 = DAT_007670a8;
          if (49999 < *(int *)(iVar1 + iVar5 * 0x11)) {
            iVar5 = *param_2;
            if (49999 < iVar5) {
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar5 = iVar5 + -50000 + iVar1 + iVar2;
            }
            iVar1 = *(int *)(iVar6 + iVar5 * 0x11);
            iVar5 = apmngr_db_get_sensor_max();
            if (iVar1 < iVar5 + 50000) {
              iVar5 = *param_2;
              goto LAB_00469130;
            }
          }
          if ((g_dhcpdef_warn != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            iVar5 = *param_2;
            pcVar7 = "\x1b[33;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
            uVar4 = 0x39e;
LAB_004692e8:
            printf(pcVar7,"dhcp_defend","dhcpdef_db_apbind_entry_batch_able",uVar4,iVar5);
          }
        }
        else {
          iVar5 = *param_2;
          if (49999 < iVar5) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar5 = iVar5 + -50000 + iVar1 + iVar2;
          }
          iVar6 = *(int *)(iVar6 + iVar5 * 0x11);
          iVar5 = apmngr_db_get_ap_max();
          iVar1 = apmngr_db_get_template_max();
          if (iVar5 + iVar1 <= iVar6) goto LAB_0046922c;
          iVar5 = *param_2;
LAB_00469130:
          iVar1 = DAT_007670a8;
          if (49999 < iVar5) {
            iVar6 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar5 = iVar5 + -50000 + iVar6 + iVar2;
          }
          iVar6 = DAT_007670a8;
          if (*(char *)(iVar1 + iVar5 * 0x11 + 8) == param_1) {
            if ((g_dhcpdef_warn != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              iVar5 = *param_2;
              pcVar7 = 
              "\x1b[33;49m[%s]<%s():%d> ap_id[%d] has been %s already, NO need to set again!\x1b[0m\r\n"
              ;
              uVar4 = 0x3a4;
              goto LAB_004692e8;
            }
          }
          else {
            iVar5 = *param_2;
            if (49999 < iVar5) {
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar5 = iVar5 + -50000 + iVar1 + iVar2;
            }
            *(char *)(iVar6 + iVar5 * 0x11 + 8) = (char)param_1;
            *param_4 = 1;
          }
        }
        iVar3 = iVar3 + 1;
        param_4 = param_4 + 1;
        param_2 = param_2 + 1;
      } while( true );
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "batch_apconf_chg";
    uVar4 = 0x394;
  }
  printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
         "dhcpdef_db_apbind_entry_batch_able",uVar4,pcVar7);
  return 0xffffffff;
}

