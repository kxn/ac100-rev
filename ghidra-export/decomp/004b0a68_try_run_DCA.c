// func try_run_DCA @ 004b0a68 size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
try_run_DCA(int param_1,int param_2,int param_3,short param_4,undefined4 param_5,int param_6)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  ushort *__s;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  short *psVar11;
  undefined4 uVar12;
  ushort *puVar13;
  uint uVar14;
  undefined1 uVar15;
  uint uVar16;
  int iVar17;
  ushort *puVar18;
  uint uVar19;
  ushort *puVar20;
  int iVar21;
  size_t __n;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  undefined8 uVar33;
  int iStack_80;
  int iStack_78;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  
  __n = param_1 * 0x2a * param_2 * param_3;
  __s = (ushort *)FUN_00408450(__n,0x127);
  memset(__s,0,__n);
  iVar4 = param_1 * param_2;
  iVar25 = iVar4 * param_3;
  puVar13 = __s;
  for (iVar5 = 0; iVar5 < iVar25; iVar5 = iVar5 + 1) {
    *puVar13 = (ushort)iVar5;
    puVar13 = puVar13 + 0x15;
  }
  iVar6 = FUN_00408450(iVar25 * 0xc,0x12e);
  iVar7 = FUN_00408450(iVar25 * 0xc,0x12f);
  iVar5 = iVar25 * param_1 * param_2 * param_3 * 0x28;
  iVar8 = FUN_00408450(iVar5,0x131);
  iVar9 = FUN_00408450(iVar5,0x133);
  iVar5 = iVar6;
  for (iVar24 = 0; iVar24 < iVar25; iVar24 = iVar24 + 1) {
    FUN_0051ad88(iVar5);
    iVar27 = (iVar7 - iVar6) + iVar5;
    iVar5 = iVar5 + 0xc;
    FUN_0051ad88(iVar27);
  }
  iStack_68 = 0;
  iVar5 = 0;
  if (-1 < param_3) {
    iVar5 = param_3;
  }
  iVar24 = 0;
  if (-1 < param_2) {
    iVar24 = param_2;
  }
  iStack_80 = 0;
  do {
    if (param_1 <= iStack_80) {
      iVar4 = func_0x00406f50();
      if (_rrm_test_dump_switch != 0) {
        puts("-----before run_DCA():-----");
        puVar13 = __s;
        for (iVar5 = 0; iVar5 < iVar25; iVar5 = iVar5 + 1) {
          printf("apid:%d total itf:%d\n",(uint)*puVar13,(int)(short)puVar13[5]);
          iVar24 = 0;
          puVar18 = puVar13;
          while (iVar24 < param_6) {
            printf("\tradio:%d, channel:%d, interfer:%d\n",iVar24 + 1,
                   (int)*(char *)((int)puVar13 + iVar24 + 3),(uint)puVar18[6]);
            iVar24 = iVar24 + 1;
            puVar18 = puVar18 + 1;
          }
          puVar13 = puVar13 + 0x15;
        }
      }
      puts("Running DCA...");
      run_DCA(__s,iVar25,6,param_5,iVar6,iVar7);
      iVar5 = func_0x00406f50();
      uVar33 = __floatsidf(iVar5 - iVar4);
      __divdf3((int)((ulonglong)uVar33 >> 0x20),(int)uVar33,0x412e8480,0);
      printf("DCA finished,total cost time:%fs\n");
      if (_rrm_test_dump_switch != 0) {
        puts("-----after run_DCA():-----");
        puVar13 = __s;
        for (iVar4 = 0; iVar4 < iVar25; iVar4 = iVar4 + 1) {
          printf("apid:%d total itf:%d\n",(uint)*puVar13,(int)(short)puVar13[5]);
          iVar5 = 0;
          puVar18 = puVar13;
          while (iVar5 < param_6) {
            printf("\tradio:%d, channel:%d, interfer:%d\n",iVar5 + 1,
                   (int)*(char *)((int)puVar13 + iVar5 + 3),(uint)puVar18[6]);
            iVar5 = iVar5 + 1;
            puVar18 = puVar18 + 1;
          }
          puVar13 = puVar13 + 0x15;
        }
      }
      FUN_00407df0(iVar8);
      FUN_00407df0(iVar9);
      FUN_00407df0(iVar6);
      FUN_00407df0(iVar7);
      FUN_00407df0(__s);
      return 0;
    }
    iVar27 = iStack_68;
    for (iVar30 = 0; iVar30 < param_2; iVar30 = iVar30 + 1) {
      puVar13 = __s + iVar27 * 0x15;
      iStack_6c = iVar6 + iVar27 * 0xc;
      iStack_70 = iVar8 + iVar27 * param_1 * param_2 * param_3 * 0x28;
      iStack_78 = iVar27;
      for (iVar29 = 0; iVar29 < param_3; iVar29 = iVar29 + 1) {
        uVar15 = (undefined1)param_6;
        *(undefined1 *)(puVar13 + 1) = uVar15;
        iVar22 = (iVar9 - iVar8) + iStack_70;
        iVar23 = iStack_70;
        iVar28 = iVar7;
        for (iVar26 = 0; iVar26 < iVar25; iVar26 = iVar26 + 1) {
          if (iVar4 == 0) {
            trap(7);
          }
          if (param_1 == 0) {
            trap(7);
          }
          iVar32 = (iVar26 % iVar4) / param_1;
          iVar31 = (iVar26 % iVar4) % param_1;
          if (iVar31 == iStack_80) {
            if (iVar32 != iVar30) {
              uVar16 = iVar32 - iVar30;
              goto code_r0x004b0cb4;
            }
            if (iVar26 / iVar4 != iVar29) {
              uVar16 = iVar32 - iVar30;
              goto code_r0x004b0cb4;
            }
          }
          else {
            uVar16 = iVar32 - iVar30;
code_r0x004b0cb4:
            uVar10 = iVar26 / iVar4 - iVar29;
            uVar14 = iVar31 - iStack_80;
            uVar19 = (int)uVar14 >> 0x1f;
            iVar17 = (uVar19 ^ uVar14) - uVar19;
            uVar14 = (int)uVar10 >> 0x1f;
            iVar32 = ((int)uVar16 >> 0x1f ^ uVar16) - ((int)uVar16 >> 0x1f);
            iVar31 = (uVar14 ^ uVar10) - uVar14;
            if (iVar17 + iVar32 + iVar31 == 1) {
              *(short *)(iVar23 + 0xc) = (short)iVar26;
              sVar3 = ((param_4 - (short)iVar31) - (short)iVar17) - (short)iVar32;
              *(undefined1 *)(iVar23 + 0xe) = uVar15;
              *(undefined1 *)(iVar22 + 0xe) = uVar15;
              *(short *)(iVar22 + 0xc) = (short)iStack_78;
              iVar31 = iVar22;
              for (iVar32 = 0; iVar32 < param_6; iVar32 = iVar32 + 1) {
                iVar17 = 0;
                psVar11 = (short *)(iVar23 + iVar32 * 6 + 0x12);
                puVar18 = puVar13;
                puVar20 = puVar13;
                while( true ) {
                  if (param_6 <= iVar17) break;
                  *(short *)(iVar23 + 0x10) = sVar3 + *(short *)(iVar23 + 0x10);
                  *psVar11 = sVar3;
                  *(short *)(iVar22 + 0x10) = sVar3 + *(short *)(iVar22 + 0x10);
                  iVar21 = iVar17 * 2;
                  iVar17 = iVar17 + 1;
                  *(short *)(iVar31 + iVar21 + 0x12) = sVar3;
                  puVar18[9] = puVar18[9] + *psVar11;
                  puVar20[6] = puVar20[6] + *psVar11;
                  sVar2 = *psVar11;
                  psVar11 = psVar11 + 1;
                  puVar13[5] = sVar2 + puVar13[5];
                  *(int *)(iVar23 + 0x24) = iVar22;
                  *(int *)(iVar22 + 0x24) = iVar23;
                  puVar18 = puVar18 + 4;
                  puVar20 = puVar20 + 1;
                }
                iVar31 = iVar31 + 6;
              }
              FUN_004086b0(iStack_6c,iVar23);
              FUN_004086b0(iVar28,iVar22);
            }
          }
          iVar23 = iVar23 + 0x28;
          iVar22 = iVar22 + 0x28;
          iVar28 = iVar28 + 0xc;
        }
        uVar1 = puVar13[5];
        puVar13 = puVar13 + 0x15;
        uVar12 = FUN_00407fe0(iStack_6c);
        printf("ap_id(%d)\'s itf is %d list_size is %d\n",iStack_78,(int)(short)uVar1,uVar12);
        iStack_78 = iStack_78 + 1;
        iStack_6c = iStack_6c + 0xc;
        iStack_70 = iStack_70 + iVar25 * 0x28;
      }
      iVar27 = iVar27 + iVar5;
    }
    iStack_80 = iStack_80 + 1;
    iStack_68 = iStack_68 + iVar5 * iVar24;
  } while( true );
}

