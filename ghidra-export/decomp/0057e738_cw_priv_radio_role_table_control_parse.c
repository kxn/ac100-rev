// func cw_priv_radio_role_table_control_parse @ 0057e738 size=1244

undefined4 cw_priv_radio_role_table_control_parse(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  byte *__s;
  int iVar3;
  byte *__s_00;
  byte bVar7;
  undefined2 uVar6;
  undefined1 *puVar4;
  int iVar5;
  char *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  byte *pbVar11;
  uint *puVar12;
  
  if (capwap_debug_switch == 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 6);
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      uVar2 = (uint)*(ushort *)(param_1 + 6);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_control_parse ENTER\n",
             "cw_priv_radio_role_table_control_parse",0x88);
      uVar2 = (uint)*(ushort *)(param_1 + 6);
    }
  }
  __s = (byte *)FUN_00408450(8,0x8f);
  if (__s == (byte *)0x0) {
    uVar9 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_radio_role_table_control_parse",0x92);
    }
  }
  else {
    memset(__s,0,8);
    iVar3 = cw_protocol_retrieve8(param_1);
    *__s = (byte)iVar3;
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d val->tlv_num:%d <= 0\n",
               "cw_priv_radio_role_table_control_parse",0x9b,(uint)*__s);
      }
LAB_0057ead8:
      cw_priv_radio_role_table_control_val_destroy(__s);
      uVar9 = 0xffffffff;
    }
    else {
      __s_00 = (byte *)FUN_00408450(iVar3 << 3,0x9f);
      if (__s_00 == (byte *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_radio_role_table_control_parse",
                 0xa2);
        }
        FUN_00407df0(__s);
        uVar9 = 0xffffffff;
      }
      else {
        memset(__s_00,0,(uint)*__s << 3);
        *(byte **)(__s + 4) = __s_00;
        if (2 < *__s) {
          *__s = 2;
        }
        if ((capwap_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_DEBUG]%32s():%4d val->tlv_num:%d\n","cw_priv_radio_role_table_control_parse",
                 0xae,(uint)*__s);
        }
        iVar3 = 0;
        while (iVar3 < (int)(uint)*__s) {
          bVar7 = cw_protocol_retrieve8(param_1);
          *__s_00 = bVar7;
          uVar6 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)(__s_00 + 2) = uVar6;
          if ((capwap_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_DEBUG]%32s():%4d tlv_list[i].type:%d\n",
                   "cw_priv_radio_role_table_control_parse",0xb5,(uint)*__s_00);
          }
          if (capwap_debug_switch == 0) {
            bVar7 = *__s_00;
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              bVar7 = *__s_00;
            }
            else {
              printf("[CW_DEBUG]%32s():%4d tlv_list[i].len:%d\n",
                     "cw_priv_radio_role_table_control_parse",0xb6,(uint)*(ushort *)(__s_00 + 2));
              bVar7 = *__s_00;
            }
          }
          if (bVar7 == 0) {
            puVar4 = (undefined1 *)FUN_00408450(1,0xbd);
            *(undefined1 **)(__s_00 + 4) = puVar4;
            if (puVar4 == (undefined1 *)0x0) {
              if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                pcVar8 = "[CW_ERROR]%32s():%4d Malloc failed\n";
                uVar9 = 0xc0;
LAB_0057eb14:
                printf(pcVar8,"cw_priv_radio_role_table_control_parse",uVar9);
              }
              goto LAB_0057ead8;
            }
            *puVar4 = 0;
            pbVar11 = *(byte **)(__s_00 + 4);
            bVar7 = cw_protocol_retrieve8(param_1);
            *pbVar11 = bVar7;
            if ((capwap_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              uVar10 = (uint)*pbVar11;
              pcVar8 = "[CW_DEBUG]%32s():%4d tlv_item->table_id:%d\n";
              uVar9 = 200;
              goto LAB_0057e8f4;
            }
LAB_0057e88c:
            iVar3 = iVar3 + 1;
            __s_00 = __s_00 + 8;
          }
          else {
            if (bVar7 == 1) {
              puVar4 = (undefined1 *)FUN_00408450(4,0xce);
              *(undefined1 **)(__s_00 + 4) = puVar4;
              if (puVar4 != (undefined1 *)0x0) {
                *puVar4 = 0;
                puVar4[1] = 0;
                puVar4[2] = 0;
                puVar4[3] = 0;
                puVar12 = *(uint **)(__s_00 + 4);
                uVar10 = cw_protocol_retrieve32(param_1);
                *puVar12 = uVar10;
                if ((capwap_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  uVar10 = *puVar12;
                  pcVar8 = "[CW_DEBUG]%32s():%4d tlv_item->param_capability:%d\n";
                  uVar9 = 0xd9;
                  goto LAB_0057e8f4;
                }
                goto LAB_0057e88c;
              }
              if ((capwap_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                pcVar8 = "[CW_DEBUG]%32s():%4d Malloc failed\n";
                uVar9 = 0xd1;
                goto LAB_0057eb14;
              }
              goto LAB_0057ead8;
            }
            if ((capwap_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
            goto LAB_0057e88c;
            uVar10 = (uint)*__s_00;
            uVar9 = 0xde;
            pcVar8 = "[CW_WARNING]%32s():%4d Unrecognize tlv ele type(%d)\n";
LAB_0057e8f4:
            iVar3 = iVar3 + 1;
            printf(pcVar8,"cw_priv_radio_role_table_control_parse",uVar9,uVar10);
            __s_00 = __s_00 + 8;
          }
        }
        bVar1 = capwap_debug_switch != 0;
        *(byte **)(param_2 + 0x10) = __s;
        if ((bVar1) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_DEBUG]%32s():%4d pkt_buf->offset:%d - old_offset:%d == msg_ele->len:%d\n",
                 "cw_priv_radio_role_table_control_parse",0xe5,(uint)*(ushort *)(param_1 + 6),uVar2,
                 (uint)*(ushort *)(param_2 + 0xe));
        }
        uVar9 = 0xffffffff;
        if (*(ushort *)(param_1 + 6) - uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
          uVar9 = 0;
        }
      }
    }
  }
  return uVar9;
}

