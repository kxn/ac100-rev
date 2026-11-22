// func rdmngr_db_print_all @ 00622014 size=1612

void rdmngr_db_print_all(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  if (g_rdmngr_data != 0) {
    iVar10 = 0;
    iVar9 = 0;
    uVar8 = 0;
    while( true ) {
      iVar6 = DAT_007cc65c;
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar3 = apmngr_db_get_sensor_max();
      if ((uint)((iVar1 + iVar2 + iVar3) * iVar6) <= uVar8) break;
      piVar4 = (int *)(DAT_007cc650 + uVar8 * 8);
      piVar7 = (int *)piVar4[1];
      if ((piVar7 == (int *)0x0) || (*piVar7 == -1)) {
        iVar10 = iVar10 + 1;
        uVar8 = uVar8 + 1;
      }
      else {
        iVar6 = *piVar4;
        puts("#####################################################################");
        printf("rdId\t\t\t= %d\n",*piVar7);
        printf("prealloc        = %d\n",(uint)(iVar6 != 0));
        if (*(char *)(piVar7 + 2) == '\0') {
          pcVar5 = "2.4GHz";
        }
        else {
          pcVar5 = "5GHz";
        }
        printf("freqBand\t\t= %s\n",pcVar5);
        printf("rdMode\t\t    = %d\n",(int)*(char *)((int)piVar7 + 9));
        printf("bwMode   \t\t= %d\n",(uint)*(byte *)((int)piVar7 + 10));
        printf("chnl    \t\t= %d\n",(int)*(short *)(piVar7 + 3));
        printf("pwrLevel\t\t= %d\n",(int)*(char *)((int)piVar7 + 0x19));
        printf("maxUsr  \t\t= %d\n",(uint)*(ushort *)((int)piVar7 + 0x1a));
        printf("antenna \t\t= %d\n",(uint)*(byte *)(piVar7 + 7));
        printf("fragThr\t\t    = %d\n",(uint)*(ushort *)((int)piVar7 + 0x1e));
        printf("bcnIntvl\t\t= %d\n",(uint)*(ushort *)(piVar7 + 8));
        printf("manageframeRate\t= %d\n",(int)*(char *)((int)piVar7 + 0x29));
        printf("rtsThr\t\t    = %d\n",(uint)*(ushort *)(piVar7 + 9));
        printf("dtimPrd \t\t= %d\n",(uint)*(byte *)((int)piVar7 + 0x26));
        printf("wmm     \t\t= %d\n",(int)*(char *)((int)piVar7 + 0x27));
        printf("brdProbe\t\t= %d\n",(int)*(char *)(piVar7 + 10));
        printf("shortGi\t    \t= %d\n",(int)*(char *)((int)piVar7 + 0x2a));
        printf("realChnl     \t= %d\n",(int)*(short *)(piVar7 + 0xf));
        printf("realPwr\t\t    = %d\n",(int)*(char *)(piVar7 + 0x10));
        printf("realRdMode\t    = %d\n",(int)*(char *)((int)piVar7 + 0x3a));
        if (*(char *)((int)piVar7 + 0x2b) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("bRssiRestrct\t= %s\n",pcVar5);
        printf("rssiRestrictVal\t= %d\n",(int)*(char *)(piVar7 + 0xb));
        if (*(char *)((int)piVar7 + 0x2d) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("bRssiKick \t\t= %s\n",pcVar5);
        printf("rssiKickVal     = %d\n",(int)*(char *)((int)piVar7 + 0x2e));
        if (*(char *)((int)piVar7 + 0x41) == '\0') {
          pcVar5 = "unlocked";
        }
        else {
          pcVar5 = "locked";
        }
        printf("chLock   \t\t= %s\n",pcVar5);
        if (*(char *)((int)piVar7 + 0x42) == '\0') {
          pcVar5 = "unlocked";
        }
        else {
          pcVar5 = "locked";
        }
        printf("pwrLock\t\t    = %s\n",pcVar5);
        printf("scanMode \t\t= %d\n",(uint)*(byte *)((int)piVar7 + 0x43));
        printf("scanType     \t= %d\n",(uint)*(byte *)(piVar7 + 0x11));
        printf("scanIntvl\t\t= %d\n",(uint)*(ushort *)((int)piVar7 + 0x46));
        if (*(char *)(piVar7 + 0x12) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("rdState\t    \t= %s\n",pcVar5);
        if (*(char *)((int)piVar7 + 0xe) == '\0') {
          pcVar5 = "Auto";
        }
        else if (*(char *)((int)piVar7 + 0xe) == '\x01') {
          pcVar5 = "Manual";
        }
        else {
          pcVar5 = "Closed";
        }
        printf("chSwitchType\t= %s\n",pcVar5);
        printf("chScanInterval\t= %d\n",(uint)*(ushort *)(piVar7 + 4));
        printf("chOccup         = %d\n",(uint)*(ushort *)((int)piVar7 + 0x12));
        printf("chErrFrameRatio\t= %d\n",(uint)*(ushort *)(piVar7 + 5));
        printf("chTolerance   \t= %d\n",(uint)*(ushort *)((int)piVar7 + 0x16));
        printf("chOnlineSwitch  = %d\n",(uint)*(byte *)(piVar7 + 6));
        printf("chnlReselect    = %d\n",(uint)*(byte *)((int)piVar7 + 0x49));
        printf("airtime         = %d\n",(uint)*(ushort *)((int)piVar7 + 0x22));
        printf("rejectLimit\t\t= %d\n",(int)*(char *)((int)piVar7 + 0x2f));
        if (*(char *)(piVar7 + 0xc) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("rejectEnable\t= %s\n",pcVar5);
        printf("rejectDiff\t\t= %d\n",(uint)*(byte *)((int)piVar7 + 0x31));
        if (*(char *)((int)piVar7 + 0x32) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)((int)piVar7 + 0x32) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("donwLinkMuMimo\t= %s\n",pcVar5);
        if (*(char *)((int)piVar7 + 0x33) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)((int)piVar7 + 0x33) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("upLinkMuMimo\t= %s\n",pcVar5);
        if (*(char *)(piVar7 + 0xd) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)(piVar7 + 0xd) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("donwLinkOfdma\t= %s\n",pcVar5);
        if (*(char *)((int)piVar7 + 0x35) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)((int)piVar7 + 0x35) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("upLinkOfdma\t= %s\n",pcVar5);
        if (*(char *)((int)piVar7 + 0x36) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)((int)piVar7 + 0x36) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("twt\t= %s\n",pcVar5);
        printf("giMode\t= %d\n",(int)*(char *)((int)piVar7 + 0x37));
        if (*(char *)(piVar7 + 0xe) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)(piVar7 + 0xe) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        printf("6Genable\t= %s\n",pcVar5);
        if (*(char *)((int)piVar7 + 0x39) == -1) {
          pcVar5 = "not support";
        }
        else if (*(char *)((int)piVar7 + 0x39) == '\0') {
          pcVar5 = "disable";
        }
        else {
          pcVar5 = "enable";
        }
        iVar9 = iVar9 + 1;
        uVar8 = uVar8 + 1;
        printf("6G_PSC_enable\t= %s\n",pcVar5);
      }
    }
    printf("total rd entry number count: is %d, invalid is %d\n",iVar9,iVar10);
  }
  FUN_00407f30(DAT_007cc64c);
  return;
}

