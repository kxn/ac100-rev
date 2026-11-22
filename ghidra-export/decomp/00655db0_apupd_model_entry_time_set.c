// func apupd_model_entry_time_set @ 00655db0 size=584

undefined4 apupd_model_entry_time_set(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 auStack_48 [52];
  
  memset(auStack_48,0,0x2c);
  iVar1 = memcmp(auStack_48,(void *)(param_2 + 0x150),0x2c);
  if (iVar1 == 0) {
    iVar1 = apupd_model_entry_time_delete(param_1);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APUPD_ERROR]%32s() %05d: clear time failed.\r\n";
    uVar3 = 0xb26;
    goto LAB_00655fa0;
  }
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(param_1), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_model_entry_time_add, model_name = %s\r\n",
           "apupd_model_entry_time_add",0xaf0,param_1 + 0x5c);
  }
  iVar1 = apupd_model_entry_time_delete(param_1);
  if (iVar1 == -1) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar2 = "[APUPD_ERROR]%32s() %05d: clear old time failed.\r\n";
      uVar3 = 0xaf4;
      goto LAB_00655ed4;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14c) = 0;
    memcpy((void *)(param_1 + 0x150),(void *)(param_2 + 0x150),0x2c);
    *(undefined4 *)(param_1 + 0x7ec) = *(undefined4 *)(param_2 + 0x7ec);
    *(undefined4 *)(param_1 + 0x7f0) = *(undefined4 *)(param_2 + 0x7f0);
    iVar1 = apupd_update_wtp_num_get(param_1,param_1 + 0x144);
    if (iVar1 == -1) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar2 = "[APUPD_ERROR]%32s() %05d: get update-wtp number failed.\r\n";
        uVar3 = 0xb00;
        goto LAB_00655ed4;
      }
    }
    else {
      iVar1 = apupd_model_entry_timer_add(param_1);
      if (iVar1 != -1) {
        *(undefined4 *)(param_1 + 0x140) = 1;
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar2 = "[APUPD_ERROR]%32s() %05d: add timer failed..\r\n";
        uVar3 = 0xb06;
LAB_00655ed4:
        printf(pcVar2,"apupd_model_entry_time_add",uVar3);
      }
    }
  }
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar2 = "[APUPD_ERROR]%32s() %05d: add time failed.\r\n";
  uVar3 = 0xb30;
LAB_00655fa0:
  printf(pcVar2,"apupd_model_entry_time_set",uVar3);
  return 0xffffffff;
}

