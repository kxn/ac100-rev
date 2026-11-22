// func apupd_db_model_wtp_num_get @ 006537c0 size=1

undefined4 apupd_db_model_wtp_num_get(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int aiStack_18 [2];
  
  aiStack_18[0] = param_1;
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar4 = apupd_wtp_list;
  if (param_1 != -1) {
    iVar2 = FUN_00407fa0(apupd_model_hash,aiStack_18);
    iVar4 = iVar2 + 0x7f4;
    if (iVar2 == 0) {
      if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(iVar2 + 0x7f4), iVar4 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n","apupd_db_model_wtp_num_get",
               0x1d62);
      }
      FUN_00407f30(apupd_db_mutex);
      return 0xffffffff;
    }
  }
  uVar3 = FUN_00407fe0(iVar4);
  uVar1 = apupd_db_mutex;
  *param_2 = uVar3;
  FUN_00407f30(uVar1);
  return 0;
}

