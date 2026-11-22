// func _uac_wserv_pkt_igmp_snooping_config_send @ 005e7f58 size=676

undefined4
_uac_wserv_pkt_igmp_snooping_config_send
          (int param_1,undefined1 param_2,undefined1 param_3,uint param_4,byte param_5,byte param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  size_t __n;
  int iVar6;
  int iVar7;
  char cVar8;
  undefined4 local_50;
  void *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_30;
  uint local_2c;
  
  local_30 = param_4 & 0xff;
  local_2c = (uint)param_5;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_50 = 0;
  local_4c = (void *)0x0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 != 0) {
    __n = (uint)param_6 << 2;
    FUN_0051ad88(&local_40);
    local_50 = CONCAT22(CONCAT11(param_2,param_3),CONCAT11(param_6,(undefined1)local_50));
    local_4c = (void *)FUN_00408450(__n,0xfa);
    if (local_4c == (void *)0x0) {
      uVar4 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n",
               "_uac_wserv_pkt_igmp_snooping_config_create",0xfe);
        uVar4 = 0xffffffff;
      }
      goto LAB_005e8150;
    }
    cVar8 = '\x01';
    iVar6 = 0;
    memset(local_4c,0,__n);
    while (iVar6 < (int)(uint)param_6) {
      iVar7 = iVar6 * 4;
      *(char *)((int)local_4c + iVar7) = cVar8;
      if (iVar6 == 0) {
        uVar5 = (undefined2)local_30;
      }
      else {
        uVar5 = (undefined2)local_2c;
      }
      *(undefined2 *)((int)local_4c + iVar7 + 2) = uVar5;
      if ((g_wserv_debug == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
        iVar6 = iVar6 + 1;
        cVar8 = cVar8 + '\x01';
      }
      else {
        cVar8 = cVar8 + '\x01';
        printf("<wserv>[debug]%s(): %d  -> radio_id = %d, rate = %d\r\n",
               "_uac_wserv_pkt_igmp_snooping_config_create",0x10d,iVar6,
               (uint)*(ushort *)((int)local_4c + iVar7 + 2));
        iVar6 = iVar6 + 1;
      }
    }
    iVar6 = cw_service_msg_add(iVar2,0x25,&local_48,1,0x70,&local_50);
    if (iVar6 == 0) {
      if (wserv_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar2);
      }
      iVar6 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar6 != -1) {
        if (local_4c != (void *)0x0) {
          FUN_00407df0();
          local_4c = (void *)0x0;
        }
        cw_parsed_pkt_destroy(iVar2);
        uVar4 = serv_packet_send(param_1,iVar1,1);
        goto LAB_005e8150;
      }
    }
    if (local_4c != (void *)0x0) {
      FUN_00407df0();
      local_4c = (void *)0x0;
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  uVar4 = 0xffffffff;
LAB_005e8150:
  cw_pkt_buf_destroy(iVar1);
  return uVar4;
}

