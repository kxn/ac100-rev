// func apupd_jcs_callback_apupd_models_del @ 00644e08 size=756

void apupd_jcs_callback_apupd_models_del(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 auStack_1010 [320];
  int local_ed0;
  int local_824;
  undefined1 auStack_810 [88];
  int local_7b8;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_models_del",
             0x8fc);
      return;
    }
    return;
  }
  memset(auStack_810,0,0x800);
  memset(auStack_1010,0,0x800);
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 == 0) {
    uVar3 = 1;
    if (g_apupd_error == 0) goto LAB_00644c18;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar3 = 1;
      goto LAB_00644c18;
    }
    uVar3 = 0x906;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
LAB_00644cdc:
      if (iVar1 != -1) {
        local_7b8 = iVar1;
        iVar1 = apupd_db_model_get_by_id(iVar1,auStack_1010);
        if (iVar1 == 0) {
          uVar3 = 1;
          if (g_apupd_error == 0) goto LAB_00644c18;
          iVar1 = is_target_debug_ap(1);
          if (iVar1 == 0) {
            uVar3 = 1;
            goto LAB_00644c18;
          }
          uVar3 = 0x914;
        }
        else {
          if (local_824 - 1U < 2) {
            if (local_ed0 == 3) {
              uVar3 = 6;
              if (g_apupd_error != 0) {
                iVar1 = is_target_debug_ap(6);
                if (iVar1 == 0) {
                  uVar3 = 6;
                }
                else {
                  printf("[APUPD_ERROR]%32s() %05d: model state(%d) isn\'t right, it cann\'t delete software.\r\n"
                         ,"apupd_jcs_callback_apupd_models_del",0x921,local_ed0);
                  uVar3 = 6;
                }
              }
            }
            else {
              apupd_clear_model(auStack_810);
              uVar3 = 0;
            }
            goto LAB_00644c18;
          }
          uVar3 = 1;
          if (g_apupd_error == 0) goto LAB_00644c18;
          iVar1 = is_target_debug_ap(1);
          if (iVar1 == 0) {
            uVar3 = 1;
            goto LAB_00644c18;
          }
          uVar3 = 0x91a;
        }
        printf("[APUPD_ERROR]%32s() %05d: get model by id(%d) failed.\r\n",
               "apupd_jcs_callback_apupd_models_del",uVar3,local_7b8);
        uVar3 = 1;
        goto LAB_00644c18;
      }
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
        goto LAB_00644cdc;
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "apupd_jcs_callback_apupd_models_del",0x909);
      }
    }
    uVar3 = 1;
    if (g_apupd_error == 0) goto LAB_00644c18;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar3 = 1;
      goto LAB_00644c18;
    }
    uVar3 = 0x90c;
  }
  printf("[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n",
         "apupd_jcs_callback_apupd_models_del",uVar3);
  uVar3 = 1;
LAB_00644c18:
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

