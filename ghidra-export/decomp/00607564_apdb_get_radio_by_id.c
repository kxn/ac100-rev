// func apdb_get_radio_by_id @ 00607564 size=552

undefined4
apdb_get_radio_by_id(undefined4 param_1,int param_2,uint param_3,void *param_4,uint param_5)

{
  int iVar1;
  char *__format;
  uint *__src;
  undefined4 uVar2;
  uint uVar3;
  int local_28 [3];
  
  param_3 = param_3 & 0xff;
  local_28[0] = 0;
  if ((param_3 == 0) || (param_4 == (void *)0x0)) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : input radio_id or ap_radio invalid.\n";
      uVar2 = 0x2281;
      goto LAB_00607610;
    }
  }
  else if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar2 = 0x2286;
      goto LAB_00607610;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_28);
    if (iVar1 == 0) {
      uVar3 = param_3 - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if (*(int *)(local_28[0] + 0x10) + -1 < (int)uVar3) {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        printf("[APDB_WARNING]%s()/line %d : input radio id[%d] out of range[1,%d].\n",
               "apdb_get_radio_by_id",0x2295,param_3,*(undefined4 *)(local_28[0] + 0x10));
        return 0xffffffff;
      }
      if (param_5 < 2) {
        __src = (uint *)(*(int *)(local_28[0] + 0x28) + uVar3 * 0x114);
        if ((*__src != param_5) &&
           ((__src = (uint *)__src[0x44], __src == (uint *)0x0 || (*__src != param_5)))) {
          FUN_00407f30(l_apdb_mutex);
          if (apdb_warning_switch == 0) {
            return 0xffffffff;
          }
          printf("[APDB_WARNING]%s()/line %d : Illegal freq %s.\n","apdb_get_radio_by_id",0x22a7,
                 (&PTR_s_2_4GHz_00702480)[param_5]);
          return 0xffffffff;
        }
      }
      else {
        __src = (uint *)(*(int *)(local_28[0] + 0x28) + uVar3 * 0x114);
      }
      memcpy(param_4,__src,0x114);
      FUN_00407f30(l_apdb_mutex);
      return 0;
    }
    if (apdb_warning_switch != 0) {
      __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar2 = 0x228c;
LAB_00607610:
      printf(__format,"apdb_get_radio_by_id",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

