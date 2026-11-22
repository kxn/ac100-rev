// func _mesh_re_ip_update @ 00408e3c size=104

void _mesh_re_ip_update(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    apmngr_db_ap_run_ip_update(*(undefined2 *)(param_1 + 0x10));
    apupd_db_wtp_ip_update(param_1 + 0x48,param_2,param_3,param_4);
    return;
  }
  return;
}

