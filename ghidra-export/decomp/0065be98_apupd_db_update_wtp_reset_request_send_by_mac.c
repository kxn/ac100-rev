// func apupd_db_update_wtp_reset_request_send_by_mac @ 0065be98 size=1124

undefined4 apupd_db_update_wtp_reset_request_send_by_mac(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 auStack_180 [64];
  char acStack_140 [128];
  undefined1 auStack_c0 [160];
  
  if ((param_1 == 0) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n",
           "apupd_db_update_wtp_reset_request_send_by_mac",0x2530);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar2 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar2 == 0) {
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065c1a0;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get update wtp failed.\r\n";
    uVar6 = 0x253a;
    goto LAB_0065c194;
  }
  iVar7 = *(int *)(iVar2 + 0x30);
  if (*(int *)(iVar2 + 0x20) == 3) {
    if ((*(int *)(iVar7 + 0x48) == 6) || (*(int *)(iVar7 + 0x48) == 0x16)) {
      cVar1 = *(char *)(*(int *)(iVar7 + 0x50) + 0x138);
      if ((cVar1 == '\x01') || (cVar1 == '\x03')) {
        *(int *)(iVar7 + 0x48) = param_2;
        apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
        uVar6 = apmngr_db_get_id_by_mac(iVar2 + 0x18);
        apmngr_db_ap_run_state_update(uVar6,2);
        memset(acStack_140,0,0x80);
        sprintf(acStack_140,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar2 + 0x18),
                (uint)*(byte *)(iVar2 + 0x19),(uint)*(byte *)(iVar2 + 0x1a),
                (uint)*(byte *)(iVar2 + 0x1b),(uint)*(byte *)(iVar2 + 0x1c),
                (uint)*(byte *)(iVar2 + 0x1d));
        memset(auStack_180,0,0x40);
        memset(auStack_c0,0,0x9a);
        iVar3 = *(int *)(iVar2 + 0x30);
        FUN_00408190(*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                     *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),
                     *(undefined4 *)(iVar3 + 0x28),auStack_180,0x40,"---");
        uVar6 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(iVar7 + 0x50) + 0x138));
        uVar4 = FUN_006505b0(iVar2 + 0x18,auStack_c0);
        uVar8 = 1;
        loggerk_reg(0x54,0x3817,1,uVar6,1,uVar4,1,auStack_180,1,acStack_140,0);
        if ((param_2 != 0xf) && (*(int *)(*(int *)(iVar7 + 0x50) + 0x7ec) != 3)) {
          if (param_2 != 10) {
            uVar8 = 7;
          }
          iVar7 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar2 + 0x30),uVar8);
          if (iVar7 == -1) {
            if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
            goto LAB_0065c1a0;
            pcVar5 = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
            uVar6 = 0x255d;
            goto LAB_0065c194;
          }
        }
        iVar2 = apupd_update_wtp_entry_delete(iVar2);
        if (iVar2 != -1) {
LAB_0065bf70:
          FUN_00407f30(apupd_db_mutex);
          return 0;
        }
        if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
        goto LAB_0065c1a0;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
        uVar6 = 0x2562;
      }
      else {
        if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(iVar7 + 0x2e), iVar2 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_reset_request_send\r\n",
                 "apupd_db_update_wtp_reset_request_send_by_mac",0x2569);
        }
        iVar2 = FUN_00650298(iVar7 + 0x2e,iVar7 + 0x38);
        if (iVar2 != -1) goto LAB_0065bf70;
        if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
        goto LAB_0065c1a0;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: send reset request failed.\r\n";
        uVar6 = 0x256c;
      }
LAB_0065c194:
      printf(pcVar5,"apupd_db_update_wtp_reset_request_send_by_mac",uVar6);
      goto LAB_0065c1a0;
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065c1a0;
    uVar4 = *(undefined4 *)(iVar7 + 0x48);
    pcVar5 = "[APUPD_ERROR]%32s() %05d: wtp satte(%d) is invalib\r\n";
    uVar6 = 0x2548;
  }
  else {
    if ((g_apupd_error == 0) || (iVar7 = is_target_debug_ap(apupd_db_mutex), iVar7 == 0))
    goto LAB_0065c1a0;
    uVar4 = *(undefined4 *)(iVar2 + 0x20);
    pcVar5 = "[APUPD_ERROR]%32s() %05d: update wtp satte(%d) is invalib\r\n";
    uVar6 = 0x2542;
  }
  printf(pcVar5,"apupd_db_update_wtp_reset_request_send_by_mac",uVar6,uVar4);
LAB_0065c1a0:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

