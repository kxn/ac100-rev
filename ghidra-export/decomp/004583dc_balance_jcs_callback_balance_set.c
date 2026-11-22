// func balance_jcs_callback_balance_set @ 004583dc size=2264

/* WARNING: Type propagation algorithm not settling */

void balance_jcs_callback_balance_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined8 uVar10;
  int local_70 [18];
  
  if (param_1 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  local_70[0xb] = 0;
  local_70[0xc] = 0;
  local_70[0xd] = 0;
  local_70[0xe] = 0;
  local_70[0xf] = 0;
  local_70[0x10] = 0;
  local_70[5] = 0;
  local_70[6] = 0;
  local_70[7] = 0;
  local_70[8] = 0;
  local_70[9] = 0;
  local_70[10] = 0;
  iVar1 = balance_db_config_get(local_70 + 5);
  if (iVar1 == -1) {
    uVar8 = 0;
    if (g_balance_debug == 0) goto LAB_00458794;
    iVar1 = is_target_debug_ap(0);
    if (iVar1 == 0) {
      uVar8 = 0;
      goto LAB_00458794;
    }
    pcVar9 = "[BALANCE_DEBUG](%32s) %05d: get balance config failed.\r\n";
    uVar8 = 0x22d;
  }
  else {
    iVar1 = json_object_object_get(param_1,"enable");
    iVar2 = json_object_object_get(param_1,"mode");
    iVar3 = json_object_object_get(param_1,"usr_threshold");
    iVar4 = json_object_object_get(param_1,"dif_threshold");
    iVar5 = json_object_object_get(param_1,"max_fail_num");
    iVar6 = json_object_object_get(param_1,"rssi_threshold");
    if (((((iVar1 == 0) || (iVar2 == 0)) || (iVar3 == 0)) || ((iVar4 == 0 || (iVar5 == 0)))) ||
       (iVar6 == 0)) {
      uVar8 = 0;
      if (g_balance_error == 0) goto LAB_00458794;
      iVar1 = is_target_debug_ap(0);
      if (iVar1 != 0) {
        printf("[BALANCE_ERROR](%32s) %05d: get balance config by parsing config-json failed.\r\n",
               "balance_config_get_from_json",0x97);
      }
      uVar8 = 0;
      if (g_balance_error == 0) goto LAB_00458794;
      iVar1 = is_target_debug_ap(0);
      if (iVar1 == 0) {
        uVar8 = 0;
        goto LAB_00458794;
      }
      pcVar9 = "[BALANCE_ERROR](%32s) %05d: get config fron json failed.\r\n";
      uVar8 = 0x234;
    }
    else {
      iVar7 = json_object_get_type(iVar1);
      if (iVar7 == 3) {
        uVar8 = json_object_get_int(iVar1);
      }
      else {
        iVar7 = json_object_get_type();
        if (iVar7 == 2) {
          uVar10 = json_object_get_double(iVar1);
          uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "balance_config_get_from_json",0x9c);
          }
        }
      }
      balance_config_state_set(local_70 + 0xb,uVar8);
      iVar1 = json_object_get_type(iVar2);
      if (iVar1 == 3) {
        uVar8 = json_object_get_int(iVar2);
      }
      else {
        iVar1 = json_object_get_type();
        if (iVar1 == 2) {
          uVar10 = json_object_get_double(iVar2);
          uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "balance_config_get_from_json",0xa2);
          }
        }
      }
      balance_config_mode_set(local_70 + 0xb,uVar8);
      iVar1 = json_object_get_type(iVar3);
      if (iVar1 == 3) {
        uVar8 = json_object_get_int(iVar3);
      }
      else {
        iVar1 = json_object_get_type();
        if (iVar1 == 2) {
          uVar10 = json_object_get_double(iVar3);
          uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "balance_config_get_from_json",0xa6);
          }
        }
      }
      balance_config_threshold_set(local_70 + 0xb,uVar8);
      iVar1 = json_object_get_type(iVar4);
      if (iVar1 == 3) {
        uVar8 = json_object_get_int(iVar4);
      }
      else {
        iVar1 = json_object_get_type();
        if (iVar1 == 2) {
          uVar10 = json_object_get_double(iVar4);
          uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "balance_config_get_from_json",0xaa);
          }
        }
      }
      balance_config_dif_threshold_set(local_70 + 0xb,uVar8);
      iVar1 = json_object_get_type(iVar5);
      if (iVar1 == 3) {
        uVar8 = json_object_get_int(iVar5);
      }
      else {
        iVar1 = json_object_get_type();
        if (iVar1 == 2) {
          uVar10 = json_object_get_double(iVar5);
          uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "balance_config_get_from_json",0xae);
          }
        }
      }
      balance_config_max_fail_num_set(local_70 + 0xb,uVar8);
      iVar1 = json_object_get_type(iVar6);
      if (iVar1 == 3) {
        uVar8 = json_object_get_int(iVar6);
      }
      else {
        iVar1 = json_object_get_type();
        if (iVar1 == 2) {
          uVar10 = json_object_get_double(iVar6);
          uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "balance_config_get_from_json",0xb2);
          }
        }
      }
      balance_config_rssi_threshold_set(local_70 + 0xb,uVar8);
      iVar1 = memcmp(local_70 + 5,local_70 + 0xb,0x18);
      if (iVar1 == 0) {
        uVar8 = 1;
        if (g_balance_debug != 0) {
          iVar1 = is_target_debug_ap(1);
          if (iVar1 == 0) {
            uVar8 = 1;
          }
          else {
            printf("[BALANCE_DEBUG](%32s) %05d: config has no change, so do nothing.\r\n",
                   "balance_jcs_callback_balance_set",0x23b);
            uVar8 = 1;
          }
        }
        goto LAB_00458794;
      }
      iVar1 = balance_db_config_set(local_70 + 0xb);
      if (iVar1 == -1) {
        uVar8 = 0;
        if (g_balance_debug == 0) goto LAB_00458794;
        iVar1 = is_target_debug_ap(0);
        if (iVar1 == 0) {
          uVar8 = 0;
          goto LAB_00458794;
        }
        pcVar9 = "[BALANCE_DEBUG](%32s) %05d: set balance config failed.\r\n";
        uVar8 = 0x243;
        goto LAB_00458788;
      }
      if (local_70[5] == local_70[0xb]) {
        if ((local_70[5] == 1) && (local_70[0x10] != local_70[10])) {
          if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(local_70 + 1), iVar1 != 0)) {
            uVar8 = 0x1fd;
            goto LAB_00458b04;
          }
          goto LAB_004586fc;
        }
        if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(local_70), iVar1 != 0)) {
          printf("[BALANCE_DEBUG](%32s) %05d: needn\'t send packet.\r\n",
                 "balance_need_send_packet_handle",0x202);
        }
LAB_00458a14:
        local_70[0] = 0;
        wsta_roam_db_roam_strategy_update(local_70);
        if (local_70[0] == 0) {
          uVar8 = 1;
        }
        else {
          wsta_intelligent_roam_ctl_update_to_all_ap(1);
          uVar8 = 1;
        }
        goto LAB_00458794;
      }
      if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(local_70 + 1), iVar1 != 0)) {
        uVar8 = 0x1f8;
LAB_00458b04:
        printf("[BALANCE_DEBUG](%32s) %05d: need send packet.\r\n","balance_need_send_packet_handle"
               ,uVar8);
      }
LAB_004586fc:
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      local_70[4] = 0;
      iVar1 = serv_wtp_address_arg_init(local_70 + 1);
      if (iVar1 == -1) {
        if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[BALANCE_ERROR](%32s) %05d: init serv argv failed.\r\n",
                 "balance_all_wtps_packt_send",0x183);
        }
      }
      else {
        iVar1 = apmngr_db_get_all_addr_by_capacity(local_70 + 1,1,1,0x15f0000,0);
        if (iVar1 != -1) {
          if (local_70[3] == 0) {
            if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[BALANCE_DEBUG](%32s) %05d: no wtp need send balance pakcet.\r\n",
                     "balance_all_wtps_packt_send",400);
            }
          }
          else {
            iVar1 = balance_packet_send(local_70 + 1,local_70 + 0xb);
            if (iVar1 == -1) {
              if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar9 = "[BALANCE_ERROR](%32s) %05d: init serv argv failed.\r\n";
                uVar8 = 0x198;
                goto LAB_00458c80;
              }
              goto LAB_00458c0c;
            }
          }
          serv_wtp_address_arg_destroy(local_70 + 1);
          goto LAB_00458a14;
        }
        if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar9 = "[BALANCE_ERROR](%32s) %05d: get serv argv failed.\r\n";
          uVar8 = 0x189;
LAB_00458c80:
          printf(pcVar9,"balance_all_wtps_packt_send",uVar8);
        }
LAB_00458c0c:
        serv_wtp_address_arg_destroy(local_70 + 1);
      }
      uVar8 = 0;
      if (g_balance_error == 0) goto LAB_00458794;
      iVar1 = is_target_debug_ap(0);
      if (iVar1 != 0) {
        printf("[BALANCE_ERROR](%32s) %05d: send packet failed.\r\n",
               "balance_need_send_packet_handle",0x20c);
      }
      uVar8 = 0;
      if (g_balance_error == 0) goto LAB_00458794;
      iVar1 = is_target_debug_ap(0);
      uVar8 = 0;
      if (iVar1 == 0) goto LAB_00458794;
      pcVar9 = "[BALANCE_ERROR](%32s) %05d: balance send packet failed.\r\n";
      uVar8 = 0x24c;
    }
  }
LAB_00458788:
  printf(pcVar9,"balance_jcs_callback_balance_set",uVar8);
  uVar8 = 0;
LAB_00458794:
  uVar8 = json_object_new_boolean(uVar8);
  json_object_object_add(param_2,&DAT_00676a24,uVar8);
  return;
}

