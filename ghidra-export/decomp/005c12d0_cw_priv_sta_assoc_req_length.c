// func cw_priv_sta_assoc_req_length @ 005c12d0 size=48

uint cw_priv_sta_assoc_req_length(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = 0xc;
    if (*(int *)(param_1 + 8) < 0) {
      iVar2 = 0x10;
    }
    uVar1 = iVar2 + *(int *)(param_1 + 0xc) & 0xffff;
  }
  return uVar1;
}

