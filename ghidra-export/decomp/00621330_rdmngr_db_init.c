// func rdmngr_db_init @ 00621330 size=2324

/* WARNING: Removing unreachable block (ram,0x006215d4) */

undefined4 rdmngr_db_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *__format;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  int local_cd8;
  int local_cd4;
  undefined1 auStack_cd0 [4];
  undefined1 auStack_ccc [36];
  char acStack_ca8 [128];
  char acStack_c28 [1536];
  char acStack_628 [1540];
  
  local_cd4 = 0;
  memset(acStack_628,0,0x600);
  if (g_rdmngr_data != 0) {
    return 0;
  }
  DAT_007cc64c = FUN_00407f00("rdmngr_mutex",1);
  if (DAT_007cc64c == 0) {
    if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00621978;
    pcVar7 = "[RDMNGR_ERROR]%s()/%d Create rdmngr data mutex failed.\n";
    uVar11 = 0x1287;
  }
  else {
    iVar1 = FUN_0051eb48("radio_mngr","max_wlan_per_radio",&g_rdmngr_profile);
    if (iVar1 == -1) {
      if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
        g_rdmngr_profile = 8;
      }
      else {
        printf("[RDMNGR_ERROR]%s()/%d get profile[radio_mngr->max_wlan_per_radio] fail.\n",
               "rdmngr_db_init",0x128e);
        g_rdmngr_profile = 8;
      }
    }
    iVar1 = FUN_0051eb48("radio_mngr","max_radio_per_ap",&DAT_007cc65c);
    if (iVar1 == -1) {
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d get profile[radio_mngr->max_radio_per_ap] fail.\n",
               "rdmngr_db_init",0x1295);
      }
      DAT_007cc65c = 8;
    }
    if (6 < DAT_007cc65c - 2U) {
      if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00621978;
      pcVar7 = (char *)0x2;
      __format = 
      "[RDMNGR_ERROR]%s()/%d Illegal radio_mngr->max_radio_per_ap[%d],need to be %d-%d.\n";
      pcVar12 = (char *)0x8;
      uVar11 = 0x129a;
      iVar1 = DAT_007cc65c;
LAB_0062196c:
      printf(__format,"rdmngr_db_init",uVar11,iVar1,pcVar7,pcVar12);
      goto LAB_00621978;
    }
    DAT_007cc660 = 0;
    memcpy(auStack_ccc,&DAT_0070a7a4,0x24);
    iVar1 = FUN_00408120("apmng_rf","rf_entry_capability",auStack_ccc,1);
    if (iVar1 != 0) {
      uVar11 = 0xffffffff;
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "[RDMNGR_ERROR]%s()/%d uci req parse failed.\n";
      uVar10 = 0x12a6;
LAB_00621498:
      printf(pcVar7,"rdmngr_db_init",uVar10);
      return uVar11;
    }
    iVar1 = FUN_0051eb48("apmng_rf","cfg_dft_mngt_frame_2g_rate",&g_cfg_dft_mngt_frame_2g_rate);
    if (iVar1 == -1) {
      uVar11 = 0xffffffff;
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "[RDMNGR_ERROR]%s()/%d get profile[g_cfg_dft_mngt_frame_2g_rate] failed.\n";
      uVar10 = 0x12ac;
      goto LAB_00621498;
    }
    iVar2 = FUN_0051eb48("apmng_rf","cfg_dft_mngt_frame_5g_rate",&g_cfg_dft_mngt_frame_5g_rate);
    iVar1 = DAT_007cc65c;
    if (iVar2 == -1) {
      uVar11 = 0xffffffff;
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "[RDMNGR_ERROR]%s()/%d get profile[g_cfg_dft_mngt_frame_5g_rate] failed.\n";
      uVar10 = 0x12b2;
      goto LAB_00621498;
    }
    DAT_007598ec = &rcInf;
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    DAT_007cc650 = FUN_004082a0((iVar2 + iVar3 + iVar4) * iVar1,8,0x12ba);
    if (DAT_007cc650 == 0) {
      if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00621978;
      pcVar7 = "[RDMNGR_ERROR]%s()/%d Not enough memory\n";
      uVar11 = 0x12bd;
    }
    else {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar3 = apmngr_db_get_sensor_max();
      DAT_007cc654 = FUN_004082a0((iVar1 + iVar2 + iVar3) * 2,0x54,0x12c1);
      iVar1 = 0;
      if (DAT_007cc654 == 0) {
        if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
        goto LAB_00621978;
        pcVar7 = "[RDMNGR_ERROR]%s()/%d Not enough memory\n";
        uVar11 = 0x12c4;
      }
      else {
        while( true ) {
          iVar2 = apmngr_db_get_ap_max();
          iVar3 = apmngr_db_get_template_max();
          iVar4 = apmngr_db_get_sensor_max();
          if ((iVar2 + iVar3 + iVar4) * 2 <= iVar1) break;
          iVar2 = iVar1 / 2;
          puVar5 = (undefined4 *)(DAT_007cc654 + iVar1 * 0x54);
          *puVar5 = 0xffffffff;
          iVar3 = iVar1 % 2;
          iVar1 = iVar1 + 1;
          puVar8 = (undefined4 *)(DAT_007cc650 + (iVar2 * DAT_007cc65c + iVar3) * 8);
          *puVar8 = 1;
          puVar8[1] = puVar5;
        }
        memset(acStack_c28,0,0x600);
        snprintf(acStack_c28,0x600,
                 "CREATE TABLE IF NOT EXISTS %s(rf_id\tINTEGER,rf_name\tINTEGER,freq_band INTEGER,mode INTEGER,bandwidth INTEGER,channel INTEGER,power_level INTEGER,max_usr INTEGER,antenna INTEGER,frag_thr INTEGER,bcn_intvl INTEGER,manage_frame_rate INTEGER,rts_thr INTEGER,dtim_prd INTEGER,wmm VARCHAR(4),brd_probe VARCHAR(4),short_gi VARCHAR(4),rssi_restrict VARCHAR(4),rssi_restrict_val INTEGER,rssi_kick VARCHAR(4),rssi_kick_val INTEGER,chLock INTEGER,pwrLock INTEGER,scanMode INTEGER,scanType INTEGER,scanIntvl INTEGER,rf_state VARCHAR(4),airtime VARCHAR(4),rf_chnl_dcs INTEGER,rf_chnl_reselect INTEGER,rf_online_switch VARCHAR(4),rf_check_circle INTEGER,rf_chnl_occup_threshold INTEGER,rf_chnl_tolerance INTEGER,chErrFrameRatio INTEGER,reject_limit INTEGER,reject_enable VARCHAR(4),reject_diff INTEGER,downlink_mumimo VARCHAR(4),uplink_mumimo VARCHAR(4),downlink_ofdma VARCHAR(4),uplink_ofdma VARCHAR(4),twt VARCHAR(4),gi_mode INTEGER,enable_6g VARCHAR(4),enable_6g_psc VARCHAR(4),key\t\t\t\tINTEGER PRIMARY KEY AUTOINCREMENT)"
                 ,"rdmngrTable");
        local_cd8 = 0;
        memset(acStack_ca8,0,0x80);
        iVar1 = FUN_00408130("/etc/nouci_config/dbs/rdmngr.db",&local_cd8,
                             uac_cfg_trigger_changed_by_restore);
        if (iVar1 == 0) {
          iVar1 = FUN_00407d60(local_cd8,acStack_c28);
          if (iVar1 == 0) {
            snprintf(acStack_ca8,0x80,"CREATE INDEX %s_%s ON %s(%s)","rdmngrTable","rf_id",
                     "rdmngrTable","rf_id");
            FUN_00408530(local_cd8,acStack_ca8);
          }
          else {
            iVar2 = FUN_00408410();
            if (iVar2 != 0) {
              printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"create table %s failed.\"\n"
                     ,"create_table",0x196,iVar1,acStack_c28,"rdmngrTable");
            }
          }
        }
        if (local_cd8 != 0) {
          FUN_004080b0();
        }
        if (((iVar1 != 0) && (rdmngr_err_switch != 0)) &&
           (iVar1 = is_target_debug_ap("/etc/nouci_config/dbs/rdmngr.db"), iVar1 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d Create table %s failed.\n","rdmngr_db_sqlite_create_table",
                 0x1e9,"rdmngrTable");
        }
        iVar2 = FUN_00408130("/etc/nouci_config/dbs/rdmngr.db",&local_cd4,
                             uac_cfg_trigger_changed_by_restore);
        iVar1 = DAT_007cc65c;
        if (iVar2 != 0) goto LAB_00621978;
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar4 = apmngr_db_get_sensor_max();
        pcVar7 = acStack_628;
        FUN_00408300(&g_invalid_radioId,&g_invalid_radioId_pos,(iVar2 + iVar3 + iVar4) * iVar1);
        snprintf(pcVar7,0x600,"select * from %s","rdmngrTable");
        iVar1 = FUN_00407fb0(local_cd4,pcVar7,rdmngr_db_sqlite_cb,DAT_007cc650);
        if (iVar1 != 0) {
          iVar2 = FUN_00408410();
          if (iVar2 == 0) goto LAB_00621978;
          pcVar12 = "Failed to read database, select failed.";
          __format = "[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n";
          uVar11 = 0x12d9;
          goto LAB_0062196c;
        }
        iVar1 = FUN_00408490(g_invalid_radioId,g_invalid_radioId_pos,local_cd4,"rdmngrTable","rf_id"
                            );
        if (0 < g_invalid_radioId_pos) {
          FUN_00408400();
        }
        if (iVar1 == 0) {
          FUN_00407de0(&g_invalid_radioId,&g_invalid_radioId_pos);
          if (local_cd4 != 0) {
            FUN_004080b0();
            local_cd4 = 0;
          }
          iVar1 = DAT_007cc65c;
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar6 = apmngr_db_get_sensor_max();
          iVar2 = DAT_007cc65c;
          iVar9 = 30000;
          if ((uint)((iVar3 + iVar4 + iVar6) * iVar1) < 0x7531) {
            iVar1 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            iVar4 = apmngr_db_get_sensor_max();
            iVar9 = (iVar1 + iVar3 + iVar4) * iVar2;
          }
          g_rdmngr_msgq = FUN_00408460("/rdmngr_msgq",iVar9,8,4);
          if (g_rdmngr_msgq == -1) {
            uVar11 = 0xffffffff;
            if (rdmngr_err_switch == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            pcVar7 = "[RDMNGR_ERROR]%s()/%d Create rdmngr msgQ failed.\n";
            uVar10 = 0x12ee;
          }
          else {
            iVar1 = FUN_004084e0(auStack_cd0,"rdmngr_task",rdmgnr_db_work_task,0);
            if (iVar1 == 0) {
              g_rdmngr_data = 1;
              uVar11 = 0;
              FUN_00408620("/etc/nouci_config/dbs/rdmngr.db",rdmngr_get_msgq_len);
              if (rdmngr_debug_switch == 0) {
                return 0;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0;
              }
              pcVar7 = "[RDMNGR_DEBUG]%s()/%d rdmngr_db_init() OK.\n";
              uVar10 = 0x12ff;
            }
            else {
              uVar11 = 0xffffffff;
              if (rdmngr_err_switch == 0) {
                return 0xffffffff;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0xffffffff;
              }
              pcVar7 = "[RDMNGR_ERROR]%s()/%d Create rdmngr thread failed.\n";
              uVar10 = 0x12f4;
            }
          }
          goto LAB_00621498;
        }
        if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
        goto LAB_00621978;
        pcVar7 = "[RDMNGR_ERROR]%s()/%d Create rdmngr msgQ failed.\n";
        uVar11 = 0x12e2;
      }
    }
  }
  printf(pcVar7,"rdmngr_db_init",uVar11);
LAB_00621978:
  FUN_00407de0(&g_invalid_radioId,&g_invalid_radioId_pos);
  g_rdmngr_data = 0;
  if (local_cd4 != 0) {
    FUN_004080b0();
    local_cd4 = 0;
  }
  rdmngr_db_uninit();
  return 0xffffffff;
}

