// func sensor_mngt_global_dump @ 004e95f8 size=1

void sensor_mngt_global_dump(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *apcStack_50 [10];
  
  apcStack_50[0] = "Idle";
  apcStack_50[1] = "Testing";
  apcStack_50[2] = "Finished";
  memcpy(apcStack_50 + 3,&PTR_DAT_006b1e28,0x18);
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (g_sensor_enable == 0) {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  printf("g_sensor_enable:\t%s\n",pcVar6 + 4);
  if (g_sensor_state < 4) {
    pcVar6 = (&PTR_DAT_006b2110)[g_sensor_state];
  }
  else {
    pcVar6 = "unknown";
  }
  printf("g_sensor_state:\t%s\n",pcVar6);
  printf("g_dft_backhaul_wserv_id:\t%d\n",g_dft_backhaul_wserv_id);
  printf("g_backhaul_wserv_id:\t%d\n",g_backhaul_wserv_id);
  printf("unfinished_sensor_num_first/unfinished_sensor_num:\t%d/%d\n",unfinished_sensor_num_first,
         unfinished_sensor_num);
  if ((0 < unfinished_sensor_num) && (unfinished_sensor_list != 0)) {
    iVar9 = 0;
    puts("unfinished_sensor_ids:\t");
code_r0x004e9740:
    do {
      if (unfinished_sensor_num_first <= iVar9) break;
      iVar10 = iVar9 * 0x30;
      uVar7 = (uint)*(ushort *)(unfinished_sensor_list + iVar10);
      if (uVar7 != 0xffff) {
        uVar1 = *(uint *)((ushort *)(unfinished_sensor_list + iVar10) + 2);
        pcVar6 = "Unknown";
        if (uVar1 < 6) {
          pcVar6 = apcStack_50[uVar1 + 3];
        }
        printf("%d:\t%s(%u)\n",uVar7,pcVar6,
               *(undefined4 *)(current_backhaul_test_operation_id + iVar9 * 4));
        iVar8 = 0;
        if (*(int *)(unfinished_sensor_list + iVar10 + 4) == 2) {
          while (iVar4 = unfinished_sensor_list + iVar10, iVar8 < *(int *)(iVar4 + 8)) {
            iVar5 = iVar8 + 1;
            iVar2 = iVar8 * 0xc;
            iVar8 = iVar8 + 1;
            iVar2 = iVar4 + iVar2;
            puVar3 = &UNK_006b1888;
            if (*(int *)(iVar2 + 0x14) == 0) {
              puVar3 = &DAT_006b1890;
            }
            printf("\t[%02x:%02x:%02x:%02x:%02x:%02x]:%s\n",(uint)*(byte *)(iVar2 + 0xc),
                   (uint)*(byte *)(iVar2 + 0xd),(uint)*(byte *)(iVar2 + 0xe),
                   (uint)*(byte *)(iVar2 + 0xf),(uint)*(byte *)(iVar4 + iVar5 * 0xc + 4),
                   (uint)*(byte *)(iVar2 + 0x11),puVar3);
          }
          iVar9 = iVar9 + 1;
          goto code_r0x004e9740;
        }
      }
      iVar9 = iVar9 + 1;
    } while( true );
  }
  if (g_sensor_backhaul_test_state < 3) {
    pcVar6 = apcStack_50[g_sensor_backhaul_test_state];
  }
  else {
    pcVar6 = "Unknown";
  }
  printf("g_sensor_backhaul_test_state:%s\n",pcVar6);
  printf("backhaul_test_finished_sensor_num:%d\n",backhaul_test_finished_sensor_num);
  printf("backhaul_test_suc_sensor_num:%d\n\n",backhaul_test_suc_sensor_num);
  printf("g_change_backhaul_wserv:%d\n",g_change_backhaul_wserv);
  if (g_change_backhaul_wserv != 0) {
    printf("wserv setting sensor_ids(%d/%d):\t\n",sensor_backhaul_set_finished,
           sensor_backhaul_set_total);
    for (iVar9 = 0; iVar10 = apmngr_db_get_sensor_max(), iVar9 < iVar10; iVar9 = iVar9 + 1) {
      if (*(char *)(sensor_backhaul_set_id_map + iVar9) != -1) {
        pcVar6 = "Finished";
        if (*(char *)(sensor_backhaul_set_id_map + iVar9) == '\0') {
          pcVar6 = "Wait Resp";
        }
        printf("\t%d:%s(%d)\n",iVar9 + 50000,pcVar6,
               *(undefined4 *)(sensor_backhaul_set_pkt_id_list + iVar9 * 4));
      }
    }
  }
  uac_mutex_give(g_sensor_mngt_mutex);
  return;
}

