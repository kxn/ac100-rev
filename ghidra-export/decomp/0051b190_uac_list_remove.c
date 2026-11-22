// func uac_list_remove @ 0051b190 size=120

void uac_list_remove(int *param_1)

{
  if (param_1 == (int *)0x0) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input entry invalid.\n","uac_list_remove",0x1ad);
      return;
    }
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    *(int *)(param_1[2] + 8) = *(int *)(param_1[2] + 8) + -1;
    param_1[2] = 0;
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}

