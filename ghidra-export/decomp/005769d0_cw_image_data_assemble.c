// func cw_image_data_assemble @ 005769d0 size=488

undefined4 cw_image_data_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*pbVar5 - 1 < 2) || (*pbVar5 == 5)) {
    cw_protocol_restore8(param_1);
    uVar4 = (uint)*(ushort *)(pbVar5 + 2);
    if (*pbVar5 == 5) {
      if (uVar4 != 0) goto LAB_00576a74;
    }
    else if (uVar4 == 0) {
LAB_00576a74:
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d length of data(%d) doesn\'t match type(%d)\n",
               "cw_image_data_assemble",0xb7,(uint)*(ushort *)(pbVar5 + 2),(uint)*pbVar5);
      }
      return 0xffffffff;
    }
    if ((uVar4 < 0x401) && (*(ushort *)(param_2 + 0xe) - 1 == uVar4)) {
      if (uVar4 == 0) {
        if (*(int *)(pbVar5 + 4) != 0) goto LAB_00576b7c;
      }
      else {
        if (*(int *)(pbVar5 + 4) == 0) {
LAB_00576b7c:
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          printf("[CW_ERROR]%32s():%4d length of data doesn\'t match data\n",
                 "cw_image_data_assemble",0xc5);
          return 0xffffffff;
        }
        cw_protocol_restore_raw_bytes(param_1);
      }
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar4 = (uint)*(ushort *)(pbVar5 + 2);
    __format = "[CW_ERROR]%32s():%4d length of data(%d) is wrong\n";
    uVar3 = 0xbe;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar4 = (uint)*pbVar5;
    __format = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
    uVar3 = 0xaf;
  }
  printf(__format,"cw_image_data_assemble",uVar3,uVar4);
  return 0xffffffff;
}

