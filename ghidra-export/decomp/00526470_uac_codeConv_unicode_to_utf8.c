// func uac_codeConv_unicode_to_utf8 @ 00526470 size=212

uint uac_codeConv_unicode_to_utf8(ushort *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (ushort *)0x0) && (iVar5 = 0, param_2 != 0)) {
    uVar2 = 0;
    do {
      uVar3 = (uint)*param_1;
      uVar1 = uVar2 + 1;
      if (uVar3 == 0) {
        return uVar2;
      }
      if (param_4 == 1) {
        uVar3 = uVar3 * 0x100 + (uint)(*param_1 >> 8) & 0xffff;
      }
      pbVar6 = (byte *)(param_2 + iVar5);
      bVar4 = (byte)uVar3;
      if (uVar3 < 0x80) {
        iVar5 = iVar5 + 1;
        *pbVar6 = bVar4;
      }
      else if (uVar3 < 0x800) {
        *pbVar6 = (byte)(uVar3 >> 6) | 0xc0;
        pbVar6[1] = bVar4 & 0x3f | 0x80;
        iVar5 = iVar5 + 2;
      }
      else {
        iVar5 = iVar5 + 3;
        *pbVar6 = (byte)(uVar3 >> 0xc) | 0xe0;
        pbVar6[1] = (byte)((uVar3 << 0x14) >> 0x1a) | 0x80;
        pbVar6[2] = bVar4 & 0x3f | 0x80;
      }
      param_1 = param_1 + 1;
      uVar2 = uVar1;
    } while (uVar1 <= param_3 - 1U);
  }
  return uVar1;
}

