// func wportal_db_rdt_set @ 0042d800 size=124

undefined4 wportal_db_rdt_set(void *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (void *)0x0) && (*(uint *)((int)param_1 + 0x134) < 0x1001)) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    memcpy((void *)(rdt_list + *(int *)((int)param_1 + 0x134) * 0x16c),param_1,0x16c);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

