// func _rrm_task @ 004aef30 size=2140

void _rrm_task(void)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  int local_44;
  undefined4 local_40;
  code *local_3c;
  int local_30;
  int local_2c;
  
LAB_004aef68:
  while( true ) {
    FUN_004082e0(rrm_signal,0xffffffff);
    iVar1 = rrm_db_state_get();
    if (iVar1 == 2) break;
    if (iVar1 != 5) goto code_r0x004aef94;
    if (rrm_info_dump_switch != 0) {
      rrm_info_dump();
    }
    if (rrm_debug_switch != '\0') {
      printf("[RRM_DEBUG]%s()/%d start pwr rrm calculate\n","_rrm_task",0x80c);
    }
    rrm_db_state_set(6);
    piVar12 = &ap_pwr_para;
    iVar1 = 0;
    local_30 = 1;
    do {
      piVar10 = (int *)*piVar12;
      iVar8 = *piVar10;
      if (0 < iVar8) {
        if (piVar10[1] < (iVar8 + 1) / 2) {
          rrm_pwr_failed = 1;
          break;
        }
        local_3c = rrm_adjust_cur_pwr;
        local_44 = rrm_pwr_tpc_neigh_size;
        local_40 = pwr_rrm_max_change_power;
        iVar8 = run_TPC(piVar10[6],iVar8,piVar10 + 8,(int)high_threshold,(int)low_threshold);
        if ((0 < iVar8) && (local_30 = 0, rrm_pwr_smooth_tpc_switch != 0)) {
          puVar11 = (undefined4 *)*piVar12;
          local_3c = rrm_adjust_cur_pwr;
          local_44 = rrm_pwr_tpc_neigh_size;
          local_40 = pwr_rrm_max_change_power;
          run_smooth_TPC(puVar11[6],puVar11[5],*puVar11,puVar11 + 8,(int)high_threshold);
        }
        if (rrm_info_dump_switch != 0) {
          if (iVar1 == 0) {
            iVar8 = 1;
            puVar9 = &DAT_00693fd4;
          }
          else {
            puVar9 = &DAT_00693fd0;
            iVar8 = iVar1;
          }
          printf("*****radio(%s%d)\'s rrm(power) result:******\n",puVar9,iVar8);
          for (iVar8 = 0; iVar8 < *(int *)*piVar12; iVar8 = iVar8 + 1) {
            printf("apid:%d\n",(uint)*(ushort *)(((int *)*piVar12)[6] + iVar8 * 0x12));
            local_2c = iVar8 * 0xf;
            iVar6 = *piVar12;
            for (iVar13 = 0; iVar3 = *(int *)(iVar6 + 0x18) + iVar8 * 0x12,
                iVar13 < (int)(uint)*(byte *)(iVar3 + 2); iVar13 = iVar13 + 1) {
              printf("\tradio:%d, curPwr:%d\n",
                     (uint)*(byte *)(*(int *)(iVar6 + 0x1c) + local_2c + iVar13),
                     (uint)*(byte *)(iVar3 + iVar13 + 3));
              iVar6 = *piVar12;
            }
          }
          puts("*************************************");
        }
      }
      iVar1 = iVar1 + 1;
      piVar12 = piVar12 + 1;
    } while (iVar1 != 3);
    if (((rrm_pwr_failed != 0) || (local_30 != 0)) || (pwr_rrm_max_count <= pwr_rrm_count)) {
      pwr_rrm_count = 0;
      rrm_set_to_all_ap();
      if (rrm_pwr_failed == 0) {
        uVar4 = 0x3976;
        uVar7 = 0x397c;
      }
      else {
        uVar4 = 0x3977;
        uVar7 = 0x397d;
      }
      if (rrm_type != 1) {
        uVar4 = uVar7;
      }
      loggerk_reg(0x55,uVar4,0);
      goto LAB_004aefb4;
    }
    rrm_reset_ap_pwr_para_all();
    iVar1 = pwr_rrm_start(0);
    if (iVar1 != 0) {
      pwr_rrm_count = 0;
      rrm_pwr_failed = 1;
      uVar4 = 0x3977;
      if (rrm_type != 1) {
        uVar4 = 0x397d;
      }
      loggerk_reg(0x55,uVar4,0);
      goto LAB_004af448;
    }
    pwr_rrm_count = pwr_rrm_count + 1;
  }
  if (rrm_info_dump_switch != 0) {
    rrm_info_dump();
  }
  if (rrm_debug_switch != '\0') {
    printf("[RRM_DEBUG]%s()/%d start channel rrm calculate\n","_rrm_task",0x7af);
  }
  piVar12 = &ap_para;
  iVar1 = 0;
  rrm_db_state_set(3);
  do {
    iVar8 = *(int *)*piVar12;
    if (0 < iVar8) {
      if (((int *)*piVar12)[1] < (iVar8 + 1) / 2) {
        rrm_chnl_failed = 1;
        break;
      }
      if ((iVar1 == 1) && (0 < *DAT_00767c00)) {
        if (rrm_debug_switch != '\0') {
          printf("[RRM_DEBUG]%s()/%d start RRM_RADIO_5G2 DCA before RRM_RADIO_5G DCA\n","_rrm_task",
                 0x7ba);
        }
        local_44 = DAT_00767c00[9];
        run_DCA(DAT_00767c00[6],*DAT_00767c00,6,
                (&rrm_channel_list)[(uint)*(byte *)(DAT_00767c00 + 4) * 5],DAT_00767c00[8]);
        if (rrm_info_dump_switch != 0) {
          puts("*****radio(5G2)\'s rrm(channel) result:******");
          for (iVar8 = 0; iVar8 < *DAT_00767c00; iVar8 = iVar8 + 1) {
            iVar13 = iVar8 * 0x2a;
            printf("apid:%d total itf:%d\n",(uint)*(ushort *)(DAT_00767c00[6] + iVar13),
                   (int)(short)((ushort *)(DAT_00767c00[6] + iVar13))[5]);
            local_30 = iVar8 * 0xf;
            for (iVar6 = 0; iVar6 < (int)(uint)*(byte *)(*(int *)(DAT_00767bfc + 0x18) + iVar13 + 2)
                ; iVar6 = iVar6 + 1) {
              printf("\tradio:%d, channel:%d, interfer:%d\n",
                     (uint)*(byte *)(DAT_00767c00[7] + local_30 + iVar6),
                     (int)*(char *)(DAT_00767c00[6] + iVar13 + iVar6 + 3),
                     (uint)*(ushort *)(DAT_00767c00[6] + iVar13 + (iVar6 + 4) * 2 + 4));
            }
          }
          puts("*************************************");
        }
        if (rrm_debug_switch != '\0') {
          printf("[RRM_DEBUG]%s()/%d before rrm_add_co_chnl_itf\n","_rrm_task",0x7c9);
        }
        rrm_ap_para_dump(1,1);
        for (uVar5 = 0; uVar5 < 5; uVar5 = uVar5 + 1) {
          *(undefined1 *)((int)&local_44 + uVar5) = (&DAT_00767bd5)[uVar5];
        }
        local_3c = (code *)0x3;
        rrm_add_co_chnl_itf(&ap_para,2,DAT_00767bd8 << 0x10 | DAT_00767bdc >> 0x10,
                            (DAT_00767bdc >> 8) << 0x18,1);
        if (rrm_debug_switch != '\0') {
          printf("[RRM_DEBUG]%s()/%d after rrm_add_co_chnl_itf\n","_rrm_task",0x7cc);
        }
        rrm_ap_para_dump(1,1);
        puVar11 = (undefined4 *)*piVar12;
      }
      else {
        puVar11 = (undefined4 *)*piVar12;
      }
      local_44 = puVar11[9];
      run_DCA(puVar11[6],*puVar11,6,(&rrm_channel_list)[(uint)*(byte *)(puVar11 + 4) * 5],puVar11[8]
             );
      if (rrm_info_dump_switch != 0) {
        if (iVar1 == 0) {
          puVar9 = &DAT_00693fd4;
        }
        else {
          puVar9 = &DAT_00693fd0;
        }
        printf("*****radio(%s%d)\'s rrm(channel) result:******\n",puVar9,1);
        for (iVar8 = 0; iVar8 < *(int *)*piVar12; iVar8 = iVar8 + 1) {
          puVar2 = (ushort *)(((int *)*piVar12)[6] + iVar8 * 0x2a);
          printf("apid:%d total itf:%d\n",(uint)*puVar2,(int)(short)puVar2[5]);
          local_30 = iVar8 * 0xf;
          iVar6 = *piVar12;
          for (iVar13 = 0; iVar3 = *(int *)(iVar6 + 0x18) + iVar8 * 0x2a,
              iVar13 < (int)(uint)*(byte *)(iVar3 + 2); iVar13 = iVar13 + 1) {
            printf("\tradio:%d, channel:%d, interfer:%d\n",
                   (uint)*(byte *)(*(int *)(iVar6 + 0x1c) + local_30 + iVar13),
                   (int)*(char *)(iVar3 + iVar13 + 3),
                   (uint)*(ushort *)(iVar3 + (iVar13 + 4) * 2 + 4));
            iVar6 = *piVar12;
          }
        }
        puts("*************************************");
      }
    }
    iVar1 = iVar1 + 1;
    piVar12 = piVar12 + 1;
  } while (iVar1 != 2);
  if (rrm_chnl_failed == 0) {
    uVar4 = 0x3973;
    uVar7 = 0x3979;
  }
  else {
    uVar4 = 0x3974;
    uVar7 = 0x397a;
  }
  if (rrm_type != 1) {
    uVar4 = uVar7;
  }
  loggerk_reg(0x55,uVar4,0);
  if (g_pwr_enable != 0) {
    iVar1 = pwr_rrm_start(1);
    if (iVar1 != 0) {
      pwr_rrm_count = 0;
      rrm_channel_set_to_all_ap();
      goto LAB_004aefb4;
    }
    pwr_rrm_count = pwr_rrm_count + 1;
    uVar4 = 0x3975;
    if (rrm_type != 1) {
      uVar4 = 0x397b;
    }
    loggerk_reg(0x55,uVar4,0);
    goto LAB_004aef68;
  }
LAB_004af448:
  rrm_set_to_all_ap();
  goto LAB_004aefb4;
code_r0x004aef94:
  if (iVar1 != 8) goto LAB_004aef68;
  rdmngr_callback_proc(3,0xffffffff,0,0);
LAB_004aefb4:
  rrm_destroy_ap_para_all();
  rrm_destroy_ap_pwr_para_all();
  rrm_type = 0;
  rrm_chnl_failed = 0;
  rrm_pwr_failed = 0;
  rrm_db_state_set(7);
  rrm_callback_proc(1);
  goto LAB_004aef68;
}

