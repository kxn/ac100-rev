// func hmac_md5 @ 0051c10c size=492

void hmac_md5(void *param_1,size_t param_2,uchar *param_3,size_t param_4,uchar *param_5)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  size_t __n;
  uchar *__src;
  uchar auStack_180 [16];
  byte local_170 [68];
  byte local_12c [68];
  MD5_CTX MStack_e8;
  MD5_CTX MStack_80;
  
  __n = param_4;
  __src = param_3;
  if (0x40 < (int)param_4) {
    MD5_Init(&MStack_e8);
    __src = auStack_180;
    __n = 0x10;
    MD5_Update(&MStack_e8,param_3,param_4);
    MD5_Final(auStack_180,&MStack_e8);
  }
  memset(local_12c,0,0x41);
  memset(local_170,0,0x41);
  memcpy(local_12c,__src,__n);
  memcpy(local_170,__src,__n);
  pbVar2 = local_12c;
  pbVar1 = local_170;
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    *pbVar2 = *pbVar2 ^ 0x36;
    pbVar2 = pbVar2 + 1;
    *pbVar1 = *pbVar1 ^ 0x5c;
    pbVar1 = pbVar1 + 1;
  } while (iVar3 != 0x40);
  MD5_Init(&MStack_80);
  MD5_Update(&MStack_80,local_12c,0x40);
  MD5_Update(&MStack_80,param_1,param_2);
  MD5_Final(param_5,&MStack_80);
  MD5_Init(&MStack_80);
  MD5_Update(&MStack_80,local_170,0x40);
  MD5_Update(&MStack_80,param_5,0x10);
  MD5_Final(param_5,&MStack_80);
  return;
}

