// func _sensor_jcs_sensor_list_added_get @ 004e3afc size=2116

void _sensor_jcs_sensor_list_added_get(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  FILE *__s;
  char *__format;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined4 local_588;
  undefined4 local_584;
  undefined4 local_580;
  undefined4 local_57c;
  undefined4 local_578;
  char acStack_574 [256];
  undefined1 auStack_474 [218];
  char acStack_39a [65];
  char local_359 [81];
  undefined1 auStack_308 [18];
  ushort local_2f6;
  undefined4 local_2c8;
  undefined1 auStack_2c0 [6];
  undefined1 auStack_2ba [458];
  undefined1 auStack_f0 [192];
  int local_30;
  int local_2c;
  
  memset(auStack_474,0,0x168);
  memset(auStack_308,0,0x2d8);
  local_588 = 0;
  local_584 = 0;
  local_580 = 0;
  local_57c = 0;
  local_578 = 0;
  iVar2 = json_object_object_get(param_1,"start");
  if (iVar2 == 0) {
    iVar2 = 0;
    bVar1 = false;
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      bVar1 = true;
      iVar2 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar14 = json_object_get_double(iVar2);
        iVar2 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
      }
      else {
        if (jcs_err_switch != 0) {
          iVar2 = -1;
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_jcs_sensor_list_added_get",0x7e3);
          bVar1 = true;
          goto LAB_004e3bbc;
        }
        iVar2 = -1;
      }
      bVar1 = true;
    }
  }
LAB_004e3bbc:
  iVar3 = json_object_object_get(param_1,"end");
  if (iVar3 == 0) {
    iVar3 = 0;
    bVar1 = false;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      iVar3 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 == 2) {
        uVar14 = json_object_get_double(iVar3);
        iVar3 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
      }
      else {
        iVar3 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_jcs_sensor_list_added_get",0x7ee);
        }
      }
    }
  }
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d start=%d, end=%d\n","_sensor_jcs_sensor_list_added_get",0x7f7,
           iVar2,iVar3);
  }
  if ((iVar2 < 0) || (iVar3 < iVar2)) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d start or end invalid\n","_sensor_jcs_sensor_list_added_get",
             0x7fa);
    }
    __s = (FILE *)0x0;
    pcVar11 = (char *)0x0;
    iVar4 = 0;
    uVar10 = 0xfffffff4;
  }
  else if (((g_sensor_enable == 0) || (g_backhaul_wserv_id == -1)) || (g_sensor_state != 3)) {
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Sensor(%d) is closed or g_backhaul_wserv_id(%d) or state(%d) is error\n"
             ,"_sensor_jcs_sensor_list_added_get",0x801,g_sensor_enable,g_backhaul_wserv_id,
             g_sensor_state);
    }
    __s = (FILE *)0x0;
    pcVar11 = (char *)0x0;
    iVar4 = 0;
    uVar10 = 0xfffffffe;
  }
  else if ((unfinished_sensor_num < 1) || (unfinished_sensor_list != 0)) {
    iVar9 = json_object_new_array();
    iVar4 = unfinished_sensor_num;
    if (iVar9 == 0) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d mem malloc sensor_list_obj fail\n",
               "_sensor_jcs_sensor_list_added_get",0x80e);
      }
      __s = (FILE *)0x0;
      pcVar11 = (char *)0x0;
      iVar4 = 0;
      uVar10 = 0xffffffff;
      goto LAB_004e3c60;
    }
    if (0 < unfinished_sensor_num) {
      iVar13 = 0;
      if (!bVar1) {
        iVar3 = unfinished_sensor_num + -1;
        iVar2 = 0;
      }
      local_2c = 0;
      local_30 = 0;
      while (iVar13 < unfinished_sensor_num_first) {
        iVar12 = iVar13 * 0x30;
        iVar5 = local_30;
        if ((*(short *)(unfinished_sensor_list + iVar12) == -1) ||
           (iVar5 = local_30 + 1, local_30 < iVar2)) {
LAB_004e3edc:
          local_30 = iVar5;
          iVar13 = iVar13 + 1;
        }
        else {
          iVar5 = json_object_new_object();
          if (iVar5 == 0) {
            if (sensor_warning_switch == '\0') {
              iVar13 = iVar13 + 1;
            }
            else {
              printf("[SENSOR_WARNING]%s()/%d mem malloc sensor_item_obj fail\n",
                     "_sensor_jcs_sensor_list_added_get",0x82a);
              iVar13 = iVar13 + 1;
            }
          }
          else {
            memset(auStack_308,0,0x2d8);
            iVar6 = apmngr_db_entry_get_by_id
                              (*(undefined2 *)(unfinished_sensor_list + iVar12),auStack_308);
            if (iVar6 != -1) {
              memset(acStack_574,0,0x100);
              snprintf(acStack_574,0x100,"%d",(uint)*(ushort *)(unfinished_sensor_list + iVar12));
              uVar10 = json_object_new_string(acStack_574);
              json_object_object_add(iVar5,"ap_id",uVar10);
              FUN_004e3340(auStack_2c0,&local_588);
              uVar10 = json_object_new_string(&local_588);
              json_object_object_add(iVar5,"mac",uVar10);
              uVar10 = json_object_new_string(auStack_2ba);
              json_object_object_add(iVar5,"name",uVar10);
              memset(acStack_574,0,0x100);
              snprintf(acStack_574,0x100,"%d",(uint)local_2f6);
              uVar10 = json_object_new_string(acStack_574);
              json_object_object_add(iVar5,"group_id",uVar10);
              iVar6 = apdb_get_ap_by_id(local_2c8,auStack_f0,auStack_474);
              if (iVar6 == 0) {
                pcVar11 = local_359;
                if (local_359[0] == '\0') {
                  pcVar11 = acStack_39a;
                }
                uVar10 = json_object_new_string(pcVar11);
                json_object_object_add(iVar5,"model_name",uVar10);
              }
              memset(acStack_574,0,0x100);
              snprintf(acStack_574,0x100,"%d",*(undefined4 *)(unfinished_sensor_list + iVar12 + 4));
              uVar10 = json_object_new_string(acStack_574);
              json_object_object_add(iVar5,"test_status",uVar10);
              json_object_array_add(iVar9,iVar5);
              local_2c = local_2c + 1;
              iVar5 = local_30;
              if (local_2c <= (iVar3 - iVar2) + 1) goto LAB_004e3edc;
              break;
            }
            if (sensor_err_switch != '\0') {
              printf("[SENSOR_ERROR]%s()/%d apmngr_db_entry_get_by_id fail\n",
                     "_sensor_jcs_sensor_list_added_get",0x830);
            }
            json_object_put(iVar5);
            iVar13 = iVar13 + 1;
          }
        }
      }
    }
    pcVar11 = (char *)json_object_to_json_string_ext(iVar9,0);
    pcVar11 = strdup(pcVar11);
    if (pcVar11 == (char *)0x0) {
      if (sensor_err_switch == '\0') {
        __s = (FILE *)0x0;
        uVar10 = 0xffffffff;
      }
      else {
        __s = (FILE *)0x0;
        printf("[SENSOR_ERROR]%s()/%d generate ret_str failed\n","_sensor_jcs_sensor_list_added_get"
               ,0x850);
        uVar10 = 0xffffffff;
      }
      goto LAB_004e3c60;
    }
    json_object_put(iVar9);
    sVar7 = strlen(pcVar11);
    __s = fopen("/tmp/sensor_list_added","w+");
    if (__s == (FILE *)0x0) {
      if (sensor_err_switch != '\0') {
        __format = "[SENSOR_ERROR]%s()/%d open result file failed.\n";
        uVar8 = 0x85d;
LAB_004e4204:
        uVar10 = 0xffffffff;
        printf(__format,"_sensor_jcs_sensor_list_added_get",uVar8);
        iVar9 = 0;
        goto LAB_004e3c60;
      }
      uVar10 = 0xffffffff;
    }
    else {
      sVar7 = fwrite(pcVar11,(int)(short)sVar7,1,__s);
      uVar10 = 0;
      if (sVar7 != 1) {
        if (sensor_err_switch != '\0') {
          __format = "[SENSOR_ERROR]%s()/%d write result to file failed.\n";
          uVar8 = 0x864;
          goto LAB_004e4204;
        }
        uVar10 = 0xffffffff;
      }
    }
  }
  else {
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Some error occured\n","_sensor_jcs_sensor_list_added_get",
             0x807);
    }
    __s = (FILE *)0x0;
    pcVar11 = (char *)0x0;
    iVar4 = 0;
    uVar10 = 0xffffffff;
  }
  iVar9 = 0;
LAB_004e3c60:
  FUN_00407f30(g_sensor_mngt_mutex);
  if (iVar9 != 0) {
    json_object_put(iVar9);
  }
  if (pcVar11 != (char *)0x0) {
    free(pcVar11);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  memset(acStack_574,0,0x100);
  snprintf(acStack_574,0x100,"%d",uVar10);
  uVar10 = json_object_new_string(acStack_574);
  json_object_object_add(param_2,&DAT_00676a24,uVar10);
  memset(acStack_574,0,0x100);
  snprintf(acStack_574,0x100,"%d",iVar4);
  uVar10 = json_object_new_string(acStack_574);
  json_object_object_add(param_2,"total_num",uVar10);
  uVar10 = json_object_new_string("/tmp/sensor_list_added");
  json_object_object_add(param_2,"file_name",uVar10);
  return;
}

