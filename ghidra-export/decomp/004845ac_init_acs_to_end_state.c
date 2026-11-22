// func init_acs_to_end_state @ 004845ac size=64

void init_acs_to_end_state(void)

{
  FUN_004082d0(wsta_roam_pkt_chnl_mutex,0xffffffff);
  is_process_acs = 0;
  acs_ap_cnt = 0;
  FUN_00407f30(wsta_roam_pkt_chnl_mutex);
  return;
}

