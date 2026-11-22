// func apupd_jcs_callback_apupd_models_large_fw_info_set @ 006400fc size=1024

undefined4 apupd_jcs_callback_apupd_models_large_fw_info_set(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  char acStack_40 [32];
  undefined1 local_20;
  
  memset(acStack_40,0,0x21);
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar6 = 0x5d3;
  }
  else {
    iVar2 = json_object_object_get(param_1,"total_image_size");
    if (iVar2 == 0) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[APUPD_ERROR]%32s() %05d: get total_image_size from json failed.\r\n";
      uVar6 = 0x5da;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 == 2) {
          uVar7 = json_object_get_double(iVar2);
          uVar6 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
        }
        else {
          uVar6 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_large_fw_info_set",0x5dd);
          }
        }
      }
      *(undefined4 *)(param_2 + 0x188) = uVar6;
      if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: model total_image_size is %d.\r\n",
               "apupd_jcs_callback_apupd_models_large_fw_info_set",0x5df,uVar6);
      }
      iVar2 = json_object_object_get(param_1,"total_image_piece");
      if (iVar2 == 0) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[APUPD_ERROR]%32s() %05d: get total_image_piece from json failed.\r\n";
        uVar6 = 0x5e4;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          uVar6 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 == 2) {
            uVar7 = json_object_get_double(iVar2);
            uVar6 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
          }
          else {
            uVar6 = 0xffffffff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "apupd_jcs_callback_apupd_models_large_fw_info_set",0x5e7);
            }
          }
        }
        bVar1 = g_apupd_debug != 0;
        *(undefined4 *)(param_2 + 0x18c) = uVar6;
        if ((bVar1) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: model total_image_piece is %d.\r\n",
                 "apupd_jcs_callback_apupd_models_large_fw_info_set",0x5e9,uVar6);
        }
        iVar2 = json_object_object_get(param_1,"total_md5");
        if (iVar2 != 0) {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 6) {
            pcVar5 = (char *)json_object_get_string(iVar2);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"apupd_jcs_callback_apupd_models_large_fw_info_set",0x5f2);
            }
            pcVar5 = "";
          }
          strncpy(acStack_40,pcVar5,0x20);
          local_20 = 0;
          if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: md5_str = %s\r\n",
                   "apupd_jcs_callback_apupd_models_large_fw_info_set",0x5f3,acStack_40);
          }
          sVar4 = strlen(acStack_40);
          FUN_00408280(&local_50,acStack_40,sVar4);
          memcpy((void *)(param_2 + 400),&local_50,0x10);
          return 0;
        }
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[APUPD_ERROR]%32s() %05d: get total git md5 from json failed.\r\n";
        uVar6 = 0x5ee;
      }
    }
  }
  printf(pcVar5,"apupd_jcs_callback_apupd_models_large_fw_info_set",uVar6);
  return 0xffffffff;
}

