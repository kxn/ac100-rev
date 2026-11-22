// func backtrace_mips32_notleaf @ 005d3c58 size=532

int backtrace_mips32_notleaf(undefined4 *param_1,int param_2,int param_3)

{
  Elf32_Ehdr *pEVar1;
  int iVar2;
  uint uVar3;
  short sVar6;
  int iVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  Elf32_Ehdr *pEVar9;
  undefined4 *puVar10;
  int iVar11;
  
  iVar7 = 0;
  if ((((param_2 != 0) && (iVar7 = -1, param_1 != (undefined4 *)0x0)) && (-1 < param_2)) &&
     (iVar7 = -1, param_3 != 0)) {
    pEVar1 = *(Elf32_Ehdr **)(param_3 + 0x124);
    iVar7 = 1;
    pEVar9 = *(Elf32_Ehdr **)(param_3 + 0x24);
    iVar11 = *(int *)(param_3 + 0x114);
    *param_1 = pEVar9;
    if (param_2 != 1) {
      iVar7 = 0;
      iVar8 = 0;
      do {
        iVar2 = isAddrExcecuted(pEVar9);
        if (iVar2 == 0) {
          return 1;
        }
        if (pEVar9 < &__DT_MIPS_BASE_ADDRESS) {
          return 1;
        }
        uVar3._0_1_ = pEVar9->e_ident_magic_num;
        uVar3._1_1_ = pEVar9->e_ident_magic_str[0];
        uVar3._2_1_ = pEVar9->e_ident_magic_str[1];
        uVar3._3_1_ = pEVar9->e_ident_magic_str[2];
        sVar6 = (short)uVar3;
        if ((uVar3 & 0xffff0000) == 0xafbf0000) {
          iVar8 = (int)sVar6;
        }
        else if ((uVar3 & 0xffff0000) == 0x27bd0000) {
          if (-1 < sVar6) {
LAB_005d3e5c:
            if (iVar8 == 0) goto LAB_005d3da0;
            break;
          }
          iVar7 = -(int)sVar6;
        }
        else {
          if (uVar3 == 0x3e00008) goto LAB_005d3e5c;
          if (uVar3 == 0xf821) {
            return 1;
          }
        }
        pEVar9 = (Elf32_Ehdr *)&pEVar9[-1].e_shnum;
      } while ((iVar8 == 0) || (iVar7 == 0));
      pEVar1 = *(Elf32_Ehdr **)(iVar11 + iVar8);
LAB_005d3da0:
      iVar11 = iVar11 + iVar7;
      iVar7 = 1;
      while (pEVar1 != (Elf32_Ehdr *)0x0) {
        iVar8 = 0;
        param_1[1] = pEVar1;
        iVar2 = 0;
        do {
          iVar4 = isAddrExcecuted(pEVar1);
          if (iVar4 == 0) {
            return iVar7 + 1;
          }
          if (pEVar1 < &__DT_MIPS_BASE_ADDRESS) {
            return iVar7 + 1;
          }
          uVar5._0_1_ = pEVar1->e_ident_magic_num;
          uVar5._1_1_ = pEVar1->e_ident_magic_str[0];
          uVar5._2_1_ = pEVar1->e_ident_magic_str[1];
          uVar5._3_1_ = pEVar1->e_ident_magic_str[2];
          sVar6 = (short)uVar5;
          if ((uVar5 & 0xffff0000) == 0xafbf0000) {
            iVar2 = (int)sVar6;
          }
          else if ((uVar5 & 0xffff0000) == 0x27bd0000) {
            iVar8 = -(int)sVar6;
            if (-1 < sVar6) {
LAB_005d3d44:
              return iVar7 + 1;
            }
          }
          else {
            if (uVar5 == 0xf821) goto LAB_005d3d44;
            if (uVar5 == 0x3e00008) {
              return iVar7 + 1;
            }
          }
          pEVar1 = (Elf32_Ehdr *)&pEVar1[-1].e_shnum;
        } while ((iVar2 == 0) || (iVar8 == 0));
        puVar10 = (undefined4 *)(iVar11 + iVar2);
        iVar7 = iVar7 + 1;
        iVar11 = iVar11 + iVar8;
        pEVar1 = (Elf32_Ehdr *)*puVar10;
        param_1 = param_1 + 1;
        if (param_2 <= iVar7) {
          return iVar7;
        }
      }
    }
  }
  return iVar7;
}

