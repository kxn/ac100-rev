// func _apdb_parse_rrst_channel_from_apdb @ 005f9d3c size=1516

/* WARNING: Type propagation algorithm not settling */

undefined4 _apdb_parse_rrst_channel_from_apdb(char *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  char local_b0 [18];
  short asStack_9e [55];
  int local_30;
  
  local_30 = param_3;
  memset(asStack_9e + 1,0,0x66);
  local_b0[0] = '\0';
  local_b0[1] = '\0';
  local_b0[2] = '\0';
  local_b0[3] = '\0';
  local_b0[4] = '\0';
  local_b0[5] = '\0';
  local_b0[6] = '\0';
  local_b0[7] = '\0';
  local_b0[8] = '\0';
  local_b0[9] = '\0';
  local_b0[10] = '\0';
  local_b0[0xb] = '\0';
  local_b0[0xc] = '\0';
  local_b0[0xd] = '\0';
  local_b0[0xe] = '\0';
  local_b0[0xf] = '\0';
  stack0xffffff60 = 0;
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  iVar5 = 0;
  if (param_2 == 0) {
    return 0xffffffff;
  }
  bVar2 = false;
  iVar7 = 0;
  do {
    sVar1 = *(short *)(param_2 + iVar5);
    iVar11 = iVar7;
    if (sVar1 == 0) break;
    if (sVar1 == -1) {
      bVar2 = true;
    }
    else {
      iVar11 = (int)(short)((short)iVar7 + 1);
      asStack_9e[iVar7 + 1] = sVar1;
    }
    iVar5 = iVar5 + 2;
    iVar7 = iVar11;
  } while (iVar5 != 0x66);
  if (iVar11 == 0) {
    if (apdb_debug_switch == 0) {
      return 0xffffffff;
    }
    printf("[APDB_DEBUG]%s()/line %d : _apdb_parse_rrst_channel:no channel\n",
           "_apdb_parse_rrst_channel_from_apdb",0x1715);
    return 0xffffffff;
  }
  iVar5 = 0;
  if (iVar11 != 1) {
    for (; iVar7 = 0, iVar5 < iVar11; iVar5 = iVar5 + 1) {
      psVar12 = asStack_9e;
      while (psVar12 = (short *)((int)psVar12 + 2), iVar7 < (iVar11 + -1) - iVar5) {
        sVar1 = *psVar12;
        iVar7 = iVar7 + 1;
        if (psVar12[1] < sVar1) {
          *psVar12 = psVar12[1];
          psVar12[1] = sVar1;
        }
      }
    }
  }
  if (bVar2) {
    sVar6 = strlen(param_1);
    strncat(param_1,"0",200 - sVar6);
  }
  psVar12 = asStack_9e;
  bVar3 = false;
  bVar4 = false;
  iVar13 = 0;
  iVar5 = 0;
  iVar7 = 0;
  while (iVar13 < iVar11) {
    iVar10 = (int)psVar12[1];
    iVar8 = 4;
    if (iVar10 < 0xe) {
      iVar8 = 1;
    }
    if (iVar13 == 0) {
      iVar13 = 1;
      psVar12 = psVar12 + 1;
      iVar5 = iVar10;
    }
    else if (bVar3) {
      sVar1 = *psVar12;
      if (sVar1 + iVar8 == iVar10) {
        iVar13 = iVar13 + 1;
        psVar12 = psVar12 + 1;
        iVar7 = sVar1 + iVar8;
      }
      else {
        if (bVar2) {
          sVar6 = strlen(param_1);
          strncat(param_1," ",200 - sVar6);
        }
        pcVar9 = "%d-%d";
LAB_005fa140:
        snprintf(local_b0,0x14,pcVar9,iVar5,iVar7);
        sVar6 = strlen(param_1);
        strncat(param_1,local_b0,200 - sVar6);
        iVar7 = 0;
        bVar3 = false;
LAB_005fa0fc:
        bVar4 = false;
        bVar2 = true;
        iVar13 = iVar13 + 1;
        psVar12 = psVar12 + 1;
        iVar5 = iVar10;
      }
    }
    else if (bVar4) {
      sVar1 = *psVar12;
      if (sVar1 + iVar8 != iVar10) {
        if (bVar2) {
          sVar6 = strlen(param_1);
          strncat(param_1," ",200 - sVar6);
        }
        pcVar9 = "%d %d";
        goto LAB_005fa140;
      }
      bVar3 = true;
      bVar4 = false;
      iVar13 = iVar13 + 1;
      psVar12 = psVar12 + 1;
      iVar7 = sVar1 + iVar8;
    }
    else {
      sVar1 = *psVar12;
      if (sVar1 + iVar8 != iVar10) {
        if (bVar2) {
          sVar6 = strlen(param_1);
          strncat(param_1," ",200 - sVar6);
        }
        snprintf(local_b0,0x14,"%d",iVar5);
        sVar6 = strlen(param_1);
        strncat(param_1,local_b0,200 - sVar6);
        goto LAB_005fa0fc;
      }
      bVar4 = true;
      iVar13 = iVar13 + 1;
      psVar12 = psVar12 + 1;
      iVar7 = sVar1 + iVar8;
    }
  }
  if (bVar3) {
    if (bVar2) {
      sVar6 = strlen(param_1);
      strncat(param_1," ",200 - sVar6);
    }
    snprintf(local_b0,0x14,"%d-%d",iVar5,iVar7);
  }
  else {
    if (iVar5 != 0) {
      if (bVar2) {
        sVar6 = strlen(param_1);
        strncat(param_1," ",200 - sVar6);
      }
      snprintf(local_b0,0x14,"%d",iVar5);
      sVar6 = strlen(param_1);
      strncat(param_1,local_b0,200 - sVar6);
      bVar2 = true;
    }
    if (iVar7 == 0) goto LAB_005f9edc;
    if (bVar2) {
      sVar6 = strlen(param_1);
      strncat(param_1," ",200 - sVar6);
    }
    snprintf(local_b0,0x14,"%d",iVar7);
  }
  sVar6 = strlen(param_1);
  strncat(param_1,local_b0,200 - sVar6);
  bVar2 = true;
LAB_005f9edc:
  if (param_4 != 0) {
    if (bVar2) {
      sVar6 = strlen(param_1);
      strncat(param_1," ",200 - sVar6);
    }
    sVar6 = strlen(param_1);
    strncat(param_1,"equal",200 - sVar6);
    bVar2 = true;
  }
  if (local_30 == -1) {
    if (bVar2) {
      sVar6 = strlen(param_1);
      strncat(param_1," ",200 - sVar6);
    }
    sVar6 = strlen(param_1);
    pcVar9 = "default:0";
  }
  else {
    if (local_30 < 1) {
      return 0;
    }
    if (bVar2) {
      sVar6 = strlen(param_1);
      strncat(param_1," ",200 - sVar6);
    }
    snprintf(local_b0,0x14,"default:%d",local_30);
    sVar6 = strlen(param_1);
    pcVar9 = local_b0;
  }
  strncat(param_1,pcVar9,200 - sVar6);
  return 0;
}

