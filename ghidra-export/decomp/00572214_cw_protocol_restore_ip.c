// func cw_protocol_restore_ip @ 00572214 size=284

undefined4 cw_protocol_restore_ip(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_restore_ip",0x18c);
    }
  }
  else {
    cw_protocol_restore8(param_1,*param_2);
    if (*param_2 == 1) {
      uVar2 = 0xffffffff;
      iVar1 = cw_protocol_restore32(param_1,*(undefined4 *)(param_2 + 4));
      if (-1 < iVar1) {
        uVar2 = 5;
      }
    }
    else if (*param_2 == 2) {
      iVar1 = cw_protocol_restore_raw_bytes(param_1,param_2 + 4,0x10);
      uVar2 = 0xffffffff;
      if (-1 < iVar1) {
        uVar2 = 0x11;
      }
    }
    else {
      uVar2 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d illegal ip type:%d\n","cw_protocol_restore_ip",0x1a2,
               (uint)*param_2);
      }
    }
  }
  return uVar2;
}

