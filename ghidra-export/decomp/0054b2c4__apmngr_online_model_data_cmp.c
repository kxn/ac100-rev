// func _apmngr_online_model_data_cmp @ 0054b2c4 size=48

bool _apmngr_online_model_data_cmp(void *param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) {
    iVar1 = memcmp(param_1,param_2,0x18);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

