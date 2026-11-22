// func cw_priv_sta_ip_list_parse @ 005c64f4 size=444

undefined4 cw_priv_sta_ip_list_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint *__s;
  uint uVar3;
  undefined4 uVar4;
  void *__s_00;
  int iVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (uint *)FUN_00408450(8,0x8f);
  if (__s == (uint *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_ip_list_parse",0x92);
    }
  }
  else {
    memset(__s,0,8);
    uVar3 = cw_protocol_retrieve32(param_1);
    *__s = uVar3;
    if (uVar3 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(uVar3 * 0x1c,0x9c);
      __s[1] = (uint)__s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc wlan info list failed\n","cw_priv_sta_ip_list_parse",
                 0x9f);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*__s * 0x1c);
      uVar3 = *__s;
      for (uVar6 = 0; uVar6 < uVar3; uVar6 = uVar6 + 1) {
        cw_protocol_retrieve_bytes(param_1,__s[1] + uVar6 * 0x1c,6);
        cw_protocol_retrieve_ip(param_1,__s[1] + uVar6 * 0x1c + 8);
        uVar3 = *__s;
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(uint **)(param_2 + 0x10) = __s;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

