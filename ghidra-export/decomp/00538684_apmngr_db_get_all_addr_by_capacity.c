// func apmngr_db_get_all_addr_by_capacity @ 00538684 size=404

undefined4
apmngr_db_get_all_addr_by_capacity
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  uint local_22c;
  uint *local_228;
  uint local_224 [130];
  
  memset(local_224,0,0x200);
  local_23c = 0;
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = (uint *)0x0;
  if ((param_5 < 0x81) && (param_1 != 0)) {
    puVar3 = (uint *)&stack0x00000014;
    uVar5 = 0;
    puVar1 = local_224;
    if (param_5 != 0) {
      do {
        uVar4 = *puVar3;
        *puVar1 = uVar4;
        puVar1 = puVar1 + 1;
        if (0x5f < uVar4) {
          if (apmngr_debug_switch == '\0') {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          printf("[APMNGR_DEBUG]%s()/%d cap(%d) is illegal\n","apmngr_db_get_all_addr_by_capacity",
                 0x463,local_224[uVar5]);
          return 0xffffffff;
        }
        uVar5 = uVar5 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar5 != param_5);
    }
    local_228 = local_224;
    uVar6 = 0;
    local_23c = param_1;
    local_238 = param_2;
    local_234 = param_3;
    local_230 = param_4;
    local_22c = uVar5;
    apmngr_db_foreach_proc(0xffffffff,_apmngr_db_get_addr_by_capa,&local_23c);
  }
  else {
    uVar6 = 0xffffffff;
    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_get_all_addr_by_capacity",0x45a);
    }
  }
  return uVar6;
}

