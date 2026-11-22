// func _sensor_db_vap_hash_cmp_func @ 004cfb54 size=32

bool _sensor_db_vap_hash_cmp_func(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,6);
  return iVar1 == 0;
}

