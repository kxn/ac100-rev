// func apdb_get_dft_radio_freq_by_id @ 00607e0c size=364

undefined4 apdb_get_dft_radio_freq_by_id(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint uVar3;
  int local_20 [3];
  
  param_3 = param_3 & 0xff;
  local_20[0] = 0;
  if (param_3 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : input radio id error.\n";
      uVar2 = 0x2393;
      goto LAB_00607ed4;
    }
  }
  else if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar2 = 0x2398;
      goto LAB_00607ed4;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_20);
    if (iVar1 == 0) {
      uVar3 = param_3 - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if ((*(int *)(local_20[0] + 0x10) - 1U & 0xff) < uVar3) {
        uVar2 = 0xffffffff;
        if (apdb_warning_switch != 0) {
          printf("[APDB_WARNING]%s()/line %d : radios_id[%d] out of range[1,%d].\n",
                 "apdb_get_dft_radio_freq_by_id",0x23a6,param_3,*(int *)(local_20[0] + 0x10));
        }
      }
      else {
        uVar2 = *(undefined4 *)(*(int *)(local_20[0] + 0x28) + uVar3 * 0x114);
      }
      FUN_00407f30(l_apdb_mutex);
      return uVar2;
    }
    if (apdb_warning_switch != 0) {
      __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar2 = 0x239e;
LAB_00607ed4:
      printf(__format,"apdb_get_dft_radio_freq_by_id",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

