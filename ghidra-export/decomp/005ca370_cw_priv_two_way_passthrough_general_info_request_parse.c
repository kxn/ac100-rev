// func cw_priv_two_way_passthrough_general_info_request_parse @ 005ca370 size=372

undefined4 cw_priv_two_way_passthrough_general_info_request_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar5;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0x10,0x78);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n",
             "cw_priv_two_way_passthrough_general_info_request_parse",0x7b);
    }
  }
  else {
    memset(__s,0,0x10);
    uVar5 = cw_protocol_retrieve8(param_1);
    *__s = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[2] = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[3] = uVar5;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 4) = uVar2;
    uVar3 = cw_protocol_retrieve32(param_1);
    *(uint *)(__s + 8) = uVar3;
    if (uVar3 != 0) {
      iVar4 = cw_protocol_retrieve_raw_bytes(param_1,uVar3 & 0xffff);
      *(int *)(__s + 0xc) = iVar4;
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read transport data\n",
                 "cw_priv_two_way_passthrough_general_info_request_parse",0x8d);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

