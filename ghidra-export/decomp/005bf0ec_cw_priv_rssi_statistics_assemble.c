// func cw_priv_rssi_statistics_assemble @ 005bf0ec size=416

undefined4 cw_priv_rssi_statistics_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  
  iVar5 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*(uint *)(iVar5 + 0x10) < 0x191) {
    if ((*(uint *)(iVar5 + 0x10) == 0) || (*(int *)(iVar5 + 0x14) != 0)) {
      cw_protocol_restore_raw_bytes(param_1,iVar5);
      cw_protocol_restore_raw_bytes(param_1,iVar5 + 8,8);
      uVar7 = 0;
      cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x10));
      bVar3 = *(int *)(iVar5 + 0x10) != 0;
      if (*(int *)(iVar5 + 0x10) == 0) {
        uVar2 = *(ushort *)(param_1 + 4);
      }
      else {
        while (iVar4 = uVar7 * 0xe, bVar3) {
          uVar7 = uVar7 + 1;
          cw_protocol_restore_raw_bytes(param_1,*(int *)(iVar5 + 0x14) + iVar4,6);
          cw_protocol_restore_raw_bytes(param_1,*(int *)(iVar5 + 0x14) + iVar4 + 6,8);
          bVar3 = uVar7 < *(uint *)(iVar5 + 0x10);
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
      if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(param_1,param_2,8), iVar5 != 0)) {
        printf("[CW_ERROR]%32s():%4d sta list is null\n","cw_priv_rssi_statistics_assemble",0xd6);
      }
    }
  }
  else {
    uVar6 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d Sta count is out of range[%u]\n",
             "cw_priv_rssi_statistics_assemble",0xd0,*(undefined4 *)(iVar5 + 0x10));
    }
  }
  return uVar6;
}

