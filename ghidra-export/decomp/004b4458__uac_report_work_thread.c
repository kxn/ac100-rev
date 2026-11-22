// func _uac_report_work_thread @ 004b4458 size=2156

void _uac_report_work_thread(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  FUN_00407fd0(1,1,0xe);
  do {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    FUN_004082d0(uac_report_mutex,0xffffffff);
    while (time_to_report == 0) {
      FUN_004086c0(uac_report_cond,uac_report_mutex,0xffffffff);
    }
    time_to_report = 0;
    FUN_00407f30(uac_report_mutex);
    if (report_debug_switch != 0) {
      printf("[REPORT_DEBUG]%s()/line %d : _uac_report_work_thread\n","_uac_report_work_thread",
             0x328);
    }
    FUN_0051ad88(&local_34);
    FUN_0051ad88(&local_40);
    if ((DAT_00767d5c & 3) == 0) {
LAB_004b453c:
      if ((DAT_00767d5c & 4) != 0) {
        uVar4 = wsta_profile_get_max_wstation();
        wsta_db_sta_for_each_range(0,uVar4,_uac_report_collect_sta_status,&local_40);
        iVar2 = json_object_new_object();
        if (iVar2 == 0) {
          if (report_err_switch != 0) {
            printf("[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n","_send_sta_list_json",
                   0x244);
          }
        }
        else {
          iVar3 = json_object_new_object();
          if (iVar3 == 0) {
            if (report_err_switch != 0) {
              printf("[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n","_send_sta_list_json",
                     0x24a);
            }
LAB_004b4a64:
            if (iVar2 == 0) goto LAB_004b454c;
          }
          else {
            iVar5 = json_object_new_array();
            if (iVar5 == 0) {
              if (report_err_switch != 0) {
                pcVar8 = "[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n";
                uVar4 = 0x250;
LAB_004b4c48:
                printf(pcVar8,"_send_sta_list_json",uVar4);
              }
LAB_004b4b50:
              json_object_put(iVar3);
              if (iVar5 != 0) {
                json_object_put(iVar5);
              }
              goto LAB_004b4a64;
            }
            json_object_object_add(iVar2,"count",iVar3);
            json_object_object_add(iVar2,"client_list",iVar5);
            bVar1 = true;
            iVar6 = FUN_004081b0(&local_40);
            uVar9 = 0;
            while (iVar6 != 0) {
              if ((uVar9 == DAT_00767d60) || ((DAT_00767c59 == '\x02' && (uVar9 == 100)))) {
                uVar4 = json_object_new_int(uVar9);
                json_object_object_add(iVar3,"client_list",uVar4);
                iVar7 = json_object_to_json_string_ext(iVar2,0);
                if (iVar7 == 0) {
                  if (report_err_switch == 0) goto LAB_004b4b50;
                  pcVar8 = 
                  "[REPORT_ERROR]%s()/line %d : translate obj_main json to string failed.\n";
                  uVar4 = 0x265;
                  goto LAB_004b4c48;
                }
                iVar7 = uac_report_client_send(iVar7);
                if (iVar7 == -2) {
                  if (report_debug_switch == 0) goto LAB_004b489c;
                  pcVar8 = "_send_sta_list_json";
                  uVar4 = 0x26b;
                  goto LAB_004b4b30;
                }
                iVar5 = json_object_new_array();
                if (iVar5 == 0) {
                  if (report_err_switch == 0) goto LAB_004b4b50;
                  pcVar8 = "[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n";
                  uVar4 = 0x271;
                  goto LAB_004b4c48;
                }
                json_object_object_add(iVar2,"client_list",iVar5);
                bVar1 = false;
                uVar9 = 0;
              }
              iVar7 = _trans_sta_entry_to_json(iVar6 + 0xc,uVar9);
              if (iVar7 != 0) {
                json_object_array_add(iVar5,iVar7);
              }
              iVar6 = FUN_00408680(iVar6);
              uVar9 = uVar9 + 1;
            }
            if ((0 < (int)uVar9) || ((bVar1 && (uVar9 == 0)))) {
              uVar4 = json_object_new_int(uVar9);
              json_object_object_add(iVar3,"client_list",uVar4);
              iVar6 = json_object_to_json_string_ext(iVar2,0);
              if (iVar6 == 0) {
                if (report_err_switch != 0) {
                  pcVar8 = 
                  "[REPORT_ERROR]%s()/line %d : translate obj_main json to string failed.\n";
                  uVar4 = 0x287;
                  goto LAB_004b4c48;
                }
                goto LAB_004b4b50;
              }
              iVar6 = uac_report_client_send(iVar6);
              if (iVar6 == -2) {
                if (report_debug_switch != 0) {
                  pcVar8 = "_send_sta_list_json";
                  uVar4 = 0x28d;
                  goto LAB_004b4b30;
                }
                goto LAB_004b489c;
              }
            }
          }
          json_object_put(iVar2);
        }
      }
LAB_004b454c:
      if (report_debug_switch != 0) {
        printf("[REPORT_DEBUG]%s()/line %d : _uac_report_collect_timer_init\n",
               "_uac_report_collect_timer_init",0xbd);
      }
      if (((report_ctx == '\x01') &&
          (DAT_00767d64 = FUN_00408340(DAT_00767d5e,0,_uac_report_work_thread_wakeup,0,0,
                                       "_uac_report_collect_timer_init",0xc0), DAT_00767d64 == -1))
         && (report_err_switch != 0)) {
        printf("[REPORT_ERROR]%s()/line %d : _uac_report_collect_timer_init fail\n",
               "_uac_report_collect_timer_init",0xc4);
      }
    }
    else {
      apmngr_db_foreach_proc(0x15f0000,_uac_report_collect_ap_status,&local_34);
      iVar2 = json_object_new_object();
      if (iVar2 == 0) {
        if (report_err_switch != 0) {
          printf("[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n","_send_ap_list_json",0x13f
                );
        }
        goto LAB_004b453c;
      }
      iVar3 = json_object_new_object();
      if (iVar3 == 0) {
        if (report_err_switch != 0) {
          printf("[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n","_send_ap_list_json",0x145
                );
        }
joined_r0x004b4a20:
        if (iVar2 != 0) {
LAB_004b46b0:
          json_object_put(iVar2);
        }
        goto LAB_004b453c;
      }
      iVar5 = json_object_new_array();
      if (iVar5 == 0) {
        if (report_err_switch != 0) {
          pcVar8 = "[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n";
          uVar4 = 0x14b;
LAB_004b4b90:
          printf(pcVar8,"_send_ap_list_json",uVar4);
        }
LAB_004b4aa8:
        json_object_put(iVar3);
        if (iVar5 != 0) {
          json_object_put(iVar5);
        }
        goto joined_r0x004b4a20;
      }
      json_object_object_add(iVar2,"count",iVar3);
      json_object_object_add(iVar2,"ap_list",iVar5);
      bVar1 = true;
      iVar6 = FUN_004081b0(&local_34);
      uVar9 = 0;
      while (iVar6 != 0) {
        if ((uVar9 == DAT_00767d60) || ((DAT_00767c59 == '\x02' && (uVar9 == 100)))) {
          uVar4 = json_object_new_int(uVar9);
          json_object_object_add(iVar3,"ap_list",uVar4);
          iVar7 = json_object_to_json_string_ext(iVar2,0);
          if (iVar7 == 0) {
            if (report_err_switch == 0) goto LAB_004b4aa8;
            pcVar8 = "[REPORT_ERROR]%s()/line %d : translate obj_main json to string failed.\n";
            uVar4 = 0x160;
            goto LAB_004b4b90;
          }
          iVar7 = uac_report_client_send(iVar7);
          if (iVar7 == -2) {
            if (report_debug_switch == 0) goto LAB_004b489c;
            pcVar8 = "_send_ap_list_json";
            uVar4 = 0x166;
            goto LAB_004b4b30;
          }
          iVar5 = json_object_new_array();
          if (iVar5 == 0) {
            if (report_err_switch == 0) goto LAB_004b4aa8;
            pcVar8 = "[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n";
            uVar4 = 0x16c;
            goto LAB_004b4b90;
          }
          json_object_object_add(iVar2,"ap_list",iVar5);
          bVar1 = false;
          uVar9 = 0;
        }
        iVar7 = _trans_ap_entry_to_json(iVar6 + 0x10,uVar9);
        if (iVar7 != 0) {
          json_object_array_add(iVar5,iVar7);
        }
        iVar6 = FUN_00408680(iVar6);
        uVar9 = uVar9 + 1;
      }
      if (((int)uVar9 < 1) && ((!bVar1 || (uVar9 != 0)))) goto LAB_004b46b0;
      uVar4 = json_object_new_int(uVar9);
      json_object_object_add(iVar3,"ap_list",uVar4);
      iVar6 = json_object_to_json_string_ext(iVar2,0);
      if (iVar6 == 0) {
        if (report_err_switch != 0) {
          pcVar8 = "[REPORT_ERROR]%s()/line %d : translate obj_main json to string failed.\n";
          uVar4 = 0x182;
          goto LAB_004b4b90;
        }
        goto LAB_004b4aa8;
      }
      iVar6 = uac_report_client_send(iVar6);
      if (iVar6 != -2) goto LAB_004b46b0;
      if (report_debug_switch != 0) {
        pcVar8 = "_send_ap_list_json";
        uVar4 = 0x188;
LAB_004b4b30:
        printf("[REPORT_DEBUG]%s()/line %d : report reset by jcs\n",pcVar8,uVar4);
      }
LAB_004b489c:
      json_object_put(iVar3);
      json_object_put(iVar5);
      json_object_put(iVar2);
    }
    iVar2 = FUN_004081b0(&local_34);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
    iVar2 = FUN_004081b0(&local_40);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
  } while( true );
}

