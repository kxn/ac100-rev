// func cw_priv_tdcp_passthrough_send_info_parse @ 0057f1a0 size=524

undefined4 cw_priv_tdcp_passthrough_send_info_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  undefined1 uVar4;
  void *__s_00;
  int iVar3;
  char *__format;
  uint uVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0x10,0x76);
  if (__s == (undefined4 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_tdcp_passthrough_send_info_parse",0x79);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar2 = cw_protocol_retrieve32(param_1);
  *__s = uVar2;
  uVar2 = cw_protocol_retrieve32(param_1);
  __s[1] = uVar2;
  uVar4 = cw_protocol_retrieve8(param_1);
  *(undefined1 *)(__s + 2) = uVar4;
  if (__s[1] - 1 < 0xff80) {
    __s_00 = (void *)FUN_00408450(__s[1] + 1,0x8b);
    __s[3] = __s_00;
    if (__s_00 != (void *)0x0) {
      memset(__s_00,0,__s[1] + 1);
      cw_protocol_retrieve_bytes(param_1,__s[3],*(undefined2 *)((int)__s + 6));
      *(undefined4 **)(param_2 + 0x10) = __s;
      if (capwap_debug_switch == 0) {
        uVar5 = (uint)*(ushort *)(param_1 + 6);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          uVar5 = (uint)*(ushort *)(param_1 + 6);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d offset:%d old_offset:%d len:%d\n",
                 "cw_priv_tdcp_passthrough_send_info_parse",0x97,(uint)*(ushort *)(param_1 + 6),
                 (uint)uVar1,(uint)*(ushort *)(param_2 + 0xe));
          uVar5 = (uint)*(ushort *)(param_1 + 6);
        }
      }
      if (uVar5 - uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0057f338;
    __format = "[CW_ERROR]%32s():%4d malloc data failed len:%d\n";
    uVar2 = 0x8e;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0057f338;
    __format = "[CW_ERROR]%32s():%4d len:%d error\n";
    uVar2 = 0x85;
  }
  printf(__format,"cw_priv_tdcp_passthrough_send_info_parse",uVar2,__s[1]);
LAB_0057f338:
  FUN_00407df0(__s);
  return 0xffffffff;
}

