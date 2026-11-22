// func _tdcp_send_pkt_to_ap @ 00510c10 size=1352

undefined4
_tdcp_send_pkt_to_ap
          (uint param_1,int param_2,char *param_3,undefined4 param_4,ushort param_5,int param_6)

{
  int iVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint local_68 [2];
  size_t local_60;
  void *local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_30 = param_4;
  iVar1 = serv_wtp_address_arg_init(&local_58);
  if (iVar1 == -1) {
    if (tdcp_err_switch != 0) {
      printf("[TDCP_ERROR]%s()/%d Failed to serv_wtp_address_arg_init()!\n","_tdcp_send_pkt_to_ap",
             0x248);
    }
    serv_wtp_address_arg_destroy(&local_58);
    return 0xffffffff;
  }
  if (param_6 == 0) {
    iVar1 = apmngr_db_get_addr_by_capacity((uint)param_5,&local_58,1,1,0x15f0000,1,0x4b);
    if (iVar1 == 0) goto LAB_00510d68;
    if (tdcp_err_switch != 0) {
      uVar6 = 0x25a;
      goto LAB_00510e74;
    }
  }
  else {
    iVar1 = apmngr_db_get_all_addr_by_capacity(&local_58,1,1,0x15f0000,1,0x4b);
    if (iVar1 == 0) {
LAB_00510d68:
      if (local_50 == 0) {
        if (tdcp_debug_switch == 0) {
          iVar1 = 0;
          uVar6 = 0;
        }
        else {
          iVar1 = 0;
          printf("[TDCP_DEBUG]%s()/%d <-------------Num of APs is 0, no need to send packet.\n",
                 "_tdcp_send_pkt_to_ap",0x263);
          uVar6 = 0;
        }
        goto LAB_00510cc4;
      }
      if (tdcp_debug_switch != 0) {
        printf("[TDCP_DEBUG]%s()/%d Num of APs to be notified: %d.\n","_tdcp_send_pkt_to_ap",0x26a);
      }
      iVar1 = cw_pkt_buf_create(0xfa);
      if (iVar1 == 0) {
        uVar6 = 0xffffffff;
        if (tdcp_err_switch != 0) {
          printf("[TDCP_ERROR]%s()/%d no memory!\n","_tdcp_send_pkt_to_ap",0x271);
        }
        goto LAB_00510cc4;
      }
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_68[0] = 0;
      local_68[1] = 0;
      local_60 = 0;
      local_5c = (void *)0x0;
      if (((param_1 < 2) && (-1 < param_2)) && (param_2 < 2)) {
        if (param_3 == (char *)0x0) {
          if (tdcp_err_switch != 0) {
            pcVar4 = "[TDCP_ERROR]%s()/%d inputs tdcp_data error.\n";
            uVar6 = 0xbf;
            goto LAB_00510e94;
          }
        }
        else {
          __n = strlen(param_3);
          iVar2 = cw_parsed_pkt_create(7);
          if (iVar2 == 0) {
            if (tdcp_err_switch != 0) {
              pcVar4 = "[TDCP_ERROR]%s()/%d malloc for CW_PARSED_PKT failed.\n";
              uVar6 = 0xce;
              goto LAB_00510e94;
            }
          }
          else {
            local_48 = 0x12345678;
            local_44 = CONCAT22(0xa5,local_44._2_2_);
            FUN_0051ad88(&local_40);
            local_68[0] = 0;
            local_68[1] = 0;
            local_60 = 0;
            local_5c = (void *)0x0;
            local_5c = (void *)FUN_00408450(__n + 1,0xd7);
            if (local_5c == (void *)0x0) {
              if (tdcp_err_switch != 0) {
                pcVar4 = "[TDCP_ERROR]%s()/%d malloc  failed.\n";
                uVar6 = 0xd9;
LAB_00511044:
                printf(pcVar4,"_tdcp_pkt_create",uVar6);
              }
            }
            else {
              local_68[0] = CONCAT22((short)(CONCAT13((char)local_30,
                                                      CONCAT12((char)param_2,(short)param_1)) >>
                                            0x10),(short)param_1) & 0xffff00ff;
              local_68[1] = 0;
              local_60 = __n;
              memset(local_5c,0,__n + 1);
              memcpy(local_5c,param_3,__n);
              iVar3 = cw_service_msg_add(iVar2,0x25,&local_48,1,0xa5,local_68);
              if (iVar3 == 0) {
                iVar3 = capwap_packet_assemble(iVar1,iVar2);
                if (iVar3 == 0) {
                  if (tdcp_debug_switch != 0) {
                    printf("[TDCP_DEBUG]%s()/%d create parsed_pkt success.\n","_tdcp_pkt_create",
                           0xf6);
                  }
                  cw_parsed_pkt_destroy(iVar2);
                  if (local_5c != (void *)0x0) {
                    FUN_00407df0();
                  }
                  iVar2 = serv_packet_send(&local_58,iVar1,1);
                  if (iVar2 == 0) {
                    uVar6 = 0;
                    if (tdcp_debug_switch == 0) goto LAB_00510cc4;
                    pcVar4 = 
                    "[TDCP_DEBUG]%s()/%d <-------------succeed to send packet to ap_id[%d].\n";
                    uVar5 = 0x282;
                  }
                  else {
                    uVar6 = 0;
                    if (tdcp_err_switch == 0) goto LAB_00510cc4;
                    pcVar4 = "[TDCP_ERROR]%s()/%d Failed to send packt to ap_id[%d]!\n";
                    uVar5 = 0x27e;
                  }
                  uVar6 = 0;
                  printf(pcVar4,"_tdcp_send_pkt_to_ap",uVar5,(uint)param_5);
                  goto LAB_00510cc4;
                }
                if (tdcp_err_switch != 0) {
                  pcVar4 = "[TDCP_ERROR]%s()/%d assemble packet buffer failed.\n";
                  uVar6 = 0xf3;
                  goto LAB_00511044;
                }
              }
              else if (tdcp_err_switch != 0) {
                printf("[TDCP_ERROR]%s()/%d add msg element failed ret:%d.\n","_tdcp_pkt_create",
                       0xec,iVar3);
              }
            }
            cw_parsed_pkt_destroy(iVar2);
          }
        }
      }
      else if (tdcp_err_switch != 0) {
        pcVar4 = "[TDCP_ERROR]%s()/%d input para error\n";
        uVar6 = 0xb9;
LAB_00510e94:
        printf(pcVar4,"_tdcp_pkt_create",uVar6);
      }
      uVar6 = 0xffffffff;
      if (local_5c != (void *)0x0) {
        FUN_00407df0();
      }
      goto LAB_00510cc4;
    }
    if (tdcp_err_switch != 0) {
      uVar6 = 0x252;
LAB_00510e74:
      iVar1 = 0;
      printf("[TDCP_ERROR]%s()/%d error .\n","_tdcp_send_pkt_to_ap",uVar6);
      uVar6 = 0xffffffff;
      goto LAB_00510cc4;
    }
  }
  iVar1 = 0;
  uVar6 = 0xffffffff;
LAB_00510cc4:
  serv_wtp_address_arg_destroy(&local_58);
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  return uVar6;
}

