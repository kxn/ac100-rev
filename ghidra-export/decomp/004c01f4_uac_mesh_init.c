// func uac_mesh_init @ 004c01f4 size=1028

undefined4 uac_mesh_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_a8 [4];
  undefined *local_a4;
  undefined4 local_a0;
  code *local_9c;
  undefined4 local_98;
  undefined1 auStack_94 [12];
  undefined *local_88;
  code *local_84;
  code *local_80;
  undefined4 local_60;
  undefined1 auStack_5c [12];
  undefined *local_50;
  undefined4 local_4c;
  code *local_48;
  code *local_44;
  code *local_3c;
  code *local_2c;
  code *local_24;
  code *local_20;
  
  memset(auStack_5c,0,0x4c);
  local_a4 = (undefined *)0x0;
  local_a0 = 0;
  local_9c = (code *)0x0;
  local_98 = 0;
  memset(auStack_94,0,0x38);
  mesh_signal = FUN_004085e0("ac_mesh",0);
  if (mesh_signal == 0) {
    if (mesh_err_switch == '\0') goto LAB_004c0530;
    __format = "[MESH_ERROR]%s()/%d uac_sem_create() fail!\n";
    uVar2 = 0x871;
  }
  else {
    iVar1 = mesh_db_init();
    if (iVar1 == 0) {
      iVar1 = mesh_pkt_init();
      if (iVar1 == 0) {
        local_4c = 0x6f;
        local_50 = &DAT_006a49f8;
        local_48 = mesh_cb_for_ap_join;
        local_44 = mesh_cb_for_ap_leave;
        local_3c = mesh_cb_for_ap_delete;
        local_2c = mesh_cb_for_ap_copy;
        local_24 = mesh_cb_for_ap_cap_change;
        local_20 = mesh_cb_for_ap_role_change;
        iVar1 = apmngr_callback_register(auStack_5c);
        if (iVar1 == 0) {
          local_a4 = &DAT_006a49f8;
          local_98 = 0;
          local_a0 = CONCAT13(0x7d,local_a0._1_3_);
          local_9c = mesh_wtp_packet_send;
          iVar1 = multi_link_reg(&local_a4);
          if (iVar1 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c0530;
            __format = "[MESH_ERROR]%s()/%d multi_link_reg() failed.\n";
            uVar2 = 0x899;
          }
          else {
            local_88 = &DAT_006a49f8;
            local_84 = mesh_cb_for_rd_enable;
            local_80 = mesh_cb_for_rd_disable;
            local_60 = 1;
            iVar1 = rdmngr_callback_register(auStack_94);
            if (iVar1 == -1) {
              if (mesh_err_switch == '\0') goto LAB_004c0530;
              __format = "[MESH_ERROR]%s()/%d rdmngr_callback_register() fail!\n";
              uVar2 = 0x8a4;
            }
            else {
              iVar1 = FUN_004084d0("ac_mesh_global_settings",2,mesh_jcs_global_set);
              if ((((((iVar1 != 0) ||
                     (iVar1 = FUN_004084d0("ac_mesh_trigger_discover",2,mesh_jcs_trigger_discover),
                     iVar1 != 0)) ||
                    (iVar1 = FUN_004084d0("ac_mesh_stop_discover",2,mesh_jcs_stop_discover),
                    iVar1 != 0)) ||
                   ((iVar1 = FUN_004084d0("ac_mesh_discover_status",3,mesh_jcs_discover_status_get),
                    iVar1 != 0 ||
                    (iVar1 = FUN_004084d0("ac_mesh_discover_list",3,mesh_jcs_discover_list_get),
                    iVar1 != 0)))) ||
                  ((iVar1 = FUN_004084d0("ac_mesh_discover_cap_change",2,
                                         mesh_jcs_discover_cap_change), iVar1 != 0 ||
                   ((iVar1 = FUN_004084d0("ac_mesh_trigger_pair_all",2,mesh_jcs_trigger_pair_all),
                    iVar1 != 0 ||
                    (iVar1 = FUN_004084d0("ac_mesh_trigger_pair",2,mesh_jcs_trigger_pair),
                    iVar1 != 0)))))) ||
                 ((iVar1 = FUN_004084d0("ac_mesh_topology",3,mesh_jcs_topology_get), iVar1 != 0 ||
                  (iVar1 = FUN_004084d0("ac_mesh_wan_status",2,mesh_jcs_wan_status_set), iVar1 != 0)
                  ))) goto LAB_004c0530;
              apmngr_support_capacity_register(0x2c);
              apmngr_support_capacity_register(0x43);
              apmngr_support_sub_capacity_register(0x2c,0);
              apmngr_support_sub_capacity_register(0x2c,1);
              apmngr_support_sub_capacity_register(0x2c,2);
              apmngr_support_sub_capacity_register(0x2c,5);
              apdb_support_product_type_register(1);
              apdb_support_product_type_register(3);
              apdb_support_product_type_register(2);
              mesh_help_reg();
              mesh_wan_status_send_interval();
              iVar1 = FUN_004084e0(auStack_a8,"mesh_auto_pair_task",_mesh_auto_pair_task,0);
              if (iVar1 == 0) {
                return 0;
              }
              if (mesh_err_switch == '\0') goto LAB_004c0530;
              __format = "[MESH_ERROR]%s()/%d create mesh_auto_pair_task fail\n";
              uVar2 = 0x8ea;
            }
          }
        }
        else {
          if (mesh_err_switch == '\0') goto LAB_004c0530;
          __format = "[MESH_ERROR]%s()/%d apmngr_callback_register() failed.\n";
          uVar2 = 0x88b;
        }
      }
      else {
        if (mesh_err_switch == '\0') goto LAB_004c0530;
        __format = "[MESH_ERROR]%s()/%d mesh_pkt_init() failed.\n";
        uVar2 = 0x87d;
      }
    }
    else {
      if (mesh_err_switch == '\0') goto LAB_004c0530;
      __format = "[MESH_ERROR]%s()/%d mesh_db_init() fail!\n";
      uVar2 = 0x877;
    }
  }
  printf(__format,"uac_mesh_init",uVar2);
LAB_004c0530:
  uac_mesh_uninit();
  return 0xffffffff;
}

