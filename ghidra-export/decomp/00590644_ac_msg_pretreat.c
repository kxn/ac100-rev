// func ac_msg_pretreat @ 00590644 size=1812

undefined4 ac_msg_pretreat(int param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  char *__format;
  undefined4 uVar7;
  void *__src;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [64];
  
  local_68 = 0;
  local_64 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 != 0) {
      printf("[CW_ERROR]%32s():%4d input parameter is null\n","ac_msg_pretreat",0xc0);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  *param_3 = 0;
  iVar2 = cw_parsed_pkt_init();
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 != 0) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","ac_msg_pretreat",199);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  puVar3 = (undefined4 *)cw_pkt_buf_create(0xfa);
  if (puVar3 == (undefined4 *)0x0) {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005906d4;
    __format = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar7 = 0xce;
  }
  else {
    iVar4 = (**(code **)(param_2 + 0x94))(param_2 + 0x2c,puVar3);
    if (iVar4 == -1) {
      if ((capwap_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
      goto LAB_005906d4;
      __format = "[CW_WARNING]%32s():%4d try to decrypt packet failed\n";
      uVar7 = 0xd5;
    }
    else {
      iVar4 = cw_header_parse(puVar3,iVar2);
      if (iVar4 == -1) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_005906d4;
        __format = "[CW_ERROR]%32s():%4d parse header failed\n";
        uVar7 = 0xdc;
      }
      else if (*(char *)(iVar2 + 6) == '\x01') {
        *(undefined2 *)((int)puVar3 + 6) = 0;
        iVar4 = (**(code **)(*(int *)(param_2 + 0xac) + 0x28))(*(int *)(param_2 + 0xac),puVar3);
        if (iVar4 == 0) {
          if ((capwap_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[CW_DEBUG]%32s():%4d still need more frag packet\n","ac_msg_pretreat",0xec);
          }
          cw_pkt_buf_destroy(puVar3);
          cw_parsed_pkt_destroy(iVar2);
          return 0;
        }
        if (iVar4 == 1) {
          if ((capwap_debug_switch != 0) && (iVar4 = is_target_debug_ap(puVar3), iVar4 != 0)) {
            printf("[CW_DEBUG]%32s():%4d receive a complete packet\n","ac_msg_pretreat",0xf2);
          }
          iVar4 = cw_header_parse(puVar3,iVar2);
          if (iVar4 != -1) {
            cVar1 = *(char *)(iVar2 + 6);
            goto LAB_005907fc;
          }
          if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005906d4;
          __format = "[CW_ERROR]%32s():%4d parse reassemble packet header failed\n";
          uVar7 = 0xf5;
        }
        else if (iVar4 == -1) {
          if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005906d4;
          __format = "[CW_ERROR]%32s():%4d packet reassembled failed\n";
          uVar7 = 0xe8;
        }
        else {
          if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005906d4;
          __format = "[CW_ERROR]%32s():%4d wrong reassemble result\n";
          uVar7 = 0xfa;
        }
      }
      else {
        cVar1 = *(char *)(iVar2 + 6);
LAB_005907fc:
        if (cVar1 == '\x01') {
          iVar4 = puVar3[8];
        }
        else {
          iVar4 = puVar3[7] - puVar3[5];
        }
        *(int *)(iVar2 + 0x30) = iVar4;
        uVar7 = puVar3[5];
        *(undefined4 *)(iVar2 + 0x28) = puVar3[4];
        *(undefined4 *)(iVar2 + 0x2c) = uVar7;
        if ((((capwap_buffer_switch != 0) || (capwap_recv_buffer_switch != 0)) &&
            ((debug_ip == 0 ||
             ((*(char *)(param_2 + 0x2c) == '\x01' && (debug_ip == *(int *)(param_2 + 0x30))))))) &&
           ((debug_port == 0 || (*(short *)(param_2 + 0x40) == debug_port)))) {
          uVar7 = cw_control_header_msg_type_get(*puVar3);
          iVar4 = ac_packet_debug_is_open(uVar7);
          if (iVar4 != 0) {
            memset(auStack_60,0,0x40);
            FUN_00408190(*(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_2 + 0x30),
                         *(undefined4 *)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
                         *(undefined4 *)(param_2 + 0x3c),auStack_60,0x40,"---");
            printf("receive packet from AP[%s/%d]:\n",auStack_60,(uint)*(ushort *)(param_2 + 0x40));
            cw_pkt_buf_dump(puVar3);
          }
        }
        iVar4 = cw_control_header_parse(puVar3,iVar2 + 0x10);
        if (iVar4 == -1) {
          if ((capwap_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005906d4;
          __format = "[CW_WARNING]%32s():%4d parse control header failed\n";
          uVar7 = 0x11a;
        }
        else {
          iVar4 = ac_packet_is_request(iVar2);
          if (((iVar4 != 0) && (iVar4 = (int)*(short *)(param_2 + 0xa6), iVar4 != -1)) &&
             (((uVar6 = (uint)*(byte *)(iVar2 + 0x14), iVar4 < (int)uVar6 &&
               (0x80 < (int)(uVar6 - iVar4))) ||
              (((int)uVar6 < iVar4 && ((int)(iVar4 - uVar6) < 0x80)))))) {
            if ((capwap_warning_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[CW_WARNING]%32s():%4d illegal request sequence id[%d:%d]\n","ac_msg_pretreat"
                     ,0x124,(uint)*(byte *)(iVar2 + 0x14),(int)*(short *)(param_2 + 0xa6));
            }
            iVar4 = is_store_snapshot();
            if (iVar4 != 0) {
              __src = (void *)(param_2 + 0x14);
              if (*(int *)(param_2 + 0x10) == 0) {
                __src = (void *)get_mac(iVar2);
              }
              iVar4 = create_new_pkt_snapshot(1,param_1);
              get_pkt_info(iVar4,iVar2);
              if ((iVar4 != 0) && (__src != (void *)0x0)) {
                if (*(undefined1 **)(iVar4 + 0x54) != (undefined1 *)0x0) {
                  **(undefined1 **)(iVar4 + 0x54) = 1;
                  *(undefined1 *)(*(int *)(iVar4 + 0x54) + 1) = 0;
                  *(undefined1 *)(*(int *)(iVar4 + 0x54) + 2) = 0;
                  *(undefined4 *)(*(int *)(iVar4 + 0x54) + 4) = *(undefined4 *)(iVar2 + 0x30);
                  *(undefined4 *)(*(int *)(iVar4 + 0x54) + 8) = 0;
                  *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0xc) = 0;
                }
                uVar7 = *(undefined4 *)(iVar2 + 0x28);
                *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar2 + 0x2c);
                *(undefined4 *)(iVar4 + 0x10) = uVar7;
                memcpy((void *)(iVar4 + 0x2c),__src,6);
              }
            }
            goto LAB_005906d4;
          }
          local_68 = 1;
          local_64 = *(undefined4 *)(iVar2 + 0x10);
          iVar4 = cw_fsm_ac_process_event(param_2,&local_68);
          if (iVar4 != 0) {
            if ((capwap_warning_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              uVar7 = cw_fsm_get_state_name(*(undefined4 *)(param_2 + 0xb4));
              uVar5 = cw_control_msg_name(*(undefined4 *)(iVar2 + 0x10));
              printf("[CW_WARNING]%32s():%4d state:%s   packet type:%s\n","ac_msg_pretreat",0x13d,
                     uVar7,uVar5);
            }
            goto LAB_005906d4;
          }
          iVar4 = (*(code *)**(undefined4 **)(param_2 + 0xb0))(puVar3,iVar2,1,1,param_2 + 0xdc);
          if (iVar4 != -1) {
            *param_3 = iVar2;
            cw_pkt_buf_destroy(puVar3);
            return 0;
          }
          if ((capwap_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005906d4;
          __format = "[CW_WARNING]%32s():%4d parse message element failed\n";
          uVar7 = 0x144;
        }
      }
    }
  }
  printf(__format,"ac_msg_pretreat",uVar7);
LAB_005906d4:
  cw_parsed_pkt_destroy(iVar2);
  if (puVar3 != (undefined4 *)0x0) {
    cw_pkt_buf_destroy(puVar3);
  }
  return 0xffffffff;
}

