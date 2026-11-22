// func _wportal_free_strategy_packet_timer_handler @ 00415868 size=160

void _wportal_free_strategy_packet_timer_handler(void)

{
  int iVar1;
  
  _wportal_common_free_strategy_send();
  free_strategy_timer =
       FUN_00408340(free_strategy_interval,0,_wportal_free_strategy_packet_timer_handler,0,0,
                    "_wportal_free_strategy_packet_timer_handler",0x18d3);
  if (((free_strategy_timer == -1) && (wportal_err_switch != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_ERR]%s()/%d add free strategy packet timer failed!\n",
           "_wportal_free_strategy_packet_timer_handler",0x18d5);
    return;
  }
  return;
}

