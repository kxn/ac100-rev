// func rrm_destroy_ap_para_all @ 004ad0e4 size=84

void rrm_destroy_ap_para_all(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &ap_para;
  iVar1 = ap_para;
  while( true ) {
    if (iVar1 != 0) {
      rrm_ap_para_destroy();
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    if (piVar2 == (int *)&g_rrm_cb_list) break;
    iVar1 = *piVar2;
  }
  return;
}

