// func wportal_db_rdt_get_by_vlan @ 0042d8ec size=128

undefined4 wportal_db_rdt_get_by_vlan(uint param_1,void *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_2 != (void *)0x0) && (param_1 < 0x1001)) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    memcpy(param_2,(void *)(rdt_list + param_1 * 0x16c),0x16c);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

