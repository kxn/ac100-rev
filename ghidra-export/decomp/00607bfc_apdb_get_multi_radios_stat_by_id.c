// func apdb_get_multi_radios_stat_by_id @ 00607bfc size=528

undefined4
apdb_get_multi_radios_stat_by_id
          (undefined4 param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  int local_28 [3];
  
  local_28[0] = 0;
  if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input fw_id is null.\n";
    uVar4 = 0x234e;
  }
  else if (param_3 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input radios_id null.\n";
    uVar4 = 0x2354;
  }
  else if (param_4 == (uint *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input radio_type null.\n";
    uVar4 = 0x2359;
  }
  else {
    if (param_5 != (uint *)0x0) {
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      iVar1 = apdb_get_model_by_id(param_1,param_2,local_28);
      if (iVar1 == 0) {
        cVar3 = '\x01';
        for (uVar2 = 0; uVar4 = l_apdb_mutex, uVar2 < *(uint *)(local_28[0] + 0x10);
            uVar2 = uVar2 + 1) {
          uVar5 = 0x1f;
          *(char *)(param_3 + uVar2) = cVar3;
          *param_4 = 0xf;
          if (*(int *)(*(int *)(local_28[0] + 0x28) + uVar2 * 0x114 + 4) != 1) {
            uVar5 = 0xf;
          }
          *param_4 = uVar5;
          if (*(int *)(*(int *)(local_28[0] + 0x28) + uVar2 * 0x114 + 8) == 1) {
            *param_4 = uVar5 | 0x20;
          }
          cVar3 = cVar3 + '\x01';
          param_4 = param_4 + 1;
        }
        *param_5 = uVar2;
        FUN_00407f30(uVar4);
        return 0;
      }
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : get model failed\n","apdb_get_multi_radios_stat_by_id",
               0x2366);
      }
      FUN_00407f30(l_apdb_mutex);
      return 0xffffffff;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input count null.\n";
    uVar4 = 0x235e;
  }
  printf(__format,"apdb_get_multi_radios_stat_by_id",uVar4);
  return 0xffffffff;
}

