// func _apmngr_db_sqlite_thread_main @ 0054739c size=720

void _apmngr_db_sqlite_thread_main(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0051ad88(&local_38);
  do {
    FUN_004082d0(apmngr_msg_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_apmngr_msg_list), iVar1 == 0) {
      FUN_004086c0(apmngr_msg_cond,apmngr_msg_mutex,0xffffffff);
    }
    FUN_004082c0(&local_38,&g_apmngr_msg_list);
    FUN_00407f30(apmngr_msg_mutex);
    while (iVar1 = FUN_004081b0(&local_38), iVar1 != 0) {
      FUN_00408500(iVar1);
      iVar2 = _apmngr_sql_op_change_option(iVar1);
      if (iVar2 == 1) {
        FUN_004082d0(apmngr_msg_mutex,0xffffffff);
        g_apmngr_sql_option_changed_node_num = g_apmngr_sql_option_changed_node_num + -1;
        FUN_00407f30(apmngr_msg_mutex);
        uVar3 = *(uint *)(iVar1 + 0xc);
      }
      else {
        uVar3 = *(uint *)(iVar1 + 0xc);
      }
      if (uVar3 < 0x1b) {
        puVar4 = *(undefined2 **)(iVar1 + 0x10);
        switch(uVar3) {
        case 0:
          _apmngr_db_sqlite_ap_insert();
          break;
        case 1:
          _apmngr_db_sqlite_template_insert();
          break;
        case 2:
          _apmngr_db_sqlite_ap_firm();
          break;
        case 3:
          _apmngr_db_sqlite_ap_update();
          break;
        case 4:
          _apmngr_db_sqlite_ap_hwver_update();
          break;
        case 5:
          _apmngr_db_sqlite_ap_capid_update();
          break;
        case 6:
          _apmngr_db_sqlite_ap_re_cloud_config_id_update();
          break;
        case 7:
          _apmngr_db_sqlite_ap_role_update();
          break;
        case 8:
          _apmngr_db_sqlite_template_hwver_update();
          break;
        case 9:
          _apmngr_db_sqlite_ap_hwver_and_model_update();
          break;
        case 10:
          _apmngr_db_sqlite_ap_software_update();
          break;
        case 0xb:
          _apmngr_db_sqlite_ap_led_update();
          break;
        case 0xc:
          _apmngr_db_sqlite_set_errno();
          break;
        case 0xd:
          _apmngr_db_sqlite_ap_run_state_update();
          break;
        case 0xe:
          _apmngr_db_sqlite_ap_tmp_delete(*puVar4);
          break;
        case 0xf:
          _apmngr_db_sqlite_ap_delete(*puVar4);
          break;
        case 0x10:
          _apmngr_db_sqlite_template_delete(*puVar4);
          break;
        case 0x11:
          _apmngr_db_sqlite_hdap_insert();
          break;
        case 0x12:
          _apmngr_db_sqlite_ap_cur_lag_config_update();
          break;
        case 0x13:
          _apmngr_db_sqlite_bluetooth_enable_update();
        case 0x16:
          _apmngr_db_sqlite_ap_cur_using_rrst_idx_update(*(undefined4 *)(iVar1 + 0x10));
          break;
        case 0x14:
          _apmngr_db_sqlite_ap_telnet_update();
          break;
        case 0x15:
          _apmngr_db_sqlite_fit_fat_button_update();
          break;
        case 0x17:
          _apmngr_db_sqlite_ap_cur_using_region_code_update();
          break;
        case 0x18:
          _apmngr_db_sqlite_ap_cur_firmware_id_update();
          break;
        case 0x19:
          _apmngr_db_sqlite_ap_mesh_switch_update();
          break;
        case 0x1a:
          _apmngr_db_sqlite_ssid_mlo_support_update();
        }
      }
      FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
      FUN_00407df0(iVar1);
    }
  } while( true );
}

