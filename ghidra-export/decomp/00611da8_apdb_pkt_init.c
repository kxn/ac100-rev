// func apdb_pkt_init @ 00611da8 size=364

undefined4 apdb_pkt_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = serv_msg_mngr_register(3,0x100,_apdb_pkt_join_req_listen);
  if (iVar1 == -1) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = 
    "[APDB_ERROR]%s()/line %d : register callback to listen join-req capwap message event failed.\n"
    ;
    uVar2 = 0x8d6;
  }
  else {
    iVar1 = serv_msg_mngr_register(1,0x100,_apdb_pkt_discover_req_listen);
    if (iVar1 == -1) {
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      __format = 
      "[APDB_ERROR]%s()/line %d : register callback to listen discover-req capwap message event failed.\n"
      ;
      uVar2 = 0x8db;
    }
    else {
      apdb_pkt_mutex = FUN_00407f00("apdb_pkt_mutex",1);
      if (apdb_pkt_mutex != 0) {
        iVar1 = FUN_004084e0(&unsupport_check_thread,"apdb_unsupp_check",_apdb_unsupport_ap_check,0)
        ;
        if (iVar1 == 0) {
          return 0;
        }
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : Failed to create sqlite thread\n","apdb_pkt_init",0x8e8
                );
        }
        if (apdb_pkt_mutex == 0) {
          return 0xffffffff;
        }
        FUN_00408360();
        apdb_pkt_mutex = 0;
        return 0xffffffff;
      }
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_ERROR]%s()/line %d : Failed to init mutex.\n";
      uVar2 = 0x8e2;
      apdb_pkt_mutex = 0;
    }
  }
  printf(__format,"apdb_pkt_init",uVar2);
  return 0xffffffff;
}

