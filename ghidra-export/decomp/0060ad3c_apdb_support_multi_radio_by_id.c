// func apdb_support_multi_radio_by_id @ 0060ad3c size=340

bool apdb_support_multi_radio_by_id(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  char *__format;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int local_20 [3];
  
  local_20[0] = 0;
  if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar3 = 0x29e0;
      goto LAB_0060ae34;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_20);
    if (iVar1 == 0) {
      uVar5 = (param_3 & 0xff) - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if ((*(int *)(local_20[0] + 0x10) - 1U & 0xff) < uVar5) {
        bVar4 = false;
        if (apdb_warning_switch != 0) {
          printf("[APDB_WARNING]%s()/line %d : input radio id[%d] out of range[1,%d].\n",
                 "apdb_support_multi_radio_by_id",0x29ee,param_3 & 0xff,*(int *)(local_20[0] + 0x10)
                );
        }
      }
      else {
        piVar6 = (int *)(*(int *)(local_20[0] + 0x28) + uVar5 * 0x114);
        piVar2 = (int *)piVar6[0x44];
        bVar4 = false;
        if (piVar2 != (int *)0x0) {
          bVar4 = *piVar2 != *piVar6;
        }
      }
      FUN_00407f30(l_apdb_mutex);
      return bVar4;
    }
    if (apdb_warning_switch != 0) {
      __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar3 = 0x29e6;
LAB_0060ae34:
      printf(__format,"apdb_support_multi_radio_by_id",uVar3);
      return false;
    }
  }
  return false;
}

