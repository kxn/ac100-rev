// func wips_whitelist_get @ 004cbc10 size=292

undefined4 wips_whitelist_get(void *param_1,char *param_2,int param_3,int param_4,void *param_5)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_4 != 0) {
    FUN_004082d0(wips_global_mutex,0xffffffff);
    __src = (void *)FUN_004081b0(&g_white_list);
    if (__src == (void *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      do {
        if (param_4 == 1) {
          iVar1 = memcmp((void *)((int)__src + 0x10),param_1,6);
          if (iVar1 == 0) goto LAB_004cbd20;
        }
        else if (((param_4 == 2) &&
                 (iVar1 = strcmp((char *)((int)__src + 0x16),param_2), iVar1 == 0)) &&
                (*(int *)((int)__src + 0x48) == param_3)) {
LAB_004cbd20:
          memcpy(param_5,__src,0x5c);
          uVar2 = 0;
          goto LAB_004cbcd0;
        }
        __src = (void *)FUN_00408680(__src);
      } while (__src != (void *)0x0);
      uVar2 = 0xffffffff;
    }
LAB_004cbcd0:
    FUN_00407f30(wips_global_mutex);
  }
  return uVar2;
}

