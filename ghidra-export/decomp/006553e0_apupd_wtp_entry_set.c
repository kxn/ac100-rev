// func apupd_wtp_entry_set @ 006553e0 size=724

undefined4 apupd_wtp_entry_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *__format;
  undefined1 auStack_2f0 [18];
  ushort local_2de;
  
  memset(auStack_2f0,0,0x2d8);
  if (((param_1 == 0) || (param_2 == 0)) || (apupd_model_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0xe83;
    goto LAB_00655670;
  }
  iVar1 = FUN_00407fa0(apupd_model_hash,param_2 + 0x34);
  if (iVar1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get model from hash by id failed.\r\n";
    uVar3 = 0xe8a;
    goto LAB_00655670;
  }
  if (*(int *)(param_1 + 0x34) == *(int *)(param_2 + 0x34)) {
    iVar2 = memcmp((void *)(param_1 + 0x58),(void *)(param_2 + 0x58),0x10);
    if (iVar2 != 0) {
      apupd_update_hw_fw_info(param_1,param_2,iVar1,iVar1);
    }
  }
  else {
    iVar2 = FUN_00407fa0(apupd_model_hash,param_1 + 0x34);
    if (iVar2 == 0) {
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(param_1), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: old_model get error.\r\n","apupd_wtp_entry_set",0xe98);
      }
    }
    else {
      apupd_update_hw_fw_info(param_1,param_2,iVar2,iVar1);
    }
    FUN_00408500(param_1);
    FUN_004086b0(iVar1 + 0x7f4,param_1);
    FUN_00408500(param_1 + 0xc);
    FUN_004086b0(apupd_wtp_list,param_1 + 0xc);
    *(int *)(param_1 + 0x50) = iVar1;
  }
  iVar2 = apmngr_db_entry_get_by_mac(param_1 + 0x2e,auStack_2f0);
  if (iVar2 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n";
    uVar3 = 0xeab;
    goto LAB_00655670;
  }
  if ((*(uint *)(iVar1 + 0x18) & 1) == 0) {
    if (local_2de < 0x200) {
      uVar4 = local_2de + 1;
      if ((*(uint *)(iVar1 + (((int)uVar4 >> 5) + 6) * 4) >> (uVar4 & 0x1f) & 1) != 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x48);
        goto LAB_006554cc;
      }
      iVar1 = *(int *)(iVar1 + 0x7ec);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x7ec);
    }
    if (iVar1 == 3) {
      uVar3 = *(undefined4 *)(param_1 + 0x48);
      goto LAB_006554cc;
    }
    *(undefined4 *)(param_2 + 0x48) = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x48);
LAB_006554cc:
    *(undefined4 *)(param_2 + 0x48) = uVar3;
  }
  iVar1 = apupd_wtp_entry_clone(param_1,param_2);
  if (iVar1 != -1) {
    apupd_wtp_entry_add_after_handle(param_1);
    return 0;
  }
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __format = "[APUPD_ERROR]%32s() %05d: clone wtp failed.\r\n";
  uVar3 = 0xebd;
LAB_00655670:
  printf(__format,"apupd_wtp_entry_set",uVar3);
  return 0xffffffff;
}

