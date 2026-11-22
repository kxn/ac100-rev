// func apupd_model_entry_delete @ 00650f30 size=352

undefined4 apupd_model_entry_delete(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x140) == 3) && (apupd_updating_model_num != 0)) {
    apupd_updating_model_num = apupd_updating_model_num + -1;
  }
  iVar1 = apupd_wtp_entry_list_delete(param_1);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: delete wtp list failed.\r\n";
    uVar2 = 0xa0b;
  }
  else {
    iVar1 = apupd_model_entry_image_delete(param_1);
    if (iVar1 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete image failed.\r\n";
      uVar2 = 0xa11;
    }
    else {
      memset((void *)(param_1 + 0x18),0,0x40);
      iVar1 = FUN_00407f40(apupd_model_hash,param_1);
      if (iVar1 == 0) {
        FUN_00408500(param_1);
        FUN_00407df0(param_1);
        return 0;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: remove model from hash failed.\r\n";
      uVar2 = 0xa1a;
    }
  }
  printf(__format,"apupd_model_entry_delete",uVar2);
  return 0xffffffff;
}

