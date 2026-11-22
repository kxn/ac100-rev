// func uac_codeConv_utf8_to_unicode @ 00526364 size=268

uint uac_codeConv_utf8_to_unicode(int param_1,ushort *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (ushort *)0x0)) {
    iVar3 = 0;
    uVar5 = 1;
    do {
      uVar2 = uVar5;
      pbVar4 = (byte *)(param_1 + iVar3);
      bVar1 = *pbVar4;
      uVar5 = (uint)bVar1;
      if (uVar5 == 0) {
        return uVar2 - 1;
      }
      if ((char)bVar1 < '\0') {
        if ((uVar5 & 0xe0) == 0xc0) {
          iVar3 = iVar3 + 2;
          *param_2 = (ushort)((uVar5 & 0x3f) << 6) | pbVar4[1] & 0x3f;
        }
        else if ((uVar5 & 0xf0) == 0xe0) {
          iVar3 = iVar3 + 3;
          *param_2 = pbVar4[2] & 0x3f | (ushort)bVar1 << 0xc | (ushort)((pbVar4[1] & 0x3f) << 6);
        }
        else if ((uVar5 & 0xf8) == 0xf0) {
          iVar3 = iVar3 + 4;
          *param_2 = (ushort)pbVar4[1] << 0xc | pbVar4[3] & 0x3f | (ushort)((pbVar4[2] & 0x3f) << 6)
          ;
        }
        else {
          iVar3 = iVar3 + 5;
          *param_2 = pbVar4[4] & 0x3f;
        }
      }
      else {
        iVar3 = iVar3 + 1;
        *param_2 = (ushort)bVar1;
      }
      param_2 = param_2 + 1;
      uVar5 = uVar2 + 1;
    } while (uVar2 < param_3);
  }
  return uVar2;
}

