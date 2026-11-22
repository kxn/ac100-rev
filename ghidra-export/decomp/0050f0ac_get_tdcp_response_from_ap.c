// func get_tdcp_response_from_ap @ 0050f0ac size=2088

undefined4
get_tdcp_response_from_ap
          (int param_1,int param_2,int param_3,char *param_4,uint *param_5,uint *param_6,int param_7
          )

{
  bool bVar1;
  FILE *__s;
  size_t sVar2;
  int iVar3;
  int extraout_v1;
  int extraout_v1_00;
  int extraout_v1_01;
  int extraout_v1_02;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  uint local_3b8;
  int local_3b4;
  undefined4 local_3b0;
  undefined4 local_3ac;
  uint local_3a8;
  undefined4 local_3a4;
  int local_3a0;
  FILE *local_39c;
  int local_398;
  uint local_394;
  uint local_390;
  size_t local_38c;
  char acStack_388 [128];
  undefined1 auStack_308 [728];
  int local_30;
  int local_2c;
  
  memset(acStack_388,0,0x80);
  if (param_4 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_5 == (uint *)0x0) {
    return 0xffffffff;
  }
  snprintf(acStack_388,0x80,"/tmp/ac_passthrough_info_%d",param_3);
  __s = fopen(acStack_388,"w+");
  if (__s == (FILE *)0x0) {
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d open get file[%s] fail!\n","get_tdcp_response_from_ap",
             0x93b,acStack_388);
    }
    goto LAB_0050f1cc;
  }
  if ((param_1 == 0) || (param_2 < 1)) {
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d ............._ac_passthrough_response_get_from_all_ap begin............\n"
             ,"_ac_passthrough_response_get_from_all_ap",0x545);
    }
    local_3a0 = 0;
    local_39c = (FILE *)0x0;
    local_398 = 0;
    local_394 = 0;
    local_390 = 0;
    local_38c = 0;
    local_3b0 = 0;
    local_3ac = 0;
    local_3a8 = 0;
    local_3a4 = 0;
    FUN_004081f0();
    if ((param_3 < 1) || (param_6 == (uint *)0x0)) {
      if (ac_passthrough_err_switch != '\0') {
        pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d invalid params\n";
        pcVar5 = "_ac_passthrough_response_get_from_all_ap";
        uVar6 = 0x552;
        goto LAB_0050f320;
      }
    }
    else {
      sVar2 = fwrite("[",1,1,__s);
      if (sVar2 == 1) {
        local_394 = 0;
        local_3a0 = 0;
        local_390 = 0;
        local_39c = __s;
        local_398 = param_3;
        local_38c = sVar2;
        iVar7 = serv_wtp_address_arg_init(&local_3b0);
        if (iVar7 == 0) {
          iVar7 = apmngr_db_get_all_addr_by_capacity(&local_3b0,1,1,0x15f0000,1,0x31);
          if (iVar7 == 0) {
            while( true ) {
              if (ac_passthrough_info_switch != '\0') {
                printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
                       "_ac_passthrough_response_get_from_all_ap",0x572);
              }
              FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
              FUN_00408570(ac_passthrough_response_result_hash,
                           _ac_passthrough_response_get_from_one_hash_node,&local_3a0);
              if (ac_passthrough_info_switch != '\0') {
                printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                       "_ac_passthrough_response_get_from_all_ap",0x574);
              }
              FUN_00407f30(ac_passthrough_get_reponse_mutex);
              if (local_3a0 != 0) {
                iVar7 = -1;
                goto LAB_0050f2ac;
              }
              FUN_004081f0();
              if (((local_3a8 <= local_394) || (param_7 != 1)) ||
                 (extraout_v1_02 - extraout_v1_00 <= g_response_wait_time)) break;
              usleep(100000);
            }
            sVar2 = fwrite("]",1,1,__s);
            if (sVar2 == 1) {
              iVar7 = 0;
              *param_5 = local_394;
              *param_6 = (uint)(local_390 < local_3a8);
            }
            else {
              iVar7 = -1;
              if (ac_passthrough_err_switch != '\0') {
                pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d write result to file fail!\n";
                uVar6 = 0x583;
                goto LAB_0050f3c4;
              }
            }
          }
          else {
            iVar7 = -1;
            if (ac_passthrough_err_switch != '\0') {
              pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d get serv argv failed.\n";
              uVar6 = 0x56b;
              goto LAB_0050f3c4;
            }
          }
        }
        else {
          iVar7 = -1;
          if (ac_passthrough_err_switch != '\0') {
            pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d init serv argv failed.\n";
            uVar6 = 0x564;
            goto LAB_0050f3c4;
          }
        }
      }
      else {
        iVar7 = -1;
        if (ac_passthrough_err_switch != '\0') {
          pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d write result to file fail!\n";
          uVar6 = 0x558;
LAB_0050f3c4:
          iVar7 = -1;
          printf(pcVar4,"_ac_passthrough_response_get_from_all_ap",uVar6);
        }
      }
LAB_0050f2ac:
      serv_wtp_address_arg_destroy(&local_3b0);
      if (iVar7 == 0) {
LAB_0050f2bc:
        fclose(__s);
        strncpy(param_4,acStack_388,0x7f);
        return 0;
      }
    }
  }
  else {
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d ............._ac_passthrough_response_get begin............\n"
             ,"_ac_passthrough_response_get",0x4d3);
    }
    local_3b4 = 0;
    local_3b0 = 0;
    local_3ac = local_3ac & 0xffff;
    memset(auStack_308,0,0x2d8);
    local_3b8 = 0;
    FUN_004081f0();
    local_2c = extraout_v1;
    if ((param_3 < 1) || (param_6 == (uint *)0x0)) {
      if (ac_passthrough_err_switch != '\0') {
        pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d invalid params\n";
        pcVar5 = "_ac_passthrough_response_get";
        uVar6 = 0x4e7;
        goto LAB_0050f320;
      }
    }
    else {
      sVar2 = fwrite("[",1,1,__s);
      if (sVar2 == 1) {
        iVar7 = 0;
        local_30 = 0;
        local_3b4 = local_3b4 + 1;
        do {
          while( true ) {
            while( true ) {
              bVar1 = iVar7 < param_2;
              while (!bVar1) {
                FUN_004081f0();
                if (((param_2 <= (int)local_3b8) || (param_7 != 1)) ||
                   (g_response_wait_time < extraout_v1_01 - local_2c)) {
                  sVar2 = fwrite("]",1,1,__s);
                  if (sVar2 == 1) {
                    local_3b4 = local_3b4 + 1;
                    *param_5 = local_3b8;
                    *param_6 = (uint)(local_30 < param_2);
                    goto LAB_0050f2bc;
                  }
                  if (ac_passthrough_err_switch == '\0') goto LAB_0050f1c0;
                  pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d write result to file fail!\n";
                  pcVar5 = "_ac_passthrough_response_get";
                  uVar6 = 0x51f;
                  goto LAB_0050f320;
                }
                iVar7 = 0;
                usleep(100000);
                bVar1 = 0 < param_2;
              }
              memcpy(&local_3b0,(void *)(param_1 + iVar7 * 6),6);
              if (ac_passthrough_debug_switch != '\0') {
                printf("[AC_PASSTHROUGH_DEBUG]%s()/%d param timeout:%02x-%02x-%02x-%02x-%02x-%02x  id:%d \n"
                       ,"_ac_passthrough_response_get",0x4f8,local_3b0 >> 0x18,
                       local_3b0 >> 0x10 & 0xff,local_3b0 >> 8 & 0xff,local_3b0 & 0xff,
                       local_3ac >> 0x18,local_3ac >> 0x10 & 0xff,param_3);
              }
              iVar3 = apmngr_db_entry_get_by_mac(&local_3b0,auStack_308);
              if (iVar3 == 0) break;
              iVar7 = iVar7 + 1;
            }
            if (ac_passthrough_info_switch != '\0') {
              printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
                     "_ac_passthrough_response_get",0x4fd);
            }
            FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
            iVar3 = FUN_00407fa0(ac_passthrough_response_result_hash,&local_3b0);
            if (iVar3 != 0) break;
            if (ac_passthrough_debug_switch != '\0') {
              printf("[AC_PASSTHROUGH_DEBUG]%s()/%d param timeout:%02x-%02x-%02x-%02x-%02x-%02x \n",
                     "_ac_passthrough_response_get",0x501,(uint)local_3b0._0_1_,
                     (uint)local_3b0._1_1_,(uint)local_3b0._2_1_,local_3b0 & 0xff,
                     (uint)local_3ac._0_1_,(uint)local_3ac._1_1_);
            }
            if (ac_passthrough_info_switch != '\0') {
              uVar6 = 0x502;
LAB_0050f640:
              printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                     "_ac_passthrough_response_get",uVar6);
            }
LAB_0050f4f8:
            FUN_00407f30(ac_passthrough_get_reponse_mutex);
            iVar7 = iVar7 + 1;
          }
          if (ac_passthrough_debug_switch != '\0') {
            printf("going to print id:%d mac:%02x-%02x-%02x-%02x-%02x-%02x  \r\n",param_3,
                   (uint)local_3b0._0_1_,(uint)local_3b0._1_1_,(uint)local_3b0._2_1_,
                   local_3b0 & 0xff,(uint)local_3ac._0_1_,(uint)local_3ac._1_1_);
            print_passthrough_response_get_from_one_ap(iVar3,param_3);
          }
          iVar3 = _ac_passthrough_response_get_from_one_ap(iVar3,__s,param_3,&local_3b4,&local_3b8);
          if (iVar3 != 0) {
            if (ac_passthrough_info_switch != '\0') {
              uVar6 = 0x50f;
              goto LAB_0050f640;
            }
            goto LAB_0050f4f8;
          }
          if (ac_passthrough_info_switch != '\0') {
            printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                   "_ac_passthrough_response_get",0x512);
          }
          iVar7 = iVar7 + 1;
          FUN_00407f30(ac_passthrough_get_reponse_mutex);
          local_30 = local_30 + 1;
        } while( true );
      }
      if (ac_passthrough_err_switch != '\0') {
        pcVar4 = "[AC_PASSTHROUGH_ERROR]%s()/%d write result to file fail!\n";
        pcVar5 = "_ac_passthrough_response_get";
        uVar6 = 0x4ed;
LAB_0050f320:
        printf(pcVar4,pcVar5,uVar6);
      }
    }
  }
LAB_0050f1c0:
  fclose(__s);
LAB_0050f1cc:
  memset(acStack_388,0,0x80);
  snprintf(acStack_388,0x80,"rm -f /tmp/ac_passthrough_info_%d",param_3);
  system(acStack_388);
  return 0xffffffff;
}

