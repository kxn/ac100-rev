// func mac_auth_sqlite_group_cb @ 00453fa0 size=1604

undefined4
mac_auth_sqlite_group_cb(undefined4 *param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  char *__dest;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  void *__s;
  void *__s_00;
  int iVar6;
  int iVar7;
  char acStack_1e8 [52];
  undefined1 auStack_1b4 [12];
  char *local_1a8;
  uint local_1a4;
  char acStack_1a0 [156];
  char acStack_104 [156];
  undefined1 auStack_68 [56];
  undefined4 local_30;
  
  memset(acStack_1e8,0,0x33);
  memset(auStack_1b4,0,0x188);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d column is %d\n","mac_auth_sqlite_group_cb",0x247,param_2);
  }
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0;
    if (macauth_err_switch == 0) {
      return 0;
    }
    pcVar4 = "[MACAUTH_ERROR]%s()/%d para is null.\n";
    uVar3 = 0x24b;
LAB_0045423c:
    printf(pcVar4,"mac_auth_sqlite_group_cb",uVar3);
    return uVar2;
  }
  __s = (void *)*param_1;
  iVar7 = 0;
  iVar6 = 0;
  memset(__s,-1,(DAT_00766fec + 1) * 4);
  __s_00 = (void *)param_1[2];
  memset(__s_00,0,(g_mac_auth_profile + 0x1fU >> 5) << 2);
LAB_00454084:
  if (param_2 <= iVar6) goto LAB_0045428c;
  pcVar5 = (char *)*param_3;
  if ((pcVar5 == (char *)0x0) || (pcVar4 = (char *)*param_4, pcVar4 == (char *)0x0)) {
    uVar2 = 1;
    if (macauth_err_switch == 0) {
      return 1;
    }
    pcVar4 = "[MACAUTH_ERROR]%s()/%d column value or name is null.\n";
    uVar3 = 599;
    goto LAB_0045423c;
  }
  iVar1 = strcmp(pcVar4,"id");
  if (iVar1 == 0) {
    local_1a8 = (char *)atoi(pcVar5);
    uVar2 = local_30;
  }
  else {
    iVar1 = strcmp(pcVar4,"enable");
    if (iVar1 == 0) {
      iVar1 = strcmp(pcVar5,"on");
      local_1a4 = (uint)(iVar1 == 0);
      uVar2 = local_30;
    }
    else {
      iVar1 = strcmp(pcVar4,"name");
      __dest = acStack_1a0;
      if (iVar1 != 0) {
        iVar1 = strcmp(pcVar4,"note");
        __dest = acStack_104;
        if (iVar1 != 0) {
          iVar1 = strcmp(pcVar4,"vlan");
          if (iVar1 == 0) {
            if (macauth_debug_switch == 0) {
              pcVar4 = (char *)*param_3;
            }
            else {
              printf("[MACAUTH_DEBUG]%s()/%d bind vlan: %s\n","mac_auth_sqlite_group_cb",0x26d,
                     pcVar5);
              pcVar4 = (char *)*param_3;
            }
            strncpy(acStack_1e8,pcVar4,0x32);
            memcpy(auStack_68,(void *)*param_3,0x32);
            uVar2 = local_30;
          }
          else {
            iVar1 = strcmp(pcVar4,"mac_id_map");
            if (iVar1 == 0) {
              if (macauth_debug_switch == 0) {
                iVar7 = *param_3;
                uVar2 = local_30;
              }
              else {
                printf("[MACAUTH_DEBUG]%s()/%d bind mac: %s\n","mac_auth_sqlite_group_cb",0x273,
                       pcVar5);
                iVar7 = *param_3;
                uVar2 = local_30;
              }
            }
            else {
              iVar1 = strcmp(pcVar4,"type");
              if (iVar1 == 0) {
                iVar1 = strcmp(pcVar5,"whitelist");
                uVar2 = 0;
                if (iVar1 != 0) {
                  iVar1 = strcmp(pcVar5,"blacklist");
                  uVar2 = 1;
                  if (iVar1 != 0) {
                    uVar2 = 0xffffffff;
                  }
                }
                goto LAB_00454078;
              }
              iVar1 = strcmp(pcVar4,"key");
              uVar2 = local_30;
              if ((iVar1 != 0) &&
                 (iVar1 = strcmp(pcVar4,"serv_id_map"), uVar2 = local_30, iVar1 != 0)) {
                if (macauth_err_switch == 0) {
                  return 1;
                }
                pcVar5 = "[MACAUTH_ERROR]%s()/%d Invalid column_name[%s]\n";
                uVar2 = 0x280;
                goto LAB_004542c0;
              }
            }
          }
          goto LAB_00454078;
        }
      }
      strncpy(__dest,pcVar5,0x9b);
      uVar2 = local_30;
    }
  }
LAB_00454078:
  local_30 = uVar2;
  iVar6 = iVar6 + 1;
  param_3 = param_3 + 1;
  param_4 = param_4 + 1;
  goto LAB_00454084;
LAB_0045428c:
  iVar6 = mac_auth_db_get_bind_vlan(__s);
  if (iVar6 == 0) {
    iVar6 = mac_auth_bind_vlan(acStack_1e8,__s,1,0,local_1a8,0);
    if (iVar6 == 0) {
      if ((iVar7 == 0) || (iVar6 = mac_auth_bind_mac(iVar7,__s_00,0), iVar6 != 0)) {
        if (macauth_err_switch != 0) {
          pcVar5 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_mac() for entry(%d) failed.\n";
          uVar2 = 0x292;
          pcVar4 = local_1a8;
          goto LAB_004542c0;
        }
      }
      else {
        if ((__s == (void *)0x0) || (__s_00 == (void *)0x0)) {
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d Invalid params.\n","mac_auth_db_load_group_service",0x205
                  );
          }
        }
        else {
          if ((-1 < (int)local_1a8) && (local_1a8 < DAT_00766fe8)) {
            FUN_004082d0(DAT_00766ff8,0xffffffff);
            *(char **)(DAT_00767024 + (int)local_1a8 * 0x188 + 0xc) = local_1a8;
            *(uint *)(DAT_00767024 + (int)local_1a8 * 0x188 + 0x10) = local_1a4;
            iVar6 = DAT_00767024 + (int)local_1a8 * 0x188;
            *(undefined4 *)(iVar6 + 0x184) = local_30;
            memcpy((void *)(iVar6 + 0x14),acStack_1a0,0x9c);
            memcpy((void *)(DAT_00767024 + (int)local_1a8 * 0x188 + 0xb0),acStack_104,0x9c);
            memcpy((void *)(DAT_00767024 + (int)local_1a8 * 0x188 + 0x14c),auStack_68,0x33);
            memcpy(*(void **)(DAT_00767024 + (int)local_1a8 * 0x188 + 0x180),__s_00,
                   (g_mac_auth_profile + 0x1fU >> 5) << 2);
            memcpy(DAT_00767018,__s,(DAT_00766fec + 1) * 4);
            FUN_00408440(DAT_00767000,local_1a8);
            FUN_004086b0(&DAT_0076700c,DAT_00767024 + (int)local_1a8 * 0x188);
            FUN_00407f30(DAT_00766ff8);
            return 0;
          }
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d Invalid group entry Id(%d)\n",
                   "mac_auth_db_load_group_service",0x20b);
          }
        }
        uVar2 = 1;
        if (macauth_err_switch != 0) {
          pcVar4 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_load_group_service() failed.\n";
          uVar3 = 0x297;
          goto LAB_0045423c;
        }
      }
    }
    else if (macauth_err_switch != 0) {
      pcVar5 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_vlan() for entry(%d) failed.\n";
      uVar2 = 0x28c;
      pcVar4 = local_1a8;
      goto LAB_004542c0;
    }
  }
  else if (macauth_err_switch != 0) {
    pcVar5 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_vlan() for entry(%d) failed.\n";
    uVar2 = 0x286;
    pcVar4 = local_1a8;
LAB_004542c0:
    printf(pcVar5,"mac_auth_sqlite_group_cb",uVar2,pcVar4);
    return 1;
  }
  return 1;
}

