// func apupd_db_model_num_get @ 00653650 size=1

undefined4 apupd_db_model_num_get(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_1 == (undefined4 *)0x0) || (apupd_model_list == 0)) {
    uVar4 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_num_get",0x1d14);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    uVar4 = 0;
    uVar2 = FUN_00407fe0(apupd_model_list);
    uVar1 = apupd_db_mutex;
    *param_1 = uVar2;
    FUN_00407f30(uVar1);
  }
  return uVar4;
}

