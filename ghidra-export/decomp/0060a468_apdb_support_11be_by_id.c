// func apdb_support_11be_by_id @ 0060a468 size=464

uint apdb_support_11be_by_id(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int local_20 [2];
  
  local_20[0] = 0;
  iVar1 = apdb_get_model_by_id(param_1,param_2,local_20);
  if (iVar1 != 0) {
    if (apdb_warning_switch == 0) {
      return 0;
    }
    printf("[APDB_WARNING]%s()/line %d : get model failed\n","apdb_support_11be_by_id",0x28bf);
    return 0;
  }
  uVar3 = (param_3 & 0xff) - 1 & 0xff;
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  if ((*(int *)(local_20[0] + 0x10) - 1U & 0xff) < uVar3) {
    uVar3 = 0;
    if (apdb_warning_switch != 0) {
      printf("[APDB_WARNING]%s()/line %d : input radio id[%d] out of range[1,%d].\n",
             "apdb_support_11be_by_id",0x28c6,param_3 & 0xff,*(int *)(local_20[0] + 0x10));
    }
  }
  else {
    if (1 < param_4) {
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch == 0) {
        return 0;
      }
      uVar2 = 0x28dd;
LAB_0060a600:
      printf("[APDB_WARNING]%s()/line %d : Illegal freq %s.\n","apdb_support_11be_by_id",uVar2,
             (&PTR_s_2_4GHz_00702480)[param_4]);
      return 0;
    }
    puVar4 = (uint *)(*(int *)(local_20[0] + 0x28) + uVar3 * 0x114);
    if (*puVar4 == param_4) {
      uVar3 = puVar4[5];
    }
    else {
      puVar4 = (uint *)puVar4[0x44];
      if ((puVar4 == (uint *)0x0) || (*puVar4 != param_4)) {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0;
        }
        uVar2 = 0x28d6;
        goto LAB_0060a600;
      }
      uVar3 = puVar4[5];
    }
  }
  FUN_00407f30(l_apdb_mutex);
  return uVar3;
}

