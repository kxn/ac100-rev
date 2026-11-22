// func wportal_db_destroy @ 0042d5f8 size=396

undefined4 wportal_db_destroy(void)

{
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  FUN_00407df0(rdt_list);
  rdt_list = 0;
  FUN_00407f30(wportal_rdt_mutex);
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  FUN_00407df0(iface_list);
  iface_list = 0;
  FUN_00407f30(wportal_rdt_mutex);
  FUN_00408360(wportal_rdt_mutex);
  wportal_rdt_mutex = 0;
  FUN_004082d0(wportal_ftt_mutex,0xffffffff);
  FUN_00408370(ftt_tree);
  ftt_tree = 0;
  FUN_00407f30(wportal_ftt_mutex);
  FUN_00408360(wportal_ftt_mutex);
  wportal_ftt_mutex = 0;
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  FUN_00408370(aut_tree);
  aut_tree = 0;
  FUN_00407df0(aut_list);
  aut_list = 0;
  FUN_00407f30(wportal_aut_mutex);
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  FUN_00408370(nsa_tree);
  nsa_tree = 0;
  FUN_00407df0(nsa_list);
  nsa_list = 0;
  FUN_00407f30(wportal_nsa_mutex);
  FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
  FUN_00408370(rds_srv_tree_index);
  rds_srv_tree_index = 0;
  FUN_00408310(rds_srv_hash_addr);
  FUN_00407f30(wportal_rds_srv_mutex);
  FUN_00408360(wportal_rds_srv_mutex);
  wportal_rds_srv_mutex = 0;
  FUN_00408360(wportal_aut_mutex);
  wportal_aut_mutex = 0;
  FUN_00408360(wportal_nsa_mutex);
  wportal_nsa_mutex = 0;
  return 0;
}

