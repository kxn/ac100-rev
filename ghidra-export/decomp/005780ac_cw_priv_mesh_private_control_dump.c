// func cw_priv_mesh_private_control_dump @ 005780ac size=3700

int cw_priv_mesh_private_control_dump(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  byte *pbVar8;
  char *pcVar9;
  short sVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  ushort *puVar14;
  short *psVar15;
  int iVar16;
  int iVar17;
  char *local_b8 [6];
  char acStack_a0 [36];
  undefined1 auStack_7c [40];
  undefined1 auStack_54 [44];
  
  memset(auStack_54,0,0x28);
  memset(auStack_7c,0,0x28);
  uVar12 = *(undefined4 *)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private mesh private control \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private mesh private control(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  uVar3 = FUN_00407fe0(uVar12);
  printf("\t\t\t\tValue: %04x.. \r\n",uVar3 & 0xffff);
  uVar4 = FUN_00407fe0(uVar12);
  printf("\t\t\t\tElement count: %d \r\n",uVar4);
  iVar5 = FUN_00407fe0(uVar12);
  if (iVar5 == 0) {
    return 0;
  }
  printf("\t\t\t\t\t*****Sub Message Element of mesh control private(%d)*****\n",
         (uint)*(ushort *)(param_1 + 0xc));
  iVar5 = FUN_004081b0(uVar12);
  if (iVar5 != 0) {
    uVar2 = *(ushort *)(iVar5 + 0xc);
    do {
      uVar3 = (uint)uVar2;
      pcVar11 = "Unknown";
      if (uVar3 < 0x1c) {
        pcVar11 = (&PTR_s_Discover_Request_006da358)[uVar3];
      }
      printf("\t\t\t\t\tSub element: (t=%d,l=%d) %s \r\n",uVar3,(uint)*(ushort *)(iVar5 + 0xe),
             pcVar11);
      switch(*(undefined2 *)(iVar5 + 0xc)) {
      case 0:
        if (**(char **)(iVar5 + 0x10) == '\0') {
          pcVar9 = "No";
          pcVar11 = "\t\t\t\t\t\tOnboarding:%s\n";
        }
        else {
          pcVar9 = "Yes";
          pcVar11 = "\t\t\t\t\t\tOnboarding:%s\n";
        }
        break;
      case 1:
        puVar14 = *(ushort **)(iVar5 + 0x10);
        if ((*puVar14 == 0) || (iVar16 = 0, *(int *)(puVar14 + 2) == 0)) {
LAB_00578c48:
          pcVar11 = "\t\t\t\t\t\tNo Re(s)";
LAB_00578c4c:
          puts(pcVar11);
        }
        else {
          while (iVar16 < (int)(uint)*puVar14) {
            iVar17 = iVar16 * 0x51;
            iVar16 = iVar16 + 1;
            pbVar7 = (byte *)(*(int *)(puVar14 + 2) + iVar17);
            printf("\t\t\t\t\t\tDev%d:\n",iVar16);
            printf("\t\t\t\t\t\t\tPap AP:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)*pbVar7,
                   (uint)pbVar7[1],(uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
            printf("\t\t\t\t\t\t\tRe  AP:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)pbVar7[8],
                   (uint)pbVar7[9],(uint)pbVar7[10],(uint)pbVar7[0xb],(uint)pbVar7[0xc],
                   (uint)pbVar7[0xd]);
            pcVar11 = "Wired";
            if (pbVar7[6] == 2) {
              pcVar11 = "Wireless";
            }
            printf("\t\t\t\t\t\t\tLink type:%s\n",pcVar11);
            printf("\t\t\t\t\t\t\tRssi:%d\n",(int)(char)pbVar7[7]);
            printf("\t\t\t\t\t\t\tModel name:%s\n",pbVar7 + 0xe);
            printf("\t\t\t\t\t\t\tHardware ver:%d.%d\n",(uint)pbVar7[0x4f],(uint)pbVar7[0x50]);
          }
        }
        goto switchD_00578224_caseD_19;
      case 2:
      case 8:
      case 9:
      case 0xb:
      case 0x13:
        puVar14 = *(ushort **)(iVar5 + 0x10);
        if (*puVar14 == 0) goto LAB_00578c48;
        pcVar11 = "\t\t\t\t\t\tNo Re(s)";
        if (*(int *)(puVar14 + 2) == 0) goto LAB_00578c4c;
        iVar17 = 0;
        iVar16 = 0;
        while (iVar16 < (int)(uint)*puVar14) {
          iVar16 = iVar16 + 1;
          pbVar7 = (byte *)(*(int *)(puVar14 + 2) + iVar17);
          iVar17 = iVar17 + 6;
          printf("\t\t\t\t\t\tRe%d:%02X-%02X-%02X-%02X-%02X-%02X\n",iVar16,(uint)*pbVar7,
                 (uint)pbVar7[1],(uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
        }
        goto switchD_00578224_caseD_19;
      case 3:
      case 0xd:
        pbVar7 = *(byte **)(iVar5 + 0x10);
        printf("\t\t\t\t\t\tRe  AP:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)*pbVar7,(uint)pbVar7[1],
               (uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
        pcVar9 = *(char **)(pbVar7 + 8);
        pcVar11 = "\t\t\t\t\t\tErrorcode:%d\n";
        break;
      case 4:
      case 5:
        pbVar7 = *(byte **)(iVar5 + 0x10);
        printf("\t\t\t\t\t\tRe Mac:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)*pbVar7,(uint)pbVar7[1],
               (uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
        if (*(short *)(iVar5 + 0xc) == 4) {
          pcVar11 = "Join Request";
        }
        else {
          pcVar11 = "Join Result";
        }
        printf("\t\t*****Sub Message Element of Mesh AP %s*****\n",pcVar11);
        for (iVar16 = FUN_004081b0(pbVar7 + 8); iVar16 != 0; iVar16 = FUN_00408680(iVar16)) {
          puVar14 = (ushort *)cw_msg_ele_mngr_get(*(undefined2 *)(iVar16 + 0xc));
          if (puVar14 == (ushort *)0x0) {
            if (capwap_err_switch == 0) {
              return -1;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return -1;
            }
            printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                   "cw_priv_mesh_private_control_dump",0x707,(uint)*(ushort *)(iVar16 + 0xc));
            return -1;
          }
          if (*(int *)(iVar16 + 0x10) == 0) {
            if (capwap_err_switch == 0) {
              return -1;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return -1;
            }
            printf("[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value\n",
                   "cw_priv_mesh_private_control_dump",0x70d,*(undefined4 *)(puVar14 + 2),
                   (uint)*puVar14);
            return -1;
          }
          iVar17 = (**(code **)(puVar14 + 0xe))(iVar16);
          if (((iVar17 == -1) && (capwap_err_switch != 0)) &&
             (iVar17 = is_target_debug_ap(), iVar17 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to dump %s(%d)\n",
                   "cw_priv_mesh_private_control_dump",0x714,*(undefined4 *)(puVar14 + 2),
                   (uint)*puVar14);
          }
        }
        if (*(short *)(iVar5 + 0xc) == 4) {
          pcVar9 = "Join Request";
          pcVar11 = "\t\t***Sub Message Element of Mesh AP %s End***\n";
        }
        else {
          pcVar9 = "Join Result";
          pcVar11 = "\t\t***Sub Message Element of Mesh AP %s End***\n";
        }
        break;
      case 6:
        puVar14 = *(ushort **)(iVar5 + 0x10);
        if ((*puVar14 == 0) || (iVar16 = 0, *(int *)(puVar14 + 2) == 0)) {
LAB_00578c5c:
          pcVar11 = "\t\t\t\t\t\tNo dev info";
          goto LAB_00578c4c;
        }
        while (iVar16 < (int)(uint)*puVar14) {
          iVar17 = iVar16 * 0x40;
          iVar16 = iVar16 + 1;
          cw_protocol_addr2str(*(int *)(puVar14 + 2) + iVar17 + 8,auStack_54,0x28);
          cw_protocol_addr2str(*(int *)(puVar14 + 2) + iVar17 + 0x1c,auStack_7c,0x28);
          pbVar7 = (byte *)(*(int *)(puVar14 + 2) + iVar17);
          pcVar11 = "Led on";
          if (pbVar7[0x30] == 0) {
            pcVar11 = "Led off";
          }
          pcVar9 = "Wireless";
          if (pbVar7[0x31] != 2) {
            pcVar9 = "Wired";
          }
          printf("\t\t\t\t\t\tDev%d:(%02X-%02X-%02X-%02X-%02X-%02X,%s,%s,%s,%s,%d,%02X-%02X-%02X-%02X-%02X-%02X)\n"
                 ,iVar16,(uint)*pbVar7,(uint)pbVar7[1],(uint)pbVar7[2],(uint)pbVar7[3],
                 (uint)pbVar7[4],(uint)pbVar7[5],auStack_54,auStack_7c,pcVar11,pcVar9,
                 *(undefined4 *)(pbVar7 + 0x34),(uint)pbVar7[0x38],(uint)pbVar7[0x39],
                 (uint)pbVar7[0x3a],(uint)pbVar7[0x3b],(uint)pbVar7[0x3c],(uint)pbVar7[0x3d]);
        }
        goto switchD_00578224_caseD_19;
      case 7:
        pbVar7 = *(byte **)(iVar5 + 0x10);
        pcVar11 = "Unknown";
        if (*pbVar7 < 3) {
          pcVar11 = *(char **)(&DAT_006da3ec + (uint)*pbVar7 * 4);
        }
        printf("\t\t\t\t\t\tEvent:%s\n",pcVar11);
        if ((*(short *)(pbVar7 + 2) == 0) || (*(int *)(pbVar7 + 4) == 0)) goto LAB_00578c5c;
        bVar1 = *pbVar7;
        iVar16 = 0;
        if ((bVar1 == 0) || (bVar1 == 2)) {
          while (iVar16 < (int)(uint)*(ushort *)(pbVar7 + 2)) {
            iVar17 = iVar16 * 0x40;
            iVar16 = iVar16 + 1;
            cw_protocol_addr2str(*(int *)(pbVar7 + 4) + iVar17 + 8,auStack_54,0x28);
            cw_protocol_addr2str(*(int *)(pbVar7 + 4) + iVar17 + 0x1c,auStack_7c,0x28);
            pbVar8 = (byte *)(*(int *)(pbVar7 + 4) + iVar17);
            pcVar11 = "Led on";
            if (pbVar8[0x30] == 0) {
              pcVar11 = "Led off";
            }
            pcVar9 = "Wireless";
            if (pbVar8[0x31] != 2) {
              pcVar9 = "Wired";
            }
            printf("\t\t\t\t\t\tDev%d:(%02X-%02X-%02X-%02X-%02X-%02X,%s,%s,%s,%s,%d,%02X-%02X-%02X-%02X-%02X-%02X)\n"
                   ,iVar16,(uint)*pbVar8,(uint)pbVar8[1],(uint)pbVar8[2],(uint)pbVar8[3],
                   (uint)pbVar8[4],(uint)pbVar8[5],auStack_54,auStack_7c,pcVar11,pcVar9,
                   *(undefined4 *)(pbVar8 + 0x34),(uint)pbVar8[0x38],(uint)pbVar8[0x39],
                   (uint)pbVar8[0x3a],(uint)pbVar8[0x3b],(uint)pbVar8[0x3c],(uint)pbVar8[0x3d]);
          }
        }
        else if (bVar1 == 1) {
          iVar17 = 0;
          iVar16 = 0;
          while (iVar16 < (int)(uint)*(ushort *)(pbVar7 + 2)) {
            iVar16 = iVar16 + 1;
            pbVar8 = (byte *)(*(int *)(pbVar7 + 4) + iVar17);
            iVar17 = iVar17 + 0x40;
            printf("\t\t\t\t\t\tDev%d:(%02X-%02X-%02X-%02X-%02X-%02X,%02X-%02X-%02X-%02X-%02X-%02X)\n"
                   ,iVar16,(uint)*pbVar8,(uint)pbVar8[1],(uint)pbVar8[2],(uint)pbVar8[3],
                   (uint)pbVar8[4],(uint)pbVar8[5],(uint)pbVar8[0x38],(uint)pbVar8[0x39],
                   (uint)pbVar8[0x3a],(uint)pbVar8[0x3b],(uint)pbVar8[0x3c],(uint)pbVar8[0x3d]);
          }
        }
        goto switchD_00578224_caseD_19;
      case 10:
        pcVar11 = *(char **)(iVar5 + 0x10);
        memset(acStack_a0,0,0x21);
        strncpy(acStack_a0,pcVar11,0x20);
        printf("\t\t\t\t\t\tSSID:%s\n",acStack_a0);
        sVar10 = *(short *)(pcVar11 + 0x20);
        if ((sVar10 < 1) || (*(char **)(pcVar11 + 0x24) == (char *)0x0)) {
          puts("\t\t\t\t\t\tKey:");
          sVar10 = *(short *)(pcVar11 + 0x28);
        }
        else {
          if (0x20 < sVar10) {
            sVar10 = 0x20;
          }
          strncpy(acStack_a0,*(char **)(pcVar11 + 0x24),(int)sVar10);
          printf("\t\t\t\t\t\tKey:%s\n",acStack_a0);
          sVar10 = *(short *)(pcVar11 + 0x28);
        }
        if ((sVar10 < 1) || (*(char **)(pcVar11 + 0x2c) == (char *)0x0)) {
          pcVar11 = "\t\t\t\t\t\tToken:";
          goto LAB_00578c4c;
        }
        if (0x20 < sVar10) {
          sVar10 = 0x20;
        }
        strncpy(acStack_a0,*(char **)(pcVar11 + 0x2c),(int)sVar10);
        pcVar9 = acStack_a0;
        pcVar11 = "\t\t\t\t\t\tToken:%s\n";
        break;
      case 0xc:
        pbVar7 = *(byte **)(iVar5 + 0x10);
        printf("\t\t\t\t\t\tRe  AP:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)*pbVar7,(uint)pbVar7[1],
               (uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
        if (pbVar7[6] == 2) {
          pcVar9 = "Wireless";
          pcVar11 = "\t\t\t\t\t\tLink type:%s\n";
        }
        else {
          pcVar9 = "Wired";
          pcVar11 = "\t\t\t\t\t\tLink type:%s\n";
        }
        break;
      case 0xe:
        pcVar11 = *(char **)(iVar5 + 0x10);
        if (*pcVar11 == '\0') {
          pcVar9 = "Led off";
        }
        else {
          pcVar9 = "Led on";
        }
        printf("\t\t\t\t\t\tWireless roam Switch:%s\n",pcVar9 + 4);
        if (pcVar11[1] == '\0') {
          pcVar9 = "off";
          pcVar11 = "\t\t\t\t\t\tWired roam Switch:%s\n";
        }
        else {
          pcVar9 = "on";
          pcVar11 = "\t\t\t\t\t\tWired roam Switch:%s\n";
        }
        break;
      case 0xf:
        psVar15 = *(short **)(iVar5 + 0x10);
        memset(acStack_a0,0,0x21);
        sVar10 = *psVar15;
        if ((sVar10 < 1) || (pcVar11 = *(char **)(psVar15 + 2), pcVar11 == (char *)0x0)) {
          pcVar11 = "\t\t\t\t\t\tPassword:";
          goto LAB_00578c4c;
        }
        if (0x20 < sVar10) {
          sVar10 = 0x20;
        }
        strncpy(acStack_a0,pcVar11,(int)sVar10);
        pcVar9 = acStack_a0;
        pcVar11 = "\t\t\t\t\t\tPassword:%s\n";
        break;
      case 0x10:
        pbVar7 = *(byte **)(iVar5 + 0x10);
        local_b8[0] = "CAP";
        local_b8[1] = "RE";
        pcVar11 = "Unknown";
        if (*pbVar7 < 2) {
          pcVar11 = local_b8[(char)*pbVar7];
        }
        printf("\t\t\t\t\t\tRole:%s\n",pcVar11);
        if (*pbVar7 == 1) {
          printf("\t\t\t\t\t\tCap:%02X-%02X-%02X-%02X-%02X-%02X\n",(uint)pbVar7[1],(uint)pbVar7[2],
                 (uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5],(uint)pbVar7[6]);
        }
        goto switchD_00578224_caseD_19;
      case 0x11:
        pcVar11 = "\t\t\t\t\t\tHops:%d\n";
        pcVar9 = (char *)(int)**(short **)(iVar5 + 0x10);
        break;
      case 0x12:
        pbVar7 = *(byte **)(iVar5 + 0x10);
        local_b8[0] = "CAP";
        local_b8[1] = "RE";
        bVar1 = *pbVar7;
        pcVar11 = "Unknown";
        if (bVar1 < 2) {
          pcVar11 = local_b8[(char)bVar1];
        }
        printf("\t\t\t\t\t\tRole:%s\n",pcVar11);
        if (pbVar7[1] == 0) {
          pcVar9 = "No";
          pcVar11 = "\t\t\t\t\t\tFixed:%s\n";
        }
        else {
          pcVar9 = "Yes";
          pcVar11 = "\t\t\t\t\t\tFixed:%s\n";
        }
        break;
      case 0x14:
        puVar14 = *(ushort **)(iVar5 + 0x10);
        if ((*puVar14 == 0) || (*(int *)(puVar14 + 2) == 0)) {
          puts("\t\t\t\t\t\tNo Re(s)");
        }
        else {
          iVar17 = 0;
          iVar16 = 0;
          while (iVar16 < (int)(uint)*puVar14) {
            iVar16 = iVar16 + 1;
            pbVar7 = (byte *)(*(int *)(puVar14 + 2) + iVar17);
            iVar17 = iVar17 + 6;
            printf("\t\t\t\t\t\tRe%d:%02X-%02X-%02X-%02X-%02X-%02X\n",iVar16,(uint)*pbVar7,
                   (uint)pbVar7[1],(uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
          }
        }
        pcVar11 = "\t\t\t\t\t\tDuration:%d\n";
        pcVar9 = *(char **)(puVar14 + 4);
        break;
      case 0x15:
        if (**(short **)(iVar5 + 0x10) == 0) {
          pcVar9 = "off";
          pcVar11 = "\t\t\t\t\t\tEnable:%s\n";
        }
        else {
          pcVar9 = "on";
          pcVar11 = "\t\t\t\t\t\tEnable:%s\n";
        }
        break;
      case 0x16:
        puVar14 = *(ushort **)(iVar5 + 0x10);
        memcpy(acStack_a0,&PTR_s_AP_006da0b0,0x10);
        local_b8[0] = "Physical";
        local_b8[1] = "Virtual";
        memcpy(local_b8 + 2,&PTR_s_Invalid_006da0c0,0x10);
        if (*puVar14 == 0) goto LAB_00578c48;
        pcVar11 = "\t\t\t\t\t\tNo Re(s)";
        if (*(int *)(puVar14 + 2) == 0) goto LAB_00578c4c;
        iVar17 = 0;
        iVar16 = 0;
        while (iVar16 < (int)(uint)*puVar14) {
          iVar16 = iVar16 + 1;
          pcVar11 = "Unknown";
          pbVar7 = (byte *)(*(int *)(puVar14 + 2) + iVar17);
          if (pbVar7[6] < 4) {
            pcVar11 = *(char **)(acStack_a0 + (uint)pbVar7[6] * 4);
          }
          pcVar9 = "Unknown";
          if (pbVar7[7] < 2) {
            pcVar9 = local_b8[pbVar7[7]];
          }
          pcVar6 = "Unknown";
          if (pbVar7[0xc] < 4) {
            pcVar6 = local_b8[pbVar7[0xc] + 2];
          }
          iVar17 = iVar17 + 0x10;
          printf("\t\t\t\t\t\tRe%d:%02X-%02X-%02X-%02X-%02X-%02X %s %s 0x%08x %s\n",iVar16,
                 (uint)*pbVar7,(uint)pbVar7[1],(uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],
                 (uint)pbVar7[5],pcVar11,pcVar9,*(undefined4 *)(pbVar7 + 8),pcVar6);
        }
        goto switchD_00578224_caseD_19;
      case 0x17:
        pcVar11 = "\t\t\t\t\t\tbh_work_mode=%d\n";
        pcVar9 = (char *)(uint)**(byte **)(iVar5 + 0x10);
        break;
      case 0x18:
        pcVar11 = "\t\t\t\t\t\tWan status: %d\n";
        pcVar9 = (char *)(int)**(char **)(iVar5 + 0x10);
        break;
      default:
        goto switchD_00578224_caseD_19;
      case 0x1b:
        puVar13 = *(undefined4 **)(iVar5 + 0x10);
        printf("\t\t\t\t\t\tPolicy mask: %d\n",*puVar13);
        pcVar9 = (char *)puVar13[1];
        pcVar11 = "\t\t\t\t\t\tPolicy: %d\n";
      }
      printf(pcVar11,pcVar9);
switchD_00578224_caseD_19:
      iVar5 = FUN_00408680(iVar5);
      if (iVar5 == 0) goto code_r0x00578268;
      uVar2 = *(ushort *)(iVar5 + 0xc);
    } while( true );
  }
LAB_0057826c:
  printf("\t\t\t\t\t***Sub Message Element of Mesh Control Public(%d) End***\n",
         (uint)*(ushort *)(param_1 + 0xc));
  return iVar5;
code_r0x00578268:
  iVar5 = 0;
  goto LAB_0057826c;
}

