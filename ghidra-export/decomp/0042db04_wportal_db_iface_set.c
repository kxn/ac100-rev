// func wportal_db_iface_set @ 0042db04 size=204

undefined4 wportal_db_iface_set(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *__dest;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (void *)0x0) && (*(char *)((int)param_1 + 0x134) != '\0')) {
    iVar3 = 0;
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    do {
      __dest = (void *)(iface_list + iVar3);
      iVar2 = strncmp((char *)((int)__dest + 0x134),(char *)((int)param_1 + 0x134),0x20);
      iVar3 = iVar3 + 0x16c;
      if (iVar2 == 0) {
        memcpy(__dest,param_1,0x16c);
        break;
      }
    } while (iVar3 != 0x2d80);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

