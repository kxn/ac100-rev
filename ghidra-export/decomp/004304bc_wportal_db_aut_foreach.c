// func wportal_db_aut_foreach @ 004304bc size=168

undefined4 wportal_db_aut_foreach(code *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (code *)0x0) {
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    iVar1 = FUN_004081b0(aut_list);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1);
      (*param_1)(iVar1,param_2);
      iVar1 = iVar2;
    }
    FUN_00407f30(wportal_aut_mutex);
  }
  return 0;
}

