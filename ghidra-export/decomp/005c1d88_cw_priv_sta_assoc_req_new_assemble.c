// func cw_priv_sta_assoc_req_new_assemble @ 005c1d88 size=956

undefined4 cw_priv_sta_assoc_req_new_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  short sVar8;
  uint uVar9;
  byte *pbVar10;
  
  pbVar10 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar10 < 0x20) {
    cw_protocol_restore8();
    if (pbVar10[1] < 0x11) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore_raw_bytes(param_1,pbVar10 + 2,6);
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar10 + 8));
      cw_protocol_restore8(param_1,pbVar10[0xc]);
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar10 + 0x10));
      iVar3 = FUN_004081b0(pbVar10 + 0x14);
      do {
        if (iVar3 == 0) {
          if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) <
            (int)(*(ushort *)(iVar3 + 0xe) + 4)) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          pcVar5 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
          uVar7 = 0x14b;
LAB_005c203c:
          printf(pcVar5,"cw_priv_sta_assoc_req_new_assemble",uVar7);
          return 0xffffffff;
        }
        cw_protocol_restore16(param_1,*(undefined2 *)(iVar3 + 0xc));
        if (0x3ff < *(ushort *)(iVar3 + 0xe) - 1) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          uVar9 = (uint)*(ushort *)(iVar3 + 0xe);
          pcVar5 = "[CW_ERROR]%32s():%4d subelement length(%d) is wrong\n";
          uVar7 = 0x155;
          goto LAB_005c1e64;
        }
        cw_protocol_restore16(param_1);
        iVar4 = *(int *)(iVar3 + 0x10);
        if (iVar4 == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          pcVar5 = "[CW_ERROR]%32s():%4d subelement data is null\n";
          uVar7 = 0x15d;
          goto LAB_005c203c;
        }
        if (*(short *)(iVar3 + 0xc) == 0) {
          if (*(short *)(iVar3 + 0xe) == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              return 0xffffffff;
            }
            uVar1 = *(ushort *)(iVar3 + 0xc);
            uVar2 = *(ushort *)(iVar3 + 0xe);
            uVar7 = 0x165;
LAB_005c20f4:
            printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                   "cw_priv_sta_assoc_req_new_assemble",uVar7,(uint)uVar2,(uint)uVar1);
            return 0xffffffff;
          }
          iVar6 = *(int *)(iVar4 + 4);
LAB_005c1f60:
          sVar8 = *(short *)(iVar4 + 2);
LAB_005c1f64:
          cw_protocol_restore_raw_bytes(param_1,iVar6,sVar8);
        }
        else {
          if (*(short *)(iVar3 + 0xc) == 1) {
            if (*(short *)(iVar3 + 0xe) == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                return 0xffffffff;
              }
              uVar1 = *(ushort *)(iVar3 + 0xc);
              uVar2 = *(ushort *)(iVar3 + 0xe);
              uVar7 = 0x171;
              goto LAB_005c20f4;
            }
            iVar6 = iVar4 + 4;
            goto LAB_005c1f60;
          }
          if (capwap_warning_switch == 0) {
            sVar8 = *(short *)(iVar3 + 0xe);
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              sVar8 = *(short *)(iVar3 + 0xe);
            }
            else {
              printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                     "cw_priv_sta_assoc_req_new_assemble",0x17a,(uint)*(ushort *)(iVar3 + 0xc));
              sVar8 = *(short *)(iVar3 + 0xe);
            }
          }
          if ((sVar8 != 0) && (iVar6 = *(int *)(iVar3 + 0x10), iVar6 != 0)) goto LAB_005c1f64;
        }
        iVar3 = FUN_00408680(iVar3);
      } while( true );
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar9 = (uint)pbVar10[1];
    pcVar5 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar7 = 0x138;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar9 = (uint)*pbVar10;
    pcVar5 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar7 = 0x130;
  }
LAB_005c1e64:
  printf(pcVar5,"cw_priv_sta_assoc_req_new_assemble",uVar7,uVar9);
  return 0xffffffff;
}

