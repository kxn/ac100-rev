// func rdmngr_db_get_radio_attribute_relation_unit_by_rrst @ 00622b00 size=280

undefined4
rdmngr_db_get_radio_attribute_relation_unit_by_rrst(undefined1 *param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  if ((param_3 == 0) || (param_1 == (undefined1 *)0x0)) {
    uVar6 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d src_rra is null\n",
             "rdmngr_db_get_radio_attribute_relation_unit_by_rrst",0x14c1);
    }
  }
  else {
    uVar1 = *(undefined1 *)(param_3 + 0x6c);
    param_1[9] = 0;
    param_1[5] = 0;
    *param_1 = uVar1;
    param_1[8] = 0;
    param_1[3] = 2;
    param_1[6] = 0;
    param_1[2] = 1;
    param_1[7] = 0;
    param_1[10] = 0;
    param_1[4] = 0;
    param_1[0xc] = *(undefined1 *)(param_3 + 0x6d);
    if (param_2 == 1) {
      param_1[1] = 1;
LAB_00622bb4:
      uVar6 = 0;
    }
    else {
      param_1[1] = 2;
      sVar2 = *(short *)(param_3 + 4);
      if (sVar2 != 0) {
        *(short *)(param_1 + 0xe) = sVar2;
      }
      uVar3 = (uint)(sVar2 != 0);
      iVar4 = param_3;
      do {
        sVar2 = *(short *)(iVar4 + 6);
        if (sVar2 == 0) goto LAB_00622bb4;
        if (*(short *)(param_3 + 4) != sVar2) {
          iVar5 = uVar3 + 4;
          if (0x32 < (int)uVar3) goto LAB_00622bb4;
          uVar3 = uVar3 + 1;
          *(short *)(param_1 + iVar5 * 2 + 6) = sVar2;
        }
        iVar4 = iVar4 + 2;
        uVar6 = 0;
      } while (iVar4 != param_3 + 0x66);
    }
  }
  return uVar6;
}

