// func uac_list_prev @ 0051af40 size=120

int uac_list_prev(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input entry invalid.\n","uac_list_prev",0xfd);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == *(int *)(param_1 + 8)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

