// func rrm_ap_para_dump @ 004aa8a0 size=696

void rrm_ap_para_dump(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  undefined4 uVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (rrm_info_dump_switch != 0) {
    puts("\nthis is rrm_ap_para_dump():");
    piVar4 = (int *)(&ap_para)[param_1];
    if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
      if (param_1 == 0) {
        iVar11 = 1;
        puVar9 = &DAT_00693fd4;
      }
      else {
        puVar9 = &DAT_00693fd0;
        iVar11 = param_1;
      }
      printf("ap para(%s%d),collect count:%d:\n",puVar9,iVar11,piVar4[1]);
      iVar11 = 0;
      while( true ) {
        piVar4 = (int *)(&ap_para)[param_1];
        if (*piVar4 <= iVar11) break;
        puVar6 = (ushort *)(piVar4[6] + iVar11 * 0x2a);
        uVar3 = *puVar6;
        bVar1 = *(byte *)(puVar6 + 1);
        uVar2 = puVar6[5];
        uVar5 = FUN_00407fe0(piVar4[8] + iVar11 * 0xc);
        printf("\t%d: apid(%d) radio count(%d) total itf(%d) neighbor count(%d)\n",iVar11,
               (uint)uVar3,(uint)bVar1,(int)(short)uVar2,uVar5);
        iVar11 = iVar11 + 1;
      }
    }
    if (param_2 != 0) {
      if (param_1 == 0) {
        iVar11 = 1;
        puVar9 = &DAT_00693fd4;
      }
      else {
        puVar9 = &DAT_00693fd0;
        iVar11 = param_1;
      }
      piVar4 = &ap_para + param_1;
      printf("*****radio(%s%d)\'s rrm(channel) result:******\n",puVar9,iVar11);
      for (iVar11 = 0; iVar11 < *(int *)*piVar4; iVar11 = iVar11 + 1) {
        iVar12 = iVar11 * 0x2a;
        puVar6 = (ushort *)(((int *)*piVar4)[6] + iVar12);
        printf("apid:%d total itf:%d\n",(uint)*puVar6,(int)(short)puVar6[5]);
        iVar7 = *piVar4;
        for (iVar10 = 0; iVar8 = *(int *)(iVar7 + 0x18) + iVar12,
            iVar10 < (int)(uint)*(byte *)(iVar8 + 2); iVar10 = iVar10 + 1) {
          printf("\tradio:%d, channel:%d, interfer:%d\n",
                 (uint)*(byte *)(*(int *)(iVar7 + 0x1c) + iVar11 * 0xf + iVar10),
                 (int)*(char *)(iVar8 + iVar10 + 3),(uint)*(ushort *)(iVar8 + (iVar10 + 4) * 2 + 4))
          ;
          iVar8 = *piVar4;
          iVar7 = 0;
          while( true ) {
            printf("(%d)%d ",iVar7,
                   (uint)*(ushort *)
                          (*(int *)(iVar8 + 0x18) + iVar12 + (iVar10 * 4 + iVar7 + 8) * 2 + 2));
            if (iVar7 + 1 == 4) break;
            iVar8 = *piVar4;
            iVar7 = iVar7 + 1;
          }
          putchar(10);
          iVar7 = *piVar4;
        }
      }
      puts("*************************************");
      return;
    }
  }
  return;
}

