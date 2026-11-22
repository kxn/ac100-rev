// func cw_dtls_pkt_destroy @ 00598244 size=1

void cw_dtls_pkt_destroy(int param_1)

{
  if (param_1 != 0) {
    cw_dtls_pkt_eles_free();
    uac_mem_free_my(param_1);
    return;
  }
  return;
}

