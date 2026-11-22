// func ac_packet_debug_is_open @ 005903d0 size=104

bool ac_packet_debug_is_open(int param_1)

{
  if (param_1 - 1U < 0x1a) {
    return (1 << (param_1 - 1U & 0x1f) & capwap_packet_bitmap) != 0;
  }
  if (1 < param_1 - 0x33dd01U) {
    return false;
  }
  return (1 << (param_1 + 0x19U & 0x1f) & capwap_packet_bitmap) != 0;
}

