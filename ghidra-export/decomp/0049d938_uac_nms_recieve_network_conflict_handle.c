// func uac_nms_recieve_network_conflict_handle @ 0049d938 size=788

void uac_nms_recieve_network_conflict_handle(byte *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  undefined8 uVar12;
  char local_d8 [80];
  char acStack_88 [104];
  
  memset(acStack_88,0,100);
  if (param_1 == (byte *)0x0) {
    return;
  }
  uVar12 = FUN_00407dd0();
  memset(local_d8 + 0x10,0,0x40);
  local_d8[0] = '\0';
  local_d8[1] = '\0';
  local_d8[2] = '\0';
  local_d8[3] = '\0';
  local_d8[4] = '\0';
  local_d8[5] = '\0';
  local_d8[6] = '\0';
  local_d8[7] = '\0';
  local_d8[8] = '\0';
  local_d8[9] = '\0';
  local_d8[10] = '\0';
  local_d8[0xb] = '\0';
  local_d8[0xc] = '\0';
  local_d8[0xd] = '\0';
  local_d8[0xe] = '\0';
  local_d8[0xf] = '\0';
  memset(local_d8 + 0x10,0,0x40);
  snprintf(local_d8,0x10,"%d",0xa7dcab);
  iVar2 = getUciOptionSpecifyPath
                    ("event_params",local_d8,"enable",local_d8 + 0x10,"/etc/nms_report");
  if (iVar2 != 0) {
    if (cloud_mngt_err_switch == '\0') {
      return;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d event_cfg_str get failed.\n\n","trigger_cw_network_conflict",
           0x2f5);
    return;
  }
  iVar2 = strcmp(local_d8 + 0x10,"off");
  uVar1 = CONCAT44(DAT_00767918,DAT_0076791c);
  if (iVar2 != 0) {
    memset(local_d8 + 0x10,0,0x40);
    snprintf(local_d8,0x10,"%d",0xa7dcab);
    iVar2 = getUciOptionSpecifyPath
                      ("event_params",local_d8,"detect_check_interval",local_d8 + 0x10,
                       "/etc/nms_report");
    iVar5 = 0x3c;
    if (iVar2 == 0) {
      iVar5 = atoi(local_d8 + 0x10);
    }
    uVar1 = uVar12;
    if (DAT_00767918 != 0 || DAT_0076791c != 0) {
      uVar6 = (uint)uVar12 - DAT_0076791c;
      uVar8 = ((int)((ulonglong)uVar12 >> 0x20) - DAT_00767918) - (uint)((uint)uVar12 < uVar6);
      uVar9 = iVar5 * 60000 >> 0x1f;
      if (uVar8 < uVar9) {
        return;
      }
      if ((uVar9 == uVar8) && (uVar6 < (uint)(iVar5 * 60000))) {
        return;
      }
    }
  }
  DAT_00767918 = (int)((ulonglong)uVar1 >> 0x20);
  DAT_0076791c = (int)uVar1;
  uVar3 = json_object_new_object();
  memset(acStack_88,0,100);
  if (*param_1 == 1) {
    pcVar11 = "0.0.0.0";
    FUN_00408190(*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),acStack_88,0x28,
                 "0.0.0.0");
    bVar7 = *param_1 ^ 1;
  }
  else {
    if (*param_1 != 2) goto LAB_0049da54;
    pcVar11 = "::";
    FUN_00408190(*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),acStack_88,0x28,
                 &DAT_00698ca0);
    bVar7 = *param_1 ^ 2;
  }
  pcVar10 = acStack_88;
  if (bVar7 != 0) {
    pcVar10 = pcVar11;
  }
  uVar4 = json_object_new_string(pcVar10);
  json_object_object_add(uVar3,&DAT_00677c24,uVar4);
LAB_0049da54:
  uVar4 = json_object_to_json_string_ext(uVar3,0);
  printf("%s %d %s\r\n","uac_nms_recieve_network_conflict_handle",0x321,uVar4);
  json_object_to_json_string_ext(uVar3,0);
  nms_event_notify(0xa7dcab);
  json_object_put(uVar3);
  return;
}

