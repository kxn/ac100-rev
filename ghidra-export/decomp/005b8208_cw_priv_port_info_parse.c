// func cw_priv_port_info_parse @ 005b8208 size=764

undefined4 cw_priv_port_info_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  byte *__s;
  uint uVar5;
  byte bVar7;
  int iVar6;
  void *__s_00;
  undefined1 uVar8;
  int *piVar9;
  char *__format;
  undefined4 uVar10;
  int iVar11;
  byte *pbVar12;
  int local_40 [7];
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0xa5);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_port_info_parse",0xa8);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar5 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar5;
  if (uVar5 < 0x41) {
    if (uVar5 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(uVar5 << 3,0xb7);
      *(void **)(__s + 4) = __s_00;
      if (__s_00 == (void *)0x0) {
        if (capwap_err_switch == 0) {
          bVar7 = *__s;
        }
        else {
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            bVar7 = *__s;
          }
          else {
            __format = "[CW_ERROR]%32s():%4d malloc phy info list failed\n";
            uVar10 = 0xba;
LAB_005b84b4:
            printf(__format,"cw_priv_port_info_parse",uVar10);
            bVar7 = *__s;
          }
        }
        goto LAB_005b8288;
      }
      memset(__s_00,0,(uint)*__s << 3);
      for (uVar5 = 0; (int)uVar5 < (int)(uint)*__s; uVar5 = uVar5 + 1) {
        iVar6 = *(int *)(__s + 4);
        iVar11 = uVar5 * 8;
        uVar8 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar11) = uVar8;
        iVar6 = *(int *)(__s + 4);
        uVar8 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar11 + 1) = uVar8;
        iVar6 = *(int *)(__s + 4);
        uVar10 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(iVar6 + iVar11 + 4) = uVar10;
        pbVar12 = (byte *)(*(int *)(__s + 4) + iVar11);
        if (*pbVar12 != uVar5) {
LAB_005b8484:
          if (capwap_err_switch == 0) {
            bVar7 = *__s;
            goto LAB_005b8288;
          }
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            bVar7 = *__s;
            goto LAB_005b8288;
          }
          __format = "[CW_ERROR]%32s():%4d check parameters failed\n";
          uVar10 = 0xc9;
          goto LAB_005b84b4;
        }
        bVar7 = pbVar12[1];
        iVar11 = *(int *)(pbVar12 + 4);
        memcpy(local_40,&DAT_006eceb0,0x18);
        iVar6 = 0;
        piVar9 = local_40;
        do {
          iVar6 = iVar6 + 4;
          if (*piVar9 == iVar11) {
            bVar4 = true;
            goto LAB_005b8454;
          }
          piVar9 = (int *)((int)local_40 + iVar6);
        } while (iVar6 != 0x18);
        bVar4 = false;
LAB_005b8454:
        bVar3 = true;
        if ((bVar7 != 0) && (bVar7 != 1)) {
          bVar3 = bVar7 == 2;
        }
        if ((!bVar4) || (!bVar3)) goto LAB_005b8484;
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(byte **)(param_2 + 0x10) = __s;
    uVar10 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar10 = 0;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      bVar7 = *__s;
    }
    else {
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        bVar7 = *__s;
      }
      else {
        printf("[CW_ERROR]%32s():%4d phy_num(%d) is too large\n","cw_priv_port_info_parse",0xb1,
               (uint)*__s);
        bVar7 = *__s;
      }
    }
LAB_005b8288:
    if ((bVar7 != 0) && (*(int *)(__s + 4) != 0)) {
      FUN_00407df0();
      __s[4] = 0;
      __s[5] = 0;
      __s[6] = 0;
      __s[7] = 0;
    }
    FUN_00407df0(__s);
    uVar10 = 0xffffffff;
  }
  return uVar10;
}

