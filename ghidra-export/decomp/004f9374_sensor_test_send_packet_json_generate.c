// func sensor_test_send_packet_json_generate @ 004f9374 size=2172

char * sensor_test_send_packet_json_generate(uint param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *local_1d8 [3];
  undefined1 auStack_1cc [152];
  char local_134 [260];
  int local_30;
  int local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d send_json_generate ENTER, op_type=%d\n",
           "sensor_test_send_packet_json_generate",0x1c7f,param_1);
  }
  local_1d8[0] = "add_test";
  local_1d8[1] = "del_test";
  local_1d8[2] = "mod_test";
  memset(auStack_1cc,0,0x96);
  if ((2 < param_1) || (param_2 == (undefined4 *)0x0)) {
    if (sensor_test_err_switch == '\0') {
      return (char *)0x0;
    }
    printf("[SENSOR_TEST_ERROR]%s()/%d Input error\n","sensor_test_send_packet_json_generate",0x1c8e
          );
    return (char *)0x0;
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (sensor_test_err_switch == '\0') goto LAB_004f95f0;
    uVar4 = 0x1c95;
LAB_004f9648:
    iVar9 = 0;
    printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n","sensor_test_send_packet_json_generate",
           uVar4);
    iVar10 = 0;
  }
  else {
    iVar2 = json_object_new_object();
    if (iVar2 == 0) {
      if (sensor_test_err_switch != '\0') {
        uVar4 = 0x1c9c;
        goto LAB_004f9648;
      }
LAB_004f95f0:
      iVar9 = 0;
      iVar10 = 0;
    }
    else {
      iVar3 = json_object_new_object();
      if (iVar3 == 0) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n",
                 "sensor_test_send_packet_json_generate",0x1ca3);
        }
        iVar9 = 0;
        if (iVar2 == 0) goto LAB_004f95f0;
        iVar10 = 0;
      }
      else {
        uVar4 = json_object_new_string(&DAT_00697f28);
        json_object_object_add(iVar1,"method",uVar4);
        uVar4 = json_object_new_string("sensor-test");
        json_object_object_add(iVar3,"function",uVar4);
        memset(local_134,0,0x100);
        snprintf(local_134,0x100,"%d",1);
        uVar4 = json_object_new_string(local_134);
        json_object_object_add(iVar3,"radio_id",uVar4);
        memset(local_134,0,0x100);
        snprintf(local_134,0x100,"%d",*param_2);
        uVar4 = json_object_new_string(local_134);
        json_object_object_add(iVar3,"operation_id",uVar4);
        if ((param_1 != 0) && (param_1 != 2)) {
LAB_004f9508:
          json_object_object_add(iVar2,local_1d8[param_1],iVar3);
          json_object_object_add(iVar1,"test_manager",iVar2);
          pcVar8 = (char *)json_object_to_json_string_ext(iVar1,0);
          pcVar8 = strdup(pcVar8);
          iVar10 = iVar1;
          if (pcVar8 != (char *)0x0) goto LAB_004f9550;
          if (sensor_test_err_switch != '\0') {
            uVar4 = 0x1d0c;
            goto LAB_004f9648;
          }
          goto LAB_004f95f0;
        }
        memset(local_134,0,0x100);
        snprintf(local_134,0x100,"%d",(uint)*(byte *)(param_2[1] + 8));
        uVar4 = json_object_new_string(local_134);
        json_object_object_add(iVar3,"change_id",uVar4);
        if (*(short *)param_2[1] == 0) {
          pcVar8 = "0";
        }
        else {
          pcVar8 = "1";
        }
        uVar4 = json_object_new_string(pcVar8);
        json_object_object_add(iVar3,"sch_type",uVar4);
        memset(local_134,0,0x100);
        snprintf(local_134,0x100,"%d",(int)*(short *)(param_2[1] + 2));
        uVar4 = json_object_new_string(local_134);
        json_object_object_add(iVar3,"sch_period",uVar4);
        iVar9 = param_2[1];
        if (*(short *)(iVar9 + 2) == 0) {
          memset(local_134,0,0x100);
          uVar4 = *(undefined4 *)(iVar9 + 4);
        }
        else {
          memset(local_134,0,0x100);
          uVar4 = 0;
        }
        snprintf(local_134,0x100,"%d",uVar4);
        uVar4 = json_object_new_string(local_134);
        json_object_object_add(iVar3,"sch_time",uVar4);
        iVar9 = sensor_test_service_object_generate(param_2[1] + 0x3c);
        if (iVar9 == 0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d Generate service object failed\n",
                   "sensor_test_send_packet_json_generate",0x1cbf);
          }
          iVar9 = 0;
          iVar10 = 0;
        }
        else {
          json_object_object_add(iVar3,"service",iVar9);
          iVar10 = json_object_new_array();
          local_30 = 0;
          if (iVar10 != 0) {
            for (; local_30 < *param_3; local_30 = local_30 + 1) {
              iVar9 = json_object_new_object();
              if (iVar9 == 0) {
                if (sensor_test_err_switch != '\0') {
                  pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d ssid_info_sub_obj Malloc failed\n";
                  uVar4 = 0x1cd4;
LAB_004f9b88:
                  printf(pcVar8,"sensor_test_send_packet_json_generate",uVar4);
                }
                goto LAB_004f9b24;
              }
              iVar11 = local_30 * 0x254;
              pcVar8 = (char *)(param_3[1] + iVar11 + 0xc);
              sVar5 = strlen(pcVar8);
              FUN_00407fc0(pcVar8,sVar5,auStack_1cc,0x96);
              uVar4 = json_object_new_string(auStack_1cc);
              json_object_object_add(iVar9,"ssid",uVar4);
              memset(local_134,0,0x100);
              snprintf(local_134,0x100,"%d",*(undefined4 *)(param_3[1] + iVar11));
              uVar4 = json_object_new_string(local_134);
              json_object_object_add(iVar9,"ssid_code_type",uVar4);
              memset(local_134,0,0x100);
              snprintf(local_134,0x100,"%d",*(undefined4 *)(param_3[1] + iVar11 + 4));
              uVar4 = json_object_new_string(local_134);
              json_object_object_add(iVar9,"encryption",uVar4);
              if (*(int *)(param_3[1] + iVar11 + 4) == 2) {
                uVar4 = json_object_new_string(param_3[1] + iVar11 + 0x3e);
                json_object_object_add(iVar9,"radius_type",uVar4);
                uVar4 = json_object_new_string(param_3[1] + iVar11 + 0x5e);
                json_object_object_add(iVar9,"radius_key",uVar4);
                uVar4 = json_object_new_string(param_3[1] + iVar11 + 0xd6);
                json_object_object_add(iVar9,"radius_username",uVar4);
                iVar7 = param_3[1];
              }
              else {
                iVar7 = param_3[1];
              }
              iVar6 = *(int *)(iVar7 + iVar11 + 4);
              if ((iVar6 == 1) || (iVar6 == 4)) {
                uVar4 = json_object_new_string(iVar7 + iVar11 + 0x1d6);
                json_object_object_add(iVar9,"key",uVar4);
              }
              local_2c = json_object_new_array();
              if (local_2c == 0) {
                if (sensor_test_err_switch != '\0') {
                  pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d bssid_obj Malloc failed\n";
                  uVar4 = 0x1cea;
                  goto LAB_004f9b88;
                }
                goto LAB_004f9b24;
              }
              if (0 < *(int *)(param_3[1] + iVar11 + 8)) {
                local_134[0] = '\0';
                local_134[1] = '\0';
                local_134[2] = '\0';
                local_134[3] = '\0';
                local_134[4] = '\0';
                local_134[5] = '\0';
                local_134[6] = '\0';
                local_134[7] = '\0';
                local_134[8] = '\0';
                local_134[9] = '\0';
                local_134[10] = '\0';
                local_134[0xb] = '\0';
                local_134[0xc] = '\0';
                local_134[0xd] = '\0';
                local_134[0xe] = '\0';
                local_134[0xf] = '\0';
                local_134[0x10] = '\0';
                local_134[0x11] = '\0';
                local_134[0x12] = '\0';
                local_134[0x13] = '\0';
                for (iVar7 = 0; iVar7 < *(int *)(param_3[1] + iVar11 + 8); iVar7 = iVar7 + 1) {
                  iVar6 = *(int *)(param_3[1] + iVar11 + 0x250) + iVar7 * 0x18;
                  snprintf(local_134,0x14,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",
                           (uint)*(byte *)(iVar6 + 0xc),(uint)*(byte *)(iVar6 + 0xd),
                           (uint)*(byte *)(iVar6 + 0xe),(uint)*(byte *)(iVar6 + 0xf),
                           (uint)*(byte *)(iVar6 + 0x10),(uint)*(byte *)(iVar6 + 0x11));
                  uVar4 = json_object_new_string(local_134);
                  json_object_array_add(local_2c,uVar4);
                }
              }
              json_object_object_add(iVar9,"bssid",local_2c);
              json_object_array_add(iVar10,iVar9);
            }
            json_object_object_add(iVar3,"ssid_info",iVar10);
            goto LAB_004f9508;
          }
          iVar9 = 0;
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d ssid_info_obj Malloc failed\n",
                   "sensor_test_send_packet_json_generate",0x1cca);
            iVar9 = 0;
          }
        }
LAB_004f9b24:
        json_object_put(iVar3);
      }
      json_object_put(iVar2);
    }
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (iVar9 != 0) {
    json_object_put(iVar9);
  }
  pcVar8 = (char *)0x0;
  if (iVar10 == 0) {
    return (char *)0x0;
  }
LAB_004f9550:
  json_object_put(iVar10);
  return pcVar8;
}

