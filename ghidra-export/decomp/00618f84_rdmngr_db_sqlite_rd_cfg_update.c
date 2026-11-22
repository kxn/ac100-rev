// func rdmngr_db_sqlite_rd_cfg_update @ 00618f84 size=1924

undefined4 rdmngr_db_sqlite_rd_cfg_update(undefined4 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  int local_668;
  undefined4 local_664;
  char acStack_660 [1536];
  int local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  
  local_668 = 0;
  local_664 = 0;
  memset(acStack_660,0,0x600);
  iVar11 = g_rdmngr_db_ptr;
  if (param_1 == (undefined4 *)0x0) {
    uVar10 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Wrong value, failed to update rd table in memory.\n",
             "rdmngr_db_sqlite_rd_cfg_update",0x2c7);
    }
  }
  else {
    if (g_rdmngr_db_ptr == 0) {
      iVar9 = -1;
      if ((rdmngr_err_switch != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d open db failed.\n","rdmngr_db_sqlite_rd_cfg_update",0x2cd);
      }
    }
    else {
      snprintf(acStack_660,0x600,"SELECT key from %s WHERE %s = \'%d\'","rdmngrTable","rf_id",
               *param_1);
      iVar9 = FUN_00407fb0(iVar11,acStack_660,isIndexExisted,&local_668);
      if ((iVar9 == 0) && (local_668 != 0)) {
        local_30 = (uint)*(ushort *)(param_1 + 8);
        local_60 = (int)*(char *)((int)param_1 + 0x29);
        local_5c = (uint)*(ushort *)(param_1 + 9);
        local_58 = (uint)*(byte *)((int)param_1 + 0x26);
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
        if (*(char *)((int)param_1 + 0x2a) == '\0') {
          pcVar3 = "Led off";
        }
        else {
          pcVar3 = "Led on";
        }
        if (*(char *)((int)param_1 + 0x2b) == '\0') {
          pcVar4 = "Led off";
        }
        else {
          pcVar4 = "Led on";
        }
        local_54 = (int)*(char *)(param_1 + 0xb);
        if (*(char *)((int)param_1 + 0x2d) == '\0') {
          pcVar5 = "Led off";
        }
        else {
          pcVar5 = "Led on";
        }
        local_50 = (int)*(char *)((int)param_1 + 0x2e);
        if (*(short *)((int)param_1 + 0x22) == 0) {
          pcVar6 = "Led off";
        }
        else {
          pcVar6 = "Led on";
        }
        local_4c = (uint)*(byte *)((int)param_1 + 0xe);
        if (*(char *)(param_1 + 6) == '\0') {
          pcVar7 = "Led off";
        }
        else {
          pcVar7 = "Led on";
        }
        local_3c = (int)*(char *)((int)param_1 + 0x2f);
        local_48 = (uint)*(ushort *)(param_1 + 4);
        local_44 = (uint)*(ushort *)((int)param_1 + 0x12);
        local_40 = (uint)*(ushort *)((int)param_1 + 0x16);
        if (*(char *)(param_1 + 0xc) == '\0') {
          pcVar8 = "Led off";
        }
        else {
          pcVar8 = "Led on";
        }
        local_38 = (uint)*(byte *)((int)param_1 + 0x31);
        if (*(char *)((int)param_1 + 0x32) == -1) {
          pcVar18 = "null";
        }
        else if (*(char *)((int)param_1 + 0x32) == '\0') {
          pcVar18 = "off";
        }
        else {
          pcVar18 = "on";
        }
        if (*(char *)((int)param_1 + 0x33) == -1) {
          pcVar17 = "null";
        }
        else if (*(char *)((int)param_1 + 0x33) == '\0') {
          pcVar17 = "off";
        }
        else {
          pcVar17 = "on";
        }
        if (*(char *)(param_1 + 0xd) == -1) {
          pcVar16 = "null";
        }
        else if (*(char *)(param_1 + 0xd) == '\0') {
          pcVar16 = "off";
        }
        else {
          pcVar16 = "on";
        }
        if (*(char *)((int)param_1 + 0x35) == -1) {
          pcVar15 = "null";
        }
        else if (*(char *)((int)param_1 + 0x35) == '\0') {
          pcVar15 = "off";
        }
        else {
          pcVar15 = "on";
        }
        if (*(char *)((int)param_1 + 0x36) == -1) {
          pcVar14 = "null";
        }
        else if (*(char *)((int)param_1 + 0x36) == '\0') {
          pcVar14 = "off";
        }
        else {
          pcVar14 = "on";
        }
        local_34 = (int)*(char *)((int)param_1 + 0x37);
        if (*(char *)(param_1 + 0xe) == -1) {
          pcVar13 = "null";
        }
        else if (*(char *)(param_1 + 0xe) == '\0') {
          pcVar13 = "off";
        }
        else {
          pcVar13 = "on";
        }
        if (*(char *)((int)param_1 + 0x39) == -1) {
          pcVar12 = "null";
        }
        else if (*(char *)((int)param_1 + 0x39) == '\0') {
          pcVar12 = "off";
        }
        else {
          pcVar12 = "on";
        }
        snprintf(acStack_660,0x600,
                 "UPDATE %s SET %s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%d\',%s = \'%s\',%s = \'%d\', %s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%s\',%s = \'%d\',%s = \'%s\',%s = \'%s\'WHERE %s = \'%d\';"
                 ,"rdmngrTable","rf_name",(int)*(char *)(param_1 + 2),"freq_band",
                 (int)*(char *)(param_1 + 2),"mode",(int)*(char *)((int)param_1 + 9),"bandwidth",
                 (uint)*(byte *)((int)param_1 + 10),"channel",(int)*(short *)(param_1 + 3),
                 "power_level",(int)*(char *)((int)param_1 + 0x19),"max_usr",
                 (uint)*(ushort *)((int)param_1 + 0x1a),"antenna",(uint)*(byte *)(param_1 + 7),
                 "frag_thr",(uint)*(ushort *)((int)param_1 + 0x1e),"bcn_intvl",local_30,
                 "manage_frame_rate",local_60,"rts_thr",local_5c,"dtim_prd",local_58,&DAT_006fe1c0,
                 pcVar1 + 4,"brd_probe",pcVar2 + 4,"short_gi",pcVar3 + 4,"rssi_restrict",pcVar4 + 4,
                 "rssi_restrict_val",local_54,"rssi_kick",pcVar5 + 4,"rssi_kick_val",local_50,
                 "airtime",pcVar6 + 4,&DAT_00707dbc,local_4c,"rf_online_switch",pcVar7 + 4,
                 "rf_check_circle",local_48,"rf_chnl_occup_threshold",local_44,"rf_chnl_tolerance",
                 local_40,"reject_limit",local_3c,"reject_enable",pcVar8 + 4,"reject_diff",local_38,
                 "downlink_mumimo",pcVar18,"uplink_mumimo",pcVar17,"downlink_ofdma",pcVar16,
                 "uplink_ofdma",pcVar15,&DAT_00707e84,pcVar14,"gi_mode",local_34,"enable_6g",pcVar13
                 ,"enable_6g_psc",pcVar12,"key",local_664);
        if ((rdmngr_debug_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d sql:%s, key:%d\n","rdmngr_db_sqlite_rd_cfg_update",0x308,
                 acStack_660,local_664);
        }
        iVar9 = FUN_00407d60(iVar11,acStack_660);
        if ((iVar9 != 0) && (iVar11 = FUN_00408410(), iVar11 != 0)) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "rdmngr_db_sqlite_rd_cfg_update",0x309,iVar9,acStack_660,
                 "Failed to update rd table in memory.");
        }
      }
    }
    FUN_00407df0(param_1);
    uVar10 = 0xffffffff;
    if (iVar9 == 0) {
      uVar10 = 0;
    }
  }
  return uVar10;
}

