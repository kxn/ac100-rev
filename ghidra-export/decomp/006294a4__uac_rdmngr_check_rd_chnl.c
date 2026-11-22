// func _uac_rdmngr_check_rd_chnl @ 006294a4 size=744

uint _uac_rdmngr_check_rd_chnl
               (undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 *param_4)

{
  short sVar1;
  undefined2 uVar7;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined1 local_d0 [2];
  short local_ce;
  undefined4 local_cc [16];
  char acStack_8c [100];
  
  memset(acStack_8c,0,100);
  sVar1 = *(short *)(param_4 + 2);
  iVar9 = (int)sVar1;
  local_ce = 0;
  local_d0[0] = 0;
  if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d target chnl(%d).\n","_uac_rdmngr_check_rd_chnl",0xd4,iVar9);
  }
  uVar7 = rdmngr_db_generate_ap_id(*param_4);
  pcVar2 = (char *)apdb_get_radio_mutex_channel
                             (param_1,param_2,param_3,uVar7,(int)*(char *)(param_4 + 1));
  iVar3 = apdb_is_support_rrst(param_1,param_2);
  if (iVar3 == 1) {
    uVar10 = *param_4;
    uVar6 = apmngr_db_get_cur_using_region_code(uVar7);
    iVar9 = apmngr_get_linkage_chnl_bwMode(uVar7,uVar10,uVar6,iVar9,&local_ce,local_d0);
    uVar8 = 1;
    if ((iVar9 == 0) && (local_ce != sVar1)) {
      uVar8 = 0xffffffff;
    }
  }
  else if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
    uVar8 = (iVar9 - 0x34U & 0xffff) < 0xd ^ 1;
  }
  else {
    uVar8 = 1;
    if (iVar9 != -1) {
      strncpy(acStack_8c,pcVar2,99);
      iVar3 = FUN_0062784c(acStack_8c,local_cc,0x10);
      if (iVar3 < 1) {
        if ((rdmngr_debug_switch != 0) && (iVar9 = is_target_debug_ap(), iVar9 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_util_str_split() fail, str: %s!\n",
                 "_uac_rdmngr_check_rd_chnl",0xfa,acStack_8c);
        }
      }
      else {
        puVar12 = local_cc;
        iVar11 = 0;
        do {
          iVar4 = atoi((char *)*puVar12);
          if ((rdmngr_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[RDMNGR_DEBUG]%s()/%d mutex_chnl[%d] is %d.\n","_uac_rdmngr_check_rd_chnl",0x101
                   ,iVar11,iVar4);
          }
          uVar8 = 1;
          if (iVar9 == iVar4) goto LAB_0062961c;
          iVar11 = iVar11 + 1;
          puVar12 = puVar12 + 1;
        } while (iVar11 != iVar3);
        uVar8 = 0;
LAB_0062961c:
        if ((*(char *)(param_4 + 1) == '\x01') && (iVar9 == 0xa5)) {
          if (*(char *)((int)param_4 + 5) == '\0') {
            uVar8 = 1;
          }
          else if (*(char *)((int)param_4 + 6) == '\0') {
            uVar8 = 1;
          }
        }
        if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          if (uVar8 == 0) {
            pcVar2 = "not found";
          }
          else {
            pcVar2 = "found";
          }
          printf("[RDMNGR_DEBUG]%s()/%d target %d %s\n","_uac_rdmngr_check_rd_chnl",0x112,iVar9,
                 pcVar2);
        }
      }
    }
  }
  return uVar8;
}

