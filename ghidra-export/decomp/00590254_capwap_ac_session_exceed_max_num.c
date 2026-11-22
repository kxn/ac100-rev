// func capwap_ac_session_exceed_max_num @ 00590254 size=104

bool capwap_ac_session_exceed_max_num(int param_1)

{
  bool bVar1;
  
  FUN_004082d0(total_num_mutex,0xffffffff);
  bVar1 = param_1 <= session_total_num;
  if (bVar1) {
    FUN_00407f30(total_num_mutex);
  }
  else {
    FUN_00407f30(total_num_mutex);
  }
  return bVar1;
}

