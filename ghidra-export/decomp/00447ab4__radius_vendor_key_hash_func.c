// func _radius_vendor_key_hash_func @ 00447ab4 size=64

void _radius_vendor_key_hash_func(undefined4 *param_1)

{
  undefined4 local_10 [3];
  
  local_10[0] = *param_1;
  uac_hash_update(local_10,4,0);
  return;
}

