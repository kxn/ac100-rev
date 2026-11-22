// func ac_session_global_init @ 00590304 size=136

undefined4 ac_session_global_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  total_num_mutex = FUN_00407f00("session_total_num",0);
  if (total_num_mutex == 0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d Create database mutex failed.\n","ac_session_global_init",0x1c4);
    }
  }
  else {
    uVar2 = 0;
    session_total_num = 0;
  }
  return uVar2;
}

