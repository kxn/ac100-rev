// func apdb_get_hwver_name_by_id @ 0060b1a4 size=400

undefined4 apdb_get_hwver_name_by_id(undefined4 param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  short *local_e8;
  char acStack_e4 [208];
  
  local_e8 = (short *)0x0;
  memset(acStack_e4,0,200);
  if ((param_3 == (void *)0x0) || (param_4 < 200)) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : Input error.\n";
      uVar2 = 0x2a7c;
      goto LAB_0060b260;
    }
  }
  else if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar2 = 0x2a81;
      goto LAB_0060b260;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,&local_e8);
    if (iVar1 == 0) {
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      snprintf(acStack_e4,200,"%d.%d",(int)*local_e8,(int)local_e8[1]);
      memcpy(param_3,acStack_e4,200);
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : hwver:%s\n","apdb_get_hwver_name_by_id",0x2a93,param_3);
      }
      FUN_00407f30(l_apdb_mutex);
      return 0;
    }
    if (apdb_warning_switch != 0) {
      __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar2 = 0x2a87;
LAB_0060b260:
      printf(__format,"apdb_get_hwver_name_by_id",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

