// func uac_list_first @ 0051ade0 size=116

int uac_list_first(int *param_1)

{
  int *piVar1;
  
  if (param_1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input head invalid.\n","uac_list_first",0xae);
    }
  }
  else {
    piVar1 = (int *)*param_1;
    if (piVar1 == param_1) {
      piVar1 = (int *)0x0;
    }
  }
  return (int)piVar1;
}

