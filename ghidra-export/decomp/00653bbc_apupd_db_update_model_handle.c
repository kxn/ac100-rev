// func apupd_db_update_model_handle @ 00653bbc size=300

undefined4 apupd_db_update_model_handle(code *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (apupd_update_model_list == 0) {
    uVar4 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0x1e05;
  }
  else {
    if (param_1 != (code *)0x0) {
      FUN_004082d0(apupd_db_mutex,0xffffffff);
      iVar1 = FUN_004081b0(apupd_update_model_list);
      while (iVar1 != 0) {
        iVar2 = FUN_00408680(iVar1);
        (*param_1)(iVar1,param_2);
        iVar1 = iVar2;
      }
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    uVar4 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: nothing need be done.\r\n";
    uVar3 = 0x1e0c;
  }
  printf(__format,"apupd_db_update_model_handle",uVar3);
  return uVar4;
}

