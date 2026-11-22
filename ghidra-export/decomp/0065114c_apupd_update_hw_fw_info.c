// func apupd_update_hw_fw_info @ 0065114c size=2668

undefined4 apupd_update_hw_fw_info(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  void *__s;
  void *__s_00;
  undefined4 uVar7;
  char *__format;
  
  bVar2 = false;
  if ((param_3 != 0) && (iVar3 = FUN_00407fa0(apupd_hwid_hash,param_3 + 0x119), iVar3 != 0)) {
    if (param_1 == 0) {
      cVar1 = *(char *)(param_3 + 0x138);
LAB_00651300:
      if (cVar1 != '\x02') {
        if (g_apupd_debug == 0) {
          uVar7 = *(undefined4 *)(iVar3 + 0x10);
        }
        else {
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            uVar7 = *(undefined4 *)(iVar3 + 0x10);
          }
          else {
            printf("[APUPD_DEBUG]%32s() %05d: delete old hw_id is %02X-%02X-%02X-%02X....\r\n",
                   "apupd_update_hw_fw_info",0xd9e,(uint)*(byte *)(param_3 + 0x119),
                   (uint)*(byte *)(param_3 + 0x11a),(uint)*(byte *)(param_3 + 0x11b),
                   (uint)*(byte *)(param_3 + 0x11c));
            uVar7 = *(undefined4 *)(iVar3 + 0x10);
          }
        }
        for (iVar4 = FUN_004081b0(uVar7); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
          iVar5 = memcmp((void *)(iVar4 + 0xc),(void *)(param_1 + 0x58),0x10);
          if (iVar5 == 0) {
            *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + -1;
            if (g_apupd_debug == 0) {
              iVar5 = *(int *)(iVar4 + 0x1c);
            }
            else {
              iVar5 = is_target_debug_ap();
              if (iVar5 == 0) {
                iVar5 = *(int *)(iVar4 + 0x1c);
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: decrease fw_id ref %02X-%02X-%02X-%02X... ref[%d].\r\n"
                       ,"apupd_update_hw_fw_info",0xda7,(uint)*(byte *)(param_1 + 0x58),
                       (uint)*(byte *)(param_1 + 0x59),(uint)*(byte *)(param_1 + 0x5a),
                       (uint)*(byte *)(param_1 + 0x5b),*(undefined4 *)(iVar4 + 0x1c));
                iVar5 = *(int *)(iVar4 + 0x1c);
              }
            }
            if (iVar5 == 0) {
              FUN_00408500(iVar4);
              FUN_00407df0(iVar4);
              bVar2 = true;
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: ref <= [%d] delete node.\r\n",
                       "apupd_update_hw_fw_info",0xdae,*(undefined4 *)(iVar4 + 0x1c));
              }
              goto LAB_00651364;
            }
            break;
          }
        }
        bVar2 = false;
LAB_00651364:
        if (g_apupd_debug == 0) {
          iVar4 = *(int *)(iVar3 + 0x10);
        }
        else {
          iVar5 = is_target_debug_ap();
          iVar4 = *(int *)(iVar3 + 0x10);
          if (iVar5 != 0) {
            printf("[APUPD_DEBUG]%32s() %05d: old_hw_fw_node->fw_id_list->size [%d].\r\n",
                   "apupd_update_hw_fw_info",0xdb5,*(undefined4 *)(iVar4 + 8));
            iVar4 = *(int *)(iVar3 + 0x10);
          }
        }
        if (*(int *)(iVar4 + 8) == 0) {
          FUN_00408500(iVar3 + -0xc);
          DAT_007cc7c4 = DAT_007cc7c4 + -1;
          if (DAT_007cc7c4 < 0) {
            DAT_007cc7c4 = 0;
          }
          if ((g_apupd_debug != 0) && (iVar4 = is_target_debug_ap(apupd_hwid_hash), iVar4 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: remove this hwid node total_hw_count[%d]\r\n",
                   "apupd_update_hw_fw_info",0xdc2,DAT_007cc7c4);
          }
          FUN_00407f40(apupd_hwid_hash,iVar3);
          if ((g_apupd_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: old_model->is_sys[%d] old_model->state[%d]\r\n",
                   "apupd_update_hw_fw_info",0xdc7,(uint)*(byte *)(param_3 + 0x139),
                   *(undefined4 *)(param_3 + 0x140));
          }
          FUN_00407df0(iVar3 + -0xc);
          bVar2 = true;
        }
        goto LAB_006511e4;
      }
    }
    else {
      iVar4 = apupd_check_from_vap
                        (*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                         *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                         *(undefined4 *)(param_1 + 0x28));
      if (iVar4 == 0) {
        cVar1 = *(char *)(param_3 + 0x138);
        goto LAB_00651300;
      }
    }
    bVar2 = false;
    if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: old_wtp is from vap(or maybe sensor) ,just ignore \r\n",
             "apupd_update_hw_fw_info",0xd9a);
    }
  }
LAB_006511e4:
  if ((param_4 == 0) || (param_2 == 0)) {
LAB_006512c0:
    if (!bVar2) {
      return 0;
    }
  }
  else {
    iVar3 = FUN_00407fa0(apupd_hwid_hash,param_4 + 0x119);
    if (iVar3 != 0) {
      if (g_apupd_debug == 0) {
        uVar7 = *(undefined4 *)(param_2 + 0x28);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          uVar7 = *(undefined4 *)(param_2 + 0x28);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: add new hw_id is %02X-%02X-%02X-%02X....\r\n",
                 "apupd_update_hw_fw_info",0xdd6,(uint)*(byte *)(param_4 + 0x119),
                 (uint)*(byte *)(param_4 + 0x11a),(uint)*(byte *)(param_4 + 0x11b),
                 (uint)*(byte *)(param_4 + 0x11c));
          uVar7 = *(undefined4 *)(param_2 + 0x28);
        }
      }
      iVar4 = apupd_check_from_vap
                        (*(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                         *(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),uVar7);
      if ((iVar4 == 0) && (*(char *)(param_4 + 0x138) != '\x02')) {
        for (iVar4 = FUN_004081b0(*(undefined4 *)(iVar3 + 0x10)); iVar4 != 0;
            iVar4 = FUN_00408680(iVar4)) {
          iVar5 = memcmp((void *)(iVar4 + 0xc),(void *)(param_2 + 0x58),0x10);
          if (iVar5 == 0) {
            *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
            if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: already exist fw_id is %02X-%02X-%02X-%02X... ref++.\r\n"
                     ,"apupd_update_hw_fw_info",0xde2,(uint)*(byte *)(param_2 + 0x58),
                     (uint)*(byte *)(param_2 + 0x59),(uint)*(byte *)(param_2 + 0x5a),
                     (uint)*(byte *)(param_2 + 0x5b));
            }
            goto LAB_006512c0;
          }
        }
        pvVar6 = (void *)FUN_00408450(0x20,0xdea);
        if (pvVar6 != (void *)0x0) {
          memset(pvVar6,0,0x20);
          memcpy((void *)((int)pvVar6 + 0xc),(void *)(param_2 + 0x58),0x10);
          *(undefined4 *)((int)pvVar6 + 0x1c) = 1;
          if (g_apupd_debug == 0) {
            uVar7 = *(undefined4 *)(iVar3 + 0x10);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              uVar7 = *(undefined4 *)(iVar3 + 0x10);
            }
            else {
              printf("[APUPD_DEBUG]%32s() %05d: new fw_id is %02X-%02X-%02X-%02X... ref++.\r\n",
                     "apupd_update_hw_fw_info",0xdf1,(uint)*(byte *)(param_2 + 0x58),
                     (uint)*(byte *)(param_2 + 0x59),(uint)*(byte *)(param_2 + 0x5a),
                     (uint)*(byte *)(param_2 + 0x5b));
              uVar7 = *(undefined4 *)(iVar3 + 0x10);
            }
          }
          FUN_004086b0(uVar7,pvVar6);
          goto LAB_00651424;
        }
      }
      else if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        uVar7 = 0xdf9;
LAB_006512b8:
        printf("[APUPD_DEBUG]%32s() %05d: new_wtp is from vap(or sensor),just ignore\r\n",
               "apupd_update_hw_fw_info",uVar7);
      }
      goto LAB_006512c0;
    }
    if (g_apupd_debug == 0) {
      uVar7 = *(undefined4 *)(param_2 + 0x28);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        uVar7 = *(undefined4 *)(param_2 + 0x28);
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: new model.\r\n","apupd_update_hw_fw_info",0xe04);
        uVar7 = *(undefined4 *)(param_2 + 0x28);
      }
    }
    iVar3 = apupd_check_from_vap
                      (*(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),uVar7);
    if ((iVar3 != 0) || (*(char *)(param_4 + 0x138) == '\x02')) {
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        uVar7 = 0xe54;
        goto LAB_006512b8;
      }
      goto LAB_006512c0;
    }
    pvVar6 = (void *)FUN_00408450(0x20,0xe09);
    if (pvVar6 == (void *)0x0) {
      if (g_apupd_error == 0) {
        return 0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      __format = "[APUPD_ERROR]%32s() %05d: create tmp_hw_fw_list_node failed.\r\n";
      uVar7 = 0xe0c;
      goto LAB_006514b8;
    }
    memset(pvVar6,0,0x20);
    memcpy((void *)((int)pvVar6 + 0xc),(void *)(param_4 + 0x119),0x10);
    if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(0x20), iVar3 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: hw_id is %02X-%02X-%02X-%02X....\r\n",
             "apupd_update_hw_fw_info",0xe12,(uint)*(byte *)(param_4 + 0x119),
             (uint)*(byte *)(param_4 + 0x11a),(uint)*(byte *)(param_4 + 0x11b),
             (uint)*(byte *)(param_4 + 0x11c));
    }
    __s = (void *)FUN_00408450(0x20,0xe14);
    if (__s == (void *)0x0) {
      FUN_00407df0(pvVar6);
      if (g_apupd_error == 0) {
        return 0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      __format = "[APUPD_ERROR]%32s() %05d: uac_mem_malloc failed.\r\n";
      uVar7 = 0xe19;
      goto LAB_006514b8;
    }
    memset(__s,0,0x20);
    memcpy((void *)((int)__s + 0xc),(void *)(param_2 + 0x58),0x10);
    *(undefined4 *)((int)__s + 0x1c) = 1;
    if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(0xc), iVar3 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: fw_id is %02X-%02X-%02X-%02X....\r\n",
             "apupd_update_hw_fw_info",0xe1f,(uint)*(byte *)(param_2 + 0x58),
             (uint)*(byte *)(param_2 + 0x59),(uint)*(byte *)(param_2 + 0x5a),
             (uint)*(byte *)(param_2 + 0x5b));
    }
    __s_00 = (void *)FUN_00408450(0xc,0xe21);
    *(void **)((int)pvVar6 + 0x1c) = __s_00;
    if (__s_00 == (void *)0x0) {
      if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: create tmp_hw_fw_node.fw_id_list failed.\r\n",
               "apupd_update_hw_fw_info",0xe24);
      }
      FUN_00407df0(pvVar6);
LAB_006517ac:
      FUN_00407df0(__s);
      return 0;
    }
    memset(__s_00,0,0xc);
    FUN_0051ad88(*(undefined4 *)((int)pvVar6 + 0x1c));
    FUN_004086b0(*(undefined4 *)((int)pvVar6 + 0x1c),__s);
    if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: fw_id_list size is %d \r\n","apupd_update_hw_fw_info",0xe2e,
             *(undefined4 *)(*(int *)((int)pvVar6 + 0x1c) + 8));
    }
    FUN_004086b0(&apupd_report_upgrade_info,pvVar6);
    DAT_007cc7c4 = DAT_007cc7c4 + 1;
    if (DAT_007cc7c8 != -1) {
      FUN_00408060();
      DAT_007cc7c8 = -1;
    }
    DAT_007cc7c8 = FUN_00408340(g_apupd_report_interval,0,apupd_timer_report_hw_fw_to_cloud,0,0,
                                "apupd_update_hw_fw_info",0xe3b);
    if (((DAT_007cc7c8 == -1) && (g_apupd_error != 0)) &&
       (iVar3 = is_target_debug_ap(apupd_hwid_hash), iVar3 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n",
             "apupd_update_hw_fw_info",0xe3e);
    }
    iVar3 = FUN_00408380(apupd_hwid_hash,(int)pvVar6 + 0xc);
    if (iVar3 != 0) {
      if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: uac_hash_add failed.\r\n","apupd_update_hw_fw_info",0xe45)
        ;
      }
      FUN_00407df0(__s);
      FUN_00407df0(*(undefined4 *)((int)pvVar6 + 0x1c));
      *(undefined4 *)((int)pvVar6 + 0x1c) = 0;
      __s = pvVar6;
      goto LAB_006517ac;
    }
  }
LAB_00651424:
  if (DAT_007cc7c8 != -1) {
    FUN_00408060();
    DAT_007cc7c8 = -1;
  }
  DAT_007cc7c8 = FUN_00408340(g_apupd_report_interval,0,apupd_timer_report_hw_fw_to_cloud,0,0,
                              "apupd_update_hw_fw_info",0xe63);
  if (DAT_007cc7c8 != -1) {
    return 0;
  }
  if (g_apupd_error == 0) {
    return 0;
  }
  iVar3 = is_target_debug_ap();
  if (iVar3 == 0) {
    return 0;
  }
  uVar7 = 0xe66;
  __format = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
LAB_006514b8:
  printf(__format,"apupd_update_hw_fw_info",uVar7);
  return 0;
}

