// func uac_list_move @ 0051b274 size=208

void uac_list_move(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (uac_list_err_switch != 0) {
      printf("[UAC_LIST_ERROR]%s()/line %d : Input inlist or outlist invalid.\n","uac_list_move",
             0x1eb);
      return;
    }
  }
  else {
    while (iVar1 = uac_list_first(param_2), iVar1 != 0) {
      uac_list_remove(iVar1);
      uac_list_insert_last(param_1,iVar1);
    }
  }
  return;
}

