// func audit_client_init @ 00509a80 size=780

undefined4 audit_client_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_48 [4];
  char acStack_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  code *local_1c;
  undefined4 local_18;
  
  iVar1 = audit_client_db_init();
  if (iVar1 != 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d audit_client_db_init failed.\n";
    uVar2 = 0x2d3;
    goto LAB_00509b08;
  }
  iVar1 = audit_client_pkt_init();
  if (iVar1 != 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d audit_client_pkt_init fail!\n";
    uVar2 = 0x2d9;
    goto LAB_00509b08;
  }
  apmngr_support_capacity_register(0x29);
  iVar1 = FUN_004084d0("ac_audit",2,_audit_client_jcs_set_cb);
  if (iVar1 != 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[AUDIT_ERR]%s()/%d _audit_client_register_to_jcs failed.\n","audit_client_init",0x2e1);
    return 0xffffffff;
  }
  memset(acStack_44,0,0x30);
  snprintf(acStack_44,0x20,"audit_sta_auth");
  local_24 = 10;
  local_20 = 0;
  local_18 = 0;
  local_1c = _audit_client_sta_auth_cb;
  iVar1 = wportal_db_event_register(acStack_44);
  if (iVar1 == -1) {
    if (audit_err_switch != 0) {
      uVar2 = 0x10c;
LAB_00509d18:
      printf("[AUDIT_ERR]%s()/%d Audit module register to wportal failed.\n",
             "_audit_client_register_to_wportal",uVar2);
    }
  }
  else {
    memset(acStack_44,0,0x30);
    snprintf(acStack_44,0x20,"audit_sta_unauth");
    local_24 = 10;
    local_20 = 1;
    local_18 = 0;
    local_1c = _audit_client_sta_unauth_cb;
    iVar1 = wportal_db_event_register(acStack_44);
    if (iVar1 != -1) {
      audit_auth_sc =
           FUN_00407e50("audit_schedule",5,100,_audit_client_sc_free_cb,_audit_client_sc_handle_auth
                       );
      if (audit_auth_sc == 0) {
        if (audit_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[AUDIT_ERR]%s()/%d uac_schedule_container_queue_create() fail!\n";
        uVar2 = 0x2f0;
      }
      else {
        audit_sniffing_sc =
             FUN_00407e50("audit_schedule",5,100,_audit_client_sc_free_cb,
                          _audit_client_sc_handle_sniffing);
        if (audit_sniffing_sc == 0) {
          if (audit_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[AUDIT_ERR]%s()/%d uac_schedule_container_queue_create() fail!\n";
          uVar2 = 0x2f7;
        }
        else {
          iVar1 = FUN_004084e0(auStack_48,"audit_client",_audit_client_thread,0);
          if (iVar1 == 0) {
            return 0;
          }
          if (audit_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[AUDIT_ERR]%s()/%d Create thread error\n";
          uVar2 = 0x2fd;
        }
      }
      goto LAB_00509b08;
    }
    if (audit_err_switch != 0) {
      uVar2 = 0x118;
      goto LAB_00509d18;
    }
  }
  if (audit_err_switch == 0) {
    return 0xffffffff;
  }
  __format = "[AUDIT_ERR]%s()/%d _audit_client_register_to_wportal failed.\n";
  uVar2 = 0x2e8;
LAB_00509b08:
  printf(__format,"audit_client_init",uVar2);
  return 0xffffffff;
}

