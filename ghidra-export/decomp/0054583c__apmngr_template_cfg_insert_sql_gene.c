// func _apmngr_template_cfg_insert_sql_gene @ 0054583c size=1412

size_t _apmngr_template_cfg_insert_sql_gene(char *param_1,size_t param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  size_t sVar8;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328;
  undefined4 local_324;
  undefined1 auStack_320 [32];
  undefined1 auStack_300 [36];
  undefined1 auStack_2dc [64];
  undefined1 auStack_29c [128];
  undefined1 auStack_21c [128];
  undefined1 auStack_19c [308];
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
  
  memset(auStack_19c,0,0x134);
  memset(auStack_2dc,0,0x40);
  memset(auStack_320,0,0x20);
  memset(auStack_21c,0,0x80);
  memset(auStack_29c,0,0x80);
  memset(auStack_300,0,0x21);
  local_334 = 0;
  local_330 = 0;
  local_32c = 0;
  local_328 = 0;
  local_324 = 0;
  local_348 = 0;
  local_344 = 0;
  local_340 = 0;
  local_33c = 0;
  local_338 = 0;
  _apmngr_trim_single_quota(auStack_19c,param_3 + 0x4e,0x134);
  _apmngr_trim_single_quota(auStack_2dc,param_3 + 0xf4,0x40);
  _apmngr_trim_single_quota(auStack_320,param_3 + 0x114,0x20);
  _apmngr_trim_single_quota(auStack_21c,param_3 + 0x132,0x80);
  _apmngr_trim_single_quota(auStack_29c,param_3 + 0x173,0x80);
  FUN_004084f0(param_3 + 0x218,0x10,auStack_300);
  local_68 = (uint)*(ushort *)(param_3 + 0x10);
  local_64 = (uint)*(ushort *)(param_3 + 0x12);
  local_60 = *(undefined4 *)(param_3 + 0x40);
  local_5c = (uint)*(ushort *)(param_3 + 0x44);
  local_58 = (uint)*(ushort *)(param_3 + 0x46);
  local_54 = (uint)*(byte *)(param_3 + 0xe8);
  local_50 = (uint)*(ushort *)(param_3 + 0xea);
  local_4c = *(undefined4 *)(param_3 + 0xec);
  if (*(int *)(param_3 + 0xf0) == 0) {
    pcVar1 = "Led off";
  }
  else {
    pcVar1 = "Led on";
  }
  local_48 = (uint)*(ushort *)(param_3 + 0x128);
  local_44 = (uint)*(ushort *)(param_3 + 0x12a);
  local_40 = (uint)*(ushort *)(param_3 + 300);
  local_3c = (uint)*(ushort *)(param_3 + 0x12e);
  local_38 = *(undefined4 *)(param_3 + 0x124);
  local_34 = *(undefined4 *)(param_3 + 0x1b8);
  if (*(char *)(param_3 + 0x130) == '\0') {
    pcVar2 = "Led off";
  }
  else {
    pcVar2 = "Led on";
  }
  if (*(char *)(param_3 + 0x1bc) == '\0') {
    pcVar3 = "Led off";
  }
  else {
    pcVar3 = "Led on";
  }
  uVar4 = apmngr_db_date_str(*(undefined1 *)(param_3 + 0x1bd));
  uVar5 = apmngr_db_time_str(((uint)(*(ushort *)(param_3 + 0x1c0) >> 8) |
                             (uint)*(ushort *)(param_3 + 0x1be) << 8) << 8,&local_334,0x14);
  local_30 = apmngr_db_date_str(*(undefined1 *)(param_3 + 0x1c1));
  uVar6 = apmngr_db_time_str(((uint)(*(ushort *)(param_3 + 0x1c4) >> 8) |
                             (uint)*(ushort *)(param_3 + 0x1c2) << 8) << 8,&local_348,0x14);
  iVar7 = snprintf(param_1,param_2,
                   "INSERT INTO %s (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s, %s, %s, %s) VALUES( %d, %d, \'%s\', %d, \'%u.%u\', %d, %d, %d, \'%s\', \'%s\', \'%s\', %d,%d,%d,%d, %d, %d,\'%s\', \'%s\',\'%s\',\'%s\',\'%s\',\'%s\',%d,\'%s\',\'%s\', %d,%d,%d,\'%s\',%d,%d,%d,%d,%d,\'%s\',%d);"
                   ,"ApTemplate_table","entry_id","group_id","entry_name","model_id","hardware_ver",
                   "ap_keep_alive","client_keep_alive","client_idle","offline_selfmanage","username"
                   ,"password","phy_wire_vlan_1","phy_wire_vlan_2","phy_wire_vlan_3",
                   "phy_wire_vlan_4","ap_trunk","led","led_wifi_sync","led_timer_enable",
                   "led_close_date","led_close_time","led_open_date","led_open_time",
                   "bluetooth_enable","account_username","account_password","new_ap_trunk",
                   "lag_mode","lag_phy_num","lag_phy_list","telnet_status","fit_fat_button_status",
                   "radio_role_table_idx","region_code","ap_mesh_switch","firmware_id",
                   "ssid_mlo_support",local_68,local_64,auStack_19c,local_60,local_5c,local_58,
                   local_54,local_50,local_4c,pcVar1 + 4,auStack_2dc,auStack_320,local_48,local_44,
                   local_40,local_3c,local_38,local_34,pcVar2 + 4,pcVar3 + 4,uVar4,uVar5,local_30,
                   uVar6,(int)*(char *)(param_3 + 0x131),auStack_21c,auStack_29c,
                   (uint)*(byte *)(param_3 + 0x2b1),(uint)*(byte *)(param_3 + 0x2b2),
                   (uint)*(byte *)(param_3 + 0x2b3),param_3 + 0x2b4,(int)*(char *)(param_3 + 0x206),
                   (int)*(char *)(param_3 + 0x1b4),(uint)*(byte *)(param_3 + 0x2d0),
                   (uint)*(byte *)(param_3 + 0x2d1),(int)*(char *)(param_3 + 0x207),auStack_300,
                   (uint)*(byte *)(param_3 + 0x2d2));
  sVar8 = 0xffffffff;
  if (-1 < iVar7) {
    sVar8 = strlen(param_1);
  }
  return sVar8;
}

