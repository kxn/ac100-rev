// func dhcpdef_db_svr_all_bindap_foreach @ 0046ecb4 size=1080

int dhcpdef_db_svr_all_bindap_foreach(undefined *param_1,code *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  void *__dest;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_svr_all_bindap_foreach",0x701,
           "dhcpdef_db_svr_all_bindap_foreach");
  }
  if (param_2 == (code *)0x0) {
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return -1;
      }
      param_1 = &DAT_0068df1c;
      __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
      uVar6 = 0x702;
      goto LAB_0046eea8;
    }
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < l_dhcpdef_profile)) {
      FUN_0051ad88(&local_38);
      __dest = (void *)0x0;
      iVar2 = 0;
      uVar9 = 0;
      FUN_004082d0(DAT_00767094,0xffffffff);
LAB_0046ede4:
      do {
        uVar3 = dhcpdef_db_get_max_ap();
        iVar7 = 0;
        if (uVar3 <= uVar9) {
LAB_0046efcc:
          FUN_00407f30(DAT_00767094);
          if (iVar7 != 0) {
            if (iVar2 != 0) {
              FUN_00407df0(iVar2);
            }
            if (__dest != (void *)0x0) {
              FUN_00407df0(__dest);
            }
          }
          iVar2 = FUN_004081b0(&local_38);
          while (iVar2 != 0) {
            iVar8 = FUN_00408680(iVar2);
            (*param_2)(iVar2 + 0xc,param_3);
            FUN_00408500(iVar2);
            FUN_00407df0(*(undefined4 *)(iVar2 + 0x19));
            FUN_00407df0(iVar2);
            iVar2 = iVar8;
          }
          return iVar7;
        }
        iVar7 = uVar9 * 0x11;
        iVar8 = *(int *)(DAT_007670a8 + iVar7);
        if (-1 < iVar8) {
          iVar4 = apmngr_db_get_ap_max();
          iVar5 = apmngr_db_get_template_max();
          if (iVar4 + iVar5 <= iVar8) goto LAB_0046eeb8;
LAB_0046ee3c:
          iVar8 = 0;
          if (DAT_0076708c == 0) {
LAB_0046ee84:
            uVar9 = uVar9 + 1;
          }
          else {
            for (uVar3 = *(uint *)(DAT_007670a8 + iVar7 + 0xd);
                *(undefined **)(iVar8 * 4 + uVar3) != param_1;
                uVar3 = *(int *)(uVar3 - uVar1) << uVar1 * 8 | 0xffffffffU >> (4 - uVar1) * 8 & 1) {
              iVar8 = iVar8 + 1;
              if (iVar8 == DAT_0076708c) goto LAB_0046ee84;
              uVar3 = DAT_007670a8 + iVar7 + 0xd;
              uVar1 = uVar3 & 3;
            }
            iVar2 = FUN_004082a0(1,0x20,0x716);
            if (iVar2 == 0) {
              __dest = (void *)0x0;
              if ((g_dhcpdef_error == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0)) {
                iVar7 = -1;
              }
              else {
                printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                       "dhcpdef_db_svr_all_bindap_foreach",0x719);
                iVar7 = -1;
              }
              goto LAB_0046efcc;
            }
            memcpy((void *)(iVar2 + 0xc),(void *)(DAT_007670a8 + iVar7),0x11);
            __dest = (void *)FUN_004082a0(DAT_0076708c,4,0x71e);
            if (__dest == (void *)0x0) {
              iVar7 = -1;
              if ((g_dhcpdef_error != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                       "dhcpdef_db_svr_all_bindap_foreach",0x721);
              }
              goto LAB_0046efcc;
            }
            uVar9 = uVar9 + 1;
            memcpy(__dest,*(void **)(DAT_007670a8 + iVar7 + 0xd),DAT_0076708c << 2);
            *(void **)(iVar2 + 0x19) = __dest;
            FUN_004086b0(&local_38,iVar2);
          }
          goto LAB_0046ede4;
        }
LAB_0046eeb8:
        iVar8 = *(int *)(DAT_007670a8 + iVar7);
        if (iVar8 < 50000) {
          uVar9 = uVar9 + 1;
        }
        else {
          iVar4 = apmngr_db_get_sensor_max();
          if (iVar8 < iVar4 + 50000) goto LAB_0046ee3c;
          uVar9 = uVar9 + 1;
        }
      } while( true );
    }
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
      uVar6 = 0x703;
LAB_0046eea8:
      printf(__format,"dhcp_defend","dhcpdef_db_svr_all_bindap_foreach",uVar6,param_1);
      return -1;
    }
  }
  return -1;
}

