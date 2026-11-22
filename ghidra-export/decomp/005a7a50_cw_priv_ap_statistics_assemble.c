// func cw_priv_ap_statistics_assemble @ 005a7a50 size=1204

undefined4 cw_priv_ap_statistics_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  byte *pbVar7;
  int iVar8;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if ((((8 < *pbVar7) || (0x40 < pbVar7[1])) || (8 < pbVar7[4])) || (pbVar7[4] == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d Para is out of range[%u:%u:%u]\n","cw_priv_ap_statistics_assemble",
           0x155,(uint)*pbVar7,(uint)pbVar7[1],(uint)pbVar7[4]);
    return 0xffffffff;
  }
  if ((*pbVar7 == 0) || (*(int *)(pbVar7 + 0x2c) != 0)) {
    if ((pbVar7[1] == 0) || (*(int *)(pbVar7 + 0x30) != 0)) {
      cw_protocol_restore8(param_1);
      iVar5 = 0;
      cw_protocol_restore8(param_1,pbVar7[1]);
      cw_protocol_restore8(param_1,pbVar7[4]);
      cw_protocol_restore_raw_bytes(param_1,pbVar7 + 5,8);
      cw_protocol_restore8(param_1,pbVar7[0xd]);
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar7 + 0xe));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x10));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x14));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x18));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x1c));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x20));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x24));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar7 + 0x28));
      bVar4 = *pbVar7 != 0;
      if (*pbVar7 == 0) {
        bVar1 = pbVar7[1];
      }
      else {
        while (bVar4) {
          iVar8 = iVar5 * 0x20;
          iVar5 = iVar5 + 1;
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 1));
          cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 2));
          cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 4));
          cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 6));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 8));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 9));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 10));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0xb));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0xc));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x10));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x14));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x18));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x1c));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x1d));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x1e));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x2c) + iVar8 + 0x1f));
          bVar4 = iVar5 < (int)(uint)*pbVar7;
        }
        bVar1 = pbVar7[1];
      }
      iVar5 = 0;
      if (bVar1 == 0) {
        uVar3 = *(ushort *)(param_1 + 4);
      }
      else {
        for (; iVar8 = iVar5 * 0x1c, iVar5 < (int)(uint)pbVar7[1]; iVar5 = iVar5 + 1) {
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x30) + iVar8));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 1));
          cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar7 + 0x30) + iVar8 + 2,6);
          cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 8));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 10));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 0xb));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 0xc));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 0x10));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 0x14));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar7 + 0x30) + iVar8 + 0x18));
        }
        uVar3 = *(ushort *)(param_1 + 4);
      }
      if ((uint)uVar3 - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d ssid list is null\n";
    uVar6 = 0x160;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d radio list is null\n";
    uVar6 = 0x15b;
  }
  printf(__format,"cw_priv_ap_statistics_assemble",uVar6);
  return 0xffffffff;
}

