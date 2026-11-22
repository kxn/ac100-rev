// func apupd_update_wtp_large_image_info_timer_callback @ 0065e8b4 size=772

void apupd_update_wtp_large_image_info_timer_callback(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *__format;
  int iVar5;
  undefined1 auStack_180 [64];
  char acStack_140 [128];
  undefined1 auStack_c0 [164];
  
  memset(auStack_180,0,0x40);
  memset(auStack_c0,0,0x9a);
  if ((param_1 == 0) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n",
           "apupd_update_wtp_large_image_info_timer_callback",0xfe7);
    return;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065ea80;
    __format = "[APUPD_ERROR]%32s() %05d: get update wtp failed.\r\n";
    uVar3 = 0xff1;
  }
  else {
    iVar5 = *(int *)(iVar1 + 0x30);
    if (*(int *)(iVar1 + 0x24) != 1) goto LAB_0065ea80;
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: confirm wtp large_image_update_state(%d) timeout\r\n",
             "apupd_update_wtp_large_image_info_timer_callback",0xff9,*(undefined4 *)(iVar1 + 0x24))
      ;
    }
    *(undefined4 *)(iVar5 + 0x48) = 0xc;
    if ((*(int *)(*(int *)(iVar5 + 0x50) + 0x7ec) == 3) ||
       (iVar2 = apupd_wtp_log_entry_add(iVar5,8), iVar2 != -1)) {
      memset(acStack_140,0,0x80);
      sprintf(acStack_140,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar5 + 0x2e),
              (uint)*(byte *)(iVar5 + 0x2f),(uint)*(byte *)(iVar5 + 0x30),
              (uint)*(byte *)(iVar5 + 0x31),(uint)*(byte *)(iVar5 + 0x32),
              (uint)*(byte *)(iVar5 + 0x33));
      FUN_00408190(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                   *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                   *(undefined4 *)(iVar5 + 0x28),auStack_180,0x40,"---");
      uVar3 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(iVar5 + 0x50) + 0x138));
      uVar4 = FUN_006505b0(iVar5 + 0x2e,auStack_c0);
      loggerk_reg(0x54,0x3813,1,uVar3,1,uVar4,1,auStack_180,1,acStack_140,0);
      *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
      apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
      iVar1 = apupd_update_wtp_entry_delete(iVar1);
      if ((iVar1 != -1) || ((g_apupd_error == 0 || (iVar1 = is_target_debug_ap(), iVar1 == 0))))
      goto LAB_0065ea80;
      __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
      uVar3 = 0x1010;
    }
    else {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065ea80;
      __format = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
      uVar3 = 0xfff;
    }
  }
  printf(__format,"apupd_update_wtp_large_image_info_timer_callback",uVar3);
LAB_0065ea80:
  FUN_00407f30(apupd_db_mutex);
  return;
}

