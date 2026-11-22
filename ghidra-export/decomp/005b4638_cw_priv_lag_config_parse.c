// func cw_priv_lag_config_parse @ 005b4638 size=336

undefined4 cw_priv_lag_config_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(8,0x71);
  if (__s == (undefined1 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_lag_config_parse",0x74);
    }
  }
  else {
    memset(__s,0,8);
    uVar4 = cw_protocol_retrieve8(param_1);
    *__s = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar4;
    iVar2 = cw_protocol_retrieve8(param_1);
    __s[2] = (char)iVar2;
    if (iVar2 != 0) {
      iVar2 = cw_protocol_retrieve_raw_bytes(param_1,iVar2);
      *(int *)(__s + 4) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to parse lag config\n","cw_priv_lag_config_parse",0x86
                );
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

