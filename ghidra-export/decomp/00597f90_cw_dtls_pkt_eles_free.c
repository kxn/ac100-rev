// func cw_dtls_pkt_eles_free @ 00597f90 size=104

void cw_dtls_pkt_eles_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1 + 4), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return;
}

