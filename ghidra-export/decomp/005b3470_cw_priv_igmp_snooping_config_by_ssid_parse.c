// func cw_priv_igmp_snooping_config_by_ssid_parse @ 005b3470 size=436

undefined4 cw_priv_igmp_snooping_config_by_ssid_parse(undefined4 param_1,int param_2)

{
  uint *__s;
  uint uVar1;
  void *__s_00;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  __s = (uint *)FUN_00408450(8,0x7d);
  if (__s == (uint *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_igmp_snooping_config_by_ssid_parse",
             0x80);
    }
  }
  else {
    memset(__s,0,8);
    uVar1 = cw_protocol_retrieve32(param_1);
    *__s = uVar1;
    if (uVar1 != 0) {
      __s_00 = (void *)FUN_00408450(uVar1 * 3,0x8b);
      __s[1] = (uint)__s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc ssid info list failed\n",
                 "cw_priv_igmp_snooping_config_by_ssid_parse",0x8e);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*__s * 3);
      uVar1 = *__s;
      for (uVar4 = 0; iVar5 = uVar4 * 3, uVar4 < uVar1; uVar4 = uVar4 + 1) {
        uVar1 = __s[1];
        uVar2 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar1 + iVar5) = uVar2;
        uVar1 = __s[1];
        uVar2 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar1 + iVar5 + 1) = uVar2;
        uVar1 = __s[1];
        uVar2 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar1 + iVar5 + 2) = uVar2;
        uVar1 = *__s;
      }
    }
    uVar3 = 0;
    *(uint **)(param_2 + 0x10) = __s;
  }
  return uVar3;
}

