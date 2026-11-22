// func l_unicode_gbk_spec_code_change @ 00525fd0 size=112

uint l_unicode_gbk_spec_code_change(uint param_1,int param_2)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_006c44e0;
  do {
    if (param_2 == 0) {
      if (param_1 == *puVar2) {
        return (uint)(ushort)(&DAT_006c44e2)[iVar1 * 2];
      }
    }
    else if (param_1 == puVar2[1]) {
      return (uint)(ushort)(&DAT_006c44e0)[iVar1 * 2];
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 2;
  } while (iVar1 != 0x37);
  return param_1 & 0xffff;
}

