// func apupd_update_model_entry_delete_by_id @ 0064f2b0 size=200

undefined4 apupd_update_model_entry_delete_by_id(undefined4 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  iVar1 = FUN_00407fa0(apupd_update_model_hash,local_res0);
  if (iVar1 == 0) {
    uVar3 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: no update model need delete.\r\n";
    uVar2 = 0x65b;
  }
  else {
    iVar1 = apupd_update_model_entry_delete(iVar1);
    if (iVar1 != -1) {
      return 0;
    }
    uVar3 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: delete update model failed.\r\n";
    uVar2 = 0x662;
  }
  printf(__format,"apupd_update_model_entry_delete_by_id",uVar2);
  return uVar3;
}

