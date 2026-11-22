// func uac_codeConv_unicode_to_gbk @ 005261f8 size=364

uint uac_codeConv_unicode_to_gbk(ushort *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (ushort *)0x0) && (param_2 != 0)) {
    iVar7 = 0;
    uVar2 = 0;
    do {
      uVar6 = (uint)*param_1;
      uVar1 = uVar2 + 1;
      if (uVar6 == 0) {
        return uVar2;
      }
      if (param_4 == 1) {
        uVar6 = uVar6 * 0x100 + (uint)(*param_1 >> 8) & 0xffff;
      }
      puVar3 = (undefined1 *)(param_2 + iVar7);
      if (uVar6 < 0x80) {
        iVar7 = iVar7 + 1;
        *puVar3 = (char)uVar6;
      }
      else if (((uVar6 < g_unicode_first_code) || (g_unicode_last_code < uVar6)) ||
              (iVar4 = uVar6 - g_unicode_first_code, (int)(uint)g_unicode_to_gbk_buf_size <= iVar4))
      {
        uVar5 = l_unicode_gbk_spec_code_change(uVar6,0);
        puVar3 = (undefined1 *)(param_2 + iVar7);
        iVar7 = iVar7 + 2;
        *puVar3 = (char)((ushort)uVar5 >> 8);
        puVar3[1] = (char)uVar5;
      }
      else {
        uVar5 = *(undefined2 *)(g_unicode_to_gbk_buf + iVar4 * 2);
        puVar3 = (undefined1 *)(param_2 + iVar7);
        iVar7 = iVar7 + 2;
        puVar3[1] = (char)uVar5;
        *puVar3 = (char)((ushort)uVar5 >> 8);
      }
      param_1 = param_1 + 1;
      uVar2 = uVar1;
    } while (uVar1 < param_3);
  }
  return uVar1;
}

