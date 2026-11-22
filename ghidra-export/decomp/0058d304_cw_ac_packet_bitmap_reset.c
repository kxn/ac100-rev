// func cw_ac_packet_bitmap_reset @ 0058d304 size=1

void cw_ac_packet_bitmap_reset(void)

{
  capwap_packet_bitmap = 0xfffffff;
  return;
}

