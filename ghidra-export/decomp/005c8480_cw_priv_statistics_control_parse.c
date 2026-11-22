// func cw_priv_statistics_control_parse @ 005c8480 size=272

undefined4 cw_priv_statistics_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar5;
  undefined2 uVar4;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(10,0x79);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_statistics_control_parse",0x7c);
    }
  }
  else {
    memset(__s,0,10);
    uVar5 = cw_protocol_retrieve8(param_1);
    *__s = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[1] = uVar5;
    uVar5 = cw_protocol_retrieve8(param_1);
    __s[2] = uVar5;
    uVar4 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(__s + 4) = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(__s + 6) = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(__s + 8) = uVar4;
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

