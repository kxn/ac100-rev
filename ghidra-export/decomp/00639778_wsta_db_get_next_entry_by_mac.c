// func wsta_db_get_next_entry_by_mac @ 00639778 size=1

undefined4 wsta_db_get_next_entry_by_mac(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_2 != (void *)0x0) {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_007cc6cc,param_1);
    if (iVar1 != 0) {
      iVar1 = FUN_00408680((int)param_2 + 0xc);
      if (iVar1 != 0) {
        uVar2 = 0;
        memcpy(param_2,(void *)(iVar1 + -0xc),0x80);
      }
    }
    FUN_00407f30(DAT_007cc6bc);
  }
  return uVar2;
}

