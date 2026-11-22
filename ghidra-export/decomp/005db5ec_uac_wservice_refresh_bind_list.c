// func uac_wservice_refresh_bind_list @ 005db5ec size=88

undefined4
uac_wservice_refresh_bind_list
          (undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  wserv_db_rd_unbind_with_freq_vlan(param_1,param_2,param_3,_uac_wserv_del_cb,param_4,param_5);
  apmngr_db_foreach_proc(0xf0000,_bind_ap_to_wserv,local_res0);
  uac_wservice_sync_all_wlan_to_re();
  return 0;
}

