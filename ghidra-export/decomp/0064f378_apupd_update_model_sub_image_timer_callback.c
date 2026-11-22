// func apupd_update_model_sub_image_timer_callback @ 0064f378 size=396

void apupd_update_model_sub_image_timer_callback(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_sub_image_timer_callback start for model %d\r\n"
           ,"apupd_update_model_sub_image_timer_callback",0x7ec,*param_1);
  }
  iVar1 = FUN_00407fa0(apupd_model_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get model by model id failed.\r\n",
             "apupd_update_model_sub_image_timer_callback",0x7f0);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0x13c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x140) = 4;
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: set model[%s] state = %d\r\n",
             "apupd_update_model_sub_image_timer_callback",0x7f6,iVar1 + 0x5c,4);
    }
    iVar2 = apupd_update_model_entry_delete_by_id(*(undefined4 *)(iVar1 + 0x58));
    if (((iVar2 == -1) && (g_apupd_error != 0)) &&
       (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: apupd_update_model_entry_delete_by_id[%d] failed.\r\n",
             "apupd_update_model_sub_image_timer_callback",0x7f9,*(undefined4 *)(iVar1 + 0x58));
    }
  }
  FUN_00407f30(apupd_db_mutex);
  return;
}

