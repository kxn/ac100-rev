// func apdb_get_specified_rrst @ 0060c644 size=444

undefined4
apdb_get_specified_rrst
          (undefined4 param_1,int param_2,undefined4 param_3,void *param_4,uint param_5,
          undefined4 *param_6)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint __n;
  short local_res8;
  short sStackX_a;
  int local_28 [2];
  
  if (apdb_warning_switch != 0) {
    local_res8 = (short)((uint)param_3 >> 0x10);
    sStackX_a = (short)param_3;
    printf("[APDB_WARNING]%s()/line %d : apdb_get_specified_rrst ENTER,model_id=%d, hw.major=%d, hw.minor=%d\n"
           ,"apdb_get_specified_rrst",0x2cc9,param_1,(int)local_res8,(int)sStackX_a);
  }
  local_28[0] = 0;
  if (param_4 == (void *)0x0) {
    return 0xffffffff;
  }
  if (param_6 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar2 = 0x2cd3;
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,local_28);
    if (iVar1 == 0) {
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      iVar1 = local_28[0];
      if (0 < *(int *)(local_28[0] + 4)) {
        __n = *(int *)(local_28[0] + 4) * 0x1fc;
        if (param_5 <= __n) {
          __n = param_5;
        }
        memcpy(param_4,*(void **)(local_28[0] + 0x34),__n);
        uVar2 = l_apdb_mutex;
        *param_6 = *(undefined4 *)(iVar1 + 4);
        FUN_00407f30(uVar2);
        return 0;
      }
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : model->rrst_row_cnt=%d\n","apdb_get_specified_rrst",
               0x2ce1);
      }
      FUN_00407f30(l_apdb_mutex);
      return 0xffffffff;
    }
    if (apdb_warning_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
    uVar2 = 0x2cd9;
  }
  printf(__format,"apdb_get_specified_rrst",uVar2);
  return 0xffffffff;
}

