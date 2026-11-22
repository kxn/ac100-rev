// func _radius_vendor_name_key_hash_func @ 00447984 size=76

void _radius_vendor_name_key_hash_func(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  uac_hash_update(param_1,sVar1,0);
  return;
}

