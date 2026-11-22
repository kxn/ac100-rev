// func _sensor_scan_bssid_hash_cmp_func @ 004e2abc size=32

bool _sensor_scan_bssid_hash_cmp_func(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,6);
  return iVar1 == 0;
}

