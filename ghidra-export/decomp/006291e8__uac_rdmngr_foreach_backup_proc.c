// func _uac_rdmngr_foreach_backup_proc @ 006291e8 size=652

undefined4 _uac_rdmngr_foreach_backup_proc(int param_1,undefined4 param_2)

{
  undefined2 uVar4;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  int iVar5;
  undefined4 local_80;
  int local_7c [21];
  
  local_80 = 0;
  memset(local_7c,0,0x54);
  if (rdmngr_debug_switch == 0) {
    uVar4 = *(undefined2 *)(param_1 + 0x44);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      uVar4 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_foreach_backup_proc() begin.\n",
             "_uac_rdmngr_foreach_backup_proc",0x29c);
      uVar4 = *(undefined2 *)(param_1 + 0x44);
    }
  }
  local_80 = CONCAT22(uVar4,*(undefined2 *)(param_1 + 0x46));
  iVar1 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_80);
  if (iVar1 < 0) {
    uVar2 = 1;
    if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
             "_uac_rdmngr_foreach_backup_proc",0x2a4,iVar1);
    }
  }
  else {
    iVar5 = 1;
    if (*(int *)(param_1 + 0x3c) != 0) {
      while (iVar5 <= iVar1) {
        uVar2 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar5);
        memset(local_7c,0,0x54);
        iVar3 = rdmngr_db_rd_entry_get(uVar2,local_7c);
        if (iVar3 == 0) {
          if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[RDMNGR_DEBUG]%s()/%d rd_id is %d\n","_uac_rdmngr_foreach_backup_proc",0x2b5,
                   local_7c[0]);
          }
          if (local_7c[0] == -1) {
            if (rdmngr_debug_switch == 0) {
              iVar5 = iVar5 + 1;
            }
            else {
              iVar3 = is_target_debug_ap();
              if (iVar3 != 0) {
                uVar2 = 0x2b9;
                __format = "[RDMNGR_DEBUG]%s()/%d Invalid rd entry.\n";
                goto LAB_0062933c;
              }
              iVar5 = iVar5 + 1;
            }
          }
          else {
            _uac_rdmngr_backup_detail_rd_entry(param_1,local_7c,param_2);
            iVar5 = iVar5 + 1;
          }
        }
        else if (rdmngr_err_switch == 0) {
          iVar5 = iVar5 + 1;
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            iVar5 = iVar5 + 1;
          }
          else {
            uVar2 = 0x2b1;
            __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n";
LAB_0062933c:
            printf(__format,"_uac_rdmngr_foreach_backup_proc",uVar2);
            iVar5 = iVar5 + 1;
          }
        }
      }
    }
    uVar2 = 0;
    if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_foreach_proc() finish.\n",
             "_uac_rdmngr_foreach_backup_proc",0x2c1);
    }
  }
  return uVar2;
}

