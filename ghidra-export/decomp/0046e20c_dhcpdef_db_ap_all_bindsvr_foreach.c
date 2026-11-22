// func dhcpdef_db_ap_all_bindsvr_foreach @ 0046e20c size=1640

undefined4
dhcpdef_db_ap_all_bindsvr_foreach(undefined *param_1,code *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *__format;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_ap_all_bindsvr_foreach",0x75d,
           "dhcpdef_db_ap_all_bindsvr_foreach");
  }
  if (param_2 == (code *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    param_1 = &DAT_0068df1c;
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar7 = 0x75e;
    goto LAB_0046e500;
  }
  if (-1 < (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar1 + iVar2) ||
       ((49999 < (int)param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000))
       )) {
      FUN_0051ad88(&local_38);
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar1 = DAT_007670a8;
      iVar2 = (int)param_1 * 0x11;
      if (49999 < (int)param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar5 = apmngr_db_get_template_max();
        iVar2 = (int)(param_1 + iVar5 + iVar2 + -50000) * 0x11;
      }
      iVar5 = DAT_007670a8;
      if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0046e514:
        iVar1 = DAT_007670a8;
        iVar2 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar5 = apmngr_db_get_template_max();
          iVar2 = (int)(param_1 + iVar5 + iVar2 + -50000) * 0x11;
        }
        iVar5 = DAT_007670a8;
        if (49999 < *(int *)(iVar1 + iVar2)) {
          iVar1 = (int)param_1 * 0x11;
          if (49999 < (int)param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
          }
          iVar2 = *(int *)(iVar5 + iVar1);
          iVar1 = apmngr_db_get_sensor_max();
          if (iVar2 < iVar1 + 50000) goto LAB_0046e348;
        }
        uVar7 = 0xffffffff;
        if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_ap_all_bindsvr_foreach",0x763,param_1);
        }
      }
      else {
        iVar1 = (int)param_1 * 0x11;
        if (49999 < (int)param_1) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar1 = (int)(param_1 + iVar2 + iVar1 + -50000) * 0x11;
        }
        iVar5 = *(int *)(iVar5 + iVar1);
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        if (iVar1 + iVar2 <= iVar5) goto LAB_0046e514;
LAB_0046e348:
        uVar6 = 0;
        iVar1 = (int)param_1 * 0x11;
        while (iVar2 = DAT_007670a8, uVar6 < DAT_0076708c) {
          iVar5 = iVar1;
          if (49999 < (int)param_1) {
            iVar5 = apmngr_db_get_ap_max();
            iVar4 = apmngr_db_get_template_max();
            iVar5 = (int)(param_1 + iVar4 + iVar5 + -50000) * 0x11;
          }
          iVar4 = DAT_007670a8;
          iVar8 = uVar6 * 4;
          if (*(int *)(*(int *)(iVar2 + iVar5 + 0xd) + iVar8) < 0) {
LAB_0046e450:
            uVar6 = uVar6 + 1;
          }
          else {
            iVar2 = iVar1;
            if (49999 < (int)param_1) {
              iVar2 = apmngr_db_get_ap_max();
              iVar5 = apmngr_db_get_template_max();
              iVar2 = (int)(param_1 + iVar5 + iVar2 + -50000) * 0x11;
            }
            iVar5 = DAT_007670a8;
            if (*(uint *)(*(int *)(iVar4 + iVar2 + 0xd) + iVar8) < l_dhcpdef_profile) {
              iVar2 = iVar1;
              if (49999 < (int)param_1) {
                iVar2 = apmngr_db_get_ap_max();
                iVar4 = apmngr_db_get_template_max();
                iVar2 = (int)(param_1 + iVar4 + iVar2 + -50000) * 0x11;
              }
              iVar2 = *(int *)(*(int *)(iVar5 + iVar2 + 0xd) + iVar8);
              iVar5 = iVar2 * 0xac;
              uVar3 = *(uint *)(DAT_007670a0 + iVar5);
              if (((int)uVar3 < 0) || (l_dhcpdef_profile <= uVar3)) {
                if (g_dhcpdef_error == 0) goto LAB_0046e450;
                iVar5 = is_target_debug_ap();
                if (iVar5 == 0) {
                  uVar6 = uVar6 + 1;
                }
                else {
                  printf("\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n","dhcp_defend"
                         ,"dhcpdef_db_ap_all_bindsvr_foreach",0x76d,iVar2);
                  uVar6 = uVar6 + 1;
                }
              }
              else {
                iVar2 = FUN_004082a0(1,0xb8,0x772);
                if (iVar2 == 0) {
                  uVar7 = 0xffffffff;
                  if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                           "dhcpdef_db_ap_all_bindsvr_foreach",0x775);
                  }
                  goto LAB_0046e598;
                }
                memcpy((void *)(iVar2 + 0xc),(void *)(DAT_007670a0 + iVar5),0xac);
                FUN_004086b0(&local_38,iVar2);
                uVar6 = uVar6 + 1;
              }
            }
            else {
              uVar6 = uVar6 + 1;
            }
          }
        }
        uVar7 = 0;
      }
LAB_0046e598:
      iVar2 = 0;
      FUN_00407f30(DAT_00767094);
      *param_4 = 0;
      iVar1 = FUN_004081b0(&local_38);
      while (iVar1 != 0) {
        iVar5 = FUN_00408680(iVar1);
        iVar4 = (*param_2)(iVar2,iVar1 + 0xc,param_3);
        if (iVar4 == 0) {
          *param_4 = *param_4 + 1;
          iVar2 = iVar2 + 1;
          if ((g_dhcpdef_info != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[%s]<%s():%d> cursor: %d\r\n","dhcp_defend","dhcpdef_db_ap_all_bindsvr_foreach",
                   0x78e,iVar2);
          }
        }
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
        iVar1 = iVar5;
      }
      return uVar7;
    }
  }
  if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    return 0xffffffff;
  }
  __format = "\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n";
  uVar7 = 0x75f;
LAB_0046e500:
  printf(__format,"dhcp_defend","dhcpdef_db_ap_all_bindsvr_foreach",uVar7,param_1);
  return 0xffffffff;
}

