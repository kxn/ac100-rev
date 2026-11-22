// func try_run_DCA_new @ 004b10dc size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 try_run_DCA_new(int param_1,ushort param_2,undefined4 param_3,int param_4,int param_5)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  ushort *__s;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  ushort *puVar10;
  int iVar11;
  uint uVar12;
  undefined1 uVar14;
  int iVar13;
  ushort *puVar15;
  ushort *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined8 uVar23;
  int iStack_58;
  int iStack_48;
  
  uVar12 = (uint)param_2;
  __s = (ushort *)FUN_00408450(param_1 * 0x2a,0x19b);
  memset(__s,0,param_1 * 0x2a);
  puVar10 = __s;
  for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
    *puVar10 = (ushort)iVar4;
    puVar10 = puVar10 + 0x15;
  }
  iVar5 = FUN_00408450(param_1 * 0xc,0x1a4);
  iVar6 = FUN_00408450(param_1 * 0xc,0x1a5);
  iVar4 = param_1 * param_1 * 0x28;
  iVar7 = FUN_00408450(iVar4,0x1a7);
  iVar8 = FUN_00408450(iVar4,0x1a9);
  iVar4 = iVar5;
  for (iVar19 = 0; iVar19 < param_1; iVar19 = iVar19 + 1) {
    FUN_0051ad88(iVar4);
    iVar20 = (iVar6 - iVar5) + iVar4;
    iVar4 = iVar4 + 0xc;
    FUN_0051ad88(iVar20);
  }
  iStack_58 = 0;
  puVar10 = __s;
  iStack_48 = iVar5;
  for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
    iVar22 = 1;
    uVar14 = (undefined1)param_4;
    *(undefined1 *)(puVar10 + 1) = uVar14;
    iVar20 = (iStack_58 + 1) * 0x28;
    iVar19 = iVar7 + iVar20;
    iVar20 = iVar8 + iVar20;
    while( true ) {
      if (param_5 / 2 < iVar22) break;
      iVar21 = iVar4 - iVar22;
      if (iVar4 < iVar22) {
        iVar21 = (iVar4 + param_1) - iVar22;
      }
      *(short *)(iVar19 + 0xc) = (short)iVar21;
      *(undefined1 *)(iVar19 + 0xe) = uVar14;
      if (uVar12 == 0) {
        trap(7);
      }
      *(undefined1 *)(iVar20 + 0xe) = uVar14;
      *(short *)(iVar20 + 0xc) = (short)iVar4;
      sVar3 = param_2 - (short)((iVar4 + iVar21) % (int)uVar12);
      iVar17 = iVar20;
      for (iVar11 = 0; iVar11 < param_4; iVar11 = iVar11 + 1) {
        iVar13 = 0;
        psVar9 = (short *)(iVar19 + iVar11 * 6 + 0x12);
        puVar15 = puVar10;
        puVar16 = puVar10;
        while( true ) {
          if (param_4 <= iVar13) break;
          *(short *)(iVar19 + 0x10) = sVar3 + *(short *)(iVar19 + 0x10);
          *psVar9 = sVar3;
          *(short *)(iVar20 + 0x10) = sVar3 + *(short *)(iVar20 + 0x10);
          iVar18 = iVar13 * 2;
          iVar13 = iVar13 + 1;
          *(short *)(iVar17 + iVar18 + 0x12) = sVar3;
          puVar15[9] = puVar15[9] + *psVar9;
          puVar16[6] = puVar16[6] + *psVar9;
          sVar1 = *psVar9;
          psVar9 = psVar9 + 1;
          puVar10[5] = sVar1 + puVar10[5];
          *(int *)(iVar19 + 0x24) = iVar20;
          *(int *)(iVar20 + 0x24) = iVar19;
          puVar15 = puVar15 + 4;
          puVar16 = puVar16 + 1;
        }
        iVar17 = iVar17 + 6;
      }
      iVar22 = iVar22 + 1;
      FUN_004086b0(iStack_48,iVar19);
      FUN_004086b0(iVar6 + iVar21 * 0xc,iVar20);
      iVar19 = iVar19 + 0x28;
      iVar20 = iVar20 + 0x28;
      iStack_58 = iStack_58 + 1;
    }
    iVar20 = (iStack_58 + 1) * 0x28;
    iVar19 = iVar7 + iVar20;
    iVar20 = iVar8 + iVar20;
    for (iVar22 = 1; iVar22 <= (param_5 + 1) / 2; iVar22 = iVar22 + 1) {
      iStack_58 = iStack_58 + 1;
      iVar21 = iVar22 + iVar4;
      if (param_1 <= iVar22 + iVar4) {
        iVar21 = iVar22 + (iVar4 - param_1);
      }
      *(short *)(iVar19 + 0xc) = (short)iVar21;
      if (uVar12 == 0) {
        trap(7);
      }
      *(undefined1 *)(iVar19 + 0xe) = uVar14;
      *(undefined1 *)(iVar20 + 0xe) = uVar14;
      *(short *)(iVar20 + 0xc) = (short)iVar4;
      sVar3 = param_2 - (short)((iVar4 + iVar21) % (int)uVar12);
      iVar17 = iVar20;
      for (iVar11 = 0; iVar11 < param_4; iVar11 = iVar11 + 1) {
        iVar13 = 0;
        psVar9 = (short *)(iVar19 + iVar11 * 6 + 0x12);
        puVar15 = puVar10;
        puVar16 = puVar10;
        while( true ) {
          if (param_4 <= iVar13) break;
          *(short *)(iVar19 + 0x10) = sVar3 + *(short *)(iVar19 + 0x10);
          *psVar9 = sVar3;
          *(short *)(iVar20 + 0x10) = sVar3 + *(short *)(iVar20 + 0x10);
          iVar18 = iVar13 * 2;
          iVar13 = iVar13 + 1;
          *(short *)(iVar17 + iVar18 + 0x12) = sVar3;
          puVar15[9] = puVar15[9] + *psVar9;
          puVar16[6] = puVar16[6] + *psVar9;
          sVar1 = *psVar9;
          psVar9 = psVar9 + 1;
          puVar10[5] = sVar1 + puVar10[5];
          *(int *)(iVar19 + 0x24) = iVar20;
          *(int *)(iVar20 + 0x24) = iVar19;
          puVar15 = puVar15 + 4;
          puVar16 = puVar16 + 1;
        }
        iVar17 = iVar17 + 6;
      }
      FUN_004086b0(iStack_48,iVar19);
      FUN_004086b0(iVar6 + iVar21 * 0xc,iVar20);
      iVar19 = iVar19 + 0x28;
      iVar20 = iVar20 + 0x28;
    }
    puVar10 = puVar10 + 0x15;
    iStack_48 = iStack_48 + 0xc;
  }
  iVar4 = func_0x00406f50();
  if (_rrm_test_dump_switch != 0) {
    puts("-----before run_DCA():-----");
    puVar10 = __s;
    for (iVar19 = 0; iVar19 < param_1; iVar19 = iVar19 + 1) {
      printf("apid:%d total itf:%d\n",(uint)*puVar10,(int)(short)puVar10[5]);
      bVar2 = 0 < param_4;
      iVar20 = 0;
      puVar15 = puVar10;
      while (bVar2) {
        iVar22 = iVar20 + 1;
        printf("\tradio:%d, channel:%d, interfer:%d\n",iVar22,
               (int)*(char *)((int)puVar10 + iVar20 + 3),(uint)puVar15[6]);
        bVar2 = iVar22 < param_4;
        iVar20 = iVar22;
        puVar15 = puVar15 + 1;
      }
      puVar10 = puVar10 + 0x15;
    }
  }
  puts("Running DCA...");
  run_DCA(__s,param_1,6,param_3,iVar5,iVar6);
  iVar19 = func_0x00406f50();
  uVar23 = __floatsidf(iVar19 - iVar4);
  __divdf3((int)((ulonglong)uVar23 >> 0x20),(int)uVar23,0x412e8480,0);
  printf("DCA finished,total cost time:%fs\n");
  if (_rrm_test_dump_switch != 0) {
    puts("-----after run_DCA():-----");
    puVar10 = __s;
    for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
      printf("apid:%d total itf:%d\n",(uint)*puVar10,(int)(short)puVar10[5]);
      bVar2 = 0 < param_4;
      iVar19 = 0;
      puVar15 = puVar10;
      while (bVar2) {
        iVar20 = iVar19 + 1;
        printf("\tradio:%d, channel:%d, interfer:%d\n",iVar20,
               (int)*(char *)((int)puVar10 + iVar19 + 3),(uint)puVar15[6]);
        bVar2 = iVar20 < param_4;
        iVar19 = iVar20;
        puVar15 = puVar15 + 1;
      }
      puVar10 = puVar10 + 0x15;
    }
  }
  FUN_00407df0(iVar7);
  FUN_00407df0(iVar8);
  FUN_00407df0(iVar5);
  FUN_00407df0(iVar6);
  FUN_00407df0(__s);
  return 0;
}

