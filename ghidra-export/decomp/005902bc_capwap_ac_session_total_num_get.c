// func capwap_ac_session_total_num_get @ 005902bc size=72

undefined4 capwap_ac_session_total_num_get(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(total_num_mutex,0xffffffff);
  uVar1 = session_total_num;
  FUN_00407f30(total_num_mutex);
  return uVar1;
}

