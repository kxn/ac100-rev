// func _uac_wserv_pkt_igmp_snooping_switch_send @ 005e81fc size=752

undefined4 _uac_wserv_pkt_igmp_snooping_switch_send(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int local_48;
  void *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_48 = 0;
  local_44 = (void *)0x0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 != 0) {
    FUN_0051ad88(&local_38);
    iVar3 = FUN_00407fe0(param_2 + 4);
    local_48 = iVar3;
    if ((g_wserv_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> ssid_num = %d\r\n",
             "_uac_wserv_pkt_igmp_snooping_switch_create",0x15d,iVar3);
    }
    local_44 = (void *)FUN_00408450(iVar3 * 3,0x15e);
    if ((iVar3 != 0) && (local_44 == (void *)0x0)) {
      uVar6 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n",
               "_uac_wserv_pkt_igmp_snooping_switch_create",0x162);
        uVar6 = 0xffffffff;
      }
      goto LAB_005e83c8;
    }
    memset(local_44,0,iVar3 * 3);
    iVar7 = 0;
    iVar4 = FUN_004081b0(param_2 + 4);
    if (iVar3 != 0) {
      do {
        iVar5 = iVar7 * 3;
        *(char *)((int)local_44 + iVar5) = *(char *)(iVar4 + 0xc) + '\x01';
        *(char *)((int)local_44 + iVar5 + 1) = (char)*(undefined2 *)(iVar4 + 0xe);
        *(undefined1 *)((int)local_44 + iVar5 + 2) = *(undefined1 *)(iVar4 + 0x10);
        if ((g_wserv_debug != 0) && (iVar5 = is_target_debug_ap(iVar4), iVar5 != 0)) {
          printf("<wserv>[debug]%s(): %d  -> i = %d, radio_id = %d, wlan_id = %d, snooping_enable = %d\r\n"
                 ,"_uac_wserv_pkt_igmp_snooping_switch_create",0x16e,iVar7,
                 (uint)*(byte *)(iVar4 + 0xc),(int)*(short *)(iVar4 + 0xe),
                 (uint)*(byte *)(iVar4 + 0x10));
        }
        iVar7 = iVar7 + 1;
        iVar4 = FUN_00408680(iVar4);
      } while (iVar7 != iVar3);
    }
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_40,1,0x71,&local_48);
    if (iVar3 == 0) {
      if (wserv_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar2);
      }
      iVar3 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar3 != -1) {
        if (local_44 != (void *)0x0) {
          FUN_00407df0();
          local_44 = (void *)0x0;
        }
        cw_parsed_pkt_destroy(iVar2);
        uVar6 = serv_packet_send(param_1,iVar1,1);
        goto LAB_005e83c8;
      }
    }
    if (local_44 != (void *)0x0) {
      FUN_00407df0();
      local_44 = (void *)0x0;
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  uVar6 = 0xffffffff;
LAB_005e83c8:
  cw_pkt_buf_destroy(iVar1);
  return uVar6;
}

