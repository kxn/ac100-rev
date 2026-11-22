// func apupd_db_model_log_handle @ 00653ce8 size=496

undefined4
apupd_db_model_log_handle
          (undefined4 param_1,uint param_2,uint param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_30 [2];
  
  local_30[0] = param_1;
  if (apupd_model_hash == 0) {
    uVar4 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0x1e3b;
  }
  else {
    if ((param_4 != (code *)0x0) && (param_3 != 0)) {
      FUN_004082d0(apupd_db_mutex,0xffffffff);
      iVar1 = FUN_00407fa0(apupd_model_hash,local_30);
      if (iVar1 == 0) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n","apupd_db_model_log_handle"
                 ,0x1e4c);
        }
        FUN_00407f30(apupd_db_mutex);
        return 0xffffffff;
      }
      uVar5 = 0;
      iVar1 = FUN_004081b0(iVar1 + 0x17c);
      uVar6 = 0;
      do {
        while( true ) {
          if (iVar1 == 0) goto LAB_00653e3c;
          iVar2 = FUN_00408680(iVar1);
          if (param_2 <= uVar6) break;
          uVar6 = uVar6 + 1;
          iVar1 = iVar2;
        }
        uVar5 = uVar5 + 1;
        (*param_4)(iVar1,param_5);
        iVar1 = iVar2;
      } while (uVar5 < param_3);
LAB_00653e3c:
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
    uVar3 = 0x1e42;
  }
  printf(__format,"apupd_db_model_log_handle",uVar3);
  return uVar4;
}

