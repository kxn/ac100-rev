// func _apmngr_template_hash_callback @ 00542e2c size=1

void _apmngr_template_hash_callback(int param_1)

{
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined1 *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined1 auStack_980 [218];
  char acStack_8a6 [65];
  char acStack_865 [77];
  char acStack_818 [2052];
  
  uVar18 = param_1 + 0x4e;
  memset(auStack_980,0,0x168);
  memset(acStack_818,0,0x800);
  apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_980);
  pcVar3 = acStack_865;
  if (acStack_865[0] == '\0') {
    pcVar3 = acStack_8a6;
  }
  puVar17 = (undefined1 *)(uint)*(ushort *)(param_1 + 0x44);
  uVar20 = (uint)*(ushort *)(param_1 + 0x46);
  uVar19 = (uint)*(byte *)(param_1 + 0xe8);
  uVar16 = (uint)*(ushort *)(param_1 + 0xea);
  uVar15 = *(undefined4 *)(param_1 + 0xec);
  if (*(int *)(param_1 + 0xf0) == 0) {
    pcVar5 = "Led off";
  }
  else {
    pcVar5 = "Led on";
  }
  pcVar5 = pcVar5 + 4;
  iVar14 = param_1 + 0xf4;
  iVar13 = param_1 + 0x114;
  uVar12 = (uint)*(ushort *)(param_1 + 0x128);
  uVar11 = (uint)*(ushort *)(param_1 + 0x12a);
  uVar10 = (uint)*(ushort *)(param_1 + 300);
  uVar9 = (uint)*(ushort *)(param_1 + 0x12e);
  uVar7 = *(undefined4 *)(param_1 + 0x124);
  uVar6 = *(undefined4 *)(param_1 + 0x1b8);
  if (*(char *)(param_1 + 0x130) == '\0') {
    pcVar2 = "LED";
  }
  else {
    pcVar2 = "LED+WiFi";
  }
  snprintf(acStack_818,0x800,
           "%5d(  Template )|%3d|%20s|                 |%16s %d.%d|%2d|%4d|%5d|%3s|\'%12s\'|\'%12s\'|\'%5d.%5d.%5d.%5d\'|%d | %d(%s)"
           ,(uint)*(ushort *)(param_1 + 0x10),(uint)*(ushort *)(param_1 + 0x12),uVar18,pcVar3,
           puVar17,uVar20,uVar19,uVar16,uVar15,pcVar5,iVar14,iVar13,uVar12,uVar11,uVar10,uVar9,uVar7
           ,uVar6,pcVar2);
  if (*(char *)(param_1 + 0x1bc) == '\0') {
    sVar1 = strlen(acStack_818);
    snprintf(acStack_818 + sVar1,0x800 - sVar1," timer:off");
    cVar4 = *(char *)(param_1 + 0x131);
  }
  else {
    sVar1 = strlen(acStack_818);
    if (*(byte *)(param_1 + 0x1bd) < 8) {
      puVar8 = (&g_apmngr_date_str)[*(byte *)(param_1 + 0x1bd)];
    }
    else {
      puVar8 = &DAT_00688af8;
    }
    uVar18 = (uint)*(byte *)(param_1 + 0x1bf);
    pcVar3 = (char *)(uint)*(byte *)(param_1 + 0x1c0);
    if (*(byte *)(param_1 + 0x1c1) < 8) {
      puVar17 = (&g_apmngr_date_str)[*(byte *)(param_1 + 0x1c1)];
    }
    else {
      puVar17 = &DAT_00688af8;
    }
    uVar20 = (uint)*(byte *)(param_1 + 0x1c2);
    uVar19 = (uint)*(byte *)(param_1 + 0x1c3);
    uVar16 = (uint)*(byte *)(param_1 + 0x1c4);
    snprintf(acStack_818 + sVar1,0x800 - sVar1," timer:[%s %02d:%02d:%02d-%s %02d:%02d:%02d]",puVar8
             ,(uint)*(byte *)(param_1 + 0x1be),uVar18,pcVar3,puVar17,uVar20,uVar19,uVar16,uVar15,
             pcVar5,iVar14,iVar13,uVar12,uVar11,uVar10,uVar9,uVar7,uVar6,pcVar2);
    cVar4 = *(char *)(param_1 + 0x131);
  }
  if (cVar4 == '\x01') {
    sVar1 = strlen(acStack_818);
    snprintf(acStack_818 + sVar1,0x800 - sVar1," bluetooth_enable: on [%12s %12s]",param_1 + 0x132,
             param_1 + 0x173,uVar18,pcVar3,puVar17,uVar20,uVar19,uVar16);
  }
  else {
    sVar1 = strlen(acStack_818);
    snprintf(acStack_818 + sVar1,0x800 - sVar1," bluetooth_enable: off or not support");
  }
  puts(acStack_818);
  return;
}

