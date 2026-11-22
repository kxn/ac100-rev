// func cw_add_station_parse @ 00570338 size=828

undefined4 cw_add_station_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte *__s;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  short sVar8;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x10,0x68);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_add_station_parse",0x6b);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar4 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar4;
  if (uVar4 < 0x20) {
    iVar5 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar5;
    if ((iVar5 == 6) || (iVar5 == 8)) {
      if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < iVar5) {
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_0057050c;
        pcVar6 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
        uVar7 = 0x85;
      }
      else {
        iVar5 = cw_protocol_retrieve_raw_bytes(param_1,iVar5);
        *(int *)(__s + 4) = iVar5;
        if (iVar5 != 0) {
          sVar8 = (*(short *)(param_2 + 0xe) + -2) - (ushort)__s[1];
          iVar5 = (int)sVar8;
          if (iVar5 < 1) {
            if (iVar5 == 0) {
              uVar3 = *(ushort *)(param_2 + 0xe);
LAB_00570444:
              *(byte **)(param_2 + 0x10) = __s;
              if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)uVar3) {
                return 0xffffffff;
              }
              return 0;
            }
            if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[CW_ERROR]%32s():%4d length of message element(%d) is wrong\n",
                     "cw_add_station_parse",0xad,(uint)*(ushort *)(param_2 + 0xe));
            }
          }
          else if (((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < iVar5)
                  || (0x200 < iVar5)) {
            if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              pcVar6 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
              uVar7 = 0x9a;
LAB_005705bc:
              printf(pcVar6,"cw_add_station_parse",uVar7);
            }
          }
          else {
            iVar5 = cw_protocol_retrieve_str(param_1,sVar8);
            *(int *)(__s + 0xc) = iVar5;
            if (iVar5 != 0) {
              *(short *)(__s + 8) = sVar8;
              uVar3 = *(ushort *)(param_2 + 0xe);
              goto LAB_00570444;
            }
            if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              pcVar6 = "[CW_ERROR]%32s():%4d failed to read vlan name\n";
              uVar7 = 0xa4;
              goto LAB_005705bc;
            }
          }
          FUN_00407df0(*(undefined4 *)(__s + 4));
          goto LAB_0057050c;
        }
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_0057050c;
        pcVar6 = "[CW_ERROR]%32s():%4d failed to read mac address\n";
        uVar7 = 0x8e;
      }
      printf(pcVar6,"cw_add_station_parse",uVar7);
      goto LAB_0057050c;
    }
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0057050c;
    bVar1 = __s[1];
    pcVar6 = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
    uVar7 = 0x7d;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0057050c;
    bVar1 = *__s;
    pcVar6 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar7 = 0x74;
  }
  printf(pcVar6,"cw_add_station_parse",uVar7,(uint)bVar1);
LAB_0057050c:
  FUN_00407df0(__s);
  return 0xffffffff;
}

