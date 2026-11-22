// func apmngr_apdb_update_proc @ 0052a0f8 size=60

undefined4
apmngr_apdb_update_proc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  apmngr_db_foreach_proc(0xffffffff,_apmngr_model_valid_check,&local_18);
  return 0;
}

