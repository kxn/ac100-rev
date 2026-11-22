// func apupd_jcs_callback_apupd_models_get @ 00641f54 size=1728

void apupd_jcs_callback_apupd_models_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  FILE *__s;
  char *pcVar3;
  size_t sVar4;
  undefined1 uVar8;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined8 uVar13;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64;
  undefined1 local_60;
  int local_5c;
  uint local_58 [10];
  undefined4 local_30;
  undefined4 local_2c;
  
  apdb_support_product_type_get();
  memset(&local_78,0,0x20);
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar9 = 1;
    if (g_apupd_error == 0) goto LAB_00642180;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar9 = 1;
      goto LAB_00642180;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar9 = 0x2b8;
  }
  else {
    iVar1 = json_object_object_get(param_1,"start");
    local_30 = 0;
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_30 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar13 = json_object_get_double(iVar1);
          local_30 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
        else {
          local_30 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_get",0x2be);
          }
        }
      }
    }
    iVar1 = json_object_object_get(param_1,"size");
    local_2c = 10;
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_2c = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar13 = json_object_get_double(iVar1);
          local_2c = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
        else {
          local_2c = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_get",0x2c0);
          }
        }
      }
    }
    uVar10 = 0xffffffff;
    iVar1 = json_object_object_get(param_1,"is_mesh_device");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 1) {
        uVar10 = json_object_get_boolean(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 3) {
          iVar1 = json_object_get_int(iVar1);
          uVar10 = (uint)(iVar1 != 0);
        }
        else {
          uVar10 = 0;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n"
                   ,"apupd_jcs_callback_apupd_models_get",0x2c2);
          }
        }
      }
    }
    uVar8 = 1;
    memset(local_58,0,0x28);
    if (uVar10 == 1) {
      uVar8 = apdb_support_product_type_get();
    }
    iVar1 = json_object_object_get(param_1,"product_type");
    if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
       (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
      iVar2 = json_object_get_type(iVar1);
      puVar12 = local_58;
      if (iVar2 == 5) {
        puVar11 = puVar12;
        for (iVar2 = 0; iVar5 = json_object_array_length(iVar1), iVar2 < iVar5; iVar2 = iVar2 + 1) {
          if (iVar2 == 10) goto LAB_00642564;
          iVar5 = json_object_array_get_idx(iVar1,iVar2);
          if (iVar5 == 0) {
LAB_006424a8:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "apupd_jcs_product_type_bitmap_get",0x293);
            }
            *puVar11 = 0xffffffff;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 != 6) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "apupd_jcs_product_type_bitmap_get",0x293);
              }
              goto LAB_006424a8;
            }
            pcVar3 = (char *)json_object_get_string(iVar5);
            uVar7 = atoi(pcVar3);
            *puVar11 = uVar7;
          }
          puVar11 = puVar11 + 1;
        }
        if (0 < iVar2) {
LAB_00642564:
          uVar7 = 0;
          iVar1 = 0;
          do {
            iVar1 = iVar1 + 1;
            uVar7 = uVar7 | 1 << (*puVar12 & 0x1f);
            uVar8 = (undefined1)uVar7;
            puVar12 = puVar12 + 1;
          } while (iVar1 < iVar2);
        }
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (((iVar2 != 4) || (iVar1 = json_object_object_length(iVar1), iVar1 != 0)) &&
           (jcs_err_switch != 0)) {
          printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
                 ,"apupd_jcs_product_type_bitmap_get",0x293);
        }
      }
    }
    iVar1 = json_object_new_array();
    if (iVar1 != 0) {
      local_70 = 0;
      local_78 = local_30;
      local_74 = local_2c;
      local_6c = 0;
      local_68 = 0;
      local_64 = uVar10;
      local_60 = uVar8;
      local_5c = iVar1;
      iVar2 = apupd_db_model_range_handle_for_ui(apupd_callback_model_json_add,&local_78);
      if (iVar2 == -1) {
        __s = (FILE *)0x0;
        if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar3 = "[APUPD_DEBUG]%32s() %05d: get model range failed.\r\n";
          uVar9 = 0x2d6;
          goto LAB_0064228c;
        }
      }
      else {
        __s = fopen("/tmp/apupd_models","w+");
        if (__s == (FILE *)0x0) {
          if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: open get file[%s] fail!\r\n",
                   "apupd_jcs_callback_apupd_models_get",0x2dd,"/tmp/apupd_models");
          }
        }
        else {
          pcVar3 = (char *)json_object_to_json_string_ext(iVar1,0);
          if (pcVar3 == (char *)0x0) {
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar3 = "[APUPD_ERROR]%32s() %05d: JSON_STRING_FROM_OBJ fail!\r\n";
              uVar9 = 0x2e2;
LAB_0064228c:
              printf(pcVar3,"apupd_jcs_callback_apupd_models_get",uVar9);
            }
          }
          else {
            sVar4 = strlen(pcVar3);
            sVar4 = fwrite(pcVar3,sVar4,1,__s);
            if (sVar4 == 1) {
              fclose(__s);
              json_object_put(iVar1);
              uVar9 = json_object_new_string("/tmp/apupd_models");
              json_object_object_add(param_2,"file_name",uVar9);
              uVar9 = json_object_new_int(local_68);
              json_object_object_add(param_2,"totalNum",uVar9);
              uVar9 = 0;
              goto LAB_00642180;
            }
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar3 = "[APUPD_ERROR]%32s() %05d: write result to file fail!\r\n";
              uVar9 = 0x2e8;
              goto LAB_0064228c;
            }
          }
        }
      }
      json_object_put(iVar1);
      uVar9 = 1;
      if (__s != (FILE *)0x0) {
        fclose(__s);
        uVar9 = 1;
      }
      goto LAB_00642180;
    }
    uVar9 = 1;
    if (g_apupd_error == 0) goto LAB_00642180;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar9 = 1;
      goto LAB_00642180;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: malloc json obj failed.\r\n";
    uVar9 = 0x2c7;
  }
  printf(pcVar3,"apupd_jcs_callback_apupd_models_get",uVar9);
  uVar9 = 1;
LAB_00642180:
  uVar9 = json_object_new_int(uVar9);
  json_object_object_add(param_2,&DAT_00676a24,uVar9);
  return;
}

