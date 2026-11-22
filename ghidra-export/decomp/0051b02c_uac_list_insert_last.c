// func uac_list_insert_last @ 0051b02c size=116

void uac_list_insert_last(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input head or entry invalid.\n","uac_list_insert_last",
             0x13a);
      return;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    *param_2 = param_1;
    param_2[1] = iVar1;
    *(int **)(param_1 + 4) = param_2;
    *(int **)param_2[1] = param_2;
    param_2[2] = param_1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return;
}

