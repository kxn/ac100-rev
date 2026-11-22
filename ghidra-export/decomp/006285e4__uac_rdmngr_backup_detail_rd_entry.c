// func _uac_rdmngr_backup_detail_rd_entry @ 006285e4 size=3076

undefined4 _uac_rdmngr_backup_detail_rd_entry(int param_1,undefined4 *param_2,FILE *param_3)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar9;
  char *pcVar8;
  char *pcVar10;
  undefined4 uVar11;
  undefined *puVar12;
  char *__s;
  int iVar13;
  undefined1 auStack_8f0 [20];
  char acStack_8dc [112];
  char acStack_86c [200];
  undefined1 auStack_7a4 [256];
  undefined1 auStack_6a4 [276];
  undefined1 auStack_590 [218];
  char acStack_4b6 [65];
  char local_475 [77];
  char acStack_428 [1028];
  
  memset(acStack_428,0,0x400);
  memset(auStack_7a4,0,0x100);
  memset(auStack_8f0,0,0x84);
  memset(acStack_86c,0,200);
  memset(auStack_590,0,0x168);
  memset(auStack_6a4,0,0x114);
  if (rdmngr_debug_switch == 0) {
    bVar9 = *(byte *)((int)param_2 + 3);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      bVar9 = *(byte *)((int)param_2 + 3);
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_backup_detail_rd_entry begins, radioId:%d\n",
             "_uac_rdmngr_backup_detail_rd_entry",0x1e3,*param_2);
      bVar9 = *(byte *)((int)param_2 + 3);
    }
  }
  iVar13 = param_1 + 0x218;
  iVar1 = apdb_get_radio_by_id
                    (*(undefined4 *)(param_1 + 0x40),iVar13,bVar9 & 0xf,auStack_6a4,
                     (int)*(char *)(param_2 + 2));
  if (iVar1 == 0) {
    apmngr_db_group_get_by_id(*(undefined2 *)(param_1 + 0x12),auStack_8f0);
    pcVar2 = strchr(acStack_8dc,0x2c);
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(acStack_8dc,0x22), pcVar2 == (char *)0x0)) {
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = "%s,";
      pcVar10 = acStack_8dc;
    }
    else {
      FUN_0062852c(acStack_86c,acStack_8dc);
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = "\"%s\",";
      pcVar10 = acStack_86c;
    }
    __s = (char *)(param_1 + 0x4e);
    snprintf(pcVar2,0x400 - sVar3,pcVar8,pcVar10);
    pcVar2 = strchr(__s,0x2c);
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(__s,0x22), pcVar2 == (char *)0x0)) {
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = "%s,";
    }
    else {
      FUN_0062852c(acStack_86c,__s);
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = "\"%s\",";
      __s = acStack_86c;
    }
    snprintf(pcVar2,0x400 - sVar3,pcVar8,__s);
    if (*(int *)(param_1 + 0xc) == 0) {
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = &DAT_006ce9e8;
    }
    else {
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = &DAT_006ce9f0;
    }
    snprintf(pcVar2,0x400 - sVar3,pcVar8);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",*(undefined4 *)(param_1 + 0x40));
    apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),iVar13,auStack_590);
    sVar3 = strlen(acStack_428);
    pcVar2 = local_475;
    if (local_475[0] == '\0') {
      pcVar2 = acStack_4b6;
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    apdb_get_hwver_name_by_id(*(undefined4 *)(param_1 + 0x40),iVar13,auStack_7a4,0x100);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"v%s,",auStack_7a4);
    sVar3 = strlen(acStack_428);
    uVar4 = (uint)*(byte *)(param_1 + 0x4a);
    uVar5 = (uint)*(byte *)(param_1 + 0x4b);
    uVar6 = (uint)*(byte *)(param_1 + 0x4c);
    uVar7 = (uint)*(byte *)(param_1 + 0x4d);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%02X-%02X-%02X-%02X-%02X-%02X,",
             (uint)*(byte *)(param_1 + 0x48),(uint)*(byte *)(param_1 + 0x49),uVar4,uVar5,uVar6,uVar7
            );
    sVar3 = strlen(acStack_428);
    bVar9 = *(byte *)((int)param_2 + 3);
    pcVar2 = (char *)apdb_get_radio_freq_name_by_freq((int)*(char *)(param_2 + 2));
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d(%s),",bVar9 & 0xf,pcVar2,uVar4,uVar5,uVar6,uVar7)
    ;
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 9) & 0xffff;
    if (uVar4 < 0xe) {
      pcVar8 = (&PTR_s_802_11a_0070c96c)[uVar4];
    }
    else {
      pcVar8 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar8,pcVar2);
    sVar3 = strlen(acStack_428);
    if (*(byte *)((int)param_2 + 10) < 8) {
      pcVar8 = (&PTR_s_20MHz_0070c880)[*(byte *)((int)param_2 + 10)];
    }
    else {
      pcVar8 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar8,pcVar2);
    puVar12 = (undefined *)(int)*(short *)(param_2 + 3);
    if (puVar12 == (undefined *)0xffffffff) {
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = "%s,";
      puVar12 = &DAT_0070c064;
    }
    else {
      sVar3 = strlen(acStack_428);
      pcVar2 = acStack_428 + sVar3;
      pcVar8 = "%d,";
    }
    snprintf(pcVar2,0x400 - sVar3,pcVar8,puVar12);
    sVar3 = strlen(acStack_428);
    if (*(byte *)((int)param_2 + 0xe) < 3) {
      pcVar2 = (&PTR_DAT_0070c9a4)[*(byte *)((int)param_2 + 0xe)];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    if (*(byte *)(param_2 + 6) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[*(byte *)(param_2 + 6)];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)(param_2 + 4));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)((int)param_2 + 0x12));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)((int)param_2 + 0x16));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"Lv%d,",(int)*(char *)((int)param_2 + 0x19));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)((int)param_2 + 0x1a));
    sVar3 = strlen(acStack_428);
    if (*(byte *)(param_2 + 0xc) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[*(byte *)(param_2 + 0xc)];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(int)*(char *)((int)param_2 + 0x2f));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(byte *)((int)param_2 + 0x31));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",&DAT_0070c074);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)((int)param_2 + 0x1e));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)(param_2 + 8));
    sVar3 = strlen(acStack_428);
    if (*(ushort *)((int)param_2 + 0x22) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[*(ushort *)((int)param_2 + 0x22)];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(ushort *)(param_2 + 9));
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(uint)*(byte *)((int)param_2 + 0x26));
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 0x27) & 0xffff;
    if (uVar4 < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[uVar4];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    if (((int)*(char *)(param_2 + 10) & 0xffffU) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[(int)*(char *)(param_2 + 10) & 0xffffU];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 0x2a) & 0xffff;
    if (uVar4 < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[uVar4];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    if (*(byte *)((int)param_2 + 0x2b) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[*(byte *)((int)param_2 + 0x2b)];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(int)*(char *)(param_2 + 0xb));
    iVar1 = rdmngr_profile_support_rssi_kick();
    if (iVar1 != 0) {
      sVar3 = strlen(acStack_428);
      if (*(byte *)((int)param_2 + 0x2d) < 2) {
        pcVar2 = (&PTR_DAT_0070c9b0)[*(byte *)((int)param_2 + 0x2d)];
      }
      else {
        pcVar2 = "---";
      }
      snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
      sVar3 = strlen(acStack_428);
      snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(int)*(char *)((int)param_2 + 0x2e));
    }
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 0x32) & 0xffff;
    if (uVar4 < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[uVar4];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 0x33) & 0xffff;
    if (uVar4 < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[uVar4];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    if (((int)*(char *)(param_2 + 0xd) & 0xffffU) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[(int)*(char *)(param_2 + 0xd) & 0xffffU];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 0x35) & 0xffff;
    if (uVar4 < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[uVar4];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    uVar4 = (int)*(char *)((int)param_2 + 0x36) & 0xffff;
    if (uVar4 < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[uVar4];
    }
    else {
      pcVar2 = "---";
    }
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s,",pcVar2);
    sVar3 = strlen(acStack_428);
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%d,",(int)*(char *)((int)param_2 + 0x37));
    sVar3 = strlen(acStack_428);
    if (((int)*(char *)(param_2 + 0x12) & 0xffffU) < 2) {
      pcVar2 = (&PTR_DAT_0070c9b0)[(int)*(char *)(param_2 + 0x12) & 0xffffU];
    }
    else {
      pcVar2 = "---";
    }
    uVar11 = 0;
    snprintf(acStack_428 + sVar3,0x400 - sVar3,"%s\r\n",pcVar2);
    sVar3 = strlen(acStack_428);
    fwrite(acStack_428,sVar3,1,param_3);
    if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_backup_detail_rd_entry finishes\n",
             "_uac_rdmngr_backup_detail_rd_entry",0x23e);
    }
  }
  else {
    uVar11 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Get radio cfg from apdb failed of radio %d!\n",
             "_uac_rdmngr_backup_detail_rd_entry",0x1e6,*param_2);
    }
  }
  return uVar11;
}

