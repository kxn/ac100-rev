// func dhcpdef_db_bind @ 0046b7b4 size=1800

undefined4 dhcpdef_db_bind(char *param_1,char *param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  if (-1 < (int)param_1) {
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar3 + iVar4) ||
       ((49999 < (int)param_1 && (iVar3 = apmngr_db_get_sensor_max(), (int)param_1 < iVar3 + 50000))
       )) {
      if (((int)param_2 < 0) || (l_dhcpdef_profile <= param_2)) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        pcVar6 = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
        uVar7 = 0x537;
        goto LAB_0046bb00;
      }
      if (param_3 == (undefined4 *)0x0) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        param_2 = "apconf_chg";
        pcVar6 = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
        uVar7 = 0x538;
        goto LAB_0046bb00;
      }
      *param_3 = 0;
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar3 = DAT_007670a8;
      pcVar6 = *(char **)(DAT_007670a0 + (int)param_2 * 0xac);
      if (((int)pcVar6 < 0) || (l_dhcpdef_profile <= pcVar6)) {
        uVar7 = 0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0046bb24;
        pcVar6 = "\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n";
        uVar8 = 0x53c;
        param_1 = param_2;
      }
      else {
        iVar4 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar4 = apmngr_db_get_ap_max();
          iVar9 = apmngr_db_get_template_max();
          iVar4 = (int)(param_1 + iVar9 + iVar4 + -50000) * 0x11;
        }
        iVar9 = DAT_007670a8;
        if (*(int *)(iVar3 + iVar4) < 0) {
LAB_0046bc70:
          iVar3 = DAT_007670a8;
          iVar4 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar4 = apmngr_db_get_ap_max();
            iVar9 = apmngr_db_get_template_max();
            iVar4 = (int)(param_1 + iVar9 + iVar4 + -50000) * 0x11;
          }
          iVar9 = DAT_007670a8;
          if (49999 < *(int *)(iVar3 + iVar4)) {
            iVar3 = (int)param_1 * 0x11;
            if (49999 < (int)param_1) {
              iVar3 = apmngr_db_get_ap_max();
              iVar4 = apmngr_db_get_template_max();
              iVar3 = (int)(param_1 + iVar4 + iVar3 + -50000) * 0x11;
            }
            iVar4 = *(int *)(iVar9 + iVar3);
            iVar3 = apmngr_db_get_sensor_max();
            if (iVar4 < iVar3 + 50000) goto LAB_0046b960;
          }
          uVar7 = 0xffffffff;
          if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0046bb24;
          pcVar6 = "\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
          uVar8 = 0x53d;
        }
        else {
          iVar3 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar3 = apmngr_db_get_ap_max();
            iVar4 = apmngr_db_get_template_max();
            iVar3 = (int)(param_1 + iVar4 + iVar3 + -50000) * 0x11;
          }
          iVar9 = *(int *)(iVar9 + iVar3);
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          if (iVar3 + iVar4 <= iVar9) goto LAB_0046bc70;
LAB_0046b960:
          iVar3 = DAT_007670a8;
          iVar4 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar4 = apmngr_db_get_ap_max();
            iVar9 = apmngr_db_get_template_max();
            iVar4 = (int)(param_1 + iVar9 + iVar4 + -50000) * 0x11;
          }
          if (*(uint *)(iVar3 + iVar4 + 9) < DAT_0076708c) {
            iVar3 = (int)param_1 * 0x11;
            bVar1 = 49999 < (int)param_1;
            uVar2 = 0;
            uVar11 = 0xffffffff;
            while (uVar10 = uVar2, iVar4 = DAT_007670a8, uVar10 < DAT_0076708c) {
              iVar9 = iVar3;
              if (bVar1) {
                iVar9 = apmngr_db_get_ap_max();
                iVar5 = apmngr_db_get_template_max();
                iVar9 = (int)(param_1 + iVar5 + iVar9 + -50000) * 0x11;
              }
              iVar5 = DAT_007670a8;
              iVar12 = uVar10 * 4;
              if (*(int *)(*(int *)(iVar4 + iVar9 + 0xd) + iVar12) < 0) {
LAB_0046ba50:
                if (uVar11 != 0xffffffff) goto LAB_0046ba60;
                uVar2 = uVar10 + 1;
                uVar11 = uVar10;
              }
              else {
                iVar4 = iVar3;
                if (bVar1) {
                  iVar4 = apmngr_db_get_ap_max();
                  iVar9 = apmngr_db_get_template_max();
                  iVar4 = (int)(param_1 + iVar9 + iVar4 + -50000) * 0x11;
                }
                if (l_dhcpdef_profile <= *(char **)(*(int *)(iVar5 + iVar4 + 0xd) + iVar12))
                goto LAB_0046ba50;
LAB_0046ba60:
                iVar4 = DAT_007670a8;
                iVar9 = iVar3;
                if (bVar1) {
                  iVar9 = apmngr_db_get_ap_max();
                  iVar5 = apmngr_db_get_template_max();
                  iVar9 = (int)(param_1 + iVar5 + iVar9 + -50000) * 0x11;
                }
                if (*(char **)(*(int *)(iVar4 + iVar9 + 0xd) + iVar12) == param_2) {
                  uVar7 = 0;
                  if ((g_dhcpdef_warn == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
                  goto LAB_0046bb24;
                  pcVar6 = 
                  "\x1b[33;49m[%s]<%s():%d> svr_id [%d] has been binded to ap_id [%d] already!\x1b[0m\r\n"
                  ;
                  uVar8 = 0x550;
                  param_1 = param_2;
                  goto LAB_0046bb64;
                }
                uVar2 = uVar10 + 1;
              }
            }
            uVar7 = 0;
            if (uVar11 != 0xffffffff) {
              iVar9 = iVar3;
              if (49999 < (int)param_1) {
                iVar9 = apmngr_db_get_ap_max();
                iVar5 = apmngr_db_get_template_max();
                iVar9 = (int)(param_1 + iVar5 + iVar9 + -50000) * 0x11;
              }
              *(char **)(uVar11 * 4 + *(int *)(iVar4 + iVar9 + 0xd)) = param_2;
              iVar4 = DAT_007670a8;
              if (49999 < (int)param_1) {
                iVar3 = apmngr_db_get_ap_max();
                iVar9 = apmngr_db_get_template_max();
                iVar3 = (int)(param_1 + iVar9 + iVar3 + -50000) * 0x11;
              }
              uVar7 = 0;
              *(int *)(iVar4 + iVar3 + 9) = *(int *)(iVar4 + iVar3 + 9) + 1;
              *param_3 = 1;
            }
            goto LAB_0046bb24;
          }
          uVar7 = 0xffffffff;
          if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0046bb24;
          pcVar6 = 
          "\x1b[31;49m[%s]<%s():%d> Can NOT find empty space for new bind, ap_id [%d], svr_id [%d]!\x1b[0m\r\n"
          ;
          uVar8 = 0x541;
        }
      }
LAB_0046bb64:
      printf(pcVar6,"dhcp_defend","dhcpdef_db_bind",uVar8,param_1);
LAB_0046bb24:
      FUN_00407f30(DAT_00767094);
      return uVar7;
    }
  }
  if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
    return 0xffffffff;
  }
  pcVar6 = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar7 = 0x536;
  param_2 = param_1;
LAB_0046bb00:
  printf(pcVar6,"dhcp_defend","dhcpdef_db_bind",uVar7,param_2);
  return 0xffffffff;
}

