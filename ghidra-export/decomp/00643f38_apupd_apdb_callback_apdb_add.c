// func apupd_apdb_callback_apdb_add @ 00643f38 size=280

undefined4 apupd_apdb_callback_apdb_add(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_810 [2052];
  
  memset(auStack_810,0,0x800);
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0x112b;
  }
  else {
    iVar1 = apupd_turn_apdb_to_model(param_1,auStack_810);
    if (iVar1 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: turn apdb to mdoel failed.\r\n";
      uVar2 = 0x1132;
    }
    else {
      iVar1 = apupd_db_model_add_or_update(auStack_810);
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
      __format = "[APUPD_ERROR]%32s() %05d: add model failed.\r\n";
      uVar2 = 0x1139;
    }
  }
  printf(__format,"apupd_apdb_callback_apdb_add",uVar2);
  return 0xffffffff;
}

