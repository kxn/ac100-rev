// func dhcpdef_db_unbind @ 0046bebc size=1

undefined4 dhcpdef_db_unbind(char *param_1,char *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  
  if ((g_dhcpdef_info != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_unbind",0x56d,
           "dhcpdef_db_unbind");
  }
  if (-1 < (int)param_1) {
    iVar4 = apmngr_db_get_ap_max();
    iVar5 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar4 + iVar5) ||
       ((49999 < (int)param_1 && (iVar4 = apmngr_db_get_sensor_max(), (int)param_1 < iVar4 + 50000))
       )) {
      if (((int)param_2 < 0) || (l_dhcpdef_profile <= param_2)) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        pcVar12 = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
        uVar13 = 0x570;
        goto code_r0x0046c1cc;
      }
      if (param_3 == (undefined4 *)0x0) {
        if (g_dhcpdef_error == 0) {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        param_2 = "apconf_chg";
        pcVar12 = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
        uVar13 = 0x571;
        goto code_r0x0046c1cc;
      }
      *param_3 = 0;
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar4 = DAT_007670a8;
      uVar10 = DAT_007670a0 + (int)param_2 * 0xac;
      uVar6 = uVar10 & 3;
      uVar16 = uVar10 + 3 & 3;
      pcVar12 = (char *)((*(int *)(uVar10 - uVar6) << uVar6 * 8 |
                         DAT_007670a0 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar16 + 1) * 8 |
                        *(uint *)((uVar10 + 3) - uVar16) >> (3 - uVar16) * 8);
      if (((int)pcVar12 < 0) || (l_dhcpdef_profile <= pcVar12)) {
        uVar13 = 0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto code_r0x0046c1f0;
        pcVar12 = "\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n";
        uVar14 = 0x575;
        param_1 = param_2;
      }
      else {
        uVar6 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar5 = apmngr_db_get_ap_max();
          iVar7 = apmngr_db_get_template_max();
          uVar6 = (int)(param_1 + iVar7 + iVar5 + -50000) * 0x11;
        }
        iVar5 = DAT_007670a8;
        uVar15 = iVar4 + uVar6;
        uVar16 = uVar15 & 3;
        uVar10 = uVar15 + 3 & 3;
        if (-1 < (int)((*(int *)(uVar15 - uVar16) << uVar16 * 8 |
                       uVar6 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar10 + 1) * 8 |
                      *(uint *)((uVar15 + 3) - uVar10) >> (3 - uVar10) * 8)) {
          iVar4 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar4 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            iVar4 = (int)(param_1 + iVar7 + iVar4 + -50000) * 0x11;
          }
          uVar10 = iVar5 + iVar4;
          uVar6 = uVar10 & 3;
          iVar4 = *(int *)(uVar10 - uVar6);
          uVar16 = uVar10 + 3 & 3;
          uVar10 = *(uint *)((uVar10 + 3) - uVar16);
          iVar5 = apmngr_db_get_ap_max();
          iVar7 = apmngr_db_get_template_max();
          if (iVar5 + iVar7 <=
              (int)((iVar4 << uVar6 * 8 | 0xffffffffU >> (4 - uVar6) * 8 & 0x11) &
                    -1 << (uVar16 + 1) * 8 | uVar10 >> (3 - uVar16) * 8)) goto code_r0x0046c28c;
code_r0x0046c0ac:
          iVar4 = DAT_007670a8;
          uVar6 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar5 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            uVar6 = (int)(param_1 + iVar7 + iVar5 + -50000) * 0x11;
          }
          uVar16 = iVar4 + uVar6 + 9;
          uVar15 = uVar16 & 3;
          uVar10 = iVar4 + uVar6 + 0xc;
          uVar8 = uVar10 & 3;
          if ((int)((*(int *)(uVar16 - uVar15) << uVar15 * 8 |
                    uVar6 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)(uVar10 - uVar8) >> (3 - uVar8) * 8) < 1) {
            uVar13 = 0;
            if ((g_dhcpdef_warn != 0) &&
               (iVar5 = is_target_debug_ap(), iVar4 = DAT_007670a8, iVar5 != 0)) {
              uVar6 = (int)param_1 * 0x11;
              if (49999 < (int)param_1) {
                iVar5 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                uVar6 = (int)(param_1 + iVar7 + iVar5 + -50000) * 0x11;
              }
              uVar16 = iVar4 + uVar6 + 9;
              uVar15 = uVar16 & 3;
              uVar10 = iVar4 + uVar6 + 0xc;
              uVar8 = uVar10 & 3;
              printf("\x1b[33;49m[%s]<%s():%d> bind_svr_num[%d] <= 0 of ap_id[%d], NO need to unbind!\x1b[0m\r\n"
                     ,"dhcp_defend","dhcpdef_db_unbind",0x57b,
                     (*(int *)(uVar16 - uVar15) << uVar15 * 8 |
                     uVar6 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar8 + 1) * 8 |
                     *(uint *)(uVar10 - uVar8) >> (3 - uVar8) * 8,param_1);
              uVar13 = 0;
            }
          }
          else {
            pcVar11 = (char *)(uint)((int)param_1 < 50000);
            uVar16 = (int)param_1 * 0x11;
            pcVar12 = pcVar11;
            for (uVar6 = 0; iVar4 = DAT_007670a8, uVar6 < DAT_0076708c; uVar6 = uVar6 + 1) {
              pcVar9 = pcVar11;
              uVar10 = uVar16;
              if (pcVar11 == (char *)0x0) {
                iVar5 = apmngr_db_get_ap_max();
                uVar17 = apmngr_db_get_template_max();
                pcVar12 = (char *)uVar17;
                pcVar9 = (char *)0x11;
                uVar10 = (int)(param_1 + (int)((ulonglong)uVar17 >> 0x20) + iVar5 + -50000) * 0x11;
              }
              iVar5 = DAT_007670a8;
              uVar15 = iVar4 + uVar10 + 0xd;
              uVar8 = uVar15 & 3;
              uVar10 = iVar4 + uVar10 + 0x10;
              uVar1 = uVar10 & 3;
              uVar8 = ((*(int *)(uVar15 - uVar8) << uVar8 * 8 |
                       (uint)pcVar9 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar1 + 1) * 8 |
                      *(uint *)(uVar10 - uVar1) >> (3 - uVar1) * 8) + uVar6 * 4;
              uVar10 = uVar8 & 3;
              uVar15 = uVar8 + 3 & 3;
              pcVar12 = (char *)((*(int *)(uVar8 - uVar10) << uVar10 * 8 |
                                 (uint)pcVar12 & 0xffffffffU >> (4 - uVar10) * 8) &
                                 -1 << (uVar15 + 1) * 8 |
                                *(uint *)((uVar8 + 3) - uVar15) >> (3 - uVar15) * 8);
              if (pcVar12 == param_2) {
                uVar10 = uVar16;
                if (49999 < (int)param_1) {
                  iVar4 = apmngr_db_get_ap_max();
                  iVar7 = apmngr_db_get_template_max();
                  uVar10 = (int)(param_1 + iVar7 + iVar4 + -50000) * 0x11;
                }
                uVar15 = iVar5 + uVar10 + 0xd;
                uVar1 = uVar15 & 3;
                uVar8 = iVar5 + uVar10 + 0x10;
                uVar2 = uVar8 & 3;
                uVar10 = ((*(int *)(uVar15 - uVar1) << uVar1 * 8 |
                          uVar10 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
                         *(uint *)(uVar8 - uVar2) >> (3 - uVar2) * 8) + uVar6 * 4;
                uVar6 = uVar10 & 3;
                *(uint *)(uVar10 - uVar6) =
                     *(uint *)(uVar10 - uVar6) & -1 << (4 - uVar6) * 8 | 0xffffffffU >> uVar6 * 8;
                uVar6 = uVar10 + 3 & 3;
                puVar3 = (uint *)((uVar10 + 3) - uVar6);
                *puVar3 = *puVar3 & 0xffffffffU >> (uVar6 + 1) * 8 | -1 << (3 - uVar6) * 8;
                iVar4 = DAT_007670a8;
                uVar6 = (uint)((int)param_1 < 50000);
                if (uVar6 == 0) {
                  iVar5 = apmngr_db_get_ap_max();
                  uVar6 = apmngr_db_get_template_max();
                  uVar16 = (int)(param_1 + uVar6 + iVar5 + -50000) * 0x11;
                }
                iVar4 = iVar4 + uVar16;
                uVar13 = 0;
                uVar16 = iVar4 + 9U & 3;
                uVar10 = iVar4 + 0xcU & 3;
                uVar16 = ((*(int *)((iVar4 + 9U) - uVar16) << uVar16 * 8 |
                          uVar6 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar10 + 1) * 8 |
                         *(uint *)((iVar4 + 0xcU) - uVar10) >> (3 - uVar10) * 8) - 1;
                uVar6 = iVar4 + 9U & 3;
                puVar3 = (uint *)((iVar4 + 9U) - uVar6);
                *puVar3 = *puVar3 & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
                uVar6 = iVar4 + 0xcU & 3;
                puVar3 = (uint *)((iVar4 + 0xcU) - uVar6);
                *puVar3 = *puVar3 & 0xffffffffU >> (uVar6 + 1) * 8 | uVar16 << (3 - uVar6) * 8;
                *param_3 = 1;
                goto code_r0x0046c1f0;
              }
            }
            uVar13 = 0;
          }
          goto code_r0x0046c1f0;
        }
code_r0x0046c28c:
        iVar4 = DAT_007670a8;
        uVar6 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar5 = apmngr_db_get_ap_max();
          iVar7 = apmngr_db_get_template_max();
          uVar6 = (int)(param_1 + iVar7 + iVar5 + -50000) * 0x11;
        }
        iVar5 = DAT_007670a8;
        uVar15 = iVar4 + uVar6;
        uVar16 = uVar15 & 3;
        uVar10 = uVar15 + 3 & 3;
        if (49999 < (int)((*(int *)(uVar15 - uVar16) << uVar16 * 8 |
                          uVar6 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar10 + 1) * 8 |
                         *(uint *)((uVar15 + 3) - uVar10) >> (3 - uVar10) * 8)) {
          iVar4 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar4 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            iVar4 = (int)(param_1 + iVar7 + iVar4 + -50000) * 0x11;
          }
          uVar10 = iVar5 + iVar4;
          uVar6 = uVar10 & 3;
          iVar4 = *(int *)(uVar10 - uVar6);
          uVar16 = uVar10 + 3 & 3;
          uVar10 = *(uint *)((uVar10 + 3) - uVar16);
          iVar5 = apmngr_db_get_sensor_max();
          if ((int)((iVar4 << uVar6 * 8 | 0xffffffffU >> (4 - uVar6) * 8 & 50000) &
                    -1 << (uVar16 + 1) * 8 | uVar10 >> (3 - uVar16) * 8) < iVar5 + 50000)
          goto code_r0x0046c0ac;
        }
        uVar13 = 0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto code_r0x0046c1f0;
        pcVar12 = "\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
        uVar14 = 0x576;
      }
      uVar13 = 0xffffffff;
      printf(pcVar12,"dhcp_defend","dhcpdef_db_unbind",uVar14,param_1);
code_r0x0046c1f0:
      FUN_00407f30(DAT_00767094);
      return uVar13;
    }
  }
  if ((g_dhcpdef_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) {
    return 0xffffffff;
  }
  pcVar12 = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar13 = 0x56f;
  param_2 = param_1;
code_r0x0046c1cc:
  printf(pcVar12,"dhcp_defend","dhcpdef_db_unbind",uVar13,param_2);
  return 0xffffffff;
}

