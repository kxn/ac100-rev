// func apupd_db_softver_get_by_mac_without_lock @ 00656e6c size=408

undefined4 apupd_db_softver_get_by_mac_without_lock(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  int iVar3;
  void *__src;
  int iVar4;
  undefined4 uVar5;
  
  if ((param_1 == 0) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x217c;
  }
  else {
    iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x30);
      iVar3 = *(int *)(iVar2 + 0x50);
      if ((*(char *)(iVar3 + 0x13a) == '\x01') || (iVar4 = *(int *)(iVar3 + 0x7ec), iVar4 == 2)) {
        if (param_2 == (void *)0x0) {
          return 0;
        }
        __src = (void *)(iVar3 + 0x1c4);
      }
      else if ((iVar4 == 1) || ((iVar4 == 3 && (*(int *)(iVar2 + 0x54) == 1)))) {
        iVar1 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x2c),iVar2 + 0x58);
        if (iVar1 == 0) {
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[APUPD_ERROR]%32s() %05d: get wtp list from hash failed\r\n";
          uVar5 = 0x21a0;
          goto LAB_00656f58;
        }
        if (param_2 == (void *)0x0) {
          return 0;
        }
        __src = (void *)(iVar1 + 0x164);
      }
      else {
        if (param_2 == (void *)0x0) {
          return 0;
        }
        __src = (void *)(iVar1 + 0x3c);
      }
      memcpy(param_2,__src,0x10);
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get wtp by mac failed.\r\n";
    uVar5 = 0x2184;
  }
LAB_00656f58:
  printf(__format,"apupd_db_softver_get_by_mac_without_lock",uVar5);
  return 0xffffffff;
}

