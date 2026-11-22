// func apdb_set_supprt_160m_to_radio @ 0060778c size=532

undefined4
apdb_set_supprt_160m_to_radio
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined *param_4,undefined4 param_5)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int local_20 [2];
  
  param_3 = param_3 & 0xff;
  local_20[0] = 0;
  if (param_3 == 0) {
    if (apdb_err_switch != 0) {
      pcVar2 = "[APDB_ERROR]%s()/line %d : input radio_id or ap_radio invalid.\n";
      uVar3 = 0x22bd;
LAB_00607838:
      printf(pcVar2,"apdb_set_supprt_160m_to_radio",uVar3);
      return 0xffffffff;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_20);
    if (iVar1 == 0) {
      uVar4 = param_3 - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if (*(int *)(local_20[0] + 0x10) + -1 < (int)uVar4) {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        printf("[APDB_WARNING]%s()/line %d : input radio id[%d] out of range[1,%d].\n",
               "apdb_set_supprt_160m_to_radio",0x22cc,param_3,*(undefined4 *)(local_20[0] + 0x10));
        return 0xffffffff;
      }
      if ((undefined *)0x1 < param_4) {
        FUN_00407f30(l_apdb_mutex);
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        pcVar2 = "[APDB_WARNING]%s()/line %d : Illegal freq %d.\n";
        uVar3 = 0x22e5;
LAB_006078b8:
        printf(pcVar2,"apdb_set_supprt_160m_to_radio",uVar3,param_4);
        return 0xffffffff;
      }
      puVar5 = (undefined4 *)(*(int *)(local_20[0] + 0x28) + uVar4 * 0x114);
      if ((undefined *)*puVar5 == param_4) {
        puVar5[3] = param_5;
      }
      else {
        puVar5 = (undefined4 *)puVar5[0x44];
        if ((puVar5 == (undefined4 *)0x0) || ((undefined *)*puVar5 != param_4)) {
          FUN_00407f30(l_apdb_mutex);
          if (apdb_warning_switch == 0) {
            return 0xffffffff;
          }
          pcVar2 = "[APDB_WARNING]%s()/line %d : Illegal freq %s.\n";
          param_4 = (&PTR_s_2_4GHz_00702480)[(int)param_4];
          uVar3 = 0x22de;
          goto LAB_006078b8;
        }
        puVar5[3] = param_5;
      }
      FUN_00407f30(l_apdb_mutex);
      return 0;
    }
    if (apdb_warning_switch != 0) {
      pcVar2 = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar3 = 0x22c3;
      goto LAB_00607838;
    }
  }
  return 0xffffffff;
}

