// func cw_parsed_pkt_destroy @ 005888f4 size=64

void cw_parsed_pkt_destroy(int param_1)

{
  if (param_1 != 0) {
    cw_msg_eles_free();
    FUN_00407df0(param_1);
    return;
  }
  return;
}

