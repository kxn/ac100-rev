// func packet_parse_test @ 005d17d0 size=1

undefined4 packet_parse_test(void)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_58 [28];
  undefined1 auStack_3c [32];
  
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  memset(auStack_58,0,0x38);
  FUN_0051ad88(auStack_3c);
  uRam0074e8a1 = 4;
  uRam0074e8a2 = 0xe9;
  piVar2 = (int *)cw_pkt_buf_create(0x4f6);
  piVar3 = (int *)cw_pkt_buf_create(0x4f6);
  memcpy((void *)*piVar2,&cw_dis_req_mesh,0x4f6);
  *(undefined2 *)((int)piVar2 + 6) = 0;
  *(undefined2 *)(piVar2 + 1) = 0x4f6;
  iVar4 = capwap_packet_parse(piVar2,auStack_58,0,0,&uStack_6c);
  if (iVar4 == -1) {
    pcVar5 = "parse packet failed. \r";
  }
  else {
    iVar4 = capwap_parsed_packet_dump(auStack_58);
    if (iVar4 == -1) {
      pcVar5 = "dump packet failed. \r";
    }
    else {
      iVar4 = capwap_packet_assemble(piVar3,auStack_58);
      if (iVar4 == -1) {
        pcVar5 = "assemble packet failed. \r";
      }
      else {
        uVar7 = 0;
        iVar4 = capwap_parsed_packet_free(auStack_58);
        if (iVar4 != -1) {
          uVar8 = (uint)*(ushort *)(piVar3 + 1);
          while ((int)uVar7 < (int)uVar8) {
            pbVar6 = (byte *)(*piVar3 + uVar7);
            uVar7 = uVar7 + 1;
            printf("%02x ",(uint)*pbVar6);
            if ((uVar7 & 0xf) == 0) {
              puts("\r");
              uVar8 = (uint)*(ushort *)(piVar3 + 1);
            }
            else {
              uVar8 = (uint)*(ushort *)(piVar3 + 1);
            }
          }
          uVar1 = *(ushort *)(piVar2 + 1);
          iVar4 = memcmp((void *)*piVar2,(void *)*piVar3,(uint)uVar1);
          if ((iVar4 == 0) && (uVar1 == uVar8)) {
            pcVar5 = "\nassemble packet successed \r";
          }
          else {
            for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(piVar3 + 1); iVar4 = iVar4 + 1) {
              if (*(char *)(*piVar3 + iVar4) != *(char *)(*piVar2 + iVar4)) {
                printf("%d:(%02x:%02x)\r\n",iVar4);
              }
            }
            pcVar5 = "\nassemble packet failed \r";
          }
          puts(pcVar5);
          cw_pkt_buf_destroy(piVar2);
          cw_pkt_buf_destroy(piVar3);
          return 0;
        }
        pcVar5 = "free parsed packet failed. \r";
      }
    }
  }
  puts(pcVar5);
  return 0;
}

