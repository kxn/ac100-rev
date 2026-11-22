// func rdmngr_db_sqlite_rd_insert @ 0061835c size=1532

undefined4 rdmngr_db_sqlite_rd_insert(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  int iVar18;
  char *pcVar19;
  char acStack_688 [1536];
  uint local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  
  memset(acStack_688,0,0x600);
  iVar11 = g_rdmngr_db_ptr;
  if (param_1 == 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar11 = is_target_debug_ap();
    if (iVar11 == 0) {
      return 0xffffffff;
    }
    printf("[RDMNGR_ERROR]%s()/%d Wrong value, failed to insert rd entry into rd table.\n",
           "rdmngr_db_sqlite_rd_insert",0x209);
    return 0xffffffff;
  }
  if (g_rdmngr_db_ptr == 0) {
    iVar18 = -1;
    if ((rdmngr_err_switch == 0) || (iVar11 = is_target_debug_ap(), iVar11 == 0)) goto LAB_00618758;
    pcVar14 = "[RDMNGR_ERROR]%s()/%d open db failed.\n";
    uVar9 = 0x20f;
  }
  else {
    local_84 = (uint)*(ushort *)(param_1 + 0x1e);
    local_88 = (uint)*(byte *)(param_1 + 0x4d);
    local_30 = (uint)*(byte *)(param_1 + 0x1c);
    local_80 = (uint)*(ushort *)(param_1 + 0x20);
    local_7c = (int)*(char *)(param_1 + 0x29);
    local_78 = (uint)*(ushort *)(param_1 + 0x24);
    local_74 = (uint)*(byte *)(param_1 + 0x26);
    if (*(char *)(param_1 + 0x27) == '\0') {
      pcVar14 = "Led off";
    }
    else {
      pcVar14 = "Led on";
    }
    if (*(char *)(param_1 + 0x28) == '\0') {
      pcVar1 = "Led off";
    }
    else {
      pcVar1 = "Led on";
    }
    if (*(char *)(param_1 + 0x2a) == '\0') {
      pcVar2 = "Led off";
    }
    else {
      pcVar2 = "Led on";
    }
    if (*(char *)(param_1 + 0x2b) == '\0') {
      pcVar3 = "Led off";
    }
    else {
      pcVar3 = "Led on";
    }
    local_70 = (int)*(char *)(param_1 + 0x2c);
    if (*(char *)(param_1 + 0x2d) == '\0') {
      pcVar4 = "Led off";
    }
    else {
      pcVar4 = "Led on";
    }
    local_68 = (int)*(char *)(param_1 + 0x41);
    local_6c = (int)*(char *)(param_1 + 0x2e);
    local_64 = (int)*(char *)(param_1 + 0x42);
    local_60 = (uint)*(byte *)(param_1 + 0x43);
    local_5c = (uint)*(byte *)(param_1 + 0x44);
    local_58 = (uint)*(ushort *)(param_1 + 0x46);
    if (*(char *)(param_1 + 0x48) == '\0') {
      pcVar5 = "Led off";
    }
    else {
      pcVar5 = "Led on";
    }
    if (*(short *)(param_1 + 0x22) == 0) {
      pcVar6 = "Led off";
    }
    else {
      pcVar6 = "Led on";
    }
    local_50 = (uint)*(byte *)(param_1 + 0x49);
    local_54 = (uint)*(byte *)(param_1 + 0xe);
    if (*(char *)(param_1 + 0x18) == '\0') {
      pcVar7 = "Led off";
    }
    else {
      pcVar7 = "Led on";
    }
    local_4c = (uint)*(ushort *)(param_1 + 0x10);
    local_40 = (uint)*(ushort *)(param_1 + 0x14);
    local_48 = (uint)*(ushort *)(param_1 + 0x12);
    local_44 = (uint)*(ushort *)(param_1 + 0x16);
    local_3c = (int)*(char *)(param_1 + 0x2f);
    if (*(char *)(param_1 + 0x30) == '\0') {
      pcVar8 = "Led off";
    }
    else {
      pcVar8 = "Led on";
    }
    local_38 = (uint)*(byte *)(param_1 + 0x31);
    if (*(char *)(param_1 + 0x32) == -1) {
      pcVar17 = "null";
    }
    else if (*(char *)(param_1 + 0x32) == '\0') {
      pcVar17 = "off";
    }
    else {
      pcVar17 = "on";
    }
    if (*(char *)(param_1 + 0x33) == -1) {
      pcVar16 = "null";
    }
    else if (*(char *)(param_1 + 0x33) == '\0') {
      pcVar16 = "off";
    }
    else {
      pcVar16 = "on";
    }
    if (*(char *)(param_1 + 0x34) == -1) {
      pcVar15 = "null";
    }
    else if (*(char *)(param_1 + 0x34) == '\0') {
      pcVar15 = "off";
    }
    else {
      pcVar15 = "on";
    }
    if (*(char *)(param_1 + 0x35) == -1) {
      pcVar13 = "null";
    }
    else if (*(char *)(param_1 + 0x35) == '\0') {
      pcVar13 = "off";
    }
    else {
      pcVar13 = "on";
    }
    if (*(char *)(param_1 + 0x36) == -1) {
      pcVar12 = "null";
    }
    else if (*(char *)(param_1 + 0x36) == '\0') {
      pcVar12 = "off";
    }
    else {
      pcVar12 = "on";
    }
    local_34 = (int)*(char *)(param_1 + 0x37);
    if (*(char *)(param_1 + 0x38) == -1) {
      pcVar10 = "null";
    }
    else if (*(char *)(param_1 + 0x38) == '\0') {
      pcVar10 = "off";
    }
    else {
      pcVar10 = "on";
    }
    if (*(char *)(param_1 + 0x39) == -1) {
      pcVar19 = "null";
    }
    else if (*(char *)(param_1 + 0x39) == '\0') {
      pcVar19 = "off";
    }
    else {
      pcVar19 = "on";
    }
    iVar18 = -1;
    snprintf(acStack_688,0x600,
             "INSERT INTO %s VALUES( %d, %d, %d,%d, %d, %d, %d,%d, %d, %d, %d, %d,%d, %d, \'%s\', \'%s\',\'%s\', \'%s\', %d, \'%s\',%d, %d, %d, %d,%d, %d, \'%s\',\'%s\', %d, %d, \'%s\', %d, %d, %d, %d,%d, \'%s\', %d,  \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%d\', \'%s\', \'%s\',null);"
             ,"rdmngrTable",*(undefined4 *)(param_1 + 4),(int)*(char *)(param_1 + 8),
             (int)*(char *)(param_1 + 8),(int)*(char *)(param_1 + 9),(uint)*(byte *)(param_1 + 10),
             (int)*(short *)(param_1 + 0xc),(int)*(char *)(param_1 + 0x19),
             (uint)*(ushort *)(param_1 + 0x1a),local_30,local_84,local_80,local_7c,local_78,local_74
             ,pcVar14 + 4,pcVar1 + 4,pcVar2 + 4,pcVar3 + 4,local_70,pcVar4 + 4,local_6c,local_68,
             local_64,local_60,local_5c,local_58,pcVar5 + 4,pcVar6 + 4,local_54,local_50,pcVar7 + 4,
             local_4c,local_48,local_44,local_40,local_3c,pcVar8 + 4,local_38,pcVar17,pcVar16,
             pcVar15,pcVar13,pcVar12,local_34,pcVar10,pcVar19);
    if ((local_88 != 0) && (iVar18 = FUN_00407d60(iVar11,acStack_688), iVar18 != 0)) {
      iVar11 = FUN_00408410();
      if (iVar11 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "rdmngr_db_sqlite_rd_insert",0x244,iVar18,acStack_688,
               "Failed to insert into rd table in flash.");
      }
      goto LAB_00618758;
    }
    if ((rdmngr_debug_switch == 0) || (iVar11 = is_target_debug_ap(), iVar11 == 0))
    goto LAB_00618758;
    pcVar14 = "[RDMNGR_DEBUG]%s()/%d rdmngr_db_sqlite_rd_insert() OK.\n";
    uVar9 = 0x247;
  }
  printf(pcVar14,"rdmngr_db_sqlite_rd_insert",uVar9);
LAB_00618758:
  FUN_00407df0(param_1);
  uVar9 = 0xffffffff;
  if (iVar18 == 0) {
    uVar9 = 0;
  }
  return uVar9;
}

