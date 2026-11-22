// func uac_mac_auth_init @ 00451078 size=684

undefined4 uac_mac_auth_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_58 [36];
  char acStack_34 [32];
  undefined4 local_14;
  code *local_10;
  undefined4 local_c;
  
  memset(acStack_34,0,0x2c);
  memcpy(auStack_58,&DAT_00685150,0x24);
  iVar1 = FUN_00408120("authentication","macauth",auStack_58,1);
  if (iVar1 == 0) {
    iVar1 = mac_auth_db_init();
    if (iVar1 == -1) {
      if (macauth_err_switch == 0) {
        return 0xffffffff;
      }
      __format = "[MACAUTH_ERROR]%s()/%d mac_auth_db_init() failed.\n";
      uVar2 = 0x572;
    }
    else {
      iVar1 = mac_auth_init();
      if (iVar1 == -1) {
        if (macauth_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[MACAUTH_ERROR]%s()/%d mac_auth_init() failed.\n";
        uVar2 = 0x578;
      }
      else {
        FUN_004084d0("macauth_mac",3,_uac_mac_auth_mac_jcs_get);
        FUN_004084d0("macauth_mac",0,_uac_mac_auth_mac_jcs_add);
        FUN_004084d0("macauth_mac",1,_uac_mac_auth_mac_jcs_del);
        FUN_004084d0("macauth_mac",2,_uac_mac_auth_mac_jcs_set);
        FUN_004084d0("macauth_mac_for_group",1,_uac_mac_auth_mac_jcs_del_for_group);
        FUN_004084d0("macauth_group",3,_uac_mac_auth_group_jcs_get);
        FUN_004084d0("macauth_group",0,_uac_mac_auth_group_jcs_add);
        FUN_004084d0("macauth_group",1,_uac_mac_auth_group_jcs_del);
        FUN_004084d0("macauth_group",2,_uac_mac_auth_group_jcs_set);
        FUN_004084d0("macauth_group_for_ssid",0,_uac_mac_auth_group_jcs_add_for_ssid);
        FUN_004084d0("macauth_group_for_ssid",1,_uac_mac_auth_group_jcs_del_for_ssid);
        FUN_004084d0("macauth_group_for_ssid",2,_uac_mac_auth_group_jcs_set_for_ssid);
        FUN_004084d0("macauth_type",2,_uac_mac_auth_auth_type_jcs_set);
        strncpy(acStack_34,"mac_auth",0x1f);
        local_c = 0;
        local_14 = 10;
        local_10 = _uac_mac_auth_wservice_del_callback;
        iVar1 = wserv_db_event_register(4,acStack_34);
        if (iVar1 == 0) {
          return 0;
        }
        if (macauth_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[MACAUTH_ERROR]%s()/%d wserv_db_event_register() fail!\n";
        uVar2 = 0x587;
      }
    }
    printf(__format,"uac_mac_auth_init",uVar2);
  }
  else {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d uci req parse failed.\n","_uac_mac_auth_read_auth_type",0x55f);
    }
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d _uac_mac_auth_read_auth_type_from_uci() failed.\n",
             "uac_mac_auth_init",0x56d);
    }
  }
  return 0xffffffff;
}

