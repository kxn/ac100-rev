// func mesh_pkt_discover_request_send_with_check @ 004c4740 size=128

undefined4 mesh_pkt_discover_request_send_with_check(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar1 = 0xffffffff;
  local_10 = 0;
  if (param_2 != (undefined4 *)0x0) {
    local_c = param_1;
    apmngr_db_foreach_proc(0xe0000,mesh_discovery_send,&local_10);
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d pkt_param.num %d.\n","mesh_pkt_discover_request_send_with_check",
             0x7e9,local_10);
    }
    *param_2 = local_10;
    uVar1 = 0;
  }
  return uVar1;
}

