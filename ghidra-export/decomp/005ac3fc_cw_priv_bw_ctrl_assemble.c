// func cw_priv_bw_ctrl_assemble @ 005ac3fc size=624

undefined4 cw_priv_bw_ctrl_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  puVar6 = *(uint **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if ((puVar6 == (uint *)0x0) || (puVar6[3] == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d ctrl_val is null.\n","cw_priv_bw_ctrl_assemble",0xe3);
    return 0xffffffff;
  }
  if (*(byte *)puVar6 < 5) {
    cw_protocol_restore8();
    cw_protocol_restore32(param_1,puVar6[1]);
    cw_protocol_restore32(param_1,puVar6[2]);
    bVar1 = *(byte *)puVar6;
    puVar6 = (uint *)puVar6[3];
    if (bVar1 == 0) {
      uVar4 = *puVar6;
    }
    else {
      if (bVar1 != 4) {
        if (*(byte *)puVar6 < 0x20) {
          if (0x10 < *(byte *)((int)puVar6 + 1)) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              return 0xffffffff;
            }
            bVar1 = *(byte *)((int)puVar6 + 1);
            __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
            uVar5 = 0x10e;
            goto LAB_005ac558;
          }
          cw_protocol_restore8(param_1);
          cw_protocol_restore8(param_1,*(byte *)((int)puVar6 + 1));
          uVar4 = (uint)*(ushort *)(param_1 + 4);
          goto LAB_005ac618;
        }
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
        uVar5 = 0x108;
        goto LAB_005ac554;
      }
      uVar4 = *puVar6;
    }
    if (0x80 < uVar4) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d mac_num(%d) is too big, shouldn\'t bigger then %d\n",
             "cw_priv_bw_ctrl_assemble",0xf7,*puVar6,0x80);
      return 0xffffffff;
    }
    cw_protocol_restore32(param_1);
    if (*puVar6 == 0) {
      uVar4 = (uint)*(ushort *)(param_1 + 4);
    }
    else {
      cw_protocol_restore_raw_bytes(param_1,puVar6 + 1,*puVar6 * 6 & 0xfffe);
      uVar4 = (uint)*(ushort *)(param_1 + 4);
    }
LAB_005ac618:
    uVar5 = 0xffffffff;
    if (uVar4 - uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar5 = 0;
    }
    return uVar5;
  }
  if (capwap_err_switch == 0) {
    return 0xffffffff;
  }
  iVar3 = is_target_debug_ap();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  __format = "[CW_ERROR]%32s():%4d bw_type(%d) is wrong\n";
  uVar5 = 0xe9;
LAB_005ac554:
  bVar1 = *(byte *)puVar6;
LAB_005ac558:
  printf(__format,"cw_priv_bw_ctrl_assemble",uVar5,(uint)bVar1);
  return 0xffffffff;
}

