// func _apdb_fwid_hash_cmp_func @ 005fa328 size=32

bool _apdb_fwid_hash_cmp_func(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return iVar1 == 0;
}

