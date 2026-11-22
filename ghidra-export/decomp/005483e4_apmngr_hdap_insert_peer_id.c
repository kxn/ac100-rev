// func apmngr_hdap_insert_peer_id @ 005483e4 size=236

int apmngr_hdap_insert_peer_id(short *param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  undefined1 auStack_2f8 [12];
  int local_2ec;
  short local_60;
  
  memset(auStack_2f8,0,0x2d8);
  iVar3 = param_2;
  if ((param_1 != (short *)0x0) && (0 < param_2)) {
    iVar5 = 0;
    psVar4 = param_1;
    do {
      iVar1 = apmngr_db_entry_get_by_id(*psVar4,auStack_2f8);
      if ((iVar1 == 0) && (local_2ec == 2)) {
        iVar1 = 0;
        psVar2 = param_1;
        do {
          iVar1 = iVar1 + 1;
          if (*psVar2 == local_60) goto LAB_00548448;
          psVar2 = psVar2 + 1;
        } while (iVar1 != param_2);
        param_1[iVar3] = local_60;
        iVar3 = iVar3 + 1;
      }
LAB_00548448:
      iVar5 = iVar5 + 1;
      psVar4 = psVar4 + 1;
    } while (iVar5 != param_2);
  }
  return iVar3;
}

