// func _uac_wserv_pkt_igmp_group_policy_send @ 005e88d4 size=636

undefined4 _uac_wserv_pkt_igmp_group_policy_send(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_88;
  void *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 auStack_6c [68];
  
  param_3 = param_3 & 0xff;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar6 = cw_pkt_buf_create(0xfa);
  if (iVar6 == 0) {
    return 0xffffffff;
  }
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_88 = 0;
  local_84 = (void *)0x0;
  memset(auStack_6c,0,0x40);
  iVar7 = cw_parsed_pkt_create(7);
  if (iVar7 != 0) {
    FUN_0051ad88(&local_78);
    local_88 = param_3;
    local_84 = (void *)FUN_00408450(param_3 * 0x18,0x25b);
    if ((param_3 != 0) && (local_84 == (void *)0x0)) {
      uVar8 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_pkt_igmp_group_policy_create"
               ,0x25f);
        uVar8 = 0xffffffff;
      }
      goto LAB_005e8aa8;
    }
    memset(local_84,0,param_3 * 0x18);
    for (iVar9 = 0; iVar9 < (int)param_3; iVar9 = iVar9 + 1) {
      *(undefined1 *)((int)local_84 + iVar9 * 0x18) = *(undefined1 *)(param_2 + 0x18);
      memcpy((void *)((int)local_84 + iVar9 * 0x18 + 4),(void *)(param_2 + 4),0x14);
      puVar1 = (undefined4 *)(param_2 + 0x14);
      puVar2 = (undefined4 *)(param_2 + 4);
      puVar3 = (undefined4 *)(param_2 + 8);
      puVar4 = (undefined4 *)(param_2 + 0xc);
      puVar5 = (undefined4 *)(param_2 + 0x10);
      param_2 = param_2 + 0x1c;
      FUN_00408190(*puVar2,*puVar3,*puVar4,*puVar5,*puVar1,auStack_6c,0x40,"---");
    }
    iVar9 = cw_service_msg_add(iVar7,0x25,&local_80,1,0x74,&local_88);
    if (iVar9 == 0) {
      if (wserv_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar7);
      }
      iVar9 = capwap_packet_assemble(iVar6,iVar7);
      if (iVar9 != -1) {
        if (local_84 != (void *)0x0) {
          FUN_00407df0();
          local_84 = (void *)0x0;
        }
        cw_parsed_pkt_destroy(iVar7);
        uVar8 = serv_packet_send(param_1,iVar6,1);
        goto LAB_005e8aa8;
      }
    }
    if (local_84 != (void *)0x0) {
      FUN_00407df0();
      local_84 = (void *)0x0;
    }
    cw_parsed_pkt_destroy(iVar7);
  }
  uVar8 = 0xffffffff;
LAB_005e8aa8:
  cw_pkt_buf_destroy(iVar6);
  return uVar8;
}

