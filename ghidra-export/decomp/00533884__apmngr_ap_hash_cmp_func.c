// func _apmngr_ap_hash_cmp_func @ 00533884 size=36

bool _apmngr_ap_hash_cmp_func(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp((void *)(param_1 + 0x48),param_2,6);
  return iVar1 == 0;
}

