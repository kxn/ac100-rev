// func rrm_reset_ap_pwr_para_all @ 004ad18c size=76

void rrm_reset_ap_pwr_para_all(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &ap_pwr_para;
  iVar1 = ap_pwr_para;
  while( true ) {
    piVar2 = piVar2 + 1;
    if (iVar1 != 0) {
      rrm_ap_pwr_para_reset();
    }
    if (piVar2 == &ap_para) break;
    iVar1 = *piVar2;
  }
  return;
}

