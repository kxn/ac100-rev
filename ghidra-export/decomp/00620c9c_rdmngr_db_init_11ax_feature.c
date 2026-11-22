// func rdmngr_db_init_11ax_feature @ 00620c9c size=824

undefined4 rdmngr_db_init_11ax_feature(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_3 == 0) {
    if ((rdmngr_err_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d val is null\n","rdmngr_db_init_11ax_feature",0x56f);
    }
  }
  else {
    uVar3 = rdmngr_db_generate_rd_idx_by_rd_id();
    if ((rdmngr_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d enter rdmngr_db_init_11ax_feature,the extend_capabilty: %s\n",
             "rdmngr_db_init_11ax_feature",0x57d,param_2);
    }
    FUN_004082d0(DAT_007cc64c,0xffffffff);
    iVar7 = DAT_007cc65c;
    if (-1 < (int)uVar3) {
      iVar4 = apmngr_db_get_ap_max();
      iVar5 = apmngr_db_get_template_max();
      iVar6 = apmngr_db_get_sensor_max();
      if ((uVar3 < (uint)((iVar4 + iVar5 + iVar6) * iVar7)) &&
         (iVar7 = *(int *)(DAT_007cc650 + uVar3 * 8 + 4), iVar7 != 0)) {
        bVar2 = false;
        if (((*(byte *)(param_2 + 0xe) & 1) != 0) && (*(char *)(iVar7 + 0x32) == -1)) {
          bVar2 = true;
          *(undefined1 *)(iVar7 + 0x32) = *(undefined1 *)(param_3 + 1);
        }
        if ((*(byte *)(param_2 + 0xe) & 2) == 0) {
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        else {
          if (*(char *)(iVar7 + 0x33) == -1) {
            bVar2 = true;
            *(undefined1 *)(iVar7 + 0x33) = *(undefined1 *)(param_3 + 2);
          }
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        if ((bVar1 & 4) == 0) {
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        else {
          if (*(char *)(iVar7 + 0x34) == -1) {
            bVar2 = true;
            *(undefined1 *)(iVar7 + 0x34) = *(undefined1 *)(param_3 + 3);
          }
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        if ((bVar1 & 8) == 0) {
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        else {
          if (*(char *)(iVar7 + 0x35) == -1) {
            bVar2 = true;
            *(undefined1 *)(iVar7 + 0x35) = *(undefined1 *)(param_3 + 4);
          }
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        if ((bVar1 & 0x10) == 0) {
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        else {
          if (*(char *)(iVar7 + 0x36) == -1) {
            bVar2 = true;
            *(undefined1 *)(iVar7 + 0x36) = *(undefined1 *)(param_3 + 5);
          }
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        if ((bVar1 & 0x10) == 0) {
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        else {
          if (*(char *)(iVar7 + 0x37) == -1) {
            bVar2 = true;
            *(undefined1 *)(iVar7 + 0x37) = *(undefined1 *)(param_3 + 6);
          }
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        if ((bVar1 & 0x20) == 0) {
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        else {
          if (*(char *)(iVar7 + 0x38) == -1) {
            bVar2 = true;
            *(undefined1 *)(iVar7 + 0x38) = *(undefined1 *)(param_3 + 7);
          }
          bVar1 = *(byte *)(param_2 + 0xe);
        }
        if (((bVar1 & 0x20) != 0) && (*(char *)(iVar7 + 0x39) == -1)) {
          bVar2 = true;
          *(undefined1 *)(iVar7 + 0x39) = *(undefined1 *)(param_3 + 8);
        }
        FUN_00407f30(DAT_007cc64c);
        if (!bVar2) {
          return 0;
        }
        rdmngr_db_rd_update(param_1,2);
        return 0;
      }
    }
    if ((rdmngr_err_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Invalid rd_idx:%d\n","rdmngr_db_init_11ax_feature",0x583,uVar3);
    }
    FUN_00407f30(DAT_007cc64c);
  }
  return 0xffffffff;
}

