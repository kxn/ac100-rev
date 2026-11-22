// func rdmngr_db_check_and_do_peer_radio_linked_modify @ 0061a558 size=2044

undefined4
rdmngr_db_check_and_do_peer_radio_linked_modify
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          short param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,char param_10,
          undefined4 param_11,undefined4 param_12)

{
  char cVar1;
  short sVar2;
  char cVar7;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar8;
  char *pcVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  undefined4 in_stack_00000048;
  int in_stack_00000054;
  int in_stack_00000058;
  int in_stack_0000005c;
  undefined4 *in_stack_00000060;
  short *in_stack_00000064;
  int *in_stack_00000068;
  
  if (in_stack_00000054 == 0) {
    return 0xffffffff;
  }
  if (in_stack_0000005c == 0) {
    return 0xffffffff;
  }
  if (in_stack_00000060 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if (in_stack_00000064 == (short *)0x0) {
    return 0xffffffff;
  }
  if (in_stack_00000068 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*(char *)(in_stack_0000005c + 2) == '\x01') {
    if (*(char *)(in_stack_00000054 + 9) != (char)((uint)param_3 >> 0x10)) {
      *in_stack_00000060 = 1;
      goto LAB_0061a66c;
    }
    cVar7 = *(char *)(in_stack_0000005c + 1);
  }
  else {
LAB_0061a66c:
    cVar7 = *(char *)(in_stack_0000005c + 1);
  }
  if (cVar7 != '\x02') {
    if (cVar7 == '\x03') {
      if (0x32 < in_stack_00000058) {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[RDMNGR_ERROR]%s()/%d index exceeds rrst chnl max cnt\n";
        uVar11 = 0x72e;
LAB_0061aa98:
        printf(pcVar9,"rdmngr_db_check_and_do_peer_radio_linked_modify",uVar11);
        return 0xffffffff;
      }
      sVar2 = *(short *)(in_stack_0000005c + (in_stack_00000058 + 0x38) * 2 + 4);
      if (sVar2 == 0) {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[RDMNGR_ERROR]%s()/%d mutex chnl not enough\n";
        uVar11 = 0x733;
        goto LAB_0061aa98;
      }
      *(short *)(in_stack_00000054 + 0xc) = sVar2;
      *in_stack_00000060 = 1;
    }
    else if (cVar7 == '\x01') {
      if ((int)*(short *)(in_stack_00000054 + 0xc) == param_4 >> 0x10) {
        cVar7 = *(char *)(in_stack_0000005c + 3);
        goto LAB_0061a694;
      }
      *in_stack_00000060 = 1;
    }
    goto LAB_0061a690;
  }
  iVar13 = 0;
  iVar6 = in_stack_0000005c;
  do {
    if (rdmngr_debug_switch == 0) {
      iVar5 = (int)*(short *)(iVar6 + 0xe);
    }
    else {
      iVar4 = is_target_debug_ap();
      iVar5 = (int)*(short *)(iVar6 + 0xe);
      if (iVar4 != 0) {
        printf("[RDMNGR_DEBUG]%s()/%d compliance loop, channel[%d]=%d\n",
               "rdmngr_db_check_and_do_peer_radio_linked_modify",0x6dd,iVar13,iVar5);
        iVar5 = (int)*(short *)(iVar6 + 0xe);
      }
    }
    if (iVar5 == 0) break;
    if (*(short *)(in_stack_00000054 + 0xc) == iVar5) {
      if (rdmngr_debug_switch == 0) {
        iVar6 = *in_stack_00000068;
      }
      else {
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          iVar6 = *in_stack_00000068;
        }
        else {
          printf("[RDMNGR_DEBUG]%s()/%d isfit_compliance=%d\n",
                 "rdmngr_db_check_and_do_peer_radio_linked_modify",0x6e6,1);
          iVar6 = *in_stack_00000068;
        }
      }
      iVar13 = 0;
      psVar8 = in_stack_00000064;
      goto LAB_0061ab28;
    }
    iVar13 = iVar13 + 1;
    iVar6 = iVar6 + 2;
  } while (iVar13 != 0x33);
  if ((rdmngr_debug_switch != 0) &&
     (iVar6 = is_target_debug_ap(in_stack_0000005c + 0xe), iVar6 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d isfit_compliance=%d\n",
           "rdmngr_db_check_and_do_peer_radio_linked_modify",0x717,0);
  }
  iVar6 = rdmngr_db_get_chnl_from_compliance_chnls
                    (in_stack_0000005c + 0xe,in_stack_00000064,in_stack_00000068);
  if (iVar6 == 0) {
    if (rdmngr_err_switch == 0) {
      cVar7 = *(char *)(in_stack_0000005c + 3);
    }
    else {
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        cVar7 = *(char *)(in_stack_0000005c + 3);
      }
      else {
        pcVar9 = "[RDMNGR_ERROR]%s()/%d fail to get chnl from compliance chnls\n";
        uVar11 = 0x71b;
LAB_0061ab78:
        printf(pcVar9,"rdmngr_db_check_and_do_peer_radio_linked_modify",uVar11);
        cVar7 = *(char *)(in_stack_0000005c + 3);
      }
    }
  }
  else {
    *(short *)(in_stack_00000054 + 0xc) = (short)iVar6;
    iVar6 = *in_stack_00000068 + 1;
    if (iVar6 < 0x33) {
      *in_stack_00000068 = iVar6;
      goto LAB_0061abe0;
    }
    if (rdmngr_err_switch == 0) {
      cVar7 = *(char *)(in_stack_0000005c + 3);
    }
    else {
      iVar6 = is_target_debug_ap();
      if (iVar6 != 0) {
        pcVar9 = "[RDMNGR_ERROR]%s()/%d sc_last_ele_index exceeds rrst chnl max cnt\n";
        uVar11 = 0x721;
        goto LAB_0061ab78;
      }
      cVar7 = *(char *)(in_stack_0000005c + 3);
    }
  }
  goto LAB_0061a694;
  while( true ) {
    sVar2 = *psVar8;
    iVar13 = iVar13 + 1;
    psVar8 = psVar8 + 1;
    if (*(short *)(in_stack_00000054 + 0xc) == sVar2) break;
LAB_0061ab28:
    if (iVar6 < iVar13) {
      iVar6 = iVar6 + 1;
      if (iVar6 < 0x33) {
        *in_stack_00000068 = iVar6;
        in_stack_00000064[iVar6] = *(short *)(in_stack_00000054 + 0xc);
        goto LAB_0061a690;
      }
      if (rdmngr_err_switch == 0) {
        cVar7 = *(char *)(in_stack_0000005c + 3);
        goto LAB_0061a694;
      }
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        cVar7 = *(char *)(in_stack_0000005c + 3);
        goto LAB_0061a694;
      }
      pcVar9 = "[RDMNGR_ERROR]%s()/%d sc_last_ele_index exceeds rrst chnl max cnt\n";
      uVar11 = 0x6f7;
      goto LAB_0061ab78;
    }
  }
  iVar6 = rdmngr_db_get_chnl_from_compliance_chnls
                    (in_stack_0000005c + 0xe,in_stack_00000064,in_stack_00000068);
  if (iVar6 == 0) {
    if (rdmngr_err_switch != 0) {
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        cVar7 = *(char *)(in_stack_0000005c + 3);
        goto LAB_0061a694;
      }
      pcVar9 = "[RDMNGR_ERROR]%s()/%d fail to get chnl from compliance chnls\n";
      uVar11 = 0x703;
      goto LAB_0061ab78;
    }
    cVar7 = *(char *)(in_stack_0000005c + 3);
  }
  else {
    *(short *)(in_stack_00000054 + 0xc) = (short)iVar6;
    iVar6 = *in_stack_00000068 + 1;
    if (0x32 < iVar6) {
      if (rdmngr_err_switch == 0) {
        cVar7 = *(char *)(in_stack_0000005c + 3);
      }
      else {
        iVar6 = is_target_debug_ap();
        if (iVar6 != 0) {
          pcVar9 = "[RDMNGR_ERROR]%s()/%d sc_last_ele_index exceeds rrst chnl max cnt\n";
          uVar11 = 0x70a;
          goto LAB_0061ab78;
        }
        cVar7 = *(char *)(in_stack_0000005c + 3);
      }
      goto LAB_0061a694;
    }
    *in_stack_00000068 = iVar6;
LAB_0061abe0:
    in_stack_00000064[iVar6] = *(short *)(in_stack_00000054 + 0xc);
    *in_stack_00000060 = 1;
LAB_0061a690:
    cVar7 = *(char *)(in_stack_0000005c + 3);
  }
LAB_0061a694:
  if (cVar7 == '\x01') {
    if ((uint)*(byte *)(in_stack_00000054 + 10) != (uint)(param_3 << 0x10) >> 0x18) {
      *in_stack_00000060 = 1;
      goto LAB_0061a6a8;
    }
    cVar7 = *(char *)(in_stack_0000005c + 4);
  }
  else {
    if (cVar7 == '\x02') {
      if (5 < *(byte *)(in_stack_00000054 + 10)) {
        if (rdmngr_err_switch == 0) {
          return 0;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0;
        }
        printf("[RDMNGR_ERROR]%s()/%d invalid peer_rd_entry->rd_cfg.bwMode=%d\n",
               "rdmngr_db_check_and_do_peer_radio_linked_modify",0x74f,
               (uint)*(byte *)(in_stack_00000054 + 10));
        return 0;
      }
      uVar12 = 0xffffffff;
      uVar3 = 0;
      uVar10 = (uint)*(byte *)(in_stack_0000005c + 0xc);
      do {
        if (((uVar10 & 1) != 0) &&
           (uVar12 = uVar3,
           *(uint *)(&DAT_0070a894 + (uint)*(byte *)(in_stack_00000054 + 10) * 4) == uVar3)) {
          cVar7 = *(char *)(in_stack_0000005c + 4);
          goto LAB_0061a6ac;
        }
        uVar3 = uVar3 + 1;
        uVar10 = (int)(uint)*(byte *)(in_stack_0000005c + 0xc) >> (uVar3 & 0x1f);
      } while (uVar3 != 6);
      if (5 < uVar12) {
        if (rdmngr_err_switch == 0) {
          cVar7 = *(char *)(in_stack_0000005c + 4);
        }
        else {
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            cVar7 = *(char *)(in_stack_0000005c + 4);
          }
          else {
            printf("[RDMNGR_ERROR]%s()/%d invalid enum value selected_bw=%d\n",
                   "rdmngr_db_check_and_do_peer_radio_linked_modify",0x76b,uVar12);
            cVar7 = *(char *)(in_stack_0000005c + 4);
          }
        }
        goto LAB_0061a6ac;
      }
      *(char *)(in_stack_00000054 + 10) = (char)(&DAT_0070a8ac)[uVar12];
      *in_stack_00000060 = 1;
    }
LAB_0061a6a8:
    cVar7 = *(char *)(in_stack_0000005c + 4);
  }
LAB_0061a6ac:
  if (cVar7 == '\x01') {
    if (*(char *)(in_stack_00000054 + 0x27) != param_10) {
      *in_stack_00000060 = 1;
      goto LAB_0061a6b8;
    }
    cVar7 = *(char *)(in_stack_0000005c + 5);
  }
  else {
LAB_0061a6b8:
    cVar7 = *(char *)(in_stack_0000005c + 5);
  }
  if (cVar7 == '\x01') {
    if (*(char *)(in_stack_00000054 + 0x28) != param_11._0_1_) {
      *in_stack_00000060 = 1;
      goto LAB_0061a6c8;
    }
    cVar7 = *(char *)(in_stack_0000005c + 6);
  }
  else {
LAB_0061a6c8:
    cVar7 = *(char *)(in_stack_0000005c + 6);
  }
  if (cVar7 == '\x01') {
    if (*(short *)(in_stack_00000054 + 0x1a) != param_7._2_2_) {
      *in_stack_00000060 = 1;
      goto LAB_0061a6d8;
    }
    cVar7 = *(char *)(in_stack_0000005c + 7);
  }
  else {
LAB_0061a6d8:
    cVar7 = *(char *)(in_stack_0000005c + 7);
  }
  if (cVar7 == '\x01') {
    if (*(char *)(in_stack_00000054 + 0x2b) != (char)param_11) {
      *in_stack_00000060 = 1;
    }
    if (*(char *)(in_stack_00000054 + 0x2c) != param_12._0_1_) {
      *in_stack_00000060 = 1;
    }
    if (*(char *)(in_stack_00000054 + 0x2d) != param_12._1_1_) {
      *in_stack_00000060 = 1;
    }
    if (*(char *)(in_stack_00000054 + 0x2e) != param_12._2_1_) {
      *in_stack_00000060 = 1;
    }
  }
  if (*(char *)(in_stack_0000005c + 8) == '\x01') {
    if ((uint)*(byte *)(in_stack_00000054 + 0xe) != (uint)(param_4 << 0x10) >> 0x18) {
      *in_stack_00000060 = 1;
    }
    if (*(short *)(in_stack_00000054 + 0x10) != param_5._0_2_) {
      *in_stack_00000060 = 1;
    }
    if (*(short *)(in_stack_00000054 + 0x12) != param_5._2_2_) {
      *in_stack_00000060 = 1;
    }
    if (*(short *)(in_stack_00000054 + 0x16) != param_6) {
      *in_stack_00000060 = 1;
    }
    if (*(char *)(in_stack_00000054 + 0x18) != param_7._0_1_) {
      *in_stack_00000060 = 1;
    }
    if (*(char *)(in_stack_00000054 + 0x49) != in_stack_00000048._1_1_) {
      *in_stack_00000060 = 1;
    }
  }
  if (*(char *)(in_stack_0000005c + 9) == '\x01') {
    if (*(short *)(in_stack_00000054 + 0x20) == param_9._0_2_) {
      cVar7 = *(char *)(in_stack_0000005c + 10);
      goto LAB_0061a70c;
    }
    *in_stack_00000060 = 1;
  }
  cVar7 = *(char *)(in_stack_0000005c + 10);
LAB_0061a70c:
  if (cVar7 == '\x01') {
    cVar7 = *(char *)(in_stack_00000054 + 0x2f);
    if (cVar7 != (char)param_12) {
      *in_stack_00000060 = 1;
    }
    cVar1 = *(char *)(in_stack_00000054 + 0x2f);
    if (cVar1 != cVar7) {
      *in_stack_00000060 = 1;
    }
    if (*(char *)(in_stack_00000054 + 0x2f) != cVar1) {
      *in_stack_00000060 = 1;
    }
  }
  return 0;
}

