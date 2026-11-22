// func cw_priv_radio_role_table_control_assemble @ 0057dedc size=784

undefined4 cw_priv_radio_role_table_control_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  byte bVar3;
  short sVar5;
  undefined4 uVar4;
  byte *pbVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  
  if (capwap_debug_switch == 0) {
    pbVar11 = *(byte **)(param_2 + 0x10);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      pbVar11 = *(byte **)(param_2 + 0x10);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d enter cw_priv_radio_role_table_control_assemble\n",
             "cw_priv_radio_role_table_control_assemble",0xf9);
      pbVar11 = *(byte **)(param_2 + 0x10);
    }
  }
  uVar1 = *(ushort *)(param_1 + 4);
  uVar9 = (uint)*pbVar11;
  if (uVar9 - 1 < 2) {
    if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_DEBUG]%32s():%4d tlv_num:%d\n","cw_priv_radio_role_table_control_assemble",0x106,
             uVar9);
    }
    iVar10 = 0;
    cw_protocol_restore8(param_1,uVar9);
    iVar2 = *(int *)(pbVar11 + 4);
    while( true ) {
      pbVar6 = (byte *)(iVar2 + iVar10 * 8);
      if (*(short *)(pbVar6 + 2) == 0) {
        bVar3 = *pbVar6;
      }
      else {
        if (*(int *)(pbVar6 + 4) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          uVar9 = (uint)*pbVar6;
          __format = "[CW_ERROR]%32s():%4d Data can not be NULL for tlv ele type(%d)\n";
          uVar4 = 0x10e;
          goto LAB_0057e170;
        }
        bVar3 = *pbVar6;
      }
      cw_protocol_restore8(param_1,bVar3);
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 2));
      if (*pbVar6 == 0) {
        pbVar6 = *(byte **)(pbVar6 + 4);
        if (capwap_debug_switch == 0) {
          bVar3 = *pbVar6;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            bVar3 = *pbVar6;
          }
          else {
            printf("[CW_DEBUG]%32s():%4d tlv_item->table_id:%d\n",
                   "cw_priv_radio_role_table_control_assemble",0x118,(uint)*pbVar6);
            bVar3 = *pbVar6;
          }
        }
        cw_protocol_restore8(param_1,bVar3);
      }
      else if (*pbVar6 == 1) {
        puVar7 = *(undefined4 **)(pbVar6 + 4);
        if (capwap_debug_switch == 0) {
          uVar4 = *puVar7;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            uVar4 = *puVar7;
          }
          else {
            printf("[CW_DEBUG]%32s():%4d tlv_item->param_capability:%d\n",
                   "cw_priv_radio_role_table_control_assemble",0x11f,*puVar7);
            uVar4 = *puVar7;
          }
        }
        cw_protocol_restore32(param_1,uVar4);
      }
      else {
        if (capwap_warning_switch == 0) {
          sVar5 = *(short *)(pbVar6 + 2);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            sVar5 = *(short *)(pbVar6 + 2);
          }
          else {
            printf("[CW_WARNING]%32s():%4d Unrecognize tlv ele type(%d)\n",
                   "cw_priv_radio_role_table_control_assemble",0x124,(uint)*pbVar6);
            sVar5 = *(short *)(pbVar6 + 2);
          }
        }
        if ((sVar5 != 0) && (*(int *)(pbVar6 + 4) != 0)) {
          cw_protocol_restore_raw_bytes(param_1);
        }
      }
      iVar10 = iVar10 + 1;
      if ((int)uVar9 <= iVar10) break;
      iVar2 = *(int *)(pbVar11 + 4);
    }
    uVar8 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "[CW_ERROR]%32s():%4d Ele num(%d) is wrong\n";
      uVar4 = 0x102;
LAB_0057e170:
      uVar8 = 0xffffffff;
      printf(__format,"cw_priv_radio_role_table_control_assemble",uVar4,uVar9);
    }
  }
  return uVar8;
}

