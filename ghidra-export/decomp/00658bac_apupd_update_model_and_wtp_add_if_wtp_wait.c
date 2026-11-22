// func apupd_update_model_and_wtp_add_if_wtp_wait @ 00658bac size=668

undefined4 apupd_update_model_and_wtp_add_if_wtp_wait(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  iVar2 = FUN_004081b0(param_1 + 0x7f4);
  if (iVar2 == 0) {
LAB_00658c04:
    if (param_3 != 1) {
      return 0;
    }
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: update_model->model->state is %d.\r\n",
             "apupd_update_model_and_wtp_add_if_wtp_wait",0x6e4,*(undefined4 *)(param_1 + 0x140));
    }
    FUN_00407f30(apupd_db_mutex);
    if (g_apupd_debug == 0) {
      iVar2 = *(int *)(param_1 + 0x13c);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x13c);
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: del model->timer_id = %d\r\n",
               "apupd_update_model_and_wtp_add_if_wtp_wait",0x6e6,*(undefined4 *)(param_1 + 0x13c));
        iVar2 = *(int *)(param_1 + 0x13c);
      }
    }
    if (iVar2 != -1) {
      FUN_00408060();
      *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    }
    apupd_clear_sys_model(param_1,param_2);
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x48);
  while (iVar3 != 1) {
    iVar2 = FUN_00408680(iVar2);
    if (iVar2 == 0) goto LAB_00658c04;
    iVar3 = *(int *)(iVar2 + 0x48);
  }
  bVar1 = false;
  iVar2 = FUN_00407fa0(apupd_update_model_hash,param_1 + 0x58);
  if (iVar2 == 0) {
    iVar2 = apupd_update_model_entry_add(param_1);
    if (iVar2 == 0) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: add update model failed.\r\n";
      uVar4 = 0x6cf;
      goto LAB_00658cbc;
    }
    bVar1 = true;
    *(undefined4 *)(param_1 + 0x140) = 2;
  }
  if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_entry_list_add start\r\n",
           "apupd_update_model_and_wtp_add_if_wtp_wait",0x6da);
  }
  iVar3 = apupd_update_wtp_entry_list_add(iVar2,param_1);
  if (iVar3 != -1) {
    return 0;
  }
  if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: add update wtp list failed.\r\n",
           "apupd_update_model_and_wtp_add_if_wtp_wait",0x6de);
  }
  if (!bVar1) {
    return 0xffffffff;
  }
  iVar2 = apupd_update_model_entry_delete(iVar2);
  if (iVar2 != -1) {
    return 0xffffffff;
  }
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  __format = "[APUPD_ERROR]%32s() %05d: delete update model failed.\r\n";
  uVar4 = 0x6f6;
LAB_00658cbc:
  printf(__format,"apupd_update_model_and_wtp_add_if_wtp_wait",uVar4);
  return 0xffffffff;
}

