// func cw_frag_session_create @ 00597294 size=256

undefined4 * cw_frag_session_create(undefined4 param_1,undefined4 param_2)

{
  undefined4 *__s;
  int iVar1;
  
  __s = (undefined4 *)FUN_00408450(0x48,0x368);
  if (__s == (undefined4 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d malloc pkt_frag_mngr failed\n","cw_frag_session_create",0x36b);
    }
  }
  else {
    memset(__s,0,0x48);
    FUN_0051ad88(__s + 5);
    __s[2] = 0;
    __s[1] = 0xffffffff;
    __s[3] = 0;
    __s[4] = 0;
    __s[8] = 0;
    FUN_0051ad88(__s + 0xc);
    __s[0xb] = 0;
    *__s = param_1;
    __s[9] = param_2;
    __s[10] = cw_pkt_reassemble;
    __s[0xf] = cw_pkt_frag;
    __s[0x10] = cw_frag_mngr_free;
    __s[0x11] = cw_frag_mngr_dump;
  }
  return __s;
}

