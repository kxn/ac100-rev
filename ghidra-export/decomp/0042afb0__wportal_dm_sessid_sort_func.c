// func _wportal_dm_sessid_sort_func @ 0042afb0 size=16

int _wportal_dm_sessid_sort_func(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x164) - *(int *)(param_2 + 0x164);
}

