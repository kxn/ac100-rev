// func apupd_db_update_wtp_large_image_info_request_confirm @ 0065f61c size=1484

undefined4 apupd_db_update_wtp_large_image_info_request_confirm(int param_1,byte *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  byte bVar5;
  int iVar4;
  undefined4 extraout_v1;
  char *__format;
  void *__src;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  
  if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: receive large image info\r\n",
           "apupd_db_update_wtp_large_image_info_request_confirm",0x2367);
  }
  memset(auStack_300,0,0x2d8);
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  memset(auStack_300,0,0x2d8);
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n",
           "apupd_db_update_wtp_large_image_info_request_confirm",0x2375);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar2 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar2 == 0) {
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get update wtp by mac failed.\r\n",
             "apupd_db_update_wtp_large_image_info_request_confirm",0x237f);
    }
    goto LAB_0065f958;
  }
  iVar8 = *(int *)(*(int *)(iVar2 + 0x34) + 0x10);
  iVar3 = apmngr_db_entry_get_by_mac(param_1,auStack_300);
  if (iVar3 != 0) {
    if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(apupd_db_mutex), iVar3 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get ap_entry by mac[%02X:%02X:%02X:%02X:%02X:%02X] failed.\r\n"
             ,"apupd_db_update_wtp_large_image_info_request_confirm",0x2386,
             (uint)*(byte *)(iVar2 + 0x18),(uint)*(byte *)(iVar2 + 0x19),
             (uint)*(byte *)(iVar2 + 0x1a),(uint)*(byte *)(iVar2 + 0x1b),
             (uint)*(byte *)(iVar2 + 0x1c),(uint)*(byte *)(iVar2 + 0x1d));
    }
    goto LAB_0065f958;
  }
  if (*(int *)(iVar2 + 0x20) == 1) {
    if (*(int *)(iVar2 + 0x24) == 1) {
      if (*(int *)(iVar8 + 0x7ec) == 1) {
LAB_0065f9e8:
        iVar3 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x2c),
                             *(int *)(iVar2 + 0x30) + 0x58);
        if (iVar3 != 0) {
          uVar9 = *(uint *)(iVar3 + 0x178);
          uVar10 = *(uint *)(iVar3 + 0x194);
          __src = (void *)(iVar3 + 0x180);
          iVar3 = *(int *)(iVar3 + 0x17c);
          goto LAB_0065f724;
        }
        iVar3 = 0;
        uVar10 = 0;
        uVar9 = 0;
      }
      else {
        if (*(int *)(iVar8 + 0x7ec) == 3) {
          if (*(int *)(*(int *)(iVar2 + 0x30) + 0x54) == 1) goto LAB_0065f9e8;
          uVar9 = *(uint *)(iVar8 + 0x188);
        }
        else {
          uVar9 = *(uint *)(iVar8 + 0x188);
        }
        uVar10 = *(uint *)(iVar8 + 0x1a4);
        __src = (void *)(iVar8 + 400);
        iVar3 = *(int *)(iVar8 + 0x18c);
LAB_0065f724:
        memcpy(&local_310,__src,0x10);
      }
      if ((g_apupd_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: model total_image_size = %d, total_image_piece = %d, \r\n"
               ,"apupd_db_update_wtp_large_image_info_request_confirm",0x23a8,uVar9,iVar3);
      }
      if (g_apupd_debug == 0) {
        bVar5 = *param_2;
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          bVar5 = *param_2;
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: wtp is_info = %d, total_image_size = %d, total_image_piece = %d, \r\n"
                 ,"apupd_db_update_wtp_large_image_info_request_confirm",0x23a9,(uint)*param_2,
                 *(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8));
          bVar5 = *param_2;
        }
      }
      if ((((bVar5 != 0) || (uVar9 != *(uint *)(param_2 + 4))) || (iVar3 != *(int *)(param_2 + 8)))
         || (iVar3 = memcmp(&local_310,param_2 + 0xc,0x10), iVar3 != 0)) {
        if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: AP[%d] large image info error,stop update\r\n",
                 "apupd_db_update_wtp_large_image_info_request_confirm",0x23af,(uint)local_2f0);
        }
        *(undefined4 *)(iVar2 + 0x24) = 3;
        *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x48) = 0x17;
        apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
        iVar3 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar2 + 0x30),8);
        if ((((iVar3 == -1) || (iVar2 = apupd_update_wtp_entry_delete(iVar2), iVar2 == -1)) &&
            (g_apupd_error != 0)) && (iVar2 = is_target_debug_ap(local_2f0), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: add log or del update wtp failed.\r\n",
                 "apupd_db_update_wtp_large_image_info_request_confirm",0x23b5);
        }
        apmngr_db_ap_run_state_update(local_2f0,2);
        goto LAB_0065f958;
      }
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined4 *)(iVar2 + 0x24) = 2;
      FUN_00407e70();
      *(undefined4 *)(iVar2 + 0x2c) = extraout_v1;
      if (*(int *)(iVar2 + 0x28) != -1) {
        FUN_00408060();
        *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;
      }
      *(int *)(iVar8 + 0x1a8) = *(int *)(iVar8 + 0x1a8) + 1;
      if (g_apupd_debug == 0) {
        iVar3 = *(int *)(iVar8 + 0x1a8);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar8 + 0x1a8);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: model_id = %d, reply_num = %d, need_update = %d, total_image_size = %d, got_image_size = %d\r\n"
                 ,"apupd_db_update_wtp_large_image_info_request_confirm",0x23c4,
                 *(undefined4 *)(iVar8 + 0x58),*(undefined4 *)(iVar8 + 0x1a8),
                 *(undefined4 *)(iVar8 + 0x144),uVar9,uVar10);
          iVar3 = *(int *)(iVar8 + 0x1a8);
        }
      }
      if ((iVar3 != *(int *)(iVar8 + 0x144)) || (uVar9 <= uVar10)) goto LAB_0065f7d0;
      if (*(int *)(iVar8 + 0x7ec) == 1) {
LAB_0065faec:
        *(undefined4 *)(iVar8 + 0x1a8) = 0;
        apupd_db_send_sub_image_info_to_update_wtp(*(undefined4 *)(iVar8 + 0x58));
      }
      else {
        if (*(int *)(iVar8 + 0x7ec) == 3) {
          if (*(int *)(*(int *)(iVar2 + 0x30) + 0x54) == 1) goto LAB_0065faec;
          uVar1 = *(undefined1 *)(iVar8 + 0x1a0);
        }
        else {
          uVar1 = *(undefined1 *)(iVar8 + 0x1a0);
        }
        *(undefined4 *)(iVar8 + 0x1a8) = 0;
        apupd_db_send_sub_action_to_update_wtp(*(undefined4 *)(iVar8 + 0x58),5,uVar1,0);
      }
LAB_0065f7d0:
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(apupd_db_mutex), iVar3 == 0))
    goto LAB_0065f958;
    uVar7 = *(undefined4 *)(iVar2 + 0x24);
    __format = "[APUPD_ERROR]%32s() %05d: update wtp large_image_update_state(%d) is invalib\r\n";
    uVar6 = 0x2392;
  }
  else {
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(apupd_db_mutex), iVar3 == 0))
    goto LAB_0065f958;
    uVar7 = *(undefined4 *)(iVar2 + 0x20);
    __format = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) is invalib\r\n";
    uVar6 = 0x238d;
  }
  printf(__format,"apupd_db_update_wtp_large_image_info_request_confirm",uVar6,uVar7);
LAB_0065f958:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

