// func apupd_db_model_real_state_get @ 00652a10 size=272

int apupd_db_model_real_state_get(int param_1,int *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (g_apupd_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0x1b0e;
  }
  else {
    if (*param_2 == 1) {
      return *(int *)(param_1 + 0x140);
    }
    if (*param_2 == 0) {
      iVar1 = *(int *)(param_1 + 0x140);
      if (iVar1 - 1U < 2) {
        return 5;
      }
      if (iVar1 != 3) {
        return iVar1;
      }
      iVar1 = FUN_004081b0(param_1 + 0x7f4);
      while( true ) {
        if (iVar1 == 0) {
          return 5;
        }
        if (*(int *)(iVar1 + 0x48) - 6U < 2) break;
        iVar1 = FUN_00408680(iVar1);
      }
      return 3;
    }
    if (g_apupd_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    __format = "[APUPD_ERROR]%32s() %05d: some error occured.\r\n";
    uVar2 = 0x1b36;
  }
  printf(__format,"apupd_db_model_real_state_get",uVar2);
  return -1;
}

