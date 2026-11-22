// func cw_dtls_pkt_cc_get @ 0059876c size=84

int cw_dtls_pkt_cc_get(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_004081b0(param_1 + 4), iVar2 != 0)) {
    cVar1 = *(char *)(iVar2 + 0xc);
    while ((cVar1 != '\x14' && (iVar2 = FUN_00408680(iVar2), iVar2 != 0))) {
      cVar1 = *(char *)(iVar2 + 0xc);
    }
  }
  return iVar2;
}

