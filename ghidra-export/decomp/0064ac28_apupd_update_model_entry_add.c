// func apupd_update_model_entry_add @ 0064ac28 size=512

void * apupd_update_model_entry_add(int param_1)

{
  void *__s;
  undefined4 uVar1;
  int iVar2;
  time_t tVar3;
  time_t tVar4;
  char *__format;
  
  __s = (void *)FUN_00408450(0x40,0x39b);
  if (__s == (void *)0x0) {
    if (g_apupd_error == 0) {
      return (void *)0x0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return (void *)0x0;
    }
    __format = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
    uVar1 = 0x39d;
  }
  else {
    memset(__s,0,0x40);
    uVar1 = *(undefined4 *)(param_1 + 0x58);
    *(int *)((int)__s + 0x10) = param_1;
    *(undefined4 *)((int)__s + 0xc) = uVar1;
    FUN_0051ad88((int)__s + 0x30);
    iVar2 = FUN_004080a0(apupd_wtp_firmware_id_hash_obj,apupd_wtp_firmware_id_hash_key,
                         apupd_wtp_firmware_id_hash_cmp,5);
    *(int *)((int)__s + 0x2c) = iVar2;
    if (iVar2 != 0) {
      FUN_0051ad88((int)__s + 0x14);
      FUN_0051ad88((int)__s + 0x20);
      iVar2 = FUN_00408380(apupd_update_model_hash,__s);
      uVar1 = apupd_update_model_list;
      if (iVar2 != 0) {
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: add update mdoel to hash failed.\r\n",
                 "apupd_update_model_entry_add",0x3b1);
        }
        FUN_00408310(*(undefined4 *)((int)__s + 0x2c));
        FUN_00407df0(__s);
        return (void *)0x0;
      }
      iVar2 = FUN_004081b0(apupd_update_model_list);
      while( true ) {
        if (iVar2 == 0) {
          FUN_004086b0(uVar1,__s);
          return __s;
        }
        tVar3 = mktime((tm *)(*(int *)(iVar2 + 0x10) + 0x150));
        tVar4 = mktime((tm *)(*(int *)((int)__s + 0x10) + 0x150));
        if (tVar4 <= tVar3) break;
        iVar2 = FUN_00408680();
      }
      FUN_00408170(iVar2,__s);
      return __s;
    }
    if (g_apupd_error == 0) {
      return (void *)0x0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return (void *)0x0;
    }
    __format = "[APUPD_ERROR]%32s() %05d: wtp list hash malloc failed.\r\n";
    uVar1 = 0x3a9;
  }
  printf(__format,"apupd_update_model_entry_add",uVar1);
  return (void *)0x0;
}

