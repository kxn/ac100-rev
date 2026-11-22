// func apupd_db_model_get_by_id @ 00653248 size=404

void * apupd_db_model_get_by_id(undefined4 param_1,void *param_2)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  local_20[0] = param_1;
  if (((param_2 == (void *)0x0) || (apupd_model_hash == 0)) || (apupd_config == 0)) {
    __src = (void *)0x0;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_get_by_id",0x1c91);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    __src = (void *)FUN_00407fa0(apupd_model_hash,local_20);
    if (__src == (void *)0x0) {
      uVar2 = apupd_db_mutex;
      if ((g_apupd_error != 0) &&
         (iVar1 = is_target_debug_ap(apupd_db_mutex), uVar2 = apupd_db_mutex, iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get model from hash by id failed.\r\n",
               "apupd_db_model_get_by_id",0x1c9b);
        uVar2 = apupd_db_mutex;
      }
    }
    else {
      memcpy(param_2,__src,0x800);
      iVar1 = apupd_db_model_real_state_get(__src,apupd_config);
      uVar2 = apupd_db_mutex;
      if (iVar1 == -1) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: get model state failed.\r\n","apupd_db_model_get_by_id",
                 0x1ca2);
        }
        FUN_00407f30(apupd_db_mutex);
        return (void *)0x0;
      }
      *(int *)((int)param_2 + 0x140) = iVar1;
    }
    FUN_00407f30(uVar2);
  }
  return __src;
}

