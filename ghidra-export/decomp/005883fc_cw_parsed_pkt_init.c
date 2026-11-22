// func cw_parsed_pkt_init @ 005883fc size=140

void * cw_parsed_pkt_init(void)

{
  void *__s;
  int iVar1;
  
  __s = (void *)FUN_00408450(0x38,0x56f);
  if (__s == (void *)0x0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_parsed_pkt_init",0x572);
    }
  }
  else {
    memset(__s,0,0x38);
    FUN_0051ad88((int)__s + 0x1c);
  }
  return __s;
}

