// func uac_base64_encode @ 005267dc size=396

/* WARNING: Removing unreachable block (ram,0x00526800) */
/* WARNING: Removing unreachable block (ram,0x00526910) */

undefined4 uac_base64_encode(byte *param_1,int param_2,undefined1 *param_3,int *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (byte *)0x0) && (param_2 != 0)) {
    iVar4 = 0;
    iVar3 = 3 - param_2 % 3;
    if (param_2 % 3 == 0) {
      iVar3 = 0;
    }
    param_2 = param_2 + iVar3;
    for (; iVar4 < param_2; iVar4 = iVar4 + 3) {
      *param_3 = (&DAT_006c45bc)[*param_1 >> 2];
      if (iVar4 == param_2 + -3) {
        if (iVar3 == 0) {
          bVar1 = *param_1;
          goto LAB_0052683c;
        }
        if (iVar3 == 1) {
          param_3[1] = (&DAT_006c45bc)[(*param_1 & 3) * 0x10 + (uint)(param_1[1] >> 4)];
          bVar1 = param_1[1];
          param_3[3] = 0x3d;
          param_3[2] = (&DAT_006c45bc)[(bVar1 & 0xf) * 4];
        }
        else if (iVar3 == 2) {
          bVar1 = *param_1;
          param_3[2] = 0x3d;
          param_3[3] = 0x3d;
          param_3[1] = (&DAT_006c45bc)[(bVar1 & 3) * 0x10];
        }
      }
      else {
        bVar1 = *param_1;
LAB_0052683c:
        param_3[1] = (&DAT_006c45bc)[(bVar1 & 3) * 0x10 + (uint)(param_1[1] >> 4)];
        param_3[2] = (&DAT_006c45bc)[(param_1[1] & 0xf) * 4 + (uint)(param_1[2] >> 6)];
        param_3[3] = (&DAT_006c45bc)[param_1[2] & 0x3f];
      }
      param_3 = param_3 + 4;
      param_1 = param_1 + 3;
    }
    uVar2 = 0;
    if (param_4 != (int *)0x0) {
      *param_4 = (param_2 * 8) / 6;
    }
  }
  return uVar2;
}

