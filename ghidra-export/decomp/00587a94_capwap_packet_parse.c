// func capwap_packet_parse @ 00587a94 size=1072

undefined4 capwap_packet_parse(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  void *__s;
  short sVar6;
  uint uVar5;
  char *pcVar7;
  undefined4 uVar8;
  short local_30;
  undefined2 local_2e [3];
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_5 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
    uVar8 = 0x6a3;
  }
  else if ((param_3 == 0) && (iVar3 = cw_header_parse(), iVar3 == -1)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d failed to parsed capwap header\n";
    uVar8 = 0x6ad;
  }
  else {
    if (param_4 == 0) {
      iVar3 = cw_control_header_parse(param_1,param_2 + 0x10);
      if (iVar3 == -1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        pcVar7 = "[CW_ERROR]%32s():%4d failed to parse capwap control header\n";
        uVar8 = 0x6b8;
        goto LAB_00587d7c;
      }
      uVar1 = *(ushort *)(param_2 + 0x16);
    }
    else {
      uVar1 = *(ushort *)(param_2 + 0x16);
    }
    iVar3 = uVar1 - 3;
    if (iVar3 == (uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) {
LAB_00587c60:
      sVar6 = *(short *)(param_1 + 4);
      do {
        if (sVar6 == *(short *)(param_1 + 6)) {
          if (capwap_debug_switch == 0) {
            return 0;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0;
          }
          uVar8 = cw_control_msg_name(*(undefined4 *)(param_2 + 0x10));
          printf("[CW_DEBUG]%32s():%4d success to parse %s(%d)\n","capwap_packet_parse",0x6c5,uVar8,
                 *(undefined4 *)(param_2 + 0x10));
          return 0;
        }
        local_2e[0] = 0;
        local_30 = 0;
        iVar3 = cw_msg_ele_format_parse(param_1,local_2e,&local_30);
        if (iVar3 == -1) {
          cw_msg_eles_free(param_2);
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar7 = "[CW_ERROR]%32s():%4d failed to parse type and length of message element\n";
            uVar8 = 0x9b;
LAB_00587e24:
            printf(pcVar7,"cw_msg_eles_parse",uVar8);
          }
          goto LAB_00587b30;
        }
        puVar4 = (ushort *)cw_msg_ele_mngr_get(local_2e[0]);
        if (puVar4 == (ushort *)0x0) goto LAB_00587d4c;
        __s = (void *)FUN_00408450(0x18,0xc2);
        if (__s == (void *)0x0) {
          cw_msg_eles_free(param_2);
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar7 = "[CW_ERROR]%32s():%4d out of memory\n";
            uVar8 = 0xc6;
            goto LAB_00587e24;
          }
          goto LAB_00587b30;
        }
        memset(__s,0,0x18);
        FUN_004086b0(param_2 + 0x1c,__s);
        *(int *)((int)__s + 0x14) = param_5;
        *(undefined2 *)((int)__s + 0xc) = local_2e[0];
        *(short *)((int)__s + 0xe) = local_30;
        iVar3 = (**(code **)(puVar4 + 6))(param_1,__s);
        if (iVar3 == -1) {
          cw_msg_eles_free(param_2);
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_00587b30;
          uVar5 = (uint)*puVar4;
          iVar3 = *(int *)(puVar4 + 2);
          pcVar7 = "[CW_ERROR]%32s():%4d failed to parse %s(%d)\n";
          uVar8 = 0xe2;
          goto LAB_00587dd8;
        }
        sVar6 = *(short *)(param_1 + 4);
      } while( true );
    }
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar7 = 
      "[CW_ERROR]%32s():%4d total length of capwap message(%d) isn\'t equal to length of packet buffer(%d)\n"
      ;
      uVar5 = (uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6);
      uVar8 = 0x8b;
LAB_00587dd8:
      printf(pcVar7,"cw_msg_eles_parse",uVar8,iVar3,uVar5);
    }
LAB_00587b30:
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d failed to parse capwap message elements\n";
    uVar8 = 0x6c0;
  }
LAB_00587d7c:
  printf(pcVar7,"capwap_packet_parse",uVar8);
  return 0xffffffff;
LAB_00587d4c:
  if (capwap_err_switch == 0) {
    sVar6 = *(short *)(param_1 + 6);
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      sVar6 = *(short *)(param_1 + 6);
    }
    else {
      printf("[CW_ERROR]%32s():%4d message element doesn\'t have manager, ignore it\n",
             "cw_msg_eles_parse",0xbb);
      sVar6 = *(short *)(param_1 + 6);
    }
  }
  *(short *)(param_1 + 6) = local_30 + sVar6;
  goto LAB_00587c60;
}

