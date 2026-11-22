// func rrm_ap_pwr_para_create @ 004b3458 size=444

void * rrm_ap_pwr_para_create(int param_1,undefined1 param_2)

{
  void *__s;
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  
  __s = (void *)FUN_00408450(0x40,0xf7);
  if (__s != (void *)0x0) {
    memset(__s,0,0x40);
    *(undefined1 *)((int)__s + 0x10) = param_2;
    *(int *)((int)__s + 0xc) = param_1;
    pvVar1 = (void *)FUN_00408450(param_1 * 0x12,0xff);
    *(void **)((int)__s + 0x18) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      memset(pvVar1,0,*(int *)((int)__s + 0xc) * 0x12);
      pvVar1 = (void *)FUN_00408450(*(int *)((int)__s + 0xc) << 1,0x107);
      *(void **)((int)__s + 0x14) = pvVar1;
      if (pvVar1 != (void *)0x0) {
        memset(pvVar1,-1,*(int *)((int)__s + 0xc) << 1);
        pvVar1 = (void *)FUN_00408450(*(undefined4 *)((int)__s + 0xc),0x10f);
        *(void **)((int)__s + 8) = pvVar1;
        if (pvVar1 != (void *)0x0) {
          memset(pvVar1,0,*(size_t *)((int)__s + 0xc));
          pvVar1 = (void *)FUN_00408450(*(int *)((int)__s + 0xc) * 0xf,0x117);
          *(void **)((int)__s + 0x1c) = pvVar1;
          if (pvVar1 != (void *)0x0) {
            memset(pvVar1,0,*(int *)((int)__s + 0xc) * 0xf);
            iVar3 = *(int *)((int)__s + 0xc);
            pvVar1 = __s;
            while( true ) {
              uVar2 = FUN_00408450(iVar3 * 0xc,0x121);
              *(undefined4 *)((int)pvVar1 + 0x20) = uVar2;
              for (iVar3 = 0; iVar3 < *(int *)((int)__s + 0xc); iVar3 = iVar3 + 1) {
                FUN_0051ad88(*(int *)((int)pvVar1 + 0x20) + iVar3 * 0xc);
              }
              pvVar1 = (void *)((int)pvVar1 + 4);
              if (pvVar1 == (void *)((int)__s + 0x20)) break;
              iVar3 = *(int *)((int)__s + 0xc);
            }
            for (iVar3 = 0; iVar3 < *(int *)((int)__s + 0xc); iVar3 = iVar3 + 1) {
              memset((void *)(*(int *)((int)__s + 0x1c) + iVar3 * 0xf + 3),-1,8);
            }
            return __s;
          }
        }
      }
    }
    rrm_ap_pwr_para_destroy(__s);
    __s = (void *)0x0;
  }
  return __s;
}

