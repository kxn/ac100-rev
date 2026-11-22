// func _wportal_dm_calling_station_cmp_func @ 0042bdfc size=32

bool _wportal_dm_calling_station_cmp_func(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,6);
  return iVar1 == 0;
}

