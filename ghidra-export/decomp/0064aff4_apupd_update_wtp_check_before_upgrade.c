// func apupd_update_wtp_check_before_upgrade @ 0064aff4 size=320

undefined4 apupd_update_wtp_check_before_upgrade(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [660];
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0xc),auStack_2e8);
  if (iVar1 == -1) {
    uVar5 = 1;
    if (g_apupd_debug == 0) {
      return 1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 1;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: get ap entry by mac failed.\r\n";
    uVar4 = 0x590;
LAB_0064b0e0:
    printf(__format,"apupd_update_wtp_check_before_upgrade",uVar4);
    return uVar5;
  }
  iVar1 = FUN_00407fa0(apupd_wtp_hash,auStack_2a0);
  if (iVar1 == 0) {
    uVar5 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: get update wtp from hash by mac failed.\r\n";
    uVar4 = 0x595;
    goto LAB_0064b0e0;
  }
  if (param_2[1] == 0) {
    uVar3 = *(uint *)(iVar1 + 0x48);
  }
  else if (*(char *)(*(int *)(iVar1 + 0x50) + 0x13a) == '\0') {
    uVar3 = *(uint *)(iVar1 + 0x48);
  }
  else {
    if (*(int *)(*(int *)(iVar1 + 0x50) + 0x148) != 0) goto LAB_0064b094;
    uVar3 = *(uint *)(iVar1 + 0x48);
  }
  uVar2 = 2;
  if (param_2[1] == 0) {
    uVar2 = 3;
  }
  if (uVar3 < uVar2) {
    return 0;
  }
  if (6 < uVar3) {
    return 0;
  }
LAB_0064b094:
  *param_2 = 0;
  return 2;
}

