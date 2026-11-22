// func ac_passthrough_send_packet_handle @ 0050b3a8 size=1560

int ac_passthrough_send_packet_handle(int param_1,int param_2,char *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  void *__s;
  undefined4 extraout_v1;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int local_50;
  size_t local_4c;
  undefined4 local_48;
  void *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  if ((((param_2 == 0) || (param_3 == (char *)0x0)) || (sVar3 = strlen(param_3), (int)sVar3 < 0)) ||
     (0xff7f < (int)sVar3)) {
    iVar8 = 0;
    if (ac_passthrough_err_switch == '\0') goto LAB_0050b5a4;
    pcVar6 = "[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n";
    uVar7 = 0x212;
  }
  else {
    iVar8 = cw_pkt_buf_create(DAT_0074cb98 + sVar3);
    if (iVar8 == 0) {
      if (ac_passthrough_err_switch == '\0') goto LAB_0050b5a4;
      pcVar6 = "[AC_PASSTHROUGH_ERROR]%s()/%d malloc failed.\n";
      uVar7 = 0x219;
    }
    else {
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = (void *)0x0;
      sVar3 = strlen(param_3);
      iVar4 = cw_parsed_pkt_create(7);
      if (iVar4 == 0) {
        if (ac_passthrough_err_switch != '\0') {
          printf("[AC_PASSTHROUGH_ERROR]%s()/%d malloc for CW_PARSED_PKT failed.\n",
                 "ac_passthrough_buffer_create",0x1c1);
        }
      }
      else {
        local_40 = 0x12345678;
        local_3c = CONCAT22(0x83,local_3c._2_2_);
        FUN_0051ad88(&local_38);
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = (void *)0x0;
        local_44 = (void *)FUN_00408450(sVar3 + 1,0x1ca);
        if (local_44 == (void *)0x0) {
          if (ac_passthrough_err_switch != '\0') {
            pcVar6 = "[AC_PASSTHROUGH_ERROR]%s()/%d malloc  failed.\n";
            uVar7 = 0x1cc;
LAB_0050b600:
            printf(pcVar6,"ac_passthrough_buffer_create",uVar7);
          }
        }
        else {
          if (ac_passthrough_info_switch != '\0') {
            printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_msg_report_mutex\n",
                   "generate_tdcp_request_id",0x1a2);
          }
          FUN_004082d0(ac_passthrough_msg_report_mutex,0xffffffff);
          g_send_tdcp_request_id = g_send_tdcp_request_id + 1;
          if (g_send_tdcp_request_id < 1) {
            g_send_tdcp_request_id = 1;
          }
          iVar2 = g_send_tdcp_request_id;
          if (ac_passthrough_info_switch != '\0') {
            printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_msg_report_mutex\n",
                   "generate_tdcp_request_id",0x1a9);
          }
          FUN_00407f30(ac_passthrough_msg_report_mutex);
          local_50 = iVar2;
          local_48 = CONCAT13((char)param_1,local_48._1_3_);
          local_4c = sVar3;
          memset(local_44,0,sVar3 + 1);
          memcpy(local_44,param_3,sVar3);
          iVar5 = cw_service_msg_add(iVar4,0x25,&local_40,1,0x83,&local_50);
          if (iVar5 == 0) {
            iVar5 = capwap_packet_assemble(iVar8,iVar4);
            if (iVar5 == 0) {
              if (ac_passthrough_debug_switch != '\0') {
                printf("[AC_PASSTHROUGH_DEBUG]%s()/%d create parsed_pkt success.\n",
                       "ac_passthrough_buffer_create",0x1e8);
              }
              cw_parsed_pkt_destroy(iVar4);
              if (local_44 != (void *)0x0) {
                FUN_00407df0();
              }
              if (param_4 != (int *)0x0) {
                *param_4 = iVar2;
              }
              if (param_1 == 0) {
LAB_0050b7b4:
                iVar4 = serv_packet_send(param_2,iVar8,1);
                if (iVar4 == 0) {
                  if (ac_passthrough_debug_switch != '\0') {
                    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d send packet buffer success.\n",
                           "ac_passthrough_send_packet_handle",0x235);
                  }
                  cw_pkt_buf_destroy(iVar8);
                  return iVar2;
                }
                if (ac_passthrough_err_switch != '\0') {
                  printf("[AC_PASSTHROUGH_ERROR]%s()/%d send packet buffer failed.\n",
                         "ac_passthrough_send_packet_handle",0x231);
                }
                if (ac_passthrough_info_switch != '\0') {
                  printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_wairting_result_list_ock\n"
                         ,"del_ac_passthrough_waitting_result_list",0x156);
                }
                pthread_mutex_lock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
                iVar4 = FUN_004081b0(&g_ac_passthrough_waitting_result_list);
                while (iVar5 = iVar4, iVar5 != 0) {
                  iVar4 = FUN_00408680(iVar5);
                  if (iVar2 == *(int *)(iVar5 + 0xc)) {
                    FUN_00408500(iVar5);
                    FUN_00407df0(iVar5);
                    g_ac_passthrough_waitting_result_cnt = g_ac_passthrough_waitting_result_cnt + -1
                    ;
                  }
                }
                if (ac_passthrough_info_switch != '\0') {
                  printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_wairting_result_list_ock\n"
                         ,"del_ac_passthrough_waitting_result_list",0x164);
                }
                pthread_mutex_unlock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
                goto LAB_0050b5a4;
              }
              if ((0 < iVar2) && (__s = (void *)FUN_00408450(0x14,0x136), __s != (void *)0x0)) {
                memset(__s,0,0x14);
                FUN_00407e70();
                cVar1 = ac_passthrough_info_switch;
                *(undefined4 *)((int)__s + 0x10) = extraout_v1;
                *(int *)((int)__s + 0xc) = iVar2;
                if (cVar1 != '\0') {
                  printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_wairting_result_list_ock\n"
                         ,"insert_ac_passthrough_waitting_result_list",0x13e);
                }
                pthread_mutex_lock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
                if (g_ac_passthrough_waitting_result_cnt < 20000) {
                  iVar4 = 0;
                  FUN_004086b0(&g_ac_passthrough_waitting_result_list,__s);
                  g_ac_passthrough_waitting_result_cnt = g_ac_passthrough_waitting_result_cnt + 1;
                }
                else {
                  iVar4 = -1;
                  FUN_00407df0(__s);
                }
                if (ac_passthrough_info_switch != '\0') {
                  printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_wairting_result_list_ock\n"
                         ,"insert_ac_passthrough_waitting_result_list",0x14d);
                }
                pthread_mutex_unlock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
                if (iVar4 == 0) goto LAB_0050b7b4;
              }
              if (ac_passthrough_err_switch == '\0') goto LAB_0050b5a4;
              pcVar6 = "[AC_PASSTHROUGH_ERROR]%s()/%d send packet buffer failed.\n";
              uVar7 = 0x22b;
              goto LAB_0050b664;
            }
            if (ac_passthrough_err_switch != '\0') {
              pcVar6 = "[AC_PASSTHROUGH_ERROR]%s()/%d assemble packet buffer failed.\n";
              uVar7 = 0x1e5;
              goto LAB_0050b600;
            }
          }
          else if (ac_passthrough_err_switch != '\0') {
            printf("[AC_PASSTHROUGH_ERROR]%s()/%d add msg element failed ret:%d.\n",
                   "ac_passthrough_buffer_create",0x1de,iVar5);
          }
        }
        cw_parsed_pkt_destroy(iVar4);
      }
      if (local_44 != (void *)0x0) {
        FUN_00407df0();
      }
      if (ac_passthrough_err_switch == '\0') goto LAB_0050b5a4;
      pcVar6 = 
      "[AC_PASSTHROUGH_ERROR]%s()/%d create broadcast storm control packet buffer failed.\n";
      uVar7 = 0x21f;
    }
  }
LAB_0050b664:
  printf(pcVar6,"ac_passthrough_send_packet_handle",uVar7);
LAB_0050b5a4:
  cw_pkt_buf_destroy(iVar8);
  return -1;
}

