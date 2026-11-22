// func capwap_ac_session_create @ 0058fac4 size=228

void * capwap_ac_session_create(undefined2 param_1,undefined1 param_2)

{
  void *__s;
  int iVar1;
  
  __s = (void *)FUN_00408450(0x104,0x9f);
  if (__s == (void *)0x0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d no memory\n","capwap_ac_session_create",0xa2);
    }
  }
  else {
    memset(__s,0,0x104);
    *(undefined2 *)((int)__s + 0xf4) = param_1;
    *(undefined2 *)((int)__s + 0xf0) = param_1;
    *(undefined2 *)((int)__s + 0xa6) = 0xffff;
    *(undefined1 *)((int)__s + 0xf7) = param_2;
    FUN_0051ad88((int)__s + 0xf8);
    FUN_004082d0(total_num_mutex,0xffffffff);
    session_total_num = session_total_num + 1;
    FUN_00407f30(total_num_mutex);
  }
  return __s;
}

