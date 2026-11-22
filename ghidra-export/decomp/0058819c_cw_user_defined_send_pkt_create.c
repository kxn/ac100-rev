// func cw_user_defined_send_pkt_create @ 0058819c size=84

void * cw_user_defined_send_pkt_create(undefined4 param_1)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x10,0x4e5);
  if (__s != (void *)0x0) {
    memset(__s,0,0x10);
    *(undefined4 *)((int)__s + 4) = param_1;
  }
  return __s;
}

