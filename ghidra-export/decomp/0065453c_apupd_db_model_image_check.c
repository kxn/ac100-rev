// func apupd_db_model_image_check @ 0065453c size=1

undefined4 apupd_db_model_image_check(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((param_1 == 0) || (apupd_model_hash == 0)) {
    uVar4 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0x2067;
code_r0x00654640:
    printf(pcVar2,"apupd_db_model_image_check",uVar3);
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(apupd_model_hash,param_1 + 0x58);
    if (iVar1 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        pcVar2 = "[APUPD_ERROR]%32s() %05d: get model from hash faild.\r\n";
        uVar4 = 0x2071;
code_r0x0065468c:
        printf(pcVar2,"apupd_db_model_image_check",uVar4);
      }
    }
    else {
      iVar1 = memcmp((void *)(param_1 + 0x1b4),(void *)(iVar1 + 0x1b4),0x10);
      if (iVar1 == 0) {
        FUN_00407f30(apupd_db_mutex);
        uVar4 = 0;
        if (g_apupd_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        pcVar2 = "[APUPD_DEBUG]%32s() %05d: image is existent.\r\n";
        uVar3 = 0x2081;
        goto code_r0x00654640;
      }
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        pcVar2 = "[APUPD_DEBUG]%32s() %05d: image isn\'t existent.\r\n";
        uVar4 = 0x2079;
        goto code_r0x0065468c;
      }
    }
    uVar4 = 0xffffffff;
    FUN_00407f30(apupd_db_mutex);
  }
  return uVar4;
}

