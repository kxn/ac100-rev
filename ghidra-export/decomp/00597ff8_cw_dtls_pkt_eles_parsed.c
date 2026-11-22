// func cw_dtls_pkt_eles_parsed @ 00597ff8 size=464

undefined4 cw_dtls_pkt_eles_parsed(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  void *__s;
  undefined1 uVar6;
  undefined2 uVar5;
  int iVar4;
  char *__format;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_dtls_pkt_eles_parsed",0x3a);
    }
  }
  else {
    uVar1 = *(ushort *)(param_1 + 4);
    while( true ) {
      uVar2 = *(ushort *)(param_1 + 6);
      uVar3 = 0xffffffff;
      if ((uint)uVar1 <= (uint)uVar2) break;
      __s = (void *)FUN_00408450(0x20,0x44);
      if (__s == (void *)0x0) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_005980e4;
        __format = "[CW_ERROR]%32s():%4d out of memory\n";
        uVar3 = 0x46;
LAB_00598174:
        printf(__format,"cw_dtls_pkt_eles_parsed",uVar3);
LAB_005980e4:
        cw_dtls_pkt_eles_free(param_2);
        return 0xffffffff;
      }
      memset(__s,0,0x20);
      FUN_004086b0(param_2 + 4,__s);
      uVar6 = cw_protocol_retrieve8(param_1);
      *(undefined1 *)((int)__s + 0xc) = uVar6;
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)((int)__s + 0xe) = uVar5;
      uVar5 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)((int)__s + 0x10) = uVar5;
      cw_protocol_retrieve_bytes(param_1,(int)__s + 0x12,6);
      uVar3 = cw_protocol_retrieve16(param_1);
      *(short *)((int)__s + 0x18) = (short)uVar3;
      uVar3 = cw_protocol_retrieve_raw_bytes(param_1,uVar3);
      *(undefined4 *)((int)__s + 0x1c) = uVar3;
      if (*(ushort *)((int)__s + 0x18) + 0xd != (uint)*(ushort *)(param_1 + 6) - (uint)uVar2) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_005980e4;
        __format = "[CW_ERROR]%32s():%4d pasred dtls element failed.\n";
        uVar3 = 0x57;
        goto LAB_00598174;
      }
      uVar1 = *(ushort *)(param_1 + 4);
    }
    if (uVar2 == uVar1) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

