// func uac_list_init @ 0051ad90 size=80

void uac_list_init(int param_1)

{
  if (param_1 == 0) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input head invalid.\n","uac_list_init",0x4f);
      return;
    }
  }
  else {
    *(int *)param_1 = param_1;
    *(int *)(param_1 + 4) = param_1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

