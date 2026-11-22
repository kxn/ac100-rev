// func apdb_get_radio_freq_info_by_id @ 00607fa0 size=452

int apdb_get_radio_freq_info_by_id(undefined4 param_1,int param_2,uint param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  int local_20 [2];
  
  param_3 = param_3 & 0xff;
  local_20[0] = 0;
  if (param_3 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : input radio id error.\n";
      uVar3 = 0x23d0;
      goto LAB_00608074;
    }
  }
  else if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar3 = 0x23d5;
      goto LAB_00608074;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_20);
    if (iVar1 == 0) {
      uVar4 = param_3 - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if ((*(int *)(local_20[0] + 0x10) - 1U & 0xff) < uVar4) {
        iVar1 = -1;
        if (apdb_warning_switch != 0) {
          printf("[APDB_WARNING]%s()/line %d : radios_id[%d] out of range[1,%d].\n",
                 "apdb_get_radio_freq_info_by_id",0x23e3,param_3,*(int *)(local_20[0] + 0x10));
        }
      }
      else {
        *param_4 = '\x01';
        iVar1 = *(int *)(*(int *)(local_20[0] + 0x28) + uVar4 * 0x114);
        iVar2 = 0;
        while (iVar2 < (int)uVar4) {
          if (iVar1 == *(int *)(*(int *)(local_20[0] + 0x28) + iVar2 * 0x114)) {
            iVar2 = iVar2 + 1;
            *param_4 = *param_4 + '\x01';
          }
          else {
            iVar2 = iVar2 + 1;
          }
        }
      }
      FUN_00407f30(l_apdb_mutex);
      return iVar1;
    }
    if (apdb_warning_switch != 0) {
      __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar3 = 0x23db;
LAB_00608074:
      printf(__format,"apdb_get_radio_freq_info_by_id",uVar3);
      return -1;
    }
  }
  return -1;
}

