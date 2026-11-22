// func cw_priv_wechat_iplist_parse @ 005cb378 size=312

undefined4 cw_priv_wechat_iplist_parse(int param_1,int param_2)

{
  ushort uVar1;
  uint *__s;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (uint *)FUN_00408450(8,0x76);
  if (__s == (uint *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wechat_iplist_parse",0x79);
    }
  }
  else {
    memset(__s,0,8);
    uVar2 = cw_protocol_retrieve32(param_1);
    *__s = uVar2;
    if (uVar2 != 0) {
      uVar2 = cw_protocol_retrieve_raw_bytes(param_1,uVar2 & 0xffff);
      __s[1] = uVar2;
      if (uVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to parse white ip list\n",
                 "cw_priv_wechat_iplist_parse",0x85);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(uint **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

