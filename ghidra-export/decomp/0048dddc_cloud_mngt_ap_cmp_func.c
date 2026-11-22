// func cloud_mngt_ap_cmp_func @ 0048dddc size=48

bool cloud_mngt_ap_cmp_func(int param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    iVar1 = strcmp((char *)(param_1 + 4),param_2);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

