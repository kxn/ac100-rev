// func ac_packet_buf_send @ 00590ed4 size=1224

undefined4 ac_packet_buf_send(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 auStack_90 [28];
  undefined1 auStack_74 [28];
  undefined1 auStack_58 [64];
  
  memset(auStack_90,0,0x38);
  if (param_1 == 0) {
    uVar5 = 0x1b4;
    pcVar6 = "NULL != session";
LAB_00591354:
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_packet_buf_send",uVar5,pcVar6);
    return 0xffffffff;
  }
  if (param_2 == (int *)0x0) {
    uVar5 = 0x1b5;
    pcVar6 = "NULL != pkt_buf";
    goto LAB_00591354;
  }
  if (*param_2 == 0) {
    uVar5 = 0x1b6;
    pcVar6 = "NULL != pkt_buf->buf";
    goto LAB_00591354;
  }
  if ((((capwap_buffer_switch != 0) || (capwap_send_buffer_switch != 0)) &&
      ((debug_ip == 0 ||
       ((*(char *)(param_1 + 0x2c) == '\x01' && (debug_ip == *(int *)(param_1 + 0x30))))))) &&
     ((debug_port == 0 || (*(short *)(param_1 + 0x40) == debug_port)))) {
    uVar5 = cw_control_header_msg_type_get();
    iVar1 = ac_packet_debug_is_open(uVar5);
    if (iVar1 != 0) {
      memset(auStack_58,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                   *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                   *(undefined4 *)(param_1 + 0x3c),auStack_58,0x40,"---");
      printf("send packet to AP[%s/%d]:\n",auStack_58,(uint)*(ushort *)(param_1 + 0x40));
      cw_pkt_buf_dump(param_2);
    }
  }
  if ((capwap_packet_switch == 0) && (capwap_send_packet_switch == 0)) {
    iVar1 = *(int *)(param_1 + 0xc);
    goto LAB_00590f88;
  }
  if (debug_ip != 0) {
    if (*(char *)(param_1 + 0x2c) != '\x01') {
      iVar1 = *(int *)(param_1 + 0xc);
      goto LAB_00590f88;
    }
    if (debug_ip != *(int *)(param_1 + 0x30)) {
      iVar1 = *(int *)(param_1 + 0xc);
      goto LAB_00590f88;
    }
  }
  if ((debug_port == 0) || (*(short *)(param_1 + 0x40) == debug_port)) {
    uVar5 = cw_control_header_msg_type_get(*param_2);
    iVar1 = ac_packet_debug_is_open(uVar5);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      memset(auStack_58,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                   *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                   *(undefined4 *)(param_1 + 0x3c),auStack_58,0x40,"---");
      printf("send packet to AP[%s/%d]:\n",auStack_58,(uint)*(ushort *)(param_1 + 0x40));
      FUN_0051ad88(auStack_74);
      *(undefined2 *)((int)param_2 + 6) = 0;
      capwap_packet_parse(param_2,auStack_90,0,0,param_1 + 0xdc);
      *(undefined2 *)((int)param_2 + 6) = 0;
      capwap_parsed_packet_dump(auStack_90);
      capwap_parsed_packet_free(auStack_90);
      iVar1 = *(int *)(param_1 + 0xc);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
  }
LAB_00590f88:
  if (*(int *)(iVar1 + 8) == 0) {
    iVar1 = (**(code **)(param_1 + 0x90))(param_1 + 0x2c,param_2);
    if (iVar1 != -1) {
      return 0;
    }
    if (capwap_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[CW_WARNING]%32s():%4d packet send failed\n";
    uVar5 = 0x208;
  }
  else {
    piVar4 = *(int **)(param_1 + 0xac);
    if (*piVar4 < (int)(uint)*(ushort *)(param_2 + 1)) {
      iVar1 = (*(code *)piVar4[0xf])(piVar4,param_2);
      if (iVar1 != -1) {
        iVar1 = *(int *)(param_1 + 0xac) + 0x30;
        do {
          iVar3 = FUN_004081b0(iVar1);
          if (iVar3 == 0) {
            uVar5 = 0;
LAB_00591020:
            while (iVar3 = FUN_004081b0(iVar1), iVar3 != 0) {
              FUN_00408500(iVar3);
              cw_pkt_buf_destroy(*(undefined4 *)(iVar3 + 0xc));
              *(undefined4 *)(iVar3 + 0xc) = 0;
              FUN_00407df0(iVar3);
            }
            return uVar5;
          }
          iVar2 = (**(code **)(param_1 + 0x90))(param_1 + 0x2c,*(undefined4 *)(iVar3 + 0xc));
          if (iVar2 == -1) {
            uVar5 = 0xffffffff;
            if ((capwap_warning_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[CW_WARNING]%32s():%4d frag packet send failed\n","ac_packet_buf_send",0x1e4);
            }
            goto LAB_00591020;
          }
          FUN_00408500(iVar3);
          cw_pkt_buf_destroy(*(undefined4 *)(iVar3 + 0xc));
          *(undefined4 *)(iVar3 + 0xc) = 0;
          FUN_00407df0(iVar3);
        } while( true );
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_ERROR]%32s():%4d packet frag failed\n";
      uVar5 = 0x1da;
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x90))(param_1 + 0x2c,param_2);
      if (iVar1 != -1) {
        return 0;
      }
      if (capwap_warning_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_WARNING]%32s():%4d packet send failed\n";
      uVar5 = 0x1fe;
    }
  }
  printf(pcVar6,"ac_packet_buf_send",uVar5);
  return 0xffffffff;
}

