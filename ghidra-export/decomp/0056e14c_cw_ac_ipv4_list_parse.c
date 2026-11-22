// func cw_ac_ipv4_list_parse @ 0056e14c size=472

undefined4 cw_ac_ipv4_list_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *__s;
  void *__s_00;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  if ((*(ushort *)(param_2 + 0xe) & 3) == 0) {
    __s = (ushort *)FUN_00408450(8,0x6e);
    if (__s == (ushort *)0x0) {
      uVar4 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ac_ipv4_list_parse",0x71);
      }
    }
    else {
      memset(__s,0,8);
      *__s = *(ushort *)(param_2 + 0xe) >> 2;
      __s_00 = (void *)FUN_00408450(*(undefined2 *)(param_2 + 0xe),0x78);
      *(void **)(__s + 2) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ac_ipv4_list_parse",0x7b);
        }
        FUN_00407df0(__s);
        uVar4 = 0xffffffff;
      }
      else {
        memset(__s_00,0,(uint)*(ushort *)(param_2 + 0xe));
        uVar2 = *__s;
        for (iVar3 = 0; iVar3 < (int)(uint)uVar2; iVar3 = iVar3 + 1) {
          iVar5 = *(int *)(__s + 2);
          uVar4 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar5 + iVar3 * 4) = uVar4;
          uVar2 = *__s;
        }
        *(ushort **)(param_2 + 0x10) = __s;
        uVar4 = 0xffffffff;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
          uVar4 = 0;
        }
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d length of message element(%d) is wrong\n","cw_ac_ipv4_list_parse"
             ,0x69,(uint)*(ushort *)(param_2 + 0xe));
    }
  }
  return uVar4;
}

