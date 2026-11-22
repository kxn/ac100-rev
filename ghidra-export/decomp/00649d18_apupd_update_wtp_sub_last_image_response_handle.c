// func apupd_update_wtp_sub_last_image_response_handle @ 00649d18 size=1064

undefined4 apupd_update_wtp_sub_last_image_response_handle(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 *__dest;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_2f8,0,0x2d8);
  if (param_1 == 0) {
    uVar4 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x1891;
    goto LAB_00649eec;
  }
  iVar6 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(iVar6 + 0x50);
  if (*(int *)(iVar2 + 0x7ec) == 1) {
LAB_00649e54:
    iVar2 = FUN_00407fa0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x2c),iVar6 + 0x58);
    if (iVar2 == 0) {
      iVar8 = 0;
      uVar7 = 0;
      iVar2 = 0;
    }
    else {
      uVar7 = (uint)*(byte *)(iVar2 + 400);
      iVar8 = *(int *)(iVar2 + 0x17c);
      iVar2 = *(int *)(iVar2 + 0x44);
    }
  }
  else {
    if (*(int *)(iVar2 + 0x7ec) == 3) {
      if (*(int *)(iVar6 + 0x54) == 1) goto LAB_00649e54;
      bVar1 = *(byte *)(iVar2 + 0x1a0);
    }
    else {
      bVar1 = *(byte *)(iVar2 + 0x1a0);
    }
    uVar7 = (uint)bVar1;
    iVar8 = *(int *)(iVar2 + 0x18c);
    iVar2 = *(int *)(iVar2 + 0x1ac);
  }
  if (*(int *)(iVar6 + 0x4c) != iVar2) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    uVar5 = *(undefined4 *)(iVar6 + 0x4c);
    pcVar3 = "[APUPD_ERROR]%32s() %05d: offset(%d) isn\'t equal to file size(%d)\r\n";
    uVar4 = 0x18ad;
LAB_00649e94:
    printf(pcVar3,"apupd_update_wtp_sub_last_image_response_handle",uVar4,uVar5,iVar2);
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x24) == 10) {
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: all sub image send, receive eof\r\n",
             "apupd_update_wtp_sub_last_image_response_handle",0x18b3);
    }
    *(undefined4 *)(iVar6 + 0x48) = 7;
    return 0;
  }
  if ((*(int *)(param_1 + 0x20) != 3) ||
     ((*(int *)(iVar6 + 0x48) != 6 && (*(int *)(iVar6 + 0x48) != 0x16)))) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = *(int *)(iVar6 + 0x48);
    uVar5 = *(undefined4 *)(param_1 + 0x20);
    pcVar3 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) or wtp state(%d) is invalib\r\n";
    uVar4 = 0x18bb;
    goto LAB_00649e94;
  }
  __dest = (undefined1 *)FUN_00408450(6,0x18c1);
  if (__dest == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
    uVar5 = 0x18c3;
LAB_00649eec:
    printf(pcVar3,"apupd_update_wtp_sub_last_image_response_handle",uVar5);
    return uVar4;
  }
  *__dest = 0;
  __dest[1] = 0;
  __dest[2] = 0;
  __dest[3] = 0;
  __dest[4] = 0;
  __dest[5] = 0;
  memcpy(__dest,(void *)(param_1 + 0x18),6);
  if (*(int *)(param_1 + 0x28) != -1) {
    FUN_00408060();
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  }
  iVar2 = FUN_00408340(0x1e,0,apupd_update_wtp_sub_image_action_timer_callback,__dest,
                       apupd_update_wtp_argv_callback,
                       "apupd_update_wtp_sub_last_image_response_handle",0x18cf);
  *(int *)(param_1 + 0x28) = iVar2;
  if (iVar2 == -1) {
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0064a0a8;
    uVar4 = 0x18d2;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
  }
  else {
    iVar2 = apmngr_db_entry_get_by_mac(iVar6 + 0x2e,auStack_2f8);
    if (iVar2 == 0) {
      iVar2 = apupd_sub_image_action_send(local_2e8,0,uVar7,0);
      if (iVar2 != -1) {
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x24) = 7;
        uVar4 = 0;
        if (iVar8 != uVar7 - 1) {
          return 0;
        }
        if (g_apupd_debug == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        pcVar3 = "[APUPD_DEBUG]%32s() %05d: ALL sub image have sent\r\n";
        uVar5 = 0x18e6;
        goto LAB_00649eec;
      }
      if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0064a0a8;
      pcVar3 = "[APUPD_ERROR]%32s() %05d: send sub image action packet failed.\r\n";
      uVar4 = 0x18de;
    }
    else {
      if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0064a0a8;
      pcVar3 = "[APUPD_ERROR]%32s() %05d: Get AP entry failed.\r\n";
      uVar4 = 0x18d9;
    }
  }
  printf(pcVar3,"apupd_update_wtp_sub_last_image_response_handle",uVar4);
LAB_0064a0a8:
  FUN_00407df0(__dest);
  return 0xffffffff;
}

