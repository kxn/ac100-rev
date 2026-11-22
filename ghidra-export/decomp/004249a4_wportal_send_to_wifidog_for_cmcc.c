// func wportal_send_to_wifidog_for_cmcc @ 004249a4 size=1484

undefined4 wportal_send_to_wifidog_for_cmcc(undefined4 param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  ssize_t sVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  socklen_t local_608;
  sockaddr local_604 [7];
  undefined1 auStack_594 [308];
  char acStack_460 [56];
  undefined1 auStack_428 [1028];
  
  local_608 = 0;
  memset(auStack_428,0,0x400);
  iVar2 = wportal_db_cmcc_iface_count();
  if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d iface count is %d\n","wportal_send_to_wifidog_for_cmcc",0x3782,
           iVar2);
  }
  uVar10 = 0xffffffff;
  if (0 < iVar2) {
    if (iVar2 == 1) {
      memset(auStack_594,0,0x16c);
      iVar2 = wportal_db_iface_rdt_get_first_cmcc(auStack_594);
      if (iVar2 == 0) {
        if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d interface 0x%p rdtEntry.ptIfac is %s\n",
                 "wportal_send_to_wifidog_for_cmcc",0x378c,param_2,acStack_460);
        }
        strncpy(param_2,acStack_460,0x20);
        uVar10 = 0;
      }
    }
    else {
      iVar2 = json_object_new_object();
      if (iVar2 == 0) {
        if (wportal_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[WPORTAL_ERR]%s()/%d Para null\n";
        uVar9 = 0x3799;
      }
      else {
        uVar10 = json_object_new_string(param_1);
        json_object_object_add(iVar2,&DAT_00677c24,uVar10);
        uVar10 = json_object_new_int(0x259);
        json_object_object_add(iVar2,"type",uVar10);
        memset(local_604,0,0x6e);
        local_604[0].sa_family = 1;
        strcpy(local_604[0].sa_data,"/tmp/jcs.service.srv.wifidog");
        sVar3 = strlen(local_604[0].sa_data);
        local_608 = sVar3 + 2;
        iVar4 = json_object_new_object();
        if (iVar4 == 0) {
          json_object_put(iVar2);
          if (wportal_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          pcVar5 = "[WPORTAL_ERR]%s()/%d JSON OBJ CREATE failed\n";
          uVar9 = 0x37ab;
        }
        else {
          uVar10 = json_object_new_string("wifidog");
          json_object_object_add(iVar4,"name",uVar10);
          uVar10 = json_object_new_int(3);
          json_object_object_add(iVar4,&DAT_00679d2c,uVar10);
          uVar10 = json_object_new_string("/tmp/wifidog_to_uac");
          json_object_object_add(iVar4,"clt_path",uVar10);
          json_object_object_add(iVar4,"data",iVar2);
          pcVar5 = (char *)json_object_to_json_string_ext(iVar4,0);
          if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d send_str: %s \n","wportal_send_to_wifidog_for_cmcc",0x37b4,
                   pcVar5);
          }
          do {
            sVar3 = strlen(pcVar5);
            sVar6 = sendto(wifidog_fd,pcVar5,sVar3,0,local_604,local_608);
            if (0 < sVar6) break;
            if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d Send failed.\n","wportal_send_to_wifidog_for_cmcc",0x37be
                    );
            }
            piVar7 = __errno_location();
          } while ((*piVar7 == 0xb) || (*piVar7 == 4));
          json_object_put(iVar4);
          if (sVar6 < 1) {
            return 0xffffffff;
          }
          memset(auStack_428,0,0x400);
          sVar6 = recvfrom(wifidog_fd,auStack_428,0x3ff,0,local_604,&local_608);
          if (sVar6 < 1) {
            if (wportal_err_switch == 0) {
              return 0xffffffff;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return 0xffffffff;
            }
            pcVar5 = "[WPORTAL_ERR]%s()/%d Receive failed.\n";
            uVar9 = 0x37cd;
          }
          else {
            auStack_428[sVar6] = 0;
            if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d rcv_buffer: %s \n","wportal_send_to_wifidog_for_cmcc",
                     0x37d3,auStack_428);
            }
            iVar2 = json_tokener_parse(auStack_428);
            if (iVar2 != 0) {
              iVar4 = json_object_object_get(iVar2,"interface");
              if (iVar4 != 0) {
                iVar8 = json_object_get_type(iVar4);
                if (iVar8 == 6) {
                  pcVar5 = (char *)json_object_get_string(iVar4);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"wportal_send_to_wifidog_for_cmcc",0x37e4);
                  }
                  pcVar5 = "";
                }
                strncpy(param_2,pcVar5,0x1f);
                bVar1 = wportal_debug_switch != 0;
                param_2[0x1f] = '\0';
                if ((bVar1) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  printf("[WPORTAL_DBG]%s()/%d interface: %s \n","wportal_send_to_wifidog_for_cmcc",
                         0x37e5,param_2);
                }
                json_object_put(iVar2);
                return 0;
              }
              if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[WPORTAL_ERR]%s()/%d json parse interface failed.\n",
                       "wportal_send_to_wifidog_for_cmcc",0x37de);
              }
              json_object_put(iVar2);
              return 0xffffffff;
            }
            if (wportal_err_switch == 0) {
              return 0xffffffff;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return 0xffffffff;
            }
            pcVar5 = "[WPORTAL_ERR]%s()/%d json parse failed.\n";
            uVar9 = 0x37d7;
          }
        }
      }
      uVar10 = 0xffffffff;
      printf(pcVar5,"wportal_send_to_wifidog_for_cmcc",uVar9);
    }
  }
  return uVar10;
}

