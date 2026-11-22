// func apmngr_db_get_all_addr_by_sub_capacity @ 0053848c size=504

undefined4
apmngr_db_get_all_addr_by_sub_capacity
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
          int param_6)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint *puVar4;
  uint *local_248;
  int local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  uint local_234;
  int local_230;
  uint *local_22c;
  uint local_228 [129];
  
  memset(local_228,0,0x200);
  local_244 = 0;
  local_240 = 0;
  local_23c = 0;
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = (uint *)0x0;
  if (param_1 == 0) {
    if (apmngr_debug_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_get_all_addr_by_sub_capacity",0x47b);
      return 0xffffffff;
    }
  }
  else if (param_5 < 0x60) {
    puVar4 = local_228;
    iVar1 = 0;
    local_248 = (uint *)&stack0x00000018;
    while( true ) {
      if (param_6 <= iVar1) {
        local_22c = local_228;
        local_234 = param_5;
        local_230 = param_6;
        local_244 = param_1;
        local_240 = param_2;
        local_23c = param_3;
        local_238 = param_4;
        apmngr_db_foreach_proc(0xff7fffff,_apmngr_db_get_addr_by_sub_capa,&local_244);
        return 0;
      }
      *puVar4 = *local_248;
      puVar4 = puVar4 + 1;
      iVar2 = apmngr_db_check_sub_capability_valid(param_5);
      if (iVar2 == 0) break;
      iVar1 = iVar1 + 1;
      local_248 = local_248 + 1;
    }
    if (apmngr_debug_switch != '\0') {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_DEBUG]%s()/%d sub_cap(%d) is illegal\n";
      param_5 = local_228[iVar1];
      uVar3 = 0x48b;
      goto LAB_005385f4;
    }
  }
  else if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    __format = "[APMNGR_DEBUG]%s()/%d cap(%d) is illegal\n";
    uVar3 = 0x481;
LAB_005385f4:
    printf(__format,"apmngr_db_get_all_addr_by_sub_capacity",uVar3,param_5);
    return 0xffffffff;
  }
  return 0xffffffff;
}

