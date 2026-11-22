// func wsta_db_get_first_entry @ 006396e4 size=1

undefined4 wsta_db_get_first_entry(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_1 != (void *)0x0) {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    if (DAT_007cc6e0 != 0) {
      iVar1 = FUN_004081b0(&DAT_007cc6d8);
      if (iVar1 != 0) {
        memcpy(param_1,(void *)(iVar1 + -0xc),0x80);
        uVar2 = 0;
      }
    }
    FUN_00407f30(DAT_007cc6bc);
  }
  return uVar2;
}

