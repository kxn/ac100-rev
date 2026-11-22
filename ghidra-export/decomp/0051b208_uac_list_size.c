// func uac_list_size @ 0051b208 size=108

undefined4 uac_list_size(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input head invalid.\n","uac_list_size",0x1cf);
    }
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  return uVar1;
}

