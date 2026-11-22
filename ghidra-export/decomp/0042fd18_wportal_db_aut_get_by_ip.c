// func wportal_db_aut_get_by_ip @ 0042fd18 size=140

int wportal_db_aut_get_by_ip(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = -1;
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    iVar1 = _wportal_db_aut_get_by_ip(param_1,param_2);
    if (iVar1 == 0) {
      FUN_00407f30(wportal_aut_mutex);
      iVar1 = 0;
    }
    else {
      FUN_00407f30(wportal_aut_mutex);
    }
  }
  return iVar1;
}

