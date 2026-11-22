// func dhcpdef_db_batch_bind_no_optimize @ 0046cfa0 size=2480

undefined4
dhcpdef_db_batch_bind_no_optimize
          (int *param_1,int param_2,uint *param_3,int param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 *local_48;
  int local_44;
  int local_40;
  uint *local_3c;
  int *local_38;
  
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_batch_bind_no_optimize",0x62b,
           "dhcpdef_db_batch_bind_no_optimize");
  }
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar14 = "aps && ap_num";
      uVar8 = 0x62c;
      goto LAB_0046d41c;
    }
  }
  else if ((param_3 == (uint *)0x0) || (param_4 == 0)) {
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar14 = "svrs && svr_num";
      uVar8 = 0x62d;
      goto LAB_0046d41c;
    }
  }
  else if (param_5 == (undefined4 *)0x0) {
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar14 = "batch_apconf_chg";
      uVar8 = 0x62e;
      goto LAB_0046d41c;
    }
  }
  else {
    if (param_6 != (undefined4 *)0x0) {
      if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[%s]<%s():%d> ap_num: %d, svr_num: %d\r\n","dhcp_defend",
               "dhcpdef_db_batch_bind_no_optimize",0x631,param_2,param_4);
      }
      FUN_004082d0(DAT_00767094,0xffffffff);
      local_48 = param_5;
      local_44 = 0;
      local_38 = param_1;
      do {
        if (param_2 <= local_44) {
          FUN_00407f30(DAT_00767094);
          if (g_dhcpdef_info == 0) {
            return 0;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0;
          }
          printf("[%s]<%s():%d> succeed to batch_bind()!\r\n","dhcp_defend",
                 "dhcpdef_db_batch_bind_no_optimize",0x67c);
          return 0;
        }
        *local_48 = 0;
        iVar2 = *local_38;
        if (iVar2 < 0) {
LAB_0046d530:
          if ((g_dhcpdef_warn != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar14 = "\x1b[33;49m[%s]<%s():%d> ap_id:%d is invalid!\x1b[0m\r\n";
            uVar8 = 0x63d;
LAB_0046d568:
            printf(pcVar14,"dhcp_defend","dhcpdef_db_batch_bind_no_optimize",uVar8,iVar2);
          }
        }
        else {
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          if ((iVar3 + iVar4 <= iVar2) &&
             ((iVar2 < 50000 || (iVar3 = apmngr_db_get_sensor_max(), iVar3 + 50000 <= iVar2))))
          goto LAB_0046d530;
          iVar4 = DAT_007670a8;
          iVar3 = iVar2;
          if (49999 < iVar2) {
            iVar10 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            iVar3 = iVar2 + -50000 + iVar10 + iVar3;
          }
          iVar10 = DAT_007670a8;
          if (*(int *)(iVar4 + iVar3 * 0x11) < 0) {
LAB_0046d614:
            iVar4 = DAT_007670a8;
            iVar3 = iVar2;
            if (49999 < iVar2) {
              iVar10 = apmngr_db_get_ap_max();
              iVar3 = apmngr_db_get_template_max();
              iVar3 = iVar2 + -50000 + iVar10 + iVar3;
            }
            iVar10 = DAT_007670a8;
            if (49999 < *(int *)(iVar4 + iVar3 * 0x11)) {
              iVar3 = iVar2;
              if (49999 < iVar2) {
                iVar4 = apmngr_db_get_ap_max();
                iVar3 = apmngr_db_get_template_max();
                iVar3 = iVar2 + -50000 + iVar4 + iVar3;
              }
              iVar4 = *(int *)(iVar10 + iVar3 * 0x11);
              iVar3 = apmngr_db_get_sensor_max();
              if (iVar4 < iVar3 + 50000) goto LAB_0046d18c;
            }
            if ((g_dhcpdef_warn == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_0046d574;
            pcVar14 = "\x1b[33;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n";
            uVar8 = 0x642;
            goto LAB_0046d568;
          }
          iVar3 = iVar2;
          if (49999 < iVar2) {
            iVar4 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            iVar3 = iVar2 + -50000 + iVar4 + iVar3;
          }
          iVar10 = *(int *)(iVar10 + iVar3 * 0x11);
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          if (iVar3 + iVar4 <= iVar10) goto LAB_0046d614;
LAB_0046d18c:
          iVar3 = iVar2 * 0x11;
          local_3c = param_3;
          for (local_40 = 0; local_40 < param_4; local_40 = local_40 + 1) {
            uVar11 = *local_3c;
            if (((int)uVar11 < 0) || (l_dhcpdef_profile <= uVar11)) {
              if ((g_dhcpdef_warn != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                pcVar14 = "\x1b[33;49m[%s]<%s():%d> svr_id:%d is invalid!\x1b[0m\r\n";
                uVar8 = 0x64b;
LAB_0046d468:
                printf(pcVar14,"dhcp_defend","dhcpdef_db_batch_bind_no_optimize",uVar8,uVar11);
              }
            }
            else {
              uVar5 = *(uint *)(DAT_007670a0 + uVar11 * 0xac);
              if (((int)uVar5 < 0) || (l_dhcpdef_profile <= uVar5)) {
                if ((g_dhcpdef_warn != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  pcVar14 = "\x1b[33;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n";
                  uVar8 = 0x650;
                  goto LAB_0046d468;
                }
              }
              else {
                bVar1 = 49999 < iVar2;
                iVar4 = iVar2 + -50000;
                uVar5 = 0;
                uVar13 = 0xffffffff;
                while (uVar12 = uVar5, iVar10 = DAT_007670a8, uVar12 < DAT_0076708c) {
                  iVar7 = iVar3;
                  if (bVar1) {
                    iVar7 = apmngr_db_get_ap_max();
                    iVar6 = apmngr_db_get_template_max();
                    iVar7 = (iVar4 + iVar7 + iVar6) * 0x11;
                  }
                  iVar6 = DAT_007670a8;
                  iVar9 = uVar12 * 4;
                  if (*(int *)(*(int *)(iVar10 + iVar7 + 0xd) + iVar9) < 0) {
LAB_0046d2b0:
                    if (uVar13 != 0xffffffff) goto LAB_0046d2bc;
                    uVar5 = uVar12 + 1;
                    uVar13 = uVar12;
                  }
                  else {
                    iVar10 = iVar3;
                    if (bVar1) {
                      iVar10 = apmngr_db_get_ap_max();
                      iVar7 = apmngr_db_get_template_max();
                      iVar10 = (iVar4 + iVar10 + iVar7) * 0x11;
                    }
                    if (l_dhcpdef_profile <= *(uint *)(*(int *)(iVar6 + iVar10 + 0xd) + iVar9))
                    goto LAB_0046d2b0;
LAB_0046d2bc:
                    iVar10 = DAT_007670a8;
                    iVar7 = iVar3;
                    if (bVar1) {
                      iVar7 = apmngr_db_get_ap_max();
                      iVar6 = apmngr_db_get_template_max();
                      iVar7 = (iVar4 + iVar7 + iVar6) * 0x11;
                    }
                    if (*(uint *)(*(int *)(iVar10 + iVar7 + 0xd) + iVar9) == uVar11) {
                      uVar13 = 0xffffffff;
                      if ((g_dhcpdef_warn != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                        printf("\x1b[33;49m[%s]<%s():%d> svr_id [%d] has been binded to ap_id [%d] already!\x1b[0m\r\n"
                               ,"dhcp_defend","dhcpdef_db_batch_bind_no_optimize",0x660,uVar11,iVar2
                              );
                      }
                      break;
                    }
                    uVar5 = uVar12 + 1;
                  }
                }
                iVar4 = DAT_007670a8;
                iVar10 = iVar3;
                if (49999 < iVar2) {
                  iVar10 = apmngr_db_get_ap_max();
                  iVar7 = apmngr_db_get_template_max();
                  iVar10 = (iVar2 + -50000 + iVar10 + iVar7) * 0x11;
                }
                iVar7 = DAT_007670a8;
                if (*(uint *)(iVar4 + iVar10 + 9) < DAT_0076708c) {
                  if (uVar13 != 0xffffffff) {
                    iVar4 = iVar3;
                    if (49999 < iVar2) {
                      iVar4 = apmngr_db_get_ap_max();
                      iVar10 = apmngr_db_get_template_max();
                      iVar4 = (iVar2 + -50000 + iVar4 + iVar10) * 0x11;
                    }
                    *(uint *)(uVar13 * 4 + *(int *)(iVar7 + iVar4 + 0xd)) = uVar11;
                    iVar4 = DAT_007670a8;
                    iVar10 = iVar3;
                    if (49999 < iVar2) {
                      iVar10 = apmngr_db_get_ap_max();
                      iVar7 = apmngr_db_get_template_max();
                      iVar10 = (iVar2 + -50000 + iVar10 + iVar7) * 0x11;
                    }
                    *(int *)(iVar4 + iVar10 + 9) = *(int *)(iVar4 + iVar10 + 9) + 1;
                    *local_48 = 1;
                  }
                }
                else if ((uVar13 != 0xffffffff) || (uVar12 == DAT_0076708c)) {
                  if ((g_dhcpdef_warn != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                    printf("\x1b[33;49m[%s]<%s():%d> Can NOT find empty space for new bind, ap_id [%d]!\x1b[0m\r\n"
                           ,"dhcp_defend","dhcpdef_db_batch_bind_no_optimize",0x669,iVar2);
                  }
                  *param_6 = 1;
                  break;
                }
              }
            }
            local_3c = local_3c + 1;
          }
        }
LAB_0046d574:
        local_44 = local_44 + 1;
        local_48 = local_48 + 1;
        local_38 = local_38 + 1;
      } while( true );
    }
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar14 = "bind_exceed_arr";
      uVar8 = 0x62f;
LAB_0046d41c:
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_batch_bind_no_optimize",uVar8,pcVar14);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

