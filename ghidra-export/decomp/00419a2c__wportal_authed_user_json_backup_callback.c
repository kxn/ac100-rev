// func _wportal_authed_user_json_backup_callback @ 00419a2c size=1232

/* WARNING: Removing unreachable block (ram,0x00419cb0) */
/* WARNING: Removing unreachable block (ram,0x00419c90) */
/* WARNING: Removing unreachable block (ram,0x00419c78) */
/* WARNING: Removing unreachable block (ram,0x00419c9c) */
/* WARNING: Removing unreachable block (ram,0x00419cbc) */

undefined4 _wportal_authed_user_json_backup_callback(int param_1,FILE *param_2)

{
  char cVar1;
  size_t sVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  int extraout_v1;
  char *pcVar7;
  undefined *puVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  char acStack_6f0 [200];
  undefined1 auStack_628 [304];
  char acStack_4f8 [216];
  char acStack_420 [1028];
  
  memset(acStack_420,0,0x400);
  memset(acStack_6f0,0,200);
  memset(auStack_628,0,0x205);
  if ((param_1 == 0) || (param_2 == (FILE *)0x0)) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_ERR]%s()/%d inputs error.\n","_wportal_authed_user_json_backup_callback",0x2581
          );
    return 0xffffffff;
  }
  cVar1 = *(char *)(param_1 + 0x81);
  if (cVar1 == '\0') {
    puVar8 = &DAT_00678b54;
LAB_00419aa8:
    sVar2 = strlen(acStack_420);
    uVar3 = _wportal_auth_type_int2chinesestr(*(undefined1 *)(param_1 + 0x80));
    snprintf(acStack_420 + sVar2,0x400 - sVar2,"%s(%s),",uVar3,puVar8);
  }
  else {
    if (cVar1 == '\x01') {
      puVar8 = &UNK_00678b64;
      goto LAB_00419aa8;
    }
    if (cVar1 == 'c') {
      puVar8 = &UNK_00678b74;
      goto LAB_00419aa8;
    }
    sVar2 = strlen(acStack_420);
    uVar3 = _wportal_auth_type_int2chinesestr(*(undefined1 *)(param_1 + 0x80));
    snprintf(acStack_420 + sVar2,0x400 - sVar2,"%s,",uVar3);
  }
  pcVar9 = (char *)(param_1 + 0xa3);
  pcVar4 = strchr(pcVar9,0x2c);
  if ((pcVar4 == (char *)0x0) && (pcVar4 = strchr(pcVar9,0x22), pcVar4 == (char *)0x0)) {
    sVar2 = strlen(acStack_420);
    pcVar4 = acStack_420 + sVar2;
    pcVar7 = "%s,";
    if (*(char *)(param_1 + 0xa3) == '\0') {
      pcVar9 = "---";
    }
  }
  else {
    FUN_00419974(acStack_6f0,pcVar9);
    sVar2 = strlen(acStack_420);
    pcVar4 = acStack_420 + sVar2;
    pcVar7 = "\"%s\",";
    pcVar9 = acStack_6f0;
  }
  snprintf(pcVar4,0x400 - sVar2,pcVar7,pcVar9);
  snprintf(acStack_6f0,200,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0xc),
           (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
           (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
           (uint)*(byte *)(param_1 + 0x11));
  sVar2 = strlen(acStack_420);
  snprintf(acStack_420 + sVar2,0x400 - sVar2,"%s,",acStack_6f0);
  if (g_portal_auth_mode == 1) {
    pcVar4 = *(char **)(param_1 + 0x14);
    if (pcVar4 == (char *)0xfff) goto LAB_00419e94;
    sVar2 = strlen(acStack_420);
    pcVar9 = acStack_420 + sVar2;
    sVar2 = 0x400 - sVar2;
    pcVar7 = "%d,";
  }
  else {
    memset(auStack_628,0,0x205);
    iVar5 = uac_wservice_get_entry_by_id(*(undefined4 *)(param_1 + 0x14),auStack_628);
    if (iVar5 == 0) {
      pcVar4 = strchr(acStack_4f8,0x2c);
      if ((pcVar4 == (char *)0x0) && (pcVar4 = strchr(acStack_4f8,0x22), pcVar4 == (char *)0x0)) {
        sVar6 = strlen(acStack_420);
        sVar2 = 0x400 - sVar6;
        pcVar9 = acStack_420 + sVar6;
        pcVar7 = "%s,";
        pcVar4 = acStack_4f8;
      }
      else {
        FUN_00419974(acStack_6f0,acStack_4f8);
        sVar2 = strlen(acStack_420);
        pcVar9 = acStack_420 + sVar2;
        sVar2 = 0x400 - sVar2;
        pcVar7 = "\"%s\",";
        pcVar4 = acStack_6f0;
      }
    }
    else {
LAB_00419e94:
      sVar2 = strlen(acStack_420);
      pcVar9 = acStack_420 + sVar2;
      sVar2 = 0x400 - sVar2;
      pcVar7 = "%s,";
      pcVar4 = "---";
    }
  }
  snprintf(pcVar9,sVar2,pcVar7,pcVar4);
  snprintf(acStack_6f0,200,"%04u/%02u/%02u %02u:%02u:%02u",(uint)*(ushort *)(param_1 + 0x108),
           (uint)*(byte *)(param_1 + 0x10a),(uint)*(byte *)(param_1 + 0x10b),
           (uint)*(byte *)(param_1 + 0x10c),(uint)*(byte *)(param_1 + 0x10d),
           (uint)*(byte *)(param_1 + 0x10e));
  sVar2 = strlen(acStack_420);
  snprintf(acStack_420 + sVar2,0x400 - sVar2,"%s,",acStack_6f0);
  uVar10 = *(uint *)(param_1 + 0x40);
  uVar12 = *(uint *)(param_1 + 0x44);
  uVar13 = FUN_00407e70();
  uVar11 = (uint)((ulonglong)uVar13 >> 0x20);
  if (uVar10 <= uVar11) {
    if (uVar10 != uVar11) {
      uVar11 = 0;
      goto LAB_00419c68;
    }
    if (uVar12 <= (uint)uVar13) {
      uVar11 = 0;
      goto LAB_00419c68;
    }
  }
  iVar5 = *(int *)(param_1 + 0x44);
  FUN_00407e70();
  uVar11 = iVar5 - extraout_v1;
LAB_00419c68:
  snprintf(acStack_6f0,200,&DAT_00678b9c,uVar11 / 0x15180,(uVar11 % 0x15180) / 0xe10,
           (uVar11 % 0xe10) / 0x3c,uVar11 % 0x3c);
  sVar2 = strlen(acStack_420);
  snprintf(acStack_420 + sVar2,0x400 - sVar2,"%s\r\n",acStack_6f0);
  sVar2 = strlen(acStack_420);
  fwrite(acStack_420,sVar2,1,param_2);
  return 0;
}

