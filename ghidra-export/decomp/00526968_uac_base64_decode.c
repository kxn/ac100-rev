// func uac_base64_decode @ 00526968 size=1

undefined4 uac_base64_decode(byte *param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int in_t9;
  
  if ((((param_1 != (byte *)0x0) && (0 < (int)param_2)) && (param_3 != 0)) &&
     ((param_4 != (int *)0x0 && (iVar9 = *(int *)(in_t9 + 0x2327c0), (param_2 & 3) == 0)))) {
    iVar7 = 3;
    uVar2 = 0;
    iVar4 = 0;
    iVar1 = 0;
    while( true ) {
      if (*param_1 == 0) {
        *param_4 = iVar1;
        return 0;
      }
      uVar8 = (uint)*(byte *)((uint)*param_1 + iVar9 + 0x45fc);
      if (uVar8 == 0xff) break;
      if (uVar8 == 0xfd) {
        param_1 = param_1 + 1;
      }
      else {
        if (uVar8 == 0xfe) {
          iVar7 = iVar7 + -1;
          uVar8 = 0;
        }
        uVar3 = uVar2 << 6;
        iVar4 = iVar4 + 1;
        uVar2 = uVar8 | uVar3;
        if (iVar4 == 4) {
          *(char *)(param_3 + iVar1) = (char)(uVar3 >> 0x10);
          iVar5 = iVar1 + 1;
          if (1 < iVar7) {
            *(char *)(param_3 + iVar5) = (char)(uVar3 >> 8);
            iVar5 = iVar1 + 2;
            if (iVar7 == 3) {
              puVar6 = (undefined1 *)(param_3 + iVar5);
              iVar5 = iVar1 + 3;
              *puVar6 = (char)uVar2;
            }
            else {
              iVar7 = 2;
            }
          }
          iVar4 = 0;
          uVar2 = 0;
          param_1 = param_1 + 1;
          iVar1 = iVar5;
        }
        else {
          param_1 = param_1 + 1;
        }
      }
    }
  }
  return 0xffffffff;
}

