// func rdmngr_db_init_comPara @ 00619f34 size=1180

undefined4
rdmngr_db_init_comPara
          (double param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined1 param_5)

{
  int iVar1;
  char cVar3;
  undefined1 uVar4;
  int iVar2;
  char *__format;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  undefined8 uVar11;
  undefined1 auStack_420 [4];
  int local_41c;
  int local_418;
  int local_40c;
  undefined2 local_402;
  short local_400;
  short local_3fe;
  short local_3fc;
  int local_3f0;
  undefined1 auStack_308 [536];
  undefined1 auStack_f0 [192];
  undefined8 local_30;
  
  memset(auStack_420,0,0x114);
  memset(auStack_308,0,0x2d8);
  if (param_3 == (int *)0x0) {
    uVar6 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d Invalid param.\n";
    uVar5 = 0x4ad;
    goto LAB_0061a2b0;
  }
  memset(auStack_308,0,0x2d8);
  *(char *)(param_3 + 1) = (char)param_4;
  if ((char)param_4 == '\0') {
    uVar4 = 6;
  }
  else {
    uVar4 = 7;
  }
  *(undefined1 *)((int)param_3 + 5) = uVar4;
  uVar6 = 0xffffffff;
  iVar1 = apmngr_db_entry_get_by_id((uint)(*param_3 << 0xc) >> 0x10,auStack_308);
  if (iVar1 == -1) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d get entry failed\n";
    uVar5 = 0x4be;
    goto LAB_0061a2b0;
  }
  iVar1 = apdb_get_radio_by_id(param_2,auStack_f0,(byte)*param_3 & 0xf,auStack_420,param_4);
  if (iVar1 == -1) {
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d apdb_get_radio_by_id() failed.\n","rdmngr_db_init_comPara",0x4c4
            );
    }
    iVar1 = -1;
    iVar7 = 0;
    iVar8 = 0;
    iVar9 = 0;
    uVar10 = 0;
  }
  else {
    iVar9 = (int)local_400;
    iVar8 = (int)local_3fe;
    iVar7 = (int)local_3fc;
    iVar1 = local_3f0;
    uVar10 = local_402;
    if (*(char *)(param_3 + 1) == '\x01') {
      if (local_40c == 0) {
        if (local_418 == 0) {
          if (local_41c != 0) {
            *(undefined1 *)((int)param_3 + 5) = 9;
          }
        }
        else {
          *(undefined1 *)((int)param_3 + 5) = 0xb;
        }
      }
      else {
        *(undefined1 *)((int)param_3 + 5) = 0xd;
      }
    }
    else if (*(char *)(param_3 + 1) == '\0') {
      if (local_40c == 0) {
        if (local_418 != 0) {
          *(undefined1 *)((int)param_3 + 5) = 10;
        }
      }
      else {
        *(undefined1 *)((int)param_3 + 5) = 0xc;
      }
    }
  }
  *(undefined2 *)(param_3 + 2) = 0xffff;
  *(undefined1 *)((int)param_3 + 6) = 2;
  *(undefined1 *)((int)param_3 + 0x15) = 10;
  if (rdmngr_debug_switch == 0) {
    cVar3 = *(char *)(param_3 + 1);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      cVar3 = *(char *)(param_3 + 1);
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d model id:%d\n","rdmngr_db_init_comPara",0x4f1,param_2);
      cVar3 = *(char *)(param_3 + 1);
    }
  }
  if ((cVar3 == '\0') && (iVar2 = apdb_is_hdap_by_id(param_2,auStack_f0), iVar2 != 0)) {
    *(undefined1 *)((int)param_3 + 6) = 0;
  }
  local_30 = CONCAT44(local_30._0_4_,local_30._4_4_);
  if (iVar7 != 0) {
    if (iVar8 < iVar9) {
      if (iVar8 < iVar7) {
        if (iVar9 <= iVar7) goto LAB_0061a304;
        uVar11 = __floatsidf(iVar7 - iVar8);
        local_30 = __muldf3((int)((ulonglong)uVar11 >> 0x20),(int)uVar11,0x40220000,0);
        uVar11 = __floatsidf(iVar9 - iVar8);
        uVar11 = __divdf3(local_30._0_4_,local_30._4_4_,(int)((ulonglong)uVar11 >> 0x20),(int)uVar11
                         );
        round(param_1);
        uVar11 = __adddf3((int)((ulonglong)uVar11 >> 0x20),(int)uVar11,0x3ff00000,0);
        uVar4 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
        *(undefined1 *)((int)param_3 + 0x15) = uVar4;
      }
      else {
        *(undefined1 *)((int)param_3 + 0x15) = 1;
        local_30 = CONCAT44(local_30._0_4_,local_30._4_4_);
      }
    }
    else {
LAB_0061a304:
      *(undefined1 *)((int)param_3 + 0x15) = 10;
      local_30 = CONCAT44(local_30._0_4_,local_30._4_4_);
    }
  }
  if (iVar1 != -1) {
    *(char *)((int)param_3 + 6) = (char)iVar1;
  }
  *(undefined1 *)((int)param_3 + 10) = 0;
  *(undefined1 *)(param_3 + 5) = 0;
  *(undefined2 *)(param_3 + 3) = 8;
  *(undefined2 *)(param_3 + 4) = 0;
  *(undefined2 *)((int)param_3 + 0xe) = 0x32;
  *(undefined1 *)((int)param_3 + 0x45) = 0;
  *(undefined2 *)((int)param_3 + 0x12) = 0x14;
  *(undefined2 *)((int)param_3 + 0x1e) = 0;
  *(undefined2 *)((int)param_3 + 0x1a) = 0x92a;
  *(undefined2 *)((int)param_3 + 0x16) = uVar10;
  *(undefined2 *)(param_3 + 7) = 100;
  *(undefined1 *)(param_3 + 6) = 0;
  uVar4 = DAT_007cc647;
  if (*(char *)(param_3 + 1) == '\0') {
    uVar4 = DAT_007cc643;
  }
  *(undefined1 *)((int)param_3 + 0x25) = uVar4;
  *(undefined1 *)((int)param_3 + 0x3d) = 0;
  *(undefined2 *)(param_3 + 8) = 0x92a;
  *(undefined2 *)((int)param_3 + 0x42) = 10;
  *(undefined1 *)((int)param_3 + 0x22) = 1;
  *(undefined1 *)(param_3 + 9) = 1;
  *(undefined1 *)((int)param_3 + 0x26) = 1;
  *(undefined1 *)((int)param_3 + 0x23) = 1;
  *(undefined1 *)(param_3 + 0xb) = 1;
  *(undefined1 *)((int)param_3 + 0x3e) = 0;
  *(undefined1 *)((int)param_3 + 0x2d) = 6;
  *(undefined1 *)((int)param_3 + 0x3f) = 0;
  *(undefined1 *)((int)param_3 + 0x2e) = 0xff;
  *(undefined1 *)((int)param_3 + 0x2f) = 0xff;
  *(undefined1 *)(param_3 + 0xc) = 0xff;
  *(undefined1 *)((int)param_3 + 0x31) = 0xff;
  *(undefined1 *)((int)param_3 + 0x32) = 0xff;
  *(undefined1 *)((int)param_3 + 0x33) = 0xff;
  *(undefined1 *)(param_3 + 0xd) = 0xff;
  *(undefined1 *)((int)param_3 + 0x35) = 0xff;
  *(undefined1 *)(param_3 + 0x10) = 0;
  *(undefined1 *)(param_3 + 0x11) = param_5;
  *(undefined1 *)((int)param_3 + 0x2b) = 0xc4;
  uVar6 = 0;
  if (rdmngr_debug_switch == 0) {
    return 0;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0;
  }
  __format = "[RDMNGR_DEBUG]%s()/%d rdmngr_db_init_comPara() OK.\n";
  uVar5 = 0x536;
LAB_0061a2b0:
  printf(__format,"rdmngr_db_init_comPara",uVar5);
  return uVar6;
}

