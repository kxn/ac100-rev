// func uac_list_insert_before @ 0051b0a0 size=120

void uac_list_insert_before(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input inlist or entry invalid.\n",
             "uac_list_insert_before",0x160);
      return;
    }
  }
  else {
    *param_2 = param_1;
    param_2[1] = *(int *)(param_1 + 4);
    *(int **)(param_1 + 4) = param_2;
    *(int **)param_2[1] = param_2;
    iVar1 = *(int *)(param_1 + 8);
    param_2[2] = iVar1;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  }
  return;
}

