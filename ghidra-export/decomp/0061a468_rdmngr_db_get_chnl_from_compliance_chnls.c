// func rdmngr_db_get_chnl_from_compliance_chnls @ 0061a468 size=240

int rdmngr_db_get_chnl_from_compliance_chnls(int param_1,short *param_2,int *param_3)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short sVar7;
  
  if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_db_get_chnl_from_compliance_chnls ENTER\n",
           "rdmngr_db_get_chnl_from_compliance_chnls",0x67f);
  }
  iVar4 = 0;
  if (((param_1 != 0) && (param_2 != (short *)0x0)) && (param_3 != (int *)0x0)) {
    bVar3 = false;
    sVar7 = 0;
    while (sVar1 = *(short *)(param_1 + iVar4), sVar1 != 0) {
      iVar5 = 0;
      psVar6 = param_2;
      while( true ) {
        sVar7 = sVar1;
        if (*param_3 < iVar5) goto LAB_0061a4ec;
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
        if (sVar1 == sVar2) break;
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 2;
      if (iVar4 == 0x66) {
        return 0;
      }
      bVar3 = true;
    }
    iVar4 = 0;
    if (!bVar3) {
LAB_0061a4ec:
      iVar4 = (int)sVar7;
    }
  }
  return iVar4;
}

