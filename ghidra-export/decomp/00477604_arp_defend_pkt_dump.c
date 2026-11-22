// func arp_defend_pkt_dump @ 00477604 size=40

void arp_defend_pkt_dump(int param_1)

{
  if ((param_1 != 0) && (arp_defend_pkt_dump_switch != 0)) {
    capwap_parsed_packet_dump();
    return;
  }
  return;
}

