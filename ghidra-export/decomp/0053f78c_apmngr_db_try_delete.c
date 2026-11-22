// func apmngr_db_try_delete @ 0053f78c size=612

undefined4 apmngr_db_try_delete(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  void *__src;
  short sVar6;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined1 auStack_2f8 [684];
  int local_4c;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f8,0,0x2d8);
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  if ((((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
      ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) &&
     (param_2 != (uint *)0x0)) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar5 = param_1;
    if (49999 < param_1) {
      uVar5 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    iVar2 = g_apmngr_entry_array + uVar5 * 0x2d8;
    if (*(int *)(iVar2 + 0x1c) == 1) {
      *param_2 = 0;
      *param_2 = (uint)(*(int *)(iVar2 + 0x3c) == 0);
      sVar6 = -1;
      if (((*(int *)(iVar2 + 0x3c) == 0) && (*(int *)(iVar2 + 0xc) == 2)) &&
         (iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)(iVar2 + 0x298),auStack_2f8), iVar3 == 0)
         ) {
        if (local_4c == 0) {
          sVar6 = *(short *)(iVar2 + 0x298);
        }
        else {
          *param_2 = 0;
        }
      }
      __src = (void *)(iVar2 + 0x26c);
      local_310 = 0;
      local_30c = 0;
      local_308 = 0;
      local_304 = 0;
      local_300 = 0;
      memcpy(&local_310,__src,0x14);
      if (*param_2 == 0) {
        apmngr_db_active_ap_dec(param_1);
        apmngr_db_ap_run_state_update(param_1,0);
        memset(__src,0,0x14);
        memcpy(__src,&local_310,0x14);
      }
      else {
        apmngr_db_active_ap_dec(param_1);
      }
      uVar1 = apmngr_db_mutex;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      uVar4 = 0;
      FUN_00407f30(uVar1);
      if (sVar6 != -1) {
        apmngr_ap_try_delete(sVar6);
      }
    }
    else {
      uVar4 = 0xffffffff;
      FUN_00407f30(apmngr_db_mutex);
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_try_delete",0xbbd,param_1);
    }
  }
  return uVar4;
}

