// func _uac_rdmngr_foreach_proc @ 006260d8 size=904

undefined4 _uac_rdmngr_foreach_proc(int param_1,int *param_2)

{
  int iVar1;
  undefined2 uVar5;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 local_80;
  int local_7c [21];
  
  local_80 = 0;
  memset(local_7c,0,0x54);
  if (rdmngr_debug_switch == 0) {
    iVar1 = param_2[8];
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = param_2[8];
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_foreach_proc() begin.\n","_uac_rdmngr_foreach_proc",
             0x24b);
      iVar1 = param_2[8];
    }
  }
  if (iVar1 == 2) {
    if (*(int *)(param_1 + 0x2ac) - 2U < 2) goto LAB_0062615c;
    uVar5 = *(undefined2 *)(param_1 + 0x44);
  }
  else if (iVar1 == 1) {
    if (1 < *(int *)(param_1 + 0x2ac) - 2U) {
LAB_0062615c:
      uVar3 = 0;
      if (rdmngr_debug_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = (uint)*(ushort *)(param_1 + 0x10);
      pcVar6 = "[RDMNGR_DEBUG]%s()/%d ap(%d) is out\n";
      uVar7 = 0x250;
      goto LAB_006262f0;
    }
    uVar5 = *(undefined2 *)(param_1 + 0x44);
  }
  else {
    if (iVar1 == -1) goto LAB_0062615c;
    uVar5 = *(undefined2 *)(param_1 + 0x44);
  }
  local_80 = CONCAT22(uVar5,*(undefined2 *)(param_1 + 0x46));
  uVar2 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_80);
  if (-1 < (int)uVar2) {
    iVar1 = 1;
    if (*(int *)(param_1 + 0x3c) != 0) {
LAB_006261f0:
      if (iVar1 <= (int)uVar2) {
        uVar3 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar1);
        memset(local_7c,0,0x54);
        iVar4 = rdmngr_db_rd_entry_get(uVar3,local_7c);
        if (iVar4 != 0) {
          if (rdmngr_err_switch == 0) {
            iVar1 = iVar1 + 1;
          }
          else {
            iVar4 = is_target_debug_ap();
            if (iVar4 == 0) {
              iVar1 = iVar1 + 1;
            }
            else {
              uVar3 = 0x267;
              pcVar6 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n";
LAB_00626320:
              printf(pcVar6,"_uac_rdmngr_foreach_proc",uVar3);
              iVar1 = iVar1 + 1;
            }
          }
          goto LAB_006261f0;
        }
        if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d rd_id is %d\n","_uac_rdmngr_foreach_proc",0x26b,local_7c[0])
          ;
        }
        if (local_7c[0] != -1) {
          if (param_2[5] == 0) {
            iVar4 = param_2[4];
          }
          else if ((code *)param_2[6] == (code *)0x0) {
            iVar4 = param_2[4];
          }
          else {
            iVar4 = (*(code *)param_2[6])(local_7c);
            if (iVar4 != 0) {
              iVar1 = iVar1 + 1;
              goto LAB_006261f0;
            }
            iVar4 = param_2[4];
          }
          param_2[4] = iVar4 + 1;
          if (param_2[2] < *param_2) {
            iVar1 = iVar1 + 1;
            param_2[2] = param_2[2] + 1;
          }
          else if (param_2[3] < param_2[1]) {
            param_2[3] = param_2[3] + 1;
            _uac_rdmngr_get_rd_entry(param_1,local_7c,param_2[7]);
            iVar1 = iVar1 + 1;
          }
          else {
            iVar1 = iVar1 + 1;
          }
          goto LAB_006261f0;
        }
        if (rdmngr_debug_switch == 0) {
          iVar1 = iVar1 + 1;
        }
        else {
          iVar4 = is_target_debug_ap();
          if (iVar4 != 0) {
            uVar3 = 0x26f;
            pcVar6 = "[RDMNGR_DEBUG]%s()/%d Invalid rd entry.\n";
            goto LAB_00626320;
          }
          iVar1 = iVar1 + 1;
        }
        goto LAB_006261f0;
      }
    }
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_foreach_proc() finish.\n","_uac_rdmngr_foreach_proc",
           0x290);
    return 0;
  }
  uVar3 = 1;
  if (rdmngr_err_switch == 0) {
    return 1;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 1;
  }
  pcVar6 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n";
  uVar7 = 0x25a;
LAB_006262f0:
  printf(pcVar6,"_uac_rdmngr_foreach_proc",uVar7,uVar2);
  return uVar3;
}

