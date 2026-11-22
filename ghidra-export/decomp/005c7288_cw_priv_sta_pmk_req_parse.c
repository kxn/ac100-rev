// func cw_priv_sta_pmk_req_parse @ 005c7288 size=476

undefined4 cw_priv_sta_pmk_req_parse(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined1 *__s;
  undefined1 uVar5;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  
  __s = (undefined1 *)FUN_00408450(0x68,0x89);
  if (__s == (undefined1 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_pmk_req_parse",0x8c);
    return 0xffffffff;
  }
  memset(__s,0,0x68);
  uVar5 = cw_protocol_retrieve8(param_1);
  *__s = uVar5;
  uVar5 = cw_protocol_retrieve8(param_1);
  __s[1] = uVar5;
  uVar2 = cw_protocol_retrieve8(param_1);
  __s[2] = (char)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[3] = (char)uVar2;
    if (uVar2 < 0x11) {
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 4) = uVar3;
      cw_protocol_retrieve_bytes(param_1,__s + 8,0x11);
      cw_protocol_retrieve_bytes(param_1,__s + 0x19,0x10);
      cw_protocol_retrieve_bytes(param_1,__s + 0x29,6);
      cw_protocol_retrieve_bytes(param_1,__s + 0x2f,6);
      cw_protocol_retrieve_bytes(param_1,__s + 0x35,0x20);
      cw_protocol_retrieve_bytes(param_1,__s + 0x55,0x10);
      *(undefined1 **)(param_2 + 0x10) = __s;
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c73ec;
    bVar1 = __s[3];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar3 = 0x9d;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c73ec;
    bVar1 = __s[2];
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0x96;
  }
  printf(__format,"cw_priv_sta_pmk_req_parse",uVar3,(uint)bVar1);
LAB_005c73ec:
  FUN_00407df0(__s);
  return 0xffffffff;
}

