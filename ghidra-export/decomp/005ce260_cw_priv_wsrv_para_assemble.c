// func cw_priv_wsrv_para_assemble @ 005ce260 size=1176

undefined4 cw_priv_wsrv_para_assemble(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  
  pbVar13 = *(byte **)(param_2 + 0x10);
  uVar3 = *(ushort *)(param_1 + 4);
  if (0x1f < *pbVar13) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    uVar11 = (uint)*pbVar13;
    pcVar8 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar10 = 0x129;
LAB_005ce340:
    printf(pcVar8,"cw_priv_wsrv_para_assemble",uVar10,uVar11);
    return 0xffffffff;
  }
  cw_protocol_restore8();
  if (0x10 < pbVar13[1]) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    uVar11 = (uint)pbVar13[1];
    pcVar8 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar10 = 0x130;
    goto LAB_005ce340;
  }
  cw_protocol_restore8(param_1);
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar13 + 2));
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar13 + 4));
  cw_protocol_restore8(param_1,pbVar13[6]);
  cw_protocol_restore8(param_1,pbVar13[7]);
  cw_protocol_restore8(param_1,pbVar13[8]);
  switch(pbVar13[8]) {
  case 0:
    goto switchD_005ce420_caseD_0;
  case 1:
  case 4:
    puVar12 = *(undefined1 **)(pbVar13 + 9);
    if ((puVar12 == (undefined1 *)0x0) || (*(int *)(puVar12 + 8) == 0)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar7 = is_target_debug_ap();
      if (iVar7 == 0) {
        return 0xffffffff;
      }
      pcVar8 = "[CW_ERROR]%32s():%4d psk is null or psk\'s key is null\n";
      uVar10 = 0x147;
LAB_005ce628:
      printf(pcVar8,"cw_priv_wsrv_para_assemble",uVar10);
      return 0xffffffff;
    }
    cw_protocol_restore8(param_1,*puVar12);
    cw_protocol_restore8(param_1,puVar12[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar12 + 2));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar12 + 6));
    uVar10 = *(undefined4 *)(puVar12 + 8);
    uVar1 = puVar12[6];
    uVar2 = puVar12[7];
    break;
  case 2:
    puVar12 = *(undefined1 **)(pbVar13 + 9);
    if ((puVar12 == (undefined1 *)0x0) || (*(int *)(puVar12 + 0x1b) == 0)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar7 = is_target_debug_ap();
      if (iVar7 == 0) {
        return 0xffffffff;
      }
      pcVar8 = "[CW_ERROR]%32s():%4d wpa is null or wpa\'s key is null\n";
      uVar10 = 0x156;
      goto LAB_005ce628;
    }
    cw_protocol_restore8(param_1,*puVar12);
    cw_protocol_restore8(param_1,puVar12[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar12 + 2));
    uVar11 = *(uint *)(puVar12 + 7);
    cw_protocol_restore32(param_1,uVar11);
    if (puVar12[6] == '\0') {
      uVar1 = puVar12[0x13];
    }
    else {
      uVar5 = (uint)(puVar12 + 0xb) & 3;
      uVar6 = (uint)(puVar12 + 0xe) & 3;
      cw_protocol_restore32
                (param_1,(*(int *)(puVar12 + 0xb + -uVar5) << uVar5 * 8 |
                         uVar11 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar6 + 1) * 8 |
                         *(uint *)(puVar12 + 0xe + -uVar6) >> (3 - uVar6) * 8);
      cw_protocol_restore32(param_1,*(undefined4 *)(puVar12 + 0xf));
      uVar1 = puVar12[0x13];
    }
    cw_protocol_restore16(param_1,CONCAT11(uVar1,puVar12[0x14]));
    if (puVar12[6] == '\0') {
      uVar1 = puVar12[0x19];
    }
    else {
      cw_protocol_restore16(param_1,*(undefined2 *)(puVar12 + 0x15));
      cw_protocol_restore16(param_1,*(undefined2 *)(puVar12 + 0x17));
      uVar1 = puVar12[0x19];
    }
    cw_protocol_restore16(param_1,CONCAT11(uVar1,puVar12[0x1a]));
    uVar10 = *(undefined4 *)(puVar12 + 0x1b);
    uVar1 = puVar12[0x19];
    uVar2 = puVar12[0x1a];
    break;
  case 3:
    puVar12 = *(undefined1 **)(pbVar13 + 9);
    if (puVar12 == (undefined1 *)0x0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar7 = is_target_debug_ap();
      if (iVar7 == 0) {
        return 0xffffffff;
      }
      pcVar8 = "[CW_ERROR]%32s():%4d wep is null\n";
      uVar10 = 0x172;
      goto LAB_005ce628;
    }
    iVar7 = 0;
    cw_protocol_restore8(param_1,*puVar12);
    cw_protocol_restore8(param_1,puVar12[1]);
    uVar1 = puVar12[2];
    puVar14 = puVar12;
    while( true ) {
      cw_protocol_restore8(param_1,uVar1);
      iVar9 = iVar7 * 0x21;
      iVar7 = iVar7 + 1;
      cw_protocol_restore_raw_bytes(param_1,puVar12 + iVar9 + 3,0x20);
      if (iVar7 == 4) break;
      uVar1 = puVar14[0x23];
      puVar14 = puVar14 + 0x21;
    }
    uVar4 = *(ushort *)(param_1 + 4);
    goto LAB_005ce4ec;
  default:
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    uVar11 = (uint)pbVar13[8];
    pcVar8 = "[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n";
    uVar10 = 0x180;
    goto LAB_005ce340;
  }
  cw_protocol_restore_raw_bytes(param_1,uVar10,CONCAT11(uVar1,uVar2));
switchD_005ce420_caseD_0:
  uVar4 = *(ushort *)(param_1 + 4);
LAB_005ce4ec:
  uVar10 = 0xffffffff;
  if ((uint)uVar4 - (uint)uVar3 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar10 = 0;
  }
  return uVar10;
}

