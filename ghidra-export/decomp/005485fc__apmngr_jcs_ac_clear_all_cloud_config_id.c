// func _apmngr_jcs_ac_clear_all_cloud_config_id @ 005485fc size=20

void _apmngr_jcs_ac_clear_all_cloud_config_id(void)

{
  apmngr_db_foreach_proc(0x15f0000,_ac_clear_all_cloud_config_id_cb,0);
  return;
}

