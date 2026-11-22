// func acpdt_capwap_callback_join_reqeust_listen @ 00665734 size=2204

undefined4 acpdt_capwap_callback_join_reqeust_listen(int param_1,byte *param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  void *__src;
  void *__s;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_504;
  int local_500;
  char local_4fc [20];
  int local_4e8 [16];
  undefined1 auStack_4a8 [68];
  undefined1 auStack_464 [16];
  int local_454;
  char acStack_38a [65];
  char local_349 [81];
  undefined1 auStack_2f8 [64];
  int local_2b8;
  
  local_500 = 0;
  local_504 = 0;
  memset(auStack_2f8,0,0x2d8);
  local_4fc[0] = '\0';
  local_4fc[1] = '\0';
  local_4fc[2] = '\0';
  local_4fc[3] = '\0';
  local_4fc[4] = '\0';
  local_4fc[5] = '\0';
  local_4fc[6] = '\0';
  local_4fc[7] = '\0';
  local_4fc[8] = '\0';
  local_4fc[9] = '\0';
  local_4fc[10] = '\0';
  local_4fc[0xb] = '\0';
  local_4fc[0xc] = '\0';
  local_4fc[0xd] = '\0';
  local_4fc[0xe] = '\0';
  local_4fc[0xf] = '\0';
  local_4fc[0x10] = '\0';
  local_4fc[0x11] = '\0';
  local_4fc[0x12] = '\0';
  local_4fc[0x13] = '\0';
  memset(auStack_464,0,0x168);
  memset(auStack_4a8,0,0x42);
  if (((param_1 == 0) || (param_2 == (byte *)0x0)) || (param_3 == 0)) {
    uVar10 = 0xffffffff;
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    pcVar8 = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
    uVar9 = 0x27e;
LAB_006658b8:
    printf(pcVar8,"acpdt_capwap_callback_join_reqeust_listen",uVar9);
    return uVar10;
  }
  piVar2 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    uVar10 = 0;
    if (g_acpdt_debug == 0) {
      return 0;
    }
    pcVar8 = 
    "[ACPDT_DEBUG] %32s() %05d: Failed to join for formal callback return failed result code.\r\n";
    uVar9 = 0x285;
    goto LAB_006658b8;
  }
  __src = (void *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x5b);
  __s = (void *)FUN_00408450(0x10,0x28a);
  if (__s == (void *)0x0) {
    uVar10 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar8 = "[APMNGR_ERROR]%s()/%d malloc error\n";
    uVar9 = 0x28c;
    goto LAB_006658b8;
  }
  if (__src == (void *)0x0) {
    memset(__s,0xff,0x10);
  }
  else {
    memcpy(__s,__src,0x10);
  }
  iVar3 = cw_sub_msg_ele_get(param_1,0x27,0);
  if ((iVar3 == 0) || (*(ushort *)(iVar3 + 0x12) < 4)) {
    uVar10 = 0xffffffff;
    if (g_acpdt_error == 0) goto LAB_00665888;
    pcVar8 = "[ACPDT_ERROR] %32s() %05d: get hardware version failed.\r\n";
    uVar9 = 0x29c;
  }
  else {
    local_504 = **(undefined4 **)(iVar3 + 0x14);
    iVar3 = cw_sub_msg_ele_get(param_1,0x26,0);
    if ((iVar3 == 0) || (*(short *)(iVar3 + 0xe) != 4)) {
      uVar10 = 0xffffffff;
      if (g_acpdt_error == 0) goto LAB_00665888;
      pcVar8 = "[ACPDT_ERROR] %32s() %05d: get model number failed.\r\n";
      uVar9 = 0x2a8;
    }
    else {
      memcpy(&local_500,*(void **)(iVar3 + 0x10),4);
      if (local_500 == 0) {
        iVar3 = cw_sub_msg_ele_get(param_1,0x26,9);
        if (iVar3 != 0) {
          uVar4 = (uint)*(ushort *)(iVar3 + 0xe);
          if (uVar4 != 0) {
            if (0x41 < uVar4) {
              uVar10 = 0xffffffff;
              if (g_acpdt_error == 0) goto LAB_00665888;
              pcVar8 = "[ACPDT_ERROR] %32s() %05d: Illegal model number.\r\n";
              uVar9 = 0x2c3;
              goto LAB_00665970;
            }
            memcpy(auStack_4a8,*(void **)(iVar3 + 0x10),uVar4);
            iVar3 = apdb_get_ap_by_name_and_hwver(auStack_4a8,&local_504,auStack_464);
            if (iVar3 == 0) {
              local_500 = local_454;
            }
            goto LAB_006659e8;
          }
        }
        iVar3 = apmngr_db_entry_get_by_mac(param_2,auStack_2f8);
        if (iVar3 == 0) {
          local_500 = local_2b8;
          goto LAB_006659e8;
        }
LAB_00665af8:
        iVar3 = 1;
        bVar1 = false;
      }
      else {
LAB_006659e8:
        if (local_500 == 0) {
          uVar4 = (uint)param_2[1];
LAB_00665a04:
          snprintf(local_4fc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_2,uVar4,
                   (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
          memset(local_4e8,0,0x40);
          FUN_00408190(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                       *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),local_4e8,0x40,"---");
          piVar2 = local_4e8;
          if (param_2[0xc] != 0) {
            piVar2 = (int *)0x6bb290;
          }
          loggerk_reg(0x53,0x3cf6,1,piVar2,1,local_4fc,4,local_500,2,(int)local_504._0_2_,2,
                      (int)local_504._2_2_,0);
          if (g_acpdt_debug != 0) {
            printf("[ACPDT_DEBUG] %32s() %05d: model(%d) is uncognised or hardware version(%d.%d) is uncognised.\r\n"
                   ,"acpdt_capwap_callback_join_reqeust_listen",0x2df,local_500,(int)local_504._0_2_
                   ,(int)local_504._2_2_);
          }
          goto LAB_00665af8;
        }
        iVar3 = apdb_id_valid();
        if (iVar3 == 0) {
          uVar4 = (uint)param_2[1];
          goto LAB_00665a04;
        }
        iVar3 = apdb_hwver_exist_by_id(local_500,&local_504);
        if (iVar3 == 0) {
          uVar4 = (uint)param_2[1];
          goto LAB_00665a04;
        }
        uVar4 = apdb_radio_count_by_id(local_500,__s);
        uVar7 = rdmngr_profile_get_max_rd_per_ap();
        if (uVar7 < uVar4) {
          snprintf(local_4fc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_2,(uint)param_2[1],
                   (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
          iVar3 = apdb_get_ap_by_id(local_500,__s,auStack_464);
          if (iVar3 != 0) {
            uVar10 = 0xffffffff;
            if (g_acpdt_error == 0) goto LAB_00665888;
            pcVar8 = "[ACPDT_ERROR] %32s() %05d: get apdb failed.\r\n";
            uVar9 = 0x2e9;
            goto LAB_00665970;
          }
          memset(local_4e8,0,0x40);
          FUN_00408190(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                       *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),local_4e8,0x40,"---");
          pcVar8 = local_349;
          if (local_349[0] == '\0') {
            pcVar8 = acStack_38a;
          }
          piVar2 = local_4e8;
          if (param_2[0xc] != 0) {
            piVar2 = (int *)0x6bb290;
          }
          loggerk_reg(0x53,0x3cf6,1,piVar2,1,local_4fc,1,pcVar8,2,(int)local_504._0_2_,2,
                      (int)local_504._2_2_,0);
          if (g_acpdt_debug != 0) {
            printf("[ACPDT_DEBUG] %32s() %05d: model(%d) is unsupported because rd num for the model is too big.\r\n"
                   ,"acpdt_capwap_callback_join_reqeust_listen",0x2f6,local_500);
          }
          iVar3 = 1;
          bVar1 = true;
        }
        else {
          iVar3 = 0;
          bVar1 = true;
        }
      }
      piVar2 = (int *)cw_msg_ele_val_get(param_3,0x21);
      if (piVar2 == (int *)0x0) {
        local_4e8[0] = iVar3;
        iVar6 = cw_service_msg_add(param_3,0x21,local_4e8,0);
        if (iVar6 == -1) {
          if (g_acpdt_error != 0) {
            printf("[ACPDT_ERROR] %32s() %05d: add result code failed.\r\n","acpdt_result_code_add",
                   0xfe);
          }
          uVar10 = 0xffffffff;
          if (g_acpdt_error == 0) goto LAB_00665888;
          pcVar8 = "[ACPDT_ERROR] %32s() %05d: add result code failed.\r\n";
          uVar9 = 0x300;
          goto LAB_00665970;
        }
      }
      else {
        *piVar2 = iVar3;
      }
      pcVar8 = g_acpdt_info;
      uVar10 = 0;
      if (iVar3 != 0) goto LAB_00665888;
      sVar5 = strlen(g_acpdt_info);
      iVar3 = acpdt_ac_name_add(param_3,pcVar8,sVar5 & 0xffff);
      if (iVar3 == -1) {
        uVar10 = 0xffffffff;
        if (g_acpdt_error == 0) goto LAB_00665888;
        pcVar8 = "[ACPDT_ERROR] %32s() %05d: add ac name to parsed packet failed.\r\n";
        uVar9 = 0x30f;
      }
      else {
        iVar3 = acpdt_ac_descriptor_add(param_3,g_acpdt_info);
        if (iVar3 == -1) {
          uVar10 = 0xffffffff;
          if (g_acpdt_error == 0) goto LAB_00665888;
          pcVar8 = "[ACPDT_ERROR] %32s() %05d: add ac descriptor to parsed packet failed.\r\n";
          uVar9 = 0x317;
        }
        else {
          local_4e8[0] = CONCAT13(g_acpdt_info[0xaf],local_4e8[0]._1_3_);
          iVar3 = cw_service_msg_add(param_3,0x35,local_4e8,0);
          if (iVar3 == -1) {
            if (g_acpdt_error != 0) {
              printf("[ACPDT_ERROR] %32s() %05d: add ecn support failed.\r\n",
                     "acpdt_ecn_support_add",0xe6);
            }
            uVar10 = 0xffffffff;
            if (g_acpdt_error == 0) goto LAB_00665888;
            pcVar8 = "[ACPDT_ERROR] %32s() %05d: add ecn support to parsed packet failed.\r\n";
            uVar9 = 799;
          }
          else {
            local_4e8[0] = -0x3f57fe03;
            iVar3 = cw_service_msg_add(param_3,0x1e,local_4e8,0);
            if (iVar3 == -1) {
              if (g_acpdt_error != 0) {
                printf("[ACPDT_ERROR] %32s() %05d: add local ipv4 failed.\r\n",
                       "acpdt_capwap_local_ipv4_add",0x1a5);
              }
              uVar10 = 0xffffffff;
              if (g_acpdt_error == 0) goto LAB_00665888;
              pcVar8 = "[ACPDT_ERROR] %32s() %05d: add ecn support to parsed packet failed.\r\n";
              uVar9 = 0x327;
            }
            else {
              uVar9 = apmngr_db_active_ap_num_get();
              iVar3 = FUN_00665344(param_3,uVar9);
              if (iVar3 == -1) {
                uVar10 = 0xffffffff;
                if (g_acpdt_error == 0) goto LAB_00665888;
                pcVar8 = "[ACPDT_ERROR] %32s() %05d: add ecn support to parsed packet failed.\r\n";
                uVar9 = 0x330;
              }
              else {
                if (((!bVar1) ||
                    (iVar3 = acpdt_wtp_radio_information_list_add(param_3,local_500,__s),
                    iVar3 != -1)) || (uVar10 = 0xffffffff, g_acpdt_error == 0)) goto LAB_00665888;
                pcVar8 = "[ACPDT_ERROR] %32s() %05d: add wtp radio information failed.\r\n";
                uVar9 = 0x33a;
              }
            }
          }
        }
      }
    }
  }
LAB_00665970:
  uVar10 = 0xffffffff;
  printf(pcVar8,"acpdt_capwap_callback_join_reqeust_listen",uVar9);
LAB_00665888:
  FUN_00407df0(__s);
  return uVar10;
}

