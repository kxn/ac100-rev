// func cw_dtls_pkt_ele_get @ 00598828 size=116

undefined4 cw_dtls_pkt_ele_get(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    switch(param_2) {
    case 0:
      uVar1 = cw_dtls_pkt_ch_get();
      return uVar1;
    case 1:
      uVar1 = cw_dtls_pkt_hvr_get();
      return uVar1;
    case 2:
      uVar1 = cw_dtls_pkt_sh_get();
      return uVar1;
    case 3:
      uVar1 = cw_dtls_pkt_cert_get();
      return uVar1;
    case 4:
      uVar1 = cw_dtls_pkt_shd_get();
      return uVar1;
    case 5:
      uVar1 = cw_dtls_pkt_ke_get();
      return uVar1;
    case 6:
      uVar1 = cw_dtls_pkt_cc_get();
      return uVar1;
    case 7:
      uVar1 = cw_dtls_pkt_chm_get();
      return uVar1;
    }
  }
  return 0;
}

