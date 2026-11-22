// func capwap_dtls_data_create @ 00597890 size=132

void * capwap_dtls_data_create(void)

{
  void *__s;
  int iVar1;
  
  __s = (void *)FUN_00408450(0x70,0x171);
  if (__s == (void *)0x0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d create dtls data failed\n","capwap_dtls_data_create",0x173);
    }
  }
  else {
    memset(__s,0,0x70);
  }
  return __s;
}

