// func capwap_socket_destroy @ 00561788 size=124

void capwap_socket_destroy(int param_1)

{
  int iVar1;
  
  if (param_1 == -1) {
    return;
  }
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d socket[%d] closed.\n","capwap_socket_destroy",0x200,param_1);
  }
  close(param_1);
  return;
}

