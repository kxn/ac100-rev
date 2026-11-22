// func apupd_db_model_add_or_update @ 00652fc0 size=648

undefined4 apupd_db_model_add_or_update(int param_1)

{
  int iVar1;
  void *__s;
  char *pcVar2;
  undefined4 uVar3;
  
  if (((param_1 == 0) || (apupd_model_hash == 0)) || (apupd_model_list == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_add_or_update",0x1c3d);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_model_hash,param_1 + 0x58);
  if (iVar1 == 0) {
    __s = (void *)FUN_00408450(0x800,0x1c52);
    if (__s != (void *)0x0) {
      memset(__s,0,0x800);
      memcpy((void *)((int)__s + 0x18),(void *)(param_1 + 0x18),0x40);
      *(undefined4 *)((int)__s + 0x58) = *(undefined4 *)(param_1 + 0x58);
      FUN_0051ad88((int)__s + 0x7f4);
      FUN_0051ad88((int)__s + 0x17c);
      *(undefined4 *)((int)__s + 0x13c) = 0xffffffff;
      iVar1 = apupd_model_entry_basic_set(__s,param_1);
      if (iVar1 == -1) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar2 = "[APUPD_ERROR]%32s() %05d: copy model failed.\r\n";
          uVar3 = 0x1c62;
LAB_006531a8:
          printf(pcVar2,"apupd_db_model_add_or_update",uVar3);
        }
      }
      else {
        iVar1 = FUN_00408380(apupd_model_hash,__s);
        if (iVar1 == 0) {
          FUN_004086b0(apupd_model_list,__s);
          goto LAB_00653040;
        }
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar2 = "[APUPD_ERROR]%32s() %05d: insert model to hash failed.\r\n";
          uVar3 = 0x1c6a;
          goto LAB_006531a8;
        }
      }
      FUN_00407df0(__s);
      goto LAB_00653150;
    }
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_00653150;
    pcVar2 = "[APUPD_ERROR]%32s() %05d: create model faield.\r\n";
    uVar3 = 0x1c55;
  }
  else {
    iVar1 = apupd_model_entry_basic_set(iVar1,param_1);
    if (iVar1 != -1) {
LAB_00653040:
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_00653150;
    pcVar2 = "[APUPD_ERROR]%32s() %05d: copy model failed.\r\n";
    uVar3 = 0x1c4a;
  }
  printf(pcVar2,"apupd_db_model_add_or_update",uVar3);
LAB_00653150:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

