// func jcs_deep_inspection_setting @ 004dbcb8 size=2128

void jcs_deep_inspection_setting(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  char *pcVar8;
  size_t __n;
  undefined4 *__s;
  undefined4 *puVar9;
  undefined8 uVar10;
  char local_320 [16];
  uint local_310;
  undefined1 auStack_308 [32];
  int local_2e8;
  undefined1 auStack_2ba [650];
  int local_30;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_setting ENTER\n",
           "jcs_deep_inspection_setting",0x8f3);
  }
  local_320[0] = '\0';
  local_320[1] = '\0';
  local_320[2] = '\0';
  local_320[3] = '\0';
  local_320[4] = '\0';
  local_320[5] = '\0';
  local_320[6] = '\0';
  local_320[7] = '\0';
  local_320[8] = '\0';
  local_320[9] = '\0';
  local_320[10] = '\0';
  local_320[0xb] = '\0';
  local_320[0xc] = '\0';
  local_320[0xd] = '\0';
  local_320[0xe] = '\0';
  local_320[0xf] = '\0';
  local_310 = 0;
  memset(auStack_308,0,0x2d8);
  iVar1 = json_object_object_get(param_1,"switch");
  if (iVar1 == 0) {
    if (sensor_di_err_switch != 0) {
      pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : switch not found\n";
      uVar3 = 0x905;
      goto LAB_004dc2ac;
    }
    iVar1 = -1;
LAB_004dc158:
    __s = (undefined4 *)0x0;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar10 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_deep_inspection_setting",0x908);
        }
      }
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : is_switch_on=%d\n","jcs_deep_inspection_setting",0x909
             ,iVar1);
    }
    if (iVar1 != 1) {
      iVar1 = sensor_di_handler_stop_cur_deep_inspection();
      if (iVar1 != -1) {
LAB_004dbd9c:
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_setting success EXIT\n",
                 "jcs_deep_inspection_setting",0x97e);
        }
        uVar3 = json_object_new_int(0);
        pcVar8 = "ret";
        goto LAB_004dbdcc;
      }
      if (sensor_di_err_switch != 0) {
        pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : stop_cur_deep_inspection fail\n";
        uVar3 = 0x973;
        goto LAB_004dc2ac;
      }
      iVar1 = -1;
      goto LAB_004dc158;
    }
    iVar1 = _sensor_di_get_cur_status();
    if (iVar1 == 1) {
      if (sensor_di_debug_switch != 0) {
        iVar1 = -5;
        printf("[SENSOR_DI_DEBUG]%s()/line %d : a deep checkup already running \n",
               "jcs_deep_inspection_setting",0x90e);
        __s = (undefined4 *)0x0;
        goto LAB_004dc160;
      }
      iVar1 = -5;
      goto LAB_004dc158;
    }
    iVar2 = 0;
    iVar1 = json_object_object_get(param_1,"use_previous_setting");
    if (iVar1 != 0) {
      local_320[0] = '\0';
      local_320[1] = '\0';
      local_320[2] = '\0';
      local_320[3] = '\0';
      local_320[4] = '\0';
      local_320[5] = '\0';
      local_320[6] = '\0';
      local_320[7] = '\0';
      local_320[8] = '\0';
      local_320[9] = '\0';
      local_320[10] = '\0';
      local_320[0xb] = '\0';
      local_320[0xc] = '\0';
      local_320[0xd] = '\0';
      local_320[0xe] = '\0';
      local_320[0xf] = '\0';
      local_310 = 0;
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar8 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "jcs_deep_inspection_setting",0x917);
        }
        pcVar8 = "";
      }
      strncpy(local_320,pcVar8,0x13);
      local_310 = local_310 & 0xffffff00;
      iVar2 = atoi(local_320);
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : is_use_pre_setting=%d\n","jcs_deep_inspection_setting"
             ,0x91e,iVar2);
    }
    __s = (undefined4 *)0x0;
    if (iVar2 != 0) {
LAB_004dc258:
      iVar1 = sensor_di_handler_start_new_deep_inspection();
      if (iVar1 != 0) {
        if (sensor_di_err_switch != 0) {
          pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : start_new_deep_inspection fail\n";
          uVar3 = 0x96b;
          goto LAB_004dc28c;
        }
        goto LAB_004dc160;
      }
      if (__s != (undefined4 *)0x0) {
        FUN_00407df0(__s);
      }
      goto LAB_004dbd9c;
    }
    iVar1 = json_object_object_get(param_1,"deep_inspection_set");
    if (((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 5)) ||
       (iVar2 = json_object_array_length(iVar1), iVar2 < 1)) {
      if (sensor_di_err_switch == 0) {
        iVar1 = -1;
        goto LAB_004dc158;
      }
      pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : get deep_inspection set fail\n";
      uVar3 = 0x92f;
LAB_004dc2ac:
      iVar1 = -1;
      printf(pcVar8,"jcs_deep_inspection_setting",uVar3);
      __s = (undefined4 *)0x0;
    }
    else {
      local_30 = json_object_array_length(iVar1);
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : array valid,length=%d\n",
               "jcs_deep_inspection_setting",0x926,local_30);
      }
      if (local_30 < 1) {
        if (sensor_di_err_switch != 0) {
          pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : length <= 0\n";
          uVar3 = 0x929;
          goto LAB_004dc2ac;
        }
        iVar1 = -1;
        goto LAB_004dc158;
      }
      __n = local_30 * 0xa4;
      __s = (undefined4 *)FUN_00408450(__n,0x932);
      if (__s == (undefined4 *)0x0) {
        iVar1 = -1;
        if (sensor_di_err_switch != 0) {
          pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
          uVar3 = 0x935;
LAB_004dc28c:
          printf(pcVar8,"jcs_deep_inspection_setting",uVar3);
        }
      }
      else {
        iVar2 = 0;
        memset(__s,0,__n);
        puVar9 = __s;
        do {
          iVar4 = json_object_array_get_idx(iVar1,iVar2);
          if (iVar4 == 0) {
            iVar1 = -1;
            if (sensor_di_err_switch == 0) goto LAB_004dc160;
            pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : get item_obj fail\n";
            uVar3 = 0x93f;
            goto LAB_004dc28c;
          }
          iVar5 = json_object_object_get(iVar4,"entry_id");
          if (iVar5 == 0) {
LAB_004dbff8:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_deep_inspection_setting",0x943);
            }
            uVar3 = 0xffffffff;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              uVar3 = json_object_get_int(iVar5);
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_004dbff8;
              uVar10 = json_object_get_double(iVar5);
              uVar3 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
            }
          }
          *puVar9 = uVar3;
          memset(auStack_308,0,0x2d8);
          iVar5 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)puVar9 + 2),auStack_308);
          if (iVar5 == -1) {
            iVar1 = -2;
            goto LAB_004dc160;
          }
          if (local_2e8 == 0) {
            iVar1 = -3;
            goto LAB_004dc160;
          }
          memcpy(puVar9 + 2,auStack_2ba,0x9a);
          iVar5 = json_object_object_get(iVar4,"inspection_item");
          if (iVar5 == 0) {
LAB_004dc088:
            if (jcs_err_switch == 0) {
              uVar7 = 0;
            }
            else {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_deep_inspection_setting",0x957);
              uVar7 = 0;
            }
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              iVar5 = json_object_get_int(iVar5);
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_004dc088;
              uVar10 = json_object_get_double(iVar5);
              iVar5 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
            }
            uVar7 = 5;
            if (((iVar5 != 1) && (uVar7 = 6, iVar5 != 2)) && (uVar7 = 7, iVar5 != 3)) {
              uVar7 = 0;
            }
          }
          *(undefined1 *)(puVar9 + 1) = uVar7;
          iVar4 = json_object_object_get(iVar4,"inspection_band");
          if (iVar4 == 0) {
LAB_004dc0dc:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "jcs_deep_inspection_setting",0x95c);
            }
            *(undefined1 *)((int)puVar9 + 5) = 0xff;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              uVar7 = json_object_get_int(iVar4);
              *(undefined1 *)((int)puVar9 + 5) = uVar7;
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 != 2) goto LAB_004dc0dc;
              uVar10 = json_object_get_double(iVar4);
              uVar7 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
              *(undefined1 *)((int)puVar9 + 5) = uVar7;
            }
          }
          if (sensor_di_debug_switch != 0) {
            printf("[SENSOR_DI_DEBUG]%s()/line %d : di_set[%d]{entry_id=%d, inspection_item=%d, inspection_band=%d}\n"
                   ,"jcs_deep_inspection_setting",0x95e,iVar2,*puVar9,(uint)*(byte *)(puVar9 + 1),
                   (uint)*(byte *)((int)puVar9 + 5));
          }
          iVar2 = iVar2 + 1;
          puVar9 = puVar9 + 0x29;
        } while (iVar2 != local_30);
        iVar1 = sensor_di_db_set_di_setting(__s,iVar2);
        if (iVar1 != -1) goto LAB_004dc258;
        iVar1 = -1;
        if (sensor_di_err_switch != 0) {
          pcVar8 = "[SENSOR_DI_ERROR]%s()/line %d : db set di_setting fail\n";
          uVar3 = 0x963;
          goto LAB_004dc28c;
        }
      }
    }
  }
LAB_004dc160:
  if (sensor_di_err_switch != 0) {
    printf("[SENSOR_DI_ERROR]%s()/line %d : jcs_deep_inspection_setting fail EXIT\n",
           "jcs_deep_inspection_setting",0x983);
  }
  if (__s != (undefined4 *)0x0) {
    FUN_00407df0(__s);
  }
  uVar3 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  uVar3 = json_object_new_int(iVar1);
  pcVar8 = "err_code";
LAB_004dbdcc:
  json_object_object_add(param_2,pcVar8,uVar3);
  return;
}

