// func serv_wtp_address_arg_destroy @ 0059a418 size=92

void serv_wtp_address_arg_destroy(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    serv_wtp_address_arg_clear();
    if (*param_1 == 0) {
      iVar1 = param_1[1];
    }
    else {
      FUN_00407df0();
      *param_1 = 0;
      iVar1 = param_1[1];
    }
    if (iVar1 != 0) {
      FUN_00407df0();
      param_1[1] = 0;
    }
  }
  return;
}

