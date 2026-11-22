// func apupd_db_model_set_for_uilist @ 00654464 size=216

undefined4 apupd_db_model_set_for_uilist(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_model_hash,local_res0);
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get model from hash by id failed.\r\n",
             "apupd_db_model_set_for_uilist",0x1f3b);
    }
    FUN_00407f30(apupd_db_mutex);
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 == 0) {
      if (*(int *)(iVar1 + 0x14) != 0) {
        FUN_00408500(iVar1 + 0xc);
      }
    }
    else {
      FUN_004086b0(apupd_model_list_for_ui,iVar1 + 0xc);
    }
    FUN_00407f30(apupd_db_mutex);
    uVar2 = 0;
  }
  return uVar2;
}

