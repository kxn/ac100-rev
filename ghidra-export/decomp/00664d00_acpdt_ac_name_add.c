// func acpdt_ac_name_add @ 00664d00 size=352

undefined4 acpdt_ac_name_add(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_20;
  void *local_1c;
  
  local_20 = 0;
  local_1c = (void *)0x0;
  if (((param_1 == 0) || (param_2 == (void *)0x0)) || (param_3 == 0)) {
    if (g_acpdt_error != 0) {
      __format = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
      uVar2 = 0xbc;
      goto LAB_00664d84;
    }
  }
  else {
    local_1c = (void *)FUN_00408450(param_3 + 1,0xbf);
    if (local_1c != (void *)0x0) {
      memset(local_1c,0,param_3 + 1);
      local_20 = CONCAT22((short)param_3,local_20._2_2_);
      memcpy(local_1c,param_2,param_3);
      iVar1 = cw_service_msg_add(param_1,4,&local_20,0);
      if (iVar1 != -1) {
        FUN_00407df0(local_1c);
        return 0;
      }
      if (g_acpdt_error != 0) {
        printf("[ACPDT_ERROR] %32s() %05d: add ac name failed.\r\n","acpdt_ac_name_add",0xcd);
      }
      FUN_00407df0(local_1c);
      return 0xffffffff;
    }
    if (g_acpdt_error != 0) {
      __format = "[ACPDT_ERROR] %32s() %05d: malloc failed.\r\n";
      uVar2 = 0xc1;
LAB_00664d84:
      local_1c = (void *)0x0;
      printf(__format,"acpdt_ac_name_add",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

