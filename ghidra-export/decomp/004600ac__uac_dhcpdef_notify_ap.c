// func _uac_dhcpdef_notify_ap @ 004600ac size=2620

undefined4 _uac_dhcpdef_notify_ap(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined4 local_68;
  int local_64;
  void *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> ------------->Going to notify ap_id[%d]!\r\n","dhcp_defend",
           "_uac_dhcpdef_notify_ap",0x2a5,param_1);
  }
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_5c);
  if (iVar1 == -1) {
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(&local_5c), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Failed to serv_wtp_address_arg_init()!\x1b[0m\r\n",
             "dhcp_defend","_uac_dhcpdef_notify_ap",0x2ab);
    }
    serv_wtp_address_arg_destroy(&local_5c);
    return 0xffffffff;
  }
  apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&local_5c,1,1,0x15f0000,1,0xf);
  uVar8 = (undefined1)param_2;
  if (local_54 != 0) {
    if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[%s]<%s():%d> Num of APs to be notified: %d.\r\n","dhcp_defend",
             "_uac_dhcpdef_notify_ap",700,local_54);
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 == 0) {
      uVar7 = 0xffffffff;
      if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0046029c;
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
      uVar6 = 0x2c3;
      goto LAB_0046067c;
    }
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = (void *)0x0;
    iVar2 = cw_parsed_pkt_create(7);
    if (iVar2 == 0) {
      if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_004604c4;
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
      pcVar5 = "_uac_dhcpdef_packet_create";
      uVar7 = 0x21a;
      goto LAB_004604b8;
    }
    FUN_0051ad88(&local_30);
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_packet_set_priv_msg_ele",
             0x1b6,"_uac_dhcpdef_packet_set_priv_msg_ele");
    }
    iVar3 = dhcpdef_db_apbind_entry_shallow_get(param_1,&local_4c);
    if (iVar3 == 0) {
      local_68._1_3_ = CONCAT12(uVar8,local_68._2_2_);
      local_64 = 0;
      local_68 = CONCAT13(local_44._0_1_,local_68._1_3_);
      local_60 = (void *)0x0;
      if (param_2 == 1) {
        iVar3 = CONCAT31(local_44._1_3_,local_40._0_1_);
        if (iVar3 < 1) {
          local_68 = (uint)local_68._1_3_;
          goto LAB_004605dc;
        }
        local_68 = CONCAT13(uVar8,local_68._1_3_);
        local_64 = iVar3;
        local_60 = (void *)FUN_00408450(iVar3 * 7,0x1c9);
        if (local_60 == (void *)0x0) {
          if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar4 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
            pcVar5 = "_uac_dhcpdef_packet_set_priv_msg_ele";
            uVar7 = 0x1cc;
            goto LAB_004604b8;
          }
          goto LAB_004604c4;
        }
        memset(local_60,0,local_64 * 7);
        dhcpdef_db_ap_all_bindsvr_foreach
                  (param_1,_uac_dhcpdef_packet_bind_svr_get,local_60,&local_64);
        if (local_64 == 0) {
          FUN_00407df0(local_60);
          goto LAB_004605dc;
        }
      }
      else {
LAB_004605dc:
        local_60 = (void *)0x0;
      }
      iVar3 = cw_service_msg_add(iVar2,0x25,&local_38,1,0x47,&local_68);
      if (iVar3 == 0) {
        iVar3 = capwap_packet_assemble(iVar1,iVar2);
        if (iVar3 != -1) {
          if (local_60 != (void *)0x0) {
            FUN_00407df0();
          }
          cw_parsed_pkt_destroy(iVar2);
          iVar2 = serv_packet_send(&local_5c,iVar1,1);
          if (iVar2 == 0) {
            uVar7 = 0;
            if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[%s]<%s():%d> <-------------succeed to send packet to ap_id[%d].\r\n",
                     "dhcp_defend","_uac_dhcpdef_notify_ap",0x2d3,param_1);
            }
            goto LAB_00460260;
          }
          uVar7 = 0;
          if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_0046029c;
          pcVar4 = "\x1b[31;49m[%s]<%s():%d> Failed to send packt to ap_id[%d]!\x1b[0m\r\n";
          uVar6 = 0x2cf;
LAB_004607c8:
          uVar7 = 0;
          printf(pcVar4,"dhcp_defend","_uac_dhcpdef_notify_ap",uVar6,param_1);
          goto LAB_0046029c;
        }
        if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar4 = "\x1b[31;49m[%s]<%s():%d> capwap_packet_assemble() fail!\x1b[0m\r\n";
          pcVar5 = "_uac_dhcpdef_packet_create";
          uVar7 = 0x235;
          goto LAB_004604b8;
        }
      }
      else if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> cw_service_msg_add() fail!\x1b[0m\r\n";
        pcVar5 = "_uac_dhcpdef_packet_create";
        uVar7 = 0x22e;
        goto LAB_004604b8;
      }
    }
    goto LAB_004604c4;
  }
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> <-------------Num of APs is 0, no need to send packet.\r\n","dhcp_defend",
           "_uac_dhcpdef_notify_ap",0x2b6);
  }
  iVar1 = 0;
  uVar7 = 0xffffffff;
LAB_00460260:
  serv_wtp_address_arg_destroy(&local_5c);
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  iVar1 = serv_wtp_address_arg_init(&local_5c);
  if (iVar1 == -1) {
    iVar1 = 0;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0046029c;
    pcVar4 = "\x1b[31;49m[%s]<%s():%d> Failed to serv_wtp_address_arg_init()!\x1b[0m\r\n";
    uVar6 = 0x2de;
LAB_0046067c:
    printf(pcVar4,"dhcp_defend","_uac_dhcpdef_notify_ap",uVar6);
    goto LAB_0046029c;
  }
  apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&local_5c,1,1,0x15f0000,1,0x1e);
  if (local_54 == 0) {
    iVar1 = 0;
    if ((g_dhcpdef_info == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      uVar7 = 0;
    }
    else {
      printf("[%s]<%s():%d> <-------------Num of APs is 0, no need to send packet.\r\n",
             "dhcp_defend","_uac_dhcpdef_notify_ap",0x2e6);
      uVar7 = 0;
    }
    goto LAB_0046029c;
  }
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> Num of APs to be notified: %d.\r\n","dhcp_defend","_uac_dhcpdef_notify_ap"
           ,0x2ed,local_54);
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0046029c;
    pcVar4 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
    uVar6 = 0x2f2;
    goto LAB_0046067c;
  }
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = (void *)0x0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
      pcVar5 = "_uac_dhcpv6def_packet_create";
      uVar7 = 0x25f;
      goto LAB_004604b8;
    }
  }
  else {
    FUN_0051ad88(&local_30);
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpv6def_packet_set_priv_msg_ele",
             0x1e6,"_uac_dhcpv6def_packet_set_priv_msg_ele");
    }
    iVar3 = dhcpdef_db_apbind_entry_shallow_get(param_1,&local_4c);
    if (iVar3 == 0) {
      local_68._1_3_ = CONCAT12(uVar8,local_68._2_2_);
      local_64 = 0;
      local_68 = CONCAT13(local_44._0_1_,local_68._1_3_);
      local_60 = (void *)0x0;
      if (param_2 == 1) {
        iVar3 = CONCAT31(local_44._1_3_,local_40._0_1_);
        if (iVar3 < 1) {
          local_68 = (uint)local_68._1_3_;
          goto LAB_00460454;
        }
        local_68 = CONCAT13(uVar8,local_68._1_3_);
        local_64 = iVar3;
        local_60 = (void *)FUN_00408450(iVar3 * 0x11,0x1f9);
        if (local_60 == (void *)0x0) {
          if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar4 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
            pcVar5 = "_uac_dhcpv6def_packet_set_priv_msg_ele";
            uVar7 = 0x1fc;
            goto LAB_004604b8;
          }
          goto LAB_004604c4;
        }
        memset(local_60,0,local_64 * 0x11);
        dhcpdef_db_ap_all_bindsvr_foreach
                  (param_1,_uac_dhcpv6def_packet_bind_svr_get,local_60,&local_64);
        if (local_64 == 0) {
          FUN_00407df0(local_60);
          goto LAB_00460454;
        }
      }
      else {
LAB_00460454:
        local_60 = (void *)0x0;
      }
      iVar3 = cw_service_msg_add(iVar2,0x25,&local_38,1,0x61,&local_68);
      if (iVar3 == 0) {
        iVar3 = capwap_packet_assemble(iVar1,iVar2);
        if (iVar3 != -1) {
          if (local_60 != (void *)0x0) {
            FUN_00407df0();
          }
          cw_parsed_pkt_destroy(iVar2);
          iVar2 = serv_packet_send(&local_5c,iVar1,1);
          if (iVar2 == 0) {
            uVar7 = 0;
            if ((g_dhcpdef_info == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_0046029c;
            pcVar4 = "[%s]<%s():%d> <-------------succeed to send dhcpv6 packet to ap_id[%d].\r\n";
            uVar6 = 0x301;
          }
          else {
            uVar7 = 0;
            if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_0046029c;
            pcVar4 = "\x1b[31;49m[%s]<%s():%d> Failed to send packt to ap_id[%d]!\x1b[0m\r\n";
            uVar6 = 0x2fd;
          }
          goto LAB_004607c8;
        }
        if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar4 = "\x1b[31;49m[%s]<%s():%d> capwap_packet_assemble() fail!\x1b[0m\r\n";
          pcVar5 = "_uac_dhcpv6def_packet_create";
          uVar7 = 0x27a;
          goto LAB_004604b8;
        }
      }
      else if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> cw_service_msg_add() fail!\x1b[0m\r\n";
        pcVar5 = "_uac_dhcpv6def_packet_create";
        uVar7 = 0x273;
LAB_004604b8:
        printf(pcVar4,"dhcp_defend",pcVar5,uVar7);
      }
    }
  }
LAB_004604c4:
  if (local_60 != (void *)0x0) {
    FUN_00407df0();
  }
  if (iVar2 == 0) {
    uVar7 = 0xffffffff;
  }
  else {
    cw_parsed_pkt_destroy(iVar2);
    uVar7 = 0xffffffff;
  }
LAB_0046029c:
  serv_wtp_address_arg_destroy(&local_5c);
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  return uVar7;
}

