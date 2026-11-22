// func cw_priv_wsrv_para_dump @ 005cd808 size=1192

undefined4 cw_priv_wsrv_para_dump(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  uint local_40;
  char acStack_3c [24];
  
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
    local_40 = *(uint *)(pbVar5 + 7);
    inet_ntop(2,&local_40,acStack_3c,0x14);
    printf("\t\t\t\twpa-radius ip: %s \r\n",acStack_3c);
    if (pbVar5[6] == 0) {
      bVar1 = pbVar5[0x13];
    }
    else {
      uVar2 = (uint)(pbVar5 + 0xb) & 3;
      uVar3 = (uint)(pbVar5 + 0xe) & 3;
      local_40 = (*(int *)(pbVar5 + 0xb + -uVar2) << uVar2 * 8 |
                 (uint)pbVar5[6] & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar3 + 1) * 8 |
                 *(uint *)(pbVar5 + 0xe + -uVar3) >> (3 - uVar3) * 8;
      inet_ntop(2,&local_40,acStack_3c,0x14);
      printf("\t\t\t\twpa radius acct ip: %s \r\n",acStack_3c);
      local_40 = *(uint *)(pbVar5 + 0xf);
      inet_ntop(2,&local_40,acStack_3c,0x14);
      printf("\t\t\t\twpa-radius author ip: %s \r\n",acStack_3c);
      bVar1 = pbVar5[0x13];
    }
    printf("\t\t\t\twpa-radius port: %d \r\n",(uint)CONCAT11(bVar1,pbVar5[0x14]));
    if (pbVar5[6] == 0) {
      bVar1 = pbVar5[0x19];
    }
    else {
      printf("\t\t\t\twpa radius acct port: %d \r\n",(uint)*(ushort *)(pbVar5 + 0x15));
      printf("\t\t\t\twpa-radius author port: %d \r\n",(uint)*(ushort *)(pbVar5 + 0x17));
      bVar1 = pbVar5[0x19];
    }
    printf("\t\t\t\twpa-key len: %d \r\n",(uint)CONCAT11(bVar1,pbVar5[0x1a]));
    if (*(int *)(pbVar5 + 0x1b) == 0) {
      return 0;
    }
    printf("\t\t\t\twpa-key: ");
    for (iVar6 = 0; iVar6 < (int)(uint)*(ushort *)(pbVar5 + 0x19) != 0; iVar6 = iVar6 + 1) {
      uVar2 = (uint)(pbVar5 + 0x1b) & 3;
      uVar3 = (uint)(pbVar5 + 0x1e) & 3;
      printf("%02x",(uint)*(byte *)(((*(int *)(pbVar5 + 0x1b + -uVar2) << uVar2 * 8 |
                                     (uint)(iVar6 < (int)(uint)*(ushort *)(pbVar5 + 0x19)) &
                                     0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar3 + 1) * 8 |
                                    *(uint *)(pbVar5 + 0x1e + -uVar3) >> (3 - uVar3) * 8) + iVar6));
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

