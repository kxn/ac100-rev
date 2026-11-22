// func wportal_db_rdt_del @ 0042d87c size=112

undefined4 wportal_db_rdt_del(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0x1001) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    memset((void *)(rdt_list + param_1 * 0x16c),0,0x16c);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

