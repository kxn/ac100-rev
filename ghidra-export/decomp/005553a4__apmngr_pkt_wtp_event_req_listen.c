// func _apmngr_pkt_wtp_event_req_listen @ 005553a4 size=1140

/* WARNING: Type propagation algorithm not settling */

undefined4 _apmngr_pkt_wtp_event_req_listen(undefined4 param_1,byte *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378;
  uint local_374;
  int local_370 [6];
  char local_358 [88];
  undefined1 auStack_300 [16];
  ushort local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2b2 [542];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d _apmngr_pkt_wtp_event_req_listen enter\n",
           "_apmngr_pkt_wtp_event_req_listen",0x7ce);
  }
  memset(auStack_300,0,0x2d8);
  local_358[0] = '\0';
  local_358[1] = '\0';
  local_358[2] = '\0';
  local_358[3] = '\0';
  local_374 = 3;
  local_358[4] = '\0';
  local_358[5] = '\0';
  local_358[6] = '\0';
  local_358[7] = '\0';
  local_358[8] = '\0';
  local_358[9] = '\0';
  local_358[10] = '\0';
  local_358[0xb] = '\0';
  local_358[0xc] = '\0';
  local_358[0xd] = '\0';
  local_358[0xe] = '\0';
  local_358[0xf] = '\0';
  local_358[0x10] = '\0';
  local_358[0x11] = '\0';
  local_358[0x12] = '\0';
  local_358[0x13] = '\0';
  local_370[0] = 0;
  local_378 = 0;
  local_37c = 0;
  local_370[1] = 0;
  local_370[2] = 0;
  local_370[3] = 0;
  local_370[4] = 0;
  local_370[5] = 0;
  local_380 = 0x14;
  memset(local_358 + 0x14,0,0x40);
  iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_300);
  if (iVar2 != 0) {
    if (apmngr_warning_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_WARNING]%s()/%d Cannot find the ap entry.\n","_apmngr_pkt_wtp_event_req_listen",
           0x7de);
    return 0xffffffff;
  }
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Get wtp event request packet.\n",
           "_apmngr_pkt_wtp_event_req_listen",0x7e2);
  }
  puVar3 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x5f);
  if (puVar3 != (ushort *)0x0) {
    if (apmngr_debug_switch == '\0') {
      uVar4 = (uint)param_2[1];
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        uVar4 = (uint)param_2[1];
      }
      else {
        printf("[APMNGR_DEBUG]%s()/%d Record AP log.\n","_apmngr_pkt_wtp_event_req_listen",0x7e6);
        uVar4 = (uint)param_2[1];
      }
    }
    snprintf(local_358,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_2,uVar4,(uint)param_2[2],
             (uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
    apmngr_aplog_config_get(local_370,&local_374,&local_378,&local_37c,local_370 + 1,&local_380);
    if (local_370[0] == 0) {
      if (ap_log_print_switch == 0) goto LAB_00555614;
      uVar1 = *puVar3;
    }
    else {
      uVar1 = *puVar3;
    }
    if ((uVar1 != 0) && (iVar2 = 0, *(int *)(puVar3 + 2) != 0)) {
LAB_00555580:
      do {
        uVar1 = *puVar3;
        while( true ) {
          if ((int)(uint)uVar1 <= iVar2) goto LAB_00555614;
          iVar8 = iVar2 * 8;
          if (*(int *)(*(int *)(puVar3 + 2) + iVar8 + 4) == 0) break;
          FUN_00408190(local_94,local_90,local_8c,local_88,local_84,local_358 + 0x14,0x40,"---");
          if (ap_log_print_switch != 0) {
            printf("AP %s(IP %s;MAC %s)\'s log:\n%s\n",auStack_2b2,local_358 + 0x14,local_358,
                   *(undefined4 *)(*(int *)(puVar3 + 2) + iVar8 + 4));
          }
          if (local_370[0] == 0) {
            iVar2 = iVar2 + 1;
            goto LAB_00555580;
          }
          uVar4 = (uint)*(byte *)(*(int *)(puVar3 + 2) + iVar8 + 1);
          if (local_374 < uVar4) break;
          iVar2 = iVar2 + 1;
          uVar6 = apmngr_db_product_type_str_by_ap_role(local_2ec);
          loggerk_reg(0x53,uVar4 + 0x3d02,1,uVar6,1,auStack_2b2,1,local_358 + 0x14,1,local_358,1,
                      *(undefined4 *)(*(int *)(puVar3 + 2) + iVar8 + 4),0);
          uVar1 = *puVar3;
        }
        iVar2 = iVar2 + 1;
      } while( true );
    }
  }
LAB_00555614:
  iVar2 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x90);
  if ((iVar2 != 0) &&
     (pbVar5 = (byte *)cw_priv_radio_role_table_control_tlv_ele_get(iVar2,0), pbVar5 != (byte *)0x0)
     ) {
    if (apmngr_debug_switch == '\0') {
      bVar7 = *pbVar5;
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        bVar7 = *pbVar5;
      }
      else {
        printf("[APMNGR_DEBUG]%s()/%d get ap_id=%d, radio_role_table_id=%d\n",
               "_apmngr_pkt_wtp_event_req_listen",0x812,(uint)local_2f0,(uint)*pbVar5);
        bVar7 = *pbVar5;
      }
    }
    iVar2 = apmngr_db_set_cur_using_rrst_idx(bVar7,local_2f0);
    if (((iVar2 == -1) && (apmngr_err_switch != '\0')) && (iVar2 = is_target_debug_ap(), iVar2 != 0)
       ) {
      printf("[APMNGR_ERROR]%s()/%d apmngr_db_set_cur_using_rrst_idx fail, ap_id=%d\n",
             "_apmngr_pkt_wtp_event_req_listen",0x815,(uint)local_2f0);
    }
  }
  return 0;
}

