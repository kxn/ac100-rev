// func is_cw_dtls_keoccoehm @ 005988f8 size=100

bool is_cw_dtls_keoccoehm(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  iVar1 = cw_dtls_pkt_ele_get(param_1,5);
  if ((iVar1 == 0) && (iVar1 = cw_dtls_pkt_ele_get(param_1,6), iVar1 == 0)) {
    iVar1 = cw_dtls_pkt_ele_get(param_1,7);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

