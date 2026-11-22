// func _apmngr_db_entry_conformity_check @ 0054362c size=1

undefined4 _apmngr_db_entry_conformity_check(int *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  ushort *puVar12;
  char acStack_720 [24];
  undefined1 auStack_708 [18];
  ushort uStack_6f6;
  int iStack_6c8;
  uint uStack_6c4;
  byte bStack_6c0;
  byte bStack_6bf;
  byte bStack_6be;
  byte bStack_6bd;
  byte bStack_6bc;
  byte bStack_6bb;
  char acStack_6ba [154];
  byte bStack_620;
  ushort uStack_61e;
  int iStack_61c;
  int iStack_618;
  char acStack_614 [32];
  char acStack_5f4 [16];
  int iStack_5e4;
  ushort auStack_5e0 [72];
  int iStack_550;
  char acStack_543 [65];
  char cStack_502;
  ushort uStack_470;
  char acStack_430 [1024];
  undefined4 *puStack_30;
  
  memset(auStack_708,0,0x2d8);
  memset(acStack_430,0,0x400);
  uVar3 = atoi(*(char **)(param_3 + 4));
  pcVar9 = (char *)(uVar3 & 0xffff);
  iVar4 = apmngr_db_entry_get_by_id(pcVar9,auStack_708);
  if (iVar4 != 0) {
    pcVar10 = "[ERROR!]Failed to find ap_entry(%d) in mem but it actually EXISTS in database.\n";
    goto code_r0x00543b60;
  }
  *(undefined1 *)(g_debug_entry_bit + (int)pcVar9 * 2) = 1;
  uVar3 = atoi(*(char **)(param_3 + 8));
  bVar1 = uStack_6f6 != uVar3;
  if (bVar1) {
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tgroup_id\t%d\t%d\n",pcVar9,(uint)uStack_6f6,
             uVar3);
  }
  iVar4 = 3;
  if (*param_1 == 0) {
    iVar6 = 0xc;
  }
  else {
    acStack_720[0] = '\0';
    acStack_720[1] = '\0';
    acStack_720[2] = '\0';
    acStack_720[3] = '\0';
    acStack_720[4] = '\0';
    acStack_720[5] = '\0';
    acStack_720[6] = '\0';
    acStack_720[7] = '\0';
    iVar4 = 4;
    acStack_720[8] = '\0';
    acStack_720[9] = '\0';
    acStack_720[10] = '\0';
    acStack_720[0xb] = '\0';
    uVar3 = (uint)bStack_6bd;
    acStack_720[0xc] = '\0';
    acStack_720[0xd] = '\0';
    acStack_720[0xe] = '\0';
    acStack_720[0xf] = '\0';
    acStack_720[0x10] = '\0';
    acStack_720[0x11] = '\0';
    uVar7 = (uint)bStack_6bc;
    uVar8 = (uint)bStack_6bb;
    snprintf(acStack_720,0x12,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)bStack_6c0,(uint)bStack_6bf,
             (uint)bStack_6be,uVar3,uVar7,uVar8);
    pcVar10 = *(char **)(param_3 + 0xc);
    iVar6 = strncmp(acStack_720,pcVar10,0x12);
    if (iVar6 == 0) {
      iVar6 = 0x10;
    }
    else {
      bVar1 = true;
      sVar5 = strlen(acStack_430);
      snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tmac\t%s\t%s\n",pcVar9,acStack_720,pcVar10,
               uVar3,uVar7,uVar8);
      iVar6 = 0x10;
    }
  }
  puStack_30 = (undefined4 *)(param_3 + iVar6);
  pcVar10 = (char *)*puStack_30;
  iVar6 = strncmp(acStack_6ba,pcVar10,0x9a);
  if (iVar6 != 0) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tentry_name\t%s\t%s\n",pcVar9,acStack_6ba,pcVar10
            );
  }
  iVar6 = atoi(*(char **)(param_3 + (iVar4 + 1) * 4));
  if (iStack_6c8 != iVar6) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tmodel_id\t%d\t%d\n",pcVar9,iStack_6c8,iVar6);
  }
  if (uStack_6c4 != 0) {
    acStack_720[0] = '\0';
    acStack_720[1] = '\0';
    acStack_720[2] = '\0';
    acStack_720[3] = '\0';
    acStack_720[4] = '\0';
    acStack_720[5] = '\0';
    acStack_720[6] = '\0';
    acStack_720[7] = '\0';
    snprintf(acStack_720,8,"%u.%u",uStack_6c4 >> 0x10,uStack_6c4 & 0xffff);
    pcVar10 = *(char **)(param_3 + (iVar4 + 2) * 4);
    iVar6 = strncmp(acStack_720,pcVar10,8);
    if (iVar6 != 0) {
      bVar1 = true;
      sVar5 = strlen(acStack_430);
      snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\thardware_ver\t%s\t%s\n",pcVar9,acStack_720,
               pcVar10);
    }
  }
  uVar3 = atoi(*(char **)(param_3 + (iVar4 + 3) * 4));
  if (bStack_620 != uVar3) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tap_keep_alive\t%d\t%d\n",pcVar9,(uint)bStack_620
             ,uVar3);
  }
  uVar3 = atoi(*(char **)(param_3 + (iVar4 + 4) * 4));
  if (uStack_61e != uVar3) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tclient_keep_alive\t%d\t%d\n",pcVar9,
             (uint)uStack_61e,uVar3);
  }
  iVar6 = atoi(*(char **)(param_3 + (iVar4 + 5) * 4));
  if (iStack_61c != iVar6) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tclient_idle\t%d\t%d\n",pcVar9,iStack_61c,iVar6);
  }
  iVar6 = atoi(*(char **)(param_3 + (iVar4 + 6) * 4));
  if (iStack_618 != iVar6) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\toffline_selfmanage\t%d\t%d\n",pcVar9,iStack_618,
             iVar6);
  }
  pcVar10 = *(char **)(param_3 + (iVar4 + 7) * 4);
  iVar6 = strncmp(acStack_614,pcVar10,0x20);
  if (iVar6 != 0) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tusername\t%s\t%s\n",pcVar9,acStack_614,pcVar10);
  }
  pcVar10 = *(char **)(param_3 + (iVar4 + 8) * 4);
  iVar6 = strncmp(acStack_5f4,pcVar10,0x10);
  if (iVar6 != 0) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tpassword\t%s\t%s\n",pcVar9,acStack_5f4,pcVar10);
  }
  puVar12 = auStack_5e0;
  iVar6 = 1;
  do {
    uVar2 = *puVar12;
    uVar3 = atoi((char *)puStack_30[iVar6 + 8]);
    if (uVar2 != uVar3) {
      bVar1 = true;
      sVar5 = strlen(acStack_430);
      snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\textend_wire_vlan_%d\t%d\t%d\n",pcVar9,iVar6,
               (uint)uVar2,uVar3);
    }
    iVar6 = iVar6 + 1;
    puVar12 = puVar12 + 1;
  } while (iVar6 != 5);
  pcVar10 = *(char **)(param_3 + (iVar4 + 0xd) * 4);
  if (pcVar10 == (char *)0x0) {
    iVar6 = *param_1;
  }
  else {
    iVar6 = atoi(pcVar10);
    if (iStack_5e4 != iVar6) {
      bVar1 = true;
      sVar5 = strlen(acStack_430);
      snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tap_trunk\t%d\t%d\n",pcVar9,iStack_5e4,iVar6);
    }
    iVar6 = *param_1;
  }
  iVar11 = iVar4 + 0xe;
  if (iVar6 != 0) {
    pcVar10 = *(char **)(param_3 + iVar11 * 4);
    iVar11 = iVar4 + 0xf;
    if (pcVar10 != (char *)0x0) {
      uVar3 = atoi(pcVar10);
      if (uStack_470 != uVar3) {
        bVar1 = true;
        sVar5 = strlen(acStack_430);
        snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\thdap_peer_id\t%u\t%d\n",pcVar9,
                 (uint)uStack_470,uVar3);
      }
      iVar11 = iVar4 + 0xf;
    }
  }
  pcVar10 = *(char **)(param_3 + iVar11 * 4);
  if ((pcVar10 != (char *)0x0) && (iVar4 = atoi(pcVar10), iStack_550 != iVar4)) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tled\t%d\t%d\n",pcVar9,iStack_550,iVar4);
  }
  pcVar10 = *(char **)(param_3 + (iVar11 + 1) * 4);
  iVar4 = strncmp(acStack_543,pcVar10,0x41);
  if (iVar4 != 0) {
    bVar1 = true;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\tcloud_config_id\t%s\t%s\n",pcVar9,acStack_543,
             pcVar10);
  }
  pcVar10 = *(char **)(param_3 + (iVar11 + 2) * 4);
  if (pcVar10 == (char *)0x0) {
code_r0x00543b9c:
    if (!bVar1) {
      return 0;
    }
  }
  else {
    iVar4 = atoi(pcVar10);
    if (cStack_502 == iVar4) goto code_r0x00543b9c;
    sVar5 = strlen(acStack_430);
    snprintf(acStack_430 + sVar5,0x400 - sVar5,"%u\telnet_status\t%d\t%d\n",pcVar9,(int)cStack_502,
             iVar4);
  }
  pcVar9 = acStack_430;
  pcVar10 = "%s";
code_r0x00543b60:
  printf(pcVar10,pcVar9);
  return 0;
}

