// func cw_wtp_board_data_parse @ 005838e0 size=668

undefined4 cw_wtp_board_data_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  void *__s_00;
  undefined2 uVar5;
  uint uVar3;
  int iVar4;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0x10,0x9c);
  if (__s == (undefined4 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_wtp_board_data_parse",0x9f);
    }
  }
  else {
    memset(__s,0,0x10);
    FUN_0051ad88(__s + 1);
    uVar2 = cw_protocol_retrieve32(param_1);
    *__s = uVar2;
    do {
      if ((int)(uint)*(ushort *)(param_2 + 0xe) <=
          (int)((uint)*(ushort *)(param_1 + 6) - (uint)uVar1)) {
        *(undefined4 **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      __s_00 = (void *)FUN_00408450(0x14,0xaa);
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_00583a18;
        __format = "[CW_ERROR]%32s():%4d out of memory\n";
        uVar2 = 0xad;
        goto LAB_00583aec;
      }
      memset(__s_00,0,0x14);
      FUN_004086b0(__s + 1,__s_00);
      if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < 4) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_00583a18;
        __format = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
        uVar2 = 0xb7;
        goto LAB_00583aec;
      }
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)((int)__s_00 + 0xc) = uVar5;
      uVar3 = cw_protocol_retrieve16(param_1);
      *(short *)((int)__s_00 + 0xe) = (short)uVar3;
      if (((0x3ff < uVar3 - 1) || (*(ushort *)(param_2 + 0xe) < uVar3)) ||
         ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < (int)uVar3)) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d length of subelement(%d) is wrong\n",
                 "cw_wtp_board_data_parse",0xc4,(uint)*(ushort *)((int)__s_00 + 0xe));
        }
        goto LAB_00583a18;
      }
      iVar4 = cw_protocol_retrieve_raw_bytes(param_1,uVar3);
      *(int *)((int)__s_00 + 0x10) = iVar4;
    } while (iVar4 != 0);
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      __format = "[CW_ERROR]%32s():%4d failed to read subelement data\n";
      uVar2 = 0xcd;
LAB_00583aec:
      printf(__format,"cw_wtp_board_data_parse",uVar2);
    }
LAB_00583a18:
    cw_wtp_board_data_val_free(__s);
  }
  return 0xffffffff;
}

