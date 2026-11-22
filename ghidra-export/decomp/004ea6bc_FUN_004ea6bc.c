// func FUN_004ea6bc @ 004ea6bc size=1652

undefined4 FUN_004ea6bc(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined2 local_c0 [2];
  int local_bc;
  int local_b8;
  undefined8 local_b0;
  int local_a8;
  undefined4 local_a0;
  int local_9c;
  undefined4 local_68;
  char acStack_64 [50];
  undefined1 local_32;
  int local_30;
  int local_2c;
  
  memset(&local_68,0,0x38);
  memset(&local_a0,0,0x38);
  memset(local_c0,0,0x20);
  if (*(int *)(param_2 + 0x14) != 7) {
    if (sensor_warning_switch == '\0') {
      return 0;
    }
    printf("[SENSOR_WARNING]%s()/%d Not sensor,ignore the packet.\n",
           "_sensor_pkt_passthrough_callback",0x125);
    return 0;
  }
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d Receive json: %s\n","_sensor_pkt_passthrough_callback",0x128,
           param_1);
  }
  local_a0 = 0;
  local_68 = 1;
  iVar2 = json_tokener_parse(param_1);
  if (iVar2 == 0) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Invalid json string: %s\n","_sensor_pkt_passthrough_callback",
           0x12e,param_1);
    return 0xffffffff;
  }
  if (param_3 == 1) {
    pcVar6 = "eventList";
LAB_004ea844:
    iVar3 = json_object_object_get(iVar2,pcVar6);
    if ((iVar3 != 0) && (iVar4 = json_object_get_type(iVar3), iVar4 == 5)) {
      iVar4 = json_object_array_length(iVar3);
      local_30 = 0;
      if (0 < iVar4) {
        do {
          iVar4 = json_object_array_length(iVar3);
          if (iVar4 <= local_30) {
            json_object_put(iVar2);
            return 0;
          }
          uVar7 = json_object_array_get_idx(iVar3,local_30);
          iVar4 = json_object_object_get(uVar7,"function");
          local_2c = 0;
          if (iVar4 != 0) {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 6) {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 == 6) {
                pcVar6 = (char *)json_object_get_string(iVar4);
                strncpy(acStack_64,pcVar6,0x32);
                local_32 = 0;
                local_2c = 1;
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_pkt_passthrough_callback",0x14c);
                }
                strncpy(acStack_64,"",0x32);
                local_32 = 0;
                local_2c = 1;
              }
            }
          }
          bVar1 = false;
          iVar4 = json_object_object_get(uVar7,"typeId");
          if (iVar4 != 0) {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 6) {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 == 6) {
                pcVar6 = (char *)json_object_get_string(iVar4);
                bVar1 = true;
                local_9c = atoi(pcVar6);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                         "_sensor_pkt_passthrough_callback",0x152);
                }
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                         "_sensor_pkt_passthrough_callback",0x152);
                }
                local_9c = -1;
                bVar1 = true;
              }
            }
          }
          iVar4 = json_object_object_get(uVar7,"params");
          if (iVar4 == 0) {
            if (sensor_warning_switch != '\0') {
              pcVar6 = "[SENSOR_WARNING]%s()/%d Can not find params in json %s\n";
              uVar7 = 0x158;
LAB_004eab50:
              printf(pcVar6,"_sensor_pkt_passthrough_callback",uVar7,param_1);
            }
          }
          else if (bVar1 || local_2c != 0) {
            local_c0[0] = *(undefined2 *)(param_2 + 0x10);
            local_a8 = iVar4;
            iVar4 = json_object_object_get(uVar7,"operationId");
            if (iVar4 == 0) {
LAB_004eaa18:
              local_bc = -1;
            }
            else {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 != 6) {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                         "_sensor_pkt_passthrough_callback",0x160);
                }
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                         "_sensor_pkt_passthrough_callback",0x160);
                }
                goto LAB_004eaa18;
              }
              pcVar6 = (char *)json_object_get_string(iVar4);
              local_bc = atoi(pcVar6);
            }
            iVar4 = json_object_object_get(uVar7,"changeId");
            if (iVar4 == 0) {
LAB_004eaa68:
              local_b8 = -1;
            }
            else {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 != 6) {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                         "_sensor_pkt_passthrough_callback",0x162);
                }
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                         "_sensor_pkt_passthrough_callback",0x162);
                }
                goto LAB_004eaa68;
              }
              pcVar6 = (char *)json_object_get_string(iVar4);
              local_b8 = atoi(pcVar6);
            }
            iVar4 = json_object_object_get(uVar7,"time");
            if (iVar4 == 0) {
LAB_004eaab8:
              lVar8 = -1;
            }
            else {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 != 6) {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                         "_sensor_pkt_passthrough_callback",0x164);
                }
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: transfer string to int64 failed.\n",
                         "_sensor_pkt_passthrough_callback",0x164);
                }
                goto LAB_004eaab8;
              }
              pcVar6 = (char *)json_object_get_string(iVar4);
              lVar8 = strtoll(pcVar6,(char **)0x0,0);
            }
            local_b0 = lVar8;
            if (local_2c != 0) {
              sensor_stats_cb_handle(&local_68,local_c0);
            }
            if (bVar1) {
              sensor_stats_cb_handle(&local_a0,local_c0);
            }
          }
          else if (sensor_warning_switch != '\0') {
            pcVar6 = "[SENSOR_WARNING]%s()/%d Can not find function or typeid in %s\n";
            uVar7 = 0x170;
            goto LAB_004eab50;
          }
          local_30 = local_30 + 1;
        } while( true );
      }
    }
    if (sensor_err_switch == '\0') goto LAB_004ea7c8;
    pcVar6 = "[SENSOR_ERROR]%s()/%d Invalid json string: %s\n";
    uVar7 = 0x140;
  }
  else {
    if (param_3 == 4) {
      pcVar6 = "operationResultList";
      goto LAB_004ea844;
    }
    if (sensor_err_switch == '\0') goto LAB_004ea7c8;
    pcVar6 = "[SENSOR_ERROR]%s()/%d Illegal type: %d\n";
    uVar7 = 0x13b;
    param_1 = param_3;
  }
  printf(pcVar6,"_sensor_pkt_passthrough_callback",uVar7,param_1);
LAB_004ea7c8:
  json_object_put(iVar2);
  return 0xffffffff;
}

