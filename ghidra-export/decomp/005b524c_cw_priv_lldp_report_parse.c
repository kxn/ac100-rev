// func cw_priv_lldp_report_parse @ 005b524c size=492

undefined4 cw_priv_lldp_report_parse(int param_1,int param_2)

{
  ushort uVar1;
  int *__s;
  int iVar2;
  void *__s_00;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (int *)FUN_00408450(8,0x74);
  if (__s == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_lldp_report_parse",0x77);
    return 0xffffffff;
  }
  memset(__s,0,8);
  iVar2 = cw_protocol_retrieve32(param_1);
  *__s = iVar2;
  if (iVar2 - 1U < 0x12c0) {
    __s_00 = (void *)FUN_00408450(iVar2 + 1,0x87);
    __s[1] = (int)__s_00;
    if (__s_00 != (void *)0x0) {
      memset(__s_00,0,*__s + 1);
      cw_protocol_retrieve_bytes(param_1,__s[1],(short)*__s);
      *(int **)(param_2 + 0x10) = __s;
      if (capwap_debug_switch == 0) {
        uVar4 = (uint)*(ushort *)(param_1 + 6);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          uVar4 = (uint)*(ushort *)(param_1 + 6);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d offset:%d old_offset:%d len:%d\n","cw_priv_lldp_report_parse"
                 ,0x93,(uint)*(ushort *)(param_1 + 6),(uint)uVar1,(uint)*(ushort *)(param_2 + 0xe));
          uVar4 = (uint)*(ushort *)(param_1 + 6);
        }
      }
      if (uVar4 - uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005b53c4;
    __format = "[CW_ERROR]%32s():%4d malloc data failed len:%d\n";
    uVar3 = 0x8a;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005b53c4;
    __format = "[CW_ERROR]%32s():%4d len:%d error\n";
    uVar3 = 0x81;
  }
  printf(__format,"cw_priv_lldp_report_parse",uVar3,*__s);
LAB_005b53c4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

