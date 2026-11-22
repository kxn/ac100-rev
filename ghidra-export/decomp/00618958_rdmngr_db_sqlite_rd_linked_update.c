// func rdmngr_db_sqlite_rd_linked_update @ 00618958 size=1580

undefined4 rdmngr_db_sqlite_rd_linked_update(undefined4 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  int local_640;
  undefined4 local_63c;
  char acStack_638 [1536];
  uint local_38;
  int local_34;
  int local_30;
  
  local_640 = 0;
  local_63c = 0;
  memset(acStack_638,0,0x600);
  iVar9 = g_rdmngr_db_ptr;
  if (param_1 == (undefined4 *)0x0) {
    uVar8 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Wrong value, failed to update rd table in memory.\n",
             "rdmngr_db_sqlite_rd_linked_update",0x269);
    }
  }
  else {
    if (g_rdmngr_db_ptr == 0) {
      iVar7 = -1;
      if ((rdmngr_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d open db failed.\n","rdmngr_db_sqlite_rd_linked_update",0x26f);
      }
    }
    else {
      snprintf(acStack_638,0x600,"SELECT key from %s WHERE %s = \'%d\'","rdmngrTable","rf_id",
               *param_1);
      iVar7 = FUN_00407fb0(iVar9,acStack_638,isIndexExisted,&local_640);
      if ((iVar7 == 0) && (local_640 != 0)) {
        if (*(char *)((int)param_1 + 0x27) == '\0') {
          pcVar1 = "Led off";
        }
        else {
          pcVar1 = "Led on";
        }
        if (*(char *)(param_1 + 10) == '\0') {
          pcVar2 = "Led off";
        }
        else {
          pcVar2 = "Led on";
        }
        if (*(char *)((int)param_1 + 0x2b) == '\0') {
          pcVar3 = "Led off";
        }
        else {
          pcVar3 = "Led on";
        }
        if (*(char *)((int)param_1 + 0x2d) == '\0') {
          pcVar4 = "Led off";
        }
        else {
          pcVar4 = "Led on";
        }
        if (*(char *)(param_1 + 6) == '\0') {
          pcVar5 = "Led off";
        }
        else {
          pcVar5 = "Led on";
        }
        local_30 = (int)*(char *)((int)param_1 + 0x2f);
        if (*(char *)(param_1 + 0xc) == '\0') {
          pcVar6 = "Led off";
        }
        else {
          pcVar6 = "Led on";
        }
        local_38 = (uint)*(byte *)((int)param_1 + 0x31);
        if (*(char *)((int)param_1 + 0x32) == -1) {
          pcVar16 = "null";
        }
        else if (*(char *)((int)param_1 + 0x32) == '\0') {
          pcVar16 = "off";
        }
        else {
          pcVar16 = "on";
        }
        if (*(char *)((int)param_1 + 0x33) == -1) {
          pcVar15 = "null";
        }
        else if (*(char *)((int)param_1 + 0x33) == '\0') {
          pcVar15 = "off";
        }
        else {
          pcVar15 = "on";
        }
        if (*(char *)(param_1 + 0xd) == -1) {
          pcVar14 = "null";
        }
        else if (*(char *)(param_1 + 0xd) == '\0') {
          pcVar14 = "off";
        }
        else {
          pcVar14 = "on";
        }
        if (*(char *)((int)param_1 + 0x35) == -1) {
          pcVar13 = "null";
        }
        else if (*(char *)((int)param_1 + 0x35) == '\0') {
          pcVar13 = "off";
        }
        else {
          pcVar13 = "on";
        }
        if (*(char *)((int)param_1 + 0x36) == -1) {
          pcVar12 = "null";
        }
        else if (*(char *)((int)param_1 + 0x36) == '\0') {
          pcVar12 = "off";
        }
        else {
          pcVar12 = "on";
        }
        local_34 = (int)*(char *)((int)param_1 + 0x37);
        if (*(char *)(param_1 + 0xe) == -1) {
          pcVar11 = "null";
        }
        else if (*(char *)(param_1 + 0xe) == '\0') {
          pcVar11 = "off";
        }
        else {
          pcVar11 = "on";
        }
        if (*(char *)((int)param_1 + 0x39) == -1) {
          pcVar10 = "null";
        }
        else if (*(char *)((int)param_1 + 0x39) == '\0') {
          pcVar10 = "off";
        }
        else {
          pcVar10 = "on";
        }
        snprintf(acStack_638,0x600,
                 "UPDATE %s SET %s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%s\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%d\',%s = \'%d\',%s = \'%s\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%s\',%s = \'%d\' ,%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%s\'WHERE %s = \'%d\';"
                 ,"rdmngrTable","channel",(int)*(short *)(param_1 + 3),"mode",
                 (int)*(char *)((int)param_1 + 9),"bandwidth",(uint)*(byte *)((int)param_1 + 10),
                 &DAT_006fe1c0,pcVar1 + 4,"brd_probe",pcVar2 + 4,"max_usr",
                 (uint)*(ushort *)((int)param_1 + 0x1a),"rssi_restrict",pcVar3 + 4,
                 "rssi_restrict_val",(int)*(char *)(param_1 + 0xb),"rssi_kick",pcVar4 + 4,
                 "rssi_kick_val",(int)*(char *)((int)param_1 + 0x2e),&DAT_00707dbc,
                 (uint)*(byte *)((int)param_1 + 0xe),"rf_online_switch",pcVar5 + 4,"rf_check_circle"
                 ,(uint)*(ushort *)(param_1 + 4),"rf_chnl_occup_threshold",
                 (uint)*(ushort *)((int)param_1 + 0x12),"rf_chnl_tolerance",
                 (uint)*(ushort *)((int)param_1 + 0x16),"reject_limit",local_30,"reject_enable",
                 pcVar6 + 4,"reject_diff",local_38,"downlink_mumimo",pcVar16,"uplink_mumimo",pcVar15
                 ,"downlink_ofdma",pcVar14,"uplink_ofdma",pcVar13,&DAT_00707e84,pcVar12,"gi_mode",
                 local_34,"enable_6g",pcVar11,"enable_6g_psc",pcVar10,"key",local_63c);
        if ((rdmngr_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d sql:%s, key:%d\n","rdmngr_db_sqlite_rd_linked_update",0x2a2,
                 acStack_638,local_63c);
        }
        iVar7 = FUN_00407d60(iVar9,acStack_638);
        if ((iVar7 != 0) && (iVar9 = FUN_00408410(), iVar9 != 0)) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "rdmngr_db_sqlite_rd_linked_update",0x2a3,iVar7,acStack_638,
                 "Failed to update rd table in memory.");
        }
      }
    }
    FUN_00407df0(param_1);
    uVar8 = 0xffffffff;
    if (iVar7 == 0) {
      uVar8 = 0;
    }
  }
  return uVar8;
}

