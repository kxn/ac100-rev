// func apupd_update_model_entry_delete @ 0064ca68 size=284

undefined4 apupd_update_model_entry_delete(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = apupd_update_wtp_entry_list_delete();
  if (iVar1 == -1) {
    if (g_apupd_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete update wtp list failed.\r\n";
      uVar2 = 0x638;
      goto LAB_0064cb74;
    }
  }
  else {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: delete update model\r\n","apupd_update_model_entry_delete",
             0x63d);
    }
    iVar1 = FUN_00407f40(apupd_update_model_hash,param_1);
    if (iVar1 == 0) {
      FUN_00408310(*(undefined4 *)(param_1 + 0x2c));
      FUN_00408500(param_1);
      FUN_00407df0(param_1);
      return 0;
    }
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[APUPD_ERROR]%32s() %05d: remove update model from hash failed.\r\n";
      uVar2 = 0x640;
LAB_0064cb74:
      printf(__format,"apupd_update_model_entry_delete",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

