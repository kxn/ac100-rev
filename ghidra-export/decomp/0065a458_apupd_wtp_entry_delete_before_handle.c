// func apupd_wtp_entry_delete_before_handle @ 0065a458 size=1080

undefined4 apupd_wtp_entry_delete_before_handle(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined1 auStack_178 [64];
  char acStack_138 [128];
  undefined1 auStack_b8 [164];
  
  if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: wtp state is %d, apupd_updating_wtp_num:%d\r\n",
           "apupd_wtp_entry_delete_before_handle",0x836,*(undefined4 *)(param_1 + 0x48),
           apupd_updating_wtp_num);
    if (param_1 != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x48);
      goto LAB_0065a48c;
    }
LAB_0065a534:
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar1 = 0x83a;
    goto LAB_0065a564;
  }
  if (param_1 == 0) goto LAB_0065a534;
  uVar1 = *(undefined4 *)(param_1 + 0x48);
LAB_0065a48c:
  switch(uVar1) {
  case 0:
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    break;
  case 1:
    *(int *)(*(int *)(param_1 + 0x50) + 0x144) = *(int *)(*(int *)(param_1 + 0x50) + 0x144) + -1;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 0x15:
    iVar2 = apupd_update_wtp_entry_delete_by_mac(param_1 + 0x2e);
    if (iVar2 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
      uVar1 = 0x855;
      goto LAB_0065a564;
    }
    goto LAB_0065a6c0;
  case 6:
  case 0x16:
    if ((*(int *)(*(int *)(param_1 + 0x50) + 0x7ec) == 3) ||
       (iVar2 = apupd_wtp_log_entry_add(param_1,1), iVar2 != -1)) {
      memset(acStack_138,0,0x80);
      sprintf(acStack_138,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x2e),
              (uint)*(byte *)(param_1 + 0x2f),(uint)*(byte *)(param_1 + 0x30),
              (uint)*(byte *)(param_1 + 0x31),(uint)*(byte *)(param_1 + 0x32),
              (uint)*(byte *)(param_1 + 0x33));
      memset(auStack_178,0,0x40);
      memset(auStack_b8,0,0x9a);
      FUN_00408190(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                   *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                   *(undefined4 *)(param_1 + 0x28),auStack_178,0x40,"---");
      uVar1 = apmngr_db_product_type_str(*(undefined1 *)(*(int *)(param_1 + 0x50) + 0x138));
      uVar3 = FUN_006505b0(param_1 + 0x2e,auStack_b8);
      loggerk_reg(0x54,0x3811,1,uVar1,1,uVar3,1,auStack_178,1,acStack_138,0);
      iVar2 = apupd_update_wtp_entry_delete_by_mac(param_1 + 0x2e);
      if (iVar2 != -1) {
        apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
        break;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
      uVar1 = 0x872;
    }
    else {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: add wtp log failed.\r\n";
      uVar1 = 0x861;
    }
    goto LAB_0065a564;
  case 7:
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x87b;
    goto LAB_0065a4cc;
  case 8:
    *(int *)(*(int *)(param_1 + 0x50) + 0x14c) = *(int *)(*(int *)(param_1 + 0x50) + 0x14c) + -1;
    break;
  default:
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x8a5;
    goto LAB_0065a4cc;
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x89f;
LAB_0065a4cc:
    printf("[APUPD_ERROR]%32s() %05d: wtp state(%d) is invalib\r\n",
           "apupd_wtp_entry_delete_before_handle",uVar1,*(undefined4 *)(param_1 + 0x48));
    return 0xffffffff;
  }
LAB_0065a6c0:
  uVar3 = 0;
  iVar2 = FUN_00407fa0(apupd_update_model_hash,*(int *)(param_1 + 0x50) + 0x58);
  if ((((iVar2 != 0) &&
       (iVar2 = apupd_update_wtp_entry_delete_after_handle(iVar2,param_1), iVar2 == -1)) &&
      (uVar3 = 0xffffffff, g_apupd_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    __format = "[APUPD_ERROR]%32s() %05d: handle update mdoel failed.\r\n";
    uVar1 = 0x8af;
LAB_0065a564:
    uVar3 = 0xffffffff;
    printf(__format,"apupd_wtp_entry_delete_before_handle",uVar1);
  }
  return uVar3;
}

