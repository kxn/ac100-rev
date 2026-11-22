// func uac_id_expand @ 00519a60 size=448

undefined4 uac_id_expand(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *__dest;
  int iVar3;
  void *__s;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t __n;
  
  uVar2 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    if (param_2 < 1) {
      if (param_2 != -1) {
        return 0xffffffff;
      }
      iVar6 = param_1[5];
    }
    else {
      iVar6 = param_1[5];
    }
    uVar2 = 0xffffffff;
    if (iVar6 == param_1[4]) {
      if (param_2 == -1) {
        param_2 = iVar6;
      }
      iVar6 = iVar6 + param_2;
      __dest = (void *)uac_mem_malloc_my(iVar6 * 4,0x93);
      uVar2 = 0xffffffff;
      if (__dest != (void *)0x0) {
        memcpy(__dest,(void *)*param_1,param_1[4] << 2);
        iVar4 = 0;
        iVar3 = param_1[4];
        iVar5 = iVar3 * 4;
        for (; iVar1 = iVar4 + iVar5, iVar3 < iVar6; iVar3 = iVar3 + 1) {
          iVar4 = iVar4 + 4;
          *(int *)((int)__dest + iVar1) = iVar3;
        }
        iVar3 = param_1[4];
        __n = (iVar6 + 0x1fU >> 5) << 2;
        __s = (void *)uac_mem_malloc_my(__n,0xa0);
        if (param_1[1] == 0) {
          uac_mem_free_my(__dest);
          uac_mem_free_my(__s);
          uVar2 = 0xffffffff;
        }
        else {
          memset(__s,0,__n);
          memcpy(__s,(void *)param_1[1],(iVar3 + 0x1fU >> 5) << 2);
          param_1[3] = 0;
          param_1[2] = param_1[4];
          param_1[4] = iVar6;
          uac_mem_free_my(*param_1);
          *param_1 = __dest;
          uac_mem_free_my(param_1[1]);
          uVar2 = 0;
          param_1[1] = __s;
        }
      }
    }
  }
  return uVar2;
}

