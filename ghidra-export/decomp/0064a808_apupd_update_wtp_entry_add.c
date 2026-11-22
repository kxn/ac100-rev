// func apupd_update_wtp_entry_add @ 0064a808 size=1056

void * apupd_update_wtp_entry_add(int param_1,int param_2)

{
  void *__s;
  int iVar1;
  void *__s_00;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  int local_a8;
  
  memset(auStack_300,0,0x2d8);
  __s = (void *)FUN_00408450(0x4c,0x3d9);
  if (__s == (void *)0x0) {
    if (g_apupd_error == 0) {
      return (void *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    pcVar2 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
    uVar3 = 0x3db;
LAB_0064a9d8:
    printf(pcVar2,"apupd_update_wtp_entry_add",uVar3);
  }
  else {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_entry_add mac[%02X:%02X:%02X:%02X:%02X:%02X].\r\n"
             ,"apupd_update_wtp_entry_add",0x3df,(uint)*(byte *)(param_2 + 0x2e),
             (uint)*(byte *)(param_2 + 0x2f),(uint)*(byte *)(param_2 + 0x30),
             (uint)*(byte *)(param_2 + 0x31),(uint)*(byte *)(param_2 + 0x32),
             (uint)*(byte *)(param_2 + 0x33));
    }
    memset(auStack_300,0,0x2d8);
    memset(__s,0,0x4c);
    memcpy((void *)((int)__s + 0x18),(void *)(param_2 + 0x2e),6);
    uVar3 = apupd_update_wtp_hash;
    *(int *)((int)__s + 0x34) = param_1;
    *(int *)((int)__s + 0x30) = param_2;
    *(undefined4 *)((int)__s + 0x20) = 0;
    *(undefined4 *)((int)__s + 0x28) = 0xffffffff;
    *(undefined4 *)((int)__s + 0x24) = 0;
    iVar1 = FUN_00408380(uVar3,__s);
    if (iVar1 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x10) + 0x13a) != '\x01') {
        iVar1 = *(int *)(param_1 + 0x10);
LAB_0064a8e8:
        if (*(int *)(iVar1 + 0x7ec) == 3) {
          if (*(int *)(param_2 + 0x54) == 2) {
            *(undefined4 *)((int)__s + 0x38) = *(undefined4 *)(param_2 + 0x8c);
            memcpy((void *)((int)__s + 0x3c),(void *)(param_2 + 0x90),0x10);
            *(undefined4 *)(param_2 + 0x8c) = 0;
            goto LAB_0064a8f8;
          }
          iVar1 = *(int *)(param_1 + 0x10);
        }
        else {
LAB_0064a8f8:
          iVar1 = *(int *)(param_1 + 0x10);
        }
        if ((*(int *)(iVar1 + 0x7ec) == 2) ||
           ((*(int *)(iVar1 + 0x7ec) == 3 && (*(int *)(param_2 + 0x54) == 2)))) {
          FUN_004086b0(param_1 + 0x20,__s);
          if (*(int *)(param_1 + 0x3c) == 0) {
            *(void **)(param_1 + 0x3c) = __s;
          }
        }
        else {
          __s_00 = (void *)FUN_00407fa0(*(undefined4 *)(param_1 + 0x2c),(void *)(param_2 + 0x58));
          if (__s_00 == (void *)0x0) {
            __s_00 = (void *)FUN_00408450(0x1a0,0x415);
            if (__s_00 == (void *)0x0) {
              FUN_00407f40(apupd_update_wtp_hash,__s);
              FUN_00407df0(__s);
              __s = (void *)0x0;
              if (g_apupd_error == 0) {
                return (void *)0x0;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return (void *)0x0;
              }
              pcVar2 = "[APUPD_ERROR]%32s() %05d: wtp list malloc failed.\r\n";
              uVar3 = 0x41a;
              goto LAB_0064a9d8;
            }
            memset(__s_00,0,0x1a0);
            FUN_0051ad88((int)__s_00 + 0xc);
            memcpy((void *)((int)__s_00 + 0x18),(void *)(param_2 + 0x58),0x10);
            FUN_00408380(*(undefined4 *)(param_1 + 0x2c),__s_00);
            FUN_004086b0(param_1 + 0x30,__s_00);
          }
          FUN_004086b0((int)__s_00 + 0xc,__s);
          if (*(int *)((int)__s_00 + 0x3c) == 0) {
            *(void **)((int)__s_00 + 0x3c) = __s;
          }
        }
        FUN_004086b0(param_1 + 0x14,(int)__s + 0xc);
        if (g_apupd_debug == 0) {
          return __s;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return __s;
        }
        pcVar2 = "[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_entry_add success\r\n";
        uVar3 = 0x42b;
        goto LAB_0064a9d8;
      }
      iVar1 = apmngr_db_entry_get_by_mac((void *)(param_2 + 0x2e),auStack_300);
      if (iVar1 == -1) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar2 = "[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n";
          uVar3 = 0x3f6;
          goto LAB_0064ab9c;
        }
      }
      else {
        if (local_a8 << 0xe < 0) {
          iVar1 = *(int *)(param_1 + 0x10);
          goto LAB_0064a8e8;
        }
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: AP[%d] not support large image update\r\n",
                 "apupd_update_wtp_entry_add",0x3fc,(uint)local_2f0);
        }
      }
    }
    else if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar2 = "[APUPD_ERROR]%32s() %05d: add update wtp to hash failed.\r\n";
      uVar3 = 0x3ed;
LAB_0064ab9c:
      printf(pcVar2,"apupd_update_wtp_entry_add",uVar3);
    }
    FUN_00407df0(__s);
    __s = (void *)0x0;
  }
  return __s;
}

