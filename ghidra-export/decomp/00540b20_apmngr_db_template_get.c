// func apmngr_db_template_get @ 00540b20 size=136

undefined4 apmngr_db_template_get(undefined4 param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined4 local_res0 [4];
  
  uVar1 = 0xffffffff;
  local_res0[0] = param_1;
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  __src = (void *)FUN_00407fa0(g_apmngr_template_hash,local_res0);
  if ((__src != (void *)0x0) && (uVar1 = 0, param_2 != (void *)0x0)) {
    memcpy(param_2,__src,0x2d8);
  }
  FUN_00407f30(apmngr_db_mutex);
  return uVar1;
}

