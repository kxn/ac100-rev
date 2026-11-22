// func cw_priv_wlan_list_assemble @ 005cb8fc size=300

undefined4 cw_priv_wlan_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar5 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar5);
  cw_protocol_restore32(param_1,puVar5[1]);
  if (puVar5[1] == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    uVar6 = 0;
    if (puVar5[2] == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d wlan mac list should not be NULL\n","cw_priv_wlan_list_assemble",
             0xbb);
      return 0xffffffff;
    }
    for (; uVar6 < (uint)puVar5[1]; uVar6 = uVar6 + 1) {
      cw_protocol_restore8(param_1,*(undefined1 *)(puVar5[2] + uVar6 * 0x21));
      cw_protocol_restore_raw_bytes(param_1,puVar5[2] + uVar6 * 0x21 + 1,0x20);
    }
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar4 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar4 = 0;
  }
  return uVar4;
}

