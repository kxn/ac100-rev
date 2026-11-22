// func uac_list_next @ 0051aec8 size=120

int uac_list_next(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input entry invalid.\n","uac_list_next",0xe3);
    }
  }
  else {
    iVar1 = *param_1;
    if (iVar1 == param_1[2]) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

