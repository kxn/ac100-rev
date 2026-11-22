// func mesh_pkt_dump @ 004c0600 size=40

void mesh_pkt_dump(int param_1)

{
  if ((param_1 != 0) && (mesh_pkt_dump_switch != '\0')) {
    capwap_parsed_packet_dump();
    return;
  }
  return;
}

