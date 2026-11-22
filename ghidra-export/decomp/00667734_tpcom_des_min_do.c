// func tpcom_des_min_do @ 00667734 size=1644

int tpcom_des_min_do(byte *param_1,int param_2,byte *param_3,int param_4,byte *param_5,int param_6)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  byte *pbVar12;
  int *piVar13;
  byte *pbVar14;
  uint local_a8;
  uint local_a4;
  int local_a0 [32];
  
  iVar5 = 0;
  if ((((param_1 != (byte *)0x0) && (param_2 != 0)) && (param_3 != (byte *)0x0)) &&
     (((param_4 != 0 && (param_5 != (byte *)0x0)) && (param_2 <= param_4 + -8)))) {
    uVar6 = (uint)param_5[1] << 8 | (uint)param_5[2] << 0x10 | (uint)*param_5 |
            (uint)param_5[3] << 0x18;
    uVar9 = (uint)param_5[5] << 8 | (uint)param_5[6] << 0x10 | (uint)param_5[4] |
            (uint)param_5[7] << 0x18;
    uVar8 = (uVar9 >> 4 ^ uVar6) & 0xf0f0f0f;
    uVar6 = uVar8 ^ uVar6;
    uVar9 = uVar8 << 4 ^ uVar9;
    uVar10 = (uVar6 << 0x12 ^ uVar6) & 0xcccc0000;
    uVar8 = (uVar9 << 0x12 ^ uVar9) & 0xcccc0000;
    uVar6 = uVar10 ^ uVar6 ^ uVar10 >> 0x12;
    uVar9 = uVar8 ^ uVar9 ^ uVar8 >> 0x12;
    uVar8 = (uVar9 >> 1 ^ uVar6) & 0x55555555;
    uVar6 = uVar8 ^ uVar6;
    uVar9 = uVar8 << 1 ^ uVar9;
    uVar8 = (uVar6 >> 8 ^ uVar9) & 0xff00ff;
    uVar9 = uVar8 ^ uVar9;
    uVar6 = uVar8 << 8 ^ uVar6;
    uVar8 = (uVar9 >> 1 ^ uVar6) & 0x55555555;
    uVar6 = uVar8 ^ uVar6;
    uVar9 = uVar8 << 1 ^ uVar9;
    uVar8 = (uVar6 & 0xf0000000) >> 4 | uVar9 & 0xff00 | (uVar9 & 0xff) << 0x10 |
            (uVar9 << 8) >> 0x18;
    uVar6 = uVar6 & 0xfffffff;
    piVar13 = &DAT_0071cf40;
    piVar11 = local_a0;
    do {
      if (*piVar13 == 0) {
        uVar10 = uVar6 << 0x1b | uVar6 >> 1;
        uVar9 = uVar8 >> 1;
        uVar8 = uVar8 << 0x1b;
      }
      else {
        uVar10 = uVar6 << 0x1a | uVar6 >> 2;
        uVar9 = uVar8 >> 2;
        uVar8 = uVar8 << 0x1a;
      }
      uVar3 = uVar10 << 4;
      uVar6 = uVar10 & 0xfffffff;
      uVar4 = (uVar8 | uVar9) << 4;
      uVar8 = uVar8 & 0xfffffff | uVar9;
      uVar10 = *(uint *)(&DAT_0071cf80 +
                        ((uVar3 >> 0xb & 0x3c | (uVar6 << 0x18) >> 0x1e) + 0x40) * 4) |
               *(uint *)(&DAT_0071cf80 +
                        ((uVar3 >> 0x12 & 0x30 | (uVar6 << 0xf) >> 0x1c) + 0x80) * 4) |
               *(uint *)(&DAT_0071cf80 + (uVar10 & 0x3f) * 4) |
               *(uint *)(&DAT_0071cf80 +
                        ((uVar3 >> 0x19 & 6 | (uVar6 << 0xb) >> 0x1f | uVar3 >> 0x1a & 0x38) + 0xc0)
                        * 4);
      uVar9 = *(uint *)(&DAT_0071cf80 + (((uVar9 << 0xb) >> 0x1a) + 0x180) * 4) |
              *(uint *)(&DAT_0071cf80 + ((uVar9 & 0x3f) + 0x100) * 4) |
              *(uint *)(&DAT_0071cf80 +
                       ((uVar4 >> 0xc & 0x3c | (uVar9 << 0x17) >> 0x1e) + 0x140) * 4) |
              *(uint *)(&DAT_0071cf80 + ((uVar4 >> 0x1a & 0x30 | (uVar9 << 7) >> 0x1c) + 0x1c0) * 4)
      ;
      *piVar11 = ((uVar9 << 0x10) >> 0x1e) + (uVar10 & 0xffff | uVar9 << 0x10) * 4;
      piVar11[1] = (uVar9 >> 0x1a) + (uVar10 >> 0x10 | uVar9 & 0xffff0000) * 0x40;
      piVar11 = piVar11 + 2;
      piVar13 = piVar13 + 1;
    } while (piVar11 != (int *)&stack0xffffffe0);
    pbVar14 = param_3;
    if (param_6 == 0) {
      for (; iVar5 = (int)pbVar14 - (int)param_3, 0 < param_2; param_2 = param_2 + -8) {
        local_a4 = (uint)param_1[5] << 8 | (uint)param_1[6] << 0x10 | (uint)param_1[4] |
                   (uint)param_1[7] << 0x18;
        local_a8 = (uint)param_1[1] << 8 | (uint)param_1[2] << 0x10 | (uint)*param_1 |
                   (uint)param_1[3] << 0x18;
        _desEncrypt1(&local_a8,local_a0,0);
        *pbVar14 = (byte)local_a8;
        pbVar14[4] = (byte)local_a4;
        pbVar14[1] = (byte)(local_a8 >> 8);
        pbVar14[2] = (byte)(local_a8 >> 0x10);
        pbVar14[3] = (byte)(local_a8 >> 0x18);
        pbVar14[5] = (byte)(local_a4 >> 8);
        uVar6 = local_a4 >> 0x18;
        pbVar14[6] = (byte)(local_a4 >> 0x10);
        pbVar7 = pbVar14 + 8;
        pbVar14[7] = (byte)(local_a4 >> 0x18);
        if (param_2 < 9) {
          pbVar12 = pbVar7;
          for (iVar5 = 1; iVar5 <= (int)uVar6; iVar5 = iVar5 + 1) {
            pbVar12 = pbVar12 + -1;
            if (*pbVar12 != uVar6) {
              pbVar14[8] = 0;
              return 0;
            }
          }
          pbVar7 = pbVar7 + -uVar6;
          *pbVar7 = 0;
        }
        param_1 = param_1 + 8;
        pbVar14 = pbVar7;
      }
    }
    else {
      uVar6 = -param_2;
      while( true ) {
        uVar8 = uVar6 + 8;
        iVar5 = (int)pbVar14 - (int)param_3;
        if (param_2 < 0) break;
        if (param_2 < 8) {
          if (param_2 == 0) {
            local_a8 = 0x8080808;
            local_a4 = local_a8;
            goto LAB_00667b08;
          }
          pbVar7 = param_1 + param_2;
          switch(param_2) {
          case 2:
            uVar9 = 0;
            local_a8 = 0;
            goto LAB_00667d3c;
          case 3:
            uVar9 = 0;
            local_a8 = 0;
            goto LAB_00667d2c;
          case 4:
            uVar9 = 0;
            goto LAB_00667d20;
          case 5:
            uVar9 = 0;
            goto LAB_00667d14;
          case 6:
            uVar9 = 0;
            break;
          case 7:
            pbVar12 = pbVar7 + -1;
            pbVar7 = pbVar7 + -1;
            uVar9 = (uint)*pbVar12 << 0x10;
            break;
          default:
            uVar9 = 0;
            local_a8 = 0;
            goto LAB_00667c8c;
          }
          pbVar12 = pbVar7 + -1;
          pbVar7 = pbVar7 + -1;
          uVar9 = (uint)*pbVar12 << 8 | uVar9;
LAB_00667d14:
          pbVar12 = pbVar7 + -1;
          pbVar7 = pbVar7 + -1;
          uVar9 = *pbVar12 | uVar9;
LAB_00667d20:
          pbVar12 = pbVar7 + -1;
          pbVar7 = pbVar7 + -1;
          local_a8 = (uint)*pbVar12 << 0x18;
LAB_00667d2c:
          pbVar12 = pbVar7 + -1;
          pbVar7 = pbVar7 + -1;
          local_a8 = (uint)*pbVar12 << 0x10 | local_a8;
LAB_00667d3c:
          pbVar12 = pbVar7 + -1;
          pbVar7 = pbVar7 + -1;
          local_a8 = (uint)*pbVar12 << 8 | local_a8;
LAB_00667c8c:
          param_1 = pbVar7 + -1;
          local_a8 = pbVar7[-1] | local_a8;
          switch(uVar6) {
          case 0xffffffff:
            local_a8 = local_a8 | 0x700;
          case 0xfffffffe:
            local_a8 = local_a8 | uVar8 * 0x10000;
          case 0xfffffffd:
            local_a8 = local_a8 | uVar8 * 0x1000000;
          case 0xfffffffc:
            uVar9 = uVar9 | uVar8;
          case 0xfffffffb:
            uVar9 = uVar9 | uVar8 * 0x100;
          case 0xfffffffa:
            uVar9 = uVar9 | uVar8 * 0x10000;
          default:
            local_a4 = uVar9 | uVar8 * 0x1000000;
          }
        }
        else {
          pbVar7 = param_1 + 5;
          pbVar12 = param_1 + 4;
          local_a8 = (uint)param_1[1] << 8 | (uint)param_1[2] << 0x10 | (uint)*param_1 |
                     (uint)param_1[3] << 0x18;
          pbVar1 = param_1 + 6;
          pbVar2 = param_1 + 7;
          param_1 = param_1 + 8;
          local_a4 = (uint)*pbVar7 << 8 | (uint)*pbVar1 << 0x10 | (uint)*pbVar12 |
                     (uint)*pbVar2 << 0x18;
        }
LAB_00667b08:
        param_2 = param_2 + -8;
        _desEncrypt1(&local_a8,local_a0,1);
        *pbVar14 = (byte)local_a8;
        pbVar14[4] = (byte)local_a4;
        pbVar14[1] = (byte)(local_a8 >> 8);
        pbVar14[2] = (byte)(local_a8 >> 0x10);
        pbVar14[3] = (byte)(local_a8 >> 0x18);
        pbVar14[5] = (byte)(local_a4 >> 8);
        pbVar14[6] = (byte)(local_a4 >> 0x10);
        pbVar14[7] = (byte)(local_a4 >> 0x18);
        pbVar14 = pbVar14 + 8;
        uVar6 = uVar8;
      }
    }
  }
  return iVar5;
}

