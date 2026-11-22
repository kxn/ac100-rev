// func cw_ac_ipv6_list_parse @ 0056e754 size=388

undefined4 cw_ac_ipv6_list_parse(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *__s;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  if ((*(ushort *)(param_2 + 0xe) & 0xf) == 0) {
    __s = (ushort *)FUN_00408450(8,0x73);
    if (__s == (ushort *)0x0) {
      uVar3 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ac_ipv6_list_parse",0x76);
      }
    }
    else {
      memset(__s,0,8);
      *__s = *(ushort *)(param_2 + 0xe) >> 4;
      iVar2 = cw_protocol_retrieve_raw_bytes(param_1,*(undefined2 *)(param_2 + 0xe));
      *(int *)(__s + 2) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read ac ipv6 list\n","cw_ac_ipv6_list_parse",0x80);
        }
        FUN_00407df0(__s);
        uVar3 = 0xffffffff;
      }
      else {
        *(ushort **)(param_2 + 0x10) = __s;
        uVar3 = 0xffffffff;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
          uVar3 = 0;
        }
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d length of ac ipv6 list(%d) is wrong\n","cw_ac_ipv6_list_parse",
             0x6e,(uint)*(ushort *)(param_2 + 0xe));
    }
  }
  return uVar3;
}

