// func apmngr_hdap_get_direct @ 00548264 size=64

undefined4 apmngr_hdap_get_direct(void *param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) {
    iVar2 = memcmp(param_1,param_2,6);
    uVar1 = 1;
    if ((-1 < iVar2) && (uVar1 = 2, iVar2 == 0)) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

