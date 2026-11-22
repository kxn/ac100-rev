// func apupd_clear_model @ 006588e0 size=292

undefined4 apupd_clear_model(int param_1,undefined4 param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = apupd_db_model_set(param_1,1);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: delete image failed.\r\n";
    uVar2 = 0x27da;
  }
  else {
    iVar1 = apupd_db_model_set_for_uilist(*(undefined4 *)(param_1 + 0x58),0);
    if (iVar1 == 0) {
      iVar1 = apupd_db_model_set(param_1,5);
      if (iVar1 == 0) {
        apupd_entry_num_update(param_2,0);
        return 0;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete group id failed\r\n";
      uVar2 = 0x27e6;
    }
    else {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete image failed.\r\n";
      uVar2 = 0x27df;
    }
  }
  printf(__format,"apupd_clear_model",uVar2);
  return 0xffffffff;
}

