// func cw_priv_chnl_scan_parse @ 005ad7dc size=660

undefined4 cw_priv_chnl_scan_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x81);
  if (__s == (byte *)0x0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_chnl_scan_parse",0x84);
    }
  }
  else {
    memset(__s,0,8);
    iVar2 = cw_protocol_retrieve8(param_1);
    *__s = (byte)iVar2;
    if (iVar2 - 100U < 0x65) {
      iVar2 = cw_protocol_retrieve8(param_1);
      __s[1] = (byte)iVar2;
      if (iVar2 == 0) {
        uVar3 = (uint)*(ushort *)(param_2 + 0xe);
LAB_005ad860:
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != uVar3) {
          return 0xffffffff;
        }
        return 0;
      }
      iVar6 = 0;
      iVar2 = FUN_00408450(iVar2 << 3,0x99);
      *(int *)(__s + 4) = iVar2;
      if (iVar2 != 0) {
        for (; iVar6 < (int)(uint)__s[1]; iVar6 = iVar6 + 1) {
          iVar2 = *(int *)(__s + 4);
          iVar7 = iVar6 * 8;
          uVar4 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar2 + iVar7) = uVar4;
          iVar2 = *(int *)(__s + 4);
          uVar4 = cw_protocol_retrieve8(param_1);
          *(undefined1 *)(iVar2 + iVar7 + 1) = uVar4;
          iVar5 = *(int *)(__s + 4);
          iVar2 = FUN_00408450(*(byte *)(iVar5 + iVar7 + 1) + 1,0xa4);
          *(int *)(iVar5 + iVar7 + 4) = iVar2;
          if (iVar2 == 0) {
            iVar2 = (iVar6 + -1) * 8;
            for (iVar5 = 0; iVar5 != iVar6; iVar5 = iVar5 + 1) {
              if (*(int *)(*(int *)(__s + 4) + iVar2 + 4) != 0) {
                FUN_00407df0();
                FUN_00407df0(*(undefined4 *)(__s + 4));
                FUN_00407df0(__s);
              }
              iVar2 = iVar2 + -8;
            }
            uVar3 = (uint)*(ushort *)(param_2 + 0xe);
            goto LAB_005ad860;
          }
          memset(*(void **)(*(int *)(__s + 4) + iVar7 + 4),0,
                 *(byte *)(*(int *)(__s + 4) + iVar7 + 1) + 1);
          cw_protocol_retrieve_bytes
                    (param_1,*(undefined4 *)(*(int *)(__s + 4) + iVar7 + 4),
                     *(undefined1 *)(*(int *)(__s + 4) + iVar7 + 1));
        }
        uVar3 = (uint)*(ushort *)(param_2 + 0xe);
        goto LAB_005ad860;
      }
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_chnl_scan_parse",0x9c);
      }
    }
    else if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d scan_time:%d error\n","cw_priv_chnl_scan_parse",0x8c,(uint)*__s);
    }
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}

