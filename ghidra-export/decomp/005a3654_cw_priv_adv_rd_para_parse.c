// func cw_priv_adv_rd_para_parse @ 005a3654 size=660

undefined4 cw_priv_adv_rd_para_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  byte bVar7;
  undefined2 uVar6;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x1c,0x90);
  if (__s == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_adv_rd_para_parse",0x93);
    }
  }
  else {
    memset(__s,0,0x1c);
    uVar3 = cw_protocol_retrieve8(param_1);
    *__s = (byte)uVar3;
    if (uVar3 < 0x20) {
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[1] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[2] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[3] = bVar7;
      uVar6 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 4) = uVar6;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[6] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[7] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[8] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[9] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[10] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[0xb] = bVar7;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[0xc] = bVar7;
      uVar6 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 0xe) = uVar6;
      bVar7 = cw_protocol_retrieve8(param_1);
      __s[0x10] = bVar7;
      uVar3 = (uint)*(ushort *)(param_2 + 0xe);
      if (((uVar3 - 0x14 < 2) || (uVar3 == 0x1a)) || (uVar3 == 0x1b)) {
        bVar7 = cw_protocol_retrieve8(param_1);
        __s[0x11] = bVar7;
        bVar7 = cw_protocol_retrieve8(param_1);
        __s[0x12] = bVar7;
        bVar7 = cw_protocol_retrieve8(param_1);
        __s[0x13] = bVar7;
        bVar7 = cw_protocol_retrieve8(param_1);
        __s[0x14] = bVar7;
      }
      else {
        __s[0x11] = 0xff;
        __s[0x12] = 1;
        __s[0x13] = 0xff;
        __s[0x14] = 1;
      }
      if ((*(ushort *)(param_2 + 0xe) & 1) == 0) {
        __s[0x15] = 0xff;
      }
      else {
        bVar7 = cw_protocol_retrieve8(param_1);
        __s[0x15] = bVar7;
      }
      if (*(ushort *)(param_2 + 0xe) < 0x16) {
        memset(__s + 0x16,0xff,6);
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      else {
        cw_protocol_retrieve_bytes(param_1,__s + 0x16,6);
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      *(byte **)(param_2 + 0x10) = __s;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
        uVar4 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_adv_rd_para_parse",0x9b,
               (uint)*__s);
      }
      FUN_00407df0(__s);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

