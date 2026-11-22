// func serv_wtp_address_arg_init @ 0059a0f4 size=252

undefined4 serv_wtp_address_arg_init(int *param_1)

{
  int iVar1;
  void *pvVar2;
  size_t __n;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = cw_ac_data_size_get(), iVar1 != 0)) {
    __n = iVar1 * 0xc;
    pvVar2 = (void *)FUN_00408450(__n,0x3c5);
    *param_1 = (int)pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,__n);
      pvVar2 = (void *)FUN_00408450(__n,0x3cb);
      param_1[1] = (int)pvVar2;
      if (pvVar2 == (void *)0x0) {
        FUN_00407df0(*param_1);
      }
      else {
        memset(pvVar2,0,__n);
        for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
          FUN_0051ad88(*param_1 + iVar3 * 0xc);
          FUN_0051ad88(param_1[1] + iVar3 * 0xc);
        }
        uVar4 = 0;
        param_1[2] = 0;
        param_1[3] = 0;
      }
    }
  }
  return uVar4;
}

