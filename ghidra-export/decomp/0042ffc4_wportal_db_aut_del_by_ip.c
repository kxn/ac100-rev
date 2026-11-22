// func wportal_db_aut_del_by_ip @ 0042ffc4 size=84

undefined4 wportal_db_aut_del_by_ip(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    _wportal_db_aut_del_by_ip(param_1);
    FUN_00407f30(wportal_aut_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

