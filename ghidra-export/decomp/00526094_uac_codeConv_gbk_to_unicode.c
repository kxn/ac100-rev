// func uac_codeConv_gbk_to_unicode @ 00526094 size=356

uint uac_codeConv_gbk_to_unicode(int param_1,ushort *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  ushort uVar4;
  uint uVar3;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (ushort *)0x0)) {
    iVar7 = 0;
    uVar6 = 1;
    do {
      uVar1 = uVar6;
      pbVar5 = (byte *)(param_1 + iVar7);
      uVar6 = (uint)*pbVar5;
      if (uVar6 == 0) {
        return uVar1 - 1;
      }
      if (uVar6 < 0x81) {
        iVar7 = iVar7 + 1;
        *param_2 = (ushort)*pbVar5;
      }
      else {
        if (param_4 == 1) {
          uVar6 = uVar6 << 8;
          uVar3 = (uint)pbVar5[1];
        }
        else {
          uVar3 = (uint)pbVar5[1] << 8;
        }
        uVar6 = uVar3 + uVar6 & 0xffff;
        iVar7 = iVar7 + 2;
        if (((uVar6 < g_gbk_first_code) || (g_gbk_last_code < uVar6)) ||
           (iVar2 = uVar6 - g_gbk_first_code, (int)(uint)g_gbk_to_unicode_buf_size <= iVar2)) {
          uVar4 = l_unicode_gbk_spec_code_change(uVar6,1);
        }
        else {
          uVar4 = *(ushort *)(&g_gbk_to_unicode_buf + iVar2 * 2);
        }
        *param_2 = uVar4;
      }
      param_2 = param_2 + 1;
      uVar6 = uVar1 + 1;
    } while (uVar1 <= param_3 - 1U);
  }
  return uVar1;
}

