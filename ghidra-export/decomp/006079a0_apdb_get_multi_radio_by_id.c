// func apdb_get_multi_radio_by_id @ 006079a0 size=604

undefined4
apdb_get_multi_radio_by_id
          (undefined4 param_1,int param_2,uint param_3,void *param_4,undefined *param_5)

{
  int iVar1;
  undefined4 *__src;
  undefined *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_28 [3];
  
  param_3 = param_3 & 0xff;
  local_28[0] = 0;
  if ((param_3 == 0) || (param_4 == (void *)0x0)) {
    if (apdb_err_switch != 0) {
      pcVar3 = "[APDB_ERROR]%s()/line %d : input radio_id or ap_radio invalid.\n";
      uVar5 = 0x2301;
      goto LAB_00607a4c;
    }
  }
  else if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      pcVar3 = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar5 = 0x2306;
      goto LAB_00607a4c;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_28);
    if (iVar1 == 0) {
      uVar6 = param_3 - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if (*(int *)(local_28[0] + 0x10) + -1 < (int)uVar6) {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        printf("[APDB_WARNING]%s()/line %d : input radio id[%d] out of range[1,%d].\n",
               "apdb_get_multi_radio_by_id",0x2315,param_3,*(undefined4 *)(local_28[0] + 0x10));
        return 0xffffffff;
      }
      if (param_5 < (undefined *)0x2) {
        puVar4 = (undefined4 *)(*(int *)(local_28[0] + 0x28) + uVar6 * 0x114);
        __src = (undefined4 *)puVar4[0x44];
        if ((((undefined *)*puVar4 == param_5) && (__src != (undefined4 *)0x0)) ||
           ((__src != (undefined4 *)0x0 &&
            (puVar2 = (undefined *)*__src, __src = puVar4, puVar2 == param_5)))) {
          memcpy(param_4,__src,0x114);
          FUN_00407f30(l_apdb_mutex);
          return 0;
        }
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        pcVar3 = "[APDB_WARNING]%s()/line %d : freq %s has no multi radio.\n";
        param_5 = (&PTR_s_2_4GHz_00702480)[(int)param_5];
        uVar5 = 8999;
      }
      else {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        pcVar3 = "[APDB_WARNING]%s()/line %d : Illegal freq %d.\n";
        uVar5 = 0x232e;
      }
      printf(pcVar3,"apdb_get_multi_radio_by_id",uVar5,param_5);
      return 0xffffffff;
    }
    if (apdb_warning_switch != 0) {
      pcVar3 = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar5 = 0x230c;
LAB_00607a4c:
      printf(pcVar3,"apdb_get_multi_radio_by_id",uVar5);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

