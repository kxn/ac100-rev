// func cw_priv_sta_assoc_rslt_new_assemble @ 005c3834 size=1084

undefined4 cw_priv_sta_assoc_rslt_new_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  char *pcVar6;
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
          pcVar6 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
          uVar7 = 0x141;
LAB_005c3b20:
          printf(pcVar6,"cw_priv_sta_assoc_rslt_new_assemble",uVar7);
          return 0xffffffff;
        }
        cw_protocol_restore16(param_1,*(undefined2 *)(iVar3 + 0xc));
        if ((0x3ff < *(ushort *)(iVar3 + 0xe) - 1) && (*(short *)(iVar3 + 0xc) != 2)) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          uVar9 = (uint)*(ushort *)(iVar3 + 0xe);
          pcVar6 = "[CW_ERROR]%32s():%4d subelement length(%d) is wrong\n";
          uVar7 = 0x14d;
          goto LAB_005c3920;
        }
        cw_protocol_restore16(param_1);
        puVar4 = *(undefined2 **)(iVar3 + 0x10);
        sVar8 = *(short *)(iVar3 + 0xc);
        if ((puVar4 == (undefined2 *)0x0) && (sVar8 != 2)) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          pcVar6 = "[CW_ERROR]%32s():%4d subelement data is null\n";
          uVar7 = 0x158;
          goto LAB_005c3b20;
        }
        if (sVar8 == 1) {
          if (*(short *)(iVar3 + 0xe) == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return 0xffffffff;
            }
            uVar1 = *(ushort *)(iVar3 + 0xc);
            uVar2 = *(ushort *)(iVar3 + 0xe);
            uVar7 = 0x16d;
LAB_005c3c20:
            printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                   "cw_priv_sta_assoc_rslt_new_assemble",uVar7,(uint)uVar2,(uint)uVar1);
            return 0xffffffff;
          }
          iVar5 = *(int *)(puVar4 + 2);
          sVar8 = puVar4[1];
LAB_005c3a80:
          cw_protocol_restore_raw_bytes(param_1,iVar5,sVar8);
        }
        else if (sVar8 == 0) {
          if (*(short *)(iVar3 + 0xe) != 2) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return 0xffffffff;
            }
            uVar1 = *(ushort *)(iVar3 + 0xc);
            uVar2 = *(ushort *)(iVar3 + 0xe);
            uVar7 = 0x161;
            goto LAB_005c3c20;
          }
          cw_protocol_restore16(param_1,*puVar4);
        }
        else if (sVar8 == 2) {
          if ((*(short *)(iVar3 + 0xe) != 0) &&
             ((capwap_warning_switch != 0 && (iVar5 = is_target_debug_ap(), iVar5 != 0)))) {
            printf("[CW_WARNING]%32s():%4d Uncorrect sub ele len(%d)\n",
                   "cw_priv_sta_assoc_rslt_new_assemble",0x179,(uint)*(ushort *)(iVar3 + 0xe));
          }
        }
        else {
          if (capwap_warning_switch == 0) {
            sVar8 = *(short *)(iVar3 + 0xe);
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              sVar8 = *(short *)(iVar3 + 0xe);
            }
            else {
              printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                     "cw_priv_sta_assoc_rslt_new_assemble",0x17d,(uint)*(ushort *)(iVar3 + 0xc));
              sVar8 = *(short *)(iVar3 + 0xe);
            }
          }
          if ((sVar8 != 0) && (iVar5 = *(int *)(iVar3 + 0x10), iVar5 != 0)) goto LAB_005c3a80;
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
    pcVar6 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar7 = 0x12e;
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
    pcVar6 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar7 = 0x126;
  }
LAB_005c3920:
  printf(pcVar6,"cw_priv_sta_assoc_rslt_new_assemble",uVar7,uVar9);
  return 0xffffffff;
}

