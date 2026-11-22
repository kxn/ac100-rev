// func _uac_wsta_backup_entry @ 00632fa8 size=1480

int _uac_wsta_backup_entry(int param_1,FILE *param_2)

{
  byte bVar1;
  char cVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  tm *ptVar7;
  char *pcVar8;
  char *pcVar9;
  tm tStack_8a0;
  char acStack_874 [64];
  char acStack_834 [256];
  char acStack_734 [256];
  undefined1 auStack_634 [304];
  char acStack_504 [216];
  char acStack_42c [1032];
  
  memset(acStack_42c,0,0x400);
  memset(&tStack_8a0,0,0x2c);
  memset(acStack_734,0,0x100);
  memset(acStack_834,0,0x100);
  memset(acStack_42c,0,0x400);
  memset(acStack_734,0,0x100);
  snprintf(acStack_734,0x100,"%02X%02X%02X%02X%02X%02X",(uint)*(byte *)(param_1 + 0x68),
           (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
           (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
           (uint)*(byte *)(param_1 + 0x6d));
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"\"%s\",",acStack_734);
  memset(acStack_734,0,0x100);
  snprintf(acStack_734,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x68),
           (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
           (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
           (uint)*(byte *)(param_1 + 0x6d));
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%s,",acStack_734);
  memset(acStack_734,0,0x100);
  memset(acStack_834,0,0x100);
  FUN_0063240c(*(undefined4 *)(param_1 + 0x20),acStack_834);
  pcVar4 = strchr(acStack_834,0x2c);
  if ((pcVar4 == (char *)0x0) && (pcVar4 = strchr(acStack_834,0x22), pcVar4 == (char *)0x0)) {
    sVar3 = strlen(acStack_42c);
    pcVar4 = acStack_42c + sVar3;
    pcVar8 = "%s,";
    pcVar9 = acStack_834;
  }
  else {
    FUN_00632354(acStack_734,acStack_834);
    sVar3 = strlen(acStack_42c);
    pcVar4 = acStack_42c + sVar3;
    pcVar8 = "\"%s\",";
    pcVar9 = acStack_734;
  }
  snprintf(pcVar4,0x400 - sVar3,pcVar8,pcVar9);
  sVar3 = strlen(acStack_42c);
  bVar1 = *(byte *)(param_1 + 0x24);
  uVar5 = _uac_wsta_get_rd_freq_unit_name(*(undefined4 *)(param_1 + 0x20),(uint)bVar1);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%d(%s),",bVar1 & 0xf,uVar5);
  iVar6 = uac_wsta_get_wserv_entry
                    (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                     *(undefined1 *)(param_1 + 0x25),auStack_634);
  if (iVar6 == 0) {
    memset(acStack_734,0,0x100);
    pcVar4 = strchr(acStack_504,0x2c);
    if ((pcVar4 == (char *)0x0) && (pcVar4 = strchr(acStack_504,0x22), pcVar4 == (char *)0x0)) {
      sVar3 = strlen(acStack_42c);
      pcVar4 = acStack_42c + sVar3;
      pcVar8 = "%s,";
      pcVar9 = acStack_504;
    }
    else {
      FUN_00632354(acStack_734,acStack_504);
      sVar3 = strlen(acStack_42c);
      pcVar4 = acStack_42c + sVar3;
      pcVar8 = "\"%s\",";
      pcVar9 = acStack_734;
    }
    snprintf(pcVar4,0x400 - sVar3,pcVar8,pcVar9);
    cVar2 = *(char *)(param_1 + 0x3c);
  }
  else {
    sVar3 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar3,0x400 - sVar3,"---,");
    cVar2 = *(char *)(param_1 + 0x3c);
  }
  if (cVar2 == '\x01') {
    pcVar8 = acStack_874;
    memset(pcVar8,0,0x40);
    FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                 *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                 *(undefined4 *)(param_1 + 0x4c),pcVar8,0x40,"0.0.0.0");
    sVar3 = strlen(acStack_42c);
    pcVar4 = acStack_42c + sVar3;
  }
  else {
    sVar3 = strlen(acStack_42c);
    pcVar4 = acStack_42c + sVar3;
    pcVar8 = "0.0.0.0";
  }
  snprintf(pcVar4,0x400 - sVar3,"%s/",pcVar8);
  pcVar4 = acStack_874;
  if (*(char *)(param_1 + 0x50) == '\x02') {
    memset(pcVar4,0,0x40);
    FUN_00408190(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                 *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                 *(undefined4 *)(param_1 + 0x60),pcVar4,0x40,"---");
    sVar3 = strlen(acStack_42c);
    pcVar8 = acStack_42c + sVar3;
  }
  else {
    sVar3 = strlen(acStack_42c);
    pcVar8 = acStack_42c + sVar3;
    pcVar4 = "---";
  }
  snprintf(pcVar8,0x400 - sVar3,"%s,",pcVar4);
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)(param_1 + 0x2e));
  memset(acStack_734,0,0x100);
  ptVar7 = localtime_r((time_t *)(param_1 + 0x70),&tStack_8a0);
  strftime(acStack_734,0x100,"%Y/%m/%d",ptVar7);
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%s ",acStack_734);
  memset(acStack_734,0,0x100);
  ptVar7 = localtime_r((time_t *)(param_1 + 0x70),&tStack_8a0);
  strftime(acStack_734,0x100,"%H:%M:%S",ptVar7);
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%s,",acStack_734);
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%dMbps,",(uint)*(ushort *)(param_1 + 0x7c));
  sVar3 = strlen(acStack_42c);
  snprintf(acStack_42c + sVar3,0x400 - sVar3,"%ddBm\r\n",(int)*(char *)(param_1 + 0x35));
  sVar3 = strlen(acStack_42c);
  fwrite(acStack_42c,sVar3,1,param_2);
  return iVar6;
}

