// func wportal_db_iface_del @ 0042dbd0 size=224

undefined4 wportal_db_iface_del(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *__s;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar3 = 0;
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    do {
      __s = (void *)(iface_list + iVar3);
      iVar2 = strncmp((char *)((int)__s + 0x134),param_1,0x20);
      iVar3 = iVar3 + 0x16c;
      if (iVar2 == 0) {
        if (*(int *)((int)__s + 0x15c) == 0x20) {
          cmcc_iface_list_count = cmcc_iface_list_count + -1;
        }
        memset(__s,0,0x16c);
        break;
      }
    } while (iVar3 != 0x2d80);
    FUN_00407f30(wportal_rdt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

