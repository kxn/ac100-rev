// func MD5_Update @ 0051beb4 size=292

int MD5_Update(MD5_CTX *c,void *data,size_t len)

{
  uint *puVar1;
  undefined1 uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  MD5_CTX *pMVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  undefined1 *puVar11;
  uint local_60 [17];
  
  uVar7 = c->A;
  uVar9 = len * 8 + uVar7;
  if (uVar9 < uVar7) {
    c->B = c->B + 1;
  }
  c->A = uVar9;
  puVar11 = (undefined1 *)((int)data + len);
  c->B = c->B + (len >> 0x1d);
  uVar7 = (uVar7 << 0x17) >> 0x1a;
  do {
    if ((undefined1 *)data == puVar11) {
      return uVar7;
    }
    while( true ) {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *data;
      uVar9 = uVar7 + 1;
      data = (void *)((int)data + 1);
      *(undefined1 *)((int)c->data + uVar7) = uVar2;
      uVar7 = uVar9;
      if (uVar9 != 0x40) break;
      iVar8 = 0;
      pMVar6 = c;
      do {
        puVar3 = pMVar6->data;
        puVar10 = (uint *)((int)local_60 + iVar8);
        puVar4 = pMVar6->data;
        iVar8 = iVar8 + 4;
        puVar1 = pMVar6->data;
        puVar5 = pMVar6->data;
        pMVar6 = (MD5_CTX *)&pMVar6->B;
        *puVar10 = (uint)(byte)*puVar3 << 0x18 | (uint)*(byte *)((int)puVar4 + 2) << 0x10 |
                   (uint)*(byte *)puVar1 | (uint)*(byte *)((int)puVar5 + 1) << 8;
      } while (iVar8 != 0x40);
      Transform(&c->C,local_60);
      uVar7 = 0;
      if ((undefined1 *)data == puVar11) {
        return 0;
      }
    }
  } while( true );
}

