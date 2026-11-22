// func dhcpdef_db_batch_unbind @ 0046d950 size=1528

undefined4
dhcpdef_db_batch_unbind(int *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  int local_34;
  int *local_30;
  
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_batch_unbind",0x68f,
           "dhcpdef_db_batch_unbind");
  }
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar10 = "aps && ap_num";
      uVar5 = 0x690;
      goto LAB_0046dcc8;
    }
  }
  else if ((param_3 == 0) || (param_4 == 0)) {
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar10 = "sorted_svrs && svr_num";
      uVar5 = 0x691;
      goto LAB_0046dcc8;
    }
  }
  else {
    if (param_5 != (undefined4 *)0x0) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      local_34 = 0;
      local_30 = param_1;
      do {
        if (param_2 <= local_34) {
          FUN_00407f30(DAT_00767094);
          if (g_dhcpdef_info == 0) {
            return 0;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0;
          }
          printf("[%s]<%s():%d> succeed to batch_unbind()!\r\n","dhcp_defend",
                 "dhcpdef_db_batch_unbind",0x6af);
          return 0;
        }
        *param_5 = 0;
        iVar3 = DAT_007670a8;
        iVar6 = *local_30;
        iVar2 = iVar6;
        if (49999 < iVar6) {
          iVar7 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar2 = iVar6 + -50000 + iVar7 + iVar2;
        }
        iVar7 = DAT_007670a8;
        if (*(int *)(iVar3 + iVar2 * 0x11) < 0) {
LAB_0046dd14:
          iVar3 = DAT_007670a8;
          iVar2 = iVar6;
          if (49999 < iVar6) {
            iVar7 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar2 = iVar6 + -50000 + iVar7 + iVar2;
          }
          iVar7 = DAT_007670a8;
          if (49999 < *(int *)(iVar3 + iVar2 * 0x11)) {
            iVar2 = iVar6;
            if (49999 < iVar6) {
              iVar3 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar2 = iVar6 + -50000 + iVar3 + iVar2;
            }
            iVar3 = *(int *)(iVar7 + iVar2 * 0x11);
            iVar2 = apmngr_db_get_sensor_max();
            if (iVar3 < iVar2 + 50000) goto LAB_0046dac8;
          }
          if ((g_dhcpdef_warn != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("\x1b[33;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
                   "dhcpdef_db_batch_unbind",0x69d,iVar6);
          }
        }
        else {
          iVar2 = iVar6;
          if (49999 < iVar6) {
            iVar3 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar2 = iVar6 + -50000 + iVar3 + iVar2;
          }
          iVar7 = *(int *)(iVar7 + iVar2 * 0x11);
          iVar2 = apmngr_db_get_ap_max();
          iVar3 = apmngr_db_get_template_max();
          if (iVar2 + iVar3 <= iVar7) goto LAB_0046dd14;
LAB_0046dac8:
          bVar1 = 49999 < iVar6;
          iVar2 = iVar6 * 0x11;
          uVar9 = 0;
          iVar6 = iVar6 + -50000;
          while (iVar3 = DAT_007670a8, uVar9 < DAT_0076708c) {
            iVar7 = iVar2;
            if (bVar1) {
              iVar7 = apmngr_db_get_ap_max();
              iVar4 = apmngr_db_get_template_max();
              iVar7 = (iVar6 + iVar7 + iVar4) * 0x11;
            }
            iVar4 = DAT_007670a8;
            iVar8 = uVar9 * 4;
            if (*(int *)(*(int *)(iVar3 + iVar7 + 0xd) + iVar8) < 0) {
LAB_0046dc18:
              uVar9 = uVar9 + 1;
            }
            else {
              iVar3 = iVar2;
              if (bVar1) {
                iVar3 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar3 = (iVar6 + iVar3 + iVar7) * 0x11;
              }
              iVar7 = DAT_007670a8;
              if (*(uint *)(*(int *)(iVar4 + iVar3 + 0xd) + iVar8) < l_dhcpdef_profile) {
                iVar3 = iVar2;
                if (bVar1) {
                  iVar3 = apmngr_db_get_ap_max();
                  iVar4 = apmngr_db_get_template_max();
                  iVar3 = (iVar6 + iVar3 + iVar4) * 0x11;
                }
                iVar7 = dhcpdef_binary_search
                                  (param_3,param_4,
                                   *(undefined4 *)(*(int *)(iVar7 + iVar3 + 0xd) + iVar8));
                iVar3 = DAT_007670a8;
                if (-1 < iVar7) {
                  iVar7 = iVar2;
                  if (bVar1) {
                    iVar7 = apmngr_db_get_ap_max();
                    iVar4 = apmngr_db_get_template_max();
                    iVar7 = (iVar6 + iVar7 + iVar4) * 0x11;
                  }
                  *(undefined4 *)(*(int *)(iVar3 + iVar7 + 0xd) + iVar8) = 0xffffffff;
                  iVar3 = DAT_007670a8;
                  iVar7 = iVar2;
                  if (bVar1) {
                    iVar7 = apmngr_db_get_ap_max();
                    iVar4 = apmngr_db_get_template_max();
                    iVar7 = (iVar6 + iVar7 + iVar4) * 0x11;
                  }
                  *(int *)(iVar3 + iVar7 + 9) = *(int *)(iVar3 + iVar7 + 9) + -1;
                  *param_5 = 1;
                }
                goto LAB_0046dc18;
              }
              uVar9 = uVar9 + 1;
            }
          }
        }
        param_5 = param_5 + 1;
        local_34 = local_34 + 1;
        local_30 = local_30 + 1;
      } while( true );
    }
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar10 = "batch_apconf_chg";
      uVar5 = 0x692;
LAB_0046dcc8:
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_batch_unbind",uVar5,pcVar10);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

