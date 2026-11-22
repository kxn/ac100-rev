// func jcs_deep_checkup_pkt_sta_list @ 004d7d88 size=2616

/* WARNING: Removing unreachable block (ram,0x004d8224) */
/* WARNING: Removing unreachable block (ram,0x004d8250) */
/* WARNING: Removing unreachable block (ram,0x004d82f4) */
/* WARNING: Removing unreachable block (ram,0x004d8438) */

void jcs_deep_checkup_pkt_sta_list(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  FILE *__s;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char *__format;
  uint uVar9;
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
LAB_004d7e20:
    local_3c = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_deep_checkup_pkt_sta_list",0xb8e);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_3c = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004d7e20;
      uVar12 = json_object_get_double(iVar1);
      local_3c = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
    }
  }
  iVar1 = json_object_object_get(param_1,"end");
  if (iVar1 == 0) {
LAB_004d7e74:
    local_38 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_deep_checkup_pkt_sta_list",0xb91);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_38 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004d7e74;
      uVar12 = json_object_get_double(iVar1);
      local_38 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
    }
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : Create json object ret_obj failed\n",
             "jcs_deep_checkup_pkt_sta_list",0xb97);
    }
    pcVar4 = (char *)0x0;
    __s = (FILE *)0x0;
    iVar10 = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = json_object_new_array();
    if (iVar2 == 0) {
      if (sensor_di_err_switch != 0) {
        pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE FAIL\n";
        uVar8 = 0xb9e;
LAB_004d8524:
        printf(pcVar4,"jcs_deep_checkup_pkt_sta_list",uVar8);
      }
LAB_004d7ff8:
      pcVar4 = (char *)0x0;
      __s = (FILE *)0x0;
      iVar10 = 0;
    }
    else {
      local_30 = FUN_00407fe0(&DAT_00768114);
      iVar3 = FUN_004081b0(&DAT_00768114);
      local_40 = 0;
      for (; iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : =======get sta_list node=======\n",
                 "jcs_deep_checkup_pkt_sta_list",0xba7);
        }
        di_printmac(iVar3 + 0x12);
        if ((local_3c <= local_40) && (local_40 <= local_38)) {
          iVar6 = FUN_00407fa0(DAT_007685d0,iVar3 + 0xc);
          if (iVar6 == 0) {
            if (sensor_di_err_switch == 0) goto LAB_004d7ff8;
            pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : sta\'s parent bssid node not found\n";
            uVar8 = 0xbaf;
            goto LAB_004d8524;
          }
          if ((299 < *(ushort *)(iVar6 + 0xc)) ||
             (*(int *)(&DAT_007680f8 + ((short)*(ushort *)(iVar6 + 0xc) + 10) * 4) == 0)) {
            if (sensor_di_err_switch != 0) {
              printf("[SENSOR_DI_ERROR]%s()/line %d : ssid_id=%d not found\n",
                     "jcs_deep_checkup_pkt_sta_list",0xbb5);
            }
            goto LAB_004d7ff8;
          }
          iVar10 = json_object_new_object();
          if (iVar10 == 0) {
            if (sensor_di_err_switch != 0) {
              uVar8 = 0xbbd;
LAB_004d8698:
              __s = (FILE *)0x0;
              printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc\n","jcs_deep_checkup_pkt_sta_list",
                     uVar8);
              pcVar4 = (char *)0x0;
              goto LAB_004d7ffc;
            }
          }
          else {
            local_1d0 = 0;
            local_1cc = 0;
            local_1c8 = 0;
            local_1c4 = 0;
            local_1c0 = 0;
            FUN_004d7d34(iVar3 + 0xc,&local_1d0);
            uVar8 = json_object_new_string(&local_1d0);
            json_object_object_add(iVar10,"bssid",uVar8);
            local_1d0 = 0;
            local_1cc = 0;
            local_1c8 = 0;
            local_1c4 = 0;
            local_1c0 = 0;
            FUN_004d7d34(iVar3 + 0x12,&local_1d0);
            uVar8 = json_object_new_string(&local_1d0);
            json_object_object_add(iVar10,"sta_mac",uVar8);
            iVar7 = json_object_new_array();
            if (iVar7 == 0) {
              if (sensor_di_err_switch != 0) {
                uVar8 = 0xbcc;
                goto LAB_004d8698;
              }
            }
            else {
              memset(acStack_144,0,0x100);
              snprintf(acStack_144,0x100,"%d",(uint)*(ushort *)(iVar3 + 0x18));
              uVar8 = json_object_new_string(acStack_144);
              json_object_array_add(iVar7,uVar8);
              local_34 = ((((uint)*(ushort *)(iVar3 + 0x1a) * (uint)*(ushort *)(iVar6 + 0x16)) /
                          10000) * (uint)*(ushort *)
                                          (*(int *)(&DAT_007680f8 +
                                                   (*(short *)(iVar6 + 0xc) + 10) * 4) + 0x42)) /
                         10000;
              memset(acStack_144,0,0x100);
              snprintf(acStack_144,0x100,"%d",local_34);
              uVar8 = json_object_new_string(acStack_144);
              json_object_array_add(iVar7,uVar8);
              json_object_object_add(iVar10,"percent",iVar7);
              iVar6 = json_object_new_array();
              if (iVar6 == 0) {
                if (sensor_di_err_switch != 0) {
                  uVar8 = 0xbdc;
                  goto LAB_004d8698;
                }
              }
              else {
                iVar11 = 0;
                iVar7 = iVar3;
                do {
                  if (iVar11 < 3) {
                    memset(acStack_144,0,0x100);
                    uVar9 = (uint)*(ushort *)(iVar7 + 0x1c);
                  }
                  else {
                    uVar9 = *(ushort *)(iVar7 + 0x1c) * local_34;
                    memset(acStack_144,0,0x100);
                    uVar9 = uVar9 / 10000;
                  }
                  iVar11 = iVar11 + 1;
                  snprintf(acStack_144,0x100,"%d",uVar9);
                  uVar8 = json_object_new_string(acStack_144);
                  json_object_array_add(iVar6,uVar8);
                  iVar7 = iVar7 + 2;
                } while (iVar11 != 6);
                json_object_object_add(iVar10,"frame",iVar6);
                iVar6 = json_object_new_array();
                if (iVar6 == 0) {
                  if (sensor_di_err_switch != 0) {
                    uVar8 = 0xbf3;
                    goto LAB_004d8698;
                  }
                }
                else {
                  iVar7 = 0;
                  do {
                    memset(acStack_144,0,0x100);
                    iVar11 = iVar3 + iVar7;
                    iVar7 = iVar7 + 2;
                    snprintf(acStack_144,0x100,"%d",(uint)*(ushort *)(iVar11 + 0x28));
                    uVar8 = json_object_new_string(acStack_144);
                    json_object_array_add(iVar6,uVar8);
                  } while (iVar7 != 0x30);
                  json_object_object_add(iVar10,"subframe_a",iVar6);
                  iVar6 = json_object_new_array();
                  if (iVar6 != 0) {
                    iVar11 = 0;
                    iVar7 = iVar3;
                    do {
                      iVar11 = iVar11 + 2;
                      uVar9 = *(ushort *)(iVar7 + 0x58) * local_34;
                      memset(acStack_144,0,0x100);
                      snprintf(acStack_144,0x100,"%d",uVar9 / 10000);
                      uVar8 = json_object_new_string(acStack_144);
                      json_object_array_add(iVar6,uVar8);
                      iVar7 = iVar3 + iVar11;
                    } while (iVar11 != 0x30);
                    json_object_object_add(iVar10,"subframe_p",iVar6);
                    json_object_array_add(iVar2,iVar10);
                    goto LAB_004d7f0c;
                  }
                  if (sensor_di_err_switch != 0) {
                    uVar8 = 0xc01;
                    goto LAB_004d8698;
                  }
                }
              }
            }
          }
          __s = (FILE *)0x0;
          pcVar4 = (char *)0x0;
          goto LAB_004d7ffc;
        }
LAB_004d7f0c:
        local_40 = local_40 + 1;
      }
      json_object_object_add(iVar1,"deep_checkup_pkt_sta_list",iVar2);
      pcVar4 = (char *)json_object_to_json_string_ext(iVar1,0);
      pcVar4 = strdup(pcVar4);
      if (pcVar4 == (char *)0x0) {
        if (sensor_di_err_switch != 0) {
          printf("[SENSOR_DI_ERROR]%s()/line %d : generate result_str failed\n",
                 "jcs_deep_checkup_pkt_sta_list",0xc19);
        }
        iVar10 = 0;
        __s = (FILE *)0x0;
        iVar2 = 0;
      }
      else {
        json_object_put(iVar1);
        sVar5 = strlen(pcVar4);
        l_sensor_di_file_write_counter = l_sensor_di_file_write_counter + 1;
        snprintf(acStack_1bc,0x78,"/tmp/deep_checkup_result_%d");
        __s = fopen(acStack_1bc,"w+");
        if (__s == (FILE *)0x0) {
          if (sensor_di_err_switch != 0) {
            __format = "[SENSOR_DI_ERROR]%s()/line %d : open result file failed.\n";
            uVar8 = 0xc26;
LAB_004d85ec:
            iVar10 = 0;
            printf(__format,"jcs_deep_checkup_pkt_sta_list",uVar8);
            iVar2 = 0;
            goto LAB_004d7ffc;
          }
        }
        else {
          sVar5 = fwrite(pcVar4,(int)(short)sVar5,1,__s);
          if (sVar5 == 1) {
            free(pcVar4);
            fclose(__s);
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_checkup_pkt_sta_list success EXIT\n",
                     "jcs_deep_checkup_pkt_sta_list",0xc3d);
            }
            uVar8 = json_object_new_string(acStack_1bc);
            json_object_object_add(param_2,"file_name",uVar8);
            uVar8 = json_object_new_int(local_30);
            json_object_object_add(param_2,"sta_list_cnt",uVar8);
            uVar8 = 0;
            goto LAB_004d8060;
          }
          if (sensor_di_err_switch != 0) {
            __format = "[SENSOR_DI_ERROR]%s()/line %d : write result to file failed.\n";
            uVar8 = 0xc2c;
            goto LAB_004d85ec;
          }
        }
        iVar10 = 0;
        iVar2 = 0;
      }
    }
  }
LAB_004d7ffc:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_checkup_pkt_sta_list fail EXIT\n",
           "jcs_deep_checkup_pkt_sta_list",0xc44);
  }
  if (iVar10 != 0) {
    json_object_put(iVar10);
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
  uVar8 = 1;
  if (pcVar4 != (char *)0x0) {
    free(pcVar4);
    uVar8 = 1;
  }
LAB_004d8060:
  uVar8 = json_object_new_int(uVar8);
  json_object_object_add(param_2,&DAT_00676a24,uVar8);
  return;
}

