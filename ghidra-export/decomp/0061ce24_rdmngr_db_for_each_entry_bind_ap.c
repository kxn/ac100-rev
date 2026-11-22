// func rdmngr_db_for_each_entry_bind_ap @ 0061ce24 size=580

undefined4
rdmngr_db_for_each_entry_bind_ap(undefined4 param_1,int param_2,code *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *__src;
  int iVar6;
  int iVar7;
  undefined1 auStack_2c8 [672];
  
  iVar7 = 1;
  iVar6 = 0;
  memset(auStack_2c8,0,0x2a0);
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  while( true ) {
    if (param_2 < iVar7) {
      FUN_00407f30(DAT_007cc64c);
      if ((param_3 != (code *)0x0) && (iVar7 = 0, iVar6 != 0)) {
        iVar5 = 0;
        while( true ) {
          iVar7 = iVar7 + 1;
          (*param_3)(auStack_2c8 + iVar5,param_4);
          if (iVar6 <= iVar7) break;
          iVar5 = iVar7 * 0x54;
        }
      }
      return 0;
    }
    uVar1 = rdmngr_db_generate_rd_idx(param_1,iVar7);
    iVar5 = DAT_007cc65c;
    if ((int)uVar1 < 0) break;
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    if ((uint)((iVar2 + iVar3 + iVar4) * iVar5) <= uVar1) break;
    __src = *(int **)(DAT_007cc650 + uVar1 * 8 + 4);
    if ((__src == (int *)0x0) || (*__src == -1)) {
      if (rdmngr_warning_switch == 0) {
        iVar7 = iVar7 + 1;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          iVar7 = iVar7 + 1;
        }
        else {
          printf("[RDMNGR_WARNING]%s()/%d entry idx(%d) is not used.\n",
                 "rdmngr_db_for_each_entry_bind_ap",0xe84,uVar1);
          iVar7 = iVar7 + 1;
        }
      }
    }
    else if (*(char *)(__src + 0x12) == '\0') {
      iVar7 = iVar7 + 1;
    }
    else if (iVar6 < 8) {
      iVar5 = iVar6 * 0x54;
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 1;
      memcpy(auStack_2c8 + iVar5,__src,0x54);
    }
    else {
      iVar7 = iVar7 + 1;
    }
  }
  if ((rdmngr_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d Invalid rd_idx(%d)\n","rdmngr_db_for_each_entry_bind_ap",0xe7d,
           uVar1);
  }
  FUN_00407f30(DAT_007cc64c);
  return 0xffffffff;
}

