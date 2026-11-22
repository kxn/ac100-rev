// func rdmngr_db_rrst_matched_row_pre_match @ 00622eb4 size=432

undefined4
rdmngr_db_rrst_matched_row_pre_match
          (int param_1,int param_2,int param_3,uint param_4,int *param_5,undefined4 *param_6)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int iVar12;
  int iVar13;
  
  uVar5 = 0xffffffff;
  if (((param_1 != 0) && (param_3 != 0)) && (bVar11 = true, param_5 != (int *)0x0)) {
    for (iVar13 = 0; uVar5 = 0, iVar13 < (int)(param_4 & 0xff); iVar13 = iVar13 + 1) {
      iVar10 = param_3 + *param_5 * 0x1fc;
      if (*(char *)(iVar10 + 8) == '\x01') {
        *param_6 = 1;
        return 0;
      }
      iVar7 = param_1;
      for (iVar12 = 0; iVar12 < param_2; iVar12 = iVar12 + 1) {
        cVar1 = *(char *)(iVar7 + 3);
        cVar2 = *(char *)(iVar7 + 0x4e);
        uVar3 = *(undefined1 *)(iVar7 + 10);
        sVar4 = *(short *)(iVar7 + 0xc);
        iVar8 = iVar10;
        for (iVar9 = 0; iVar9 < (int)(uint)*(byte *)(iVar10 + 8); iVar9 = iVar9 + 1) {
          if ((*(char *)(iVar8 + 0x98) == cVar1) &&
             (((iVar6 = rdmngr_db_check_fit_row_rrst_radio_abstract_status
                                  (cVar2 == '\0',*(undefined4 *)(iVar8 + 0x2c)), iVar6 == 0 ||
               (iVar6 = rdmngr_db_check_fit_row_rrst_bandwidth(uVar3,*(undefined1 *)(iVar8 + 0x99)),
               iVar6 == 0)) ||
              (iVar6 = rdmngr_db_check_fit_row_rrst_channel((int)sVar4,iVar10 + iVar9 * 0x74 + 0x32)
              , iVar6 == 0)))) goto LAB_00622ff4;
          iVar8 = iVar8 + 0x74;
        }
        iVar7 = iVar7 + 0x54;
        if (!bVar11) goto LAB_00622ff4;
      }
      if (bVar11) {
        *param_6 = 1;
        return 0;
      }
LAB_00622ff4:
      param_5 = param_5 + 1;
      bVar11 = false;
    }
  }
  return uVar5;
}

