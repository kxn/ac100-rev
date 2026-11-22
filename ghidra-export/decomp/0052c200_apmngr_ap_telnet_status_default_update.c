// func apmngr_ap_telnet_status_default_update @ 0052c200 size=344

undefined4 apmngr_ap_telnet_status_default_update(uint param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined2 local_2f0 [4];
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 != 0) {
    param_1 = 0xffff;
  }
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    if (param_2 == '\x01') {
      pcVar2 = "open";
    }
    else {
      pcVar2 = "close";
    }
    printf("[APMNGR_DEBUG]%s()/%d %s %d\'s telnet start\n","apmngr_ap_telnet_status_default_update",
           0x565,pcVar2,param_1);
  }
  apmngr_db_entry_telnet_set(param_1,param_2 == '\x01');
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(local_2f0), iVar1 != 0)) {
    if (param_2 == '\x01') {
      pcVar2 = "open";
    }
    else {
      pcVar2 = "close";
    }
    printf("[APMNGR_DEBUG]%s()/%d %s %d\'s telnet_status finished\n",
           "apmngr_ap_telnet_status_default_update",0x568,pcVar2,param_1);
  }
  uVar3 = 0xffffffff;
  apmngr_db_telnet_port_get(local_2f0);
  iVar1 = apmngr_telnet_config_send(local_2d8,param_2,local_2f0[0]);
  if ((iVar1 == 0) && (uVar3 = 0, param_1 != 0xffff)) {
    apmngr_db_telnet_status_update(param_1,param_2);
  }
  return uVar3;
}

