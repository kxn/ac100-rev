// func apupd_update_wtp_entry_delete_after_handle @ 00658e48 size=396

undefined4 apupd_update_wtp_entry_delete_after_handle(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: update wtp delete after handle\r\n",
           "apupd_update_wtp_entry_delete_after_handle",0x805);
  }
  iVar1 = FUN_00407fe0(param_1 + 0x14);
  if (iVar1 != 0) {
    return 0;
  }
  if (g_apupd_debug == 0) {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
    }
    else {
      printf("[APUPD_DEBUG]%32s() %05d: before delete update model\r\n",
             "apupd_update_wtp_entry_delete_after_handle",0x808);
      iVar1 = *(int *)(param_1 + 0x10);
    }
  }
  if (*(int *)(iVar1 + 0x140) == 3) {
    if (apupd_updating_model_num == 0) {
      iVar2 = *(int *)(iVar1 + 0x7ec);
      goto LAB_00658ea8;
    }
    apupd_updating_model_num = apupd_updating_model_num + -1;
  }
  iVar2 = *(int *)(iVar1 + 0x7ec);
LAB_00658ea8:
  if (iVar2 == 3) {
    *(undefined4 *)(iVar1 + 0x140) = 0;
    memset((void *)(*(int *)(param_1 + 0x10) + 0x18),0,0x40);
  }
  else {
    *(undefined4 *)(iVar1 + 0x140) = 4;
  }
  iVar2 = apupd_update_model_entry_delete(param_1);
  if (iVar2 == -1) {
    uVar3 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: delete update model failed.\r\n",
             "apupd_update_wtp_entry_delete_after_handle",0x820);
    }
  }
  else {
    uVar3 = 0;
    apupd_update_model_and_wtp_add_if_wtp_wait(iVar1,param_2,1);
  }
  return uVar3;
}

