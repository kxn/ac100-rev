// func mac_auth_sqlite_group_cb_for_ssid @ 00454684 size=1928

undefined4
mac_auth_sqlite_group_cb_for_ssid(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *__dest;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *__s1;
  uint uVar10;
  uint uVar11;
  void *__s;
  void *pvVar12;
  undefined1 auStack_7c8 [12];
  uint local_7bc;
  uint local_7b8;
  byte abStack_7b4 [156];
  byte abStack_718 [156];
  undefined1 auStack_67c [56];
  undefined4 local_644;
  undefined1 auStack_640 [520];
  byte abStack_438 [1032];
  int local_30;
  
  memset(abStack_438,0,0x402);
  memset(auStack_7c8,0,0x188);
  if (macauth_debug_switch == 0) {
    if (param_1 == 0) {
LAB_004548e4:
      uVar8 = 0;
      if (macauth_err_switch != 0) {
        pcVar7 = "[MACAUTH_ERROR]%s()/%d para is null.\n";
        uVar9 = 0x2de;
LAB_00454904:
        printf(pcVar7,"mac_auth_sqlite_group_cb_for_ssid",uVar9);
      }
      return uVar8;
    }
    __s = *(void **)(param_1 + 4);
  }
  else {
    printf("[MACAUTH_DEBUG]%s()/%d column is %d\n","mac_auth_sqlite_group_cb_for_ssid",0x2da,param_2
          );
    if (param_1 == 0) goto LAB_004548e4;
    __s = *(void **)(param_1 + 4);
  }
  iVar1 = wserv_profile_get_max_wservice();
  memset(__s,-1,iVar1 << 2);
  pvVar12 = *(void **)(param_1 + 8);
  memset(pvVar12,0,(g_mac_auth_profile + 0x1fU >> 5) << 2);
  local_30 = 0;
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    pcVar7 = (char *)*param_3;
    if ((pcVar7 == (char *)0x0) || (__s1 = (char *)*param_4, __s1 == (char *)0x0)) {
      uVar8 = 1;
      if (macauth_err_switch == 0) {
        return 1;
      }
      pcVar7 = "[MACAUTH_ERROR]%s()/%d column value or name is null.\n";
      uVar9 = 0x2ea;
      goto LAB_00454904;
    }
    iVar4 = strcmp(__s1,"id");
    if (iVar4 == 0) {
      local_7bc = atoi(pcVar7);
      uVar8 = local_644;
    }
    else {
      iVar4 = strcmp(__s1,"enable");
      if (iVar4 == 0) {
        iVar4 = strcmp(pcVar7,"on");
        local_7b8 = (uint)(iVar4 == 0);
        uVar8 = local_644;
      }
      else {
        iVar4 = strcmp(__s1,"name");
        __dest = abStack_7b4;
        if (iVar4 == 0) {
LAB_00454838:
          sVar2 = 0x9b;
        }
        else {
          iVar4 = strcmp(__s1,"note");
          __dest = abStack_718;
          if (iVar4 == 0) goto LAB_00454838;
          iVar4 = strcmp(__s1,"serv_id_map");
          if (iVar4 != 0) {
            iVar4 = strcmp(__s1,"mac_id_map");
            if (iVar4 == 0) {
              if (macauth_debug_switch == 0) {
                local_30 = *param_3;
                uVar8 = local_644;
              }
              else {
                printf("[MACAUTH_DEBUG]%s()/%d bind mac: %s\n","mac_auth_sqlite_group_cb_for_ssid",
                       0x305,pcVar7);
                local_30 = *param_3;
                uVar8 = local_644;
              }
            }
            else {
              iVar4 = strcmp(__s1,"type");
              if (iVar4 == 0) {
                iVar4 = strcmp(pcVar7,"whitelist");
                uVar8 = 0;
                if (iVar4 != 0) {
                  iVar4 = strcmp(pcVar7,"blacklist");
                  uVar8 = 1;
                  if (iVar4 != 0) {
                    uVar8 = 0xffffffff;
                  }
                }
              }
              else {
                iVar4 = strcmp(__s1,"key");
                uVar8 = local_644;
                if ((iVar4 != 0) && (iVar4 = strcmp(__s1,"vlan"), uVar8 = local_644, iVar4 != 0)) {
                  if (macauth_err_switch == 0) {
                    return 1;
                  }
                  printf("[MACAUTH_ERROR]%s()/%d Invalid column_name[%s]\n",
                         "mac_auth_sqlite_group_cb_for_ssid",0x312,__s1);
                  return 1;
                }
              }
            }
            goto LAB_00454754;
          }
          if (macauth_debug_switch == 0) {
            pcVar7 = (char *)*param_3;
          }
          else {
            printf("[MACAUTH_DEBUG]%s()/%d bind ssid: %s\n","mac_auth_sqlite_group_cb_for_ssid",
                   0x300,pcVar7);
            pcVar7 = (char *)*param_3;
          }
          __dest = abStack_438;
          sVar2 = 0x401;
        }
        strncpy((char *)__dest,pcVar7,sVar2);
        uVar8 = local_644;
      }
    }
LAB_00454754:
    local_644 = uVar8;
    param_3 = param_3 + 1;
    param_4 = param_4 + 1;
  }
  memset(auStack_640,0,0x205);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d ssid str is %s.\n","mac_auth_bind_ssid_check",0x2a8,abStack_438);
  }
  sVar2 = strlen((char *)abStack_438);
  if (0 < (int)sVar2) {
    iVar1 = sVar2 - 1;
    uVar11 = 0;
    do {
      uVar3 = (uint)abStack_438[iVar1];
      if (uVar3 - 0x30 < 10) {
        if (uVar3 != 0x30) goto LAB_004549c4;
      }
      else {
        if ((5 < uVar3 - 0x61) && (5 < uVar3 - 0x41)) {
LAB_00454b34:
          if (macauth_err_switch != 0) {
            pcVar7 = "[MACAUTH_ERROR]%s()/%d wserv id map illegal\n";
            uVar8 = 0x318;
            goto LAB_00454be4;
          }
          iVar1 = *(int *)(param_1 + 0xc);
          goto LAB_00454b44;
        }
LAB_004549c4:
        uVar10 = 0;
        iVar4 = transfer_hex_to_int();
        uVar3 = uVar11;
        do {
          if ((iVar4 >> (uVar10 & 0x1f) & 1U) != 0) {
            uVar5 = wserv_profile_get_max_wservice();
            if ((uVar5 <= uVar3) ||
               (iVar6 = wserv_db_get_entry_by_id(uVar3,auStack_640), iVar6 != 0)) goto LAB_00454b34;
          }
          uVar10 = uVar10 + 1;
          uVar3 = uVar3 + 1;
        } while (uVar10 != 4);
      }
      iVar1 = iVar1 + -1;
      uVar11 = uVar11 + 4;
    } while (iVar1 != -1);
  }
  iVar1 = mac_auth_db_get_bind_ssid(__s);
  if (iVar1 == 0) {
    iVar1 = mac_auth_bind_ssid(abStack_438,__s,1,0,local_7bc,0);
    if (iVar1 == 0) {
      if ((local_30 != 0) && (iVar1 = mac_auth_bind_mac(local_30,pvVar12,0), iVar1 == 0)) {
        if ((__s == (void *)0x0) || (pvVar12 == (void *)0x0)) {
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d Invalid params.\n",
                   "mac_auth_db_load_group_service_for_ssid",0x223);
          }
        }
        else {
          if ((-1 < (int)local_7bc) && (local_7bc < DAT_00766fe8)) {
            FUN_004082d0(DAT_00766ff8,0xffffffff);
            *(uint *)(DAT_00767024 + local_7bc * 0x188 + 0xc) = local_7bc;
            *(uint *)(DAT_00767024 + local_7bc * 0x188 + 0x10) = local_7b8;
            iVar1 = DAT_00767024 + local_7bc * 0x188;
            *(undefined4 *)(iVar1 + 0x184) = local_644;
            memcpy((void *)(iVar1 + 0x14),abStack_7b4,0x9c);
            memcpy((void *)(DAT_00767024 + local_7bc * 0x188 + 0xb0),abStack_718,0x9c);
            memcpy((void *)(DAT_00767024 + local_7bc * 0x188 + 0x14c),auStack_67c,0x33);
            memcpy(*(void **)(DAT_00767024 + local_7bc * 0x188 + 0x180),pvVar12,
                   (g_mac_auth_profile + 0x1fU >> 5) << 2);
            pvVar12 = DAT_0076701c;
            iVar1 = wserv_profile_get_max_wservice();
            memcpy(pvVar12,__s,iVar1 << 2);
            FUN_00408440(DAT_00767004,local_7bc);
            FUN_004086b0(&DAT_0076700c,DAT_00767024 + local_7bc * 0x188);
            FUN_00407f30(DAT_00766ff8);
            return 0;
          }
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d Invalid group entry Id(%d)\n",
                   "mac_auth_db_load_group_service_for_ssid",0x229);
          }
        }
        if (macauth_err_switch == 0) {
          iVar1 = *(int *)(param_1 + 0xc);
        }
        else {
          pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_load_group_service_for_ssid() failed.\n";
          uVar8 = 0x32d;
LAB_00454be4:
          printf(pcVar7,"mac_auth_sqlite_group_cb_for_ssid",uVar8);
          iVar1 = *(int *)(param_1 + 0xc);
        }
        goto LAB_00454b44;
      }
      if (macauth_err_switch == 0) {
        iVar1 = *(int *)(param_1 + 0xc);
        goto LAB_00454b44;
      }
      pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_mac() for entry(%d) failed.\n";
      uVar8 = 0x328;
    }
    else {
      if (macauth_err_switch == 0) {
        iVar1 = *(int *)(param_1 + 0xc);
        goto LAB_00454b44;
      }
      pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_ssid() for entry(%d) failed.\n";
      uVar8 = 0x323;
    }
  }
  else {
    if (macauth_err_switch == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
      goto LAB_00454b44;
    }
    pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_ssid() for entry(%d) failed.\n";
    uVar8 = 0x31d;
  }
  printf(pcVar7,"mac_auth_sqlite_group_cb_for_ssid",uVar8,local_7bc);
  iVar1 = *(int *)(param_1 + 0xc);
LAB_00454b44:
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00407ec0(local_7bc,iVar1,param_1 + 0x10);
  return 0;
}

