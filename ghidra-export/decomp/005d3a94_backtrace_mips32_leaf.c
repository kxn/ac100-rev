// func backtrace_mips32_leaf @ 005d3a94 size=452

int backtrace_mips32_leaf(undefined4 *param_1,int param_2,int param_3)

{
  Elf32_Ehdr *pEVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  Elf32_Ehdr *pEVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = 0;
  if ((((param_2 != 0) && (iVar6 = -1, param_1 != (undefined4 *)0x0)) && (-1 < param_2)) &&
     (iVar6 = -1, param_3 != 0)) {
    pEVar1 = *(Elf32_Ehdr **)(param_3 + 0x124);
    iVar6 = 1;
    iVar10 = *(int *)(param_3 + 0x114);
    pEVar7 = *(Elf32_Ehdr **)(param_3 + 0x24);
    *param_1 = pEVar7;
    if (param_2 != 1) {
      while( true ) {
        iVar6 = isAddrExcecuted(pEVar7);
        if ((iVar6 == 0) || (pEVar7 < &__DT_MIPS_BASE_ADDRESS)) goto LAB_005d3b60;
        uVar2._0_1_ = pEVar7->e_ident_magic_num;
        uVar2._1_1_ = pEVar7->e_ident_magic_str[0];
        uVar2._2_1_ = pEVar7->e_ident_magic_str[1];
        uVar2._3_1_ = pEVar7->e_ident_magic_str[2];
        if ((uVar2 & 0xffff0000) == 0x27bd0000) break;
        if ((uVar2 == 0xf821) || (pEVar7 = (Elf32_Ehdr *)&pEVar7[-1].e_shnum, uVar2 == 0x3e00008))
        goto LAB_005d3b60;
      }
      if ((short)uVar2 < 0) {
        iVar10 = iVar10 - (short)uVar2;
      }
LAB_005d3b60:
      iVar6 = 1;
      while (pEVar1 != (Elf32_Ehdr *)0x0) {
        iVar11 = 0;
        param_1[1] = pEVar1;
        iVar8 = 0;
        do {
          iVar3 = isAddrExcecuted(pEVar1);
          if (iVar3 == 0) {
            return iVar6 + 1;
          }
          if (pEVar1 < &__DT_MIPS_BASE_ADDRESS) {
            return iVar6 + 1;
          }
          uVar4._0_1_ = pEVar1->e_ident_magic_num;
          uVar4._1_1_ = pEVar1->e_ident_magic_str[0];
          uVar4._2_1_ = pEVar1->e_ident_magic_str[1];
          uVar4._3_1_ = pEVar1->e_ident_magic_str[2];
          sVar5 = (short)uVar4;
          if ((uVar4 & 0xffff0000) == 0xafbf0000) {
            iVar8 = (int)sVar5;
          }
          else if ((uVar4 & 0xffff0000) == 0x27bd0000) {
            iVar11 = -(int)sVar5;
            if (-1 < sVar5) {
LAB_005d3c40:
              return iVar6 + 1;
            }
          }
          else {
            if (uVar4 == 0xf821) goto LAB_005d3c40;
            if (uVar4 == 0x3e00008) {
              return iVar6 + 1;
            }
          }
          pEVar1 = (Elf32_Ehdr *)&pEVar1[-1].e_shnum;
        } while ((iVar8 == 0) || (iVar11 == 0));
        puVar9 = (undefined4 *)(iVar10 + iVar8);
        iVar6 = iVar6 + 1;
        iVar10 = iVar10 + iVar11;
        pEVar1 = (Elf32_Ehdr *)*puVar9;
        param_1 = param_1 + 1;
        if (param_2 <= iVar6) {
          return iVar6;
        }
      }
    }
  }
  return iVar6;
}

