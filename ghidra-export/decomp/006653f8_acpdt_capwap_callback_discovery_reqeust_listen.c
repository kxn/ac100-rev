// func acpdt_capwap_callback_discovery_reqeust_listen @ 006653f8 size=828

undefined4 acpdt_capwap_callback_discovery_reqeust_listen(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *__src;
  void *__s;
  size_t sVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_24;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  local_24 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
    uVar5 = 0x20e;
LAB_006654b4:
    printf(pcVar3,"acpdt_capwap_callback_discovery_reqeust_listen",uVar5);
    return 0xffffffff;
  }
  iVar1 = cw_sub_msg_ele_get(param_1,0x26,0);
  if ((iVar1 == 0) || (*(short *)(iVar1 + 0xe) != 4)) {
    if (g_acpdt_warning == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[ACPDT_WARNING] %32s() %05d: get model number failed.\r\n";
    uVar5 = 0x216;
    goto LAB_006654b4;
  }
  memcpy(local_20,*(void **)(iVar1 + 0x10),4);
  __src = (void *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x5b);
  __s = (void *)FUN_00408450(0x10,0x21e);
  if (__s == (void *)0x0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APMNGR_ERROR]%s()/%d malloc error\n";
    uVar5 = 0x220;
    goto LAB_006654b4;
  }
  if (__src == (void *)0x0) {
    memset(__s,0xff,0x10);
  }
  else {
    memcpy(__s,__src,0x10);
  }
  iVar1 = cw_sub_msg_ele_get(param_1,0x27,0);
  pcVar3 = g_acpdt_info;
  if ((iVar1 == 0) || (*(ushort *)(iVar1 + 0x12) < 4)) {
    uVar5 = 0xffffffff;
    if (g_acpdt_warning == 0) goto LAB_00665558;
    pcVar3 = "[ACPDT_WARNING] %32s() %05d: get hardware version failed.\r\n";
    uVar4 = 0x230;
  }
  else {
    local_24 = **(undefined4 **)(iVar1 + 0x14);
    sVar2 = strlen(g_acpdt_info);
    iVar1 = acpdt_ac_name_add(param_3,pcVar3,sVar2 & 0xffff);
    if (iVar1 == -1) {
      uVar5 = 0xffffffff;
      if (g_acpdt_error == 0) goto LAB_00665558;
      pcVar3 = "[ACPDT_ERROR] %32s() %05d: add ac name to parsed packet failed.\r\n";
      uVar4 = 0x23c;
    }
    else {
      iVar1 = acpdt_ac_descriptor_add(param_3,g_acpdt_info);
      if (iVar1 == -1) {
        uVar5 = 0xffffffff;
        if (g_acpdt_error == 0) goto LAB_00665558;
        pcVar3 = "[ACPDT_ERROR] %32s() %05d: add ac descriptor to parsed packet failed.\r\n";
        uVar4 = 0x244;
      }
      else {
        iVar1 = apdb_id_valid(local_20[0]);
        if (((iVar1 == 1) && (iVar1 = apdb_hwver_exist_by_id(local_20[0],&local_24), iVar1 == 1)) &&
           (iVar1 = acpdt_wtp_radio_information_list_add(param_3,local_20[0],__s), iVar1 == -1)) {
          uVar5 = 0xffffffff;
          if (g_acpdt_error == 0) goto LAB_00665558;
          pcVar3 = "[ACPDT_ERROR] %32s() %05d: add wtp radio information failed.\r\n";
          uVar4 = 0x24e;
        }
        else {
          uVar5 = 0;
          uVar4 = apmngr_db_active_ap_num_get();
          iVar1 = FUN_00665344(param_3,uVar4);
          if ((iVar1 != -1) || (uVar5 = 0xffffffff, g_acpdt_error == 0)) goto LAB_00665558;
          pcVar3 = "[ACPDT_ERROR] %32s() %05d: add capwap control ipv4 failed.\r\n";
          uVar4 = 600;
        }
      }
    }
  }
  uVar5 = 0xffffffff;
  printf(pcVar3,"acpdt_capwap_callback_discovery_reqeust_listen",uVar4);
LAB_00665558:
  FUN_00407df0(__s);
  return uVar5;
}

