// func uac_list_last @ 0051ae54 size=116

int uac_list_last(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input head invalid.\n","uac_list_last",200);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == param_1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

