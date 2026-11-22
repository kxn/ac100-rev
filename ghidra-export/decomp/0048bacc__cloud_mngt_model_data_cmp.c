// func _cloud_mngt_model_data_cmp @ 0048bacc size=40

bool _cloud_mngt_model_data_cmp(int param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    bVar1 = *(int *)(param_1 + 0xc) == *param_2;
  }
  return bVar1;
}

