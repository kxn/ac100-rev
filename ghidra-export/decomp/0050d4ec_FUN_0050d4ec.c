// func FUN_0050d4ec @ 0050d4ec size=2696

undefined4 FUN_0050d4ec(int *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 extraout_v1;
  int iVar6;
  undefined4 extraout_v1_00;
  undefined4 extraout_v1_01;
  undefined4 extraout_v1_02;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  size_t __n;
  size_t __n_00;
  void *local_310;
  undefined1 auStack_308 [728];
  void *local_30;
  
  memset(auStack_308,0,0x2d8);
  if (ac_passthrough_debug_switch != '\0') {
    puts("_ac_passthrough_response_request\r");
    printf("\t\t%02x-%02x-%02x-%02x-%02x-%02x\r\n",(uint)*param_2,(uint)param_2[1],(uint)param_2[2],
           (uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
    printf("\t\tid:%d len:%d data:%s\r\n",*param_1,param_1[1],param_1[3]);
  }
  iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_308);
  if (iVar1 != 0) {
    if (ac_passthrough_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[AC_PASSTHROUGH_ERROR]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
           "ac_passthrough_tdcp_response_request",0x64b);
    return 0xffffffff;
  }
  iVar1 = *param_1;
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_wairting_result_list_ock\n",
           "update_passthrough_waitting_result_list",0x18c);
  }
  iVar10 = -1;
  pthread_mutex_lock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
  FUN_00407e70();
  iVar2 = FUN_004081b0(&g_ac_passthrough_waitting_result_list);
  if (iVar2 != 0) {
    iVar6 = *(int *)(iVar2 + 0xc);
    while( true ) {
      if (iVar1 == iVar6) {
        *(undefined4 *)(iVar2 + 0x10) = extraout_v1;
        iVar10 = 0;
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      iVar6 = *(int *)(iVar2 + 0xc);
    }
  }
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_wairting_result_list_ock\n",
           "update_passthrough_waitting_result_list",0x19a);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
  if (iVar10 != 0) {
    if (ac_passthrough_debug_switch == '\0') {
      return 0xffffffff;
    }
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d invalid reponse id:%d.\n",
           "ac_passthrough_tdcp_response_request",0x650,*param_1);
    return 0xffffffff;
  }
  iVar1 = *param_1;
  __n = param_1[1];
  local_30 = (void *)param_1[3];
  local_310 = (void *)0x0;
  if ((((param_2 == (byte *)0x0) || (iVar1 < 1)) || ((int)__n < 1)) || (local_30 == (void *)0x0)) {
    if (ac_passthrough_err_switch == '\0') {
      local_310 = (void *)0x0;
      goto LAB_0050d924;
    }
    uVar9 = 0x449;
  }
  else {
    if (ac_passthrough_info_switch != '\0') {
      printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
             "ac_passthrough_node_add",0x3e4);
    }
    FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
    if (ac_passthrough_response_result_hash == 0) {
      uVar9 = apmngr_db_get_ap_max();
      ac_passthrough_response_result_hash =
           FUN_004080a0(ac_passthrough_node_hash_hash_obj,ac_passthrough_node_hash_hash_key,
                        ac_passthrough_node_hash_cmp,uVar9);
    }
    iVar2 = FUN_00407fa0(ac_passthrough_response_result_hash,param_2);
    if (iVar2 != 0) {
      if (ac_passthrough_debug_switch != '\0') {
        pcVar7 = "[AC_PASSTHROUGH_DEBUG]%s()/%d param type:%s\n";
        uVar9 = 0x3f0;
LAB_0050d9a4:
        printf(pcVar7,"ac_passthrough_node_add",uVar9,param_2);
      }
LAB_0050d790:
      if (ac_passthrough_info_switch != '\0') {
        printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
               "ac_passthrough_node_add",0x3fd);
      }
      FUN_00407f30(ac_passthrough_get_reponse_mutex);
      if (ac_passthrough_info_switch != '\0') {
        printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
               "insert_ac_passthrough_node",0x452);
      }
      FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
      piVar3 = (int *)FUN_00407fa0(ac_passthrough_response_result_hash,param_2);
      if (piVar3 == (int *)0x0) {
        if (ac_passthrough_info_switch != '\0') {
          uVar9 = 0x45a;
          goto LAB_0050daa8;
        }
      }
      else {
        if (ac_passthrough_debug_switch != '\0') {
          printf("[AC_PASSTHROUGH_DEBUG]%s()/%d param mac:%02x-%02x-%02x-%02x-%02x-%02x \n",
                 "insert_ac_passthrough_node",0x456,(int)(char)*param_2,(int)(char)param_2[1],
                 (int)(char)param_2[2],(int)(char)param_2[3],(int)(char)param_2[4],
                 (int)(char)param_2[5]);
        }
        __n_00 = __n + 1;
        local_310 = (void *)FUN_00408450(__n_00,0x462);
        memset(local_310,0,__n_00);
        memcpy(local_310,local_30,__n);
        FUN_00407e70();
        iVar2 = get_reponse_by_id_from_list(piVar3,iVar1);
        if (iVar2 == 0) {
          if (*piVar3 < 0x14) {
            pvVar4 = (void *)FUN_00408450(0x1c,0x33b);
            if (pvVar4 != (void *)0x0) {
              memset(pvVar4,0,0x1c);
              *(int *)((int)pvVar4 + 0xc) = iVar1;
              *(size_t *)((int)pvVar4 + 0x10) = __n;
              FUN_00407e70();
              *(undefined4 *)((int)pvVar4 + 0x14) = extraout_v1_02;
              pvVar5 = (void *)FUN_00408450(*(int *)((int)pvVar4 + 0x10) + 1,0x345);
              *(void **)((int)pvVar4 + 0x18) = pvVar5;
              memset(pvVar5,0,*(int *)((int)pvVar4 + 0x10) + 1);
              memcpy(*(void **)((int)pvVar4 + 0x18),local_310,*(size_t *)((int)pvVar4 + 0x10));
              FUN_004086b0(piVar3 + 1,pvVar4);
              *piVar3 = *piVar3 + 1;
              if (ac_passthrough_debug_switch != '\0') {
                uVar9 = 0x34b;
                goto LAB_0050dd64;
              }
              goto LAB_0050dc90;
            }
            if (ac_passthrough_err_switch != '\0') {
              pcVar7 = "[AC_PASSTHROUGH_ERROR]%s()/%d malloc discovery-station failed.\n";
              pcVar8 = "ac_passthrough_node_data_entry_add";
              uVar9 = 0x33e;
              goto LAB_0050dbbc;
            }
          }
          else {
            pvVar4 = (void *)find_olddest_response(piVar3);
            if (pvVar4 != (void *)0x0) {
              if (*(int *)((int)pvVar4 + 0x18) == 0) {
                *(int *)((int)pvVar4 + 0xc) = iVar1;
              }
              else {
                FUN_00407df0();
                *(undefined4 *)((int)pvVar4 + 0x18) = 0;
                *(int *)((int)pvVar4 + 0xc) = iVar1;
              }
              *(size_t *)((int)pvVar4 + 0x10) = __n;
              FUN_00407e70();
              *(undefined4 *)((int)pvVar4 + 0x14) = extraout_v1_01;
              pvVar5 = (void *)FUN_00408450(*(int *)((int)pvVar4 + 0x10) + 1,0x32c);
              *(void **)((int)pvVar4 + 0x18) = pvVar5;
              if (pvVar5 != (void *)0x0) {
                memset(pvVar5,0,*(int *)((int)pvVar4 + 0x10) + 1);
                memcpy(*(void **)((int)pvVar4 + 0x18),local_310,*(size_t *)((int)pvVar4 + 0x10));
              }
              if (ac_passthrough_debug_switch != '\0') {
                uVar9 = 0x337;
LAB_0050dd64:
                printf("[AC_PASSTHROUGH_DEBUG]%s()/%d insert params cb :%d to hash successed.\n",
                       "ac_passthrough_node_data_entry_add",uVar9,*(undefined4 *)((int)pvVar4 + 0xc)
                      );
              }
LAB_0050dc90:
              if (ac_passthrough_debug_switch != '\0') {
                printf("[AC_PASSTHROUGH_DEBUG]%s()/%d insert params cb :%d to hash successed.\n",
                       "ac_passthrough_node_data_entry_add",0x34d,*(undefined4 *)((int)pvVar4 + 0xc)
                      );
              }
              if (ac_passthrough_debug_switch != '\0') {
                printf("[AC_PASSTHROUGH_DEBUG]%s()/%d add %d) success.\n",
                       "ac_passthrough_node_data_add",0x378,iVar1);
              }
LAB_0050d8b8:
              if (ac_passthrough_debug_switch != '\0') {
                printf("[AC_PASSTHROUGH_DEBUG]%s()/%d add params node success id:%d\n",
                       "insert_ac_passthrough_node",0x46e,iVar1);
              }
              if (local_310 != (void *)0x0) {
                FUN_00407df0();
              }
              if (ac_passthrough_info_switch != '\0') {
                printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                       "insert_ac_passthrough_node",0x474);
              }
              FUN_00407f30(ac_passthrough_get_reponse_mutex);
              return 0;
            }
            if (ac_passthrough_err_switch != '\0') {
              pcVar7 = "[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n";
              pcVar8 = "ac_passthrough_node_data_entry_add";
              uVar9 = 0x334;
LAB_0050dbbc:
              printf(pcVar7,pcVar8,uVar9);
            }
          }
        }
        else {
          if (ac_passthrough_debug_switch == '\0') {
            iVar10 = *(int *)(iVar2 + 0x18);
          }
          else {
            printf("[AC_PASSTHROUGH_DEBUG]%s()/%d update id:%d response\n",
                   "ac_passthrough_node_data_add",0x361,iVar1);
            iVar10 = *(int *)(iVar2 + 0x18);
          }
          if (iVar10 != 0) {
            FUN_00407df0(iVar10,0x367);
            *(undefined4 *)(iVar2 + 0x18) = 0;
          }
          iVar10 = FUN_00408450(__n_00,0x367);
          *(int *)(iVar2 + 0x18) = iVar10;
          if (iVar10 != 0) {
            *(int *)(iVar2 + 0xc) = iVar1;
            *(size_t *)(iVar2 + 0x10) = __n;
            FUN_00407e70();
            *(undefined4 *)(iVar2 + 0x14) = extraout_v1_00;
            memset(*(void **)(iVar2 + 0x18),0,__n_00);
            memcpy(*(void **)(iVar2 + 0x18),local_310,__n);
            goto LAB_0050d8b8;
          }
          if (ac_passthrough_err_switch != '\0') {
            pcVar7 = "[AC_PASSTHROUGH_ERROR]%s()/%d malloc error\n";
            pcVar8 = "ac_passthrough_node_data_add";
            uVar9 = 0x369;
            goto LAB_0050dbbc;
          }
        }
        if (ac_passthrough_err_switch != '\0') {
          printf("[AC_PASSTHROUGH_ERROR]%s()/%d ac_passthrough_node_data_addfailed.\n",
                 "insert_ac_passthrough_node",0x469);
        }
        if (ac_passthrough_info_switch != '\0') {
          uVar9 = 0x46a;
LAB_0050daa8:
          printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
                 "insert_ac_passthrough_node",uVar9);
        }
      }
      FUN_00407f30(ac_passthrough_get_reponse_mutex);
      goto LAB_0050d924;
    }
    if (ac_passthrough_response_result_hash == 0) {
      if (ac_passthrough_err_switch != '\0') {
        pcVar7 = "[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n";
        uVar9 = 0x387;
LAB_0050dbec:
        printf(pcVar7,"ac_passthrough_node_entry_add",uVar9);
      }
    }
    else {
      iVar2 = FUN_00407ed0();
      iVar10 = apmngr_db_get_ap_max();
      if (iVar2 < iVar10) {
        pvVar4 = (void *)FUN_00408450(0x18,0x38f);
        if (pvVar4 == (void *)0x0) {
          if (ac_passthrough_err_switch != '\0') {
            pcVar7 = "[AC_PASSTHROUGH_ERROR]%s()/%d malloc discovery-station failed.\n";
            uVar9 = 0x392;
            goto LAB_0050dbec;
          }
        }
        else {
          memset(pvVar4,0,0x18);
          memcpy((void *)((int)pvVar4 + 0x10),param_2,6);
          FUN_0051ad88((int)pvVar4 + 4);
          iVar2 = FUN_00408380(ac_passthrough_response_result_hash,pvVar4);
          if (iVar2 == 0) {
            if (ac_passthrough_debug_switch != '\0') {
              printf("[AC_PASSTHROUGH_DEBUG]%s()/%d insert response from ap: :%02x-%02x-%02x-%02x-%02x -%02x to  hash successed.\n"
                     ,"ac_passthrough_node_entry_add",0x3a2,(uint)*(byte *)((int)pvVar4 + 0x10),
                     (uint)*(byte *)((int)pvVar4 + 0x11),(uint)*(byte *)((int)pvVar4 + 0x12),
                     (uint)*(byte *)((int)pvVar4 + 0x13),(uint)*(byte *)((int)pvVar4 + 0x14),
                     (uint)*(byte *)((int)pvVar4 + 0x15));
            }
            if (ac_passthrough_debug_switch != '\0') {
              pcVar7 = "[AC_PASSTHROUGH_DEBUG]%s()/%d add (%s) success.\n";
              uVar9 = 0x3fa;
              goto LAB_0050d9a4;
            }
            goto LAB_0050d790;
          }
          if (ac_passthrough_err_switch != '\0') {
            printf("[AC_PASSTHROUGH_ERROR]%s()/%d insert response from ap: :%02x-%02x-%02x-%02x-%02x -%02x to hash failed.\n"
                   ,"ac_passthrough_node_entry_add",0x39d,(uint)*(byte *)((int)pvVar4 + 0x10),
                   (uint)*(byte *)((int)pvVar4 + 0x11),(uint)*(byte *)((int)pvVar4 + 0x12),
                   (uint)*(byte *)((int)pvVar4 + 0x13),(uint)*(byte *)((int)pvVar4 + 0x14),
                   (uint)*(byte *)((int)pvVar4 + 0x15));
          }
          FUN_00407df0(pvVar4);
        }
      }
      else if (ac_passthrough_err_switch != '\0') {
        pcVar7 = "[AC_PASSTHROUGH_ERROR]%s()/%d balance_dis_sta_hash is full.\n";
        uVar9 = 0x38c;
        goto LAB_0050dbec;
      }
    }
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d add (%s) failed.\n","ac_passthrough_node_add",0x3f6,
             param_2);
    }
    if (ac_passthrough_info_switch != '\0') {
      printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
             "ac_passthrough_node_add",0x3f7);
    }
    FUN_00407f30(ac_passthrough_get_reponse_mutex);
    if (ac_passthrough_err_switch == '\0') goto LAB_0050d924;
    uVar9 = 0x44f;
  }
  printf("[AC_PASSTHROUGH_ERROR]%s()/%d add ap_mac failed.\n","insert_ac_passthrough_node",uVar9);
  local_310 = (void *)0x0;
LAB_0050d924:
  if (local_310 != (void *)0x0) {
    FUN_00407df0();
  }
  return 0;
}

