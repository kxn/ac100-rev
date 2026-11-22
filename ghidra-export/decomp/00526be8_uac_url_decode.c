// func uac_url_decode @ 00526be8 size=1

int uac_url_decode(int param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  iVar2 = 0;
  if ((((param_1 != 0) && (param_3 != (byte *)0x0)) && (0 < param_2)) && (0 < param_4)) {
    iVar5 = 0;
    pbVar6 = param_3;
    iVar3 = 1;
    do {
      iVar2 = iVar3;
      pbVar7 = (byte *)(param_1 + iVar5);
      bVar1 = *pbVar7;
      if (bVar1 == 0x25) {
        if (iVar5 + 2 < param_2) {
          iVar3 = char2num((int)(char)pbVar7[1]);
          iVar4 = char2num((int)(char)pbVar7[2]);
          if ((iVar3 == 0x30) || (iVar4 == 0x30)) goto code_r0x00526c7c;
          *pbVar6 = (byte)iVar4 | (byte)(iVar3 << 4);
          iVar5 = iVar5 + 2;
        }
        else {
          *pbVar6 = 0x25;
        }
      }
      else if (bVar1 == 0x2b) {
        *pbVar6 = 0x20;
      }
      else {
code_r0x00526c7c:
        *pbVar6 = bVar1;
      }
      iVar5 = iVar5 + 1;
      if (param_2 <= iVar5) break;
      pbVar6 = pbVar6 + 1;
      iVar3 = iVar2 + 1;
    } while (iVar2 < param_4);
    param_3[iVar2] = 0;
  }
  return iVar2;
}

