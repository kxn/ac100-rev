// func _apmngr_send_to_telnet_ap @ 0052b93c size=308

undefined4 _apmngr_send_to_telnet_ap(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input params invalid.\n","_apmngr_send_to_telnet_ap",0x530);
    }
  }
  else if (*(char *)(param_1 + 0x206) == '\x01') {
    if (apmngr_debug_switch == '\0') {
      uVar2 = *param_2;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar2 = *param_2;
      }
      else {
        printf("[APMNGR_DEBUG]%s()/%d ap(%d)\'s telnet is open,send packet:%d,%d\n",
               "_apmngr_send_to_telnet_ap",0x53a,(uint)*(ushort *)(param_1 + 0x10),*param_2,
               (uint)*(ushort *)(param_2 + 1));
        uVar2 = *param_2;
      }
    }
    uVar3 = 0xffffffff;
    iVar1 = apmngr_telnet_config_send
                      (*(undefined2 *)(param_1 + 0x10),uVar2,*(undefined2 *)(param_2 + 1));
    if (iVar1 == 0) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d ap(%d)\'s telnet is not open\n","_apmngr_send_to_telnet_ap",
             0x535,(uint)*(ushort *)(param_1 + 0x10));
    }
  }
  return uVar3;
}

