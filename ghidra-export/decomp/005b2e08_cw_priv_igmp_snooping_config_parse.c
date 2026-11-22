// func cw_priv_igmp_snooping_config_parse @ 005b2e08 size=424

undefined4 cw_priv_igmp_snooping_config_parse(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined1 *__s;
  undefined1 uVar4;
  int iVar2;
  void *__s_00;
  undefined2 uVar3;
  int iVar5;
  undefined4 uVar6;
  
  __s = (undefined1 *)FUN_00408450(8,0x7d);
  if (__s == (undefined1 *)0x0) {
    uVar6 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_igmp_snooping_config_parse",0x80);
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
      __s_00 = (void *)FUN_00408450(iVar2 << 2,0x8d);
      *(void **)(__s + 4) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc radio info list failed\n",
                 "cw_priv_igmp_snooping_config_parse",0x90);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,(uint)(byte)__s[2] << 2);
      bVar1 = __s[2];
      for (iVar2 = 0; iVar2 < (int)(uint)bVar1; iVar2 = iVar2 + 1) {
        iVar5 = *(int *)(__s + 4);
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar5 + iVar2 * 4) = uVar4;
        iVar5 = *(int *)(__s + 4);
        uVar3 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(iVar5 + iVar2 * 4 + 2) = uVar3;
        bVar1 = __s[2];
      }
    }
    uVar6 = 0;
    *(undefined1 **)(param_2 + 0x10) = __s;
  }
  return uVar6;
}

