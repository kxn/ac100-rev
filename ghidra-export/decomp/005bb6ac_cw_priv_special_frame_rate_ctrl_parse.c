// func cw_priv_special_frame_rate_ctrl_parse @ 005bb6ac size=616

undefined4 cw_priv_special_frame_rate_ctrl_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  byte bVar5;
  void *__s_00;
  undefined2 uVar4;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x71);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_special_frame_rate_ctrl_parse",0x74);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar3;
    if (uVar3 < 0x11) {
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[2] = bVar5;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[3] = bVar5;
      if (__s[2] == 0) {
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      else {
        __s_00 = (void *)FUN_00408450((uint)__s[2] << 2,0x8d);
        *(void **)(__s + 4) = __s_00;
        if (__s_00 == (void *)0x0) {
          if ((capwap_err_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to malloc frame info\n",
                   "cw_priv_special_frame_rate_ctrl_parse",0x90);
          }
          goto LAB_005bb860;
        }
        memset(__s_00,0,(uint)__s[2] << 2);
        bVar5 = __s[2];
        for (iVar8 = 0; iVar8 < (int)(uint)bVar5; iVar8 = iVar8 + 1) {
          iVar7 = *(int *)(__s + 4);
          uVar4 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar7 + iVar8 * 4) = uVar4;
          iVar7 = *(int *)(__s + 4);
          uVar4 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar7 + iVar8 * 4 + 2) = uVar4;
          bVar5 = __s[2];
        }
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)uVar2) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar8 = is_target_debug_ap(), iVar8 == 0)) goto LAB_005bb860;
    bVar5 = __s[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar6 = 0x84;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar8 = is_target_debug_ap(), iVar8 == 0)) goto LAB_005bb860;
    bVar5 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x7d;
  }
  printf(__format,"cw_priv_special_frame_rate_ctrl_parse",uVar6,(uint)bVar5);
LAB_005bb860:
  FUN_00407df0(__s);
  return 0xffffffff;
}

