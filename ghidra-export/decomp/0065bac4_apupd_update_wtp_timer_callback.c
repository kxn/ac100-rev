// func apupd_update_wtp_timer_callback @ 0065bac4 size=1016

void apupd_update_wtp_timer_callback(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  int iVar5;
  undefined1 auStack_178 [64];
  char acStack_138 [128];
  undefined1 auStack_b8 [168];
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_timer_callback\r\n",
           "apupd_update_wtp_timer_callback",0x1663);
  }
  if ((param_1 == 0) || (apupd_update_wtp_hash == 0)) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_update_wtp_timer_callback",0x166a)
      ;
      return;
    }
    return;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065b7f8;
    __format = "[APUPD_ERROR]%32s() %05d: get update wtp failed.\r\n";
    uVar2 = 0x1674;
  }
  else {
    iVar5 = *(int *)(iVar1 + 0x30);
    if ((*(int *)(iVar1 + 0x20) != 4) || (*(int *)(iVar5 + 0x48) != 7)) {
      if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: update wtp state(%d) or wtp state(%d) is invalib\r\n",
               "apupd_update_wtp_timer_callback",0x167c,*(undefined4 *)(iVar1 + 0x20),
               *(undefined4 *)(iVar5 + 0x48));
      }
      goto LAB_0065b7f8;
    }
    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
    iVar1 = apupd_update_wtp_entry_delete(iVar1);
    if (iVar1 == -1) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065b7f8;
      __format = "[APUPD_ERROR]%32s() %05d: delete update failed.\r\n";
      uVar2 = 0x1684;
    }
    else {
      apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
      *(undefined4 *)(iVar5 + 0x48) = 0xc;
      if ((*(int *)(*(int *)(iVar5 + 0x50) + 0x7ec) == 3) ||
         (iVar1 = apupd_wtp_log_entry_add(iVar5,3), iVar1 != -1)) {
        memset(acStack_138,0,0x80);
        sprintf(acStack_138,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar5 + 0x2e),
                (uint)*(byte *)(iVar5 + 0x2f),(uint)*(byte *)(iVar5 + 0x30),
                (uint)*(byte *)(iVar5 + 0x31),(uint)*(byte *)(iVar5 + 0x32),
                (uint)*(byte *)(iVar5 + 0x33));
        memset(auStack_178,0,0x40);
        memset(auStack_b8,0,0x9a);
        FUN_00408190(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                     *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                     *(undefined4 *)(iVar5 + 0x28),auStack_178,0x40,"---");
        uVar2 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(iVar5 + 0x50) + 0x138));
        uVar3 = FUN_006505b0(iVar5 + 0x2e,auStack_b8);
        loggerk_reg(0x54,0x3813,1,uVar2,1,uVar3,1,auStack_178,1,acStack_138,0);
        iVar1 = apupd_wtp_entry_delete(iVar5);
        if (iVar1 == -1) {
          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065b7f8;
          __format = "[APUPD_ERROR]%32s() %05d: delete wtp failed.\r\n";
          uVar2 = 0x169e;
        }
        else {
          if ((g_apupd_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065b7f8;
          __format = "[APUPD_DEBUG]%32s() %05d: confirm timeout\r\n";
          uVar2 = 0x16a2;
        }
      }
      else {
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065b7f8;
        __format = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
        uVar2 = 0x168d;
      }
    }
  }
  printf(__format,"apupd_update_wtp_timer_callback",uVar2);
LAB_0065b7f8:
  FUN_00407f30(apupd_db_mutex);
  return;
}

