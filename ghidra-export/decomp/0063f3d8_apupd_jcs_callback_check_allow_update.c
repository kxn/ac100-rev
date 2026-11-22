// func apupd_jcs_callback_check_allow_update @ 0063f3d8 size=568

void apupd_jcs_callback_check_allow_update(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined1 auStack_818 [320];
  int local_6d8;
  int local_2c;
  
  bVar4 = false;
  memset(auStack_818,0,0x800);
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar5 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      }
      else {
        uVar3 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_check_allow_update",0xdc0);
        }
      }
    }
    iVar1 = apupd_db_model_get_by_id(uVar3,auStack_818);
    if (iVar1 == 0) {
      bVar4 = false;
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n",
               "apupd_jcs_callback_check_allow_update",0xdc3);
      }
    }
    else {
      bVar4 = false;
      iVar1 = json_object_object_get(param_1,"upgrade_type");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          iVar1 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar5 = json_object_get_double(iVar1);
            iVar1 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
          }
          else {
            iVar1 = -1;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "apupd_jcs_callback_check_allow_update",0xdce);
            }
          }
        }
        bVar4 = false;
        if ((((1 < local_2c - 1U) && (bVar4 = true, local_2c == 3)) && (iVar1 != 3)) &&
           ((local_6d8 != 0 && (local_6d8 != 4)))) {
          bVar4 = local_6d8 == 5;
        }
      }
    }
  }
  uVar3 = json_object_new_int(bVar4);
  json_object_object_add(param_2,"allow_update",uVar3);
  return;
}

