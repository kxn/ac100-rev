// func _desEncrypt1 @ 00666f80 size=1972

void _desEncrypt1(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = (param_1[1] >> 4 ^ *param_1) & 0xf0f0f0f;
  uVar6 = uVar3 ^ *param_1;
  uVar4 = uVar3 << 4 ^ param_1[1];
  uVar3 = (uVar6 >> 0x10 ^ uVar4) & 0xffff;
  uVar4 = uVar3 ^ uVar4;
  uVar6 = uVar3 << 0x10 ^ uVar6;
  uVar3 = (uVar4 >> 2 ^ uVar6) & 0x33333333;
  uVar6 = uVar3 ^ uVar6;
  uVar4 = uVar3 << 2 ^ uVar4;
  uVar3 = (uVar6 >> 8 ^ uVar4) & 0xff00ff;
  uVar4 = uVar3 ^ uVar4;
  uVar6 = uVar3 << 8 ^ uVar6;
  uVar1 = (uVar4 >> 1 ^ uVar6) & 0x55555555;
  uVar6 = uVar1 ^ uVar6;
  uVar3 = (uVar6 >> 0x1d) + uVar6 * 8;
  uVar4 = uVar1 << 1 ^ uVar4;
  uVar6 = (uVar4 >> 0x1d) + uVar4 * 8;
  if (param_3 == 0) {
    iVar5 = 0x1e;
    do {
      iVar5 = iVar5 + -8;
      uVar2 = uVar3 ^ param_2[0x1e];
      uVar1 = (uVar3 ^ param_2[0x1f]) >> 4;
      uVar4 = uVar1 + (uVar3 ^ param_2[0x1f]) * 0x10000000;
      uVar2 = uVar6 ^ *(uint *)(&DAT_0071d780 + ((uVar2 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar2 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar4 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar4 = uVar2 ^ param_2[0x1c];
      uVar6 = (uVar2 ^ param_2[0x1d]) >> 4;
      uVar1 = uVar6 + (uVar2 ^ param_2[0x1d]) * 0x10000000;
      uVar7 = uVar3 ^ *(uint *)(&DAT_0071d780 + ((uVar4 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar4 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar1 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar1 = uVar7 ^ param_2[0x1a];
      uVar3 = (uVar7 ^ param_2[0x1b]) >> 4;
      uVar6 = uVar3 + (uVar7 ^ param_2[0x1b]) * 0x10000000;
      uVar6 = uVar2 ^ *(uint *)(&DAT_0071d780 + ((uVar1 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar1 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar6 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar4 = uVar6 ^ param_2[0x18];
      uVar3 = (uVar6 ^ param_2[0x19]) >> 4;
      uVar1 = uVar3 + (uVar6 ^ param_2[0x19]) * 0x10000000;
      param_2 = param_2 + -8;
      uVar3 = uVar7 ^ *(uint *)(&DAT_0071d780 + ((uVar4 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar4 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar1 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    } while (iVar5 != -2);
    uVar3 = (uVar3 >> 3) + uVar3 * 0x20000000;
  }
  else {
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 8;
      uVar2 = uVar3 ^ *param_2;
      uVar1 = (uVar3 ^ param_2[1]) >> 4;
      uVar4 = uVar1 + (uVar3 ^ param_2[1]) * 0x10000000;
      uVar2 = uVar6 ^ *(uint *)(&DAT_0071d780 + ((uVar2 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar2 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar4 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar4 = uVar2 ^ param_2[2];
      uVar6 = (uVar2 ^ param_2[3]) >> 4;
      uVar1 = uVar6 + (uVar2 ^ param_2[3]) * 0x10000000;
      uVar7 = uVar3 ^ *(uint *)(&DAT_0071d780 + ((uVar4 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar4 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar1 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar1 = uVar7 ^ param_2[4];
      uVar3 = (uVar7 ^ param_2[5]) >> 4;
      uVar6 = uVar3 + (uVar7 ^ param_2[5]) * 0x10000000;
      uVar6 = uVar2 ^ *(uint *)(&DAT_0071d780 + ((uVar1 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar1 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar6 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar4 = uVar6 ^ param_2[6];
      uVar3 = (uVar6 ^ param_2[7]) >> 4;
      uVar1 = uVar3 + (uVar6 ^ param_2[7]) * 0x10000000;
      param_2 = param_2 + 8;
      uVar3 = uVar7 ^ *(uint *)(&DAT_0071d780 + ((uVar4 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(&DAT_0071d780 + (uVar4 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(&DAT_0071d780 + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar1 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(&DAT_0071d880 + (uVar1 & 0xfc)) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(&DAT_0071d780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    } while (iVar5 != 0x20);
    uVar3 = (uVar3 >> 3) + uVar3 * 0x20000000;
  }
  uVar1 = (uVar6 >> 3) + uVar6 * 0x20000000;
  uVar6 = (uVar3 >> 1 ^ uVar1) & 0x55555555;
  uVar1 = uVar6 ^ uVar1;
  uVar3 = uVar6 << 1 ^ uVar3;
  uVar6 = (uVar1 >> 8 ^ uVar3) & 0xff00ff;
  uVar3 = uVar6 ^ uVar3;
  uVar1 = uVar6 << 8 ^ uVar1;
  uVar6 = (uVar3 >> 2 ^ uVar1) & 0x33333333;
  uVar1 = uVar6 ^ uVar1;
  uVar3 = uVar6 << 2 ^ uVar3;
  uVar6 = (uVar1 >> 0x10 ^ uVar3) & 0xffff;
  uVar3 = uVar6 ^ uVar3;
  uVar1 = uVar6 << 0x10 ^ uVar1;
  uVar6 = (uVar3 >> 4 ^ uVar1) & 0xf0f0f0f;
  *param_1 = uVar6 ^ uVar1;
  param_1[1] = uVar6 << 4 ^ uVar3;
  return;
}

