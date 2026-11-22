// func cw_priv_ap_statistics_parse @ 005a7f04 size=1420

undefined4 cw_priv_ap_statistics_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  byte bVar7;
  uint uVar3;
  undefined2 uVar6;
  undefined4 uVar4;
  int iVar5;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x34,0xd6);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_statistics_parse",0xd9);
    return 0xffffffff;
  }
  memset(__s,0,0x34);
  bVar7 = cw_protocol_retrieve8(param_1);
  *__s = bVar7;
  uVar3 = cw_protocol_retrieve8(param_1);
  __s[1] = (byte)uVar3;
  if ((*__s < 9) && (uVar3 < 0x41)) {
    bVar7 = cw_protocol_retrieve8(param_1);
    __s[4] = bVar7;
    cw_protocol_retrieve_bytes(param_1,__s + 5,8);
    if ((byte)(__s[4] - 1) < 8) {
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[0xd] = bVar7;
      uVar6 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0xe) = uVar6;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x10) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x14) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x18) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x1c) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x20) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x24) = uVar4;
      uVar4 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 0x28) = uVar4;
      if (*__s == 0) {
        bVar7 = __s[1];
      }
      else {
        iVar10 = 0;
        iVar5 = FUN_00408450((uint)*__s << 5,0x100);
        *(int *)(__s + 0x2c) = iVar5;
        if (iVar5 == 0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_statistics_parse",0x103);
          }
          goto LAB_005a837c;
        }
        for (; iVar10 < (int)(uint)*__s; iVar10 = iVar10 + 1) {
          iVar5 = *(int *)(__s + 0x2c);
          iVar9 = iVar10 * 0x20;
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 1) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar6 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar5 + iVar9 + 2) = uVar6;
          iVar5 = *(int *)(__s + 0x2c);
          uVar6 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar5 + iVar9 + 4) = uVar6;
          iVar5 = *(int *)(__s + 0x2c);
          uVar6 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar5 + iVar9 + 6) = uVar6;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 8) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 9) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 10) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 0xb) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar5 + iVar9 + 0xc) = uVar4;
          iVar5 = *(int *)(__s + 0x2c);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar5 + iVar9 + 0x10) = uVar4;
          iVar5 = *(int *)(__s + 0x2c);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar5 + iVar9 + 0x14) = uVar4;
          iVar5 = *(int *)(__s + 0x2c);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar5 + iVar9 + 0x18) = uVar4;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 0x1c) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 0x1d) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 0x1e) = uVar8;
          iVar5 = *(int *)(__s + 0x2c);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar5 + iVar9 + 0x1f) = uVar8;
        }
        bVar7 = __s[1];
      }
      if (bVar7 == 0) {
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      else {
        iVar10 = 0;
        iVar5 = FUN_00408450((uint)bVar7 * 0x1c,0x122);
        *(int *)(__s + 0x30) = iVar5;
        if (iVar5 == 0) {
          if (capwap_err_switch == 0) {
            iVar5 = *(int *)(__s + 0x2c);
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              iVar5 = *(int *)(__s + 0x2c);
            }
            else {
              printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_statistics_parse",0x125);
              iVar5 = *(int *)(__s + 0x2c);
            }
          }
          if (iVar5 != 0) {
            FUN_00407df0();
          }
          goto LAB_005a837c;
        }
        for (; iVar5 = iVar10 * 0x1c, iVar10 < (int)(uint)__s[1]; iVar10 = iVar10 + 1) {
          iVar9 = *(int *)(__s + 0x30);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar9 + iVar5) = uVar8;
          iVar9 = *(int *)(__s + 0x30);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar9 + iVar5 + 1) = uVar8;
          cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 0x30) + iVar5 + 2,6);
          iVar9 = *(int *)(__s + 0x30);
          uVar6 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(iVar9 + iVar5 + 8) = uVar6;
          iVar9 = *(int *)(__s + 0x30);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar9 + iVar5 + 10) = uVar8;
          iVar9 = *(int *)(__s + 0x30);
          uVar8 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar9 + iVar5 + 0xb) = uVar8;
          iVar9 = *(int *)(__s + 0x30);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar9 + iVar5 + 0xc) = uVar4;
          iVar9 = *(int *)(__s + 0x30);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar9 + iVar5 + 0x10) = uVar4;
          iVar9 = *(int *)(__s + 0x30);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar9 + iVar5 + 0x14) = uVar4;
          iVar9 = *(int *)(__s + 0x30);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar9 + iVar5 + 0x18) = uVar4;
        }
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)uVar2) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_ap_statistics_parse",0xef,
             (uint)__s[4]);
    }
  }
  else if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[CW_ERROR]%32s():%4d Para is out of range[%u:%u]\n","cw_priv_ap_statistics_parse",0xe5,
           (uint)*__s,(uint)__s[1]);
  }
LAB_005a837c:
  FUN_00407df0(__s);
  return 0xffffffff;
}

