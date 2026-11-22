// func cw_ac_descriptor_assemble @ 0056d2fc size=1056

undefined4 cw_ac_descriptor_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  ushort *puVar8;
  
  puVar8 = *(ushort **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (puVar8[1] < *puVar8) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar1 = puVar8[1];
    uVar2 = *puVar8;
    pcVar5 = "[CW_ERROR]%32s():%4d stations(%d) is bigger than limit(%d)\n";
    uVar6 = 0x12d;
  }
  else {
    cw_protocol_restore16();
    cw_protocol_restore16(param_1,puVar8[1]);
    if (puVar8[2] <= puVar8[3]) {
      cw_protocol_restore16(param_1);
      cw_protocol_restore16(param_1,puVar8[3]);
      if ((*(byte *)(puVar8 + 4) & 6) == *(byte *)(puVar8 + 4)) {
        cw_protocol_restore8(param_1);
        if (*(byte *)((int)puVar8 + 9) - 1 < 2) {
          cw_protocol_restore8(param_1);
          if (*(char *)(puVar8 + 5) == '\0') {
            cw_protocol_restore8(param_1,0);
            if ((*(byte *)((int)puVar8 + 0xb) & 6) == *(byte *)((int)puVar8 + 0xb)) {
              cw_protocol_restore8(param_1);
              iVar3 = FUN_004081b0(puVar8 + 6);
              do {
                if (iVar3 == 0) {
                  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 !=
                      (uint)*(ushort *)(param_2 + 0xe)) {
                    return 0xffffffff;
                  }
                  return 0;
                }
                if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) < 8) {
                  if (capwap_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar3 = is_target_debug_ap();
                  if (iVar3 == 0) {
                    return 0xffffffff;
                  }
                  pcVar5 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
                  uVar6 = 0x164;
LAB_0056d668:
                  printf(pcVar5,"cw_ac_descriptor_assemble",uVar6);
                  return 0xffffffff;
                }
                cw_protocol_restore32(param_1,*(undefined4 *)(iVar3 + 0xc));
                if (1 < *(ushort *)(iVar3 + 0x10) - 4) {
                  if (capwap_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar4 = is_target_debug_ap();
                  if (iVar4 == 0) {
                    return 0xffffffff;
                  }
                  uVar7 = (uint)*(ushort *)(iVar3 + 0x10);
                  pcVar5 = "[CW_ERROR]%32s():%4d subelement type(%d) is wrong\n";
                  uVar6 = 0x16e;
                  goto LAB_0056d460;
                }
                cw_protocol_restore16(param_1);
                if (0x3ff < *(ushort *)(iVar3 + 0x12) - 1) {
                  if (capwap_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar4 = is_target_debug_ap();
                  if (iVar4 == 0) {
                    return 0xffffffff;
                  }
                  uVar7 = (uint)*(ushort *)(iVar3 + 0x12);
                  pcVar5 = "[CW_ERROR]%32s():%4d subelement length(%d) is wrong\n";
                  uVar6 = 0x176;
                  goto LAB_0056d460;
                }
                cw_protocol_restore16(param_1);
                if (((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) <
                     (int)(uint)*(ushort *)(iVar3 + 0x12)) || (*(int *)(iVar3 + 0x14) == 0)) {
                  if (capwap_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar3 = is_target_debug_ap();
                  if (iVar3 == 0) {
                    return 0xffffffff;
                  }
                  pcVar5 = "[CW_ERROR]%32s():%4d failed to write subelement data\n";
                  uVar6 = 0x17e;
                  goto LAB_0056d668;
                }
                cw_protocol_restore_raw_bytes(param_1);
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
            uVar7 = (uint)*(byte *)((int)puVar8 + 0xb);
            pcVar5 = "[CW_ERROR]%32s():%4d dtls policy(0x%02x) is wrong\n";
            uVar6 = 0x157;
          }
          else {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              return 0xffffffff;
            }
            uVar7 = (uint)*(byte *)(puVar8 + 5);
            pcVar5 = "[CW_ERROR]%32s():%4d reserved(%d) is wrong\n";
            uVar6 = 0x14f;
          }
        }
        else {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          uVar7 = (uint)*(byte *)((int)puVar8 + 9);
          pcVar5 = "[CW_ERROR]%32s():%4d rmac field(%d) is wrong\n";
          uVar6 = 0x147;
        }
      }
      else {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        uVar7 = (uint)*(byte *)(puVar8 + 4);
        pcVar5 = "[CW_ERROR]%32s():%4d security(0x%02x) is wrong\n";
        uVar6 = 0x13f;
      }
LAB_0056d460:
      printf(pcVar5,"cw_ac_descriptor_assemble",uVar6,uVar7);
      return 0xffffffff;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar1 = puVar8[3];
    uVar2 = puVar8[2];
    pcVar5 = "[CW_ERROR]%32s():%4d active wtp(%d) is bigger than max wtps(%d)\n";
    uVar6 = 0x136;
  }
  printf(pcVar5,"cw_ac_descriptor_assemble",uVar6,(uint)uVar2,(uint)uVar1);
  return 0xffffffff;
}

