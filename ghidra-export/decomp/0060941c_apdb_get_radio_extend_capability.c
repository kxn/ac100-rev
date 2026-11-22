// func apdb_get_radio_extend_capability @ 0060941c size=568

undefined4
apdb_get_radio_extend_capability
          (undefined4 param_1,int param_2,uint param_3,uint param_4,void *param_5,int param_6)

{
  int iVar1;
  char *__format;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_28 [3];
  
  param_3 = param_3 & 0xff;
  local_28[0] = 0;
  if (((param_3 == 0) || (param_5 == (void *)0x0)) || (param_6 < 0x10)) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input error.\n";
    uVar4 = 0x2676;
  }
  else if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar4 = 0x267b;
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_28);
    if (iVar1 == 0) {
      uVar5 = param_3 - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if ((*(int *)(local_28[0] + 0x10) - 1U & 0xff) < uVar5) {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch != 0) {
          printf("[APDB_WARNING]%s()/line %d : radios_id[%d] out of range[1,%d].\n",
                 "apdb_get_radio_extend_capability",0x268a,param_3,
                 *(undefined4 *)(local_28[0] + 0x10));
          return 0xffffffff;
        }
        return 0xffffffff;
      }
      if (param_4 < 2) {
        puVar2 = (uint *)(*(int *)(local_28[0] + 0x28) + uVar5 * 0x114);
        if (*puVar2 == param_4) {
          puVar2 = puVar2 + 0x40;
        }
        else {
          puVar3 = (uint *)puVar2[0x44];
          if ((puVar3 == (uint *)0x0) || (puVar2 = puVar3 + 0x40, *puVar3 != param_4)) {
            FUN_00407f30(l_apdb_mutex);
            if (apdb_warning_switch != 0) {
              printf("[APDB_WARNING]%s()/line %d : Illegal freq %s.\n",
                     "apdb_get_radio_extend_capability",0x269b,(&PTR_s_2_4GHz_00702480)[param_4]);
              return 0xffffffff;
            }
            return 0xffffffff;
          }
        }
      }
      else {
        puVar2 = (uint *)(*(int *)(local_28[0] + 0x28) + uVar5 * 0x114 + 0x100);
      }
      memcpy(param_5,puVar2,0x10);
      FUN_00407f30(l_apdb_mutex);
      return 0;
    }
    if (apdb_warning_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
    uVar4 = 0x2681;
  }
  printf(__format,"apdb_get_radio_extend_capability",uVar4);
  return 0xffffffff;
}

