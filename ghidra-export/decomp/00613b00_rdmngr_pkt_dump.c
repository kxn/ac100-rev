// func rdmngr_pkt_dump @ 00613b00 size=40

void rdmngr_pkt_dump(int param_1)

{
  if ((param_1 != 0) && (rdmngr_pkt_dump_switch != 0)) {
    capwap_parsed_packet_dump();
    return;
  }
  return;
}

