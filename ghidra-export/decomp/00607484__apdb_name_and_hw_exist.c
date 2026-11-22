// func _apdb_name_and_hw_exist @ 00607484 size=224

undefined4 _apdb_name_and_hw_exist(undefined4 param_1,void *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *__s1;
  undefined1 auStack_180 [348];
  uint local_24;
  int local_20;
  int local_1c;
  
  memset(auStack_180,0,0x168);
  iVar1 = apdb_get_ap_by_name_and_hwver(param_1,param_2,auStack_180);
  uVar3 = 0;
  if (iVar1 != -1) {
    iVar1 = 0;
    do {
      while( true ) {
        while( true ) {
          if (local_20 <= iVar1) {
            return 0;
          }
          __s1 = (void *)(local_1c + iVar1 * 0x38);
          iVar2 = memcmp(__s1,param_2,4);
          if (iVar2 == 0) break;
          iVar1 = iVar1 + 1;
        }
        if ((int)(param_3 & 0xff) < (int)local_24) {
          return 1;
        }
        if ((param_3 & 0xff) == local_24) break;
        iVar1 = iVar1 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (*(int *)((int)__s1 + 0x20) == 0);
    uVar3 = 1;
  }
  return uVar3;
}

