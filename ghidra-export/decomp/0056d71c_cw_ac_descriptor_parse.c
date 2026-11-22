// func cw_ac_descriptor_parse @ 0056d71c size=1292

undefined4 cw_ac_descriptor_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort *__s;
  ushort uVar5;
  uint uVar2;
  int iVar3;
  void *__s_00;
  undefined4 uVar4;
  undefined2 uVar6;
  char *pcVar7;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (ushort *)FUN_00408450(0x18,0xa1);
  if (__s == (ushort *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_ac_descriptor_parse",0xa4);
    return 0xffffffff;
  }
  memset(__s,0,0x18);
  FUN_0051ad88(__s + 6);
  uVar5 = cw_protocol_retrieve16(param_1);
  *__s = uVar5;
  uVar2 = cw_protocol_retrieve16(param_1);
  __s[1] = (ushort)uVar2;
  if (uVar2 < *__s) {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056d980;
    uVar1 = __s[1];
    uVar5 = *__s;
    pcVar7 = "[CW_ERROR]%32s():%4d stations(%d) is bigger than limit(%d)\n";
    uVar4 = 0xaf;
  }
  else {
    uVar5 = cw_protocol_retrieve16(param_1);
    __s[2] = uVar5;
    uVar2 = cw_protocol_retrieve16(param_1);
    __s[3] = (ushort)uVar2;
    if (__s[2] <= uVar2) {
      uVar2 = cw_protocol_retrieve8(param_1);
      *(char *)(__s + 4) = (char)uVar2;
      if ((uVar2 & 6) == uVar2) {
        iVar3 = cw_protocol_retrieve8(param_1);
        *(char *)((int)__s + 9) = (char)iVar3;
        if (iVar3 - 1U < 2) {
          iVar3 = cw_protocol_retrieve8(param_1);
          *(char *)(__s + 5) = (char)iVar3;
          if (iVar3 == 0) {
            uVar2 = cw_protocol_retrieve8(param_1);
            *(char *)((int)__s + 0xb) = (char)uVar2;
            if ((uVar2 & 6) == uVar2) {
              do {
                if ((int)(uint)*(ushort *)(param_2 + 0xe) <=
                    (int)((uint)*(ushort *)(param_1 + 6) - (uint)uVar1)) {
                  *(ushort **)(param_2 + 0x10) = __s;
                  if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 !=
                      (uint)*(ushort *)(param_2 + 0xe)) {
                    return 0xffffffff;
                  }
                  return 0;
                }
                __s_00 = (void *)FUN_00408450(0x18,0xe6);
                if (__s_00 == (void *)0x0) {
                  if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
                  goto LAB_0056d900;
                  pcVar7 = "[CW_ERROR]%32s():%4d out of memory\n";
                  uVar4 = 0xe9;
                  goto LAB_0056da3c;
                }
                memset(__s_00,0,0x18);
                FUN_004086b0(__s + 6,__s_00);
                if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < 8) {
                  if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
                  goto LAB_0056d900;
                  pcVar7 = "[CW_ERROR]%32s():%4d remaining packet bufferr isn\'t enough\n";
                  uVar4 = 0xf3;
                  goto LAB_0056da3c;
                }
                uVar4 = cw_protocol_retrieve32(param_1);
                *(undefined4 *)((int)__s_00 + 0xc) = uVar4;
                uVar6 = cw_protocol_retrieve16(param_1);
                *(undefined2 *)((int)__s_00 + 0x10) = uVar6;
                iVar3 = cw_protocol_retrieve16(param_1);
                *(short *)((int)__s_00 + 0x12) = (short)iVar3;
                if (1 < (ushort)(*(short *)((int)__s_00 + 0x10) - 4U)) {
                  if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(__s), iVar3 != 0)) {
                    uVar1 = *(ushort *)((int)__s_00 + 0x10);
                    pcVar7 = "[CW_ERROR]%32s():%4d type(%d) isn\'t recognised\n";
                    uVar4 = 0xfe;
LAB_0056dae4:
                    printf(pcVar7,"cw_ac_descriptor_parse",uVar4,(uint)uVar1);
                  }
                  goto LAB_0056d900;
                }
                if ((0x3ff < iVar3 - 1U) ||
                   ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < iVar3))
                {
                  if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(__s), iVar3 != 0)) {
                    uVar1 = *(ushort *)((int)__s_00 + 0x12);
                    pcVar7 = "[CW_ERROR]%32s():%4d length(%d) is wrong\n";
                    uVar4 = 0x106;
                    goto LAB_0056dae4;
                  }
                  goto LAB_0056d900;
                }
                iVar3 = cw_protocol_retrieve_str(param_1,iVar3);
                *(int *)((int)__s_00 + 0x14) = iVar3;
              } while (iVar3 != 0);
              if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(__s), iVar3 != 0)) {
                pcVar7 = "[CW_ERROR]%32s():%4d failed to read data\n";
                uVar4 = 0x10f;
LAB_0056da3c:
                printf(pcVar7,"cw_ac_descriptor_parse",uVar4);
              }
LAB_0056d900:
              cw_ac_descriptor_val_free(__s);
              return 0xffffffff;
            }
            if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_0056d980;
            uVar2 = (uint)*(byte *)((int)__s + 0xb);
            pcVar7 = "[CW_ERROR]%32s():%4d dtls policy(0x%02x) is wrong\n";
            uVar4 = 0xdd;
          }
          else {
            if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_0056d980;
            uVar2 = (uint)*(byte *)(__s + 5);
            pcVar7 = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
            uVar4 = 0xd4;
          }
        }
        else {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0056d980;
          uVar2 = (uint)*(byte *)((int)__s + 9);
          pcVar7 = "[CW_ERROR]%32s():%4d rmac field(%d) is wrong\n";
          uVar4 = 0xcb;
        }
      }
      else {
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0056d980;
        uVar2 = (uint)*(byte *)(__s + 4);
        pcVar7 = "[CW_ERROR]%32s():%4d security(0x%02x) is wrong\n";
        uVar4 = 0xc2;
      }
      printf(pcVar7,"cw_ac_descriptor_parse",uVar4,uVar2);
      goto LAB_0056d980;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056d980;
    uVar1 = __s[3];
    uVar5 = __s[2];
    pcVar7 = "[CW_ERROR]%32s():%4d active wtp(%d) is bigger than mac wtps(%d)\n";
    uVar4 = 0xb9;
  }
  printf(pcVar7,"cw_ac_descriptor_parse",uVar4,(uint)uVar5,(uint)uVar1);
LAB_0056d980:
  FUN_00407df0(__s);
  return 0xffffffff;
}

