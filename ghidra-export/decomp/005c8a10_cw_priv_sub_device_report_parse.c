// func cw_priv_sub_device_report_parse @ 005c8a10 size=520

undefined4 cw_priv_sub_device_report_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  undefined2 uVar3;
  int iVar2;
  void *__s_00;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(0xc,0x75);
  if (__s == (undefined2 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sub_device_report_parse",0x78);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar3 = cw_protocol_retrieve16(param_1);
  *__s = uVar3;
  uVar3 = cw_protocol_retrieve16(param_1);
  __s[1] = uVar3;
  iVar2 = cw_protocol_retrieve32(param_1);
  *(int *)(__s + 2) = iVar2;
  if (iVar2 - 1U < 0xff80) {
    __s_00 = (void *)FUN_00408450(iVar2 + 1,0x8b);
    *(void **)(__s + 4) = __s_00;
    if (__s_00 != (void *)0x0) {
      memset(__s_00,0,*(int *)(__s + 2) + 1);
      cw_protocol_retrieve_bytes(param_1,*(undefined4 *)(__s + 4),__s[3]);
      *(undefined2 **)(param_2 + 0x10) = __s;
      if (capwap_debug_switch == 0) {
        uVar5 = (uint)*(ushort *)(param_1 + 6);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          uVar5 = (uint)*(ushort *)(param_1 + 6);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d offset:%d old_offset:%d len:%d\n",
                 "cw_priv_sub_device_report_parse",0x97,(uint)*(ushort *)(param_1 + 6),(uint)uVar1,
                 (uint)*(ushort *)(param_2 + 0xe));
          uVar5 = (uint)*(ushort *)(param_1 + 6);
        }
      }
      if (uVar5 - uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005c8ba4;
    __format = "[CW_ERROR]%32s():%4d malloc data failed len:%d\n";
    uVar4 = 0x8e;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005c8ba4;
    __format = "[CW_ERROR]%32s():%4d len:%d error\n";
    uVar4 = 0x85;
  }
  printf(__format,"cw_priv_sub_device_report_parse",uVar4,*(undefined4 *)(__s + 2));
LAB_005c8ba4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

