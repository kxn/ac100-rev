// func _sensor_jcs_discover_trigger @ 004e8bec size=1392

void _sensor_jcs_discover_trigger(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *__s2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined4 local_1958 [24];
  char acStack_18f8 [256];
  undefined2 local_17f8 [1000];
  int local_1028 [1024];
  
  memset(local_17f8,0,2000);
  memcpy(local_1958,&PTR_s_begin_006b1db0,0x60);
  memset(local_1028,0,0x1000);
  iVar1 = json_object_object_get(param_1,"action");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar7 = 0;
    if (iVar2 == 6) {
      iVar2 = 0;
      while( true ) {
        pcVar4 = *(char **)((int)local_1958 + iVar2);
        if (pcVar4 != (char *)0x0) {
          __s2 = (char *)json_object_get_string(iVar1);
          iVar3 = strcmp(pcVar4,__s2);
          if (iVar3 == 0) {
            uVar6 = 0xfffffff4;
            switch(*(undefined4 *)((int)local_1958 + iVar2 + 0xc)) {
            case 0:
              iVar1 = json_object_object_get(param_1,"group_list");
              if (iVar1 == 0) {
                iVar2 = 1;
                local_1028[0] = -1;
                goto LAB_004e8eac;
              }
              iVar2 = json_object_get_type(iVar1);
              if (iVar2 == 5) {
                piVar5 = local_1028;
                iVar7 = 0;
                goto LAB_004e8f38;
              }
              iVar2 = json_object_get_type(iVar1);
              if (iVar2 == 4) {
                iVar1 = json_object_object_length(iVar1);
                iVar2 = 0;
                if (iVar1 == 0) goto LAB_004e8eac;
              }
              iVar2 = 0;
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
                       ,"_sensor_jcs_discover_trigger",0x79b);
              }
              goto LAB_004e8eac;
            case 1:
              uVar6 = sensor_discover_scan_stop();
              goto switchD_004e8dd4_default;
            case 2:
              goto switchD_004e8dd4_caseD_2;
            case 3:
              uVar6 = sensor_backhaul_test_start();
              goto switchD_004e8dd4_default;
            case 4:
              uVar6 = sensor_discover_finish();
              goto switchD_004e8dd4_default;
            case 5:
              uVar6 = sensor_discover_exit();
            default:
              goto switchD_004e8dd4_default;
            }
          }
        }
        iVar7 = iVar7 + 1;
        if (iVar7 == 6) break;
        iVar2 = iVar7 * 0x10;
      }
      if (jcs_err_switch != 0) {
        pcVar4 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
        goto LAB_004e8d3c;
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar4 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004e8d3c:
      printf(pcVar4,"_sensor_jcs_discover_trigger",0x794);
    }
  }
  if (jcs_err_switch == 0) {
    uVar6 = 0xfffffff4;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
           "_sensor_jcs_discover_trigger",0x794);
    uVar6 = 0xfffffff4;
  }
switchD_004e8dd4_default:
  memset(acStack_18f8,0,0x100);
  snprintf(acStack_18f8,0x100,"%d",uVar6);
  uVar6 = json_object_new_string(acStack_18f8);
  json_object_object_add(param_2,&DAT_00676a24,uVar6);
  return;
switchD_004e8dd4_caseD_2:
  iVar1 = json_object_object_get(param_1,"sensor_list");
  if (((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 5)) ||
     (iVar2 = json_object_array_length(iVar1), iVar2 < 1)) {
    uVar6 = 0xfffffff4;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Sensor id count error\n","_sensor_jcs_discover_trigger",0x7b0);
    }
    goto switchD_004e8dd4_default;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 5) {
    puVar8 = local_17f8;
    for (iVar2 = 0; iVar7 = json_object_array_length(iVar1), iVar2 < iVar7; iVar2 = iVar2 + 1) {
      if (iVar2 == 0x400) {
        iVar2 = 0x400;
        break;
      }
      iVar7 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar7 == 0) {
LAB_004e90fc:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_sensor_jcs_discover_trigger",0x7ab);
        }
        *puVar8 = 0xffff;
      }
      else {
        iVar3 = json_object_get_type(iVar7);
        if (iVar3 != 6) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_sensor_jcs_discover_trigger",0x7ab);
          }
          goto LAB_004e90fc;
        }
        pcVar4 = (char *)json_object_get_string(iVar7);
        iVar7 = atoi(pcVar4);
        *puVar8 = (short)iVar7;
      }
      puVar8 = puVar8 + 1;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 4) {
      iVar1 = json_object_object_length(iVar1);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_004e9050;
    }
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n",
             "_sensor_jcs_discover_trigger",0x7ab);
    }
  }
LAB_004e9050:
  uVar6 = sensor_add(local_17f8,iVar2);
  goto switchD_004e8dd4_default;
LAB_004e8f38:
  iVar3 = json_object_array_length(iVar1);
  iVar2 = iVar7;
  if ((iVar3 <= iVar7) || (iVar2 = 0x400, iVar7 == 0x400)) goto LAB_004e8eac;
  iVar2 = json_object_array_get_idx(iVar1,iVar7);
  if (iVar2 == 0) {
LAB_004e8f98:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_sensor_jcs_discover_trigger",0x79b);
    }
    *piVar5 = -1;
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_sensor_jcs_discover_trigger",0x79b);
      }
      goto LAB_004e8f98;
    }
    pcVar4 = (char *)json_object_get_string(iVar2);
    iVar2 = atoi(pcVar4);
    *piVar5 = iVar2;
  }
  iVar7 = iVar7 + 1;
  piVar5 = piVar5 + 1;
  goto LAB_004e8f38;
LAB_004e8eac:
  piVar5 = local_1028;
  if (local_1028[0] == -1) {
    piVar5 = (int *)0x0;
    iVar2 = 0;
  }
  uVar6 = sensor_discover_start(piVar5,iVar2);
  goto switchD_004e8dd4_default;
}

