// func _apmngr_db_run_conformity_check @ 0054333c size=752

undefined4 _apmngr_db_run_conformity_check(undefined4 param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  char acStack_710 [32];
  undefined1 auStack_6f0 [18];
  ushort local_6de;
  int local_6b4;
  ushort local_4e8;
  ushort local_4e6;
  ushort local_4e4;
  uint local_4e0;
  undefined4 local_4dc;
  int local_468;
  byte local_45b;
  int local_444;
  char acStack_418 [1024];
  
  memset(auStack_6f0,0,0x2d8);
  memset(acStack_418,0,0x400);
  uVar2 = atoi(*(char **)(param_3 + 4));
  pcVar6 = (char *)(uVar2 & 0xffff);
  iVar3 = apmngr_db_entry_get_by_id(pcVar6,auStack_6f0);
  if (iVar3 != 0) {
    pcVar8 = "[ERROR!]Failed to find ap_entry(%d) in mem but it actually EXISTS in database.\n";
    goto LAB_005435ac;
  }
  *(undefined1 *)(g_debug_entry_bit + (int)pcVar6 * 2 + 1) = 1;
  uVar7 = (uint)local_6de;
  uVar2 = atoi(*(char **)(param_3 + 8));
  if (uVar7 != uVar2) {
    sVar4 = strlen(acStack_418);
    snprintf(acStack_418 + sVar4,0x400 - sVar4,"%u\tgroup_id\t%d\t%d\n",pcVar6,uVar7,uVar2);
  }
  iVar3 = atoi(*(char **)(param_3 + 0xc));
  if (local_6b4 != iVar3) {
    sVar4 = strlen(acStack_418);
    snprintf(acStack_418 + sVar4,0x400 - sVar4,"%u\tfirm\t%d\t%d\n",pcVar6,local_6b4,iVar3);
  }
  bVar1 = local_6b4 != iVar3 || uVar7 != uVar2;
  if (*(int *)(param_3 + 0x10) == 0) {
LAB_005434cc:
    pcVar8 = *(char **)(param_3 + 0x14);
  }
  else {
    memset(acStack_710,0,0x1e);
    uVar5 = local_4e0 >> 0x10;
    uVar2 = (local_4e0 << 0x10) >> 0x18;
    uVar7 = local_4e0 & 0xff;
    snprintf(acStack_710,0x1e,"%2u.%2u.%2u.%4u.%2u.%2u.%5u",(uint)local_4e8,(uint)local_4e6,
             (uint)local_4e4,uVar5,uVar2,uVar7,local_4dc);
    pcVar8 = *(char **)(param_3 + 0x10);
    iVar3 = strncmp(acStack_710,pcVar8,0x1e);
    if (iVar3 == 0) goto LAB_005434cc;
    bVar1 = true;
    sVar4 = strlen(acStack_418);
    snprintf(acStack_418 + sVar4,0x400 - sVar4,"%u\tsoftver\t%s\t%s\n",pcVar6,acStack_710,pcVar8,
             uVar5,uVar2,uVar7,local_4dc);
    pcVar8 = *(char **)(param_3 + 0x14);
  }
  iVar3 = atoi(pcVar8);
  if (local_468 != iVar3) {
    bVar1 = true;
    sVar4 = strlen(acStack_418);
    snprintf(acStack_418 + sVar4,0x400 - sVar4,"%u\tled\t%d\t%d\n",pcVar6,local_468,iVar3);
  }
  uVar2 = atoi(*(char **)(param_3 + 0x18));
  if (local_45b != uVar2) {
    bVar1 = true;
    sVar4 = strlen(acStack_418);
    snprintf(acStack_418 + sVar4,0x400 - sVar4,"%u\ttelnet\t%d\t%d\n",pcVar6,(uint)local_45b,uVar2);
  }
  iVar3 = atoi(*(char **)(param_3 + 0x1c));
  if (local_444 == iVar3) {
    if (!bVar1) {
      return 0;
    }
  }
  else {
    sVar4 = strlen(acStack_418);
    snprintf(acStack_418 + sVar4,0x400 - sVar4,"%u\trun_state\t%d\t%d\n",pcVar6,local_444,iVar3);
  }
  pcVar6 = acStack_418;
  pcVar8 = "%s";
LAB_005435ac:
  printf(pcVar8,pcVar6);
  return 0;
}

