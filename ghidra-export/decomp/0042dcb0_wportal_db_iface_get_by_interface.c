// func wportal_db_iface_get_by_interface @ 0042dcb0 size=1

undefined4 wportal_db_iface_get_by_interface(char *param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *__src;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_2 != (void *)0x0) && (param_1 != (char *)0x0)) {
    iVar3 = 0;
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    do {
      __src = (void *)(iface_list + iVar3);
      iVar2 = strncmp((char *)((int)__src + 0x134),param_1,0x20);
      iVar3 = iVar3 + 0x16c;
      if (iVar2 == 0) {
        memcpy(param_2,__src,0x16c);
        break;
      }
    } while (iVar3 != 0x2d80);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

