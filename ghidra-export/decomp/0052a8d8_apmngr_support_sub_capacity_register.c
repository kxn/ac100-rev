// func apmngr_support_sub_capacity_register @ 0052a8d8 size=204

undefined4 apmngr_support_sub_capacity_register(uint param_1,uint param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0xffffffff;
  if (((param_1 < 0x60) && (-1 < (int)param_2)) && ((int)param_2 < 0x20)) {
    if ((&sub_cap_index)[param_1] == -1) {
      uVar3 = (uint)sub_cap_num;
      (&sub_cap_index)[param_1] = (char)sub_cap_num;
      sub_cap_num = sub_cap_num + 1;
      (&sub_cap_supp)[uVar3 * 4] = (short)param_1;
    }
    iVar4 = ((int)param_2 >> 3) + 1;
    bVar1 = (&sub_cap_index)[param_1];
    iVar5 = (uint)bVar1 * 8;
    if ((int)(uint)*(ushort *)(&DAT_007c549a + iVar5) < iVar4) {
      *(short *)(&DAT_007c549a + iVar5) = (short)iVar4;
    }
    iVar4 = (uint)bVar1 * 8 - ((int)param_2 >> 3);
    (&DAT_007c549f)[iVar4] = (&DAT_007c549f)[iVar4] | (byte)(1 << (param_2 & 7));
    uVar2 = 0;
  }
  return uVar2;
}

