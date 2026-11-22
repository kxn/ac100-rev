// func wsta_roam_chnl_cmp_func @ 00485fc0 size=48

bool wsta_roam_chnl_cmp_func(char *param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    iVar1 = strcmp(param_1,param_2);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

