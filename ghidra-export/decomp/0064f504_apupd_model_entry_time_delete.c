// func apupd_model_entry_time_delete @ 0064f504 size=452

undefined4 apupd_model_entry_time_delete(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = apupd_update_model_entry_delete_by_id(*(undefined4 *)(param_1 + 0x58));
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[APUPD_ERROR]%32s() %05d: delete update model failed.\r\n",
               "apupd_model_entry_time_delete_before_handle",0x7a1);
      }
      uVar2 = 0xffffffff;
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: update model before deleting time failed.\r\n",
               "apupd_model_entry_time_delete",0x7c5);
      }
    }
  }
  else {
    while (iVar1 = FUN_004081b0(param_1 + 0x17c), iVar1 != 0) {
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    if (*(int *)(param_1 + 0x7ec) - 1U < 2) {
      for (iVar1 = FUN_004081b0(param_1 + 0x7f4); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        *(undefined4 *)(iVar1 + 0x48) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
    memset((void *)(param_1 + 0x150),0,0x2c);
    if (*(int *)(param_1 + 0x13c) != -1) {
      FUN_00408060();
      *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    }
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: set large image info Init\r\n",
             "apupd_model_entry_time_delete",0x7d5);
    }
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    uVar2 = 0;
    memset((void *)(param_1 + 400),0,0x10);
    *(undefined1 *)(param_1 + 0x1a0) = 0;
    *(undefined1 *)(param_1 + 0x1a1) = 0;
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(undefined4 *)(param_1 + 0x7ec) = 0;
    *(undefined4 *)(param_1 + 0x7f0) = 0;
  }
  return uVar2;
}

