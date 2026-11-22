// func rrm_ap_para_create @ 004b3130 size=472

void * rrm_ap_para_create(int param_1,undefined1 param_2)

{
  void *__s;
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  __s = (void *)FUN_00408450(0x28,0xb4);
  if (__s != (void *)0x0) {
    memset(__s,0,0x28);
    *(undefined1 *)((int)__s + 0x10) = param_2;
    *(int *)((int)__s + 0xc) = param_1;
    pvVar1 = (void *)FUN_00408450(param_1 * 0x2a,0xbc);
    *(void **)((int)__s + 0x18) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      memset(pvVar1,0,*(int *)((int)__s + 0xc) * 0x2a);
      pvVar1 = (void *)FUN_00408450(*(int *)((int)__s + 0xc) << 1,0xc4);
      *(void **)((int)__s + 0x14) = pvVar1;
      if (pvVar1 != (void *)0x0) {
        memset(pvVar1,-1,*(int *)((int)__s + 0xc) << 1);
        pvVar1 = (void *)FUN_00408450(*(undefined4 *)((int)__s + 0xc),0xcc);
        *(void **)((int)__s + 8) = pvVar1;
        if (pvVar1 != (void *)0x0) {
          memset(pvVar1,0,*(size_t *)((int)__s + 0xc));
          pvVar1 = (void *)FUN_00408450(*(int *)((int)__s + 0xc) * 0xf,0xd4);
          *(void **)((int)__s + 0x1c) = pvVar1;
          if (pvVar1 != (void *)0x0) {
            iVar3 = 0;
            memset(pvVar1,0,*(int *)((int)__s + 0xc) * 0xf);
            iVar2 = FUN_00408450(*(int *)((int)__s + 0xc) * 0xc,0xdc);
            *(int *)((int)__s + 0x20) = iVar2;
            if (iVar2 != 0) {
              for (; iVar3 < *(int *)((int)__s + 0xc); iVar3 = iVar3 + 1) {
                FUN_0051ad88(*(int *)((int)__s + 0x20) + iVar3 * 0xc);
                memset((void *)(*(int *)((int)__s + 0x1c) + iVar3 * 0xf + 3),-1,8);
              }
              iVar3 = 0;
              iVar2 = FUN_00408450(*(int *)((int)__s + 0xc) * 0xc,0xe8);
              *(int *)((int)__s + 0x24) = iVar2;
              if (iVar2 != 0) {
                for (; iVar3 < *(int *)((int)__s + 0xc); iVar3 = iVar3 + 1) {
                  FUN_0051ad88(*(int *)((int)__s + 0x24) + iVar3 * 0xc);
                }
                return __s;
              }
            }
          }
        }
      }
    }
    rrm_ap_para_destroy(__s);
    __s = (void *)0x0;
  }
  return __s;
}

