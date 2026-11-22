// func rrm_pkt_dump @ 004aae18 size=40

void rrm_pkt_dump(int param_1)

{
  if ((param_1 != 0) && (rrm_pkt_dump_switch != 0)) {
    capwap_parsed_packet_dump();
    return;
  }
  return;
}

