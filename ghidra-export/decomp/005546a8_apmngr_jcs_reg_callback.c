// func apmngr_jcs_reg_callback @ 005546a8 size=872

uint apmngr_jcs_reg_callback(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  int iVar29;
  
  uVar1 = FUN_004084d0("apmngr_global",2,_apmngr_jcs_global_set);
  uVar2 = FUN_004084d0("apmngr_aplog",2,_apmngr_jcs_aplog_set);
  uVar3 = FUN_004084d0("diagnose_global",2,_apmngr_jcs_diagnose_global_set);
  uVar4 = FUN_004084d0("apmngr_apdb_info",3,_apmngr_jcs_apdb_info_get);
  uVar5 = FUN_004084d0("apmngr_entry",0,_apmngr_jcs_entry_add);
  uVar6 = FUN_004084d0("apmngr_entry",2,_apmngr_jcs_entry_set);
  uVar7 = FUN_004084d0("apmngr_entry",1,_apmngr_jcs_entry_del);
  uVar8 = FUN_004084d0("apmngr_entry_backup",3,_apmngr_jcs_entry_backup);
  uVar9 = FUN_004084d0("apmngr_entry_copy",2,_apmngr_jcs_entry_copy);
  uVar10 = FUN_004084d0("apmngr_entry_authorize",2,_apmngr_jcs_entry_set_authorize);
  uVar11 = FUN_004084d0("apmngr_entry_authorize",3,_apmngr_jcs_entry_authorize_get);
  uVar12 = FUN_004084d0("apmngr_group_join",2,_apmngr_jcs_group_join);
  uVar13 = FUN_004084d0("apmngr_firm",2,_apmngr_jcs_firm);
  uVar14 = FUN_004084d0("ap_status",3,_apmngr_jcs_ap_status);
  uVar15 = FUN_004084d0("apmngr_online_model",3,_apmngr_jcs_online_ap_model_get);
  uVar16 = FUN_004084d0("ap_status_evt",2,_apmngr_jcs_ap_evt);
  uVar17 = FUN_004084d0("ap_telnet_status_evt",2,_apmngr_jcs_ap_telnet_evt);
  uVar18 = FUN_004084d0("ap_status_ssid",3,_apmngr_jcs_ssid);
  uVar19 = FUN_004084d0("ap_vlan_info",3,_apmngr_jcs_ap_vlan);
  uVar20 = FUN_004084d0("ap_status_radio_info",3,_apmngr_jcs_ap_radio_info);
  uVar21 = FUN_004084d0("apmngr_group",0,_apmngr_jcs_group_add);
  uVar22 = FUN_004084d0("apmngr_group",2,_apmngr_jcs_group_set);
  uVar23 = FUN_004084d0("apmngr_group",1,_apmngr_jcs_group_del);
  uVar24 = FUN_004084d0("ap_exceed_status",3,_apmngr_jcs_ap_exceed_status);
  uVar25 = FUN_004084d0("ac_datasync_status",2,_apmngr_jcs_ac_datasync_status_set);
  uVar26 = FUN_004084d0("ac_notify_master_sync_data",2,_apmngr_jcs_ac_nitify_master_sync_data_set);
  uVar27 = FUN_004084d0("ac_clear_all_cloud_config_id",2,_apmngr_jcs_ac_clear_all_cloud_config_id);
  uVar28 = FUN_004084d0("apmngr_datasync",2,_apmngr_jcs_callback_datasync);
  uVar28 = uVar2 | uVar1 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
           uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 |
           uVar22 | uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28;
  if (((uVar28 != 0) && (apmngr_err_switch != '\0')) && (iVar29 = is_target_debug_ap(), iVar29 != 0)
     ) {
    printf("[APMNGR_ERROR]%s()/%d Failed to register callback to jcs.\n","apmngr_jcs_reg_callback",
           0xc3c);
  }
  return uVar28;
}

