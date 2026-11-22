// func MD5_Final @ 0051bfd8 size=308

int MD5_Final(uchar *md,MD5_CTX *c)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  MD5_CTX *pMVar6;
  uint uVar7;
  void *pvVar8;
  uint *puVar9;
  uint local_50 [14];
  uint local_18;
  uint local_14;
  
  local_18 = c->A;
  local_14 = c->B;
  uVar7 = (local_18 << 0x17) >> 0x1a;
  if (uVar7 < 0x38) {
    iVar5 = 0x38;
  }
  else {
    iVar5 = 0x78;
  }
  MD5_Update(c,PTR_DAT_007591ac + 0x2000,iVar5 - uVar7);
  iVar5 = 0;
  pMVar6 = c;
  do {
    puVar2 = pMVar6->data;
    puVar9 = (uint *)((int)local_50 + iVar5);
    puVar3 = pMVar6->data;
    iVar5 = iVar5 + 4;
    puVar1 = pMVar6->data;
    puVar4 = pMVar6->data;
    pMVar6 = (MD5_CTX *)&pMVar6->B;
    *puVar9 = (uint)(byte)*puVar2 << 0x18 | (uint)*(byte *)((int)puVar3 + 2) << 0x10 |
              (uint)*(byte *)puVar1 | (uint)*(byte *)((int)puVar4 + 1) << 8;
  } while (iVar5 != 0x38);
  Transform(&c->C,local_50);
  iVar5 = 0;
  pMVar6 = c;
  do {
    uVar7 = pMVar6->C;
    iVar5 = iVar5 + 4;
    *(char *)&pMVar6->num = (char)uVar7;
    *(char *)((int)&pMVar6->num + 1) = (char)(uVar7 >> 8);
    *(char *)((int)&pMVar6->num + 2) = (char)(uVar7 >> 0x10);
    *(char *)((int)&pMVar6->num + 3) = (char)(uVar7 >> 0x18);
    pMVar6 = (MD5_CTX *)&pMVar6->B;
  } while (iVar5 != 0x10);
  pvVar8 = memcpy(md,&c->num,0x10);
  return (int)pvVar8;
}

