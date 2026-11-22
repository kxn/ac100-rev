// func uac_rdmngr_jcs_register @ 0062f024 size=148

undefined4 uac_rdmngr_jcs_register(void)

{
  FUN_004084d0("rf_mngr",2,_uac_rdmngr_jcs_set);
  FUN_004084d0("rf_mngr",3,_uac_rdmngr_jcs_get);
  FUN_004084d0("rf_mngr_entry",3,_uac_rdmngr_jcs_get_entry);
  FUN_004084d0("backup_rf_mngr_entry",3,_uac_rdmngr_jcs_backup);
  FUN_004084d0("rdmngr_datasync",2,_rdmngr_jcs_callback_datasync);
  return 0;
}

