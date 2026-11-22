// func wportal_db_iface_del_all @ 0042dfb8 size=156

undefined4 wportal_db_iface_del_all(void)

{
  int iVar1;
  
  iVar1 = 0;
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  do {
    if (*(char *)(iface_list + iVar1 + 0x134) != '\0') {
      memset((void *)(iface_list + iVar1),0,0x16c);
    }
    iVar1 = iVar1 + 0x16c;
  } while (iVar1 != 0x2d80);
  cmcc_iface_list_count = 0;
  FUN_00407f30(wportal_rdt_mutex);
  return 0;
}

