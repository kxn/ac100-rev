// func _dhcpdef_db_apbind_entry_firm_inner @ 0046a27c size=1488

undefined4 _dhcpdef_db_apbind_entry_firm_inner(char *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (-1 < (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar1 + iVar2) ||
       ((49999 < (int)param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000))
       )) {
      if (1 < param_2) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        param_1 = "type == DHCPDEF_FIRM_INSERT || type == DHCPDEF_FIRM_UPDATE";
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
        uVar5 = 0x434;
        goto LAB_0046a394;
      }
      pcVar4 = (char *)0x3;
      if (param_2 == 0) {
        pcVar4 = (char *)0x0;
      }
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar1 = DAT_007670a8;
      iVar2 = (int)param_1 * 0x11;
      if (49999 < (int)param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar7 = apmngr_db_get_template_max();
        iVar2 = (int)(param_1 + iVar7 + iVar2 + -50000) * 0x11;
      }
      iVar7 = DAT_007670a8;
      if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0046a454:
        iVar1 = DAT_007670a8;
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar7 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar7 + iVar2 + -50000) * 0x11;
        }
        iVar7 = DAT_007670a8;
        if (49999 < *(int *)(iVar1 + iVar2)) {
          iVar1 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
          }
          iVar2 = *(int *)(iVar7 + iVar1);
          iVar1 = apmngr_db_get_sensor_max();
          if (iVar2 < iVar1 + 50000) goto LAB_0046a4e0;
        }
        iVar1 = 0;
        if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
          uVar5 = 0xffffffff;
        }
        else {
          printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
                 "_dhcpdef_db_apbind_entry_firm_inner",0x439,param_1);
          uVar5 = 0xffffffff;
        }
      }
      else {
        iVar1 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
        }
        iVar7 = *(int *)(iVar7 + iVar1);
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        if (iVar1 + iVar2 <= iVar7) goto LAB_0046a454;
LAB_0046a4e0:
        if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[%s]<%s():%d> sizeof DHCPDEF_APBIND_ENTRY: %lu\r\n","dhcp_defend",
                 "_dhcpdef_db_apbind_entry_firm_inner",0x43b,0x11);
        }
        if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[%s]<%s():%d> sizeof svr_id_list: %lu\r\n","dhcp_defend",
                 "_dhcpdef_db_apbind_entry_firm_inner",0x43c,DAT_0076708c << 2);
        }
        if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[%s]<%s():%d> sizeof whole apbind entry: %lu\r\n","dhcp_defend",
                 "_dhcpdef_db_apbind_entry_firm_inner",0x43d,DAT_0076708c * 4 + 0x11);
        }
        iVar1 = FUN_00408450(DAT_0076708c * 4 + 0x11,0x43f);
        if (iVar1 == 0) {
          uVar5 = 0xffffffff;
          if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                   "_dhcpdef_db_apbind_entry_firm_inner",0x442);
          }
        }
        else {
          *(int *)(iVar1 + 0xd) = iVar1 + 0x11;
          iVar2 = DAT_007670a8;
          iVar7 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar7 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            iVar7 = (int)(param_1 + iVar3 + iVar7 + -50000) * 0x11;
          }
          dhcpdef_db_apbind_entry_deep_copy(iVar1,iVar2 + iVar7);
          iVar7 = dhcpdef_sqlite_notify(pcVar4,iVar1,DAT_0076708c * 4 + 0x11);
          iVar2 = DAT_007670a8;
          if (iVar7 == 0) {
            iVar7 = (int)param_1 * 0x11;
            if (49999 < (int)param_1) {
              iVar7 = apmngr_db_get_ap_max();
              iVar3 = apmngr_db_get_template_max();
              iVar7 = (int)(param_1 + iVar3 + iVar7 + -50000) * 0x11;
            }
            *(undefined4 *)(iVar2 + iVar7 + 4) = 1;
            uVar5 = 0;
            if ((g_dhcpdef_info == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_0046a588;
            __format = "[%s]<%s():%d> apbind entry [%d] is successfully firmed.\r\n";
            uVar6 = 0x452;
          }
          else {
            uVar5 = 0xffffffff;
            if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_0046a588;
            __format = "\x1b[31;49m[%s]<%s():%d> dhcpdef_sqlite_notify(%d) fail!\x1b[0m\r\n";
            uVar6 = 0x44c;
            param_1 = pcVar4;
          }
          printf(__format,"dhcp_defend","_dhcpdef_db_apbind_entry_firm_inner",uVar6,param_1);
        }
      }
LAB_0046a588:
      FUN_00407f30(DAT_00767094);
      if (iVar1 != 0) {
        FUN_00407df0(iVar1);
        return uVar5;
      }
      return uVar5;
    }
  }
  if (g_dhcpdef_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar4 = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar5 = 0x433;
LAB_0046a394:
  printf(pcVar4,"dhcp_defend","_dhcpdef_db_apbind_entry_firm_inner",uVar5,param_1);
  return 0xffffffff;
}

