// func dhcpdef_db_batch_bind @ 0046c514 size=1

undefined4
dhcpdef_db_batch_bind(int *param_1,int param_2,uint *param_3,size_t param_4,undefined4 *param_5)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *__s;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  undefined8 uVar22;
  char *pcVar23;
  int iStack_48;
  int iStack_40;
  undefined4 *puStack_3c;
  int iStack_38;
  int *piStack_34;
  
  if ((g_dhcpdef_info != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_batch_bind",0x5a5,
           "dhcpdef_db_batch_bind");
  }
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if ((g_dhcpdef_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      pcVar23 = "aps && ap_num";
      uVar15 = 0x5a6;
      goto code_r0x0046c8e0;
    }
  }
  else {
    if ((param_3 == (uint *)0x0) || (param_4 == 0)) {
      if (g_dhcpdef_error == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      pcVar23 = "sorted_svrs && svr_num";
      uVar15 = 0x5a7;
code_r0x0046c8e0:
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_batch_bind",uVar15,pcVar23);
      return 0xffffffff;
    }
    if (param_5 == (undefined4 *)0x0) {
      if (g_dhcpdef_error == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      pcVar23 = "batch_apconf_chg";
      uVar15 = 0x5a8;
      goto code_r0x0046c8e0;
    }
    if ((g_dhcpdef_info != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[%s]<%s():%d> ap_num: %d, svr_num: %d\r\n","dhcp_defend","dhcpdef_db_batch_bind",0x5aa
             ,param_2,param_4);
    }
    puVar5 = (undefined4 *)FUN_004082a0(DAT_0076708c,4,0x5ac);
    if (puVar5 == (undefined4 *)0x0) {
      if ((g_dhcpdef_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
               "dhcpdef_db_batch_bind",0x5af);
      }
    }
    else {
      __s = (undefined4 *)FUN_004082a0(param_4,1,0x5b3);
      if (__s == (undefined4 *)0x0) {
        iVar4 = -1;
        if ((g_dhcpdef_error != 0) && (iVar17 = is_target_debug_ap(), iVar17 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_batch_bind",0x5b6);
        }
      }
      else {
        FUN_004082d0(DAT_00767094,0xffffffff);
        puStack_3c = param_5;
        piStack_34 = param_1;
        for (iStack_38 = 0; iStack_38 < param_2; iStack_38 = iStack_38 + 1) {
          *puStack_3c = 0;
          uVar18 = DAT_007670a8;
          iVar17 = *piStack_34;
          iVar4 = iVar17;
          if (49999 < iVar17) {
            iVar6 = apmngr_db_get_ap_max();
            iVar4 = apmngr_db_get_template_max();
            iVar4 = iVar17 + -50000 + iVar6 + iVar4;
          }
          uVar19 = DAT_007670a8;
          uVar18 = uVar18 + iVar4 * 0x11;
          uVar21 = uVar18 & 3;
          uVar13 = uVar18 + 3 & 3;
          if ((int)((*(int *)(uVar18 - uVar21) << uVar21 * 8 |
                    iVar4 * 0x11 & 0xffffffffU >> (4 - uVar21) * 8) & -1 << (uVar13 + 1) * 8 |
                   *(uint *)((uVar18 + 3) - uVar13) >> (3 - uVar13) * 8) < 0) {
code_r0x0046c960:
            uVar18 = DAT_007670a8;
            iVar4 = iVar17;
            if (49999 < iVar17) {
              iVar6 = apmngr_db_get_ap_max();
              iVar4 = apmngr_db_get_template_max();
              iVar4 = iVar17 + -50000 + iVar6 + iVar4;
            }
            uVar19 = DAT_007670a8;
            uVar18 = uVar18 + iVar4 * 0x11;
            uVar21 = uVar18 & 3;
            uVar13 = uVar18 + 3 & 3;
            if (49999 < (int)((*(int *)(uVar18 - uVar21) << uVar21 * 8 |
                              iVar4 * 0x11 & 0xffffffffU >> (4 - uVar21) * 8) &
                              -1 << (uVar13 + 1) * 8 |
                             *(uint *)((uVar18 + 3) - uVar13) >> (3 - uVar13) * 8)) {
              iVar4 = iVar17;
              if (49999 < iVar17) {
                iVar6 = apmngr_db_get_ap_max();
                iVar4 = apmngr_db_get_template_max();
                iVar4 = iVar17 + -50000 + iVar6 + iVar4;
              }
              uVar19 = uVar19 + iVar4 * 0x11;
              uVar18 = uVar19 & 3;
              iVar4 = *(int *)(uVar19 - uVar18);
              uVar21 = uVar19 + 3 & 3;
              uVar13 = *(uint *)((uVar19 + 3) - uVar21);
              iVar6 = apmngr_db_get_sensor_max();
              if ((int)((iVar4 << uVar18 * 8 | 0xffffffffU >> (4 - uVar18) * 8 & 50000) &
                        -1 << (uVar21 + 1) * 8 | uVar13 >> (3 - uVar21) * 8) < iVar6 + 50000)
              goto code_r0x0046c6d4;
            }
            if ((g_dhcpdef_warn != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              pcVar23 = "\x1b[33;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
              uVar15 = 0x5c3;
              goto code_r0x0046cbfc;
            }
          }
          else {
            iVar4 = iVar17;
            if (49999 < iVar17) {
              iVar6 = apmngr_db_get_ap_max();
              iVar4 = apmngr_db_get_template_max();
              iVar4 = iVar17 + -50000 + iVar6 + iVar4;
            }
            uVar19 = uVar19 + iVar4 * 0x11;
            uVar18 = uVar19 & 3;
            iVar4 = *(int *)(uVar19 - uVar18);
            uVar21 = uVar19 + 3 & 3;
            uVar13 = *(uint *)((uVar19 + 3) - uVar21);
            iVar6 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            if (iVar6 + iVar7 <=
                (int)((iVar4 << uVar18 * 8 | 0xffffffffU >> (4 - uVar18) * 8 & 0x11) &
                      -1 << (uVar21 + 1) * 8 | uVar13 >> (3 - uVar21) * 8)) goto code_r0x0046c960;
code_r0x0046c6d4:
            puVar10 = puVar5;
            for (uVar18 = 0; uVar18 < DAT_0076708c; uVar18 = uVar18 + 1) {
              *puVar10 = 0xffffffff;
              puVar10 = puVar10 + 1;
            }
            uVar21 = iVar17 * 0x11;
            memset(__s,0,param_4);
            uVar18 = 0;
            iStack_40 = 0;
            bVar1 = 49999 < iVar17;
            iStack_48 = 0;
            iVar4 = iVar17 + -50000;
            while (uVar13 = DAT_007670a8, puVar14 = (undefined4 *)&DAT_00760000,
                  uVar18 < DAT_0076708c) {
              puVar8 = &l_dhcpdef_data;
              uVar19 = uVar21;
              if (bVar1) {
                iVar6 = apmngr_db_get_ap_max();
                uVar22 = apmngr_db_get_template_max();
                puVar10 = (undefined4 *)uVar22;
                puVar8 = (undefined4 *)0x11;
                uVar19 = (iVar4 + iVar6 + (int)((ulonglong)uVar22 >> 0x20)) * 0x11;
              }
              uVar2 = DAT_007670a8;
              iVar6 = uVar18 * 4;
              uVar9 = uVar13 + uVar19 + 0xd;
              uVar11 = uVar9 & 3;
              uVar13 = uVar13 + uVar19 + 0x10;
              uVar19 = uVar13 & 3;
              uVar9 = ((*(int *)(uVar9 - uVar11) << uVar11 * 8 |
                       (uint)puVar8 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar19 + 1) * 8 |
                      *(uint *)(uVar13 - uVar19) >> (3 - uVar19) * 8) + iVar6;
              uVar13 = uVar9 & 3;
              uVar19 = uVar9 + 3 & 3;
              uVar13 = (*(int *)(uVar9 - uVar13) << uVar13 * 8 |
                       (uint)puVar10 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar19 + 1) * 8 |
                       *(uint *)((uVar9 + 3) - uVar19) >> (3 - uVar19) * 8;
              puVar10 = &l_dhcpdef_data;
              if ((int)uVar13 < 0) {
code_r0x0046c7b8:
                puVar5[iStack_48] = uVar18;
                puVar14 = puVar5;
                iStack_48 = iStack_48 + 1;
              }
              else {
                uVar19 = uVar21;
                if (bVar1) {
                  iVar7 = apmngr_db_get_ap_max();
                  uVar22 = apmngr_db_get_template_max();
                  uVar13 = (uint)uVar22;
                  puVar10 = (undefined4 *)0x11;
                  uVar19 = (iVar4 + iVar7 + (int)((ulonglong)uVar22 >> 0x20)) * 0x11;
                }
                uVar9 = uVar2 + uVar19 + 0xd;
                uVar11 = uVar9 & 3;
                uVar19 = uVar2 + uVar19 + 0x10;
                uVar2 = uVar19 & 3;
                uVar11 = ((*(int *)(uVar9 - uVar11) << uVar11 * 8 |
                          (uint)puVar10 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar2 + 1) * 8 |
                         *(uint *)(uVar19 - uVar2) >> (3 - uVar2) * 8) + iVar6;
                uVar19 = uVar11 & 3;
                uVar9 = uVar11 + 3 & 3;
                if (l_dhcpdef_profile <=
                    ((*(int *)(uVar11 - uVar19) << uVar19 * 8 |
                     uVar13 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar9 + 1) * 8 |
                    *(uint *)((uVar11 + 3) - uVar9) >> (3 - uVar9) * 8)) goto code_r0x0046c7b8;
              }
              uVar13 = DAT_007670a8;
              puVar10 = &l_dhcpdef_data;
              uVar19 = uVar21;
              if (bVar1) {
                iVar7 = apmngr_db_get_ap_max();
                iVar12 = apmngr_db_get_template_max();
                puVar10 = (undefined4 *)0x11;
                uVar19 = (iVar4 + iVar7 + iVar12) * 0x11;
              }
              uVar9 = uVar13 + uVar19 + 0xd;
              uVar11 = uVar9 & 3;
              uVar13 = uVar13 + uVar19 + 0x10;
              uVar19 = uVar13 & 3;
              uVar9 = ((*(int *)(uVar9 - uVar11) << uVar11 * 8 |
                       (uint)puVar10 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar19 + 1) * 8 |
                      *(uint *)(uVar13 - uVar19) >> (3 - uVar19) * 8) + iVar6;
              uVar13 = uVar9 & 3;
              uVar19 = uVar9 + 3 & 3;
              iVar6 = dhcpdef_binary_search
                                (param_3,param_4,
                                 (*(int *)(uVar9 - uVar13) << uVar13 * 8 |
                                 (uint)puVar14 & 0xffffffffU >> (4 - uVar13) * 8) &
                                 -1 << (uVar19 + 1) * 8 |
                                 *(uint *)((uVar9 + 3) - uVar19) >> (3 - uVar19) * 8);
              puVar10 = (undefined4 *)(uint)(iVar6 < (int)param_4);
              if (iVar6 < 0) {
code_r0x0046c834:
                uVar18 = uVar18 + 1;
              }
              else {
                if (puVar10 != (undefined4 *)0x0) {
                  iStack_40 = iStack_40 + 1;
                  *(undefined1 *)((int)__s + iVar6) = 1;
                  puVar10 = __s;
                  goto code_r0x0046c834;
                }
                uVar18 = uVar18 + 1;
              }
            }
            if ((g_dhcpdef_info != 0) &&
               (iVar4 = is_target_debug_ap(), uVar18 = DAT_007670a8, iVar4 != 0)) {
              uVar13 = uVar21;
              if (49999 < iVar17) {
                iVar4 = apmngr_db_get_ap_max();
                iVar6 = apmngr_db_get_template_max();
                uVar13 = (iVar17 + -50000 + iVar4 + iVar6) * 0x11;
              }
              uVar19 = uVar18 + uVar13 + 9;
              uVar9 = uVar19 & 3;
              uVar18 = uVar18 + uVar13 + 0xc;
              uVar11 = uVar18 & 3;
              printf("[%s]<%s():%d> ap_id[%d], num_bind_svr[%d], empty_count[%d], select svrs\' bind_count[%d]\r\n"
                     ,"dhcp_defend","dhcpdef_db_batch_bind",0x5e2,iVar17,
                     (*(int *)(uVar19 - uVar9) << uVar9 * 8 |
                     uVar13 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar11 + 1) * 8 |
                     *(uint *)(uVar18 - uVar11) >> (3 - uVar11) * 8,iStack_48,iStack_40);
            }
            iVar4 = 0;
            puVar20 = param_3;
            iVar6 = 0;
            while (uVar18 = DAT_007670a8, iVar6 < (int)param_4) {
              if ((-1 < (int)*puVar20) && (*puVar20 < l_dhcpdef_profile)) {
                if (iVar4 < iStack_48) {
                  if (iVar4 + iStack_40 < (int)param_4) {
                    if (*(char *)((int)__s + iVar6) == '\0') {
                      puVar10 = __s;
                      uVar13 = uVar21;
                      if (49999 < iVar17) {
                        iVar7 = apmngr_db_get_ap_max();
                        iVar12 = apmngr_db_get_template_max();
                        puVar10 = (undefined4 *)0x11;
                        uVar13 = (iVar17 + -50000 + iVar7 + iVar12) * 0x11;
                      }
                      uVar11 = *puVar20;
                      uVar19 = uVar18 + uVar13 + 0xd;
                      uVar9 = uVar19 & 3;
                      uVar18 = uVar18 + uVar13 + 0x10;
                      uVar13 = uVar18 & 3;
                      uVar13 = puVar5[iVar4] * 4 +
                               ((*(int *)(uVar19 - uVar9) << uVar9 * 8 |
                                (uint)puVar10 & 0xffffffffU >> (4 - uVar9) * 8) &
                                -1 << (uVar13 + 1) * 8 |
                               *(uint *)(uVar18 - uVar13) >> (3 - uVar13) * 8);
                      uVar18 = uVar13 & 3;
                      *(uint *)(uVar13 - uVar18) =
                           *(uint *)(uVar13 - uVar18) & -1 << (4 - uVar18) * 8 |
                           uVar11 >> uVar18 * 8;
                      uVar18 = uVar13 + 3 & 3;
                      puVar3 = (uint *)((uVar13 + 3) - uVar18);
                      *puVar3 = *puVar3 & 0xffffffffU >> (uVar18 + 1) * 8 |
                                uVar11 << (3 - uVar18) * 8;
                      uVar18 = DAT_007670a8;
                      uVar13 = uVar21;
                      if (49999 < iVar17) {
                        iVar7 = apmngr_db_get_ap_max();
                        iVar12 = apmngr_db_get_template_max();
                        uVar13 = (iVar17 + -50000 + iVar7 + iVar12) * 0x11;
                      }
                      iVar7 = uVar18 + uVar13;
                      uVar13 = iVar7 + 9U & 3;
                      uVar19 = iVar7 + 0xcU & 3;
                      uVar13 = ((*(int *)((iVar7 + 9U) - uVar13) << uVar13 * 8 |
                                uVar18 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar19 + 1) * 8 |
                               *(uint *)((iVar7 + 0xcU) - uVar19) >> (3 - uVar19) * 8) + 1;
                      uVar18 = iVar7 + 9U & 3;
                      puVar3 = (uint *)((iVar7 + 9U) - uVar18);
                      *puVar3 = *puVar3 & -1 << (4 - uVar18) * 8 | uVar13 >> uVar18 * 8;
                      uVar18 = iVar7 + 0xcU & 3;
                      puVar3 = (uint *)((iVar7 + 0xcU) - uVar18);
                      *puVar3 = *puVar3 & 0xffffffffU >> (uVar18 + 1) * 8 |
                                uVar13 << (3 - uVar18) * 8;
                      *puStack_3c = 1;
                      iVar4 = iVar4 + 1;
                    }
                    goto code_r0x0046cb14;
                  }
                  if ((g_dhcpdef_warn == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) break;
                  pcVar23 = 
                  "\x1b[33;49m[%s]<%s():%d> select svrs are all binded to ap_id[%d], fill_count[%d]!\x1b[0m\r\n"
                  ;
                  uVar15 = 0x5f5;
                }
                else {
                  if ((g_dhcpdef_warn == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) break;
                  pcVar23 = 
                  "\x1b[33;49m[%s]<%s():%d> ap_id[%d]\'s svr_id_list is full, fill_count[%d]!\x1b[0m\r\n"
                  ;
                  uVar15 = 0x5ef;
                }
                printf(pcVar23,"dhcp_defend","dhcpdef_db_batch_bind",uVar15,iVar17,iVar4);
                break;
              }
              if ((g_dhcpdef_error == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0)) {
code_r0x0046cb14:
                puVar20 = puVar20 + 1;
                iVar6 = iVar6 + 1;
              }
              else {
                printf("\x1b[31;49m[%s]<%s():%d> Invalid svrs[%d] = %d!\x1b[0m\r\n","dhcp_defend",
                       "dhcpdef_db_batch_bind",0x5e9,iVar6,*puVar20);
                puVar20 = puVar20 + 1;
                iVar6 = iVar6 + 1;
              }
            }
            if ((g_dhcpdef_info != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              pcVar23 = "[%s]<%s():%d> ap_id[%d], fill_count[%d]\r\n";
              uVar15 = 0x601;
code_r0x0046cbfc:
              printf(pcVar23,"dhcp_defend","dhcpdef_db_batch_bind",uVar15,iVar17);
            }
          }
          puStack_3c = puStack_3c + 1;
          piStack_34 = piStack_34 + 1;
        }
        iVar4 = 0;
        FUN_00407f30(DAT_00767094);
      }
      FUN_00407df0(puVar5);
      if (__s != (undefined4 *)0x0) {
        FUN_00407df0(__s);
      }
      if (iVar4 == 0) {
        uVar15 = 0;
        if (g_dhcpdef_info == 0) {
          return 0;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0;
        }
        pcVar23 = "[%s]<%s():%d> succeed to batch_bind()!\r\n";
        uVar16 = 0x616;
        goto code_r0x0046ce84;
      }
    }
    uVar15 = 0xffffffff;
    if (g_dhcpdef_error != 0) {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      pcVar23 = "\x1b[31;49m[%s]<%s():%d> fail to batch_bind()!\x1b[0m\r\n";
      uVar16 = 0x61a;
code_r0x0046ce84:
      printf(pcVar23,"dhcp_defend","dhcpdef_db_batch_bind",uVar16);
      return uVar15;
    }
  }
  return 0xffffffff;
}

