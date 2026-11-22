// func rdmngr_db_get_radio_attribute_relation_unit_by_default @ 00622964 size=412

undefined4
rdmngr_db_get_radio_attribute_relation_unit_by_default
          (undefined1 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4,int param_5,
          undefined1 param_6)

{
  undefined1 uVar2;
  int iVar1;
  undefined4 uVar3;
  
  if (((param_1 == (undefined1 *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (undefined4 *)0x0))
  {
    uVar3 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d invalid input\n",
             "rdmngr_db_get_radio_attribute_relation_unit_by_default",0x149c);
    }
  }
  else if (param_5 - 1U < 0x33) {
    *param_1 = param_6;
    uVar2 = 3;
    if (*param_3 != 1) {
      uVar2 = 0;
    }
    param_1[1] = uVar2;
    param_1[9] = param_3[8] == 1;
    param_1[5] = param_3[4] == 1;
    param_1[3] = param_3[2] == 1;
    param_1[8] = param_3[7] == 1;
    param_1[6] = param_3[5] == 1;
    param_1[2] = param_3[1] == 1;
    param_1[7] = param_3[6] == 1;
    param_1[10] = param_3[9] == 1;
    param_1[4] = param_3[3] == 1;
    iVar1 = 0;
    do {
      uVar3 = *param_4;
      iVar1 = iVar1 + 1;
      param_4 = param_4 + 1;
      *(short *)(param_1 + 0x74) = (short)uVar3;
      param_1 = param_1 + 2;
    } while (iVar1 != param_5);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d invalid mutex_chnls_cnt=%d\n",
             "rdmngr_db_get_radio_attribute_relation_unit_by_default",0x14a2,param_5);
    }
  }
  return uVar3;
}

