// func apupd_update_wtp_image_request_send @ 0064b134 size=912

undefined4 apupd_update_wtp_image_request_send(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  
  memset(auStack_2f8,0,0x2d8);
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar4 = 0x190c;
    goto LAB_0064b3b0;
  }
  iVar7 = *(int *)(param_1 + 0x30);
  iVar6 = *(int *)(iVar7 + 0x50);
  iVar2 = *(int *)(iVar6 + 0x7ec);
  if (iVar2 == 2) {
    uVar9 = *(uint *)(iVar6 + 0x1b0);
LAB_0064b220:
    puVar10 = (uint *)(iVar6 + 0x1b4);
    uVar8 = *(uint *)(iVar6 + 0x1ac);
  }
  else if (iVar2 == 1) {
LAB_0064b2f8:
    iVar2 = FUN_00407fa0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x2c),iVar7 + 0x58);
    if (iVar2 == 0) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar3 = "[APUPD_ERROR]%32s() %05d: get wtp list from hash failed\r\n";
      uVar4 = 0x191f;
      goto LAB_0064b3b0;
    }
    uVar9 = *(uint *)(iVar2 + 0x48);
    puVar10 = (uint *)(iVar2 + 0x4c);
    uVar8 = *(uint *)(iVar2 + 0x44);
  }
  else {
    if (iVar2 == 3) {
      if (*(int *)(iVar7 + 0x54) == 1) goto LAB_0064b2f8;
      cVar1 = *(char *)(iVar6 + 0x13a);
    }
    else {
      cVar1 = *(char *)(iVar6 + 0x13a);
    }
    if (cVar1 != '\0') {
      uVar9 = *(uint *)(iVar6 + 0x1b0);
      goto LAB_0064b220;
    }
    puVar10 = *(uint **)(param_1 + 0x38);
    uVar9 = puVar10[1];
    uVar8 = *puVar10;
    puVar10 = puVar10 + 2;
  }
  uVar5 = *(uint *)(iVar7 + 0x4c);
  if (uVar8 <= uVar5) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: offset(%d) is bigger than file size(%d)\r\n",
           "apupd_update_wtp_image_request_send",0x1935,*(undefined4 *)(iVar7 + 0x4c),
           *(undefined4 *)(iVar6 + 0x1ac));
    return 0xffffffff;
  }
  iVar2 = serv_wtp_address_arg_init(&local_308);
  if (iVar2 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: init serv argv failed.\r\n";
    uVar4 = 0x193f;
LAB_0064b3b0:
    printf(pcVar3,"apupd_update_wtp_image_request_send",uVar4);
    return 0xffffffff;
  }
  apmngr_db_entry_get_by_mac(iVar7 + 0x2e,auStack_2f8);
  iVar2 = apmngr_db_get_addr_by_capacity(local_2e8,&local_308,1,1,0xffffffff,0);
  if (iVar2 == -1) {
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(&local_308), iVar2 == 0))
    goto LAB_0064b400;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: add argv failed.\r\n";
    uVar4 = 0x1946;
  }
  else {
    uVar5 = uVar8 - uVar5;
    if (0x400 < uVar5) {
      uVar5 = 0x400;
    }
    iVar2 = apupd_image_request_create
                      (uVar9,uVar8,puVar10,*(undefined4 *)(iVar7 + 0x4c),uVar5,
                       *(undefined1 *)(iVar6 + 0x13a));
    if (iVar2 != 0) {
      iVar6 = serv_retransmit_packet_send(&local_308,iVar2,1,1,4);
      if (iVar6 != -1) {
        cw_pkt_buf_destroy(iVar2);
        serv_wtp_address_arg_destroy(&local_308);
        *(uint *)(iVar7 + 0x4c) = *(int *)(iVar7 + 0x4c) + uVar5;
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: send image request failed.\r\n",
               "apupd_update_wtp_image_request_send",0x1956);
      }
      cw_pkt_buf_destroy(iVar2);
      goto LAB_0064b400;
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(&local_308), iVar2 == 0))
    goto LAB_0064b400;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: assemble image request failed.\r\n";
    uVar4 = 0x194e;
  }
  printf(pcVar3,"apupd_update_wtp_image_request_send",uVar4);
LAB_0064b400:
  serv_wtp_address_arg_destroy(&local_308);
  return 0xffffffff;
}

