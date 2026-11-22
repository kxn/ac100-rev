// func cw_priv_igmp_snooping_group_policy_parse @ 005b3b3c size=452

undefined4 cw_priv_igmp_snooping_group_policy_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint *__s;
  uint uVar3;
  undefined4 uVar4;
  void *__s_00;
  undefined1 uVar6;
  int iVar5;
  uint uVar7;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (uint *)FUN_00408450(8,0x8d);
  if (__s == (uint *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_igmp_snooping_group_policy_parse",0x90)
      ;
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
      __s_00 = (void *)FUN_00408450(uVar3 * 0x18,0x9a);
      __s[1] = (uint)__s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc ip info list failed\n",
                 "cw_priv_igmp_snooping_group_policy_parse",0x9d);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,*__s * 0x18);
      uVar3 = *__s;
      for (uVar7 = 0; uVar7 < uVar3; uVar7 = uVar7 + 1) {
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + uVar7 * 0x18) = uVar6;
        cw_protocol_retrieve_ip(param_1,__s[1] + uVar7 * 0x18 + 4);
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

