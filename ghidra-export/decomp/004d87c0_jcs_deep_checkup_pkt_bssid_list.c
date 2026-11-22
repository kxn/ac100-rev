// func jcs_deep_checkup_pkt_bssid_list @ 004d87c0 size=2468

/* WARNING: Removing unreachable block (ram,0x004d8d38) */
/* WARNING: Removing unreachable block (ram,0x004d8a2c) */
/* WARNING: Removing unreachable block (ram,0x004d8b0c) */

void jcs_deep_checkup_pkt_bssid_list(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  FILE *__s;
  undefined4 uVar7;
  char *__format;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  char acStack_1bc [120];
  char acStack_144 [260];
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  memset(acStack_1bc,0,0x78);
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 == 0) {
LAB_004d8858:
    local_3c = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_deep_checkup_pkt_bssid_list",0xaa5);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_3c = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004d8858;
      uVar12 = json_object_get_double(iVar1);
      local_3c = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
    }
  }
  iVar1 = json_object_object_get(param_1,"end");
  if (iVar1 == 0) {
LAB_004d88ac:
    local_38 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_deep_checkup_pkt_bssid_list",0xaa8);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_38 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004d88ac;
      uVar12 = json_object_get_double(iVar1);
      local_38 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
    }
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : Create json object ret_obj failed\n",
             "jcs_deep_checkup_pkt_bssid_list",0xaae);
    }
    pcVar5 = (char *)0x0;
    __s = (FILE *)0x0;
    iVar9 = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = json_object_new_array();
    if (iVar2 == 0) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE FAIL\n",
               "jcs_deep_checkup_pkt_bssid_list",0xab5);
      }
LAB_004d8b88:
      __s = (FILE *)0x0;
      pcVar5 = (char *)0x0;
      iVar9 = 0;
    }
    else {
      local_30 = FUN_00407fe0(&DAT_00768108);
      iVar3 = FUN_004081b0(&DAT_00768108);
      local_40 = 0;
      for (; iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
        if ((local_3c <= local_40) && (local_40 <= local_38)) {
          if ((299 < *(ushort *)(iVar3 + 0xc)) ||
             (*(int *)(&DAT_007680f8 + ((short)*(ushort *)(iVar3 + 0xc) + 10) * 4) == 0)) {
            if (sensor_di_err_switch != 0) {
              printf("[SENSOR_DI_ERROR]%s()/line %d : ssid_id=%d not found\n",
                     "jcs_deep_checkup_pkt_bssid_list",0xac2);
            }
            goto LAB_004d8b88;
          }
          iVar9 = json_object_new_object();
          if (iVar9 == 0) {
            if (sensor_di_err_switch != 0) {
              pcVar5 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
              uVar7 = 0xaca;
LAB_004d9094:
              __s = (FILE *)0x0;
              printf(pcVar5,"jcs_deep_checkup_pkt_bssid_list",uVar7);
              pcVar5 = (char *)0x0;
              goto LAB_004d8b90;
            }
          }
          else {
            local_1d0 = 0;
            local_1cc = 0;
            local_1c8 = 0;
            local_1c4 = 0;
            local_1c0 = 0;
            FUN_004d7d34(iVar3 + 0xe,&local_1d0);
            uVar7 = json_object_new_string(&local_1d0);
            json_object_object_add(iVar9,"bssid",uVar7);
            memset(acStack_144,0,0x100);
            snprintf(acStack_144,0x100,"%d",(int)*(short *)(iVar3 + 0xc));
            uVar7 = json_object_new_string(acStack_144);
            json_object_object_add(iVar9,"ssid_id",uVar7);
            iVar4 = json_object_new_array();
            if (iVar4 == 0) {
              if (sensor_di_err_switch != 0) {
                pcVar5 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc\n";
                uVar7 = 0xad8;
                goto LAB_004d9094;
              }
            }
            else {
              local_34 = ((uint)*(ushort *)(iVar3 + 0x16) *
                         (uint)*(ushort *)
                                (*(int *)(&DAT_007680f8 + (*(short *)(iVar3 + 0xc) + 10) * 4) + 0x42
                                )) / 10000;
              memset(acStack_144,0,0x100);
              snprintf(acStack_144,0x100,"%d",(uint)*(ushort *)(iVar3 + 0x14));
              uVar7 = json_object_new_string(acStack_144);
              json_object_array_add(iVar4,uVar7);
              memset(acStack_144,0,0x100);
              snprintf(acStack_144,0x100,"%d",local_34);
              uVar7 = json_object_new_string(acStack_144);
              json_object_array_add(iVar4,uVar7);
              json_object_object_add(iVar9,"percent",iVar4);
              iVar4 = json_object_new_array();
              if (iVar4 == 0) {
                if (sensor_di_err_switch != 0) {
                  pcVar5 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                  uVar7 = 0xae5;
                  goto LAB_004d9094;
                }
              }
              else {
                iVar11 = 0;
                iVar10 = iVar3;
                do {
                  if (iVar11 < 3) {
                    memset(acStack_144,0,0x100);
                    uVar8 = (uint)*(ushort *)(iVar10 + 0x18);
                  }
                  else {
                    uVar8 = *(ushort *)(iVar10 + 0x18) * local_34;
                    memset(acStack_144,0,0x100);
                    uVar8 = uVar8 / 10000;
                  }
                  iVar11 = iVar11 + 1;
                  snprintf(acStack_144,0x100,"%d",uVar8);
                  uVar7 = json_object_new_string(acStack_144);
                  json_object_array_add(iVar4,uVar7);
                  iVar10 = iVar10 + 2;
                } while (iVar11 != 6);
                json_object_object_add(iVar9,"frame",iVar4);
                iVar4 = json_object_new_array();
                if (iVar4 == 0) {
                  if (sensor_di_err_switch != 0) {
                    pcVar5 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc\n";
                    uVar7 = 0xafd;
                    goto LAB_004d9094;
                  }
                }
                else {
                  iVar10 = 0;
                  do {
                    memset(acStack_144,0,0x100);
                    iVar11 = iVar3 + iVar10;
                    iVar10 = iVar10 + 2;
                    snprintf(acStack_144,0x100,"%d",(uint)*(ushort *)(iVar11 + 0x24));
                    uVar7 = json_object_new_string(acStack_144);
                    json_object_array_add(iVar4,uVar7);
                  } while (iVar10 != 0x30);
                  json_object_object_add(iVar9,"subframe_a",iVar4);
                  iVar4 = json_object_new_array();
                  if (iVar4 != 0) {
                    iVar11 = 0;
                    iVar10 = iVar3;
                    do {
                      iVar11 = iVar11 + 2;
                      uVar8 = *(ushort *)(iVar10 + 0x54) * local_34;
                      memset(acStack_144,0,0x100);
                      snprintf(acStack_144,0x100,"%d",uVar8 / 10000);
                      uVar7 = json_object_new_string(acStack_144);
                      json_object_array_add(iVar4,uVar7);
                      iVar10 = iVar3 + iVar11;
                    } while (iVar11 != 0x30);
                    json_object_object_add(iVar9,"subframe_p",iVar4);
                    json_object_array_add(iVar2,iVar9);
                    goto LAB_004d8d90;
                  }
                  if (sensor_di_err_switch != 0) {
                    pcVar5 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                    uVar7 = 0xb0b;
                    goto LAB_004d9094;
                  }
                }
              }
            }
          }
          __s = (FILE *)0x0;
          pcVar5 = (char *)0x0;
          goto LAB_004d8b90;
        }
LAB_004d8d90:
        local_40 = local_40 + 1;
      }
      json_object_object_add(iVar1,"deep_checkup_pkt_bssid_list",iVar2);
      pcVar5 = (char *)json_object_to_json_string_ext(iVar1,0);
      pcVar5 = strdup(pcVar5);
      if (pcVar5 == (char *)0x0) {
        if (sensor_di_err_switch != 0) {
          printf("[SENSOR_DI_ERROR]%s()/line %d : generate result_str failed\n",
                 "jcs_deep_checkup_pkt_bssid_list",0xb24);
        }
        iVar9 = 0;
        __s = (FILE *)0x0;
        iVar2 = 0;
      }
      else {
        json_object_put(iVar1);
        sVar6 = strlen(pcVar5);
        l_sensor_di_file_write_counter = l_sensor_di_file_write_counter + 1;
        snprintf(acStack_1bc,0x78,"/tmp/deep_checkup_result_%d");
        __s = fopen(acStack_1bc,"w+");
        if (__s == (FILE *)0x0) {
          if (sensor_di_err_switch != 0) {
            __format = "[SENSOR_DI_ERROR]%s()/line %d : open result file failed.\n";
            uVar7 = 0xb31;
LAB_004d9074:
            iVar9 = 0;
            printf(__format,"jcs_deep_checkup_pkt_bssid_list",uVar7);
            iVar2 = 0;
            goto LAB_004d8b90;
          }
        }
        else {
          sVar6 = fwrite(pcVar5,(int)(short)sVar6,1,__s);
          if (sVar6 == 1) {
            free(pcVar5);
            fclose(__s);
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_checkup_pkt_bssid_list success EXIT\n"
                     ,"jcs_deep_checkup_pkt_bssid_list",0xb48);
            }
            uVar7 = json_object_new_string(acStack_1bc);
            json_object_object_add(param_2,"file_name",uVar7);
            uVar7 = json_object_new_int(local_30);
            json_object_object_add(param_2,"bssid_list_cnt",uVar7);
            uVar7 = 0;
            goto LAB_004d8bf4;
          }
          if (sensor_di_err_switch != 0) {
            __format = "[SENSOR_DI_ERROR]%s()/line %d : write result to file failed.\n";
            uVar7 = 0xb37;
            goto LAB_004d9074;
          }
        }
        iVar9 = 0;
        iVar2 = 0;
      }
    }
  }
LAB_004d8b90:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_checkup_pkt_bssid_list fail EXIT\n",
           "jcs_deep_checkup_pkt_bssid_list",0xb4f);
  }
  if (iVar9 != 0) {
    json_object_put(iVar9);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  uVar7 = 1;
  if (pcVar5 != (char *)0x0) {
    free(pcVar5);
    uVar7 = 1;
  }
LAB_004d8bf4:
  uVar7 = json_object_new_int(uVar7);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  return;
}

