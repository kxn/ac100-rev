// func cw_priv_portal_data_parse @ 005b8a4c size=312

undefined4 cw_priv_portal_data_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(8,0x70);
  if (__s == (undefined2 *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_portal_data_parse",0x73);
    }
  }
  else {
    memset(__s,0,8);
    iVar2 = cw_protocol_retrieve16(param_1);
    *__s = (short)iVar2;
    if (iVar2 != 0) {
      iVar2 = cw_protocol_retrieve_raw_bytes(param_1,iVar2);
      *(int *)(__s + 2) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to parse portal data\n","cw_priv_portal_data_parse",
                 0x7f);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(undefined2 **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

