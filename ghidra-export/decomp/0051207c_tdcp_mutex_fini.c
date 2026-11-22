// func tdcp_mutex_fini @ 0051207c size=196

void tdcp_mutex_fini(void)

{
  if (tdcp_from_ap_mutex != 0) {
    FUN_00408360();
    tdcp_from_ap_mutex = 0;
  }
  if (tdcp_to_ap_mutex != 0) {
    FUN_00408360();
    tdcp_to_ap_mutex = 0;
  }
  if (tdcp_waiting_response_mutex != 0) {
    FUN_00408360();
    tdcp_waiting_response_mutex = 0;
  }
  if (tdcp_send_request_id_mutex != 0) {
    FUN_00408360();
    tdcp_send_request_id_mutex = 0;
  }
  if (tdcp_from_ap_cond != 0) {
    FUN_00408220();
    tdcp_from_ap_cond = 0;
  }
  if (tdcp_to_ap_cond != 0) {
    FUN_00408220();
    tdcp_to_ap_cond = 0;
  }
  return;
}

