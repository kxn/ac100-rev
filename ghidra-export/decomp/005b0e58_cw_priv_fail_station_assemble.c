// func cw_priv_fail_station_assemble @ 005b0e58 size=456

undefined4 cw_priv_fail_station_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  
  puVar5 = *(uint **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*puVar5 < 0xc9) {
    if ((*puVar5 == 0) || (puVar5[1] != 0)) {
      cw_protocol_restore32(param_1);
      uVar7 = 0;
      uVar4 = *puVar5;
      if (uVar4 == 0) {
        uVar2 = *(ushort *)(param_1 + 4);
      }
      else {
        for (; iVar3 = uVar7 * 0x14, uVar7 < uVar4; uVar7 = uVar7 + 1) {
          cw_protocol_restore_raw_bytes(param_1,puVar5[1] + iVar3,6);
          cw_protocol_restore8(param_1,*(undefined1 *)(puVar5[1] + iVar3 + 6));
          cw_protocol_restore8(param_1,*(undefined1 *)(puVar5[1] + iVar3 + 7));
          cw_protocol_restore8(param_1,*(undefined1 *)(puVar5[1] + iVar3 + 8));
          cw_protocol_restore32(param_1,*(undefined4 *)(puVar5[1] + iVar3 + 0xc));
          cw_protocol_restore32(param_1,*(undefined4 *)(puVar5[1] + iVar3 + 0x10));
          uVar4 = *puVar5;
        }
        uVar2 = *(ushort *)(param_1 + 4);
      }
      uVar6 = 0xffffffff;
      if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d sta_list list is null\n","cw_priv_fail_station_assemble",0xd3);
      }
    }
  }
  else {
    uVar6 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_fail_station_assemble",0xcd,
             *puVar5);
    }
  }
  return uVar6;
}

