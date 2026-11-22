// func _apupd_firmed_model_data_cmp @ 0063e700 size=48

bool _apupd_firmed_model_data_cmp(void *param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) {
    iVar1 = memcmp(param_1,param_2,0x1c);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

