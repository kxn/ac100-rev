// func apupd_jcs_callback_apupd_log_del @ 006448e4 size=540

void apupd_jcs_callback_apupd_log_del(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined8 uVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_log_del",0xb5e)
      ;
      return;
    }
    return;
  }
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 == 0) {
    uVar3 = 1;
    if (g_apupd_error == 0) goto LAB_00644968;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar3 = 1;
      goto LAB_00644968;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar3 = 0xb65;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
LAB_00644a74:
      if (iVar1 != -1) {
        iVar1 = apupd_db_model_log_handle(iVar1,0,0xffffffff,apupd_callback_model_log_delete,0);
        uVar3 = 0;
        if ((iVar1 != -1) || (uVar3 = 1, g_apupd_error == 0)) goto LAB_00644968;
        iVar1 = is_target_debug_ap(1);
        if (iVar1 == 0) {
          uVar3 = 1;
          goto LAB_00644968;
        }
        __format = "[APUPD_ERROR]%32s() %05d: delete log by model id failed.\r\n";
        uVar3 = 0xb72;
        goto LAB_00644ad4;
      }
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
        goto LAB_00644a74;
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "apupd_jcs_callback_apupd_log_del",0xb68);
      }
    }
    uVar3 = 1;
    if (g_apupd_error == 0) goto LAB_00644968;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar3 = 1;
      goto LAB_00644968;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar3 = 0xb6b;
  }
LAB_00644ad4:
  printf(__format,"apupd_jcs_callback_apupd_log_del",uVar3);
  uVar3 = 1;
LAB_00644968:
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

