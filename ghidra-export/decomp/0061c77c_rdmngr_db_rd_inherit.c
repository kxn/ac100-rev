// func rdmngr_db_rd_inherit @ 0061c77c size=844

undefined4 rdmngr_db_rd_inherit(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  if (param_3 == 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[RDMNGR_ERROR]%s()/%d Invalid ap_entry.\n","rdmngr_db_rd_inherit",0xdb3);
    return 0xffffffff;
  }
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      uVar6 = rdmngr_db_generate_rd_idx_by_rd_id(param_2);
      iVar5 = DAT_007cc65c;
      if (-1 < (int)uVar6) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar4 = apmngr_db_get_sensor_max();
        if (uVar6 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
          FUN_004082d0(DAT_007cc64c,0xffffffff);
          piVar10 = *(int **)(DAT_007cc650 + uVar1 * 8 + 4);
          if ((piVar10 == (int *)0x0) || (*piVar10 == -1)) {
            uVar11 = 0xffffffff;
            if ((rdmngr_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
            goto LAB_0061c9bc;
            pcVar8 = "[RDMNGR_WARNING]%s()/%d parent_idx[%d] is not used!\n";
            uVar12 = 0xdc8;
            uVar6 = uVar1;
          }
          else {
            iVar5 = DAT_007cc650 + uVar6 * 8;
            piVar9 = *(int **)(iVar5 + 4);
            if ((piVar9 != (int *)0x0) && (*piVar9 != -1)) {
              uVar11 = 0;
              memcpy(piVar9 + 1,piVar10 + 1,0x48);
              iVar2 = *(int *)(iVar5 + 4);
              *(uint *)(iVar2 + 4) = param_2;
              iVar5 = apdb_is_hdap_by_id(*(undefined4 *)(param_3 + 0x40),param_3 + 0x218);
              if ((iVar5 != 0) &&
                 (uVar1 = rdmngr_db_generate_rd_idx(*(undefined2 *)(param_3 + 0x298),param_2 & 0xf),
                 iVar5 = DAT_007cc65c, -1 < (int)uVar1)) {
                iVar3 = apmngr_db_get_ap_max();
                iVar4 = apmngr_db_get_template_max();
                iVar7 = apmngr_db_get_sensor_max();
                if (((uVar1 < (uint)((iVar3 + iVar4 + iVar7) * iVar5)) &&
                    (piVar10 = *(int **)(DAT_007cc650 + uVar1 * 8 + 4), piVar10 != (int *)0x0)) &&
                   (*piVar10 != -1)) {
                  rdmngr_db_do_relativity(iVar2 + 4,piVar10 + 1,0xffffffff);
                }
              }
              goto LAB_0061c9bc;
            }
            uVar11 = 0xffffffff;
            if ((rdmngr_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
            goto LAB_0061c9bc;
            pcVar8 = "[RDMNGR_WARNING]%s()/%d child_idx[%d] is not used!\n";
            uVar12 = 0xdce;
          }
          uVar11 = 0xffffffff;
          printf(pcVar8,"rdmngr_db_rd_inherit",uVar12,uVar6);
LAB_0061c9bc:
          FUN_00407f30(DAT_007cc64c);
          return uVar11;
        }
      }
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      pcVar8 = "[RDMNGR_ERROR]%s()/%d child_id[%d] is invalid!\n";
      uVar11 = 0xdc1;
      goto LAB_0061c8a8;
    }
  }
  if (rdmngr_err_switch == 0) {
    return 0xffffffff;
  }
  iVar5 = is_target_debug_ap();
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  pcVar8 = "[RDMNGR_ERROR]%s()/%d parent_id[%d] is invalid!\n";
  uVar11 = 0xdba;
  param_2 = param_1;
LAB_0061c8a8:
  printf(pcVar8,"rdmngr_db_rd_inherit",uVar11,param_2);
  return 0xffffffff;
}

