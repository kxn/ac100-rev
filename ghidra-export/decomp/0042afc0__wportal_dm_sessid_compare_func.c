// func _wportal_dm_sessid_compare_func @ 0042afc0 size=16

int _wportal_dm_sessid_compare_func(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) - *(int *)(param_2 + 0x164);
}

