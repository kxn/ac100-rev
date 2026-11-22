// func _stats_db_print_ap_by_id @ 00671928 size=4020

void _stats_db_print_ap_by_id(uint param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  undefined4 *puVar15;
  uint local_30;
  byte *local_2c;
  
  param_1 = param_1 & 0xffff;
  iVar3 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar3) {
    pbVar12 = (byte *)(DAT_007cc8ec + param_1 * 0x1e0);
    printf("ap id: %u\r\n",param_1);
    if ((*pbVar12 & 1) == 0) {
      pcVar6 = "inactive";
    }
    else {
      pcVar6 = "active";
    }
    if ((*pbVar12 & 2) == 0) {
      pcVar8 = "not-ready";
    }
    else {
      pcVar8 = "ready";
    }
    pbVar13 = pbVar12 + 0x18;
    iVar3 = 10;
    printf("state: %s, %s\r\n",pcVar6,pcVar8);
    printf("ap mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar12[0x10],(uint)pbVar12[0x11],
           (uint)pbVar12[0x12],(uint)pbVar12[0x13],(uint)pbVar12[0x14],(uint)pbVar12[0x15]);
    printf("data_bit_mask: 0x%x \r\n",*(undefined4 *)(pbVar12 + 8));
    printf("expiretime: %d \r\n",*(undefined4 *)(pbVar12 + 4));
    printf("global info: \n\r");
    if (param_2 == 0) {
      iVar3 = *(int *)(pbVar12 + 0x60);
    }
    printf("\tcpu num: %u\n",(uint)pbVar12[0x18]);
    printf("\tcpu utilization: ");
    bVar1 = *pbVar13;
    for (iVar9 = 0; iVar9 < (int)(uint)bVar1; iVar9 = iVar9 + 1) {
      printf("%u%% ",(uint)pbVar13[iVar9 + 1]);
      bVar1 = *pbVar13;
    }
    puts(" \r");
    iVar9 = 0;
    printf("\tmem utilization: %u%%\n",(uint)pbVar12[0x21]);
    printf("\tcapabilities: 0x%04x \r\n",(uint)*(ushort *)(pbVar12 + 0x22));
    printf("\tsta_associate_success: %llu\n");
    printf("\tsta_associate_fail: %llu\n");
    printf("\tsta_associate_auth_fail: %llu\n");
    printf("\tsta_associate_unknown_fail: %llu\n");
    printf("\tsta_dhcp_fail: %llu\n");
    printf("\tsta_portal_fail: %llu\n");
    printf("\tcloud_report_last_time: %llu\n");
    printf("\tsample_normal_count: %d\n",*(undefined4 *)(pbVar12 + 0x60));
    printf("\tsample_normal_last_time: %llu\n");
    puts("\t***************sample area start***************\r");
    printf("\tsample_sta_assoc_success_cumulate: %d\n",*(undefined4 *)(pbVar12 + 0x74));
    printf("\tsample_sta_assoc_fail_cumulate: %d\n",*(undefined4 *)(pbVar12 + 0x78));
    printf("\tsample_sta_assoc_auth_fail_cumulate: %d\n",*(undefined4 *)(pbVar12 + 0x7c));
    printf("\tsample_sta_assoc_unknown_fail_cumulate: %d\n",*(undefined4 *)(pbVar12 + 0x80));
    printf("\tsample_sta_dhcp_fail_cumulate: %d\n",*(undefined4 *)(pbVar12 + 0x84));
    printf("\tsample_sta_portal_fail_cumulate: %d\n",*(undefined4 *)(pbVar12 + 0x88));
    printf("\tsample_sta_assoc_success:");
    bVar2 = 0 < iVar3;
    pbVar10 = pbVar13;
    while (bVar2) {
      iVar9 = iVar9 + 1;
      printf("%u ",*(undefined4 *)(pbVar10 + 0x74));
      bVar2 = iVar9 < iVar3;
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tsample_sta_assoc_fail:");
    pbVar10 = pbVar13;
    for (iVar9 = 0; iVar9 < iVar3; iVar9 = iVar9 + 1) {
      printf("%u ",*(undefined4 *)(pbVar10 + 0x9c));
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tsample_sta_assoc_auth_faile:");
    pbVar10 = pbVar13;
    for (iVar9 = 0; iVar9 < iVar3; iVar9 = iVar9 + 1) {
      printf("%u ",*(undefined4 *)(pbVar10 + 0xc4));
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tsample_sta_assoc_unknown_fail:");
    pbVar10 = pbVar13;
    for (iVar9 = 0; iVar9 < iVar3; iVar9 = iVar9 + 1) {
      printf("%u ",*(undefined4 *)(pbVar10 + 0xec));
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tsample_sta_dhcp_fail:");
    pbVar10 = pbVar13;
    for (iVar9 = 0; iVar9 < iVar3; iVar9 = iVar9 + 1) {
      printf("%u ",*(undefined4 *)(pbVar10 + 0x114));
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tsample_sta_portal_fail:");
    pbVar10 = pbVar13;
    for (iVar9 = 0; iVar9 < iVar3; iVar9 = iVar9 + 1) {
      printf("%u ",*(undefined4 *)(pbVar10 + 0x13c));
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tsample_sta_portal_fail:");
    pbVar10 = pbVar13;
    for (iVar9 = 0; iVar9 < iVar3; iVar9 = iVar9 + 1) {
      printf("%u ",*(undefined4 *)(pbVar10 + 0x13c));
      pbVar10 = pbVar10 + 4;
    }
    puts(" \r");
    printf("\tcpu_utilization:");
    for (iVar9 = 0; iVar9 < (int)(uint)*pbVar13; iVar9 = iVar9 + 1) {
      puts(" \r");
      printf("\tcpu_utilization[%d]:",iVar9);
      for (iVar14 = 0; iVar14 < iVar3; iVar14 = iVar14 + 1) {
        printf("%u ",(uint)pbVar13[iVar14 * 8 + iVar9 + 0x164]);
      }
    }
    puts(" \r");
    printf("\tsample_mem_utilization:");
    bVar2 = 0 < iVar3;
    iVar9 = 0;
    while (bVar2) {
      printf("%u ",(uint)pbVar13[iVar9 + 0x1b4]);
      bVar2 = iVar9 + 1 < iVar3;
      iVar9 = iVar9 + 1;
    }
    puts(" \r");
    puts("\t***************sample area done***************\r");
    local_2c = *(byte **)(pbVar12 + 0x1d8);
    if (local_2c != (byte *)0x0) {
      local_30 = 1;
      do {
        uVar4 = rdmngr_profile_get_max_rd_per_ap();
        if (uVar4 < local_30) {
          puts("\r");
          return;
        }
        pbVar12 = *(byte **)(local_2c + 4);
        if (pbVar12 != (byte *)0x0) {
          uVar4 = 10;
          if (param_2 != 1) {
            if ((*pbVar12 & 1) == 0) goto LAB_00672354;
            if (param_2 == 0) {
              uVar4 = (uint)pbVar12[100];
            }
          }
          printf("\tradio id: %u\r\n",local_30);
          printf("\t\tprealloc: %u\r\n",(uint)*local_2c);
          if ((*pbVar12 & 1) == 0) {
            pcVar6 = "inactive";
          }
          else {
            pcVar6 = "active";
          }
          if ((*pbVar12 & 2) == 0) {
            pcVar8 = "not-ready";
          }
          else {
            pcVar8 = "ready";
          }
          printf("\t\tstate: %s, %s\r\n",pcVar6,pcVar8);
          printf("\t\texpiretime: %d \r\n",*(undefined4 *)(pbVar12 + 0x34));
          printf("\t\tsample_dense_count: %u\r\n",(uint)pbVar12[0x48]);
          printf("\t\tsample_dense_last_time: %u\r\n",*(undefined4 *)(pbVar12 + 0x4c));
          printf("\t\tsample_normal_count: %u\r\n",(uint)pbVar12[100]);
          printf("\t\tsample_normal_last_time: %llu\r\n");
          printf("\t\tcloud_report_last_time: %llu\r\n");
          if ((*pbVar12 & 2) == 0 && param_2 == 0) {
            puts("\t\t***************sample area start***************\r");
            printf("\t\tsample_client_num: ");
            bVar2 = uVar4 != 0;
            iVar3 = 0;
            while (bVar2) {
              printf("%u ",(uint)pbVar12[iVar3 + 0x50]);
              bVar2 = iVar3 + 1 < (int)uVar4;
              iVar3 = iVar3 + 1;
            }
            puts(" \r");
            puts("\t\t***************sample area end***************\r");
            bVar1 = *pbVar12;
          }
          else {
            bVar1 = *pbVar12;
          }
          if ((bVar1 & 2) == 0) {
            if (param_2 == 1) {
              iVar3 = *(int *)(pbVar12 + 4);
              goto LAB_0067236c;
            }
            puVar11 = *(undefined4 **)(pbVar12 + 0x160);
          }
          else {
            iVar3 = *(int *)(pbVar12 + 4);
LAB_0067236c:
            if (iVar3 == 1) {
              puVar7 = &DAT_00693fd0;
            }
            else {
              puVar7 = &DAT_00693fd4;
            }
            printf("\t\tfreq: %s \r\n",puVar7);
            printf("\t\tchannel: %u \r\n",(uint)pbVar12[8]);
            printf("\t\tbw mode: %u \r\n",(uint)*(ushort *)(pbVar12 + 10));
            printf("\t\ttx power: %u \r\n",(uint)*(ushort *)(pbVar12 + 0xc));
            printf("\t\tcapabilities: 0x%04x \r\n",(uint)*(ushort *)(pbVar12 + 0xe));
            printf("\t\tnf: %d \r\n",(int)(char)pbVar12[0x10]);
            printf("\t\tchannel load: %u%% \r\n",(uint)pbVar12[0x11]);
            printf("\t\tpacket rtx rate: %u%% \r\n",(uint)pbVar12[0x12]);
            printf("\t\tpacket loss rate: %u%% \r\n",(uint)pbVar12[0x13]);
            printf("\t\tupstream rate: %u Kbps\r\n",*(undefined4 *)(pbVar12 + 0x14));
            printf("\t\tdownstream rate: %u Kbps\r\n",*(undefined4 *)(pbVar12 + 0x18));
            printf("\t\tupstream load: %llu KBytes\r\n");
            printf("\t\tdownstream load: %llu KBytes\r\n");
            printf("\t\tchannel_interference: %d%% \r\n",(int)(char)pbVar12[0x30]);
            printf("\t\tchannel up load: %u%% \r\n",(uint)pbVar12[0x31]);
            printf("\t\tchannel down load: %u%% \r\n",(uint)pbVar12[0x32]);
            printf("\t\tweak signal station rate: %u%% \r\n",(uint)pbVar12[0x33]);
            printf("\t\tcloud_report_last_time:%llu\r\n");
            puts("\t\t***************sample area start***************\r");
            printf("\t\tsample_client_num: ");
            bVar2 = uVar4 != 0;
            iVar3 = 0;
            while (bVar2) {
              printf("%u ",(uint)pbVar12[iVar3 + 0x50]);
              bVar2 = iVar3 + 1 < (int)uVar4;
              iVar3 = iVar3 + 1;
            }
            puts(" \r");
            printf("\t\tsample_up_load_cumulate: %u KBytes\r\n",*(undefined4 *)(pbVar12 + 0x70));
            iVar3 = 0;
            printf("\t\tsample_down_load_cumulate: %u KBytes\r\n",*(undefined4 *)(pbVar12 + 0x74));
            printf("\t\tsample_up_rate: ");
            bVar2 = uVar4 != 0;
            pbVar13 = pbVar12;
            while (bVar2) {
              iVar3 = iVar3 + 1;
              printf("%u ",*(undefined4 *)(pbVar13 + 0x78));
              bVar2 = iVar3 < (int)uVar4;
              pbVar13 = pbVar13 + 4;
            }
            puts(" KBps\r");
            iVar3 = 0;
            printf("\t\tsample_down_rate: ");
            bVar2 = uVar4 != 0;
            pbVar13 = pbVar12;
            while (bVar2) {
              iVar3 = iVar3 + 1;
              printf("%u ",*(undefined4 *)(pbVar13 + 0xa0));
              bVar2 = iVar3 < (int)uVar4;
              pbVar13 = pbVar13 + 4;
            }
            puts(" KBps\r");
            iVar3 = 0;
            printf("\t\tsample_upstream_load: ");
            bVar2 = uVar4 != 0;
            pbVar13 = pbVar12;
            while (bVar2) {
              iVar3 = iVar3 + 1;
              printf("%u ",*(undefined4 *)(pbVar13 + 200));
              bVar2 = iVar3 < (int)uVar4;
              pbVar13 = pbVar13 + 4;
            }
            iVar3 = 0;
            puts(" KBytes\r");
            printf("\t\tsample_downstream_load: ");
            bVar2 = uVar4 != 0;
            pbVar13 = pbVar12;
            while (bVar2) {
              iVar3 = iVar3 + 1;
              printf("%u ",*(undefined4 *)(pbVar13 + 0xf0));
              bVar2 = iVar3 < (int)uVar4;
              pbVar13 = pbVar13 + 4;
            }
            puts(" KBytes\r");
            printf("\t\tsample_channel_load: ");
            bVar2 = uVar4 != 0;
            iVar3 = 0;
            while (bVar2) {
              printf("%u%% ",(uint)pbVar12[iVar3 + 0x118]);
              bVar2 = iVar3 + 1 < (int)uVar4;
              iVar3 = iVar3 + 1;
            }
            puts(" \r");
            printf("\t\tsample_channel_up_load: ");
            bVar2 = uVar4 != 0;
            iVar3 = 0;
            while (bVar2) {
              printf("%u%% ",(uint)pbVar12[iVar3 + 0x122]);
              bVar2 = iVar3 + 1 < (int)uVar4;
              iVar3 = iVar3 + 1;
            }
            puts(" \r");
            printf("\t\tsample_channel_down_load: ");
            for (iVar3 = 0; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
              printf("%u%% ",(uint)pbVar12[iVar3 + 300]);
            }
            puts(" \r");
            printf("\t\tsample_pkt_rtx_rate: ");
            for (iVar3 = 0; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
              printf("%u%% ",(uint)pbVar12[iVar3 + 0x136]);
            }
            puts(" \r");
            printf("\t\tsample_weak_signal_station_rate: ");
            for (iVar3 = 0; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
              printf("%u%% ",(uint)pbVar12[iVar3 + 0x14a]);
            }
            puts(" \r");
            printf("\t\tnoise_floor: ");
            for (iVar3 = 0; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
              printf("%u%% ",(int)(char)pbVar12[iVar3 + 0x154]);
            }
            puts(" \r");
            printf("\t\tsample_channel_interference: ");
            for (iVar3 = 0; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
              printf("%d%% ",(int)(char)pbVar12[iVar3 + 0x140]);
            }
            puts(" \r");
            puts("\t\t***************sample area done ***************\r");
            puVar11 = *(undefined4 **)(pbVar12 + 0x160);
          }
          if (puVar11 != (undefined4 *)0x0) {
            uVar4 = 1;
            while (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar4 <= uVar5) {
              uVar5 = 10;
              if (param_2 == 0) {
                uVar5 = (uint)*(byte *)(puVar11 + 0x12);
              }
              if (((*(byte *)(puVar11 + 2) & 1) == 0) && (param_2 != 1)) {
LAB_006720a0:
                uVar4 = uVar4 + 1;
                puVar11 = puVar11 + 0x40;
              }
              else {
                printf("\t\t\twlan id: %u\r\n",uVar4);
                if ((*(byte *)(puVar11 + 2) & 1) == 0) {
                  pcVar6 = "inactive";
                }
                else {
                  pcVar6 = "active";
                }
                if ((*(byte *)(puVar11 + 2) & 2) == 0) {
                  pcVar8 = "not-ready";
                }
                else {
                  pcVar8 = "ready";
                }
                printf("\t\t\t\tstate: %s, %s\r\n",pcVar6,pcVar8);
                printf("\t\t\t\texpiretime: %d \r\n",*puVar11);
                printf("\t\t\t\tsample_normal_last_time: %llu\r\n");
                printf("\t\t\t\tsample_normal_count: %d\r\n",(uint)*(byte *)(puVar11 + 0x12));
                printf("\t\t\t\tcloud_report_last_time: %llu\r\n");
                if ((*(byte *)(puVar11 + 2) & 2) == 0) {
                  if (param_2 != 1) goto LAB_006720a0;
                  bVar1 = *(byte *)(puVar11 + 3);
                }
                else {
                  bVar1 = *(byte *)(puVar11 + 3);
                }
                iVar3 = 0;
                printf("\t\t\t\tbssid: %02x:%02x:%02x:%02x:%02x:%02x \r\n",
                       (uint)*(byte *)((int)puVar11 + 9),(uint)*(byte *)((int)puVar11 + 10),
                       (uint)*(byte *)((int)puVar11 + 0xb),(uint)bVar1,
                       (uint)*(byte *)((int)puVar11 + 0xd),(uint)*(byte *)((int)puVar11 + 0xe));
                printf("\t\t\t\tcapabilities: 0x%04x \r\n",(uint)*(ushort *)(puVar11 + 4));
                printf("\t\t\t\tpacket rtx rate: %u%% \r\n",(uint)*(byte *)((int)puVar11 + 0x12));
                printf("\t\t\t\tpacket loss rate: %u%% \r\n",(uint)*(byte *)((int)puVar11 + 0x13));
                printf("\t\t\t\tupstream rate: %u Kbps\r\n",puVar11[5]);
                printf("\t\t\t\tdownstream rate: %u Kbps\r\n",puVar11[6]);
                printf("\t\t\t\tupstream load: %llu KBytes\r\n");
                printf("\t\t\t\tdownstream load: %llu KBytes\r\n");
                printf("\t\t\t\tlast_report_upstream_load: %llu KBytes\r\n");
                printf("\t\t\t\tlast_report_downstream_load: %llu KBytes\r\n");
                printf("\t\t\t\tsample_upstream_rate:");
                bVar2 = uVar5 != 0;
                puVar15 = puVar11;
                while (bVar2) {
                  iVar3 = iVar3 + 1;
                  printf("%u Kbps ",puVar15[0x18]);
                  bVar2 = iVar3 < (int)uVar5;
                  puVar15 = puVar15 + 1;
                }
                iVar3 = 0;
                puts(" \r");
                printf("\t\t\t\tsample_downstream_rate:");
                bVar2 = uVar5 != 0;
                puVar15 = puVar11;
                while (bVar2) {
                  iVar3 = iVar3 + 1;
                  printf("%u Kbps ",puVar15[0x22]);
                  bVar2 = iVar3 < (int)uVar5;
                  puVar15 = puVar15 + 1;
                }
                puts(" \r");
                iVar3 = 0;
                printf("\t\t\t\tsample_upstream_load:");
                bVar2 = uVar5 != 0;
                puVar15 = puVar11;
                while (bVar2) {
                  iVar3 = iVar3 + 1;
                  printf("%u KBytes ",puVar15[0x2c]);
                  bVar2 = iVar3 < (int)uVar5;
                  puVar15 = puVar15 + 1;
                }
                puts(" \r");
                iVar3 = 0;
                printf("\t\t\t\tsample_downstream_load:");
                bVar2 = uVar5 != 0;
                puVar15 = puVar11;
                while (bVar2) {
                  iVar3 = iVar3 + 1;
                  printf("%u KBytes ",puVar15[0x36]);
                  bVar2 = iVar3 < (int)uVar5;
                  puVar15 = puVar15 + 1;
                }
                puts(" \r");
                uVar4 = uVar4 + 1;
                puVar11 = puVar11 + 0x40;
              }
            }
          }
        }
LAB_00672354:
        local_30 = local_30 + 1;
        local_2c = local_2c + 8;
      } while( true );
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","_stats_db_print_ap_by_id",0x1476,param_1
          );
    return;
  }
  return;
}

