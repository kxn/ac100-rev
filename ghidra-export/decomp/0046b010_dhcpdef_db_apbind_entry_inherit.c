// func dhcpdef_db_apbind_entry_inherit @ 0046b010 size=1636

undefined4 dhcpdef_db_apbind_entry_inherit(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_inherit",0x4b4,
           "dhcpdef_db_apbind_entry_inherit");
  }
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      if (-1 < param_2) {
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        if ((param_2 < iVar1 + iVar2) ||
           ((49999 < param_2 && (iVar1 = apmngr_db_get_sensor_max(), param_2 < iVar1 + 50000)))) {
          FUN_004082d0(DAT_00767094,0xffffffff);
          iVar1 = DAT_007670a8;
          iVar2 = param_1 * 0x11;
          if (49999 < param_1) {
            iVar2 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            iVar2 = (param_1 + -50000 + iVar2 + iVar7) * 0x11;
          }
          iVar7 = DAT_007670a8;
          if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0046b398:
            iVar1 = DAT_007670a8;
            iVar2 = param_1 * 0x11;
            if (49999 < param_1) {
              iVar2 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              iVar2 = (param_1 + -50000 + iVar2 + iVar7) * 0x11;
            }
            iVar7 = DAT_007670a8;
            if (49999 < *(int *)(iVar1 + iVar2)) {
              iVar1 = param_1 * 0x11;
              if (49999 < param_1) {
                iVar1 = apmngr_db_get_ap_max();
                iVar2 = apmngr_db_get_template_max();
                iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
              }
              iVar2 = *(int *)(iVar7 + iVar1);
              iVar1 = apmngr_db_get_sensor_max();
              if (iVar2 < iVar1 + 50000) goto LAB_0046b1ec;
            }
            uVar5 = 0xffffffff;
            if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_0046b318;
            __format = "\x1b[31;49m[%s]<%s():%d> parent_id[%d] is not used!\x1b[0m\r\n";
            uVar6 = 0x4bc;
          }
          else {
            iVar1 = param_1 * 0x11;
            if (49999 < param_1) {
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x11;
            }
            iVar7 = *(int *)(iVar7 + iVar1);
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            if (iVar1 + iVar2 <= iVar7) goto LAB_0046b398;
LAB_0046b1ec:
            iVar1 = DAT_007670a8;
            iVar2 = param_2 * 0x11;
            if (49999 < param_2) {
              iVar2 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              iVar2 = (param_2 + -50000 + iVar2 + iVar7) * 0x11;
            }
            iVar7 = DAT_007670a8;
            if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0046b258:
              iVar1 = DAT_007670a8;
              iVar2 = param_2 * 0x11;
              if (49999 < param_2) {
                iVar2 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar2 = (param_2 + -50000 + iVar2 + iVar7) * 0x11;
              }
              iVar7 = DAT_007670a8;
              if (49999 < *(int *)(iVar1 + iVar2)) {
                iVar1 = param_2 * 0x11;
                if (49999 < param_2) {
                  iVar1 = apmngr_db_get_ap_max();
                  iVar2 = apmngr_db_get_template_max();
                  iVar1 = (param_2 + -50000 + iVar1 + iVar2) * 0x11;
                }
                iVar2 = *(int *)(iVar7 + iVar1);
                iVar1 = apmngr_db_get_sensor_max();
                if (iVar2 < iVar1 + 50000) goto LAB_0046b44c;
              }
              uVar5 = 0xffffffff;
              if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0046b318;
              __format = "\x1b[31;49m[%s]<%s():%d> child_id[%d] is not used!\x1b[0m\r\n";
              uVar6 = 0x4c2;
              param_1 = param_2;
            }
            else {
              iVar1 = param_2 * 0x11;
              if (49999 < param_2) {
                iVar1 = apmngr_db_get_ap_max();
                iVar2 = apmngr_db_get_template_max();
                iVar1 = (param_2 + -50000 + iVar1 + iVar2) * 0x11;
              }
              iVar7 = *(int *)(iVar7 + iVar1);
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              if (iVar1 + iVar2 <= iVar7) goto LAB_0046b258;
LAB_0046b44c:
              iVar1 = DAT_007670a8;
              iVar2 = param_2 * 0x11;
              if (49999 < param_2) {
                iVar2 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar2 = (param_2 + -50000 + iVar2 + iVar7) * 0x11;
              }
              iVar7 = DAT_007670a8;
              iVar4 = param_1 * 0x11;
              if (49999 < param_1) {
                iVar4 = apmngr_db_get_ap_max();
                iVar3 = apmngr_db_get_template_max();
                iVar4 = (param_1 + -50000 + iVar4 + iVar3) * 0x11;
              }
              dhcpdef_db_apbind_entry_deep_copy(iVar1 + iVar2,iVar7 + iVar4);
              iVar1 = DAT_007670a8;
              iVar2 = param_2 * 0x11;
              if (49999 < param_2) {
                iVar2 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar2 = (param_2 + -50000 + iVar2 + iVar7) * 0x11;
              }
              *(int *)(iVar1 + iVar2) = param_2;
              iVar1 = DAT_007670a8;
              iVar2 = param_2 * 0x11;
              if (49999 < param_2) {
                iVar2 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar2 = (param_2 + -50000 + iVar2 + iVar7) * 0x11;
              }
              *(undefined4 *)(iVar1 + iVar2 + 4) = 0;
              uVar5 = 0;
              if ((g_dhcpdef_info == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0046b318;
              __format = "[%s]<%s():%d> succeed to inherit, parent_id: %d, child_id: %d.\r\n";
              uVar6 = 0x4d0;
            }
          }
          printf(__format,"dhcp_defend","dhcpdef_db_apbind_entry_inherit",uVar6,param_1);
LAB_0046b318:
          FUN_00407f30(DAT_00767094);
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
      uVar5 = 0x4b7;
      goto LAB_0046b384;
    }
  }
  if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    return 0xffffffff;
  }
  uVar5 = 0x4b6;
  param_2 = param_1;
LAB_0046b384:
  printf("\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n","dhcp_defend",
         "dhcpdef_db_apbind_entry_inherit",uVar5,param_2);
  return 0xffffffff;
}

