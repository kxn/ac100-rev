// func _wsta_db_mlo_hash_show_cb @ 006368bc size=212

void _wsta_db_mlo_hash_show_cb(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  puts("*********************MLD hash**********************");
  printf("mld mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*(byte *)(param_1 + 0xc),
         (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
         (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
         (uint)*(byte *)(param_1 + 0x11));
  bVar1 = *(byte *)(param_1 + 0x12);
  iVar2 = param_1;
  while (iVar3 < (int)(uint)bVar1) {
    iVar3 = iVar3 + 1;
    printf("\tpeer mac%d: %02x:%02x:%02x:%02x:%02x:%02x\n",iVar3,(uint)*(byte *)(iVar2 + 0x16),
           (uint)*(byte *)(iVar2 + 0x17),(uint)*(byte *)(iVar2 + 0x18),(uint)*(byte *)(iVar2 + 0x19)
           ,(uint)*(byte *)(iVar2 + 0x1a),(uint)*(byte *)(iVar2 + 0x1b));
    iVar2 = iVar2 + 0xc;
    bVar1 = *(byte *)(param_1 + 0x12);
  }
  return;
}

