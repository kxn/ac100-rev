// func cw_wtp_descriptor_parse @ 00584978 size=1264

undefined4 cw_wtp_descriptor_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  byte bVar7;
  uint uVar2;
  int iVar3;
  undefined2 uVar6;
  void *pvVar4;
  undefined4 uVar5;
  char *pcVar8;
  int iVar9;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x1c,0xbf);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_wtp_descriptor_parse",0xc2);
    return 0xffffffff;
  }
  memset(__s,0,0x1c);
  FUN_0051ad88(__s + 4);
  FUN_0051ad88(__s + 0x10);
  bVar7 = cw_protocol_retrieve8(param_1);
  *__s = bVar7;
  uVar2 = cw_protocol_retrieve8(param_1);
  __s[1] = (byte)uVar2;
  if (*__s < uVar2) {
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d radios in use(%d) is bigger than max radios(%d)\n",
             "cw_wtp_descriptor_parse",0xce,(uint)__s[1],(uint)*__s);
    }
  }
  else {
    iVar3 = cw_protocol_retrieve8(param_1);
    iVar9 = 0;
    if (iVar3 != 0) {
      for (; iVar9 < iVar3; iVar9 = iVar9 + 1) {
        pvVar4 = (void *)FUN_00408450(0x10,0xe0);
        if (pvVar4 == (void *)0x0) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
          goto LAB_00584b78;
          pcVar8 = "[CW_ERROR]%32s():%4d out of memory\n";
          uVar5 = 0xe3;
          goto LAB_00584c28;
        }
        memset(pvVar4,0,0x10);
        FUN_004086b0(__s + 4,pvVar4);
        if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < 3) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
          goto LAB_00584b78;
          pcVar8 = "[CW_ERROR]%32s():%4d remaining pakcet buffer isn\'t enough\n";
          uVar5 = 0xed;
          goto LAB_00584c28;
        }
        uVar2 = cw_protocol_retrieve8(param_1);
        *(char *)((int)pvVar4 + 0xc) = (char)uVar2;
        if ((uVar2 & 0x1f) != uVar2) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
          goto LAB_00584b78;
          uVar2 = (uint)*(byte *)((int)pvVar4 + 0xc);
          pcVar8 = "[CW_ERROR]%32s():%4d wbid of encryption subelemenet(0x%02x) is wrong\n";
          uVar5 = 0xf6;
          goto LAB_00584ca4;
        }
        uVar6 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)((int)pvVar4 + 0xe) = uVar6;
      }
      while( true ) {
        if ((int)(uint)*(ushort *)(param_2 + 0xe) <=
            (int)((uint)*(ushort *)(param_1 + 6) - (uint)uVar1)) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < 8) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
          goto LAB_00584b78;
          pcVar8 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
          uVar5 = 0x103;
          goto LAB_00584c28;
        }
        pvVar4 = (void *)FUN_00408450(0x18,0x109);
        if (pvVar4 == (void *)0x0) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
          goto LAB_00584b78;
          pcVar8 = "[CW_ERROR]%32s():%4d out of memory\n";
          uVar5 = 0x10c;
          goto LAB_00584c28;
        }
        memset(pvVar4,0,0x18);
        FUN_004086b0(__s + 0x10,pvVar4);
        uVar5 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)((int)pvVar4 + 0xc) = uVar5;
        uVar2 = cw_protocol_retrieve16(param_1);
        *(short *)((int)pvVar4 + 0x10) = (short)uVar2;
        if (3 < uVar2) break;
        iVar3 = cw_protocol_retrieve16(param_1);
        *(short *)((int)pvVar4 + 0x12) = (short)iVar3;
        if ((0x3ff < iVar3 - 1U) ||
           ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < iVar3)) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
          goto LAB_00584b78;
          uVar2 = (uint)*(ushort *)((int)pvVar4 + 0x12);
          pcVar8 = "[CW_ERROR]%32s():%4d length(%d) is wrong\n";
          uVar5 = 0x123;
          goto LAB_00584ca4;
        }
        iVar3 = cw_protocol_retrieve_str(param_1,iVar3);
        *(int *)((int)pvVar4 + 0x14) = iVar3;
        if (iVar3 == 0) goto code_r0x00584b68;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
      goto LAB_00584b78;
      uVar2 = (uint)*(ushort *)((int)pvVar4 + 0x10);
      pcVar8 = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
      uVar5 = 0x11a;
LAB_00584ca4:
      printf(pcVar8,"cw_wtp_descriptor_parse",uVar5,uVar2);
      goto LAB_00584b78;
    }
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d num encryption(%d) is wrong\n","cw_wtp_descriptor_parse",0xd7,0);
    }
  }
  FUN_00407df0(__s);
  return 0xffffffff;
code_r0x00584b68:
  if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(__s), iVar3 != 0)) {
    pcVar8 = "[CW_ERROR]%32s():%4d failed to read data\n";
    uVar5 = 300;
LAB_00584c28:
    printf(pcVar8,"cw_wtp_descriptor_parse",uVar5);
  }
LAB_00584b78:
  cw_wtp_descriptor_val_free(__s);
  return 0xffffffff;
}

