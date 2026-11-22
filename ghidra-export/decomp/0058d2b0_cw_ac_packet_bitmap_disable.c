// func cw_ac_packet_bitmap_disable @ 0058d2b0 size=1

void cw_ac_packet_bitmap_disable(uint param_1)

{
  if (param_1 < 0x20) {
    capwap_packet_bitmap = ~(1 << (param_1 & 0x1f)) & capwap_packet_bitmap;
  }
  return;
}

