// func get_acs_process_state @ 004866c8 size=72

undefined4 get_acs_process_state(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(wsta_roam_pkt_chnl_mutex,0xffffffff);
  uVar1 = is_process_acs;
  FUN_00407f30(wsta_roam_pkt_chnl_mutex);
  return uVar1;
}

