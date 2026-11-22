// func wserv_db_entry_set_ssid_portal_switch @ 005f5584 size=180

undefined4 wserv_db_entry_set_ssid_portal_switch(uint param_1,byte param_2)

{
  int iVar1;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> enter wserv_db_entry_set_ssid_portal_switch,wserv_id:%d,ssid_portal_switch:%d\r\n"
           ,"wserv_db_entry_set_ssid_portal_switch",0x17ff,param_1 & 0xff,(uint)param_2);
  }
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  iVar1 = DAT_007cbefc + (param_1 & 0xff) * 0x21c;
  if ((uint)*(byte *)(iVar1 + 0x137) != (uint)param_2) {
    *(byte *)(iVar1 + 0x137) = param_2;
  }
  FUN_00407f30(DAT_007cbef0);
  return 0;
}

