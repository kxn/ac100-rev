// func uac_list_insert_first @ 0051afb8 size=116

void uac_list_insert_first(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input head or entry invalid.\n","uac_list_insert_first"
             ,0x116);
      return;
    }
  }
  else {
    iVar1 = *param_1;
    param_2[1] = (int)param_1;
    *param_2 = iVar1;
    *(int **)(iVar1 + 4) = param_2;
    *(int **)param_2[1] = param_2;
    param_2[2] = (int)param_1;
    param_1[2] = param_1[2] + 1;
  }
  return;
}

