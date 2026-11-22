// func cw_priv_ap_log_report_para_parse @ 005a64b4 size=372

undefined4 cw_priv_ap_log_report_para_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0x1c,0x77);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_log_report_para_parse",0x7a);
    }
  }
  else {
    memset(__s,0,0x1c);
    uVar4 = cw_protocol_retrieve8(param_1);
    *__s = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[2] = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[3] = uVar4;
    cw_protocol_retrieve_ip(param_1,__s + 4);
    if ((byte)(__s[4] - 1) < 2) {
      uVar2 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x18) = uVar2;
      *(undefined1 **)(param_2 + 0x10) = __s;
      uVar2 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar2 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d Illegal remote servert type:%d\n",
               "cw_priv_ap_log_report_para_parse",0x87,(uint)(byte)__s[4]);
      }
      FUN_00407df0(__s);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

