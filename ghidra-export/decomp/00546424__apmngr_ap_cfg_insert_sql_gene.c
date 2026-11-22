// func _apmngr_ap_cfg_insert_sql_gene @ 00546424 size=1740

size_t _apmngr_ap_cfg_insert_sql_gene(char *param_1,size_t param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  size_t sVar19;
  char *pcVar20;
  char *pcVar21;
  char *pcVar22;
  char *pcVar23;
  char *pcVar24;
  char *pcVar25;
  char *pcVar26;
  char *pcVar27;
  char *pcVar28;
  char *pcVar29;
  char *pcVar30;
  char *pcVar31;
  char *pcVar32;
  char *pcVar33;
  char *pcVar34;
  char *pcVar35;
  char *pcVar36;
  char *pcVar37;
  char *pcVar38;
  char *pcVar39;
  char *pcVar40;
  char *pcVar41;
  char *pcVar42;
  char *pcVar43;
  char *pcVar44;
  char *pcVar45;
  char *pcVar46;
  char *pcVar47;
  char *pcVar48;
  char *pcVar49;
  char *pcVar50;
  char *pcVar51;
  char *pcVar52;
  char *pcVar53;
  char *pcVar54;
  char *pcVar55;
  char *pcVar56;
  char *pcVar57;
  char *pcVar58;
  char *pcVar59;
  char *pcVar60;
  char *pcVar61;
  char *pcVar62;
  uint uVar63;
  uint uVar64;
  uint uVar65;
  uint uVar66;
  uint uVar67;
  uint uVar68;
  uint uVar69;
  uint uVar70;
  undefined1 *puVar71;
  undefined4 uVar72;
  uint uVar73;
  uint uVar74;
  uint uVar75;
  uint uVar76;
  undefined4 uVar77;
  undefined1 *puVar78;
  undefined1 *puVar79;
  uint uVar80;
  uint uVar81;
  uint uVar82;
  uint uVar83;
  undefined4 uVar84;
  undefined4 uVar85;
  undefined4 uVar86;
  undefined1 *puVar87;
  undefined1 *puVar88;
  undefined1 *puVar89;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined1 auStack_340 [32];
  undefined1 auStack_320 [36];
  undefined1 auStack_2fc [64];
  undefined1 auStack_2bc [128];
  undefined1 auStack_23c [128];
  undefined1 auStack_1bc [308];
  char *local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  memset(auStack_1bc,0,0x134);
  memset(auStack_2fc,0,0x40);
  memset(auStack_340,0,0x20);
  memset(auStack_23c,0,0x80);
  memset(auStack_2bc,0,0x80);
  memset(auStack_320,0,0x21);
  local_354 = 0;
  local_350 = 0;
  local_34c = 0;
  local_348 = 0;
  local_344 = 0;
  local_368 = 0;
  local_364 = 0;
  local_360 = 0;
  local_35c = 0;
  local_358 = 0;
  _apmngr_trim_single_quota(auStack_1bc,param_3 + 0x4e,0x134);
  _apmngr_trim_single_quota(auStack_2fc,param_3 + 0xf4,0x40);
  _apmngr_trim_single_quota(auStack_340,param_3 + 0x114,0x20);
  _apmngr_trim_single_quota(auStack_23c,param_3 + 0x132,0x80);
  _apmngr_trim_single_quota(auStack_2bc,param_3 + 0x173,0x80);
  FUN_004084f0(param_3 + 0x218,0x10,auStack_320);
  if (*(int *)(param_3 + 0x3c) == 1) {
    local_88 = "ApEntryCfg_table";
  }
  else {
    local_88 = "ApEntryTmpCfg_table";
  }
  local_80 = (uint)*(ushort *)(param_3 + 0x12);
  local_84 = (uint)*(ushort *)(param_3 + 0x10);
  uVar1 = apmngr_db_role_str(*(undefined4 *)(param_3 + 0x14));
  local_7c = (int)*(short *)(param_3 + 0x18);
  local_78 = (uint)*(byte *)(param_3 + 0x48);
  local_74 = (uint)*(byte *)(param_3 + 0x49);
  local_70 = (uint)*(byte *)(param_3 + 0x4a);
  local_6c = (uint)*(byte *)(param_3 + 0x4b);
  local_68 = (uint)*(byte *)(param_3 + 0x4c);
  local_64 = (uint)*(byte *)(param_3 + 0x4d);
  local_60 = *(undefined4 *)(param_3 + 0x40);
  local_5c = (uint)*(ushort *)(param_3 + 0x44);
  local_58 = (uint)*(ushort *)(param_3 + 0x46);
  local_54 = (uint)*(byte *)(param_3 + 0xe8);
  local_50 = (uint)*(ushort *)(param_3 + 0xea);
  local_4c = *(undefined4 *)(param_3 + 0xec);
  if (*(int *)(param_3 + 0xf0) == 0) {
    pcVar21 = "Led off";
  }
  else {
    pcVar21 = "Led on";
  }
  pcVar21 = pcVar21 + 4;
  local_44 = (uint)*(ushort *)(param_3 + 0x12a);
  local_48 = (uint)*(ushort *)(param_3 + 0x128);
  local_3c = (uint)*(ushort *)(param_3 + 0x12e);
  local_40 = (uint)*(ushort *)(param_3 + 300);
  local_34 = *(undefined4 *)(param_3 + 0x1b8);
  local_38 = *(undefined4 *)(param_3 + 0x124);
  if (*(char *)(param_3 + 0x130) == '\0') {
    pcVar22 = "Led off";
  }
  else {
    pcVar22 = "Led on";
  }
  pcVar22 = pcVar22 + 4;
  if (*(char *)(param_3 + 0x1bc) == '\0') {
    pcVar23 = "Led off";
  }
  else {
    pcVar23 = "Led on";
  }
  pcVar23 = pcVar23 + 4;
  uVar2 = apmngr_db_date_str(*(undefined1 *)(param_3 + 0x1bd));
  uVar3 = apmngr_db_time_str(((uint)(*(ushort *)(param_3 + 0x1c0) >> 8) |
                             (uint)*(ushort *)(param_3 + 0x1be) << 8) << 8,&local_354,0x14);
  local_30 = apmngr_db_date_str(*(undefined1 *)(param_3 + 0x1c1));
  uVar4 = apmngr_db_time_str(((uint)(*(ushort *)(param_3 + 0x1c4) >> 8) |
                             (uint)*(ushort *)(param_3 + 0x1c2) << 8) << 8,&local_368,0x14);
  pcVar24 = "ap_role";
  pcVar25 = "cap_id";
  pcVar26 = "mac";
  pcVar27 = "entry_name";
  pcVar28 = "model_id";
  pcVar29 = "hardware_ver";
  pcVar30 = "ap_keep_alive";
  pcVar31 = "client_keep_alive";
  pcVar32 = "client_idle";
  pcVar33 = "offline_selfmanage";
  pcVar34 = "username";
  pcVar35 = "password";
  pcVar36 = "phy_wire_vlan_1";
  pcVar37 = "phy_wire_vlan_2";
  pcVar38 = "phy_wire_vlan_3";
  pcVar39 = "phy_wire_vlan_4";
  pcVar40 = "ap_trunk";
  pcVar41 = "led";
  pcVar42 = "led_wifi_sync";
  pcVar43 = "led_timer_enable";
  pcVar44 = "led_close_date";
  pcVar45 = "led_close_time";
  pcVar46 = "led_open_date";
  pcVar47 = "led_open_time";
  pcVar48 = "bluetooth_enable";
  pcVar49 = "account_username";
  pcVar50 = "account_password";
  pcVar51 = "cloud_config_id";
  pcVar52 = "new_ap_trunk";
  pcVar53 = "lag_mode";
  pcVar54 = "lag_phy_num";
  pcVar55 = "lag_phy_list";
  pcVar56 = "telnet_status";
  pcVar57 = "fit_fat_button_status";
  pcVar58 = "radio_role_table_idx";
  pcVar59 = "region_code";
  pcVar60 = "ap_mesh_switch";
  pcVar61 = "firmware_id";
  pcVar62 = "ssid_mlo_support";
  puVar71 = auStack_1bc;
  iVar5 = (int)*(char *)(param_3 + 0x131);
  puVar87 = auStack_23c;
  puVar78 = auStack_2fc;
  puVar88 = auStack_2bc;
  puVar79 = auStack_340;
  iVar6 = param_3 + 0x1c5;
  uVar7 = (uint)*(byte *)(param_3 + 0x2b1);
  uVar8 = (uint)*(byte *)(param_3 + 0x2b2);
  uVar9 = (uint)*(byte *)(param_3 + 0x2b3);
  iVar10 = param_3 + 0x2b4;
  iVar11 = (int)*(char *)(param_3 + 0x206);
  iVar12 = (int)*(char *)(param_3 + 0x1b4);
  uVar13 = (uint)*(byte *)(param_3 + 0x2d0);
  uVar14 = (uint)*(byte *)(param_3 + 0x2d1);
  iVar15 = (int)*(char *)(param_3 + 0x207);
  puVar89 = auStack_320;
  uVar16 = (uint)*(byte *)(param_3 + 0x2d2);
  uVar63 = local_84;
  uVar64 = local_80;
  iVar18 = local_7c;
  uVar65 = local_78;
  uVar66 = local_74;
  uVar67 = local_70;
  uVar68 = local_6c;
  uVar69 = local_68;
  uVar70 = local_64;
  uVar72 = local_60;
  uVar73 = local_5c;
  uVar74 = local_58;
  uVar75 = local_54;
  uVar76 = local_50;
  uVar77 = local_4c;
  uVar80 = local_48;
  uVar81 = local_44;
  uVar82 = local_40;
  uVar83 = local_3c;
  uVar84 = local_38;
  uVar85 = local_34;
  uVar86 = local_30;
  iVar17 = snprintf(param_1,param_2,
                    "INSERT INTO %s (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s, %s, %s, %s) VALUES( %d, %d, \'%s\', %d, \'%.2X-%.2X-%.2X-%.2X-%.2X-%.2X\', \'%s\', %d, \'%u.%u\', %d, %d, %d, \'%s\', \'%s\', \'%s\', %d,%d,%d,%d, %d, %d,\'%s\', \'%s\',\'%s\',\'%s\',\'%s\',\'%s\', %d,\'%s\',\'%s\',\'%s\', %d,%d,%d,\'%s\',%d,%d,%d,%d,%d,\'%s\',%d);"
                    ,local_88,"entry_id","group_id","ap_role","cap_id","mac","entry_name","model_id"
                    ,"hardware_ver","ap_keep_alive","client_keep_alive","client_idle",
                    "offline_selfmanage","username","password","phy_wire_vlan_1","phy_wire_vlan_2",
                    "phy_wire_vlan_3","phy_wire_vlan_4","ap_trunk","led","led_wifi_sync",
                    "led_timer_enable","led_close_date","led_close_time","led_open_date",
                    "led_open_time","bluetooth_enable","account_username","account_password",
                    "cloud_config_id","new_ap_trunk","lag_mode","lag_phy_num","lag_phy_list",
                    "telnet_status","fit_fat_button_status","radio_role_table_idx","region_code",
                    "ap_mesh_switch","firmware_id","ssid_mlo_support",local_84,local_80,uVar1,
                    local_7c,local_78,local_74,local_70,local_6c,local_68,local_64,puVar71,local_60,
                    local_5c,local_58,local_54,local_50,local_4c,pcVar21,puVar78,puVar79,local_48,
                    local_44,local_40,local_3c,local_38,local_34,pcVar22,pcVar23,uVar2,uVar3,
                    local_30,uVar4,iVar5,puVar87,puVar88,iVar6,uVar7,uVar8,uVar9,iVar10,iVar11,
                    iVar12,uVar13,uVar14,iVar15,puVar89,uVar16);
  sVar19 = 0xffffffff;
  if (-1 < iVar17) {
    if (*(int *)(param_3 + 0xc) == 2) {
      sVar19 = strlen(param_1);
      if (*(int *)(param_3 + 0x3c) == 1) {
        pcVar20 = "ApEntryCfg_table";
      }
      else {
        pcVar20 = "ApEntryTmpCfg_table";
      }
      iVar18 = snprintf(param_1 + sVar19,param_2 - sVar19,
                        "UPDATE %s SET hdap_peer_id = %d WHERE entry_id = %d;",pcVar20,
                        (uint)*(ushort *)(param_3 + 0x298),(uint)*(ushort *)(param_3 + 0x10),pcVar24
                        ,pcVar25,pcVar26,pcVar27,pcVar28,pcVar29,pcVar30,pcVar31,pcVar32,pcVar33,
                        pcVar34,pcVar35,pcVar36,pcVar37,pcVar38,pcVar39,pcVar40,pcVar41,pcVar42,
                        pcVar43,pcVar44,pcVar45,pcVar46,pcVar47,pcVar48,pcVar49,pcVar50,pcVar51,
                        pcVar52,pcVar53,pcVar54,pcVar55,pcVar56,pcVar57,pcVar58,pcVar59,pcVar60,
                        pcVar61,pcVar62,uVar63,uVar64,uVar1,iVar18,uVar65,uVar66,uVar67,uVar68,
                        uVar69,uVar70,puVar71,uVar72,uVar73,uVar74,uVar75,uVar76,uVar77,pcVar21,
                        puVar78,puVar79,uVar80,uVar81,uVar82,uVar83,uVar84,uVar85,pcVar22,pcVar23,
                        uVar2,uVar3,uVar86,uVar4,iVar5,puVar87,puVar88,iVar6,uVar7,uVar8,uVar9,
                        iVar10,iVar11,iVar12,uVar13,uVar14,iVar15,puVar89,uVar16);
      if (iVar18 < 0) {
        return 0xffffffff;
      }
    }
    sVar19 = strlen(param_1);
  }
  return sVar19;
}

