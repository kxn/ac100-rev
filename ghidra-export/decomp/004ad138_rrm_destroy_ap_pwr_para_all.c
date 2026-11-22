// func rrm_destroy_ap_pwr_para_all @ 004ad138 size=84

void rrm_destroy_ap_pwr_para_all(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &ap_pwr_para;
  iVar1 = ap_pwr_para;
  while( true ) {
    if (iVar1 != 0) {
      rrm_ap_pwr_para_destroy();
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    if (piVar2 == &ap_para) break;
    iVar1 = *piVar2;
  }
  return;
}

