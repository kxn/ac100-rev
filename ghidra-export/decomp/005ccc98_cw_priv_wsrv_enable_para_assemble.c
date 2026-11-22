// func cw_priv_wsrv_enable_para_assemble @ 005ccc98 size=1212

undefined4 cw_priv_wsrv_enable_para_assemble(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  
  pbVar13 = *(byte **)(param_2 + 0x10);
  uVar4 = *(ushort *)(param_1 + 4);
  if (0x1f < *pbVar13) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    uVar12 = (uint)*pbVar13;
    pcVar9 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar11 = 0x10d;
LAB_005ccd78:
    printf(pcVar9,"cw_priv_wsrv_enable_para_assemble",uVar11,uVar12);
    return 0xffffffff;
  }
  cw_protocol_restore8();
  if (0x10 < pbVar13[1]) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    uVar12 = (uint)pbVar13[1];
    pcVar9 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar11 = 0x114;
    goto LAB_005ccd78;
  }
  cw_protocol_restore8(param_1);
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar13 + 2));
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar13 + 4));
  cw_protocol_restore8(param_1,pbVar13[6]);
  cw_protocol_restore8(param_1,pbVar13[7]);
  uVar12 = (uint)*(ushort *)(pbVar13 + 8);
  cw_protocol_restore16(param_1,uVar12);
  if (*(short *)(pbVar13 + 8) == 0) {
    bVar3 = pbVar13[0xe];
  }
  else {
    uVar6 = (uint)(pbVar13 + 10) & 3;
    uVar7 = (uint)(pbVar13 + 0xd) & 3;
    cw_protocol_restore_raw_bytes
              (param_1,(*(int *)(pbVar13 + 10 + -uVar6) << uVar6 * 8 |
                       uVar12 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar7 + 1) * 8 |
                       *(uint *)(pbVar13 + 0xd + -uVar7) >> (3 - uVar7) * 8);
    bVar3 = pbVar13[0xe];
  }
  cw_protocol_restore8(param_1,bVar3);
  cw_protocol_restore8(param_1,pbVar13[0xf]);
  switch(pbVar13[0xf]) {
  case 0:
    goto switchD_005cce94_caseD_0;
  case 1:
  case 4:
    puVar14 = *(undefined1 **)(pbVar13 + 0x10);
    if ((puVar14 == (undefined1 *)0x0) || (*(int *)(puVar14 + 8) == 0)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar8 = is_target_debug_ap();
      if (iVar8 == 0) {
        return 0xffffffff;
      }
      pcVar9 = "[CW_ERROR]%32s():%4d psk is null or psk\'s key is null\n";
      uVar11 = 0x131;
LAB_005cd0dc:
      printf(pcVar9,"cw_priv_wsrv_enable_para_assemble",uVar11);
      return 0xffffffff;
    }
    cw_protocol_restore8(param_1,*puVar14);
    cw_protocol_restore8(param_1,puVar14[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar14 + 2));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar14 + 6));
    uVar11 = *(undefined4 *)(puVar14 + 8);
    uVar1 = puVar14[6];
    uVar2 = puVar14[7];
    break;
  case 2:
    puVar14 = *(undefined1 **)(pbVar13 + 0x10);
    if ((puVar14 == (undefined1 *)0x0) || (*(int *)(puVar14 + 0x4a) == 0)) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar8 = is_target_debug_ap();
      if (iVar8 == 0) {
        return 0xffffffff;
      }
      pcVar9 = "[CW_ERROR]%32s():%4d wpa is null or wpa\'s key is null\n";
      uVar11 = 0x140;
      goto LAB_005cd0dc;
    }
    cw_protocol_restore8(param_1,*puVar14);
    cw_protocol_restore8(param_1,puVar14[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar14 + 2));
    cw_protocol_restore_ip(param_1,puVar14 + 6);
    cw_protocol_restore_ip(param_1,puVar14 + 0x1a);
    cw_protocol_restore_ip(param_1,puVar14 + 0x2e);
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar14 + 0x42));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar14 + 0x44));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar14 + 0x46));
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar14 + 0x48));
    uVar11 = *(undefined4 *)(puVar14 + 0x4a);
    uVar1 = puVar14[0x48];
    uVar2 = puVar14[0x49];
    break;
  case 3:
    puVar14 = *(undefined1 **)(pbVar13 + 0x10);
    if (puVar14 == (undefined1 *)0x0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar8 = is_target_debug_ap();
      if (iVar8 == 0) {
        return 0xffffffff;
      }
      pcVar9 = "[CW_ERROR]%32s():%4d wep is null\n";
      uVar11 = 0x158;
      goto LAB_005cd0dc;
    }
    iVar8 = 0;
    cw_protocol_restore8(param_1,*puVar14);
    cw_protocol_restore8(param_1,puVar14[1]);
    uVar1 = puVar14[2];
    puVar15 = puVar14;
    while( true ) {
      cw_protocol_restore8(param_1,uVar1);
      iVar10 = iVar8 * 0x21;
      iVar8 = iVar8 + 1;
      cw_protocol_restore_raw_bytes(param_1,puVar14 + iVar10 + 3,0x20);
      if (iVar8 == 4) break;
      uVar1 = puVar15[0x23];
      puVar15 = puVar15 + 0x21;
    }
    uVar5 = *(ushort *)(param_1 + 4);
    goto LAB_005ccf8c;
  default:
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    uVar12 = (uint)pbVar13[0xf];
    pcVar9 = "[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n";
    uVar11 = 0x166;
    goto LAB_005ccd78;
  }
  cw_protocol_restore_raw_bytes(param_1,uVar11,CONCAT11(uVar1,uVar2));
switchD_005cce94_caseD_0:
  uVar5 = *(ushort *)(param_1 + 4);
LAB_005ccf8c:
  uVar11 = 0xffffffff;
  if ((uint)uVar5 - (uint)uVar4 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar11 = 0;
  }
  return uVar11;
}

