// func cw_control_header_parse @ 005a1268 size=540

undefined4 cw_control_header_parse(int *param_1,uint *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uVar4;
  char *__format;
  undefined4 uVar5;
  uint uVar6;
  uint local_14;
  
  local_14 = 0;
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (param_2 == (uint *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_parse",0x14c,
           "((NULL != pkt_buf) && (NULL != pkt_buf->buf) && (NULL != ctrl_hdr))");
  }
  else {
    uVar4 = *(ushort *)((int)param_1 + 6);
    uVar6 = (uint)uVar4;
    if ((*(ushort *)(param_1 + 1) < uVar6) || ((int)(*(ushort *)(param_1 + 1) - uVar6) < 8)) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d length isn\'t enough\n","cw_control_header_parse",0x150);
      }
    }
    else {
      memcpy(&local_14,(void *)(*param_1 + uVar6),4);
      *(ushort *)((int)param_1 + 6) = uVar4 + 4;
      *param_2 = local_14;
      if ((local_14 - 1 < 0x1a) || (local_14 - 0x33dd01 < 2)) {
        *(undefined1 *)(param_2 + 1) =
             *(undefined1 *)(*param_1 + (uint)*(ushort *)((int)param_1 + 6));
        sVar1 = *(short *)((int)param_1 + 6);
        uVar4 = sVar1 + 1;
        *(ushort *)((int)param_1 + 6) = uVar4;
        uVar2 = *(undefined2 *)(*param_1 + (uint)uVar4);
        *(short *)((int)param_1 + 6) = sVar1 + 3;
        *(undefined2 *)((int)param_2 + 6) = uVar2;
        *(undefined1 *)(param_2 + 2) =
             *(undefined1 *)(*param_1 + (uint)*(ushort *)((int)param_1 + 6));
        *(short *)((int)param_1 + 6) = *(short *)((int)param_1 + 6) + 1;
        if (*(char *)(param_2 + 2) == '\0') {
          return 0;
        }
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        uVar6 = (uint)*(byte *)(param_2 + 2);
        __format = "[CW_ERROR]%32s():%4d flags(%d) isn\'t zeroed\n";
        uVar5 = 0x168;
      }
      else {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        uVar6 = *param_2;
        __format = "[CW_ERROR]%32s():%4d message type(%d) is unrecognised\n";
        uVar5 = 0x159;
      }
      printf(__format,"cw_control_header_parse",uVar5,uVar6);
    }
  }
  return 0xffffffff;
}

