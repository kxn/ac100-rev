// func _radius_attr_name_hash_cmp_func @ 00447868 size=52

bool _radius_attr_name_hash_cmp_func(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = strcasecmp(param_1,param_2);
  return iVar1 == 0;
}

