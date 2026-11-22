// func _uac_wserv_add_cb @ 005d8b64 size=1288

undefined4 _uac_wserv_add_cb(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char cVar7;
  undefined4 uVar6;
  undefined4 uVar8;
  char local_30;
  char local_2f;
  byte local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = rdmngr_db_get_rd_status(*param_1);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar2 = rdmngr_db_generate_ap_id(*param_1);
  iVar1 = apmngr_db_capacity_support(uVar2 & 0xffff,1,0x3f);
  uVar3 = g_wserv_debug;
  if ((g_wserv_debug == 0) || (uVar3 = is_target_debug_ap(), uVar3 == 0)) {
    if (iVar1 == 0) {
      uVar2 = param_2 + 0x11bU & 3;
      uVar3 = *(int *)((param_2 + 0x11bU) - uVar2) << uVar2 * 8 |
              uVar3 & 0xffffffffU >> (4 - uVar2) * 8;
      goto LAB_005d8d9c;
    }
  }
  else {
    printf("<wserv>[debug]%s(): %d  -> ap_id: %d, rf_id: %d, support_private_148: %d\r\n",
           "_uac_wserv_add_cb",0x836,uVar2,*param_1,iVar1);
    if (iVar1 == 0) {
      uVar3 = *(uint *)(param_2 + 0x11b);
LAB_005d8d9c:
      if (uVar3 == 0) {
        return 0xffffffff;
      }
    }
  }
  if (g_wserv_debug == 0) {
    uVar3 = *param_1;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      uVar3 = *param_1;
    }
    else {
      printf("<wserv>[debug]%s(): %d  -> add wlan. rd_id[0x%08x], wlan_id[%d], ssid[%s].\r\n",
             "_uac_wserv_add_cb",0x83c,*param_1,(uint)*(byte *)(param_1 + 1),param_2 + 0x130);
      uVar3 = *param_1;
    }
  }
  local_2d = '\0';
  local_2e = 0;
  local_2f = -1;
  local_30 = -1;
  uVar3 = rdmngr_db_generate_ap_id(uVar3);
  uVar2 = *param_1;
  FUN_004082d0(DAT_007598e4,0xffffffff);
  iVar1 = _uac_wserv_packet_waiting_status_get_by_ap_id(uVar3,&local_2d);
  if (iVar1 == 0) {
    iVar1 = (uVar2 & 0xf) - 1;
    if (local_2d == '\0') {
      local_2c = 0;
      uVar8 = 0xffffffff;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      iVar4 = serv_wtp_address_arg_init(&local_2c);
      if (iVar4 == -1) {
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> serv_wtp_address_arg_init() fail.\r\n",
                 "_uac_wserv_packet_add_cb",0x787);
        }
      }
      else {
        iVar4 = apmngr_db_get_addr_by_capacity(uVar3 & 0xffff,&local_2c,0,1,0x15f0000,0);
        if (iVar4 == -1) {
          uVar8 = 0xffffffff;
          if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar5 = 
            "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
            uVar6 = 0x78d;
LAB_005d8ef4:
            uVar8 = 0xffffffff;
            printf(pcVar5,"_uac_wserv_packet_add_cb",uVar6,uVar3);
          }
        }
        else if (local_24 == 0) {
          uVar8 = 0xffffffff;
          if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar5 = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
            uVar6 = 0x794;
            goto LAB_005d8ef4;
          }
        }
        else {
          iVar4 = serv_user_defined_packet_send(&local_2c,_uac_wserv_packet_send_callback);
          if (iVar4 == 0) {
            _uac_wserv_packet_waiting_status_set_by_ap_id(uVar3,1);
            uVar8 = 0;
            _uac_wserv_packet_type_get_by_wlan_id(uVar3,iVar1,*(char *)(param_1 + 1) + -1,&local_2e)
            ;
            _uac_wserv_packet_type_set_by_wlan_id
                      (uVar3,iVar1,*(char *)(param_1 + 1) + -1,local_2e & 0xf0 | 1);
            _uac_wserv_packet_cur_id_set_by_ap_id
                      (uVar3,iVar1,(int)(char)(*(char *)(param_1 + 1) + -1));
          }
          else {
            uVar8 = 0xffffffff;
            if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = 
              "<wserv>[warning]%s(): %d  -> serv_user_defined_packet_send() failed.ap_id=%d\r\n";
              uVar6 = 0x79a;
              goto LAB_005d8ef4;
            }
          }
        }
      }
      serv_wtp_address_arg_destroy(&local_2c);
      goto LAB_005d8d70;
    }
    iVar4 = _uac_wserv_packet_type_get_by_wlan_id(uVar3,iVar1,*(char *)(param_1 + 1) + -1,&local_2e)
    ;
    if (iVar4 == 0) {
      if (local_2e >> 4 == 1) {
        uVar2 = 0x13;
      }
      else {
        uVar2 = (uint)(local_2e >> 4) << 4 | 1;
      }
      _uac_wserv_packet_type_set_by_wlan_id(uVar3,iVar1,*(char *)(param_1 + 1) + -1,uVar2);
      iVar4 = _uac_wserv_packet_cur_id_get_by_ap_id(uVar3,&local_2f,&local_30);
      if (iVar4 == 0) {
        iVar4 = (int)local_2f;
        if (iVar4 == -1) {
LAB_005d8cdc:
          cVar7 = *(char *)(param_1 + 1);
        }
        else if (local_30 == -1) {
          cVar7 = *(char *)(param_1 + 1);
        }
        else {
          if (iVar1 < iVar4) goto LAB_005d8cdc;
          uVar8 = 0;
          if ((iVar1 != iVar4) || ((int)local_30 <= (int)(*(byte *)(param_1 + 1) - 1)))
          goto LAB_005d8d70;
          cVar7 = *(char *)(param_1 + 1);
        }
        uVar8 = 0;
        _uac_wserv_packet_cur_id_set_by_ap_id(uVar3,iVar1,(int)(char)(cVar7 + -1));
LAB_005d8d70:
        FUN_00407f30(DAT_007598e4);
        return uVar8;
      }
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
      goto LAB_005d8fc0;
      pcVar5 = "<wserv>[error]%s(): %d  -> get packet_cur_id by ap id fail\r\n";
      uVar8 = 0x7b7;
    }
    else {
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
      goto LAB_005d8fc0;
      pcVar5 = "<wserv>[error]%s(): %d  -> get packet_type by wlan id fail\r\n";
      uVar8 = 0x7a9;
    }
  }
  else {
    if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
    goto LAB_005d8fc0;
    pcVar5 = "<wserv>[warning]%s(): %d  -> wserv_db_packet_waiting_type_get_by_ap_id() fail.\r\n";
    uVar8 = 0x77c;
  }
  printf(pcVar5,"_uac_wserv_packet_add_cb",uVar8);
LAB_005d8fc0:
  FUN_00407f30(DAT_007598e4);
  return 0xffffffff;
}

