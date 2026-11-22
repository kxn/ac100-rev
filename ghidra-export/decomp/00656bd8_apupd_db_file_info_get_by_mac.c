// func apupd_db_file_info_get_by_mac @ 00656bd8 size=660

undefined4
apupd_db_file_info_get_by_mac(int param_1,undefined4 *param_2,void *param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__format;
  int iVar4;
  void *__src;
  undefined4 uVar5;
  int iVar6;
  
  if ((((param_1 == 0) || (param_2 == (undefined4 *)0x0)) || (param_3 == (void *)0x0)) ||
     (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x2134;
    goto LAB_00656d1c;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get wtp by mac failed.\r\n","apupd_db_file_info_get_by_mac",
             0x213e);
    }
    FUN_00407f30(apupd_db_mutex);
    return 0xffffffff;
  }
  iVar4 = *(int *)(iVar1 + 0x30);
  iVar6 = *(int *)(iVar4 + 0x50);
  iVar2 = *(int *)(iVar6 + 0x7ec);
  if (iVar2 == 2) {
    *param_2 = *(undefined4 *)(iVar6 + 0x1ac);
    memcpy(param_3,(void *)(iVar6 + 0x1b4),0x10);
    if (param_4 == (void *)0x0) goto LAB_00656cb4;
    __src = (void *)(iVar6 + 0x1c4);
  }
  else if (iVar2 == 1) {
LAB_00656d34:
    iVar1 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x2c),iVar4 + 0x58);
    if (iVar1 == 0) {
      FUN_00407f30(apupd_db_mutex);
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: get wtp list from hash failed\r\n";
      uVar5 = 0x2154;
      goto LAB_00656d1c;
    }
    *param_2 = *(undefined4 *)(iVar1 + 0x44);
    memcpy(param_3,(void *)(iVar1 + 0x4c),0x10);
    if (param_4 == (void *)0x0) goto LAB_00656cb4;
    __src = (void *)(iVar1 + 0x164);
  }
  else {
    if (iVar2 == 3) {
      if (*(int *)(iVar4 + 0x54) == 1) goto LAB_00656d34;
      puVar3 = *(undefined4 **)(iVar1 + 0x38);
    }
    else {
      puVar3 = *(undefined4 **)(iVar1 + 0x38);
    }
    if (puVar3 == (undefined4 *)0x0) {
      FUN_00407f30(apupd_db_mutex);
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: image info is NULL\r\n";
      uVar5 = 0x2163;
LAB_00656d1c:
      printf(__format,"apupd_db_file_info_get_by_mac",uVar5);
      return 0xffffffff;
    }
    *param_2 = *puVar3;
    memcpy(param_3,(void *)(*(int *)(iVar1 + 0x38) + 8),0x10);
    __src = (void *)(iVar1 + 0x3c);
    if (param_4 == (void *)0x0) goto LAB_00656cb4;
  }
  memcpy(param_4,__src,0x10);
LAB_00656cb4:
  FUN_00407f30(apupd_db_mutex);
  return 0;
}

