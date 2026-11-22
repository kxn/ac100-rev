// func wportal_db_nsa_list_dump @ 00433e2c size=272

void wportal_db_nsa_list_dump(void)

{
  byte bVar1;
  int iVar2;
  
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  iVar2 = FUN_004081b0(nsa_list);
  if (iVar2 != 0) {
    bVar1 = *(byte *)(iVar2 + 0x77);
    while( true ) {
      printf("%02x:%02x:%02x:%02x:%02x:%02x\t",(uint)*(byte *)(iVar2 + 0x74),
             (uint)*(byte *)(iVar2 + 0x75),(uint)*(byte *)(iVar2 + 0x76),(uint)bVar1,
             (uint)*(byte *)(iVar2 + 0x78),(uint)*(byte *)(iVar2 + 0x79));
      wportal_get_mode();
      printf("%d\t%d\t%d-%d-%d %d:%d:%d\t%s\t%s\n",*(undefined4 *)(iVar2 + 0x128),
             *(undefined4 *)(iVar2 + 0x148),(uint)*(ushort *)(iVar2 + 0x108),
             (uint)*(byte *)(iVar2 + 0x10a),(uint)*(byte *)(iVar2 + 0x10b),
             (uint)*(byte *)(iVar2 + 0x10c),(uint)*(byte *)(iVar2 + 0x10d),
             (uint)*(byte *)(iVar2 + 0x10e),iVar2 + 0x7a,iVar2 + 0xc);
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      bVar1 = *(byte *)(iVar2 + 0x77);
    }
  }
  FUN_00407f30(wportal_nsa_mutex);
  return;
}

