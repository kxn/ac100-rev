// func wportal_db_iface_add @ 0042da48 size=188

undefined4 wportal_db_iface_add(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *__dest;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (void *)0x0) && (*(char *)((int)param_1 + 0x134) != '\0')) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    iVar2 = 0;
    do {
      __dest = (void *)(iface_list + iVar2);
      iVar2 = iVar2 + 0x16c;
      if (*(char *)((int)__dest + 0x134) == '\0') {
        memcpy(__dest,param_1,0x16c);
        if (*(int *)((int)__dest + 0x15c) == 0x20) {
          cmcc_iface_list_count = cmcc_iface_list_count + 1;
        }
        break;
      }
    } while (iVar2 != 0x2d80);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

