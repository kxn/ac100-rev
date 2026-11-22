// func apupd_update_wtp_config_update_response_check @ 0065c7a8 size=980

undefined4 apupd_update_wtp_config_update_response_check(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint extraout_v1;
  char *__format;
  undefined1 auStack_190 [64];
  char acStack_150 [128];
  undefined1 auStack_d0 [160];
  int local_30;
  
  iVar2 = FUN_004081b0(apupd_update_model_list);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x10);
  do {
    if (*(int *)(iVar3 + 0x140) == 3) {
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        iVar3 = *(int *)(iVar2 + 0x10);
        uVar4 = FUN_00407fe0(iVar2 + 0x14);
        printf("[APUPD_DEBUG]%32s() %05d: tmp_update_model->model: %s list size:%d\r\n",
               "apupd_update_wtp_config_update_response_check",0x136b,iVar3 + 0x5c,uVar4);
      }
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(iVar2 + 0x14), iVar3 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: tmp_update_model->model->is_large_fw:%d\r\n",
               "apupd_update_wtp_config_update_response_check",0x136c,
               (uint)*(byte *)(*(int *)(iVar2 + 0x10) + 0x13a));
      }
      iVar3 = FUN_004081b0(iVar2 + 0x14);
      while (iVar6 = iVar3, iVar6 != 0) {
        local_30 = FUN_00408680(iVar6);
        cVar1 = *(char *)(*(int *)(iVar2 + 0x10) + 0x13a);
        iVar3 = local_30;
        if (cVar1 == '\0') {
          if ((*(int *)(iVar6 + 0x14) == 1) || (*(int *)(iVar6 + 0x14) == 3)) {
            FUN_00407e70();
            iVar3 = local_30;
            if ((*(uint *)(iVar6 + 0x20) < extraout_v1) &&
               (0x1e < extraout_v1 - *(uint *)(iVar6 + 0x20))) {
              if (*(int *)(*(int *)(iVar2 + 0x10) + 0x7ec) == 3) {
                iVar3 = *(int *)(iVar6 + 0x24);
              }
              else {
                iVar3 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar6 + 0x24),1);
                if (iVar3 == -1) {
                  if (g_apupd_error == 0) {
                    return 0xffffffff;
                  }
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    return 0xffffffff;
                  }
                  __format = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
                  uVar4 = 0x137a;
                  goto LAB_0065cb58;
                }
                iVar3 = *(int *)(iVar6 + 0x24);
              }
              memset(acStack_150,0,0x80);
              sprintf(acStack_150,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar3 + 0x2e),
                      (uint)*(byte *)(iVar3 + 0x2f),(uint)*(byte *)(iVar3 + 0x30),
                      (uint)*(byte *)(iVar3 + 0x31),(uint)*(byte *)(iVar3 + 0x32),
                      (uint)*(byte *)(iVar3 + 0x33));
              memset(auStack_190,0,0x40);
              memset(auStack_d0,0,0x9a);
              FUN_00408190(*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                           *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),
                           *(undefined4 *)(iVar3 + 0x28),auStack_190,0x40,"---");
              uVar4 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x138));
              uVar5 = FUN_006505b0(iVar3 + 0x2e,auStack_d0);
              loggerk_reg(0x54,0x3811,1,uVar4,1,uVar5,1,auStack_190,1,acStack_150,0);
              *(undefined4 *)(*(int *)(iVar6 + 0x24) + 0x48) = 10;
              apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
              uVar4 = apmngr_db_get_id_by_mac(iVar6 + 0xc);
              apmngr_db_ap_run_state_update(uVar4,2);
              iVar6 = apupd_update_wtp_entry_delete(iVar6 + -0xc);
              iVar3 = local_30;
              if (iVar6 == -1) {
                if (g_apupd_error == 0) {
                  return 0xffffffff;
                }
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  return 0xffffffff;
                }
                __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
                uVar4 = 0x138f;
LAB_0065cb58:
                printf(__format,"apupd_update_wtp_config_update_response_check",uVar4);
                return 0xffffffff;
              }
            }
          }
        }
        else if (((cVar1 == '\x01') && (g_apupd_debug != 0)) &&
                (iVar6 = is_target_debug_ap(), iVar3 = local_30, iVar6 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: large image upgrade don\'t check packet time\r\n",
                 "apupd_update_wtp_config_update_response_check",0x1396);
          iVar3 = local_30;
        }
      }
    }
    iVar2 = FUN_00408680(iVar2);
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = *(int *)(iVar2 + 0x10);
  } while( true );
}

