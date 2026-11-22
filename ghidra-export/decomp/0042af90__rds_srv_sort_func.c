// func _rds_srv_sort_func @ 0042af90 size=16

int _rds_srv_sort_func(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x108) - *(int *)(param_2 + 0x108);
}

