// func wportal_db_iface_rdt_get_first_cmcc @ 0042df28 size=144

undefined4 wportal_db_iface_rdt_get_first_cmcc(void *param_1)

{
  int iVar1;
  void *__src;
  
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  iVar1 = 0x20;
  __src = iface_list;
  while ((*(char *)((int)__src + 0x134) == '\0' || (*(int *)((int)__src + 0x15c) != 0x20))) {
    iVar1 = iVar1 + -1;
    __src = (void *)((int)__src + 0x16c);
    if (iVar1 == 0) {
      FUN_00407f30(wportal_rdt_mutex);
      return 0xffffffff;
    }
  }
  memcpy(param_1,__src,0x16c);
  FUN_00407f30(wportal_rdt_mutex);
  return 0;
}

