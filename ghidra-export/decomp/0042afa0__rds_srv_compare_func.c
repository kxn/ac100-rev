// func _rds_srv_compare_func @ 0042afa0 size=16

int _rds_srv_compare_func(int *param_1,int param_2)

{
  return *param_1 - *(int *)(param_2 + 0x108);
}

