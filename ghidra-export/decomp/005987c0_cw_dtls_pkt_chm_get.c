// func cw_dtls_pkt_chm_get @ 005987c0 size=104

int cw_dtls_pkt_chm_get(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_004081b0(param_1 + 4), iVar2 != 0)) {
    cVar1 = *(char *)(iVar2 + 0xc);
    while (((cVar1 != '\x16' || (*(short *)(iVar2 + 0x10) != 1)) &&
           (iVar2 = FUN_00408680(iVar2), iVar2 != 0))) {
      cVar1 = *(char *)(iVar2 + 0xc);
    }
  }
  return iVar2;
}

