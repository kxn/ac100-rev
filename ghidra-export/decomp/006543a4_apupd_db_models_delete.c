// func apupd_db_models_delete @ 006543a4 size=1

undefined4 apupd_db_models_delete(void)

{
  int iVar1;
  
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  do {
    iVar1 = FUN_004081b0(apupd_model_list);
    if (iVar1 == 0) {
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    iVar1 = apupd_model_entry_delete(iVar1);
  } while (iVar1 != -1);
  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: delete model failed.\r\n","apupd_db_models_delete",0x1f28);
  }
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

