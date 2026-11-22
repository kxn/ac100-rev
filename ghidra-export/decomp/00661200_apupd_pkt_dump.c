// func apupd_pkt_dump @ 00661200 size=40

void apupd_pkt_dump(int param_1)

{
  if ((param_1 != 0) && (g_apupd_pkt_switch != 0)) {
    capwap_parsed_packet_dump();
    return;
  }
  return;
}

