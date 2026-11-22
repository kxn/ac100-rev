// func _stats_ap_disconnect_cb @ 00673040 size=156

undefined4 _stats_ap_disconnect_cb(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) && (uVar2 = 0, *(int *)(param_1 + 0xc) != 0)) {
    uVar1 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
    if (uVar1 == 0xffffffff) {
      uVar2 = 0xffffffff;
      if (stats_warning_switch != '\0') {
        printf("[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail.\n",
               "_stats_ap_disconnect_cb",0x9c);
      }
    }
    else {
      stats_db_ap_reset(*(undefined2 *)(param_1 + 0x10),uVar1 & 0xff,0);
    }
  }
  return uVar2;
}

