// func wips_jcs_callback_statistics_get @ 004c6adc size=2708

void wips_jcs_callback_statistics_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  void *__s;
  void *__s_00;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  size_t __n;
  ushort *puVar12;
  ushort *puVar13;
  uint uVar14;
  short sVar15;
  undefined4 local_bf0;
  undefined4 local_bec;
  undefined2 local_be8;
  undefined1 auStack_be4 [20];
  undefined1 auStack_bd0 [112];
  char acStack_b60 [256];
  ushort local_a60 [144];
  ushort local_940 [144];
  ushort local_820 [144];
  ushort local_700 [144];
  undefined1 auStack_5e0 [16];
  ushort local_5d0;
  ushort local_5ce;
  undefined1 auStack_308 [78];
  undefined1 auStack_2ba [650];
  int local_30;
  size_t local_2c;
  
  local_bf0 = 0;
  local_bec = 0;
  local_be8 = 0;
  local_30 = apmngr_db_get_group_max();
  memset(auStack_be4,0,0x84);
  memset(auStack_308,0,0x2d8);
  memset(auStack_5e0,0,0x2d8);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch == '\0') {
      uVar8 = 0xffffffff;
      goto LAB_004c6e8c;
    }
    pcVar10 = "[SENSOR_ERROR]%s()/%d inputs error.\n";
    pcVar11 = "wips_jcs_callback_statistics_get";
    uVar8 = 0x8c9;
  }
  else {
    iVar1 = json_object_object_get(param_1,"type");
    if (iVar1 == 0) {
LAB_004c6e88:
      uVar8 = 0xffffffff;
      goto LAB_004c6e8c;
    }
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar10 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_jcs_callback_statistics_get",0x8d3);
      }
      pcVar10 = "";
    }
    strncpy((char *)&local_bf0,pcVar10,9);
    iVar1 = strncmp((char *)&local_bf0,"time",10);
    if (iVar1 == 0) {
      memset(local_700,0,0x120);
      memset(local_820,0,0x120);
      memset(local_940,0,0x120);
      memset(local_a60,0,0x120);
      local_30 = wips_local_time_get();
      iVar2 = local_30 + -0x15180;
      iVar1 = json_object_new_array();
      if (iVar1 != 0) {
        memset(local_700,0,0x120);
        puVar3 = local_a60;
        memset(local_820,0,0x120);
        puVar4 = local_700;
        memset(local_940,0,0x120);
        puVar12 = local_820;
        memset(local_a60,0,0x120);
        puVar13 = local_940;
        FUN_004082d0(wips_global_mutex,0xffffffff);
        iVar5 = iVar2;
        do {
          iVar6 = FUN_004081b0(&g_wips_list);
          local_2c = iVar5 + 600;
          for (; iVar6 != 0; iVar6 = FUN_00408680(iVar6)) {
            iVar7 = FUN_004081b0(iVar6 + 0x9c);
            if (iVar7 != 0) {
              iVar9 = *(int *)(iVar7 + 0x24);
              while ((iVar9 < iVar5 || (local_2c < *(uint *)(iVar7 + 0x20)))) {
                iVar7 = FUN_00408680(iVar7);
                if (iVar7 == 0) goto LAB_004c7028;
                iVar9 = *(int *)(iVar7 + 0x24);
              }
              if (*(int *)(iVar6 + 0x94) == 1) {
                *puVar4 = *puVar4 + 1;
              }
              else if (*(int *)(iVar6 + 0x94) == 2) {
                *puVar12 = *puVar12 + 1;
              }
              else {
                *puVar13 = *puVar13 + 1;
              }
              *puVar3 = *puVar3 + 1;
            }
LAB_004c7028:
          }
          iVar5 = iVar5 + 600;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        } while (iVar5 != local_30);
        iVar5 = 0;
        FUN_00407f30(wips_global_mutex);
        do {
          iVar6 = json_object_new_object();
          if (iVar6 == 0) {
            if (sensor_err_switch != '\0') {
              printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n",
                     "wips_jcs_callback_statistics_get_by_time",0x88c);
            }
            json_object_put(iVar1);
            uVar8 = 0xffffffff;
            goto LAB_004c6e8c;
          }
          memset(acStack_b60,0,0x100);
          snprintf(acStack_b60,0x100,"%d",iVar2);
          iVar2 = iVar2 + 600;
          uVar8 = json_object_new_string(acStack_b60);
          json_object_object_add(iVar6,"start_ts",uVar8);
          memset(acStack_b60,0,0x100);
          snprintf(acStack_b60,0x100,"%d",iVar2);
          uVar8 = json_object_new_string(acStack_b60);
          json_object_object_add(iVar6,"end_ts",uVar8);
          memset(acStack_b60,0,0x100);
          snprintf(acStack_b60,0x100,"%d",(uint)*(ushort *)((int)local_700 + iVar5));
          uVar8 = json_object_new_string(acStack_b60);
          json_object_object_add(iVar6,"slight_event_count",uVar8);
          memset(acStack_b60,0,0x100);
          snprintf(acStack_b60,0x100,"%d",(uint)*(ushort *)((int)local_820 + iVar5));
          uVar8 = json_object_new_string(acStack_b60);
          json_object_object_add(iVar6,"normal_event_count",uVar8);
          memset(acStack_b60,0,0x100);
          snprintf(acStack_b60,0x100,"%d",(uint)*(ushort *)((int)local_940 + iVar5));
          uVar8 = json_object_new_string(acStack_b60);
          json_object_object_add(iVar6,"severe_event_count",uVar8);
          memset(acStack_b60,0,0x100);
          puVar3 = (ushort *)((int)local_a60 + iVar5);
          iVar5 = iVar5 + 2;
          snprintf(acStack_b60,0x100,"%d",(uint)*puVar3);
          uVar8 = json_object_new_string(acStack_b60);
          json_object_object_add(iVar6,"total",uVar8);
          json_object_array_add(iVar1,iVar6);
        } while (iVar5 != 0x120);
        json_object_object_add(param_2,"result",iVar1);
        uVar8 = 0;
        goto LAB_004c6e8c;
      }
      if (sensor_err_switch == '\0') {
        uVar8 = 0xffffffff;
        goto LAB_004c6e8c;
      }
      pcVar10 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
      pcVar11 = "wips_jcs_callback_statistics_get_by_time";
      uVar8 = 0x853;
    }
    else {
      iVar1 = json_object_new_array();
      if (iVar1 != 0) {
        iVar2 = apmngr_db_get_sensor_max();
        puVar3 = (ushort *)FUN_00408450(iVar2 << 1,0x8e1);
        __n = local_30 << 1;
        puVar4 = (ushort *)FUN_00408450(__n,0x8e2);
        iVar2 = apmngr_db_get_sensor_max();
        __s = (void *)FUN_00408450(iVar2 << 2,0x8e3);
        local_2c = local_30 << 2;
        __s_00 = (void *)FUN_00408450(local_2c,0x8e4);
        if ((((puVar3 != (ushort *)0x0) && (__s != (void *)0x0)) && (puVar4 != (ushort *)0x0)) &&
           (__s_00 != (void *)0x0)) {
          iVar2 = apmngr_db_get_sensor_max();
          memset(puVar3,0,iVar2 << 1);
          memset(puVar4,0,__n);
          FUN_004082d0(wips_global_mutex,0xffffffff);
          for (iVar2 = FUN_004081b0(&g_wips_list); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
            iVar5 = apmngr_db_get_sensor_max();
            memset(__s,0,iVar5 << 2);
            memset(__s_00,0,local_2c);
            for (iVar5 = FUN_004081b0(iVar2 + 0x9c); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
              if (*(short *)(iVar5 + 0x38) != -1) {
                apmngr_db_entry_get_by_id(*(short *)(iVar5 + 0x38),auStack_5e0);
                if (*(int *)((int)__s + (local_5d0 - 50000) * 4) == 0) {
                  puVar3[local_5d0 - 50000] = puVar3[local_5d0 - 50000] + 1;
                  *(undefined4 *)((int)__s + (local_5d0 - 50000) * 4) = 1;
                }
                if (*(int *)((int)__s_00 + (uint)local_5ce * 4) == 0) {
                  puVar4[local_5ce] = puVar4[local_5ce] + 1;
                  *(undefined4 *)((int)__s_00 + (uint)local_5ce * 4) = 1;
                }
              }
            }
          }
          FUN_00407f30(wips_global_mutex);
          iVar2 = strncmp((char *)&local_bf0,"group",10);
          uVar14 = 0;
          puVar12 = puVar4;
          if (iVar2 == 0) {
            while ((int)uVar14 < local_30) {
              if (*puVar12 == 0) {
                uVar14 = uVar14 + 1;
                puVar12 = puVar12 + 1;
              }
              else {
                iVar2 = json_object_new_object();
                if (iVar2 == 0) {
                  if (sensor_err_switch == '\0') goto LAB_004c6e40;
                  pcVar10 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
                  uVar8 = 0x918;
                  goto LAB_004c747c;
                }
                apmngr_db_group_get_by_id(uVar14 & 0xffff,auStack_be4);
                uVar14 = uVar14 + 1;
                uVar8 = json_object_new_string(auStack_bd0);
                json_object_object_add(iVar2,"group_name",uVar8);
                memset(acStack_b60,0,0x100);
                snprintf(acStack_b60,0x100,"%d",(uint)*puVar12);
                uVar8 = json_object_new_string(acStack_b60);
                json_object_object_add(iVar2,"num",uVar8);
                json_object_array_add(iVar1,iVar2);
                puVar12 = puVar12 + 1;
              }
            }
          }
          else {
            iVar2 = strncmp((char *)&local_bf0,"sensor",10);
            sVar15 = -0x3cb0;
            if (iVar2 == 0) {
              local_30 = 0;
              puVar12 = puVar3;
              while (iVar2 = apmngr_db_get_sensor_max(), local_30 < iVar2) {
                if (*puVar12 != 0) {
                  iVar2 = json_object_new_object();
                  if (iVar2 == 0) {
                    if (sensor_err_switch == '\0') goto LAB_004c6e40;
                    pcVar10 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
                    uVar8 = 0x92b;
                    goto LAB_004c747c;
                  }
                  apmngr_db_entry_get_by_id(sVar15,auStack_308);
                  uVar8 = json_object_new_string(auStack_2ba);
                  json_object_object_add(iVar2,"entry_name",uVar8);
                  memset(acStack_b60,0,0x100);
                  snprintf(acStack_b60,0x100,"%d",(uint)*puVar12);
                  uVar8 = json_object_new_string(acStack_b60);
                  json_object_object_add(iVar2,"num",uVar8);
                  json_object_array_add(iVar1,iVar2);
                }
                sVar15 = sVar15 + 1;
                puVar12 = puVar12 + 1;
                local_30 = local_30 + 1;
              }
            }
          }
          json_object_object_add(param_2,"result",iVar1);
          uVar8 = json_object_new_int(0);
          json_object_object_add(param_2,&DAT_00676a24,uVar8);
          FUN_00407df0(puVar3);
          FUN_00407df0(__s);
          FUN_00407df0(puVar4);
          FUN_00407df0(__s_00);
          return;
        }
        if (sensor_err_switch != '\0') {
          pcVar10 = "[SENSOR_ERROR]%s()/%d out of memory\n";
          uVar8 = 0x8ea;
LAB_004c747c:
          printf(pcVar10,"wips_jcs_callback_statistics_get",uVar8);
        }
LAB_004c6e40:
        json_object_put(iVar1);
        if (puVar3 != (ushort *)0x0) {
          FUN_00407df0(puVar3);
        }
        if (__s != (void *)0x0) {
          FUN_00407df0(__s);
        }
        if (puVar4 != (ushort *)0x0) {
          FUN_00407df0(puVar4);
        }
        uVar8 = 0xffffffff;
        if (__s_00 == (void *)0x0) goto LAB_004c6e8c;
        FUN_00407df0(__s_00);
        goto LAB_004c6e88;
      }
      if (sensor_err_switch == '\0') {
        uVar8 = 0xffffffff;
        goto LAB_004c6e8c;
      }
      pcVar10 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
      pcVar11 = "wips_jcs_callback_statistics_get";
      uVar8 = 0x8dd;
    }
  }
  printf(pcVar10,pcVar11,uVar8);
  uVar8 = 0xffffffff;
LAB_004c6e8c:
  uVar8 = json_object_new_int(uVar8);
  json_object_object_add(param_2,&DAT_00676a24,uVar8);
  return;
}

