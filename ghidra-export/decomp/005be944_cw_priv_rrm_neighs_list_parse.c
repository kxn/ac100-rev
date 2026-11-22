// func cw_priv_rrm_neighs_list_parse @ 005be944 size=892

undefined4 cw_priv_rrm_neighs_list_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  byte bVar4;
  undefined4 uVar3;
  void *__s_00;
  undefined1 uVar5;
  char *__format;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0xb8);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar9 = is_target_debug_ap();
    if (iVar9 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_rrm_neighs_list_parse",0xbb);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (0x1f < uVar2) {
    if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_rrm_neighs_list_parse",0xc4,
             (uint)*__s);
    }
    FUN_00407df0(__s);
    return 0xffffffff;
  }
  bVar4 = cw_protocol_retrieve8(param_1);
  __s[1] = bVar4;
  uVar2 = cw_protocol_retrieve16(param_1);
  *(short *)(__s + 2) = (short)uVar2;
  if (uVar2 < 0x21) {
    if (uVar2 != 0) {
      __s_00 = (void *)FUN_00408450(uVar2 * 0xc,0xd4);
      *(void **)(__s + 4) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
          __format = "[CW_ERROR]%32s():%4d failed to malloc neighbor list\n";
          uVar3 = 0xd7;
LAB_005bec7c:
          printf(__format,"cw_priv_rrm_neighs_list_parse",uVar3);
        }
        goto LAB_005bec0c;
      }
      iVar9 = 0;
      memset(__s_00,0,(uint)*(ushort *)(__s + 2) * 0xc);
      while (iVar9 < (int)(uint)*(ushort *)(__s + 2)) {
        iVar8 = iVar9 * 0xc;
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 4) + iVar8,6);
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar8 + 6) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar8 + 7) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar2 = (uint)*(byte *)(iVar6 + iVar8 + 7);
        if (uVar2 == 0) {
          iVar9 = iVar9 + 1;
        }
        else {
          uVar3 = FUN_00408450(uVar2 * 3,0xe3);
          *(undefined4 *)(iVar6 + iVar8 + 8) = uVar3;
          if (*(int *)(*(int *)(__s + 4) + iVar8 + 8) == 0) {
            if ((capwap_err_switch == 0) || (iVar9 = is_target_debug_ap(), iVar9 == 0))
            goto LAB_005bec0c;
            __format = "[CW_ERROR]%32s():%4d failed to malloc neighbor\'s rssi list\n";
            uVar3 = 0xe6;
            goto LAB_005bec7c;
          }
          iVar6 = 0;
          while( true ) {
            iVar10 = iVar6 * 3;
            if ((int)(uint)*(byte *)(*(int *)(__s + 4) + iVar8 + 7) <= iVar6) break;
            iVar7 = *(int *)(*(int *)(__s + 4) + iVar8 + 8);
            uVar5 = cw_protocol_retrieve8(param_1);
            iVar6 = iVar6 + 1;
            *(undefined1 *)(iVar7 + iVar10) = uVar5;
            iVar7 = *(int *)(*(int *)(__s + 4) + iVar8 + 8);
            uVar5 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar7 + iVar10 + 1) = uVar5;
            iVar7 = *(int *)(*(int *)(__s + 4) + iVar8 + 8);
            uVar5 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar7 + iVar10 + 2) = uVar5;
          }
          iVar9 = iVar9 + 1;
        }
      }
    }
    *(byte **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
      printf("[CW_ERROR]%32s():%4d neighbor cnt(%d) is exceeded\n","cw_priv_rrm_neighs_list_parse",
             0xcd,(uint)*(ushort *)(__s + 2));
    }
LAB_005bec0c:
    cw_priv_rrm_neighs_list_val_free(__s);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

