// func cw_priv_wsrv_para_new_dump @ 005cee64 size=1128

undefined4 cw_priv_wsrv_para_new_dump(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  undefined1 auStack_50 [44];
  
  pbVar5 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wireless service parameter \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wireless service parameter (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar5,(uint)pbVar5[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar5);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar5[1]);
  printf("\t\t\t\tvlan id: %d \r\n",(uint)*(ushort *)(pbVar5 + 2));
  printf("\t\t\t\tmax users: %d \r\n",(uint)*(ushort *)(pbVar5 + 4));
  printf("\t\t\t\tnetwork type: %d \r\n",(uint)pbVar5[6]);
  printf("\t\t\t\tisolation: %d \r\n",(uint)pbVar5[7]);
  printf("\t\t\t\tsecurity option: %d \r\n",(uint)pbVar5[8]);
  bVar1 = pbVar5[8];
  if (bVar1 == 2) {
    pbVar5 = *(byte **)(pbVar5 + 9);
    if (pbVar5 == (byte *)0x0) {
      return 0;
    }
    printf("\t\t\t\twpa-auth type: %d \r\n",(uint)*pbVar5);
    printf("\t\t\t\twpa-enc alg: %d \r\n",(uint)pbVar5[1]);
    printf("\t\t\t\twpa-upd prd: %d \r\n",*(undefined4 *)(pbVar5 + 2));
    memset(auStack_50,0,0x28);
    cw_protocol_addr2str(pbVar5 + 6,auStack_50,0x28);
    printf("\t\t\t\twpa-radius ip: %s \r\n",auStack_50);
    cw_protocol_addr2str(pbVar5 + 0x1a,auStack_50,0x28);
    printf("\t\t\t\twpa radius acct ip: %s \r\n",auStack_50);
    cw_protocol_addr2str(pbVar5 + 0x2e,auStack_50,0x28);
    printf("\t\t\t\twpa-radius author ip: %s \r\n",auStack_50);
    printf("\t\t\t\twpa-radius port: %d \r\n",(uint)*(ushort *)(pbVar5 + 0x42));
    printf("\t\t\t\twpa radius acct port: %d \r\n",(uint)*(ushort *)(pbVar5 + 0x44));
    printf("\t\t\t\twpa-radius author port: %d \r\n",(uint)*(ushort *)(pbVar5 + 0x46));
    printf("\t\t\t\twpa-key len: %d \r\n",(uint)*(ushort *)(pbVar5 + 0x48));
    if (*(int *)(pbVar5 + 0x4a) == 0) {
      return 0;
    }
    printf("\t\t\t\twpa-key: ");
    for (iVar6 = 0; iVar6 < (int)(uint)*(ushort *)(pbVar5 + 0x48) != 0; iVar6 = iVar6 + 1) {
      uVar2 = (uint)(pbVar5 + 0x4a) & 3;
      uVar3 = (uint)(pbVar5 + 0x4d) & 3;
      printf("%02x",(uint)*(byte *)(((*(int *)(pbVar5 + 0x4a + -uVar2) << uVar2 * 8 |
                                     (uint)(iVar6 < (int)(uint)*(ushort *)(pbVar5 + 0x48)) &
                                     0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar3 + 1) * 8 |
                                    *(uint *)(pbVar5 + 0x4d + -uVar3) >> (3 - uVar3) * 8) + iVar6));
    }
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 1) {
        return 0;
      }
      pbVar5 = *(byte **)(pbVar5 + 9);
    }
    else {
      if (bVar1 == 3) {
        pbVar5 = *(byte **)(pbVar5 + 9);
        if (pbVar5 == (byte *)0x0) {
          return 0;
        }
        printf("\t\t\t\twep-auth type: %d \r\n",(uint)*pbVar5);
        cVar7 = '\x04';
        printf("\t\t\t\twep-key fmt: %d \r\n",(uint)pbVar5[1]);
        do {
          iVar6 = 0;
          printf("\t\t\t\twep-key type: %d \r\n",(uint)pbVar5[2]);
          printf("\t\t\t\twep-key: ");
          pbVar4 = pbVar5;
          do {
            iVar6 = iVar6 + 1;
            printf("%02x",(uint)pbVar4[3]);
            pbVar4 = pbVar5 + iVar6;
          } while (iVar6 != 0x20);
          cVar7 = cVar7 + -1;
          puts("\r");
          pbVar5 = pbVar5 + 0x21;
        } while (cVar7 != '\0');
        return 0;
      }
      if (bVar1 != 4) {
        return 0;
      }
      uVar2 = (uint)(pbVar5 + 9) & 3;
      pbVar5 = (byte *)(*(int *)(pbVar5 + 9 + -uVar2) << uVar2 * 8 |
                       param_1 & 0xffffffffU >> (4 - uVar2) * 8);
    }
    if (pbVar5 == (byte *)0x0) {
      return 0;
    }
    printf("\t\t\t\twpapsk-auth type: %d \r\n",(uint)*pbVar5);
    printf("\t\t\t\twpapsk-enc alg: %d \r\n",(uint)pbVar5[1]);
    printf("\t\t\t\twpapsk-upd prd: %d \r\n",*(undefined4 *)(pbVar5 + 2));
    printf("\t\t\t\twpapsk-key len: %d \r\n",(uint)*(ushort *)(pbVar5 + 6));
    if (*(int *)(pbVar5 + 8) == 0) {
      return 0;
    }
    printf("\t\t\t\tpsk-key: ");
    for (iVar6 = 0; iVar6 < (int)(uint)*(ushort *)(pbVar5 + 6) != 0; iVar6 = iVar6 + 1) {
      uVar2 = (uint)(pbVar5 + 8) & 3;
      uVar3 = (uint)(pbVar5 + 0xb) & 3;
      printf("%02x",(uint)*(byte *)(((*(int *)(pbVar5 + 8 + -uVar2) << uVar2 * 8 |
                                     (uint)(iVar6 < (int)(uint)*(ushort *)(pbVar5 + 6)) &
                                     0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar3 + 1) * 8 |
                                    *(uint *)(pbVar5 + 0xb + -uVar3) >> (3 - uVar3) * 8) + iVar6));
    }
  }
  puts("\r");
  return 0;
}

