// func cw_priv_vap_info_list_parse @ 005cacb4 size=848

undefined4 cw_priv_vap_info_list_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  int iVar3;
  undefined1 uVar9;
  undefined2 uVar8;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 uVar7;
  char *__format;
  int iVar10;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0xb3);
  if (__s == (byte *)0x0) {
    uVar7 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_vap_info_list_parse",0xb6);
    }
  }
  else {
    memset(__s,0,8);
    iVar3 = cw_protocol_retrieve8(param_1);
    *__s = (byte)iVar3;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      pvVar5 = (void *)FUN_00408450(iVar3 << 5,0xbe);
      *(void **)(__s + 4) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          __format = "[CW_ERROR]%32s():%4d out of memory\n";
          uVar7 = 0xc1;
LAB_005cafc4:
          printf(__format,"cw_priv_vap_info_list_parse",uVar7);
        }
LAB_005cae2c:
        cw_priv_vap_info_list_destroy(__s);
        return 0xffffffff;
      }
      memset(pvVar5,0,(uint)*__s << 5);
      bVar1 = *__s;
      for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
        FUN_0051ad88(*(int *)(__s + 4) + iVar3 * 0x20 + 0x14);
        bVar1 = *__s;
      }
      iVar3 = 0;
    }
    for (; iVar3 < (int)(uint)*__s; iVar3 = iVar3 + 1) {
      iVar10 = *(int *)(__s + 4) + iVar3 * 0x20;
      cw_protocol_retrieve_bytes(param_1,iVar10,6);
      uVar9 = cw_protocol_retrieve8(param_1);
      *(undefined1 *)(iVar10 + 6) = uVar9;
      uVar9 = cw_protocol_retrieve8(param_1);
      *(undefined1 *)(iVar10 + 7) = uVar9;
      uVar8 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(iVar10 + 8) = uVar8;
      uVar7 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(iVar10 + 0xc) = uVar7;
      iVar4 = cw_protocol_retrieve16(param_1);
      *(short *)(iVar10 + 0x10) = (short)iVar4;
      if (iVar4 != 0) {
        pvVar5 = (void *)FUN_00408450(0x14,0xd7);
        if (pvVar5 == (void *)0x0) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_005cae2c;
          __format = "[CW_ERROR]%32s():%4d out of memory\n";
          uVar7 = 0xda;
          goto LAB_005cafc4;
        }
        memset(pvVar5,0,0x14);
        FUN_004086b0(iVar10 + 0x14,pvVar5);
        if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < 4) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_005cae2c;
          __format = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
          uVar7 = 0xe3;
          goto LAB_005cafc4;
        }
        uVar8 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)((int)pvVar5 + 0xc) = uVar8;
        uVar6 = cw_protocol_retrieve16(param_1);
        *(short *)((int)pvVar5 + 0xe) = (short)uVar6;
        if ((0x100 < uVar6) ||
           ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < (int)uVar6)) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d length of subelement(%d) is wrong\n",
                   "cw_priv_vap_info_list_parse",0xef,(uint)*(ushort *)((int)pvVar5 + 0xe));
          }
          goto LAB_005cae2c;
        }
        if (uVar6 != 0) {
          iVar4 = cw_protocol_retrieve_raw_bytes(param_1,uVar6);
          *(int *)((int)pvVar5 + 0x10) = iVar4;
          if (iVar4 == 0) goto LAB_005cae2c;
        }
      }
    }
    *(byte **)(param_2 + 0x10) = __s;
    uVar7 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar7 = 0;
    }
  }
  return uVar7;
}

