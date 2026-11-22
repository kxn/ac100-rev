// func _apmngr_jcs_entry_backup_to_file @ 00553d80 size=2344

undefined4 _apmngr_jcs_entry_backup_to_file(int param_1,FILE *param_2)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_7a8 [20];
  char acStack_794 [112];
  char acStack_724 [200];
  undefined1 auStack_65c [200];
  undefined1 auStack_594 [20];
  int local_580;
  int local_578;
  int local_524;
  char acStack_4ba [65];
  char local_479 [73];
  int local_430;
  char acStack_42c [1028];
  
  memset(acStack_42c,0,0x400);
  memset(auStack_65c,0,200);
  memset(acStack_724,0,200);
  memset(auStack_7a8,0,0x84);
  memset(auStack_594,0,0x168);
  if (*(int *)(param_1 + 0x3c) != 0) {
    apmngr_db_group_get_by_id(*(undefined2 *)(param_1 + 0x12),auStack_7a8);
    pcVar1 = strchr(acStack_794,0x2c);
    if ((pcVar1 == (char *)0x0) && (pcVar1 = strchr(acStack_794,0x22), pcVar1 == (char *)0x0)) {
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      pcVar4 = "%s,";
      pcVar5 = acStack_794;
    }
    else {
      FUN_00553cc8(acStack_724,acStack_794);
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      pcVar4 = "\"%s\",";
      pcVar5 = acStack_724;
    }
    pcVar7 = (char *)(param_1 + 0x4e);
    snprintf(pcVar1,0x400 - sVar2,pcVar4,pcVar5);
    pcVar1 = strchr(pcVar7,0x2c);
    if ((pcVar1 == (char *)0x0) && (pcVar1 = strchr(pcVar7,0x22), pcVar1 == (char *)0x0)) {
      sVar2 = strlen(acStack_42c);
      pcVar4 = acStack_42c + sVar2;
      pcVar5 = "%s,";
      pcVar1 = pcVar7;
    }
    else {
      FUN_00553cc8(acStack_724,pcVar7);
      sVar2 = strlen(acStack_42c);
      pcVar4 = acStack_42c + sVar2;
      pcVar5 = "\"%s\",";
      pcVar1 = acStack_724;
    }
    snprintf(pcVar4,0x400 - sVar2,pcVar5,pcVar1);
    if (*(int *)(param_1 + 0xc) == 0) {
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      pcVar4 = &DAT_006ce9e8;
    }
    else {
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      pcVar4 = &DAT_006ce9f0;
    }
    snprintf(pcVar1,0x400 - sVar2,pcVar4);
    sVar2 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%d,",*(undefined4 *)(param_1 + 0x40));
    apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_594);
    sVar2 = strlen(acStack_42c);
    pcVar1 = local_479;
    if (local_479[0] == '\0') {
      pcVar1 = acStack_4ba;
    }
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",pcVar1);
    apdb_get_hwver_name_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_65c,200);
    sVar2 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"v%s,",auStack_65c);
    sVar2 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%02X-%02X-%02X-%02X-%02X-%02X,",
             (uint)*(byte *)(param_1 + 0x48),(uint)*(byte *)(param_1 + 0x49),
             (uint)*(byte *)(param_1 + 0x4a),(uint)*(byte *)(param_1 + 0x4b),
             (uint)*(byte *)(param_1 + 0x4c),(uint)*(byte *)(param_1 + 0x4d));
    sVar2 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%d,",(uint)*(byte *)(param_1 + 0xe8));
    sVar2 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%d,",(uint)*(ushort *)(param_1 + 0xea));
    sVar2 = strlen(acStack_42c);
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%d,",*(undefined4 *)(param_1 + 0xec));
    sVar2 = strlen(acStack_42c);
    if (*(int *)(param_1 + 0xf0) == 1) {
      puVar6 = &DAT_006ce9a4;
    }
    else {
      puVar6 = &DAT_006ce9ac;
    }
    iVar9 = 0;
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",puVar6);
    iVar8 = param_1;
    while( true ) {
      iVar3 = local_580;
      if (4 < local_580) {
        iVar3 = 4;
      }
      if (iVar3 <= iVar9) break;
      iVar9 = iVar9 + 1;
      sVar2 = strlen(acStack_42c);
      snprintf(acStack_42c + sVar2,0x400 - sVar2,"%d,",(uint)*(ushort *)(iVar8 + 0x128));
      iVar8 = iVar8 + 2;
    }
    for (; iVar3 < 4; iVar3 = iVar3 + 1) {
      sVar2 = strlen(acStack_42c);
      snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,","---");
    }
    if ((local_524 == 0) ||
       (((*(int *)(param_1 + 0xc) != 0 && (local_578 != 0)) &&
        (sVar2 = strlen(pcVar7), *(char *)(param_1 + sVar2 + 0x4d) != '1')))) {
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      sVar2 = 0x400 - sVar2;
      pcVar4 = "---";
    }
    else {
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      sVar2 = 0x400 - sVar2;
      if (*(int *)(param_1 + 0x124) == 1) {
        pcVar4 = &DAT_006ce9a4;
      }
      else {
        pcVar4 = &DAT_006ce9ac;
      }
    }
    snprintf(pcVar1,sVar2,"%s,",pcVar4);
    sVar2 = strlen(acStack_42c);
    if (*(int *)(param_1 + 0x1b8) == 1) {
      puVar6 = &DAT_006ce9a4;
    }
    else {
      puVar6 = &DAT_006ce9ac;
    }
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",puVar6);
    sVar2 = strlen(acStack_42c);
    if (*(char *)(param_1 + 0x1b4) == '\x01') {
      pcVar1 = &DAT_006ce9a4;
    }
    else if (*(char *)(param_1 + 0x1b4) == '\0') {
      pcVar1 = &DAT_006ce9ac;
    }
    else {
      pcVar1 = "---";
    }
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",pcVar1);
    sVar2 = strlen(acStack_42c);
    if (*(char *)(param_1 + 0x207) == '\x01') {
      puVar6 = &DAT_006ce9a4;
    }
    else {
      puVar6 = &DAT_006ce9ac;
    }
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",puVar6);
    sVar2 = strlen(acStack_42c);
    if (*(char *)(param_1 + 0x2d2) == '\x01') {
      pcVar1 = &DAT_006ce9b4;
    }
    else if (*(char *)(param_1 + 0x2d2) == '\0') {
      pcVar1 = &DAT_006ce9bc;
    }
    else {
      pcVar1 = "---";
    }
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",pcVar1);
    if ((local_430 == 0) || (*(int *)(local_430 + 0x2c) == 0)) {
      sVar2 = strlen(acStack_42c);
      snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,","---");
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      pcVar4 = "---";
    }
    else {
      sVar2 = strlen(acStack_42c);
      if (*(char *)(param_1 + 0x2b1) == '\0') {
        puVar6 = &DAT_006ce9ac;
      }
      else {
        puVar6 = &DAT_006ce9a4;
      }
      snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",puVar6);
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      if (*(char *)(param_1 + 0x2b2) == '\0') {
        pcVar4 = &DAT_006ce9c8;
      }
      else {
        pcVar4 = &DAT_006ce9d8;
      }
    }
    snprintf(pcVar1,0x400 - sVar2,"%s,",pcVar4);
    pcVar1 = (char *)(uint)*(byte *)(param_1 + 0x2d1);
    if (pcVar1 == (char *)0xff) {
      sVar2 = strlen(acStack_42c);
      pcVar4 = acStack_42c + sVar2;
      pcVar5 = "%s,";
      pcVar1 = "---";
    }
    else {
      sVar2 = strlen(acStack_42c);
      pcVar4 = acStack_42c + sVar2;
      pcVar5 = "%d,";
    }
    snprintf(pcVar4,0x400 - sVar2,pcVar5,pcVar1);
    sVar2 = strlen(acStack_42c);
    if (*(char *)(param_1 + 0x131) == '\x01') {
      pcVar1 = &DAT_006ce9a4;
    }
    else if (*(char *)(param_1 + 0x131) == '\0') {
      pcVar1 = &DAT_006ce9ac;
    }
    else {
      pcVar1 = "---";
    }
    snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,",pcVar1);
    if (*(char *)(param_1 + 0x131) == -1) {
      sVar2 = strlen(acStack_42c);
      snprintf(acStack_42c + sVar2,0x400 - sVar2,"%s,","---");
      sVar2 = strlen(acStack_42c);
      pcVar1 = acStack_42c + sVar2;
      sVar2 = 0x400 - sVar2;
      pcVar4 = "%s\r\n";
      pcVar5 = "---";
    }
    else {
      pcVar4 = (char *)(param_1 + 0x132);
      pcVar1 = strchr(pcVar4,0x2c);
      if ((pcVar1 == (char *)0x0) && (pcVar1 = strchr(pcVar4,0x22), pcVar1 == (char *)0x0)) {
        sVar2 = strlen(acStack_42c);
        pcVar1 = acStack_42c + sVar2;
        pcVar7 = "%s,";
      }
      else {
        FUN_00553cc8(acStack_724,pcVar4);
        sVar2 = strlen(acStack_42c);
        pcVar1 = acStack_42c + sVar2;
        pcVar7 = "\"%s\",";
        pcVar4 = acStack_724;
      }
      pcVar5 = (char *)(param_1 + 0x173);
      snprintf(pcVar1,0x400 - sVar2,pcVar7,pcVar4);
      pcVar1 = strchr(pcVar5,0x2c);
      if ((pcVar1 == (char *)0x0) && (pcVar1 = strchr(pcVar5,0x22), pcVar1 == (char *)0x0)) {
        sVar2 = strlen(acStack_42c);
        pcVar1 = acStack_42c + sVar2;
        sVar2 = 0x400 - sVar2;
        pcVar4 = "%s\r\n";
      }
      else {
        FUN_00553cc8(acStack_724,pcVar5);
        sVar2 = strlen(acStack_42c);
        pcVar1 = acStack_42c + sVar2;
        sVar2 = 0x400 - sVar2;
        pcVar4 = "\"%s\"\r\n";
        pcVar5 = acStack_724;
      }
    }
    snprintf(pcVar1,sVar2,pcVar4,pcVar5);
    sVar2 = strlen(acStack_42c);
    fwrite(acStack_42c,sVar2,1,param_2);
  }
  return 0;
}

