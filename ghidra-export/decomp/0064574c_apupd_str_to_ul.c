// func apupd_str_to_ul @ 0064574c size=380

uint apupd_str_to_ul(char *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  pcVar5 = param_1;
  do {
    pcVar2 = pcVar5;
    iVar4 = (int)*pcVar2;
    pcVar5 = pcVar2 + 1;
  } while (iVar4 == 0x20);
  if (iVar4 == 0x2d) {
    iVar4 = (int)pcVar2[1];
    pcVar5 = pcVar2 + 2;
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if (iVar4 == 0x2b) {
      iVar4 = (int)pcVar2[1];
      pcVar5 = pcVar2 + 2;
    }
  }
  if ((param_3 == 0) || (param_3 == 0x10)) {
    if ((iVar4 == 0x30) && ((*pcVar5 == 'x' || (*pcVar5 == 'X')))) {
      iVar4 = (int)pcVar5[1];
      param_3 = 0x10;
      pcVar5 = pcVar5 + 2;
    }
    else if ((param_3 == 0) && (param_3 = 8, iVar4 != 0x30)) {
      param_3 = 10;
    }
  }
  iVar6 = 0;
  if (param_3 == 0) {
    trap(7);
  }
  uVar3 = 0;
LAB_006457b4:
  do {
    uVar7 = iVar4 - 0x30;
    if (9 < uVar7) {
      iVar8 = 0x37;
      if ((0x19 < iVar4 - 0x41U) && (iVar8 = 0x57, 0x19 < iVar4 - 0x61U)) {
LAB_00645860:
        if (iVar6 == -1) {
          uVar3 = 0xffffffff;
        }
        else if (bVar1) {
          uVar3 = -uVar3;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar6 != 0) {
            param_1 = pcVar5 + -1;
          }
          *param_2 = param_1;
        }
        return uVar3;
      }
      uVar7 = iVar4 - iVar8;
    }
    if ((int)param_3 <= (int)uVar7) goto LAB_00645860;
    if ((iVar6 != -1) && (iVar6 = -1, uVar3 <= 0xffffffff / param_3)) {
      if ((uVar3 == 0xffffffff / param_3) && ((int)(0xffffffffU % param_3) < (int)uVar7)) {
        iVar4 = (int)*pcVar5;
        pcVar5 = pcVar5 + 1;
        goto LAB_006457b4;
      }
      iVar6 = 1;
      uVar3 = uVar7 + uVar3 * param_3;
    }
    iVar4 = (int)*pcVar5;
    pcVar5 = pcVar5 + 1;
  } while( true );
}

