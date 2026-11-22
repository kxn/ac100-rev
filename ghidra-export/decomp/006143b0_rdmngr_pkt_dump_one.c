// func rdmngr_pkt_dump_one @ 006143b0 size=64

void rdmngr_pkt_dump_one(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = rdmngr_dbg_idx_isset(param_2);
  if (iVar1 != 0) {
    capwap_parsed_packet_dump(param_1);
    return;
  }
  return;
}

