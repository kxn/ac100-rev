// func cloud_mngt_client_cmp_func @ 0048d628 size=48

bool cloud_mngt_client_cmp_func(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    iVar1 = memcmp((void *)(param_1 + 4),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

