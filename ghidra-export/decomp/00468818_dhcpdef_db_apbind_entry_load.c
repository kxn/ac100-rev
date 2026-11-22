// func dhcpdef_db_apbind_entry_load @ 00468818 size=1144

undefined4 dhcpdef_db_apbind_entry_load(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint unaff_s1;
  char *pcVar6;
  int iVar7;
  
  if ((g_dhcpdef_info == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
    if (param_1 != (uint *)0x0) {
      pcVar6 = (char *)*param_1;
      goto LAB_00468858;
    }
  }
  else {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_load",799,
           "dhcpdef_db_apbind_entry_load");
    if (param_1 != (uint *)0x0) {
      uVar1 = (uint)param_1 & 3;
      pcVar6 = (char *)(*(int *)((int)param_1 - uVar1) << uVar1 * 8 |
                       unaff_s1 & 0xffffffffU >> (4 - uVar1) * 8);
LAB_00468858:
      if (-1 < (int)pcVar6) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        if (((int)pcVar6 < iVar2 + iVar3) ||
           ((49999 < (int)pcVar6 &&
            (iVar2 = apmngr_db_get_sensor_max(), (int)pcVar6 < iVar2 + 50000)))) {
          FUN_004082d0(DAT_00767094,0xffffffff);
          iVar2 = DAT_007670a8;
          pcVar4 = pcVar6;
          if (49999 < (int)pcVar6) {
            iVar3 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            pcVar4 = pcVar6 + iVar7 + iVar3 + -50000;
          }
          iVar3 = DAT_007670a8;
          if (*(int *)(iVar2 + (int)pcVar4 * 0x11) < 0) {
LAB_00468a74:
            iVar2 = DAT_007670a8;
            pcVar4 = pcVar6;
            if (49999 < (int)pcVar6) {
              iVar3 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              pcVar4 = pcVar6 + iVar7 + iVar3 + -50000;
            }
            iVar3 = DAT_007670a8;
            if (49999 < *(int *)(iVar2 + (int)pcVar4 * 0x11)) {
              pcVar4 = pcVar6;
              if (49999 < (int)pcVar6) {
                iVar2 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                pcVar4 = pcVar6 + iVar7 + iVar2 + -50000;
              }
              iVar3 = *(int *)(iVar3 + (int)pcVar4 * 0x11);
              iVar2 = apmngr_db_get_sensor_max();
              if (iVar3 < iVar2 + 50000) goto LAB_00468930;
            }
            iVar2 = DAT_007670a8;
            pcVar4 = pcVar6;
            if (49999 < (int)pcVar6) {
              iVar3 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              pcVar4 = pcVar6 + iVar7 + iVar3 + -50000;
            }
            dhcpdef_db_apbind_entry_deep_copy(iVar2 + (int)pcVar4 * 0x11,param_1);
            iVar2 = DAT_007670a8;
            pcVar4 = pcVar6;
            if (49999 < (int)pcVar6) {
              iVar3 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              pcVar4 = pcVar6 + iVar7 + iVar3 + -50000;
            }
            *(char **)(iVar2 + (int)pcVar4 * 0x11) = pcVar6;
            iVar2 = DAT_007670a8;
            if (49999 < (int)pcVar6) {
              iVar3 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              pcVar6 = pcVar6 + iVar7 + iVar3 + -50000;
            }
            uVar5 = 0;
            *(undefined4 *)(iVar2 + (int)pcVar6 * 0x11 + 4) = 1;
            DAT_007670a4 = DAT_007670a4 + 1;
          }
          else {
            pcVar4 = pcVar6;
            if (49999 < (int)pcVar6) {
              iVar2 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              pcVar4 = pcVar6 + iVar7 + iVar2 + -50000;
            }
            iVar7 = *(int *)(iVar3 + (int)pcVar4 * 0x11);
            iVar2 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            if (iVar2 + iVar3 <= iVar7) goto LAB_00468a74;
LAB_00468930:
            if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] has been used!\x1b[0m\r\n","dhcp_defend",
                     "dhcpdef_db_apbind_entry_load",0x329,pcVar6);
            }
            iVar2 = DAT_007670a8;
            if (49999 < (int)pcVar6) {
              iVar3 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              pcVar6 = pcVar6 + iVar7 + iVar3 + -50000;
            }
            uVar5 = 0xffffffff;
            *(undefined4 *)(iVar2 + (int)pcVar6 * 0x11 + 4) = 1;
          }
          FUN_00407f30(DAT_00767094);
          return uVar5;
        }
      }
      if (g_dhcpdef_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
      uVar5 = 0x323;
      goto LAB_004689dc;
    }
  }
  if (g_dhcpdef_error == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  pcVar6 = "bind_entry";
  pcVar4 = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
  uVar5 = 0x321;
LAB_004689dc:
  printf(pcVar4,"dhcp_defend","dhcpdef_db_apbind_entry_load",uVar5,pcVar6);
  return 0xffffffff;
}

