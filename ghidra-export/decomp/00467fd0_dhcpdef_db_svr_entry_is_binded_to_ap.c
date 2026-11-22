// func dhcpdef_db_svr_entry_is_binded_to_ap @ 00467fd0 size=1236

undefined4 dhcpdef_db_svr_entry_is_binded_to_ap(char *param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  
  if (-1 < (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar1 + iVar2) ||
       ((49999 < (int)param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000))
       )) {
      if (((int)param_2 < 0) || (l_dhcpdef_profile <= param_2)) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar3 = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
        uVar4 = 0x235;
        goto LAB_0046828c;
      }
      if (param_3 == (undefined4 *)0x0) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        param_2 = "is_binded";
        pcVar3 = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
        uVar4 = 0x236;
        goto LAB_0046828c;
      }
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar1 = DAT_007670a8;
      pcVar3 = *(char **)(DAT_007670a0 + (int)param_2 * 0xac);
      if (((int)pcVar3 < 0) || (l_dhcpdef_profile <= pcVar3)) {
        uVar4 = 0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_004682b0;
        pcVar3 = "\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n";
        uVar5 = 0x239;
        param_1 = param_2;
      }
      else {
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar6 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar6 + iVar2 + -50000) * 0x11;
        }
        iVar6 = DAT_007670a8;
        if (-1 < *(int *)(iVar1 + iVar2)) {
          iVar1 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
          }
          iVar6 = *(int *)(iVar6 + iVar1);
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          if (iVar1 + iVar2 <= iVar6) goto LAB_0046834c;
LAB_00468170:
          iVar1 = DAT_007670a8;
          iVar2 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar2 = apmngr_db_get_ap_max();
            iVar6 = apmngr_db_get_template_max();
            iVar2 = (int)(param_1 + iVar6 + iVar2 + -50000) * 0x11;
          }
          if (*(int *)(iVar1 + iVar2 + 9) < 1) {
            *param_3 = 0;
          }
          else {
            for (uVar7 = 0; iVar1 = DAT_007670a8, uVar7 < DAT_0076708c; uVar7 = uVar7 + 1) {
              iVar2 = (int)param_1 * 0x11;
              if (49999 < (int)param_1) {
                iVar2 = apmngr_db_get_ap_max();
                iVar6 = apmngr_db_get_template_max();
                iVar2 = (int)(param_1 + iVar6 + iVar2 + -50000) * 0x11;
              }
              if (*(char **)(uVar7 * 4 + *(int *)(iVar1 + iVar2 + 0xd)) == param_2) {
                uVar4 = 0;
                *param_3 = 1;
                goto LAB_004682b0;
              }
            }
            *param_3 = 0;
          }
          uVar4 = 0;
          goto LAB_004682b0;
        }
LAB_0046834c:
        iVar1 = DAT_007670a8;
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar6 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar6 + iVar2 + -50000) * 0x11;
        }
        iVar6 = DAT_007670a8;
        if (49999 < *(int *)(iVar1 + iVar2)) {
          iVar1 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
          }
          iVar2 = *(int *)(iVar6 + iVar1);
          iVar1 = apmngr_db_get_sensor_max();
          if (iVar2 < iVar1 + 50000) goto LAB_00468170;
        }
        uVar4 = 0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_004682b0;
        pcVar3 = "\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
        uVar5 = 0x23a;
      }
      uVar4 = 0xffffffff;
      printf(pcVar3,"dhcp_defend","dhcpdef_db_svr_entry_is_binded_to_ap",uVar5,param_1);
LAB_004682b0:
      FUN_00407f30(DAT_00767094);
      return uVar4;
    }
  }
  if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    return 0xffffffff;
  }
  pcVar3 = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar4 = 0x234;
  param_2 = param_1;
LAB_0046828c:
  printf(pcVar3,"dhcp_defend","dhcpdef_db_svr_entry_is_binded_to_ap",uVar4,param_2);
  return 0xffffffff;
}

