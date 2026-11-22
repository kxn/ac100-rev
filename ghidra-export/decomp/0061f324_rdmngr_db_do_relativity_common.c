// func rdmngr_db_do_relativity_common @ 0061f324 size=1

int rdmngr_db_do_relativity_common
              (uint *param_1,int param_2,short param_3,int param_4,int param_5,int param_6,
              undefined4 param_7)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *__src;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uStack_d0;
  undefined1 auStack_cc [40];
  int aiStack_a4 [10];
  undefined1 auStack_7c [68];
  int iStack_38;
  uint uStack_34;
  int iStack_30;
  
  iStack_30 = (int)param_3;
  uStack_d0 = 0;
  uVar9 = *param_1;
  memset(aiStack_a4,0,0x28);
  uVar9 = uVar9 & 0xf;
  memset(auStack_cc,0,0x28);
  if (param_4 == 0) {
    iVar3 = apdb_get_24g_linked_modify_items
                      (*(undefined4 *)(param_2 + 0x40),param_2 + 0x218,aiStack_a4);
code_r0x0061f58c:
    if (iVar3 != 0) {
      return 0;
    }
    iVar3 = memcmp(aiStack_a4,auStack_cc,0x28);
    if (iVar3 == 0) {
      return 0;
    }
  }
  else if (param_4 == 1) {
    iVar3 = apdb_get_5g_linked_modify_items
                      (*(undefined4 *)(param_2 + 0x40),param_2 + 0x218,aiStack_a4);
    goto code_r0x0061f58c;
  }
  piVar6 = aiStack_a4;
  iVar3 = 0;
  do {
    if ((rdmngr_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      pcVar1 = "need";
      if (*piVar6 == 0) {
        pcVar1 = "no need";
      }
      printf("[RDMNGR_DEBUG]%s()/%d items[%d] %s modify.\n","rdmngr_db_do_relativity_common",0xb91,
             iVar3,pcVar1);
    }
    iVar3 = iVar3 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar3 != 10);
  iVar8 = param_2 + 0x218;
  uStack_d0 = *(undefined4 *)(param_2 + 0x44);
  iVar3 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_2 + 0x40),iVar8,&uStack_d0);
  if (iVar3 < 0) {
    if ((rdmngr_err_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
             "rdmngr_db_do_relativity_common",0xb9a,iVar3);
    }
    return 0;
  }
  uVar7 = 1;
  iVar5 = 0;
  while ((int)uVar7 <= iVar3) {
    if (uVar9 == uVar7) {
code_r0x0061f4c8:
      uVar7 = uVar7 + 1;
    }
    else {
      if (7 < iVar5) goto code_r0x0061f538;
      uStack_34 = uVar7 & 0xf;
      iStack_38 = iVar5 * 0x54;
      __src = (undefined4 *)(param_5 + iStack_38);
      rdmngr_db_rd_entry_get(uStack_34 | (uint)*(ushort *)(param_2 + 0x10) << 4,__src);
      memcpy((void *)(param_6 + iStack_38),__src,0x54);
      if (param_4 != *(char *)(__src + 2)) goto code_r0x0061f4c8;
      if (rdmngr_debug_switch == 0) {
code_r0x0061f4e0:
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 1;
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) goto code_r0x0061f4e0;
        printf("[RDMNGR_DEBUG]%s()/%d radio(%d/%d) linked.\n","rdmngr_db_do_relativity_common",0xbb0
               ,uStack_34 | (uint)*(ushort *)(param_2 + 0x10) << 4,*__src);
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 1;
      }
    }
  }
  if (iVar5 == 0) {
    return 0;
  }
code_r0x0061f538:
  if (param_4 != 0) {
    if (param_4 != 1) {
      return iVar5;
    }
    memset(auStack_7c,-1,0x40);
    if (*(short *)(param_1 + 2) != -1) {
      iVar3 = rdmngr_db_get_mutex_chnl
                        (*(undefined4 *)(param_2 + 0x40),iVar8,uVar9,*(undefined2 *)(param_2 + 0x10)
                         ,(int)*(short *)(param_1 + 2),auStack_7c,1);
      if (iVar3 < iVar5) {
        if (rdmngr_err_switch == 0) {
          return -1;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return -1;
        }
        uVar4 = 0xbd3;
code_r0x0061f678:
        printf("[RDMNGR_ERROR]%s()/%d mutex_chnl_cnt(%d) or link_cnt(%d) invalid.\n",
               "rdmngr_db_do_relativity_common",uVar4,iVar3,iVar5);
        return -1;
      }
      if (((iVar3 != iVar5) && (rdmngr_warning_switch != 0)) &&
         (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
        printf("[RDMNGR_WARNING]%s()/%d mutex_chnl_cnt(%d) should equal to link_cnt(%d).\n",
               "rdmngr_db_do_relativity_common",0xbd8,iVar3,iVar5);
      }
    }
    rdmngr_db_5g_do_relativity(aiStack_a4,param_1,param_5,iStack_30,auStack_7c,iVar5,param_7);
    return iVar5;
  }
  memset(auStack_7c,-1,0x40);
  if (*(short *)(param_1 + 2) != -1) {
    iVar3 = rdmngr_db_get_mutex_chnl
                      (*(undefined4 *)(param_2 + 0x40),iVar8,uVar9,*(undefined2 *)(param_2 + 0x10),
                       (int)*(short *)(param_1 + 2),auStack_7c,0);
    if (iVar3 < iVar5) {
      if (rdmngr_err_switch == 0) {
        return -1;
      }
      iVar8 = is_target_debug_ap();
      if (iVar8 == 0) {
        return -1;
      }
      uVar4 = 0xbbf;
      goto code_r0x0061f678;
    }
    if (((iVar3 != iVar5) && (memset(auStack_7c,-1,0x40), rdmngr_err_switch != 0)) &&
       (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d mutex_chnl_cnt(%d) should equal to link_cnt(%d).\n",
             "rdmngr_db_do_relativity_common",0xbc5,iVar3,iVar5);
    }
  }
  rdmngr_db_2_4g_do_relativity(aiStack_a4,param_1,param_5,iStack_30,auStack_7c,iVar5,param_7);
  return iVar5;
}

