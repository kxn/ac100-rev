// func uac_list_insert_after @ 0051b118 size=120

void uac_list_insert_after(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input inlist or entry invalid.\n",
             "uac_list_insert_after",0x188);
      return;
    }
  }
  else {
    param_2[1] = (int)param_1;
    iVar1 = *param_1;
    *param_2 = iVar1;
    *(int **)(iVar1 + 4) = param_2;
    *(int **)param_2[1] = param_2;
    iVar1 = param_1[2];
    param_2[2] = iVar1;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  }
  return;
}

