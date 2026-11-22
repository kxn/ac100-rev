// func cw_wtp_reboot_statistics_parse @ 00586a00 size=392

undefined4 cw_wtp_reboot_statistics_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  undefined2 uVar4;
  char cVar5;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(0x10,0x7f);
  if (__s == (undefined2 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_wtp_reboot_statistics_parse",0x82);
    }
  }
  else {
    memset(__s,0,0x10);
    uVar4 = cw_protocol_retrieve16(param_1);
    *__s = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[1] = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[2] = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[3] = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[4] = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[5] = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[6] = uVar4;
    cVar5 = cw_protocol_retrieve8(param_1);
    *(char *)(__s + 7) = cVar5;
    if ((byte)(cVar5 - 6U) < 0xf9) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d last failure type(%d) is wrong\n",
               "cw_wtp_reboot_statistics_parse",0x9b,(uint)*(byte *)(__s + 7));
      }
      FUN_00407df0(__s);
      uVar2 = 0xffffffff;
    }
    else {
      *(undefined2 **)(param_2 + 0x10) = __s;
      uVar2 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

