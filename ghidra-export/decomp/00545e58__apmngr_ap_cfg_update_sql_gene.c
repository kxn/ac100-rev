// func _apmngr_ap_cfg_update_sql_gene @ 00545e58 size=1284

size_t _apmngr_ap_cfg_update_sql_gene
                 (char *param_1,size_t param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  size_t sVar8;
  char *pcVar9;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [32];
  undefined1 auStack_2c8 [64];
  undefined1 auStack_288 [128];
  undefined1 auStack_208 [128];
  undefined1 auStack_188 [312];
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  uint local_2c;
  
  memset(auStack_188,0,0x134);
  memset(auStack_2c8,0,0x40);
  memset(auStack_2e8,0,0x20);
  memset(auStack_208,0,0x80);
  memset(auStack_288,0,0x80);
  local_2fc = 0;
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  if (param_3 == 0) {
    if (param_4 == 0) {
      pcVar9 = "ApEntryTmpCfg_table";
    }
    else {
      pcVar9 = "ApEntryCfg_table";
    }
  }
  else {
    pcVar9 = "ApTemplate_table";
  }
  _apmngr_trim_single_quota(auStack_188,param_6 + 0xe,0x134);
  _apmngr_trim_single_quota(auStack_2c8,param_6 + 0xb4,0x40);
  _apmngr_trim_single_quota(auStack_2e8,param_6 + 0xd4,0x20);
  _apmngr_trim_single_quota(auStack_208,param_6 + 0xf2,0x80);
  _apmngr_trim_single_quota(auStack_288,param_6 + 0x133,0x80);
  local_38 = (uint)*(byte *)(param_6 + 0xa8);
  local_34 = (uint)*(ushort *)(param_6 + 0xaa);
  local_30 = *(undefined4 *)(param_6 + 0xac);
  local_2c = (uint)*(ushort *)(param_6 + 0xe8);
  if (param_3 == 0) {
    if (*(int *)(param_6 + 0xb0) == 0) {
      pcVar3 = "Led off";
    }
    else {
      pcVar3 = "Led on";
    }
    local_50 = (uint)*(ushort *)(param_6 + 0xea);
    local_4c = (uint)*(ushort *)(param_6 + 0xec);
    local_48 = (uint)*(ushort *)(param_6 + 0xee);
    local_44 = *(undefined4 *)(param_6 + 0xe4);
    local_40 = *(undefined4 *)(param_6 + 0x178);
    if (*(char *)(param_6 + 0xf0) == '\0') {
      pcVar1 = "Led off";
    }
    else {
      pcVar1 = "Led on";
    }
    if (*(char *)(param_6 + 0x17c) == '\0') {
      pcVar2 = "Led off";
    }
    else {
      pcVar2 = "Led on";
    }
    uVar4 = apmngr_db_date_str(*(undefined1 *)(param_6 + 0x17d));
    uVar5 = apmngr_db_time_str(((uint)(*(ushort *)(param_6 + 0x180) >> 8) |
                               (uint)*(ushort *)(param_6 + 0x17e) << 8) << 8,&local_2fc,0x14);
    local_3c = apmngr_db_date_str(*(undefined1 *)(param_6 + 0x181));
    uVar6 = apmngr_db_time_str(((uint)(*(ushort *)(param_6 + 0x184) >> 8) |
                               (uint)*(ushort *)(param_6 + 0x182) << 8) << 8,&local_310,0x14);
    iVar7 = snprintf(param_1,param_2,
                     "UPDATE %s SET entry_name = \'%s\',ap_keep_alive = %d,client_keep_alive = %d,client_idle = %d,offline_selfmanage = %s,username = \'%s\',password = \'%s\',phy_wire_vlan_1 = %d,phy_wire_vlan_2 = %d,phy_wire_vlan_3 = %d,phy_wire_vlan_4 = %d,ap_trunk = %d,led = %d,led_wifi_sync = %s,led_timer_enable = %s,led_close_date = %s,led_close_time = %s,led_open_date = %s,led_open_time = %s,bluetooth_enable = %d,account_username = \'%s\',account_password = \'%s\',cloud_config_id = \'%s\',telnet_status = %d,fit_fat_button_status = %d,ap_mesh_switch = %d WHERE id = %d;"
                     ,pcVar9,auStack_188,local_38,local_34,local_30,pcVar3 + 4,auStack_2c8,
                     auStack_2e8,local_2c,local_50,local_4c,local_48,local_44,local_40,pcVar1 + 4,
                     pcVar2 + 4,uVar4,uVar5,local_3c,uVar6,(int)*(char *)(param_6 + 0xf1),
                     auStack_208,auStack_288,param_6 + 0x185,(int)*(char *)(param_6 + 0x1c6),
                     (int)*(char *)(param_6 + 0x174),(int)*(char *)(param_6 + 0x1c7),param_5);
  }
  else {
    if (*(int *)(param_6 + 0xb0) == 0) {
      pcVar3 = "Led off";
    }
    else {
      pcVar3 = "Led on";
    }
    local_50 = (uint)*(ushort *)(param_6 + 0xea);
    local_4c = (uint)*(ushort *)(param_6 + 0xec);
    local_48 = (uint)*(ushort *)(param_6 + 0xee);
    local_44 = *(undefined4 *)(param_6 + 0xe4);
    local_40 = *(undefined4 *)(param_6 + 0x178);
    if (*(char *)(param_6 + 0xf0) == '\0') {
      pcVar1 = "Led off";
    }
    else {
      pcVar1 = "Led on";
    }
    if (*(char *)(param_6 + 0x17c) == '\0') {
      pcVar2 = "Led off";
    }
    else {
      pcVar2 = "Led on";
    }
    uVar4 = apmngr_db_date_str(*(undefined1 *)(param_6 + 0x17d));
    uVar5 = apmngr_db_time_str(((uint)(*(ushort *)(param_6 + 0x180) >> 8) |
                               (uint)*(ushort *)(param_6 + 0x17e) << 8) << 8,&local_2fc,0x14);
    local_3c = apmngr_db_date_str(*(undefined1 *)(param_6 + 0x181));
    uVar6 = apmngr_db_time_str(((uint)(*(ushort *)(param_6 + 0x184) >> 8) |
                               (uint)*(ushort *)(param_6 + 0x182) << 8) << 8,&local_310,0x14);
    iVar7 = snprintf(param_1,param_2,
                     "UPDATE %s SET entry_name = \'%s\',ap_keep_alive = %d,client_keep_alive = %d,client_idle = %d,offline_selfmanage = %s,username = \'%s\',password = \'%s\',phy_wire_vlan_1 = %d,phy_wire_vlan_2 = %d,phy_wire_vlan_3 = %d,phy_wire_vlan_4 = %d,ap_trunk = %d,led = %d,led_wifi_sync = %s,led_timer_enable = %s,led_close_date = %s,led_close_time = %s,led_open_date = %s,led_open_time = %s,bluetooth_enable = %d,account_username = \'%s\',account_password = \'%s\',telnet_status = %d,fit_fat_button_status = %d,ap_mesh_switch = %d WHERE id = %d;"
                     ,pcVar9,auStack_188,local_38,local_34,local_30,pcVar3 + 4,auStack_2c8,
                     auStack_2e8,local_2c,local_50,local_4c,local_48,local_44,local_40,pcVar1 + 4,
                     pcVar2 + 4,uVar4,uVar5,local_3c,uVar6,(int)*(char *)(param_6 + 0xf1),
                     auStack_208,auStack_288,(int)*(char *)(param_6 + 0x1c6),
                     (int)*(char *)(param_6 + 0x174),(int)*(char *)(param_6 + 0x1c7),param_5);
  }
  sVar8 = 0xffffffff;
  if (-1 < iVar7) {
    sVar8 = strlen(param_1);
  }
  return sVar8;
}

