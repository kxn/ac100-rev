// func _rrm_jcs_rrm_para_set @ 004a95a8 size=4144

void _rrm_jcs_rrm_para_set(int param_1,int param_2)

{
  int iVar1;
  char *__dest;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  char acStack_70 [31];
  undefined1 local_51;
  char acStack_50 [31];
  undefined1 local_31;
  undefined4 local_30;
  
  local_30 = g_autorrm_enable;
  memset(acStack_50,0,0x20);
  memset(acStack_70,0,0x20);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (rrm_err_switch == '\0') {
      return;
    }
    printf("[RRM_ERROR]%s()/%d inputs error.\n","_rrm_jcs_rrm_para_set",0x94d);
    return;
  }
  iVar1 = rrm_db_state_get();
  if ((iVar1 != 0) && (iVar1 != 7)) {
    uVar7 = 0xffffffff;
    if (rrm_debug_switch != '\0') {
      printf("[RRM_DEBUG]%s()/%d You can\'t do rrm in state(%d),please wait for a moment\n",
             "_rrm_jcs_rrm_para_set",0x953,iVar1);
    }
    goto LAB_004a963c;
  }
  iVar1 = json_object_object_get(param_1,"group_id_str");
  if (iVar1 == 0) {
    __dest = (char *)0x0;
  }
  else {
    __dest = (char *)FUN_00408450(0x1c16,0x95b);
    if (__dest == (char *)0x0) {
      uVar7 = 0;
      if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_rrm_jcs_rrm_para_set",0x95e);
      }
      goto LAB_004a963c;
    }
    memset(__dest,0,0x1c16);
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_rrm_jcs_rrm_para_set",0x962);
      }
      pcVar5 = "";
    }
    strncpy(__dest,pcVar5,0x1c15);
    __dest[0x1c15] = '\0';
    _rrm_group_id_set(__dest);
  }
  iVar1 = json_object_object_get(param_1,"freq_enable");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar5);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_rrm_jcs_rrm_para_set",0x969);
      }
      if (jcs_err_switch == 0) {
        iVar1 = -1;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_rrm_jcs_rrm_para_set",
               0x969);
        iVar1 = -1;
      }
    }
    _rrm_freq_enable_set(iVar1);
  }
  iVar1 = json_object_object_get(param_1,"pwr_enable");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar8) {
            if (jcs_err_switch == 0) goto LAB_004a9798;
            pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004a9a78;
          }
          iVar2 = iVar8 * 0x10;
          pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
          if (pcVar5 != (char *)0x0) break;
          iVar8 = iVar8 + 1;
        }
        pcVar4 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar5,pcVar4);
        iVar8 = iVar8 + 1;
      } while (iVar3 != 0);
      g_pwr_enable = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004a9a78:
        printf(pcVar5,"_rrm_jcs_rrm_para_set",0x96e);
      }
LAB_004a9798:
      if (jcs_err_switch == 0) {
        g_pwr_enable = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_rrm_jcs_rrm_para_set",
               0x96e);
        g_pwr_enable = 0xffffffff;
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"chnl_enable");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar8) {
            if (jcs_err_switch == 0) goto LAB_004a97f0;
            pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004a9acc;
          }
          iVar2 = iVar8 * 0x10;
          pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
          if (pcVar5 != (char *)0x0) break;
          iVar8 = iVar8 + 1;
        }
        pcVar4 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar5,pcVar4);
        iVar8 = iVar8 + 1;
      } while (iVar3 != 0);
      g_chnl_enable = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004a9acc:
        printf(pcVar5,"_rrm_jcs_rrm_para_set",0x971);
      }
LAB_004a97f0:
      if (jcs_err_switch == 0) {
        g_chnl_enable = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_rrm_jcs_rrm_para_set",
               0x971);
        g_chnl_enable = 0xffffffff;
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"bw_2g");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (bw_map <= iVar8) {
            if (jcs_err_switch == 0) goto LAB_004a9848;
            pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004a9ab0;
          }
          iVar2 = iVar8 * 0x10;
          pcVar5 = *(char **)(PTR__mt_bw_007318d4 + iVar2);
          if (pcVar5 != (char *)0x0) break;
          iVar8 = iVar8 + 1;
        }
        pcVar4 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar5,pcVar4);
        iVar8 = iVar8 + 1;
      } while (iVar3 != 0);
      g_bw_2g = *(undefined4 *)(PTR__mt_bw_007318d4 + iVar2 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004a9ab0:
        printf(pcVar5,"_rrm_jcs_rrm_para_set",0x974);
      }
LAB_004a9848:
      if (jcs_err_switch == 0) {
        g_bw_2g = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_rrm_jcs_rrm_para_set",
               0x974);
        g_bw_2g = 0xffffffff;
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"bw_5g");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 == 6) {
      while (iVar8 < bw_map) {
        pcVar5 = *(char **)(PTR__mt_bw_007318d4 + iVar8 * 0x10);
        if (pcVar5 == (char *)0x0) {
          iVar8 = iVar8 + 1;
        }
        else {
          pcVar4 = (char *)json_object_get_string(iVar1);
          iVar2 = strcmp(pcVar5,pcVar4);
          if (iVar2 == 0) {
            g_bw_5g = *(undefined4 *)(PTR__mt_bw_007318d4 + iVar8 * 0x10 + 0xc);
            goto LAB_004a98b8;
          }
          iVar8 = iVar8 + 1;
        }
      }
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
        goto LAB_004a9a94;
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004a9a94:
      printf(pcVar5,"_rrm_jcs_rrm_para_set",0x977);
    }
    if (jcs_err_switch == 0) {
      g_bw_5g = 0xffffffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_rrm_jcs_rrm_para_set",
             0x977);
      g_bw_5g = 0xffffffff;
    }
  }
LAB_004a98b8:
  iVar1 = json_object_object_get(param_1,"chnl_2g_set");
  if (iVar1 == 0) {
LAB_004a9cd4:
    iVar1 = json_object_object_get(param_1,"chnl_5g1_set");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if ((iVar2 != 5) || (iVar2 = json_object_array_length(iVar1), iVar2 < 1)) {
        uVar7 = 0xffffffff;
        if (rrm_err_switch != '\0') {
          pcVar5 = "[RRM_ERROR]%s()/%d parse channel list of 5G failed\n";
          uVar6 = 0x990;
          goto LAB_004a9990;
        }
        goto LAB_004a98f8;
      }
      DAT_00767bd5 = 0;
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 5) {
        puVar9 = &DAT_00767bd6;
        for (iVar2 = 0; (iVar8 = json_object_array_length(iVar1), iVar2 < iVar8 && (iVar2 != 4));
            iVar2 = iVar2 + 1) {
          iVar8 = json_object_array_get_idx(iVar1,iVar2);
          if (iVar8 == 0) {
LAB_004aa260:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_rrm_jcs_rrm_para_set",0x98c);
            }
            *puVar9 = 0xff;
          }
          else {
            iVar3 = json_object_get_type(iVar8);
            if (iVar3 != 6) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_rrm_jcs_rrm_para_set",0x98c);
              }
              goto LAB_004aa260;
            }
            pcVar5 = (char *)json_object_get_string(iVar8);
            iVar8 = atoi(pcVar5);
            *puVar9 = (char)iVar8;
          }
          puVar9 = puVar9 + 1;
        }
        DAT_00767bd5 = (undefined1)iVar2;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if ((iVar2 == 4) && (iVar1 = json_object_object_length(iVar1), iVar1 == 0)) {
          DAT_00767bd5 = 0;
        }
        else if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
                 ,"_rrm_jcs_rrm_para_set",0x98c);
        }
      }
    }
    iVar1 = json_object_object_get(param_1,"chnl_5g2_set");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if ((iVar2 != 5) || (iVar2 = json_object_array_length(iVar1), iVar2 < 1)) {
        uVar7 = 0xffffffff;
        if (rrm_err_switch != '\0') {
          pcVar5 = "[RRM_ERROR]%s()/%d parse channel list of 5G2 failed\n";
          uVar6 = 0x99e;
          goto LAB_004a9990;
        }
        goto LAB_004a98f8;
      }
      DAT_00767bd8._2_1_ = 0;
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 5) {
        puVar9 = (undefined1 *)((int)&DAT_00767bd8 + 3);
        for (iVar2 = 0; (iVar8 = json_object_array_length(iVar1), iVar2 < iVar8 && (iVar2 != 4));
            iVar2 = iVar2 + 1) {
          iVar8 = json_object_array_get_idx(iVar1,iVar2);
          if (iVar8 == 0) {
LAB_004aa3f4:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_rrm_jcs_rrm_para_set",0x99a);
            }
            *puVar9 = 0xff;
          }
          else {
            iVar3 = json_object_get_type(iVar8);
            if (iVar3 != 6) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_rrm_jcs_rrm_para_set",0x99a);
              }
              goto LAB_004aa3f4;
            }
            pcVar5 = (char *)json_object_get_string(iVar8);
            iVar8 = atoi(pcVar5);
            *puVar9 = (char)iVar8;
          }
          puVar9 = puVar9 + 1;
        }
        DAT_00767bd8._2_1_ = (undefined1)iVar2;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if ((iVar2 == 4) && (iVar1 = json_object_object_length(iVar1), iVar1 == 0)) {
          DAT_00767bd8._2_1_ = 0;
        }
        else if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
                 ,"_rrm_jcs_rrm_para_set",0x99a);
        }
      }
    }
    iVar1 = json_object_object_get(param_1,"pwr_threshold");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
        iVar1 = atoi(pcVar5);
        low_threshold = (undefined1)iVar1;
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9a4);
        }
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9a4);
        }
        low_threshold = 0xff;
      }
    }
    high_threshold = low_threshold;
    iVar1 = json_object_object_get(param_1,"pwr_min_pwr");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
        rrm_pwr_min_power = atoi(pcVar5);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9a8);
        }
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9a8);
        }
        rrm_pwr_min_power = -1;
      }
    }
    iVar1 = json_object_object_get(param_1,"pwr_max_pwr");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
        rrm_pwr_max_power = atoi(pcVar5);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9ab);
        }
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9ab);
        }
        rrm_pwr_max_power = -1;
      }
    }
    iVar1 = json_object_object_get(param_1,"autorrm_enable");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      iVar8 = 0;
      if (iVar2 == 6) {
        do {
          while( true ) {
            if (onoff_map <= iVar8) {
              if (jcs_err_switch == 0) goto LAB_004aa0e8;
              pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
              goto LAB_004aa374;
            }
            iVar2 = iVar8 * 0x10;
            pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
            if (pcVar5 != (char *)0x0) break;
            iVar8 = iVar8 + 1;
          }
          pcVar4 = (char *)json_object_get_string(iVar1);
          iVar3 = strcmp(pcVar5,pcVar4);
          iVar8 = iVar8 + 1;
        } while (iVar3 != 0);
        local_30 = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
      }
      else {
        if (jcs_err_switch != 0) {
          pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004aa374:
          printf(pcVar5,"_rrm_jcs_rrm_para_set",0x9ae);
        }
LAB_004aa0e8:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_rrm_jcs_rrm_para_set",0x9ae);
        }
        local_30 = 0xffffffff;
      }
    }
    iVar1 = json_object_object_get(param_1,"autorrm_date");
    if ((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 6)) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_rrm_jcs_rrm_para_set",0x9b3);
        }
        pcVar5 = "";
      }
      strncpy(acStack_50,pcVar5,0x1f);
      local_31 = 0;
    }
    iVar1 = json_object_object_get(param_1,"autorrm_time");
    if ((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 6)) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_rrm_jcs_rrm_para_set",0x9b8);
        }
        pcVar5 = "";
      }
      strncpy(acStack_70,pcVar5,0x1f);
      local_51 = 0;
    }
    uVar7 = 0;
    _autorrm_config_set(local_30,acStack_50,acStack_70);
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if ((iVar2 == 5) && (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
      rrm_channel_list = 0;
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 5) {
        puVar9 = &DAT_00767bd1;
        for (iVar2 = 0; (iVar8 = json_object_array_length(iVar1), iVar2 < iVar8 && (iVar2 != 4));
            iVar2 = iVar2 + 1) {
          iVar8 = json_object_array_get_idx(iVar1,iVar2);
          if (iVar8 == 0) {
LAB_004a9e2c:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_rrm_jcs_rrm_para_set",0x97e);
            }
            *puVar9 = 0xff;
          }
          else {
            iVar3 = json_object_get_type(iVar8);
            if (iVar3 != 6) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_rrm_jcs_rrm_para_set",0x97e);
              }
              goto LAB_004a9e2c;
            }
            pcVar5 = (char *)json_object_get_string(iVar8);
            iVar8 = atoi(pcVar5);
            *puVar9 = (char)iVar8;
          }
          puVar9 = puVar9 + 1;
        }
        rrm_channel_list = (undefined1)iVar2;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if ((iVar2 == 4) && (iVar1 = json_object_object_length(iVar1), iVar1 == 0)) {
          rrm_channel_list = 0;
        }
        else if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
                 ,"_rrm_jcs_rrm_para_set",0x97e);
        }
      }
      goto LAB_004a9cd4;
    }
    uVar7 = 0xffffffff;
    if (rrm_err_switch != '\0') {
      pcVar5 = "[RRM_ERROR]%s()/%d parse channel list of 2.4G failed\n";
      uVar6 = 0x982;
LAB_004a9990:
      uVar7 = 0xffffffff;
      printf(pcVar5,"_rrm_jcs_rrm_para_set",uVar6);
    }
  }
LAB_004a98f8:
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
LAB_004a963c:
  uVar7 = json_object_new_int(uVar7);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  return;
}

