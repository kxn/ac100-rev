// func apmngr_db_telnet_port_get @ 0053cbe8 size=152

undefined4 apmngr_db_telnet_port_get(undefined2 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == (undefined2 *)0x0) {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input error\n","apmngr_db_telnet_port_get",0x996);
    }
  }
  else {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar1 = apmngr_db_mutex;
    *param_1 = g_apmngr_telnet_port;
    uVar3 = 0;
    FUN_00407f30(uVar1);
  }
  return uVar3;
}

