// func apmngr_pkt_config_update_request_pkt_send @ 005590c0 size=2104

int apmngr_pkt_config_update_request_pkt_send(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte bVar7;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  char *__format;
  undefined4 uVar8;
  int iVar9;
  undefined4 local_98;
  char *local_94;
  char *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [68];
  
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  if (param_1 == 0) {
    return -1;
  }
  if (*(int *)(param_1 + 0x14) == 5) {
    return 0;
  }
  memset(auStack_68,0,0x40);
  FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
               *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
               *(undefined4 *)(param_1 + 0x27c),auStack_68,0x40,"---");
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(&local_8c), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Send Config Update Request packet to update AP(ip:%s, port:%d)\'s config.\n"
           ,"apmngr_pkt_config_update_request_pkt_send",0x88f,auStack_68,
           (uint)*(ushort *)(param_1 + 0x280));
  }
  iVar9 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_8c);
  if ((iVar1 != 0) ||
     (iVar1 = apmngr_db_get_addr_by_capacity
                        (*(undefined2 *)(param_1 + 0x10),&local_8c,1,0,0xffffffff,0), iVar1 != 0))
  goto LAB_00559184;
  if (local_84 == 0) {
    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d No need to send config update for AP %d.\n",
             "apmngr_pkt_config_update_request_pkt_send",0x8a0,(uint)*(ushort *)(param_1 + 0x10));
    }
    goto LAB_00559184;
  }
  iVar1 = -1;
  iVar9 = cw_pkt_buf_create(0xfa);
  if (iVar9 == 0) goto LAB_00559184;
  iVar1 = -1;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) goto LAB_00559184;
  iVar1 = _apmngr_pkt_element_encap(param_1 + 0x40,param_1 + 0x208,iVar2,param_2);
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0x250) & 0x1000) == 0) {
      uVar6 = *(uint *)(param_1 + 0x254);
LAB_005592cc:
      if ((uVar6 & 0x400) == 0) {
        uVar6 = *(uint *)(param_1 + 600);
      }
      else {
        local_98 = 3;
        local_7c = 0;
        local_78 = 0;
        if (*(char *)(param_1 + 0x130) == '\0') {
          local_98 = 1;
        }
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        FUN_0051ad88(&local_74);
        iVar5 = cw_service_msg_add(iVar2,0x25,&local_7c,1,0x6f,&local_98);
        if (iVar5 != 0) {
          if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config update response.\n"
                   ,"_apmngr_pkt_led_mode_encap",0x68b);
          }
          iVar1 = -1;
          if ((apmngr_err_switch == '\0') || (iVar5 = is_target_debug_ap(), iVar5 == 0))
          goto LAB_00559380;
          pcVar3 = "_apmngr_pkt_led_mode_encap";
          uVar8 = 0x691;
          goto LAB_00559414;
        }
        uVar6 = *(uint *)(param_1 + 600);
      }
      if ((uVar6 & 0x2000) == 0) {
        uVar6 = *(uint *)(param_1 + 600);
      }
      else {
        if (apmngr_debug_switch == '\0') {
          bVar7 = *(byte *)(param_1 + 0x131);
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            bVar7 = *(byte *)(param_1 + 0x131);
          }
          else {
            printf("[APMNGR_DEBUG]%s()/%d cfg_info->bluetooth_enable = %d\n",
                   "_apmngr_config_update_req_pkt_create",0x837,(int)*(char *)(param_1 + 0x131));
            bVar7 = *(byte *)(param_1 + 0x131);
          }
        }
        local_7c = 0;
        local_98 = (uint)bVar7 << 0x18;
        local_78 = 0;
        local_94 = (char *)0xffffffff;
        local_90 = (char *)0xffffffff;
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        FUN_0051ad88(&local_74);
        iVar5 = cw_service_msg_add(iVar2,0x25,&local_7c,1,0xa7,&local_98);
        if (iVar5 != 0) {
          if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config update response.\n"
                   ,"_apmngr_pkt_bluetooth_encap",0x6a3);
          }
          iVar1 = -1;
          if (apmngr_err_switch != '\0') {
            iVar1 = is_target_debug_ap();
            if (iVar1 != 0) {
              pcVar3 = "_apmngr_pkt_bluetooth_encap";
              uVar8 = 0x6a9;
              goto LAB_00559414;
            }
            iVar1 = -1;
          }
          goto LAB_00559380;
        }
        uVar6 = *(uint *)(param_1 + 600);
      }
      if ((uVar6 & 0x8000) == 0) {
        uVar6 = *(uint *)(param_1 + 600);
LAB_00559554:
        if ((uVar6 & 0x200) != 0) {
          if (apmngr_debug_switch == '\0') {
            local_98 = (int)*(char *)(param_1 + 0x1b4);
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              local_98 = (int)*(char *)(param_1 + 0x1b4);
            }
            else {
              printf("[APMNGR_DEBUG]%s()/%d create fit fat button status pkt\n",
                     "_apmngr_config_update_req_pkt_create",0x842);
              local_98 = (int)*(char *)(param_1 + 0x1b4);
            }
          }
          local_7c = 0;
          local_78 = 0;
          local_74 = 0;
          local_70 = 0;
          local_6c = 0;
          FUN_0051ad88(&local_74);
          iVar5 = cw_service_msg_add(iVar2,0x25,&local_7c,1,0xa4,&local_98);
          if (iVar5 != 0) {
            if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config update response.\n"
                     ,"_apmngr_pkt_fit_fat_button_status_encap",0x6b7);
            }
            iVar1 = -1;
            if ((apmngr_err_switch != '\0') && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements.\n",
                     "_apmngr_pkt_fit_fat_button_status_encap",0x6bd);
            }
          }
        }
      }
      else {
        if ((apmngr_debug_switch != '\0') && (iVar5 = is_target_debug_ap(0x80), iVar5 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d cfg_info->account_password = %s\n",
                 "_apmngr_config_update_req_pkt_create",0x83c,param_1 + 0x173);
        }
        local_98 = 0;
        local_94 = (char *)0x0;
        local_90 = (char *)0x0;
        local_7c = 0;
        local_78 = 0;
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        pcVar3 = (char *)FUN_00408450(0x80,0x6f5);
        if (pcVar3 == (char *)0x0) {
          if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = "[APMNGR_ERROR]%s()/%d Malloc failed.\n";
            uVar8 = 0x6f8;
LAB_0055979c:
            printf(__format,"_apmngr_pkt_ap_web_account_encap",uVar8);
          }
        }
        else {
          memset(pcVar3,0,0x80);
          local_98 = CONCAT22(1,local_98._2_2_);
          sVar4 = strlen((char *)(param_1 + 0x132));
          local_98._2_2_ = CONCAT11((char)sVar4,(undefined1)local_98);
          local_94 = (char *)(param_1 + 0x132);
          apmngr_encrypt_alg_md5_v2(param_1 + 0x173,pcVar3);
          sVar4 = strlen(pcVar3);
          local_98 = CONCAT31(local_98._0_3_,(char)sVar4);
          local_90 = pcVar3;
          FUN_0051ad88(&local_74);
          iVar5 = cw_service_msg_add(iVar2,0x25,&local_7c,1,0xa9,&local_98);
          if (iVar5 == 0) {
            FUN_00407df0(pcVar3);
            uVar6 = *(uint *)(param_1 + 600);
            goto LAB_00559554;
          }
          if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = 
            "[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config update response.\n"
            ;
            uVar8 = 0x709;
            goto LAB_0055979c;
          }
        }
        if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements.\n",
                 "_apmngr_pkt_ap_web_account_encap",0x710);
        }
        if (pcVar3 == (char *)0x0) {
          iVar1 = -1;
        }
        else {
          FUN_00407df0(pcVar3);
          iVar1 = -1;
        }
      }
    }
    else {
      local_98 = *(int *)(param_1 + 0x124);
      local_7c = 0;
      local_78 = 0;
      local_74 = 0;
      local_70 = 0;
      local_6c = 0;
      FUN_0051ad88(&local_74);
      iVar5 = cw_service_msg_add(iVar2,0x25,&local_7c,1,0x44,&local_98);
      if (iVar5 == 0) {
        uVar6 = *(uint *)(param_1 + 0x254);
        goto LAB_005592cc;
      }
      if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config update response.\n"
               ,"_apmngr_pkt_ap_trunk_encap",0x674);
      }
      iVar1 = -1;
      if ((apmngr_err_switch == '\0') || (iVar5 = is_target_debug_ap(), iVar5 == 0))
      goto LAB_00559380;
      pcVar3 = "_apmngr_pkt_ap_trunk_encap";
      uVar8 = 0x67a;
LAB_00559414:
      iVar1 = -1;
      printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements.\n",pcVar3,uVar8);
    }
  }
LAB_00559380:
  if (apmngr_pkt_switch != '\0') {
    capwap_parsed_packet_dump(iVar2);
  }
  if (iVar1 == 0) {
    iVar1 = capwap_packet_assemble(iVar9,iVar2);
  }
  cw_parsed_pkt_destroy(iVar2);
  if ((iVar1 == 0) && (iVar1 = serv_packet_send(&local_8c,iVar9,1), iVar1 == 0)) {
    iVar1 = _apmngr_pkt_set_arg_timer
                      (*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                       *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                       *(undefined4 *)(param_1 + 0x27c),*(undefined2 *)(param_1 + 0x280),
                       param_1 + 0x48,*(undefined1 *)(param_1 + 0xe8));
  }
LAB_00559184:
  serv_wtp_address_arg_destroy(&local_8c);
  if (iVar9 != 0) {
    cw_pkt_buf_destroy(iVar9);
  }
  return iVar1;
}

