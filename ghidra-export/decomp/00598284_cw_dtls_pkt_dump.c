// func cw_dtls_pkt_dump @ 00598284 size=312

void cw_dtls_pkt_dump(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puts("***********cw_dtls_pkt_dump**************");
    iVar2 = FUN_004081b0(param_1 + 4);
    if (iVar2 != 0) {
      bVar1 = *(byte *)(iVar2 + 0xc);
      while( true ) {
        printf("content type:%d\n",(uint)bVar1);
        printf("version:0x%04x\n",(uint)*(ushort *)(iVar2 + 0xe));
        printf("Epoch:%d\n",(uint)*(ushort *)(iVar2 + 0x10));
        printf("Sequence Number:%02x%02x%02x%02x%02x%02x\n",(uint)*(byte *)(iVar2 + 0x12),
               (uint)*(byte *)(iVar2 + 0x13),(uint)*(byte *)(iVar2 + 0x14),
               (uint)*(byte *)(iVar2 + 0x15),(uint)*(byte *)(iVar2 + 0x16),
               (uint)*(byte *)(iVar2 + 0x17));
        printf("Length:%d\n",(uint)*(ushort *)(iVar2 + 0x18));
        printf("\tHandshake Type:%d\n",(uint)**(byte **)(iVar2 + 0x1c));
        iVar2 = FUN_00408680(iVar2);
        if (iVar2 == 0) break;
        bVar1 = *(byte *)(iVar2 + 0xc);
      }
    }
    puts("***********cw_dtls_pkt_dump end**************");
    return;
  }
  return;
}

