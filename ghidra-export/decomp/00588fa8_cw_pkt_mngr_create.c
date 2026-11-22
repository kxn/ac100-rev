// func cw_pkt_mngr_create @ 00588fa8 size=192

undefined4 * cw_pkt_mngr_create(void)

{
  undefined4 *__s;
  int iVar1;
  
  __s = (undefined4 *)FUN_00408450(0x14,0x767);
  if (__s == (undefined4 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d memory out\n","cw_pkt_mngr_create",0x76a);
    }
  }
  else {
    memset(__s,0,0x14);
    *__s = capwap_packet_parse;
    __s[1] = capwap_packet_assemble;
    __s[2] = capwap_parsed_packet_free;
    __s[3] = capwap_parsed_packet_dump;
    __s[4] = capwap_parsed_packet_check;
  }
  return __s;
}

