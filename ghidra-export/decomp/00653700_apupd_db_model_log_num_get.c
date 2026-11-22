// func apupd_db_model_log_num_get @ 00653700 size=192

undefined4 apupd_db_model_log_num_get(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_18 [2];
  
  local_18[0] = param_1;
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_model_hash,local_18);
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n","apupd_db_model_log_num_get",
             0x1d39);
    }
    FUN_00407f30(apupd_db_mutex);
    uVar3 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00407fe0(iVar1 + 0x17c);
    uVar3 = apupd_db_mutex;
    *param_2 = uVar2;
    FUN_00407f30(uVar3);
    uVar3 = 0;
  }
  return uVar3;
}

