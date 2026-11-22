// func apupd_jcs_callback_apupd_image_check @ 006418bc size=912

void apupd_jcs_callback_apupd_image_check(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *__format;
  undefined8 uVar5;
  int local_60;
  sysinfo sStack_5c;
  
  local_60 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar4 = 1;
    if (g_apupd_error == 0) goto LAB_0064194c;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar4 = 1;
      goto LAB_0064194c;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar4 = 0x318;
  }
  else {
    iVar1 = json_object_object_get(param_1,"file_size");
    if (iVar1 == 0) {
      uVar4 = 1;
      if (g_apupd_error == 0) goto LAB_0064194c;
      iVar1 = is_target_debug_ap(1);
      if (iVar1 == 0) {
        uVar4 = 1;
        goto LAB_0064194c;
      }
      __format = "[APUPD_ERROR]%32s() %05d: get file size from json failed.\r\n";
      uVar4 = 799;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
LAB_00641a40:
        if (uVar3 != 0xffffffff) {
          iVar1 = apupd_db_update_model_handle(apupd_callback_model_image_total_size_get,&local_60);
          if (iVar1 == -1) {
            uVar4 = 1;
            if (g_apupd_debug == 0) goto LAB_0064194c;
            iVar1 = is_target_debug_ap(1);
            if (iVar1 == 0) {
              uVar4 = 1;
              goto LAB_0064194c;
            }
            __format = "[APUPD_DEBUG]%32s() %05d: get update model size failed.\r\n";
            uVar4 = 0x32c;
          }
          else {
            iVar1 = apupd_db_model_range_handle_for_ui
                              (apupd_callback_ui_model_image_size_get,&local_60);
            if (iVar1 != -1) {
              if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: file_size:%d total_size:%d\r\n",
                       "apupd_jcs_callback_apupd_image_check",0x338,uVar3,local_60);
              }
              uVar4 = 0;
              if ((APUPD_ALL_SOFTWARE_SIZE_MAX != 0) &&
                 (uVar4 = 0x13, uVar3 + local_60 < APUPD_ALL_SOFTWARE_SIZE_MAX)) {
                uVar4 = 0;
              }
              sysinfo(&sStack_5c);
              if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: Totalram:%lu\n\r\n",
                       "apupd_jcs_callback_apupd_image_check",0x33f,sStack_5c.totalram);
              }
              if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: Available:%lu\n\r\n",
                       "apupd_jcs_callback_apupd_image_check",0x340,sStack_5c.freeram);
              }
              if ((sStack_5c.freeram < uVar3) && (uVar4 = 0x13, g_apupd_debug != 0)) {
                iVar1 = is_target_debug_ap();
                if (iVar1 == 0) {
                  uVar4 = 0x13;
                }
                else {
                  printf("[APUPD_DEBUG]%32s() %05d: file_size[%d] large free mem[%d]\r\n",
                         "apupd_jcs_callback_apupd_image_check",0x343,uVar3,sStack_5c.freeram);
                  uVar4 = 0x13;
                }
              }
              goto LAB_0064194c;
            }
            uVar4 = 1;
            if (g_apupd_debug == 0) goto LAB_0064194c;
            iVar1 = is_target_debug_ap(1);
            if (iVar1 == 0) {
              uVar4 = 1;
              goto LAB_0064194c;
            }
            __format = "[APUPD_DEBUG]%32s() %05d: get model size failed.\r\n";
            uVar4 = 0x331;
          }
          goto LAB_00641a94;
        }
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar5 = json_object_get_double(iVar1);
          uVar3 = __fixunsdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
          goto LAB_00641a40;
        }
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_image_check",0x322);
        }
      }
      uVar4 = 1;
      if (g_apupd_error == 0) goto LAB_0064194c;
      iVar1 = is_target_debug_ap(1);
      if (iVar1 == 0) {
        uVar4 = 1;
        goto LAB_0064194c;
      }
      __format = "[APUPD_ERROR]%32s() %05d: get file size from json failed.\r\n";
      uVar4 = 0x325;
    }
  }
LAB_00641a94:
  printf(__format,"apupd_jcs_callback_apupd_image_check",uVar4);
  uVar4 = 1;
LAB_0064194c:
  uVar4 = json_object_new_int(uVar4);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return;
}

