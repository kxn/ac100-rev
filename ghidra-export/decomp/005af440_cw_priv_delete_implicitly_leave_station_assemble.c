// func cw_priv_delete_implicitly_leave_station_assemble @ 005af440 size=380

undefined4 cw_priv_delete_implicitly_leave_station_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*pbVar5 < 0x20) {
    cw_protocol_restore8();
    if ((pbVar5[1] == 6) || (pbVar5[1] == 8)) {
      cw_protocol_restore8(param_1);
      if ((*(int *)(pbVar5 + 4) != 0) && (*(ushort *)(param_2 + 0xe) - 2 == (uint)pbVar5[1])) {
        cw_protocol_restore_raw_bytes(param_1);
        if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d failed to write mac address\n",
             "cw_priv_delete_implicitly_leave_station_assemble",0xb5);
      return 0xffffffff;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = pbVar5[1];
    __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
    uVar4 = 0xad;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *pbVar5;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0xa5;
  }
  printf(__format,"cw_priv_delete_implicitly_leave_station_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

