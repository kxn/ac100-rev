// func cw_ac_enable_packet_handler @ 0058b100 size=92

void cw_ac_enable_packet_handler(void)

{
  int iVar1;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d ---->cw_ac_enable_packet_handler()\n","cw_ac_enable_packet_handler"
           ,0x14c);
  }
  pkt_handler_switch = 1;
  return;
}

