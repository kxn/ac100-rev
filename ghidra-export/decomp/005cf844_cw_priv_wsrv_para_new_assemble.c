// func cw_priv_wsrv_para_new_assemble @ 005cf844 size=1132

undefined4 cw_priv_wsrv_para_new_assemble(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  undefined1 *puVar12;
  
  pbVar11 = *(byte **)(param_2 + 0x10);
  uVar3 = *(ushort *)(param_1 + 4);
  if (0x1f < *pbVar11) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    uVar9 = (uint)*pbVar11;
    pcVar6 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar8 = 0x122;
LAB_005cf924:
    printf(pcVar6,"cw_priv_wsrv_para_new_assemble",uVar8,uVar9);
    return 0xffffffff;
  }
  cw_protocol_restore8();
  if (0x10 < pbVar11[1]) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    uVar9 = (uint)pbVar11[1];
    pcVar6 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar8 = 0x129;
    goto LAB_005cf924;
  }
  cw_protocol_restore8(param_1);
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar11 + 2));
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar11 + 4));
  cw_protocol_restore8(param_1,pbVar11[6]);
  cw_protocol_restore8(param_1,pbVar11[7]);
  cw_protocol_restore8(param_1,pbVar11[8]);
  switch(pbVar11[8]) {
  case 0:
    goto switchD_005cfa04_caseD_0;
  case 1:
  case 4:
    puVar10 = *(undefined1 **)(pbVar11 + 9);
    if ((puVar10 == (undefined1 *)0x0) || (*(int *)(puVar10 + 8) == 0)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_ERROR]%32s():%4d psk is null or psk\'s key is null\n";
      uVar8 = 0x140;
LAB_005cfc38:
      printf(pcVar6,"cw_priv_wsrv_para_new_assemble",uVar8);
      return 0xffffffff;
    }
    cw_protocol_restore8(param_1,*puVar10);
    cw_protocol_restore8(param_1,puVar10[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar10 + 2));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar10 + 6));
    uVar8 = *(undefined4 *)(puVar10 + 8);
    uVar1 = puVar10[6];
    uVar2 = puVar10[7];
    break;
  case 2:
    puVar10 = *(undefined1 **)(pbVar11 + 9);
    if ((puVar10 == (undefined1 *)0x0) || (*(int *)(puVar10 + 0x4a) == 0)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_ERROR]%32s():%4d wpa is null or wpa\'s key is null\n";
      uVar8 = 0x14f;
      goto LAB_005cfc38;
    }
    cw_protocol_restore8(param_1,*puVar10);
    cw_protocol_restore8(param_1,puVar10[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar10 + 2));
    cw_protocol_restore_ip(param_1,puVar10 + 6);
    cw_protocol_restore_ip(param_1,puVar10 + 0x1a);
    cw_protocol_restore_ip(param_1,puVar10 + 0x2e);
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar10 + 0x42));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar10 + 0x44));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar10 + 0x46));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar10 + 0x48));
    uVar8 = *(undefined4 *)(puVar10 + 0x4a);
    uVar1 = puVar10[0x48];
    uVar2 = puVar10[0x49];
    break;
  case 3:
    puVar10 = *(undefined1 **)(pbVar11 + 9);
    if (puVar10 == (undefined1 *)0x0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_ERROR]%32s():%4d wep is null\n";
      uVar8 = 0x167;
      goto LAB_005cfc38;
    }
    iVar5 = 0;
    cw_protocol_restore8(param_1,*puVar10);
    cw_protocol_restore8(param_1,puVar10[1]);
    uVar1 = puVar10[2];
    puVar12 = puVar10;
    while( true ) {
      cw_protocol_restore8(param_1,uVar1);
      iVar7 = iVar5 * 0x21;
      iVar5 = iVar5 + 1;
      cw_protocol_restore_raw_bytes(param_1,puVar10 + iVar7 + 3,0x20);
      if (iVar5 == 4) break;
      uVar1 = puVar12[0x23];
      puVar12 = puVar12 + 0x21;
    }
    uVar4 = *(ushort *)(param_1 + 4);
    goto LAB_005cfafc;
  default:
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    uVar9 = (uint)pbVar11[8];
    pcVar6 = "[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n";
    uVar8 = 0x175;
    goto LAB_005cf924;
  }
  cw_protocol_restore_raw_bytes(param_1,uVar8,CONCAT11(uVar1,uVar2));
switchD_005cfa04_caseD_0:
  uVar4 = *(ushort *)(param_1 + 4);
LAB_005cfafc:
  uVar8 = 0xffffffff;
  if ((uint)uVar4 - (uint)uVar3 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar8 = 0;
  }
  return uVar8;
}

