// func wportal_debug_aut_traverse_dump @ 00435ab4 size=1

void wportal_debug_aut_traverse_dump(void)

{
  byte bVar1;
  int iVar2;
  
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  iVar2 = FUN_004081b0(aut_list);
  if (iVar2 != 0) {
    bVar1 = *(byte *)(iVar2 + 0xf);
    while( true ) {
      printf("%02x:%02x:%02x:%02x:%02x:%02x\t",(uint)*(byte *)(iVar2 + 0xc),
             (uint)*(byte *)(iVar2 + 0xd),(uint)*(byte *)(iVar2 + 0xe),(uint)bVar1,
             (uint)*(byte *)(iVar2 + 0x10),(uint)*(byte *)(iVar2 + 0x11));
      wportal_get_mode();
      printf("%d\t%d\t%d\t%d-%d-%d %d:%d:%d\t%s\t%s\t%s\t%d\t%d\n",*(undefined4 *)(iVar2 + 0x14),
             (uint)*(byte *)(iVar2 + 0x80),*(undefined4 *)(iVar2 + 0x3c),
             (uint)*(ushort *)(iVar2 + 0x108),(uint)*(byte *)(iVar2 + 0x10a),
             (uint)*(byte *)(iVar2 + 0x10b),(uint)*(byte *)(iVar2 + 0x10c),
             (uint)*(byte *)(iVar2 + 0x10d),(uint)*(byte *)(iVar2 + 0x10e),iVar2 + 0x58,iVar2 + 0x82
             ,iVar2 + 0xa3,*(undefined4 *)(iVar2 + 0x168),*(undefined4 *)(iVar2 + 0x16c));
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      bVar1 = *(byte *)(iVar2 + 0xf);
    }
  }
  uac_mutex_give(wportal_aut_mutex);
  return;
}

