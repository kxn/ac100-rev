// func cw_priv_mac_filter_parse @ 005b59bc size=380

undefined4 cw_priv_mac_filter_parse(int param_1,int param_2)

{
  ushort uVar1;
  int *__s;
  int iVar2;
  undefined1 uVar4;
  undefined2 uVar3;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0xffffffff;
  uVar1 = *(ushort *)(param_1 + 6);
  if (*(ushort *)(param_2 + 0xe) < 8) {
    return 0xffffffff;
  }
  __s = (int *)FUN_00408450(0xc,0x79);
  if (__s == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar5 = 0x7c;
LAB_005b5acc:
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_mac_filter_parse",uVar5);
  }
  else {
    memset(__s,0,0xc);
    iVar2 = cw_protocol_retrieve32(param_1);
    *__s = iVar2;
    uVar4 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)(__s + 1) = uVar4;
    uVar4 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)((int)__s + 5) = uVar4;
    uVar3 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)((int)__s + 6) = uVar3;
    if (*__s != 0) {
      iVar2 = cw_protocol_retrieve_raw_bytes
                        (param_1,(uint)(*(byte *)(__s + 1) >> 3) * *__s & 0xffff);
      __s[2] = iVar2;
      if (iVar2 == 0) {
        FUN_00407df0(__s);
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        uVar5 = 0x8d;
        goto LAB_005b5acc;
      }
    }
    *(int **)(param_2 + 0x10) = __s;
    uVar6 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar6 = 0;
    }
  }
  return uVar6;
}

