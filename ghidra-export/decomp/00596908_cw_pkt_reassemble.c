// func cw_pkt_reassemble @ 00596908 size=2444

undefined4 cw_pkt_reassemble(int param_1,int *param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  void *pvVar12;
  size_t __n;
  undefined4 uVar13;
  int iVar14;
  char *pcVar15;
  size_t __n_00;
  int iVar16;
  
  if (param_1 == 0) {
    uVar13 = 0x282;
    pcVar15 = "NULL != session";
LAB_00596d04:
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_pkt_reassemble",uVar13,pcVar15);
    return 0xffffffff;
  }
  if (param_2 == (int *)0x0) {
    uVar13 = 0x283;
    pcVar15 = "NULL != pkt_buff";
    goto LAB_00596d04;
  }
  if (*param_2 == 0) {
    uVar13 = 0x284;
    pcVar15 = "NULL != pkt_buff->buf";
    goto LAB_00596d04;
  }
  if (*(ushort *)(param_2 + 1) < 9) {
    uVar13 = 0x285;
    pcVar15 = "pkt_buff->len > CW_HDR_LEN";
    goto LAB_00596d04;
  }
  iVar3 = cw_header_flag_f_get();
  if (iVar3 != 1) {
    uVar13 = 0x286;
    pcVar15 = "1 == cw_header_flag_f_get(pkt_buff->buf)";
    goto LAB_00596d04;
  }
  iVar16 = param_1 + 0x14;
  iVar3 = cw_header_fragid_get(*param_2);
  iVar4 = FUN_00407fe0(iVar16);
  if (iVar4 == 0) {
    *(int *)(param_1 + 4) = iVar3;
    iVar3 = cw_frag_timer_start(param_1);
    if (iVar3 != -1) goto LAB_00596a18;
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(0x10), iVar3 == 0))
    goto LAB_00596d40;
    pcVar15 = "[CW_ERROR]%32s():%4d start frag timer failed\n";
    uVar13 = 0x294;
  }
  else {
    iVar5 = *(int *)(param_1 + 4);
    if (iVar5 != iVar3) {
      if (((iVar3 <= iVar5) || (0x80 < iVar3 - iVar5)) &&
         ((iVar5 <= iVar3 || (iVar5 - iVar3 < 0x81)))) {
        if (capwap_err_switch == 0) {
          return 0;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0;
        }
        printf("[CW_ERROR]%32s():%4d the fragment ID(%d) not match frag ID(%d).\n",
               "cw_pkt_reassemble",0x2ae,iVar3,*(undefined4 *)(param_1 + 4));
        return 0;
      }
      if ((capwap_warning_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[CW_WARNING]%32s():%4d receive a new frag id packet(%d),abandon old frag packet(%d)\n"
               ,"cw_pkt_reassemble",0x2a1,iVar3,*(undefined4 *)(param_1 + 4));
      }
      cw_frag_mngr_frag_free(param_1);
      *(int *)(param_1 + 4) = iVar3;
      iVar3 = cw_frag_timer_start(param_1);
      if (iVar3 == -1) {
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_00596d40;
        pcVar15 = "[CW_ERROR]%32s():%4d start frag timer failed\n";
        uVar13 = 0x2a7;
        goto LAB_00596da8;
      }
    }
    if (iVar4 < 3000) {
LAB_00596a18:
      pvVar6 = (void *)FUN_00408450(0x10,0x11c);
      if (pvVar6 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc pkt node failed\n","cw_frag_pkt_add",0x11e);
        }
LAB_00596cb0:
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d frag packet add to frag list failed\n","cw_pkt_reassemble",
               0x2bf);
        return 0xffffffff;
      }
      memset(pvVar6,0,0x10);
      puVar7 = (undefined4 *)cw_pkt_buf_create(*(undefined2 *)(param_2 + 1));
      *(undefined4 **)((int)pvVar6 + 0xc) = puVar7;
      if (puVar7 == (undefined4 *)0x0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc pkt buf failed\n","cw_frag_pkt_add",0x124);
        }
        FUN_00407df0(pvVar6);
        goto LAB_00596cb0;
      }
      memcpy((void *)*puVar7,(void *)*param_2,(uint)*(ushort *)(param_2 + 1));
      *(undefined2 *)(*(int *)((int)pvVar6 + 0xc) + 4) = *(undefined2 *)(param_2 + 1);
      iVar3 = FUN_00407fe0(iVar16);
      if (iVar3 == 0) {
        iVar4 = *(int *)((int)pvVar6 + 0xc);
        iVar3 = param_2[4];
        *(int *)(iVar4 + 0x14) = param_2[5];
        *(int *)(iVar4 + 0x10) = iVar3;
        FUN_004086b0(iVar16,pvVar6);
      }
      else {
        iVar3 = FUN_004081b0(iVar16);
        iVar4 = *(int *)((int)pvVar6 + 0xc);
        uVar13 = *(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x10);
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x14);
        *(undefined4 *)(iVar4 + 0x10) = uVar13;
        uVar8 = cw_header_fragoffset_get(*param_2);
        iVar3 = FUN_00408610(iVar16);
        while (iVar3 != 0) {
          uVar9 = cw_header_fragoffset_get(**(undefined4 **)(iVar3 + 0xc));
          if (uVar9 < uVar8) {
            FUN_004083a0(iVar3,pvVar6);
            break;
          }
          iVar4 = FUN_004081b0(iVar16);
          if (iVar3 == iVar4) {
            FUN_00408170(iVar3,pvVar6);
            break;
          }
          iVar3 = FUN_00407f80();
        }
      }
      iVar3 = FUN_004081b0(iVar16);
      if (iVar3 == 0) {
        iVar3 = *param_2;
      }
      else {
        iVar4 = *(int *)(iVar3 + 0xc);
        iVar3 = param_2[6];
        *(int *)(iVar4 + 0x1c) = param_2[7];
        *(int *)(iVar4 + 0x18) = iVar3;
        iVar3 = *param_2;
      }
      uVar1 = *(ushort *)(param_2 + 1);
      iVar3 = cw_header_length_get(iVar3);
      *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + ((uint)uVar1 - iVar3);
      iVar4 = cw_header_flag_l_get(*param_2);
      if (iVar4 == 1) {
        iVar4 = cw_header_fragoffset_get(*param_2);
        *(undefined4 *)(param_1 + 0x10) = 1;
        *(uint *)(param_1 + 0xc) = iVar4 * 8 + ((uint)uVar1 - iVar3);
      }
      if (*(int *)(param_1 + 0x10) != 1) {
        return 0;
      }
      if (*(int *)(param_1 + 8) != *(int *)(param_1 + 0xc)) {
        if (*(int *)(param_1 + 8) <= *(int *)(param_1 + 0xc)) {
          return 0;
        }
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_00596d40;
        pcVar15 = "[CW_ERROR]%32s():%4d current packet len is bigger than total len\n";
        uVar13 = 0x2e5;
        goto LAB_00596da8;
      }
      if (capwap_debug_switch == 0) {
        iVar3 = *param_2;
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *param_2;
        }
        else {
          printf("[CW_DEBUG]%32s():%4d start reassembling frag packets\n","cw_pkt_reassemble",0x2d5)
          ;
          iVar3 = *param_2;
        }
      }
      if (iVar3 == 0) {
        uVar13 = 0x186;
        pcVar15 = "NULL != pkt_buff->buf";
LAB_005971fc:
        printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_frag_list_read",uVar13,pcVar15);
      }
      else {
        iVar3 = FUN_00407fe0(iVar16);
        if (iVar3 < 1) {
          uVar13 = 0x188;
          pcVar15 = "frag_num > 0";
          goto LAB_005971fc;
        }
        iVar3 = FUN_00408610(iVar16);
        iVar3 = cw_header_flag_f_get(**(undefined4 **)(iVar3 + 0xc));
        if (iVar3 == 1) {
          pvVar6 = (void *)FUN_00408450(0xcc00,0x193);
          if (pvVar6 == (void *)0x0) {
            if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar15 = "[CW_ERROR]%32s():%4d malloc failed.\n";
              uVar13 = 0x195;
              goto LAB_00596f14;
            }
          }
          else {
            memset(pvVar6,0,0xcc00);
            iVar5 = 0;
            iVar4 = FUN_004081b0(iVar16);
            __n_00 = 0;
            iVar3 = 0;
            while (iVar4 != 0) {
              iVar16 = cw_header_length_get(**(undefined4 **)(iVar4 + 0xc));
              sVar2 = *(short *)(*(undefined4 **)(iVar4 + 0xc) + 1);
              iVar10 = cw_header_fragoffset_get(**(undefined4 **)(iVar4 + 0xc));
              iVar10 = iVar10 << 3;
              if (iVar5 != iVar10) {
                if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  pcVar15 = "[CW_ERROR]%32s():%4d pkt%d\'s frag offset[%d] not match frag list.\n";
                  uVar13 = 0x1a4;
LAB_00597144:
                  printf(pcVar15,"cw_frag_list_read",uVar13,iVar3,iVar10);
                }
                goto LAB_00597100;
              }
              piVar11 = *(int **)(iVar4 + 0xc);
              sVar2 = sVar2 - (short)iVar16;
              pvVar12 = (void *)*piVar11;
              if (iVar3 == 0) {
                iVar10 = piVar11[5];
                __n = (size_t)*(ushort *)(piVar11 + 1);
                iVar14 = piVar11[4];
                iVar16 = piVar11[7];
                param_2[5] = iVar10;
                param_2[4] = iVar14;
                param_2[8] = iVar16 - iVar10;
              }
              else {
                pvVar12 = (void *)((int)pvVar12 + iVar16);
                __n = (size_t)sVar2;
              }
              iVar16 = __n_00 + __n;
              if (0xcc00 < iVar16) {
                if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  iVar10 = 0xcc00;
                  pcVar15 = "[CW_ERROR]%32s():%4d pkt\'s total length(%d) is over buf(%d).\n";
                  uVar13 = 0x1c8;
                  iVar3 = iVar16;
                  goto LAB_00597144;
                }
                goto LAB_00597100;
              }
              memcpy((void *)((int)pvVar6 + __n_00),pvVar12,__n);
              iVar4 = FUN_00408680(iVar4);
              iVar5 = (int)(short)(sVar2 + (short)iVar5);
              __n_00 = (size_t)(short)iVar16;
              iVar3 = iVar3 + 1;
            }
            if ((int)__n_00 <= param_2[2]) {
              pvVar12 = (void *)*param_2;
LAB_00597184:
              *(undefined2 *)((int)param_2 + 6) = 0;
              *(short *)(param_2 + 1) = (short)__n_00;
              memcpy(pvVar12,pvVar6,__n_00);
              cw_header_flag_f_set(*param_2,0);
              cw_header_flag_l_set(*param_2,0);
              cw_header_fragid_set(*param_2,0);
              cw_header_fragoffset_set(*param_2,0);
              FUN_00407df0(pvVar6);
              cw_frag_mngr_frag_free(param_1);
              return 1;
            }
            FUN_00407df0(*param_2);
            iVar3 = FUN_00408450(__n_00,0x1d3);
            *param_2 = iVar3;
            if (iVar3 != 0) {
              param_2[2] = __n_00;
              pvVar12 = (void *)*param_2;
              goto LAB_00597184;
            }
            if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[CW_ERROR]%32s():%4d malloc failed.\n","cw_frag_list_read",0x1d5);
            }
LAB_00597100:
            FUN_00407df0(pvVar6);
          }
        }
        else if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar15 = "[CW_ERROR]%32s():%4d last packet in frag list is not last frag packet\n";
          uVar13 = 0x18e;
LAB_00596f14:
          printf(pcVar15,"cw_frag_list_read",uVar13);
        }
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00596d40;
      pcVar15 = "[CW_ERROR]%32s():%4d reassembling frag packets failed\n";
      uVar13 = 0x2d8;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00596d40;
      pcVar15 = "[CW_ERROR]%32s():%4d the fragment number is to up limited.\n";
      uVar13 = 0x2b7;
    }
  }
LAB_00596da8:
  printf(pcVar15,"cw_pkt_reassemble",uVar13);
LAB_00596d40:
  cw_frag_mngr_frag_free(param_1);
  return 0xffffffff;
}

