// func cw_ac_packet_bitmap_enable @ 0058d2dc size=1

void cw_ac_packet_bitmap_enable(uint param_1)

{
  if (param_1 < 0x20) {
    capwap_packet_bitmap = 1 << (param_1 & 0x1f) | capwap_packet_bitmap;
  }
  return;
}

