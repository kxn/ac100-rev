// func cw_vendor_specific_payload_parse @ 0058286c size=988

undefined4 cw_vendor_specific_payload_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  undefined2 uVar5;
  int iVar3;
  ushort *puVar4;
  void *__s_00;
  short sVar6;
  char *pcVar7;
  ushort uVar9;
  uint uVar8;
  int iVar10;
  short local_38;
  ushort local_36 [3];
  undefined4 *local_30;
  uint local_2c;
  
  local_2c = (uint)*(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0x14,0x1b7);
  if (__s == (undefined4 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar10 = is_target_debug_ap();
    if (iVar10 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar2 = 0x1ba;
  }
  else {
    memset(__s,0,0x14);
    local_30 = __s + 2;
    FUN_0051ad88(local_30);
    uVar2 = cw_protocol_retrieve32(param_1);
    *__s = uVar2;
    uVar5 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)(__s + 1) = uVar5;
    uVar9 = *(short *)(param_2 + 0xe) - 6;
    uVar8 = (uint)uVar9;
    *(ushort *)((int)__s + 6) = uVar9;
    uVar9 = *(ushort *)(param_1 + 6);
    if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)uVar9) < (int)uVar8) {
      if ((capwap_err_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
        printf("[CW_ERROR]%32s():%4d length of private message element(%d) is wrong\n",
               "cw_vendor_specific_payload_parse",0x1c9,uVar8);
      }
      FUN_00407df0(__s);
      return 0xffffffff;
    }
    iVar10 = *(int *)(param_2 + 0x14);
    if (iVar10 != 0) {
      do {
        uVar1 = *(ushort *)(param_1 + 6);
        while( true ) {
          if (uVar8 == (uint)uVar1 - (uint)uVar9) {
            *(undefined4 **)(param_2 + 0x10) = __s;
            if (*(ushort *)(param_1 + 6) - local_2c != (uint)*(ushort *)(param_2 + 0xe)) {
              return 0xffffffff;
            }
            return 0;
          }
          local_36[0] = 0;
          local_38 = 0;
          iVar3 = cw_msg_ele_priv_format_parse(param_1,local_36,&local_38);
          if (iVar3 == -1) {
            cw_msg_eles_priv_free(__s);
            if ((capwap_err_switch == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
            goto LAB_00582a10;
            pcVar7 = "[CW_ERROR]%32s():%4d failed to parse type and length of message element\n";
            uVar2 = 0xbb;
            goto LAB_00582b08;
          }
          puVar4 = (ushort *)cw_msg_ele_priv_mngr_get(local_36[0]);
          if (puVar4 == (ushort *)0x0) break;
          __s_00 = (void *)FUN_00408450(0x18,0xdc);
          if (__s_00 == (void *)0x0) {
            cw_msg_eles_priv_free(__s);
            if ((capwap_err_switch == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
            goto LAB_00582a10;
            pcVar7 = "[CW_ERROR]%32s():%4d out of memory\n";
            uVar2 = 0xe0;
            goto LAB_00582b08;
          }
          memset(__s_00,0,0x18);
          FUN_004086b0(local_30,__s_00);
          *(int *)((int)__s_00 + 0x14) = iVar10;
          *(ushort *)((int)__s_00 + 0xc) = local_36[0];
          *(short *)((int)__s_00 + 0xe) = local_38;
          iVar3 = (**(code **)(puVar4 + 6))(param_1,__s_00);
          if (iVar3 == -1) {
            cw_msg_eles_priv_free(__s);
            if ((capwap_err_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
              printf("[CW_ERROR]%32s():%4d failed to parse %s(%d)\n","cw_msg_eles_priv_parse",0x100,
                     *(undefined4 *)(puVar4 + 2),(uint)*puVar4);
            }
            goto LAB_00582a10;
          }
          uVar1 = *(ushort *)(param_1 + 6);
        }
        if (capwap_debug_switch == 0) {
          sVar6 = *(short *)(param_1 + 6);
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            sVar6 = *(short *)(param_1 + 6);
          }
          else {
            printf("[CW_DEBUG]%32s():%4d private message element(%d) doesn\'t recogniced and ignore it\n"
                   ,"cw_msg_eles_priv_parse",0xd4,(uint)local_36[0]);
            sVar6 = *(short *)(param_1 + 6);
          }
        }
        *(short *)(param_1 + 6) = local_38 + sVar6;
      } while( true );
    }
    if ((capwap_err_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
      pcVar7 = "[CW_ERROR]%32s():%4d input is null\n";
      uVar2 = 0xa2;
LAB_00582b08:
      printf(pcVar7,"cw_msg_eles_priv_parse",uVar2);
    }
LAB_00582a10:
    cw_msg_eles_priv_free(__s);
    FUN_00407df0(__s);
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar10 = is_target_debug_ap();
    if (iVar10 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d failed to parse private message element\n";
    uVar2 = 0x1d3;
  }
  printf(pcVar7,"cw_vendor_specific_payload_parse",uVar2);
  return 0xffffffff;
}

