// func apmngr_hdap_check @ 005482a4 size=68

bool apmngr_hdap_check(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = apmngr_hdap_get_direct(param_2,param_3);
  bVar2 = false;
  if ((iVar1 != 0) && (param_1 != 0)) {
    bVar2 = iVar1 == param_1;
  }
  return bVar2;
}

