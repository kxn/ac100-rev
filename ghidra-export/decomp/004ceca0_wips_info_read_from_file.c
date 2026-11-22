// func wips_info_read_from_file @ 004ceca0 size=1140

void wips_info_read_from_file(char *param_1,int param_2)

{
  int iVar1;
  FILE *__stream;
  size_t __n;
  void *__ptr;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char *__nptr;
  short sVar7;
  undefined8 uVar8;
  short local_50 [12];
  int local_38;
  int local_30;
  
  if ((param_1 == (char *)0x0) || (iVar1 = access(param_1,4), iVar1 == -1)) {
    puts("argument error");
  }
  else {
    printf("read wips info from file: %s\n",param_1);
    __stream = fopen(param_1,"r+");
    fseek(__stream,0,2);
    __n = ftell(__stream);
    fseek(__stream,0,0);
    __ptr = malloc(__n + 1);
    fread(__ptr,1,__n,__stream);
    fclose(__stream);
    uVar2 = json_tokener_parse(__ptr);
    free(__ptr);
    if (param_2 != 0) {
      uVar4 = json_object_to_json_string_ext(uVar2,0);
      printf("file content: %s\n",uVar4);
    }
    iVar1 = json_object_object_get(uVar2,"sensor_id");
    if (iVar1 != 0) {
      iVar3 = json_object_get_type(iVar1);
      if (iVar3 == 3) {
        sVar7 = json_object_get_int(iVar1);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) {
          if (jcs_err_switch == 0) {
            return;
          }
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "wips_info_read_from_file",0xf70);
          return;
        }
        uVar8 = json_object_get_double(iVar1);
        sVar7 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
      if (sVar7 != -1) {
        iVar1 = 0;
        uVar4 = json_object_object_get(uVar2,"eventList");
        local_30 = json_object_array_length(uVar4);
        while (iVar1 < local_30) {
          uVar5 = json_object_array_get_idx(uVar4,iVar1);
          iVar3 = json_object_object_get(uVar5,"typeId");
          if (iVar3 == 0) {
LAB_004cef00:
            if (jcs_err_switch == 0) {
              iVar3 = -1;
            }
            else {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "wips_info_read_from_file",0xf80);
              iVar3 = -1;
            }
          }
          else {
            iVar6 = json_object_get_type(iVar3);
            if (iVar6 != 6) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "wips_info_read_from_file",0xf80);
              }
              goto LAB_004cef00;
            }
            __nptr = (char *)json_object_get_string(iVar3);
            iVar3 = atoi(__nptr);
          }
          iVar6 = json_object_object_get(uVar5,"params");
          if (iVar6 == 0) {
            uVar5 = json_object_to_json_string_ext(uVar5,0);
            iVar1 = iVar1 + 1;
            printf("Can not find params in json %s",uVar5);
          }
          else {
            if (param_2 != 0) {
              uVar5 = json_object_to_json_string_ext(iVar6,0);
              printf("\n\n========\n%d sensor_id: %d\ttype_id: %d\tdata: %s\n",iVar1,(int)sVar7,
                     iVar3,uVar5);
            }
            memset(local_50,0,0x20);
            local_50[0] = sVar7;
            local_38 = iVar6;
            switch(iVar3) {
            case 0x13157f9:
              iVar1 = iVar1 + 1;
              wips_event_no_auth_ssid_cb();
              break;
            case 0x13157fa:
              iVar1 = iVar1 + 1;
              wips_event_assoc_req_torrent();
              break;
            case 0x13157fb:
              iVar1 = iVar1 + 1;
              wips_event_reassoc_req_torrent();
              break;
            case 0x13157fc:
              iVar1 = iVar1 + 1;
              wips_event_probe_req_torrent();
              break;
            case 0x13157fd:
              iVar1 = iVar1 + 1;
              wips_event_auth_torrent();
              break;
            case 0x13157fe:
              iVar1 = iVar1 + 1;
              wips_event_ps_pool_torrent();
              break;
            case 0x13157ff:
              iVar1 = iVar1 + 1;
              wips_event_beacon_torrent();
              break;
            case 0x1315800:
              iVar1 = iVar1 + 1;
              wips_event_rts_torrent();
              break;
            case 0x1315801:
              iVar1 = iVar1 + 1;
              wips_event_cts_torrent();
              break;
            case 0x1315802:
              iVar1 = iVar1 + 1;
              wips_event_disassoc_torrent();
              break;
            case 0x1315803:
              iVar1 = iVar1 + 1;
              wips_event_deauth_torrent();
              break;
            case 0x1315804:
              iVar1 = iVar1 + 1;
              wips_event_bssid_illegal_dev();
              break;
            case 0x1315805:
              iVar1 = iVar1 + 1;
              wips_event_ssid_illegal_dev(local_50);
              break;
            default:
              iVar1 = iVar1 + 1;
              printf("type_id error");
            }
          }
        }
        json_object_put(uVar2);
      }
    }
  }
  return;
}

