// func rdmngr_db_ap_leave @ 0061c3ac size=408

undefined4 rdmngr_db_ap_leave(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 1;
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  do {
    while( true ) {
      if (param_2 < (int)uVar4) {
        FUN_00407f30(DAT_007cc64c);
        return 0;
      }
      iVar1 = rdmngr_db_generate_rd_idx(param_1,uVar4);
      piVar3 = *(int **)(DAT_007cc650 + iVar1 * 8 + 4);
      if (*piVar3 != -1) break;
      if (rdmngr_err_switch == 0) {
        uVar4 = uVar4 + 1;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          printf("[RDMNGR_ERROR]%s()/%d rd entry[%d] init error.\n","rdmngr_db_ap_leave",0xcaf,
                 uVar4 & 0xf | param_1 << 4);
          uVar4 = uVar4 + 1;
        }
      }
    }
    if (*(char *)(piVar3 + 0x12) == '\x01') {
      uVar2 = 3;
LAB_0061c47c:
      *(undefined1 *)((int)piVar3 + 0x4e) = uVar2;
    }
    else if (*(char *)(piVar3 + 0x12) == '\0') {
      uVar2 = 4;
      goto LAB_0061c47c;
    }
    if (rdmngr_debug_switch == 0) {
      uVar4 = uVar4 + 1;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar4 = uVar4 + 1;
      }
      else {
        printf("[RDMNGR_DEBUG]%s()/%d cfg:%d, info:%d\n","rdmngr_db_ap_leave",0xcab,
               (int)*(char *)(piVar3 + 0x12),(uint)*(byte *)((int)piVar3 + 0x4e));
        uVar4 = uVar4 + 1;
      }
    }
  } while( true );
}

