// func apupd_wtp_entry_update @ 0065ace8 size=584

undefined4 apupd_wtp_entry_update(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_wtp_entry_update\r\n","apupd_wtp_entry_update",0xf55);
  }
  if ((param_1 == 0) || (apupd_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0xf5b;
  }
  else {
    iVar1 = FUN_00407fa0(apupd_wtp_hash,param_1 + 0x2e);
    if (iVar1 == 0) {
      iVar1 = apupd_wtp_entry_add(param_1);
      if (iVar1 != -1) {
        return 0;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: add wtp failed.\r\n";
      uVar2 = 0xf83;
    }
    else if (*(int *)(iVar1 + 0x34) == *(int *)(param_1 + 0x34)) {
      iVar1 = apupd_wtp_entry_set(iVar1,param_1);
      if (iVar1 != -1) {
        return 0;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: set wtp failed.\r\n";
      uVar2 = 0xf67;
    }
    else {
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar1 + 0x48);
      iVar1 = apupd_wtp_entry_delete();
      if (iVar1 == -1) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_ERROR]%32s() %05d: delete wtp failed.\r\n";
        uVar2 = 0xf71;
      }
      else {
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: delete wtp successed.\r\n","apupd_wtp_entry_update",
                 0xf74);
        }
        iVar1 = apupd_wtp_entry_add(param_1);
        if (iVar1 != -1) {
          return 0;
        }
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_ERROR]%32s() %05d: add wtp failed.\r\n";
        uVar2 = 0xf79;
      }
    }
  }
  printf(__format,"apupd_wtp_entry_update",uVar2);
  return 0xffffffff;
}

