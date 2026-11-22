// func _nsa_compare_func @ 0042be1c size=16

void _nsa_compare_func(int param_1,int param_2)

{
  memcmp((void *)(param_1 + 0x74),(void *)(param_2 + 0x74),6);
  return;
}

