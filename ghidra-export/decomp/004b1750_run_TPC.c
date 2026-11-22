// func run_TPC @ 004b1750 size=692

int run_TPC(int param_1,int param_2,int *param_3,char param_4,char param_5,int param_6,uint param_7,
           code *param_8)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar14 = 0;
  iVar12 = 0;
  do {
    if (param_2 <= iVar14) {
      return iVar12;
    }
    iVar13 = iVar14 * 0xc;
    iVar8 = param_1;
    piVar9 = param_3;
    for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1 + 2); iVar15 = iVar15 + 1) {
      iVar4 = FUN_00407fe0(*piVar9 + iVar13);
      if (iVar4 < param_6) {
        if (iVar4 < 1) {
          uVar5 = (uint)*(byte *)(iVar8 + 3);
          if ((int)uVar5 < (int)(*(byte *)(iVar8 + 6) - 1)) {
            uVar5 = uVar5 + (int)(*(byte *)(iVar8 + 6) - uVar5) / 2;
            *(char *)(iVar8 + 3) = (char)uVar5;
            if (param_8 != (code *)0x0) {
              uVar6 = (*param_8)(uVar5 & 0xff,*(undefined1 *)(iVar8 + 0xc),
                                 *(undefined1 *)(iVar8 + 0xf));
              *(undefined1 *)(iVar8 + 3) = uVar6;
            }
          }
        }
        else {
          iVar4 = FUN_004081b0(*piVar9 + iVar13);
          if ((int)*(short *)(iVar4 + 0x10) < (int)param_5) {
            bVar1 = *(byte *)(iVar8 + 6);
            if ((int)(uint)*(byte *)(iVar8 + 9) < (int)(bVar1 - 2)) {
              bVar2 = *(byte *)(iVar8 + 3);
              uVar11 = (uint)bVar2;
              uVar5 = (int)param_5 - (int)*(short *)(iVar4 + 0x10) & 0xff;
              if ((int)param_7 < (int)uVar5) {
                uVar5 = param_7 & 0xff;
              }
              if (*(byte *)(iVar8 + 9) < uVar11) {
                *(byte *)(iVar8 + 9) = bVar2;
              }
              cVar7 = bVar1 - 1;
              if ((int)(bVar1 - uVar11) <= (int)uVar5) goto LAB_004b18dc;
              *(byte *)(iVar8 + 3) = (char)uVar5 + bVar2;
              goto LAB_004b18a0;
            }
          }
        }
      }
      else {
        if (param_6 < iVar4) {
          iVar4 = FUN_004081b0();
          for (iVar10 = 1; iVar10 < param_6; iVar10 = iVar10 + 1) {
            iVar4 = FUN_00408680(iVar4);
          }
          sVar3 = *(short *)(iVar4 + 0x10);
        }
        else {
          iVar4 = FUN_00408610(*piVar9 + iVar13);
          sVar3 = *(short *)(iVar4 + 0x10);
        }
        if ((int)param_4 < (int)sVar3) {
          bVar1 = *(byte *)(iVar8 + 9);
          if ((int)(uint)bVar1 < (int)(*(byte *)(iVar8 + 6) - 2)) {
            bVar2 = *(byte *)(iVar8 + 3);
            uVar11 = (uint)bVar2;
            uVar5 = (int)sVar3 - (int)param_4 & 0xff;
            if ((int)param_7 < (int)uVar5) {
              uVar5 = param_7 & 0xff;
            }
            if (uVar11 < *(byte *)(iVar8 + 6)) {
              *(byte *)(iVar8 + 6) = bVar2;
            }
            cVar7 = bVar1 + 1;
            if ((int)uVar5 < (int)(uVar11 - bVar1)) {
              *(byte *)(iVar8 + 3) = bVar2 - (char)uVar5;
            }
            else {
LAB_004b18dc:
              *(char *)(iVar8 + 3) = cVar7;
            }
LAB_004b18a0:
            if (param_8 != (code *)0x0) {
              uVar6 = (*param_8)(*(undefined1 *)(iVar8 + 3),*(undefined1 *)(iVar8 + 0xc),
                                 *(undefined1 *)(iVar8 + 0xf));
              *(undefined1 *)(iVar8 + 3) = uVar6;
            }
            iVar12 = iVar12 + (uint)(*(byte *)(iVar8 + 3) != uVar11);
          }
        }
      }
      iVar8 = iVar8 + 1;
      piVar9 = piVar9 + 1;
    }
    iVar14 = iVar14 + 1;
    param_1 = param_1 + 0x12;
  } while( true );
}

