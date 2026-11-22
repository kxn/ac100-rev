// func cw_priv_config_extension_parse @ 005bf8c4 size=328

undefined4 cw_priv_config_extension_parse(undefined4 param_1,int param_2)

{
  undefined1 *__s;
  undefined1 uVar2;
  int iVar1;
  void *__s_00;
  undefined4 uVar3;
  
  __s = (undefined1 *)FUN_00408450(0xc,0x6e);
  if (__s == (undefined1 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_config_extension_parse",0x71);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar2 = cw_protocol_retrieve8(param_1);
    *__s = uVar2;
    iVar1 = cw_protocol_retrieve32(param_1);
    *(int *)(__s + 4) = iVar1;
    if (iVar1 == 0) {
      *(undefined1 **)(param_2 + 0x10) = __s;
    }
    else {
      __s_00 = (void *)FUN_00408450(iVar1,0x7d);
      *(void **)(__s + 8) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc mac info list failed\n",
                 "cw_priv_config_extension_parse",0x80);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*(size_t *)(__s + 4));
      cw_protocol_retrieve_bytes(param_1,*(undefined4 *)(__s + 8),*(undefined2 *)(__s + 6));
      *(undefined1 **)(param_2 + 0x10) = __s;
    }
    uVar3 = 0;
  }
  return uVar3;
}

