// func mesh_pkt_init @ 004c58ac size=384

undefined4 mesh_pkt_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = serv_msg_mngr_register(3,0x78,_mesh_pkt_join_req_policy_listen);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = 
    "[MESH_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n";
    uVar2 = 0xa1f;
  }
  else {
    iVar1 = serv_msg_mngr_register(9,0x78,_mesh_pkt_wtp_event_req_listen);
    if (iVar1 == -1) {
      if (mesh_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = 
      "[MESH_ERROR]%s()/%d register callback to listen wtp-event-req capwap message event failed.\n"
      ;
      uVar2 = 0xa24;
    }
    else {
      iVar1 = serv_msg_mngr_register(3,0x79,_mesh_pkt_join_req_listen);
      if (iVar1 == -1) {
        if (mesh_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = 
        "[MESH_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n";
        uVar2 = 0xa29;
      }
      else {
        iVar1 = serv_msg_mngr_register(1,100,_mesh_pkt_discover_req_listen);
        if (iVar1 == -1) {
          if (mesh_err_switch == '\0') {
            return 0xffffffff;
          }
          __format = 
          "[MESH_ERROR]%s()/%d register callback to listen discover-req capwap message event failed.\n"
          ;
          uVar2 = 0xa2e;
        }
        else {
          iVar1 = serv_msg_mngr_register(5,100,_mesh_pkt_config_status_req_listen);
          if (iVar1 != -1) {
            return 0;
          }
          if (mesh_err_switch == '\0') {
            return 0xffffffff;
          }
          __format = 
          "[MESH_ERROR]%s()/%d register callback to listen configuration status reqeust failed.\n";
          uVar2 = 0xa33;
        }
      }
    }
  }
  printf(__format,"mesh_pkt_init",uVar2);
  return 0xffffffff;
}

