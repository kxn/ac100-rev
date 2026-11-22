// func cw_priv_sta_list_parse @ 005c6c28 size=580

undefined4 cw_priv_sta_list_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte *__s;
  uint uVar4;
  int iVar5;
  void *__s_00;
  char *__format;
  undefined4 uVar6;
  uint uVar7;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0xc,0x71);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_list_parse",0x74);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar4 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar4;
  if (uVar4 < 0x20) {
    uVar4 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar4;
    if (uVar4 < 0x11) {
      iVar5 = cw_protocol_retrieve32(param_1);
      *(int *)(__s + 4) = iVar5;
      if (iVar5 == 0) {
        uVar3 = *(ushort *)(param_2 + 0xe);
      }
      else {
        __s_00 = (void *)FUN_00408450(iVar5 * 6,0x8d);
        *(void **)(__s + 8) = __s_00;
        if (__s_00 == (void *)0x0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to malloc sta mac list\n","cw_priv_sta_list_parse",
                   0x90);
          }
          goto LAB_005c6db8;
        }
        memset(__s_00,0,*(int *)(__s + 4) * 6);
        uVar4 = *(uint *)(__s + 4);
        for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
          cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + uVar7 * 6,6);
          uVar4 = *(uint *)(__s + 4);
        }
        uVar3 = *(ushort *)(param_2 + 0xe);
      }
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)uVar3) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_005c6db8;
    bVar1 = __s[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar6 = 0x84;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_005c6db8;
    bVar1 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x7d;
  }
  printf(__format,"cw_priv_sta_list_parse",uVar6,(uint)bVar1);
LAB_005c6db8:
  FUN_00407df0(__s);
  return 0xffffffff;
}

