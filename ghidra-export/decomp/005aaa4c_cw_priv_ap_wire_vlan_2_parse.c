// func cw_priv_ap_wire_vlan_2_parse @ 005aaa4c size=248

undefined4 cw_priv_ap_wire_vlan_2_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  undefined2 uVar3;
  undefined4 uVar2;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(8,0x71);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_wire_vlan_2_parse",0x74);
    }
  }
  else {
    iVar5 = 0;
    memset(__s,0,8);
    do {
      uVar3 = cw_protocol_retrieve16(param_1);
      puVar4 = (undefined2 *)((int)__s + iVar5);
      iVar5 = iVar5 + 2;
      *puVar4 = uVar3;
    } while (iVar5 != 8);
    *(void **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

