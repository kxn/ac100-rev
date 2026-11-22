// func apupd_wtp_entry_add_after_handle @ 00654ac0 size=2336

undefined4 apupd_wtp_entry_add_after_handle(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char cVar5;
  int iVar4;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  void *__s1;
  undefined1 auStack_328 [48];
  undefined1 auStack_2f8 [18];
  ushort local_2e6;
  
  memset(auStack_2f8,0,0x2d8);
  if ((param_1 == 0) || (apupd_update_model_hash == 0)) {
    uVar8 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar7 = 0xc55;
    goto LAB_00654bac;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    uVar8 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar6 = "[APUPD_DEBUG]%32s() %05d: wtp\'s state is not init\r\n";
    uVar7 = 0xc5d;
    goto LAB_00654bac;
  }
  __s1 = (void *)(param_1 + 0x2e);
  iVar9 = *(int *)(param_1 + 0x50);
  iVar1 = apmngr_db_entry_get_by_mac(__s1,auStack_2f8);
  if (iVar1 == -1) {
    uVar8 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n";
    uVar7 = 0xc66;
    goto LAB_00654bac;
  }
  iVar1 = FUN_00408430(__s1);
  if (iVar1 != 0) {
LAB_00654cbc:
    uVar8 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar6 = "[APUPD_DEBUG]%32s() %05d: wtp no update task.\r\n";
    uVar7 = 0xc6e;
    goto LAB_00654bac;
  }
  if ((*(uint *)(iVar9 + 0x18) & 1) == 0) {
    if ((0x1ff < local_2e6) ||
       (uVar2 = local_2e6 + 1,
       (*(uint *)(iVar9 + (((int)uVar2 >> 5) + 6) * 4) >> (uVar2 & 0x1f) & 1) == 0))
    goto LAB_00654cbc;
    iVar1 = *(int *)(iVar9 + 0x140);
  }
  else {
    iVar1 = *(int *)(iVar9 + 0x140);
  }
  switch(iVar1) {
  case 0:
    break;
  case 1:
    if (*(int *)(iVar9 + 0x7ec) == 1) {
      *(undefined4 *)(param_1 + 0x48) = 1;
    }
    else {
      if (*(int *)(iVar9 + 0x7ec) != 2) {
        iVar1 = *(int *)(param_1 + 0x50);
        goto LAB_00654dd4;
      }
      cVar5 = *(char *)(iVar9 + 0x138);
      if ((cVar5 == '\x01') || (cVar5 == '\x03')) {
        uVar8 = 1;
        if (*(int *)(param_1 + 0x48) != 8) goto LAB_00654f80;
        if (cVar5 == '\x01') {
          iVar1 = *(int *)(param_1 + 0x50);
          goto LAB_00654dd4;
        }
        if (cVar5 == '\x03') {
          iVar1 = *(int *)(param_1 + 0x50);
          goto LAB_00654dd4;
        }
      }
      iVar1 = memcmp((void *)(param_1 + 0x38),(void *)(iVar9 + 0x1c4),0x10);
      if (iVar1 == 0) {
LAB_00654d70:
        if ((cVar5 != '\x01') && (cVar5 != '\x03')) {
          iVar1 = memcmp((void *)(param_1 + 0x38),(void *)(iVar9 + 0x1c4),0x10);
          if (iVar1 == 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          if (*(int *)(iVar9 + 300) == 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          iVar1 = apupd_db_wtp_firmware_id_match(param_1,iVar9 + 0x1d4);
          if (iVar1 != 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          if (*(char *)(iVar9 + 0x13a) == '\x01') {
            uVar8 = 8;
            if (g_apupd_debug != 0) {
              iVar1 = is_target_debug_ap();
              if (iVar1 != 0) {
                pcVar6 = 
                "[APUPD_DEBUG]%32s() %05d: large fw upgrade no check soft_ver, wtp odl state = %d\r\n"
                ;
                uVar8 = 0xc8a;
                goto LAB_00655378;
              }
              uVar8 = 8;
            }
          }
          else {
            uVar8 = 0x10;
            if (g_apupd_debug != 0) {
              iVar1 = is_target_debug_ap();
              if (iVar1 != 0) {
                uVar8 = 0xc8f;
                goto LAB_00655080;
              }
              uVar8 = 0x10;
            }
          }
          goto LAB_00654dcc;
        }
        break;
      }
      uVar8 = 1;
      if (*(int *)(iVar9 + 300) != 0) {
        iVar1 = apupd_db_wtp_firmware_id_match(param_1,iVar9 + 0x1d4);
        uVar8 = 1;
        if (iVar1 == 0) goto LAB_00654d70;
      }
LAB_00654f80:
      *(undefined4 *)(param_1 + 0x48) = uVar8;
    }
    *(int *)(iVar9 + 0x144) = *(int *)(iVar9 + 0x144) + 1;
    break;
  case 2:
  case 3:
    iVar3 = *(int *)(iVar9 + 0x7ec);
    if (iVar3 == 1) {
LAB_00654f34:
      cVar5 = *(char *)(iVar9 + 0x13a);
LAB_00654f38:
      if (cVar5 != '\0') {
        if (iVar3 == 2) {
          if (g_apupd_debug == 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          iVar1 = is_target_debug_ap(apupd_update_model_hash);
          if (iVar1 == 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          pcVar6 = 
          "[APUPD_DEBUG]%32s() %05d: large image don\'t support auto manual upgrade during wait timeout or upgrading\r\n"
          ;
          uVar8 = 0xca2;
        }
        else {
          if ((iVar3 != 1) || (iVar1 != 3)) goto LAB_00654f5c;
          if (g_apupd_debug == 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          iVar1 = is_target_debug_ap(apupd_update_model_hash);
          if (iVar1 == 0) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          pcVar6 = 
          "[APUPD_DEBUG]%32s() %05d: large image don\'t support auto online upgrade during upgrading\r\n"
          ;
          uVar8 = 0xca8;
        }
LAB_00655290:
        printf(pcVar6,"apupd_wtp_entry_add_after_handle",uVar8);
        iVar1 = *(int *)(param_1 + 0x50);
        goto LAB_00654dd4;
      }
LAB_00654f5c:
      iVar1 = FUN_00407fa0(apupd_update_model_hash,iVar9 + 0x58);
      if (iVar1 == 0) {
        uVar8 = 0xffffffff;
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar6 = "[APUPD_ERROR]%32s() %05d: get update model failed.\r\n";
        uVar7 = 0xcaf;
LAB_00654bac:
        printf(pcVar6,"apupd_wtp_entry_add_after_handle",uVar7);
        return uVar8;
      }
      iVar3 = apupd_update_wtp_entry_add_check(param_1);
      if (iVar3 == 0) {
        uVar8 = 1;
      }
      else {
        iVar1 = apupd_update_wtp_entry_add(iVar1,param_1);
        if (iVar1 == 0) {
          uVar8 = 2;
          if (*(char *)(iVar9 + 0x13a) == '\0') {
            uVar8 = 0xffffffff;
            if (g_apupd_error == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            pcVar6 = "[APUPD_ERROR]%32s() %05d: add update wtp failed.\r\n";
            uVar7 = 0xcb7;
            goto LAB_00654bac;
          }
        }
        else {
          uVar8 = 2;
        }
      }
      goto LAB_00654f80;
    }
    if (iVar3 != 2) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    cVar5 = *(char *)(iVar9 + 0x138);
    if ((cVar5 == '\x01') || (cVar5 == '\x03')) {
      if (*(int *)(param_1 + 0x48) == 8) {
        if (cVar5 == '\x01') {
          iVar1 = *(int *)(param_1 + 0x50);
          goto LAB_00654dd4;
        }
        if (cVar5 == '\x03') {
          iVar1 = *(int *)(param_1 + 0x50);
          goto LAB_00654dd4;
        }
        goto LAB_00654f14;
      }
      cVar5 = *(char *)(iVar9 + 0x13a);
      goto LAB_00654f38;
    }
LAB_00654f14:
    iVar4 = memcmp((void *)(param_1 + 0x38),(void *)(iVar9 + 0x1c4),0x10);
    if (iVar4 != 0) {
      if (*(int *)(iVar9 + 300) == 0) goto LAB_00654f34;
      iVar4 = apupd_db_wtp_firmware_id_match(param_1,iVar9 + 0x1d4);
      if (iVar4 != 0) {
        cVar5 = *(char *)(iVar9 + 0x13a);
        goto LAB_00654f38;
      }
    }
    if ((cVar5 == '\x01') || (cVar5 == '\x03')) break;
    iVar1 = memcmp((void *)(param_1 + 0x38),(void *)(iVar9 + 0x1c4),0x10);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    if (*(int *)(iVar9 + 300) == 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    iVar1 = apupd_db_wtp_firmware_id_match(param_1,iVar9 + 0x1d4);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    if (*(char *)(iVar9 + 0x13a) == '\x01') {
      uVar8 = 8;
      if (g_apupd_debug != 0) {
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          pcVar6 = 
          "[APUPD_DEBUG]%32s() %05d: large fw upgrade no check soft_ver, wtp old state = %d\r\n";
          uVar8 = 0xcc7;
          goto LAB_00655378;
        }
        uVar8 = 8;
      }
    }
    else {
      uVar8 = 0x10;
      if (g_apupd_debug != 0) {
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          uVar8 = 0xccd;
          goto LAB_00655080;
        }
        uVar8 = 0x10;
      }
    }
    goto LAB_00654dcc;
  case 4:
    iVar1 = *(int *)(iVar9 + 0x7ec);
    if (iVar1 == 1) {
LAB_00654e7c:
      cVar5 = *(char *)(iVar9 + 0x13a);
LAB_00654e80:
      if ((cVar5 == '\0') || (iVar1 != 2)) {
        memset(auStack_328,0,0x2c);
        if ((*(int *)(iVar9 + 0x13c) == -1) &&
           (iVar1 = memcmp((void *)(iVar9 + 0x150),auStack_328,0x2c), iVar1 != 0)) {
          *(undefined4 *)(iVar9 + 0x140) = 1;
          *(undefined4 *)(param_1 + 0x48) = 1;
          *(int *)(iVar9 + 0x144) = *(int *)(iVar9 + 0x144) + 1;
          iVar1 = apupd_model_entry_timer_add(iVar9);
          if (iVar1 != -1) {
            iVar1 = *(int *)(param_1 + 0x50);
            goto LAB_00654dd4;
          }
          uVar8 = 0xffffffff;
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar6 = "[APUPD_ERROR]%32s() %05d: add timer failed.\r\n";
          uVar7 = 0xceb;
        }
        else {
          uVar8 = 0xffffffff;
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar6 = "[APUPD_ERROR]%32s() %05d: some error occured.\r\n";
          uVar7 = 0xcf1;
        }
        goto LAB_00654bac;
      }
      if (g_apupd_debug == 0) {
        iVar1 = *(int *)(param_1 + 0x50);
        goto LAB_00654dd4;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x50);
        goto LAB_00654dd4;
      }
      pcVar6 = 
      "[APUPD_DEBUG]%32s() %05d: large image don\'t support auto manual upgrade after upgrade finished\r\n"
      ;
      uVar8 = 0xcde;
      goto LAB_00655290;
    }
    if (iVar1 != 2) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    cVar5 = *(char *)(iVar9 + 0x138);
    if ((cVar5 == '\x01') || (cVar5 == '\x03')) {
      if (*(int *)(param_1 + 0x48) == 8) {
        if (cVar5 == '\x01') {
          iVar1 = *(int *)(param_1 + 0x50);
          goto LAB_00654dd4;
        }
        if (cVar5 == '\x03') {
          iVar1 = *(int *)(param_1 + 0x50);
          goto LAB_00654dd4;
        }
        goto LAB_00654e5c;
      }
      cVar5 = *(char *)(iVar9 + 0x13a);
      goto LAB_00654e80;
    }
LAB_00654e5c:
    iVar3 = memcmp((void *)(param_1 + 0x38),(void *)(iVar9 + 0x1c4),0x10);
    if (iVar3 != 0) {
      if (*(int *)(iVar9 + 300) == 0) goto LAB_00654e7c;
      iVar3 = apupd_db_wtp_firmware_id_match(param_1,iVar9 + 0x1d4);
      if (iVar3 != 0) {
        cVar5 = *(char *)(iVar9 + 0x13a);
        goto LAB_00654e80;
      }
    }
    if ((cVar5 == '\x01') || (cVar5 == '\x03')) break;
    iVar1 = memcmp((void *)(param_1 + 0x38),(void *)(iVar9 + 0x1c4),0x10);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    if (*(int *)(iVar9 + 300) == 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    iVar1 = apupd_db_wtp_firmware_id_match(param_1,iVar9 + 0x1d4);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      goto LAB_00654dd4;
    }
    if (*(char *)(iVar9 + 0x13a) == '\x01') {
      uVar8 = 8;
      if (g_apupd_debug == 0) goto LAB_00654dcc;
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar8 = 8;
        goto LAB_00654dcc;
      }
      pcVar6 = 
      "[APUPD_DEBUG]%32s() %05d: large fw upgrade no check soft_ver, wtp old state = %d\r\n";
      uVar8 = 0xcfa;
LAB_00655378:
      printf(pcVar6,"apupd_wtp_entry_add_after_handle",uVar8,*(undefined4 *)(param_1 + 0x48));
      uVar8 = 8;
    }
    else {
      uVar8 = 0x10;
      if (g_apupd_debug == 0) goto LAB_00654dcc;
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar8 = 0x10;
        goto LAB_00654dcc;
      }
      uVar8 = 0xd00;
LAB_00655080:
      printf("[APUPD_DEBUG]%32s() %05d: fw not support, set wtp state\r\n",
             "apupd_wtp_entry_add_after_handle",uVar8);
      uVar8 = 0x10;
    }
LAB_00654dcc:
    *(undefined4 *)(param_1 + 0x48) = uVar8;
    break;
  default:
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: model state(%d) is invalib\r\n",
           "apupd_wtp_entry_add_after_handle",0xd08,*(undefined4 *)(iVar9 + 0x140));
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1 + 0x50);
LAB_00654dd4:
  iVar1 = FUN_004081b0(iVar1 + 0x17c);
  while (iVar9 = iVar1, iVar9 != 0) {
    iVar1 = FUN_00408680(iVar9);
    iVar3 = memcmp(__s1,(void *)(iVar9 + 0x38),6);
    if (iVar3 == 0) {
      FUN_00408500(iVar9);
      FUN_00407df0(iVar9);
    }
  }
  return 0;
}

