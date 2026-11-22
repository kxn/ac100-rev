// func cw_priv_wsrv_enable_para_dump @ 005cc178 size=1244

undefined4 cw_priv_wsrv_enable_para_dump(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  char cVar8;
  undefined1 auStack_50 [44];
  
  pbVar6 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wsrv enable para support \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wsrv enable para support (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc)
        );
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar6,(uint)pbVar6[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar6);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar6[1]);
  printf("\t\t\t\tvlan id: %d \r\n",(uint)*(ushort *)(pbVar6 + 2));
  printf("\t\t\t\tmax users: %d \r\n",(uint)*(ushort *)(pbVar6 + 4));
  printf("\t\t\t\tnetwork type: %d \r\n",(uint)pbVar6[6]);
  printf("\t\t\t\tisolation: %d \r\n",(uint)pbVar6[7]);
  printf("\t\t\t\tssid_id_lens: %d \r\n",(uint)*(ushort *)(pbVar6 + 8));
  printf("\t\t\t\tssid_id:");
  bVar1 = pbVar6[8];
  for (iVar7 = 0; uVar4 = (uint)(iVar7 < (int)(uint)CONCAT11(bVar1,pbVar6[9])), uVar4 != 0;
      iVar7 = iVar7 + 1) {
    uVar2 = (uint)(pbVar6 + 10) & 3;
    uVar3 = (uint)(pbVar6 + 0xd) & 3;
    putchar((uint)*(byte *)(((*(int *)(pbVar6 + 10 + -uVar2) << uVar2 * 8 |
                             uVar4 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar3 + 1) * 8 |
                            *(uint *)(pbVar6 + 0xd + -uVar3) >> (3 - uVar3) * 8) + iVar7));
    bVar1 = pbVar6[8];
  }
  puts("\r");
  printf("\t\t\t\tenable: %d \r\n",(uint)pbVar6[0xe]);
  printf("\t\t\t\tsecurity option: %d \r\n",(uint)pbVar6[0xf]);
  bVar1 = pbVar6[0xf];
  if (bVar1 == 2) {
    pbVar6 = *(byte **)(pbVar6 + 0x10);
    if (pbVar6 == (byte *)0x0) {
      return 0;
    }
    printf("\t\t\t\twpa-auth type: %d \r\n",(uint)*pbVar6);
    printf("\t\t\t\twpa-enc alg: %d \r\n",(uint)pbVar6[1]);
    printf("\t\t\t\twpa-upd prd: %d \r\n",*(undefined4 *)(pbVar6 + 2));
    memset(auStack_50,0,0x28);
    cw_protocol_addr2str(pbVar6 + 6,auStack_50,0x28);
    printf("\t\t\t\twpa-radius ip: %s \r\n",auStack_50);
    cw_protocol_addr2str(pbVar6 + 0x1a,auStack_50,0x28);
    printf("\t\t\t\twpa radius acct ip: %s \r\n",auStack_50);
    cw_protocol_addr2str(pbVar6 + 0x2e,auStack_50,0x28);
    printf("\t\t\t\twpa-radius author ip: %s \r\n",auStack_50);
    printf("\t\t\t\twpa-radius port: %d \r\n",(uint)*(ushort *)(pbVar6 + 0x42));
    printf("\t\t\t\twpa radius acct port: %d \r\n",(uint)*(ushort *)(pbVar6 + 0x44));
    printf("\t\t\t\twpa-radius author port: %d \r\n",(uint)*(ushort *)(pbVar6 + 0x46));
    printf("\t\t\t\twpa-key len: %d \r\n",(uint)*(ushort *)(pbVar6 + 0x48));
    if (*(int *)(pbVar6 + 0x4a) == 0) {
      return 0;
    }
    printf("\t\t\t\twpa-key: ");
    for (iVar7 = 0; iVar7 < (int)(uint)*(ushort *)(pbVar6 + 0x48) != 0; iVar7 = iVar7 + 1) {
      uVar4 = (uint)(pbVar6 + 0x4a) & 3;
      uVar2 = (uint)(pbVar6 + 0x4d) & 3;
      printf("%02x",(uint)*(byte *)(((*(int *)(pbVar6 + 0x4a + -uVar4) << uVar4 * 8 |
                                     (uint)(iVar7 < (int)(uint)*(ushort *)(pbVar6 + 0x48)) &
                                     0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar2 + 1) * 8 |
                                    *(uint *)(pbVar6 + 0x4d + -uVar2) >> (3 - uVar2) * 8) + iVar7));
    }
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 1) {
        return 0;
      }
      pbVar6 = *(byte **)(pbVar6 + 0x10);
    }
    else {
      if (bVar1 == 3) {
        pbVar6 = *(byte **)(pbVar6 + 0x10);
        if (pbVar6 == (byte *)0x0) {
          return 0;
        }
        printf("\t\t\t\twep-auth type: %d \r\n",(uint)*pbVar6);
        cVar8 = '\x04';
        printf("\t\t\t\twep-key fmt: %d \r\n",(uint)pbVar6[1]);
        do {
          iVar7 = 0;
          printf("\t\t\t\twep-key type: %d \r\n",(uint)pbVar6[2]);
          printf("\t\t\t\twep-key: ");
          pbVar5 = pbVar6;
          do {
            iVar7 = iVar7 + 1;
            printf("%02x",(uint)pbVar5[3]);
            pbVar5 = pbVar6 + iVar7;
          } while (iVar7 != 0x20);
          cVar8 = cVar8 + -1;
          puts("\r");
          pbVar6 = pbVar6 + 0x21;
        } while (cVar8 != '\0');
        return 0;
      }
      if (bVar1 != 4) {
        return 0;
      }
      uVar4 = (uint)(pbVar6 + 0x10) & 3;
      pbVar6 = (byte *)(*(int *)(pbVar6 + 0x10 + -uVar4) << uVar4 * 8 |
                       0xffffffffU >> (4 - uVar4) * 8 & 0x6f0000);
    }
    if (pbVar6 == (byte *)0x0) {
      return 0;
    }
    printf("\t\t\t\twpapsk-auth type: %d \r\n",(uint)*pbVar6);
    printf("\t\t\t\twpapsk-enc alg: %d \r\n",(uint)pbVar6[1]);
    printf("\t\t\t\twpapsk-upd prd: %d \r\n",*(undefined4 *)(pbVar6 + 2));
    printf("\t\t\t\twpapsk-key len: %d \r\n",(uint)*(ushort *)(pbVar6 + 6));
    if (*(int *)(pbVar6 + 8) == 0) {
      return 0;
    }
    printf("\t\t\t\tpsk-key: ");
    for (iVar7 = 0; iVar7 < (int)(uint)*(ushort *)(pbVar6 + 6) != 0; iVar7 = iVar7 + 1) {
      uVar4 = (uint)(pbVar6 + 8) & 3;
      uVar2 = (uint)(pbVar6 + 0xb) & 3;
      printf("%02x",(uint)*(byte *)(((*(int *)(pbVar6 + 8 + -uVar4) << uVar4 * 8 |
                                     (uint)(iVar7 < (int)(uint)*(ushort *)(pbVar6 + 6)) &
                                     0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar2 + 1) * 8 |
                                    *(uint *)(pbVar6 + 0xb + -uVar2) >> (3 - uVar2) * 8) + iVar7));
    }
  }
  puts("\r");
  return 0;
}

