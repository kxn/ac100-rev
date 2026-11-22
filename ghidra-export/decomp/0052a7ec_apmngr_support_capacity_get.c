// func apmngr_support_capacity_get @ 0052a7ec size=44

void apmngr_support_capacity_get(void *param_1,int param_2)

{
  int iVar1;
  
  if (0 < param_2) {
    iVar1 = 4;
    if (param_2 < 5) {
      iVar1 = param_2;
    }
    memcpy(param_1,&cap_supp,iVar1 << 2);
    return;
  }
  return;
}

