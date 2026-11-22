// func apmngr_debug_ap_print @ 005423b8 size=1

/* WARNING: Removing unreachable block (ram,0x00542a3c) */
/* WARNING: Removing unreachable block (ram,0x00542a1c) */
/* WARNING: Removing unreachable block (ram,0x00542a08) */
/* WARNING: Removing unreachable block (ram,0x00542a28) */
/* WARNING: Removing unreachable block (ram,0x00542a48) */

void apmngr_debug_ap_print(int param_1,char param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  size_t sVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  undefined1 *puVar23;
  int iVar24;
  int extraout_v1;
  char *pcVar25;
  uint uVar26;
  uint uVar27;
  char *pcVar28;
  uint uVar29;
  byte *pbVar30;
  undefined *puVar31;
  uint uVar32;
  undefined4 uStack_9d0;
  char *apcStack_9cc [7];
  undefined4 auStack_9b0 [9];
  undefined1 auStack_98c [218];
  char acStack_8b2 [65];
  char acStack_871 [77];
  char acStack_824 [2052];
  
  memset(auStack_98c,0,0x168);
  memset(acStack_824,0,0x800);
  memcpy(apcStack_9cc + 3,&PTR_DAT_006c9c50,0x10);
  apcStack_9cc[0] = "Unknown";
  apcStack_9cc[1] = "On";
  apcStack_9cc[2] = "Off";
  memcpy(auStack_9b0,&PTR_s_Normal_006c9c60,0x24);
  apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_98c);
  if (*(int *)(param_1 + 0x3c) == 0) {
    puVar31 = &UNK_006c9454;
  }
  else {
    puVar31 = &DAT_006a89a8;
  }
  uVar2 = *(ushort *)(param_1 + 0x10);
  iVar3 = multi_link_status_get((uint)uVar2);
  if (iVar3 == 0) {
    pcVar25 = "Backup";
  }
  else {
    pcVar25 = "Master";
  }
  uVar29 = (uint)*(byte *)(param_1 + 0x4b);
  uVar27 = (uint)*(byte *)(param_1 + 0x4c);
  pcVar28 = acStack_871;
  if (acStack_871[0] == '\0') {
    pcVar28 = acStack_8b2;
  }
  uVar26 = (uint)*(byte *)(param_1 + 0x4d);
  uVar4 = *(uint *)(param_1 + 0x210);
  uVar17 = (uint)*(ushort *)(param_1 + 0x44);
  uVar18 = (uint)*(ushort *)(param_1 + 0x46);
  uVar19 = (uint)*(ushort *)(param_1 + 0x208);
  uVar20 = (uint)*(ushort *)(param_1 + 0x20a);
  uVar21 = (uint)*(ushort *)(param_1 + 0x20c);
  uVar22 = uVar4 >> 0x10;
  uVar32 = (uVar4 << 0x10) >> 0x18;
  uVar4 = uVar4 & 0xff;
  uVar5 = *(undefined4 *)(param_1 + 0x214);
  pcVar6 = apcStack_9cc[*(int *)(param_1 + 0x2ac) + 3];
  pcVar7 = apcStack_9cc[*(int *)(param_1 + 0x288)];
  uVar8 = *(undefined4 *)(param_1 + 0x28c);
  uVar9 = (uint)*(ushort *)(param_1 + 0x28);
  uVar10 = *(undefined4 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x30);
  uVar12 = *(undefined4 *)(param_1 + 0x34);
  uVar13 = *(undefined4 *)(param_1 + 0x38);
  snprintf(acStack_824,0x800,
           "%5u(%s,%s,%s(%d))|%3u|%20s|%02X-%02X-%02X-%02X-%02X-%02X|%16s %d.%d|%d.%2d.%2d(%04d.%02d.%02d.%05d)|%7s|%3s|%2d|%4x|%3d %3d|%3d %3d"
           ,(uint)uVar2,puVar31,pcVar25,auStack_9b0[*(int *)(param_1 + 0x14)],
           (int)*(short *)(param_1 + 0x18),(uint)*(ushort *)(param_1 + 0x12),param_1 + 0x4e,
           (uint)*(byte *)(param_1 + 0x48),(uint)*(byte *)(param_1 + 0x49),
           (uint)*(byte *)(param_1 + 0x4a),uVar29,uVar27,uVar26,pcVar28,uVar17,uVar18,uVar19,uVar20,
           uVar21,uVar22,uVar32,uVar4,uVar5,pcVar6,pcVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);
  if (param_2 == '\x01') {
    sVar14 = strlen(acStack_824);
    if (*(int *)(param_1 + 0xf0) == 0) {
      pcVar25 = "Led off";
    }
    else {
      pcVar25 = "Led on";
    }
    pcVar25 = pcVar25 + 4;
    uVar15 = param_1 + 0xf4;
    snprintf(acStack_824 + sVar14,0x800 - sVar14,
             "\n\t%2d|%4d|%5d|%3s|\'%31s\'|\'%15s\'|\'%5u.%5u.%5u.%5u\'|",
             (uint)*(byte *)(param_1 + 0xe8),(uint)*(ushort *)(param_1 + 0xea),
             *(undefined4 *)(param_1 + 0xec),pcVar25,uVar15,param_1 + 0x114,
             (uint)*(ushort *)(param_1 + 0x128),(uint)*(ushort *)(param_1 + 0x12a),
             (uint)*(ushort *)(param_1 + 300),(uint)*(ushort *)(param_1 + 0x12e),uVar29,uVar27,
             uVar26,pcVar28,uVar17,uVar18,uVar19,uVar20,uVar21,uVar22,uVar32,uVar4,uVar5,pcVar6,
             pcVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);
    sVar14 = strlen(acStack_824);
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%2d|",*(undefined4 *)(param_1 + 0x124));
    sVar14 = strlen(acStack_824);
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%2d|",*(undefined4 *)(param_1 + 0x1b8));
    sVar14 = strlen(acStack_824);
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%4d|",(uint)*(ushort *)(param_1 + 0x298));
    uVar5 = *(undefined4 *)(param_1 + 0x1b8);
    cVar1 = *(char *)(param_1 + 0x130);
    if (*(char *)(param_1 + 0x1bc) == '\0') {
      sVar14 = strlen(acStack_824);
      if (cVar1 == '\0') {
        pcVar28 = "LED";
      }
      else {
        pcVar28 = "LED+WiFi";
      }
      puVar23 = *(undefined1 **)(param_1 + 0x290);
      snprintf(acStack_824 + sVar14,0x800 - sVar14,"%2d(%s) timer:off/%d|\n\t",uVar5,pcVar28,puVar23
              );
    }
    else {
      sVar14 = strlen(acStack_824);
      if (cVar1 == '\0') {
        pcVar28 = "LED";
      }
      else {
        pcVar28 = "LED+WiFi";
      }
      if (*(byte *)(param_1 + 0x1bd) < 8) {
        puVar23 = (&g_apmngr_date_str)[*(byte *)(param_1 + 0x1bd)];
      }
      else {
        puVar23 = &DAT_00688af8;
      }
      pcVar25 = (char *)(uint)*(byte *)(param_1 + 0x1be);
      uVar15 = (uint)*(byte *)(param_1 + 0x1bf);
      if (*(byte *)(param_1 + 0x1c1) < 8) {
        puVar16 = (&g_apmngr_date_str)[*(byte *)(param_1 + 0x1c1)];
      }
      else {
        puVar16 = &DAT_00688af8;
      }
      snprintf(acStack_824 + sVar14,0x800 - sVar14,
               "%2d(%s) timer:[%s %02d:%02d:%02d-%s %02d:%02d:%02d]/%d|\n\t",uVar5,pcVar28,puVar23,
               pcVar25,uVar15,(uint)*(byte *)(param_1 + 0x1c0),puVar16,
               (uint)*(byte *)(param_1 + 0x1c2),(uint)*(byte *)(param_1 + 0x1c3),
               (uint)*(byte *)(param_1 + 0x1c4),*(undefined4 *)(param_1 + 0x290));
    }
    iVar3 = 0;
    strcat(acStack_824,"Capability : ");
    do {
      sVar14 = strlen(acStack_824);
      iVar24 = param_1 + iVar3;
      iVar3 = iVar3 + -4;
      snprintf(acStack_824 + sVar14,0x800 - sVar14,"%08X.",*(undefined4 *)(iVar24 + 0x25c));
    } while (iVar3 != -0x10);
    iVar3 = 0;
    strcat(acStack_824,"\b |\tChecksum : ");
    do {
      sVar14 = strlen(acStack_824);
      iVar24 = param_1 + iVar3;
      iVar3 = iVar3 + 1;
      snprintf(acStack_824 + sVar14,0x800 - sVar14,"%02X",(uint)*(byte *)(iVar24 + 0x29a));
    } while (iVar3 != 0x10);
    uStack_9d0 = 0;
    pbVar30 = (byte *)(param_1 + 0x260);
    uVar27 = 0;
    strcat(acStack_824," |Sub cap : ");
    do {
      iVar3 = memcmp(&uStack_9d0,(void *)(param_1 + 0x208 + (uVar27 + 0x16) * 4),4);
      if (iVar3 != 0) {
        sVar14 = strlen(acStack_824);
        pcVar28 = (char *)(uint)pbVar30[1];
        puVar23 = (undefined1 *)(uint)pbVar30[2];
        pcVar25 = (char *)(uint)pbVar30[3];
        uVar15 = uVar27;
        snprintf(acStack_824 + sVar14,0x800 - sVar14,"%02X%02X%02X%02X(%d) ",(uint)*pbVar30,pcVar28,
                 puVar23,pcVar25,uVar27);
      }
      uVar27 = uVar27 + 1;
      pbVar30 = pbVar30 + 4;
    } while (uVar27 != 3);
    sVar14 = strlen(acStack_824);
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"ap_mesh_enable %d",(int)*(char *)(param_1 + 0x207)
             ,pcVar28,puVar23,pcVar25,uVar15);
    strcat(acStack_824," |\tbluetooth_config : ");
    sVar14 = strlen(acStack_824);
    if (*(char *)(param_1 + 0x131) == '\x01') {
      pcVar25 = "on";
    }
    else if (*(char *)(param_1 + 0x131) == '\0') {
      pcVar25 = "off";
    }
    else {
      pcVar25 = "unsupport";
    }
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%s %s %s",pcVar25,param_1 + 0x132,param_1 + 0x173)
    ;
    strcat(acStack_824," |\tCloudConfigId : ");
    sVar14 = strlen(acStack_824);
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%s|",param_1 + 0x1c5);
    strcat(acStack_824,"\b |\tmodelId : ");
    sVar14 = strlen(acStack_824);
    uVar27 = 0;
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%d|",*(undefined4 *)(param_1 + 0x40));
    strcat(acStack_824,"\b |\tOnlineTime : ");
    if (1 < *(uint *)(param_1 + 0x2ac)) {
      FUN_00407e70();
      uVar27 = extraout_v1 - *(int *)(param_1 + 0x284);
    }
    sVar14 = strlen(acStack_824);
    snprintf(acStack_824 + sVar14,0x800 - sVar14,"%dd%dh%dm%ds|",uVar27 / 0x15180,
             (uVar27 % 0x15180) / 0xe10,(uVar27 % 0xe10) / 0x3c,uVar27 % 0x3c);
  }
  puts(acStack_824);
  return;
}

