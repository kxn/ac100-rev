// func wportal_db_cmcc_data_deInit @ 0043313c size=180

void wportal_db_cmcc_data_deInit(void)

{
  if (cmcc_serialno_list != 0) {
    FUN_00407df0();
    cmcc_serialno_list = 0;
  }
  if (cmcc_serialno_tree != 0) {
    FUN_00408370();
    cmcc_serialno_tree = 0;
  }
  if (wportal_cmcc_serialno_mutex != 0) {
    FUN_00408360();
    wportal_cmcc_serialno_mutex = 0;
  }
  cmcc_serialno_node_num = 0;
  if (cmcc_wq_tree != 0) {
    FUN_00408370();
    cmcc_wq_tree = 0;
  }
  if (wportal_cmcc_waitque_mutex != 0) {
    FUN_00408360();
    wportal_cmcc_waitque_mutex = 0;
  }
  cmcc_wq_node_num = 0;
  return;
}

