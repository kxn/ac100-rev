// func apupd_callback_model_log_delete @ 00644b00 size=120

undefined4 apupd_callback_model_log_delete(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_callback_model_log_delete",0xb43);
    }
  }
  else {
    FUN_00408500();
    FUN_00407df0(param_1);
  }
  return 0xffffffff;
}

