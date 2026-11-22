// func apupd_db_model_range_handle @ 00653898 size=1

undefined4 apupd_db_model_range_handle(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  undefined4 uVar5;
  uint uVar6;
  
  if (apupd_model_list == 0) {
    uVar4 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x1d88;
  }
  else {
    if ((param_2 != 0) && (param_3 != (code *)0x0)) {
      FUN_004082d0(apupd_db_mutex,0xffffffff);
      uVar1 = FUN_00407fe0(apupd_model_list);
      if (uVar1 < param_1) {
        if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
          uVar4 = FUN_00407fe0(apupd_model_list);
          printf("[APUPD_DEBUG]%32s() %05d: offset[%d] is out of range, model size[%d]!\r\n",
                 "apupd_db_model_range_handle",0x1d99,param_1,uVar4);
        }
        FUN_00407f30(apupd_db_mutex);
        return 0xffffffff;
      }
      uVar1 = 0;
      uVar6 = 0;
      iVar2 = FUN_004081b0(apupd_model_list);
      do {
        while( true ) {
          if (iVar2 == 0) goto code_r0x00653978;
          iVar3 = FUN_00408680(iVar2);
          if (param_1 <= uVar1) break;
          uVar1 = uVar1 + 1;
          iVar2 = iVar3;
        }
        uVar6 = uVar6 + 1;
        (*param_3)(iVar2,param_4);
        iVar2 = iVar3;
      } while (uVar6 < param_2);
code_r0x00653978:
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    uVar4 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: nothing need be done.\r\n";
    uVar5 = 0x1d8f;
  }
  printf(__format,"apupd_db_model_range_handle",uVar5);
  return uVar4;
}

