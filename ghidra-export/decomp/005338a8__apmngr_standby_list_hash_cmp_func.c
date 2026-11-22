// func _apmngr_standby_list_hash_cmp_func @ 005338a8 size=32

bool _apmngr_standby_list_hash_cmp_func(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,6);
  return iVar1 == 0;
}

