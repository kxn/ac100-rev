// func cw_priv_ndp_para_parse @ 005b7c44 size=520

undefined4 cw_priv_ndp_para_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  void *__s;
  uint uVar4;
  undefined1 uVar7;
  undefined2 uVar6;
  int iVar5;
  char *__format;
  undefined4 uVar8;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x34,0x80);
  if (__s == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ndp_para_parse",0x83);
    return 0xffffffff;
  }
  memset(__s,0,0x34);
  cw_protocol_retrieve_bytes(param_1,__s,6);
  uVar4 = cw_protocol_retrieve8(param_1);
  *(char *)((int)__s + 6) = (char)uVar4;
  if (uVar4 < 0x20) {
    uVar7 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)((int)__s + 7) = uVar7;
    uVar6 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)((int)__s + 8) = uVar6;
    uVar6 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)((int)__s + 10) = uVar6;
    uVar6 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)((int)__s + 0xc) = uVar6;
    uVar6 = cw_protocol_retrieve16(param_1);
    *(undefined2 *)((int)__s + 0xe) = uVar6;
    uVar7 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)((int)__s + 0x10) = uVar7;
    uVar7 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)((int)__s + 0x11) = uVar7;
    uVar7 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)((int)__s + 0x12) = uVar7;
    uVar4 = cw_protocol_retrieve8(param_1);
    *(char *)((int)__s + 0x13) = (char)uVar4;
    if (uVar4 < 0x21) {
      if (uVar4 == 0) {
        uVar3 = *(ushort *)(param_2 + 0xe);
      }
      else {
        cw_protocol_retrieve_bytes(param_1,(int)__s + 0x14,uVar4);
        uVar3 = *(ushort *)(param_2 + 0xe);
      }
      *(void **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)uVar3) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_005b7dd0;
    bVar1 = *(byte *)((int)__s + 0x13);
    __format = "[CW_ERROR]%32s():%4d channel cnt(%d) is exceeded\n";
    uVar8 = 0x9d;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_005b7dd0;
    bVar1 = *(byte *)((int)__s + 6);
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar8 = 0x8d;
  }
  printf(__format,"cw_priv_ndp_para_parse",uVar8,(uint)bVar1);
LAB_005b7dd0:
  FUN_00407df0(__s);
  return 0xffffffff;
}

