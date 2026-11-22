// func cw_priv_trans_data_request_parse @ 005c9cbc size=336

undefined4 cw_priv_trans_data_request_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  undefined2 uVar4;
  undefined4 uVar2;
  int iVar3;
  uint uVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(0xc,0x70);
  if (__s == (undefined2 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_trans_data_request_parse",0x73);
    }
  }
  else {
    memset(__s,0,0xc);
    uVar4 = cw_protocol_retrieve16(param_1);
    *__s = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[1] = uVar4;
    uVar5 = *(ushort *)(param_2 + 0xe) - 4;
    *(uint *)(__s + 2) = uVar5;
    if (uVar5 != 0) {
      iVar3 = cw_protocol_retrieve_raw_bytes(param_1,uVar5 & 0xffff);
      *(int *)(__s + 4) = iVar3;
      if (iVar3 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read transport data\n",
                 "cw_priv_trans_data_request_parse",0x81);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(undefined2 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

