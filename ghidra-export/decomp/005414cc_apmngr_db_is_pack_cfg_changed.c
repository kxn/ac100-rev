// func apmngr_db_is_pack_cfg_changed @ 005414cc size=52

bool apmngr_db_is_pack_cfg_changed(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = memcmp((void *)(param_1 + 0xa8),(void *)(param_2 + 0xa8),0xd0);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

