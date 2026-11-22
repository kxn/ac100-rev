// func balance_packet_send @ 0045802c size=944

/* WARNING: Type propagation algorithm not settling */

undefined4 balance_packet_send(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar5 = 0x14d;
    goto LAB_00458228;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: malloc failed.\r\n","balance_packet_buffer_create",0x11f);
    }
  }
  else {
    local_40[3] = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_40[1] = 0;
    local_40[2] = 0;
    local_40[0] = 0;
    iVar2 = cw_parsed_pkt_create(7);
    if (iVar2 == 0) {
      if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: malloc parsed packet failed.\r\n",
               "balance_parsed_packet_create",0xd6);
      }
    }
    else {
      local_40[3] = 0x12345678;
      local_30 = CONCAT22(0x26,local_30._2_2_);
      FUN_0051ad88(&local_2c);
      local_40[1] = 1;
      local_40[2] = (int)(*param_2 == 1);
      iVar3 = cw_service_msg_add(iVar2,0x25,local_40 + 3,1,0x26,local_40 + 1);
      if (iVar3 != -1) {
        if (*param_2 == 1) {
          local_30 = CONCAT22(0x3e,local_30._2_2_);
          FUN_0051ad88(&local_2c);
          local_40[0] = param_2[5];
          iVar3 = cw_service_msg_add(iVar2,0x25,local_40 + 3,1,0x3e,local_40);
          if (iVar3 == -1) {
            if ((g_balance_error != 0) && (iVar3 = is_target_debug_ap(iVar1), iVar3 != 0)) {
              pcVar4 = "[BALANCE_ERROR](%32s) %05d: craete vsp with spec rssi failed.\r\n";
              uVar5 = 0xf8;
              goto LAB_0045837c;
            }
            goto LAB_004582c8;
          }
        }
        iVar3 = capwap_packet_assemble(iVar1,iVar2);
        if (iVar3 != -1) {
          cw_parsed_pkt_destroy(iVar2);
          iVar2 = serv_packet_send(param_1,iVar1,1);
          if (iVar2 == -1) {
            if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[BALANCE_ERROR](%32s) %05d: send packet failed.\r\n","balance_packet_send",
                     0x15b);
            }
            cw_pkt_buf_destroy(iVar1);
            return 0xffffffff;
          }
          cw_pkt_buf_destroy(iVar1);
          return 0;
        }
        cw_pkt_buf_destroy(iVar1);
        cw_parsed_pkt_destroy(iVar2);
        goto LAB_004581d4;
      }
      if ((g_balance_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        pcVar4 = "[BALANCE_ERROR](%32s) %05d: add vsp with spec msg mask failed.\r\n";
        uVar5 = 0xea;
LAB_0045837c:
        printf(pcVar4,"balance_parsed_packet_create",uVar5);
      }
LAB_004582c8:
      cw_parsed_pkt_destroy(iVar2);
    }
    if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: create balance parsed packet failed.\r\n",
             "balance_packet_buffer_create",0x126);
    }
    cw_pkt_buf_destroy(iVar1);
  }
LAB_004581d4:
  if (g_balance_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar4 = "[BALANCE_ERROR](%32s) %05d: init serv argv failed.\r\n";
  uVar5 = 0x154;
LAB_00458228:
  printf(pcVar4,"balance_packet_send",uVar5);
  return 0xffffffff;
}

