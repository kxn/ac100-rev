// func url_encode @ 0051828c size=352

int url_encode(byte *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = 0;
  iVar3 = iVar2;
  if ((((param_1 != (byte *)0x0) && (param_3 != 0)) && (0 < param_2)) &&
     (iVar6 = 0, pbVar4 = param_1, 0 < param_4)) {
    do {
      bVar1 = *pbVar4;
      uVar5 = (uint)bVar1;
      if (((((uVar5 - 0x41 < 0x1a) || (uVar5 - 0x61 < 0x1a)) ||
           ((uVar5 - 0x30 < 10 || ((bVar1 == 0x2d || (bVar1 == 0x5f)))))) || (bVar1 == 0x2e)) ||
         (bVar1 == 0x7e)) {
        iVar3 = iVar2 + 1;
        *(byte *)(param_3 + iVar2) = bVar1;
      }
      else {
        iVar3 = iVar2 + 3;
        if (param_4 <= iVar3) {
          return 0;
        }
        sprintf((char *)(param_3 + iVar2),"%%%02X");
      }
      iVar6 = iVar6 + 1;
    } while ((iVar6 != param_2) && (iVar2 = iVar3, pbVar4 = param_1 + iVar6, iVar3 < param_4));
    *(undefined1 *)(param_3 + iVar3) = 0;
  }
  return iVar3;
}

