// func cw_priv_wtp_sub_capability_parse @ 005d06d8 size=552

undefined4 cw_priv_wtp_sub_capability_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *__s;
  int iVar3;
  undefined4 uVar4;
  void *__s_00;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (ushort *)FUN_00408450(8,0x81);
  if (__s == (ushort *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_wtp_sub_capability_parse",0x84);
    }
  }
  else {
    memset(__s,0,8);
    iVar3 = cw_protocol_retrieve16(param_1);
    *__s = (ushort)iVar3;
    if (iVar3 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(iVar3 << 3,0x8e);
      *(void **)(__s + 2) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to malloc sub_cap_list\n",
                 "cw_priv_wtp_sub_capability_parse",0x91);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      iVar3 = 0;
      memset(__s_00,0,(uint)*__s << 3);
      while (iVar3 < (int)(uint)*__s) {
        iVar6 = *(int *)(__s + 2);
        iVar7 = iVar3 * 8;
        uVar5 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(iVar6 + iVar7) = uVar5;
        iVar6 = *(int *)(__s + 2);
        uVar5 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(iVar6 + iVar7 + 2) = uVar5;
        uVar2 = *(ushort *)(*(int *)(__s + 2) + iVar7 + 2);
        if (uVar2 == 0) {
          iVar3 = iVar3 + 1;
        }
        else {
          if (uVar2 < 5) {
            iVar6 = *(int *)(__s + 2);
          }
          else {
            *(undefined2 *)(*(int *)(__s + 2) + iVar7 + 2) = 4;
            cw_protocol_retrieve_bytes_not_save
                      (param_1,*(short *)(*(int *)(__s + 2) + iVar7 + 2) + -4);
            iVar6 = *(int *)(__s + 2);
          }
          cw_protocol_retrieve_bytes
                    (param_1,((iVar6 + iVar7) - (uint)*(ushort *)(iVar6 + iVar7 + 2)) + 8);
          iVar3 = iVar3 + 1;
        }
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(ushort **)(param_2 + 0x10) = __s;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

