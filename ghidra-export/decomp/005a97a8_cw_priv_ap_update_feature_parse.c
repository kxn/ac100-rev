// func cw_priv_ap_update_feature_parse @ 005a97a8 size=300

undefined4 cw_priv_ap_update_feature_parse(int param_1,int param_2)

{
  ushort uVar1;
  uint *__s;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (uint *)FUN_00408450(8,0x74);
  if (__s == (uint *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_update_feature_parse",0x77);
    }
  }
  else {
    memset(__s,0,8);
    uVar6 = cw_protocol_retrieve64(param_1);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar5 = (uint)uVar6;
    __s[1] = uVar2 << 0x18 | uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8;
    *__s = uVar5 << 0x18 | uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8;
    *(uint **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

