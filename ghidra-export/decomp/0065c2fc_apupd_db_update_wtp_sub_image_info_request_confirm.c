// func apupd_db_update_wtp_sub_image_info_request_confirm @ 0065c2fc size=1196

undefined4 apupd_db_update_wtp_sub_image_info_request_confirm(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_v1;
  char *pcVar3;
  void *__src;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: receive sub image info\r\n",
           "apupd_db_update_wtp_sub_image_info_request_confirm",0x23df);
  }
  memset(auStack_2f8,0,0x2d8);
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  memset(auStack_2f8,0,0x2d8);
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n",
           "apupd_db_update_wtp_sub_image_info_request_confirm",0x23ec);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_0065c58c;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: get update wtp by mac failed.\r\n";
    uVar4 = 0x23f6;
LAB_0065c764:
    printf(pcVar3,"apupd_db_update_wtp_sub_image_info_request_confirm",uVar4);
  }
  else {
    iVar6 = *(int *)(*(int *)(iVar1 + 0x34) + 0x10);
    iVar2 = apmngr_db_entry_get_by_mac(param_1,auStack_2f8);
    if (iVar2 != 0) {
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get ap_entry by mac[%02X:%02X:%02X:%02X:%02X:%02X] failed.\r\n"
               ,"apupd_db_update_wtp_sub_image_info_request_confirm",0x23fe,
               (uint)*(byte *)(iVar1 + 0x18),(uint)*(byte *)(iVar1 + 0x19),
               (uint)*(byte *)(iVar1 + 0x1a),(uint)*(byte *)(iVar1 + 0x1b),
               (uint)*(byte *)(iVar1 + 0x1c),(uint)*(byte *)(iVar1 + 0x1d));
      }
      goto LAB_0065c58c;
    }
    if (*(int *)(iVar1 + 0x20) == 1) {
      if (*(int *)(iVar1 + 0x24) == 4) {
        if (*(int *)(iVar6 + 0x7ec) == 1) {
LAB_0065c5e0:
          iVar2 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x2c),
                               *(int *)(iVar1 + 0x30) + 0x58);
          if (iVar2 != 0) {
            cVar7 = *(char *)(iVar2 + 400);
            iVar8 = *(int *)(iVar2 + 0x44);
            __src = (void *)(iVar2 + 0x4c);
            goto LAB_0065c3fc;
          }
          iVar8 = 0;
          cVar7 = '\0';
        }
        else {
          if (*(int *)(iVar6 + 0x7ec) == 3) {
            if (*(int *)(*(int *)(iVar1 + 0x30) + 0x54) == 1) goto LAB_0065c5e0;
            cVar7 = *(char *)(iVar6 + 0x1a0);
          }
          else {
            cVar7 = *(char *)(iVar6 + 0x1a0);
          }
          iVar8 = *(int *)(iVar6 + 0x1ac);
          __src = (void *)(iVar6 + 0x1b4);
LAB_0065c3fc:
          memcpy(&local_308,__src,0x10);
        }
        if ((((*param_2 != '\0') || (param_2[1] != cVar7)) || (iVar8 != *(int *)(param_2 + 4))) ||
           (iVar2 = memcmp(&local_308,param_2 + 8,0x10), iVar2 != 0)) {
          if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: AP[%d] sub image info error,stop update\r\n",
                   "apupd_db_update_wtp_sub_image_info_request_confirm",0x2424,(uint)local_2e8);
          }
          *(undefined4 *)(iVar1 + 0x24) = 6;
          *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x48) = 0x18;
          apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
          iVar2 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar1 + 0x30),9);
          if (((iVar2 == -1) || (iVar1 = apupd_update_wtp_entry_delete(iVar1), iVar1 == -1)) &&
             ((g_apupd_error != 0 && (iVar1 = is_target_debug_ap(local_2e8), iVar1 != 0)))) {
            printf("[APUPD_ERROR]%32s() %05d: add log or del update wtp failed.\r\n",
                   "apupd_db_update_wtp_sub_image_info_request_confirm",0x242a);
          }
          apmngr_db_ap_run_state_update(local_2e8,2);
          goto LAB_0065c58c;
        }
        *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x4c) = 0;
        iVar2 = apupd_update_wtp_image_request_send(iVar1);
        if (iVar2 != -1) {
          if (*(int *)(iVar1 + 0x28) != -1) {
            FUN_00408060();
            *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
          }
          *(undefined4 *)(iVar1 + 0x20) = 3;
          *(undefined4 *)(iVar1 + 0x24) = 5;
          FUN_00407e70();
          uVar4 = apupd_db_mutex;
          *(undefined4 *)(iVar1 + 0x2c) = extraout_v1;
          FUN_00407f30(uVar4);
          return 0;
        }
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
        goto LAB_0065c58c;
        pcVar3 = "[APUPD_ERROR]%32s() %05d: send image request failed.\r\n";
        uVar4 = 0x2433;
        goto LAB_0065c764;
      }
      if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
      goto LAB_0065c58c;
      uVar5 = *(undefined4 *)(iVar1 + 0x24);
      pcVar3 = "[APUPD_ERROR]%32s() %05d: update wtp large_image_update_state(%d) is invalib\r\n";
      uVar4 = 0x240a;
    }
    else {
      if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
      goto LAB_0065c58c;
      uVar5 = *(undefined4 *)(iVar1 + 0x20);
      pcVar3 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) is invalib\r\n";
      uVar4 = 0x2405;
    }
    printf(pcVar3,"apupd_db_update_wtp_sub_image_info_request_confirm",uVar4,uVar5);
  }
LAB_0065c58c:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

