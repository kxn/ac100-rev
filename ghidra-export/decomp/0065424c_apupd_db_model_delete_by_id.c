// func apupd_db_model_delete_by_id @ 0065424c size=344

undefined4 apupd_db_model_delete_by_id(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [3];
  
  local_18[0] = param_1;
  if ((apupd_model_hash == 0) || (apupd_model_list == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_delete_by_id",0x1ef3);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(apupd_model_hash,local_18);
    if (iVar1 == 0) {
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: model isn\'t existent.\r\n","apupd_db_model_delete_by_id",
               0x1efd);
      }
    }
    else {
      iVar1 = apupd_model_entry_delete(iVar1);
      if (iVar1 == -1) {
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: delete model failed.\r\n","apupd_db_model_delete_by_id",
                 0x1f05);
        }
        FUN_00407f30(apupd_db_mutex);
        return 0xffffffff;
      }
    }
    uVar2 = 0;
    FUN_00407f30(apupd_db_mutex);
  }
  return uVar2;
}

