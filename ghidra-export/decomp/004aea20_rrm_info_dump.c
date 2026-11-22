// func rrm_info_dump @ 004aea20 size=1296

void rrm_info_dump(double param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined8 uVar18;
  undefined1 auStack_168 [320];
  
  memcpy(auStack_168,&DAT_006a11d0,0x140);
  iVar4 = rrm_db_state_get();
  puts("******rrm info*********");
  printf("state:\t%s\n",auStack_168 + iVar4 * 0x28);
  if (iVar4 - 1U < 2) {
    iVar4 = 0;
    piVar13 = &ap_para;
    do {
      piVar5 = (int *)*piVar13;
      if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
        if (iVar4 == 0) {
          iVar7 = 1;
          puVar10 = &DAT_00693fd4;
        }
        else {
          puVar10 = &DAT_00693fd0;
          iVar7 = iVar4;
        }
        printf("ap para(%s%d),collect count:%d:\n",puVar10,iVar7,piVar5[1]);
        iVar7 = 0;
        while (piVar5 = (int *)*piVar13, iVar7 < *piVar5) {
          iVar11 = iVar7 * 0x2a;
          iVar14 = iVar7 * 0xc;
          iVar7 = iVar7 + 1;
          puVar6 = (ushort *)(piVar5[6] + iVar11);
          uVar3 = *puVar6;
          bVar1 = *(byte *)(puVar6 + 1);
          uVar2 = puVar6[5];
          uVar8 = FUN_00407fe0(piVar5[8] + iVar14);
          printf("\t%d: apid(%d) radio count(%d) total itf(%d) neighbor count(%d)\n",iVar7,
                 (uint)uVar3,(uint)bVar1,(int)(short)uVar2,uVar8);
          for (iVar11 = FUN_004081b0(*(int *)(*piVar13 + 0x20) + iVar14); iVar11 != 0;
              iVar11 = FUN_00408680(iVar11)) {
            iVar16 = 1;
            puts("\t\tneighbor list:");
            printf("\t\t%p --> ap id:%d,radio num:%d,total itf:%d,op node:%p,itf:",iVar11,
                   (uint)*(ushort *)
                          (*(int *)(*piVar13 + 0x18) + (uint)*(ushort *)(iVar11 + 0xc) * 0x2a),
                   (uint)*(byte *)(iVar11 + 0xe),(uint)*(ushort *)(iVar11 + 0x10),
                   *(undefined4 *)(iVar11 + 0x24));
            iVar15 = iVar11;
            do {
              iVar17 = 1;
              do {
                uVar12 = (uint)*(ushort *)(iVar15 + iVar17 * 6 + 0xc);
                if (uVar12 != 0) {
                  uVar18 = __floatsidf(uVar12 * 100);
                  sqrt(param_1);
                  iVar9 = __fixdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
                  printf("(%d,%d,%d,%d)",iVar17,iVar16,uVar12,iVar9 + -100);
                }
                iVar17 = iVar17 + 1;
              } while (iVar17 != 4);
              iVar16 = iVar16 + 1;
              iVar15 = iVar15 + 2;
            } while (iVar16 != 4);
            putchar(10);
          }
          for (iVar11 = FUN_004081b0(*(int *)(*piVar13 + 0x24) + iVar14); iVar11 != 0;
              iVar11 = FUN_00408680(iVar11)) {
            iVar15 = 1;
            puts("\t\topposite neighbor list:");
            printf("\t\t%p --> ap id:%d,radio num:%d,total itf:%d,op node:%p,itf:",iVar11,
                   (uint)*(ushort *)
                          (*(int *)(*piVar13 + 0x18) + (uint)*(ushort *)(iVar11 + 0xc) * 0x2a),
                   (uint)*(byte *)(iVar11 + 0xe),(uint)*(ushort *)(iVar11 + 0x10),
                   *(undefined4 *)(iVar11 + 0x24));
            iVar14 = iVar11;
            do {
              iVar17 = 1;
              iVar16 = 6;
              do {
                uVar12 = (uint)*(ushort *)(iVar14 + iVar16 + 0xc);
                if (uVar12 != 0) {
                  uVar18 = __floatsidf(uVar12 * 100);
                  sqrt(param_1);
                  iVar16 = __fixdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
                  printf("(%d,%d,%d,%d)",iVar17,iVar15,uVar12,iVar16 + -100);
                }
                iVar17 = iVar17 + 1;
                iVar16 = iVar17 * 6;
              } while (iVar17 != 4);
              iVar15 = iVar15 + 1;
              iVar14 = iVar14 + 2;
            } while (iVar15 != 4);
            putchar(10);
          }
        }
      }
      iVar4 = iVar4 + 1;
      piVar13 = piVar13 + 1;
    } while (iVar4 != 3);
  }
  else if (iVar4 - 4U < 2) {
    iVar4 = 0;
    piVar13 = &ap_pwr_para;
    do {
      piVar5 = (int *)*piVar13;
      if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
        if (iVar4 == 0) {
          iVar7 = 1;
          puVar10 = &DAT_00693fd4;
        }
        else {
          puVar10 = &DAT_00693fd0;
          iVar7 = iVar4;
        }
        iVar11 = 0;
        printf("ap para(%s%d),collect count:%d:\n",puVar10,iVar7,piVar5[1]);
        while (iVar11 < *(int *)*piVar13) {
          iVar15 = iVar11 * 0x12;
          iVar17 = iVar11 * 0xf;
          iVar16 = iVar11 * 0xc;
          iVar11 = iVar11 + 1;
          puVar6 = (ushort *)(((int *)*piVar13)[6] + iVar15);
          printf("\t%d: apid(%d) radio count(%d)\n",iVar11,(uint)*puVar6,(uint)*(byte *)(puVar6 + 1)
                );
          iVar7 = *piVar13;
          for (iVar14 = 0; iVar14 < (int)(uint)*(byte *)(*(int *)(iVar7 + 0x18) + iVar15 + 2);
              iVar14 = iVar14 + 1) {
            printf("\t\tradio id:%d  ",(uint)*(byte *)(*(int *)(iVar7 + 0x1c) + iVar17 + iVar14));
            printf("interfere:");
            for (iVar7 = FUN_004081b0(*(int *)(*piVar13 + (iVar14 + 8) * 4) + iVar16); iVar7 != 0;
                iVar7 = FUN_00408680(iVar7)) {
              printf("(%d,%d,%d)",(uint)*(ushort *)(iVar7 + 0xc),(uint)*(byte *)(iVar7 + 0xe),
                     (int)*(short *)(iVar7 + 0x10));
            }
            putchar(10);
            iVar7 = *piVar13;
          }
        }
      }
      iVar4 = iVar4 + 1;
      piVar13 = piVar13 + 1;
    } while (iVar4 != 3);
  }
  puts("***********************");
  return;
}

