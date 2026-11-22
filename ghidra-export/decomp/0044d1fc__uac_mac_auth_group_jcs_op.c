// func _uac_mac_auth_group_jcs_op @ 0044d1fc size=1104

void _uac_mac_auth_group_jcs_op(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  char *__dest;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  undefined1 auStack_1b0 [16];
  uint local_1a0;
  
  memset(auStack_1b0,0,0x188);
  uVar1 = mac_auth_profile_get_max_group();
  piVar2 = (int *)FUN_004082a0(uVar1,4,0x351);
  if (piVar2 == (int *)0x0) {
    if (macauth_err_switch == 0) {
      uVar8 = 0xffffffff;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d no memory!\n","_uac_mac_auth_group_jcs_op",0x354);
      uVar8 = 0xffffffff;
    }
    goto LAB_0044d438;
  }
  __dest = (char *)FUN_00408450(0x1c16,0x358);
  if (__dest == (char *)0x0) {
    uVar8 = 0;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d no memory!\n","_uac_mac_auth_group_jcs_op",0x35b);
      uVar8 = 0;
    }
  }
  else {
    iVar3 = json_object_object_get(param_1,"operation");
    if (iVar3 == 0) {
LAB_0044d2b4:
      uVar9 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n",
               "_uac_mac_auth_group_jcs_op",0x360);
      }
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 1) {
        iVar3 = json_object_get_boolean(iVar3);
        uVar9 = (uint)(iVar3 != 0);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 3) goto LAB_0044d2b4;
        iVar3 = json_object_get_int(iVar3);
        uVar9 = (uint)(iVar3 != 0);
      }
    }
    iVar3 = json_object_object_get(param_1,"id");
    if (iVar3 == 0) {
      uVar8 = 0xffffffff;
      if (macauth_err_switch != 0) {
        __format = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
        uVar1 = 0x363;
        pcVar6 = "id";
LAB_0044d5a0:
        printf(__format,"_uac_mac_auth_group_jcs_op",uVar1,pcVar6);
      }
    }
    else {
      memset(__dest,0,0x1c16);
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 6) {
        pcVar6 = (char *)json_object_get_string(iVar3);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_group_jcs_op",0x366);
        }
        pcVar6 = "";
      }
      strncpy(__dest,pcVar6,0x1c15);
      __dest[0x1c15] = '\0';
      iVar4 = mac_auth_profile_get_max_group();
      pcVar6 = strtok(__dest,",");
      piVar10 = piVar2;
      for (iVar3 = 0; (pcVar6 != (char *)0x0 && (iVar3 < iVar4)); iVar3 = iVar3 + 1) {
        *piVar10 = (int)pcVar6;
        pcVar6 = strtok((char *)0x0,",");
        piVar10 = piVar10 + 1;
      }
      piVar2[iVar3] = 0;
      if (iVar3 < 1) {
        uVar8 = 0;
        if (macauth_err_switch != 0) {
          __format = "[MACAUTH_ERROR]%s()/%d _uac_mac_auth_util_str_split() fail, str: %s!\n";
          uVar1 = 0x36b;
          pcVar6 = __dest;
          goto LAB_0044d5a0;
        }
      }
      else {
        iVar4 = 0;
        uVar8 = 0;
        piVar10 = piVar2;
        do {
          iVar5 = atoi((char *)*piVar10);
          iVar5 = mac_auth_db_group_entry_get(iVar5,auStack_1b0);
          if (iVar5 == 0) {
            uVar7 = (uint)(local_1a0 != 0);
            local_1a0 = uVar9;
            if (macauth_debug_switch == 0) {
              if (uVar7 != 0) goto LAB_0044d3ec;
LAB_0044d508:
              if (uVar9 == 0) {
                uVar8 = uVar8 | 1;
                goto LAB_0044d3ac;
              }
            }
            else {
              printf("[MACAUTH_DEBUG]%s()/%d newStatus:%d, old:%d\n","_uac_mac_auth_group_jcs_op",
                     0x37a,uVar9,uVar7);
              if (uVar7 == 0) goto LAB_0044d508;
LAB_0044d3ec:
              if (uVar9 != 0) {
                uVar8 = uVar8 | 1;
                goto LAB_0044d3ac;
              }
            }
            iVar5 = mac_auth_db_group_entry_status_set(auStack_1b0);
            if (iVar5 == 0) {
              uVar8 = uVar8 | 2;
            }
          }
          else if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d id:%s, mac_auth_db_group_entry_get() failed.\n",
                   "_uac_mac_auth_group_jcs_op",0x373,*piVar10);
          }
LAB_0044d3ac:
          iVar4 = iVar4 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar4 != iVar3);
        if ((uVar8 & 2) != 0) {
          _uac_mac_auth_sta_check_trigger();
        }
      }
    }
  }
  FUN_00407df0(piVar2);
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (uVar8 == 0) {
    uVar8 = 0xffffffff;
  }
LAB_0044d438:
  uVar1 = json_object_new_int(uVar8);
  json_object_object_add(param_2,"result",uVar1);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_op() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_op",0x39d,uVar8);
  }
  return;
}

