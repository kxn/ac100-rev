// func wportal_db_cmcc_del_serialno @ 0043330c size=76

undefined4 wportal_db_cmcc_del_serialno(undefined2 param_1)

{
  FUN_004082d0(wportal_cmcc_serialno_mutex,0xffffffff);
  _wportal_db_cmcc_del_serialno(param_1);
  FUN_00407f30(wportal_cmcc_serialno_mutex);
  return 0;
}

