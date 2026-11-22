// func wportal_db_iface_rdt_get @ 0042de60 size=200

undefined4 wportal_db_iface_rdt_get(char *param_1,void *param_2)

{
  int iVar1;
  void *__src;
  int iVar2;
  
  iVar2 = 0;
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  do {
    __src = (void *)(iface_list + iVar2);
    iVar1 = strcmp((char *)((int)__src + 0x134),param_1);
    iVar2 = iVar2 + 0x16c;
    if (iVar1 == 0) {
      memcpy(param_2,__src,0x16c);
      FUN_00407f30(wportal_rdt_mutex);
      return 0;
    }
  } while (iVar2 != 0x2d80);
  FUN_00407f30(wportal_rdt_mutex);
  return 0xffffffff;
}

