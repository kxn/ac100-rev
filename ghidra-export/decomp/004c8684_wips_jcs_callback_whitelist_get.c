// func wips_jcs_callback_whitelist_get @ 004c8684 size=900

void wips_jcs_callback_whitelist_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch == '\0') {
      uVar4 = 0xffffffff;
      goto LAB_004c888c;
    }
    __format = "[SENSOR_ERROR]%s()/%d inputs error.\n";
    uVar4 = 0x78b;
  }
  else {
    iVar1 = json_object_new_array();
    if (iVar1 != 0) {
      uVar5 = 0;
      iVar2 = json_object_object_get(param_1,"start");
      if (iVar2 != 0) {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          uVar5 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 == 2) {
            uVar8 = json_object_get_double(iVar2);
            uVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
          }
          else {
            uVar5 = 0xffffffff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "wips_jcs_callback_whitelist_get",0x797);
            }
          }
        }
      }
      iVar2 = json_object_object_get(param_1,"size");
      if (iVar2 == 0) {
        uVar7 = (uint)g_wips_info_max_size;
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          uVar7 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 == 2) {
            uVar8 = json_object_get_double(iVar2);
            uVar7 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
          }
          else {
            uVar7 = 0xffffffff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "wips_jcs_callback_whitelist_get",0x799);
            }
          }
        }
      }
      uVar6 = 0;
      FUN_004082d0(wips_global_mutex,0xffffffff);
      iVar2 = FUN_004081b0(&g_white_list);
      while (iVar2 != 0) {
        if ((uVar5 <= uVar6) && (uVar6 < uVar7 + uVar5)) {
          iVar3 = json_object_new_object();
          if (iVar3 == 0) {
            if (sensor_err_switch != '\0') {
              printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n",
                     "wips_jcs_callback_whitelist_get",0x7a3);
            }
            FUN_00407f30(wips_global_mutex);
            json_object_put(iVar1);
            uVar4 = 0xffffffff;
            goto LAB_004c888c;
          }
          wips_whitelist_to_json(iVar2,iVar3);
          json_object_array_add(iVar1,iVar3);
        }
        iVar2 = FUN_00408680(iVar2);
        uVar6 = uVar6 + 1;
      }
      FUN_00407f30(wips_global_mutex);
      local_30 = uVar7 + uVar5;
      local_38 = uVar6;
      local_34 = uVar5;
      local_2c = iVar1;
      wserv_db_entry_for_each(_wips_wserv_to_json,&local_38);
      json_object_object_add(param_2,"result",iVar1);
      uVar4 = json_object_new_int(local_38);
      json_object_object_add(param_2,"count",uVar4);
      uVar4 = 0;
      goto LAB_004c888c;
    }
    if (sensor_err_switch == '\0') {
      uVar4 = 0xffffffff;
      goto LAB_004c888c;
    }
    __format = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
    uVar4 = 0x792;
  }
  printf(__format,"wips_jcs_callback_whitelist_get",uVar4);
  uVar4 = 0xffffffff;
LAB_004c888c:
  uVar4 = json_object_new_int(uVar4);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return;
}

