// func apupd_update_model_timer_callback @ 0064ccf0 size=764

void apupd_update_model_timer_callback(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_timer_callback start for model %d\r\n",
           "apupd_update_model_timer_callback",0x67e,*param_1);
  }
  iVar1 = FUN_00407fa0(apupd_model_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_0064cd6c;
    __format = "[APUPD_ERROR]%32s() %05d: get model by model id failed.\r\n";
    uVar4 = 0x682;
  }
  else {
    *(undefined4 *)(iVar1 + 0x13c) = 0xffffffff;
    if (*(int *)(iVar1 + 0x140) != 1) {
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: model state(%d) is wrong\r\n",
               "apupd_update_model_timer_callback",0x68b,*(undefined4 *)(iVar1 + 0x140));
      }
      goto LAB_0064cd6c;
    }
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_entry_add start\r\n",
             "apupd_update_model_timer_callback",0x68f);
    }
    iVar2 = apupd_update_model_entry_add(iVar1);
    if (iVar2 == 0) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
      goto LAB_0064cd6c;
      __format = "[APUPD_ERROR]%32s() %05d: add update model failed.\r\n";
      uVar4 = 0x693;
    }
    else {
      *(undefined4 *)(iVar1 + 0x140) = 2;
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_entry_list_add start\r\n",
               "apupd_update_model_timer_callback",0x698);
      }
      iVar1 = apupd_update_wtp_entry_list_add(iVar2,iVar1);
      if (iVar1 != -1) {
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_entry_list_add finish\r\n",
                 "apupd_update_model_timer_callback",0x6a3);
        }
        iVar1 = FUN_00407fe0(apupd_update_model_list);
        if (iVar1 == 1) {
          FUN_004084b0(apupd_db_cond);
        }
        goto LAB_0064cd6c;
      }
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: add update wtp list failed.\r\n",
               "apupd_update_model_timer_callback",0x69c);
      }
      iVar1 = apupd_update_model_entry_delete(iVar2);
      if (((iVar1 != -1) || (g_apupd_error == 0)) ||
         (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0)) goto LAB_0064cd6c;
      __format = "[APUPD_ERROR]%32s() %05d: delete update model failed.\r\n";
      uVar4 = 0x69f;
    }
  }
  printf(__format,"apupd_update_model_timer_callback",uVar4);
LAB_0064cd6c:
  FUN_00407f30(apupd_db_mutex);
  return;
}

