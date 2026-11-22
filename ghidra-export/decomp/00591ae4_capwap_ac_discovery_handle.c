// func capwap_ac_discovery_handle @ 00591ae4 size=2460

undefined4 capwap_ac_discovery_handle(int param_1,undefined4 *param_2,char *param_3,char *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *__src;
  undefined4 uVar6;
  int extraout_v1;
  int extraout_v1_00;
  int extraout_v1_01;
  char *pcVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 auStack_b0 [16];
  undefined1 auStack_a0 [36];
  undefined1 auStack_7c [68];
  int local_38;
  int local_34;
  int local_30;
  
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  if (param_1 == 0) {
    uVar8 = 0x5e9;
    pcVar7 = "NULL != data";
LAB_00592410:
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_ac_discovery_handle",uVar8,pcVar7);
    return 0xffffffff;
  }
  if (param_3 == (char *)0x0) {
    uVar8 = 0x5ea;
    pcVar7 = "NULL != ip_port";
    goto LAB_00592410;
  }
  if (param_4 == (char *)0x0) {
    uVar8 = 0x5eb;
    pcVar7 = "NULL != eth_ip_port";
    goto LAB_00592410;
  }
  cw_header_flag_f_get(*param_2);
  iVar1 = cw_parsed_pkt_init();
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","capwap_ac_discovery_handle",0x5f5);
    return 0xffffffff;
  }
  piVar2 = (int *)cw_pkt_buf_create(0xcc00);
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
    if (capwap_err_switch == 0) goto LAB_00591d60;
    iVar4 = is_target_debug_ap();
    iVar3 = 0;
    if (iVar4 == 0) goto LAB_00591d60;
    pcVar7 = "[CW_ERROR]%32s():%4d malloc failed.\n";
    uVar8 = 0x5fc;
  }
  else {
    iVar3 = capwap_packet_parse(param_2,iVar1,0,0,&local_c0);
    if (iVar3 == -1) {
      iVar3 = 0;
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00591d60;
      pcVar7 = "[CW_ERROR]%32s():%4d failed to parse packet\n";
      uVar8 = 0x603;
    }
    else {
      if ((((capwap_buffer_switch != 0) || (capwap_recv_buffer_switch != 0)) &&
          ((debug_ip == 0 || ((*param_3 == '\x01' && (debug_ip == *(int *)(param_3 + 4))))))) &&
         ((debug_port == 0 || (*(short *)(param_3 + 0x14) == debug_port)))) {
        uVar8 = cw_control_header_msg_type_get(*param_2);
        iVar3 = ac_packet_debug_is_open(uVar8);
        if (iVar3 != 0) {
          memset(auStack_7c,0,0x40);
          FUN_00408190(*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),
                       *(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),
                       *(undefined4 *)(param_3 + 0x10),auStack_7c,0x40,"---");
          printf("receive packet from AP[%s/%d]:\n",auStack_7c,(uint)*(ushort *)(param_3 + 0x14));
          cw_pkt_buf_dump(param_2);
        }
      }
      if ((((capwap_packet_switch != 0) || (capwap_recv_packet_switch != 0)) &&
          ((debug_ip == 0 || ((*param_3 == '\x01' && (debug_ip == *(int *)(param_3 + 4))))))) &&
         ((debug_port == 0 || (*(short *)(param_3 + 0x14) == debug_port)))) {
        iVar3 = ac_packet_debug_is_open(*(undefined4 *)(iVar1 + 0x10));
        if (iVar3 != 0) {
          memset(auStack_7c,0,0x40);
          FUN_00408190(*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),
                       *(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),
                       *(undefined4 *)(param_3 + 0x10),auStack_7c,0x40,"---");
          printf("receive packet from AP[%s/%d]:\n",auStack_7c,(uint)*(ushort *)(param_3 + 0x14));
          capwap_parsed_packet_dump(iVar1);
        }
      }
      iVar3 = ac_parsed_packet_create(iVar1);
      if (iVar3 != 0) {
        memset(auStack_b0,0,0x34);
        memcpy(auStack_a0,param_3,0x14);
        FUN_00524078();
        local_38 = extraout_v1;
        iVar4 = serv_mngr_handle(iVar1,auStack_b0,iVar3);
        if (iVar4 == -1) {
          if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_005923ac;
          pcVar7 = "[CW_ERROR]%32s():%4d service manager handled the packet failed\n";
          uVar8 = 0x634;
        }
        else {
          FUN_00524078();
          local_34 = extraout_v1_00;
          iVar4 = cw_msg_eles_length_update(iVar3);
          if (iVar4 != -1) {
            piVar5 = (int *)cw_msg_ele_val_get(iVar3,0x21);
            if ((piVar5 == (int *)0x0) || ((*piVar5 != 0x17 && (*piVar5 != 1)))) {
              iVar4 = capwap_packet_assemble(piVar2,iVar3);
              if (iVar4 == -1) {
                if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                goto LAB_00591d60;
                pcVar7 = "[CW_ERROR]%32s():%4d failed to assemble packet\n";
                uVar8 = 0x64e;
              }
              else if (*param_4 == '\x01') {
                iVar4 = capwap_plain_packet_send
                                  (*(undefined4 *)(param_1 + 0x10),param_4,param_3,*piVar2,
                                   *(undefined2 *)(piVar2 + 1));
                if (-1 < iVar4) {
LAB_00591cc0:
                  iVar4 = is_store_snapshot();
                  if (iVar4 != 0) {
                    __src = (void *)get_mac(iVar1);
                    FUN_00524078();
                    local_30 = param_2[5];
                    iVar4 = create_new_pkt_snapshot(1,param_1);
                    get_pkt_info(iVar4,iVar1);
                    if ((iVar4 != 0) && (__src != (void *)0x0)) {
                      if (*(undefined1 **)(iVar4 + 0x54) == (undefined1 *)0x0) {
                        uVar8 = param_2[5];
                      }
                      else {
                        **(undefined1 **)(iVar4 + 0x54) = 0;
                        *(undefined1 *)(*(int *)(iVar4 + 0x54) + 1) = 0;
                        *(undefined1 *)(*(int *)(iVar4 + 0x54) + 2) = 0;
                        *(undefined4 *)(*(int *)(iVar4 + 0x54) + 4) = param_2[7] - param_2[5];
                        *(int *)(*(int *)(iVar4 + 0x54) + 8) = local_34 - local_38;
                        *(int *)(*(int *)(iVar4 + 0x54) + 0xc) = extraout_v1_01 - local_30;
                        uVar8 = param_2[5];
                      }
                      uVar6 = param_2[4];
                      *(undefined4 *)(iVar4 + 0x14) = uVar8;
                      *(undefined4 *)(iVar4 + 0x10) = uVar6;
                      memcpy((void *)(iVar4 + 0x2c),__src,6);
                    }
                    iVar4 = create_new_pkt_snapshot(4,param_1);
                    get_pkt_info(iVar4,iVar3);
                    if ((iVar4 != 0) && (__src != (void *)0x0)) {
                      if (*(undefined4 **)(iVar4 + 0x58) != (undefined4 *)0x0) {
                        **(undefined4 **)(iVar4 + 0x58) = 0;
                        *(undefined1 *)(*(int *)(iVar4 + 0x58) + 4) = 0;
                        *(undefined4 *)(*(int *)(iVar4 + 0x58) + 8) = 0;
                      }
                      uVar9 = FUN_00524078();
                      *(undefined8 *)(iVar4 + 0x10) = uVar9;
                      memcpy((void *)(iVar4 + 0x2c),__src,6);
                    }
                  }
                  if ((((capwap_buffer_switch != 0) || (capwap_send_buffer_switch != 0)) &&
                      ((debug_ip == 0 ||
                       ((*param_3 == '\x01' && (debug_ip == *(int *)(param_3 + 4))))))) &&
                     (((debug_port == 0 || (*(short *)(param_3 + 0x14) == debug_port)) &&
                      (iVar4 = ac_packet_debug_is_open(*(undefined4 *)(iVar3 + 0x10)), iVar4 != 0)))
                     ) {
                    memset(auStack_7c,0,0x40);
                    FUN_00408190(*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),
                                 *(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),
                                 *(undefined4 *)(param_3 + 0x10),auStack_7c,0x40,"---");
                    printf("send packet to AP[%s/%d]:\n",auStack_7c,
                           (uint)*(ushort *)(param_3 + 0x14));
                    cw_pkt_buf_dump(piVar2);
                  }
                  if ((((capwap_packet_switch != 0) || (capwap_send_packet_switch != 0)) &&
                      ((debug_ip == 0 ||
                       ((*param_3 == '\x01' && (debug_ip == *(int *)(param_3 + 4))))))) &&
                     ((debug_port == 0 || (*(short *)(param_3 + 0x14) == debug_port)))) {
                    iVar4 = ac_packet_debug_is_open(*(undefined4 *)(iVar3 + 0x10));
                    if (iVar4 != 0) {
                      memset(auStack_7c,0,0x40);
                      FUN_00408190(*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),
                                   *(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),
                                   *(undefined4 *)(param_3 + 0x10),auStack_7c,0x40,"---");
                      printf("send packet to AP[%s/%d]:\n",auStack_7c,
                             (uint)*(ushort *)(param_3 + 0x14));
                      capwap_parsed_packet_dump(iVar3);
                    }
                  }
                  cw_parsed_pkt_destroy(iVar3);
                  cw_parsed_pkt_destroy(iVar1);
                  cw_pkt_buf_destroy(piVar2);
                  return 0;
                }
                if ((capwap_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                goto LAB_00591d60;
                pcVar7 = "[CW_WARNING]%32s():%4d failed to send discovery response packet\n";
                uVar8 = 0x656;
              }
              else {
                if ((*param_4 != '\x02') ||
                   (iVar4 = capwap_plain_ipv6_packet_send
                                      (*(undefined4 *)(param_1 + 0x14),param_4,param_3,*piVar2,
                                       *(undefined2 *)(piVar2 + 1)), -1 < iVar4)) goto LAB_00591cc0;
                if ((capwap_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                goto LAB_00591d60;
                pcVar7 = "[CW_WARNING]%32s():%4d failed to send discovery response packet\n";
                uVar8 = 0x65f;
              }
            }
            else {
              if ((capwap_debug_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
              goto LAB_00591d60;
              pcVar7 = "[CW_DEBUG]%32s():%4d not need response discovery packet\n";
              uVar8 = 0x645;
            }
            goto LAB_00592068;
          }
          if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_005923ac;
          pcVar7 = "[CW_ERROR]%32s():%4d update packet\'s length failed\n";
          uVar8 = 0x63e;
        }
        printf(pcVar7,"capwap_ac_discovery_handle",uVar8);
LAB_005923ac:
        cw_parsed_pkt_destroy(iVar3);
        return 0xffffffff;
      }
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00591d60;
      pcVar7 = "[CW_ERROR]%32s():%4d failed to create response packet\n";
      uVar8 = 0x629;
    }
  }
LAB_00592068:
  printf(pcVar7,"capwap_ac_discovery_handle",uVar8);
LAB_00591d60:
  cw_parsed_pkt_destroy(iVar1);
  if (iVar3 != 0) {
    cw_parsed_pkt_destroy(iVar3);
  }
  if (piVar2 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*piVar2 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(piVar2);
  return 0xffffffff;
}

