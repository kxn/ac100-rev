// func apupd_update_parent_wtp_remove @ 0065a298 size=448

undefined4 apupd_update_parent_wtp_remove(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_2e8 [72];
  byte local_2a0;
  byte local_29f;
  byte local_29e;
  byte local_29d;
  byte local_29c;
  byte local_29b;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0xc),auStack_2e8);
  if (iVar1 == -1) {
    uVar4 = 1;
    if (g_apupd_debug == 0) {
      return 1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 1;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: get ap entry by mac failed.\r\n";
    uVar3 = 0x5ac;
  }
  else {
    iVar1 = FUN_00407fa0(apupd_wtp_hash,&local_2a0);
    if (iVar1 == 0) {
      uVar4 = 0;
      if (g_apupd_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = "[APUPD_DEBUG]%32s() %05d: get update wtp from hash by mac failed.\r\n";
      uVar3 = 0x5b1;
    }
    else {
      if (*(int *)(iVar1 + 0x48) != 2) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0x48) = 1;
      if (g_apupd_debug == 0) {
        iVar1 = *(int *)(iVar1 + 0x50);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar1 = *(int *)(iVar1 + 0x50);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: delete update wtp %02x-%02x-%02x-%02x-%02x-%02x because child AP need upgrade first\r\n"
                 ,"apupd_update_parent_wtp_remove",0x5b8,(uint)local_2a0,(uint)local_29f,
                 (uint)local_29e,(uint)local_29d,(uint)local_29c,(uint)local_29b);
          iVar1 = *(int *)(iVar1 + 0x50);
        }
      }
      *(int *)(iVar1 + 0x148) = *(int *)(iVar1 + 0x148) + 1;
      iVar1 = apupd_update_wtp_entry_delete_by_mac(&local_2a0);
      if (iVar1 == 0) {
        return 0;
      }
      uVar4 = 1;
      if (g_apupd_error == 0) {
        return 1;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 1;
      }
      __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
      uVar3 = 0x5be;
    }
  }
  printf(__format,"apupd_update_parent_wtp_remove",uVar3);
  return uVar4;
}

