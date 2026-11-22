// func arp_defend_wtp_pkt_send @ 0047762c size=3108

undefined4 arp_defend_wtp_pkt_send(undefined2 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  undefined4 local_328;
  int local_324;
  void *local_320;
  undefined4 local_31c;
  undefined4 local_318;
  int local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined1 auStack_2f8 [12];
  int local_2ec;
  
  memset(auStack_2f8,0,0x2d8);
  local_31c = 0;
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar8 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d inputs error.\n";
    uVar7 = 0x2dd;
    goto LAB_0047770c;
  }
  uVar8 = 0xffffffff;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f8);
  if (iVar1 == -1) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d apmngr_db_entry_get_by_id() failed.\n";
    uVar7 = 0x2e3;
    goto LAB_0047770c;
  }
  if (local_2ec == 0) {
    uVar8 = 0;
    if (arp_defend_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar5 = "[ARP_DEFEND_DEBUG]%s()/%d template do not need to send pkt.\n";
    uVar7 = 0x2e9;
    goto LAB_0047770c;
  }
  iVar1 = serv_wtp_address_arg_init(&local_31c);
  if (iVar1 == -1) {
    uVar8 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d init serv argv failed.\n";
    uVar7 = 0x2f0;
    goto LAB_0047770c;
  }
  apmngr_db_get_addr_by_capacity(param_1,&local_31c,1,1,0x15f0000,1,0x10);
  uVar9 = (undefined1)param_3;
  if (local_314 == 0) {
    if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar5 = "[ARP_DEFEND_DEBUG]%s()/%d no wtp need send arp_defend pakcet.\n";
      pcVar6 = "arp_defend_wtp_pkt_send";
      uVar8 = 0x2fa;
LAB_004778c4:
      printf(pcVar5,pcVar6,uVar8);
    }
LAB_00477800:
    serv_wtp_address_arg_destroy(&local_31c);
    iVar1 = serv_wtp_address_arg_init(&local_31c);
    if (iVar1 == -1) {
      uVar8 = 0xffffffff;
      if (arp_defend_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d init serv argv failed.\n";
      uVar7 = 0x30d;
LAB_0047770c:
      printf(pcVar5,"arp_defend_wtp_pkt_send",uVar7);
      return uVar8;
    }
    apmngr_db_get_addr_by_capacity(param_1,&local_31c,1,1,0x15f0000,1,0x1f);
    if (local_314 == 0) {
      if ((arp_defend_debug_switch == 0) || (iVar1 = is_target_debug_ap(&local_31c), iVar1 == 0))
      goto LAB_00477860;
      pcVar5 = "[ARP_DEFEND_DEBUG]%s()/%d no wtp need send arp_defend pakcet.\n";
      pcVar6 = "arp_defend_wtp_pkt_send";
      uVar8 = 0x317;
LAB_00477a38:
      printf(pcVar5,pcVar6,uVar8);
LAB_00477860:
      serv_wtp_address_arg_destroy(&local_31c);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 == 0) {
      if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d cw_pkt_buf_create() failed.\n","nd_defend_packet_send",
               0x20e);
      }
    }
    else {
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 == 0) {
        if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d no memory\n","nd_defend_packet_create",0x1a9);
        }
LAB_00477ca0:
        if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_packet_create() failed.\n";
          uVar8 = 0x215;
LAB_00477ccc:
          printf(pcVar5,"nd_defend_packet_send",uVar8);
        }
      }
      else {
        local_328 = 0;
        local_324 = 0;
        local_320 = (void *)0x0;
        local_30c = 0;
        local_308 = 0;
        local_304 = 0;
        local_300 = 0;
        local_2fc = 0;
        FUN_0051ad88(&local_304);
        local_324 = param_2[2];
        local_328._1_3_ = CONCAT12(uVar9,local_328._2_2_);
        local_328 = CONCAT13(*(undefined1 *)(param_2 + 1),local_328._1_3_);
        if (local_324 == 0) {
          if (param_3 == 1) {
            local_328 = (uint)local_328._1_3_;
          }
LAB_00477ab4:
          iVar3 = cw_service_msg_add(iVar2,0x25,&local_30c,1,0x62,&local_328);
          if (iVar3 != 0) {
            if ((arp_defend_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar5 = 
              "[ARP_DEFEND_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n";
              uVar8 = 0x156;
LAB_00478158:
              printf(pcVar5,"nd_defend_ele_set_priv_bind_cfg",uVar8);
            }
            goto LAB_00477aec;
          }
          if (local_320 != (void *)0x0) {
            FUN_00407df0();
            local_320 = (void *)0x0;
          }
          if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d arp_defend_ele_set_priv_bind_cfg() OK.\n",
                   "nd_defend_ele_set_priv_bind_cfg",0x160);
          }
          arp_defend_pkt_dump(iVar2);
          iVar3 = capwap_packet_assemble(iVar1,iVar2);
          if (iVar3 != 0) {
            iVar3 = -1;
            if ((arp_defend_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
            goto LAB_00477b1c;
            pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend capwap_packet_assemble() failed.\n";
            uVar8 = 0x1b7;
            goto LAB_00477f14;
          }
          iVar3 = 0;
          if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d pkt_buf is null : %s\n","nd_defend_packet_create",
                   0x1bd,&DAT_00691368);
          }
        }
        else {
          if (param_3 != 1) goto LAB_00477ab4;
          local_328 = CONCAT13(uVar9,local_328._1_3_);
          local_320 = (void *)FUN_00408450(local_324 * 0x16,0x140);
          if (local_320 != (void *)0x0) {
            memset(local_320,0,param_2[2] * 0x16);
            arp_defend_db_ap_all_bindarp_foreach
                      (*param_2,arp_defend_packet_bind_nds_get,local_320,&local_324);
            goto LAB_00477ab4;
          }
          if ((arp_defend_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d no memory.\n";
            uVar8 = 0x143;
            goto LAB_00478158;
          }
LAB_00477aec:
          if (local_320 != (void *)0x0) {
            FUN_00407df0();
          }
          iVar3 = -1;
          if ((arp_defend_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_ele_set_priv_bind_cfg() failed.\n";
            uVar8 = 0x1af;
LAB_00477f14:
            iVar3 = -1;
            printf(pcVar5,"nd_defend_packet_create",uVar8);
          }
        }
LAB_00477b1c:
        cw_parsed_pkt_destroy(iVar2);
        if (iVar3 != 0) goto LAB_00477ca0;
        if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(&local_31c), iVar2 != 0))
        {
          printf("[ARP_DEFEND_DEBUG]%s()/%d send configure to ap, pkt_buf->len:%d\n",
                 "nd_defend_packet_send",0x219,(uint)*(ushort *)(iVar1 + 4));
        }
        iVar2 = serv_packet_send(&local_31c,iVar1,1);
        if (iVar2 == 0) {
          if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d serv_packet_send() done.\n","nd_defend_packet_send",
                   0x221);
          }
          cw_pkt_buf_destroy(iVar1);
          if ((arp_defend_debug_switch == 0) || (iVar1 = is_target_debug_ap(&local_31c), iVar1 == 0)
             ) goto LAB_00477860;
          pcVar5 = "[ARP_DEFEND_DEBUG]%s()/%d cw_pkt_buf_destroy() done.\n";
          pcVar6 = "nd_defend_packet_send";
          uVar8 = 0x225;
          goto LAB_00477a38;
        }
        if ((arp_defend_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar5 = "[ARP_DEFEND_WARNING]%s()/%d serv_packet_send() failed.\n";
          uVar8 = 0x21d;
          goto LAB_00477ccc;
        }
      }
      cw_pkt_buf_destroy(iVar1);
    }
    if ((arp_defend_warning_switch == 0) || (iVar1 = is_target_debug_ap(&local_31c), iVar1 == 0))
    goto LAB_00477a04;
    uVar8 = 799;
  }
  else {
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 == 0) {
      if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d cw_pkt_buf_create() failed.\n","arp_defend_packet_send",
               0x1d9);
      }
    }
    else {
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 == 0) {
        if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d no memory\n","arp_defend_packet_create",0x17c);
        }
LAB_00477be8:
        if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_packet_create() failed.\n";
          uVar8 = 0x1e0;
LAB_00477c14:
          printf(pcVar5,"arp_defend_packet_send",uVar8);
        }
      }
      else {
        local_328 = 0;
        local_324 = 0;
        local_320 = (void *)0x0;
        local_30c = 0;
        local_308 = 0;
        local_304 = 0;
        local_300 = 0;
        local_2fc = 0;
        FUN_0051ad88(&local_304);
        local_328._1_3_ = CONCAT12(uVar9,local_328._2_2_);
        local_328 = CONCAT13(*(undefined1 *)(param_2 + 1),local_328._1_3_);
        local_324 = param_2[2];
        if (local_324 == 0) {
          if (param_3 == 1) {
            local_328 = (uint)local_328._1_3_;
          }
LAB_00477940:
          iVar3 = cw_service_msg_add(iVar2,0x25,&local_30c,1,0x48,&local_328);
          if (iVar3 != 0) {
            if ((arp_defend_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar5 = 
              "[ARP_DEFEND_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n";
              uVar8 = 0x112;
LAB_00478090:
              printf(pcVar5,"arp_defend_ele_set_priv_bind_cfg",uVar8);
            }
            goto LAB_00477978;
          }
          if (local_320 != (void *)0x0) {
            FUN_00407df0();
            local_320 = (void *)0x0;
          }
          if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d arp_defend_ele_set_priv_bind_cfg() OK.\n",
                   "arp_defend_ele_set_priv_bind_cfg",0x11c);
          }
          arp_defend_pkt_dump(iVar2);
          iVar3 = capwap_packet_assemble(iVar1,iVar2);
          if (iVar3 != 0) {
            iVar3 = -1;
            if ((arp_defend_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
            goto LAB_004779a8;
            pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend capwap_packet_assemble() failed.\n";
            uVar8 = 0x18a;
            goto LAB_00477dc8;
          }
          iVar3 = 0;
          if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d pkt_buf is null : %s\n","arp_defend_packet_create",400
                   ,&DAT_00691368);
          }
        }
        else {
          if (param_3 != 1) goto LAB_00477940;
          local_328 = CONCAT13(uVar9,local_328._1_3_);
          local_320 = (void *)FUN_00408450(local_324 * 0xc,0xfc);
          if (local_320 != (void *)0x0) {
            memset(local_320,0,param_2[2] * 0xc);
            arp_defend_db_ap_all_bindarp_foreach
                      (*param_2,arp_defend_packet_bind_arps_get,local_320,&local_324);
            goto LAB_00477940;
          }
          if ((arp_defend_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d no memory.\n";
            uVar8 = 0xff;
            goto LAB_00478090;
          }
LAB_00477978:
          if (local_320 != (void *)0x0) {
            FUN_00407df0();
          }
          iVar3 = -1;
          if ((arp_defend_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_ele_set_priv_bind_cfg() failed.\n";
            uVar8 = 0x182;
LAB_00477dc8:
            iVar3 = -1;
            printf(pcVar5,"arp_defend_packet_create",uVar8);
          }
        }
LAB_004779a8:
        cw_parsed_pkt_destroy(iVar2);
        if (iVar3 != 0) goto LAB_00477be8;
        if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(&local_31c), iVar2 != 0))
        {
          printf("[ARP_DEFEND_DEBUG]%s()/%d send configure to ap, pkt_buf->len:%d\n",
                 "arp_defend_packet_send",0x1e4,(uint)*(ushort *)(iVar1 + 4));
        }
        iVar2 = serv_packet_send(&local_31c,iVar1,1);
        if (iVar2 == 0) {
          if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d serv_packet_send() done.\n","arp_defend_packet_send",
                   0x1ec);
          }
          cw_pkt_buf_destroy(iVar1);
          if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar5 = "[ARP_DEFEND_DEBUG]%s()/%d cw_pkt_buf_destroy() done.\n";
            pcVar6 = "arp_defend_packet_send";
            uVar8 = 0x1f0;
            goto LAB_004778c4;
          }
          goto LAB_00477800;
        }
        if ((arp_defend_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar5 = "[ARP_DEFEND_WARNING]%s()/%d serv_packet_send() failed.\n";
          uVar8 = 0x1e8;
          goto LAB_00477c14;
        }
      }
      cw_pkt_buf_destroy(iVar1);
    }
    if ((arp_defend_warning_switch == 0) || (iVar1 = is_target_debug_ap(&local_31c), iVar1 == 0))
    goto LAB_00477a04;
    uVar8 = 0x302;
  }
  printf("[ARP_DEFEND_WARNING]%s()/%d arp_defend_packet_send() failed.\n","arp_defend_wtp_pkt_send",
         uVar8);
LAB_00477a04:
  serv_wtp_address_arg_destroy(&local_31c);
  return 0xffffffff;
}

