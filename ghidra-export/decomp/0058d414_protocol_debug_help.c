// func protocol_debug_help @ 0058d414 size=1

void protocol_debug_help(void)

{
  puts("Protocol Interface Helper:");
  puts("\tcw_ac_dump():\tdump session count of every thread.");
  puts("\tcw_ac_detail_dump():\tdump every session\'s infomation of every thread.");
  puts("\tcw_ac_stat_dump():\tdump statistics of each thread,like echo_timeout_num.");
  puts("\tcw_ac_stat_reset():\treset statistics of each thread.");
  puts("\tcw_ac_queue_dump():\tdump packet count in capwap queue of every thread.");
  puts("\tcw_ac_profile_dump():\tdump protocol\'s profile infomation.");
  puts("\tcw_ac_packet_bitmap_help():\tsee the bitmap-packat corresponding table.");
  puts("\tcw_ac_packet_bitmap_disable():\tdisable dumping packet/buffer of the target type.");
  puts("\tcw_ac_packet_bitmap_enable():\tenable dumping packet/buffer of the target type.");
  puts("\tcw_ac_packet_bitmap_reset():\tenable dumping all the packet/buffer.");
  puts("\tcw_ac_debug_ap_reset():\tenable dumping all AP\'s packet/buffer/information.");
  puts("Protocol Switch Helper:");
  puts("\tcapwap_debug_switch:\tlevel[DEBUG]\'s switch.");
  puts("\tcapwap_warning_switch:\tlevel[WARNING]\'s switch.");
  puts("\tcapwap_err_switch:\tlevel[ERROR]\'s switch.");
  puts("\tcapwap_packet_switch:\tdumping all packet\'s switch.");
  puts("\tcapwap_recv_packet_switch:\tdumping received packet\'s switch.");
  puts("\tcapwap_send_packet_switch:\tdumping sent packet\'s switch.");
  puts("\tcapwap_buffer_switch:\tdumping all packet buffer\'s switch.");
  puts("\tcapwap_recv_buffer_switch:\tdumping received packet buffer\'s switch.");
  puts("\tcapwap_send_buffer_switch:\tdumping sent packet buffer\'s switch.");
  puts("\tcapwap_dtls_enable_switch:\tenable/disable dtls.");
  puts("\tcapwap_packet_rate_switch:\tdump packet process rate of every thread.");
  puts("\tcapwap_fsm_debug_switch:\tcapwap FSM\'s level[DEBUG] switch.");
  puts("\tcapwap_fsm_err_switch:\tcapwap FSM\'s level[ERROR] switch.");
  puts(
      "\tcapwap_packet_bitmap:\tset the packet need to be dump when the packet/buffer switch is open."
      );
  puts("\tsession_total_num:\ttotal num of all sessions.");
  puts("\tdebug_ip:\tto set debug AP ip,if set,you will only see debug info of target AP.");
  puts("\tdebug_port:\tto set debug AP port,if set,you will only see debug info of target AP.");
  puts("\tset_tftp_addr(u_int8_t *ip str):\tset_tftp_server to output pkt snapshot.");
  puts("\tclose_tftp_server:\tstop tftp_server to output pkt snapshot.");
  puts("\tstart_collect_snapshot:\tbegin collect pkt snapshot.");
  (*(code *)PTR_puts_00758f90)("\tclose_collect_snapshot:\tclose collect pkt snapshot.");
  return;
}

