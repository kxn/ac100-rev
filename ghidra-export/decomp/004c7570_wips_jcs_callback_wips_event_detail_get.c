// func wips_jcs_callback_wips_event_detail_get @ 004c7570 size=1104

void wips_jcs_callback_wips_event_detail_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch == '\0') {
      uVar5 = 0xffffffff;
      goto LAB_004c763c;
    }
    pcVar6 = "[SENSOR_ERROR]%s()/%d inputs error.\n";
    uVar5 = 0x72c;
  }
  else {
    iVar1 = json_object_new_array();
    if (iVar1 != 0) {
      iVar2 = json_object_object_get(param_1,"wips_info_id");
      if (iVar2 == 0) {
        if (sensor_err_switch != '\0') {
          pcVar6 = "[SENSOR_ERROR]%s()/%d get key[wips_info_id] error\n";
          uVar5 = 0x73b;
LAB_004c78bc:
          printf(pcVar6,"wips_jcs_callback_wips_event_detail_get",uVar5);
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          iVar2 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 == 2) {
            uVar10 = json_object_get_double(iVar2);
            iVar2 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
          }
          else {
            iVar2 = -1;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "wips_jcs_callback_wips_event_detail_get",0x73e);
            }
          }
        }
        iVar3 = FUN_004086a0(g_wips_id_allocator,iVar2);
        if (iVar3 != 0) {
          uVar9 = 0;
          iVar3 = json_object_object_get(param_1,"start");
          if (iVar3 != 0) {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              uVar9 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 == 2) {
                uVar10 = json_object_get_double(iVar3);
                uVar9 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
              }
              else {
                uVar9 = 0xffffffff;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"wips_jcs_callback_wips_event_detail_get",0x746);
                }
              }
            }
          }
          iVar3 = json_object_object_get(param_1,"size");
          if (iVar3 == 0) {
            uVar7 = (uint)g_wips_info_max_size;
          }
          else {
            iVar4 = json_object_get_type(iVar3);
            if (iVar4 == 3) {
              uVar7 = json_object_get_int(iVar3);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 == 2) {
                uVar10 = json_object_get_double(iVar3);
                uVar7 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
              }
              else {
                uVar7 = 0xffffffff;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"wips_jcs_callback_wips_event_detail_get",0x748);
                }
              }
            }
          }
          uVar8 = 0;
          FUN_004082d0(wips_global_mutex,0xffffffff);
          iVar2 = FUN_004081b0(*(int *)(g_wips_id2entry + iVar2 * 4) + 0x9c);
          while (iVar2 != 0) {
            if ((uVar9 <= uVar8) && (uVar8 < uVar7 + uVar9)) {
              iVar3 = json_object_new_object();
              if (iVar3 == 0) {
                if (sensor_err_switch == '\0') goto LAB_004c7630;
                pcVar6 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
                uVar5 = 0x752;
                goto LAB_004c78bc;
              }
              wips_detail_to_json(iVar2,iVar3);
              json_object_array_add(iVar1,iVar3);
            }
            iVar2 = FUN_00408680(iVar2);
            uVar8 = uVar8 + 1;
          }
          FUN_00407f30(wips_global_mutex);
          json_object_object_add(param_2,"result",iVar1);
          uVar5 = json_object_new_int(uVar8);
          json_object_object_add(param_2,"count",uVar5);
          uVar5 = 0;
          goto LAB_004c763c;
        }
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d wips event[id=%d] not found\n",
                 "wips_jcs_callback_wips_event_detail_get",0x741,iVar2);
        }
      }
LAB_004c7630:
      FUN_00407df0(iVar1);
      uVar5 = 0xffffffff;
      goto LAB_004c763c;
    }
    if (sensor_err_switch == '\0') {
      uVar5 = 0xffffffff;
      goto LAB_004c763c;
    }
    pcVar6 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
    uVar5 = 0x733;
  }
  printf(pcVar6,"wips_jcs_callback_wips_event_detail_get",uVar5);
  uVar5 = 0xffffffff;
LAB_004c763c:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
  return;
}

