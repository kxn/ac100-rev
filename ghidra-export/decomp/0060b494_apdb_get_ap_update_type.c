// func apdb_get_ap_update_type @ 0060b494 size=672

undefined4
apdb_get_ap_update_type
          (undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
          undefined4 param_6,void *param_7,void *param_8)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : Check model update type: %x\n\n","apdb_get_ap_update_type",
           0x2ae5,param_1);
  }
  if ((param_3 == 0) || (param_5 == 0)) {
    uVar6 = 3;
    if (apdb_warning_switch == 0) {
      return 3;
    }
    pcVar3 = "[APDB_WARNING]%s()/line %d : you haven\'t loaded new apdb item.\n";
    uVar4 = 0x2ae9;
  }
  else {
    if (param_2 != 0) {
      iVar1 = _apdb_ap_item_get_index_by_id_array(param_1,param_3,param_4);
      iVar5 = 0;
      iVar2 = _apdb_ap_item_get_index_by_id_array(param_1,param_5,param_6);
      if (iVar1 != -1) {
        param_3 = param_3 + iVar1 * 0x58;
        iVar5 = FUN_00407fa0(*(undefined4 *)(param_3 + 0x50),param_2);
        if (iVar5 != 0) {
          param_8 = (void *)(*(int *)(param_3 + 0x54) + *(int *)(iVar5 + 0x10) * 0x168);
        }
      }
      iVar1 = 0;
      if (iVar2 != -1) {
        param_5 = param_5 + iVar2 * 0x58;
        iVar1 = FUN_00407fa0(*(undefined4 *)(param_5 + 0x50),param_2);
        if (iVar1 != 0) {
          param_7 = (void *)(*(int *)(param_5 + 0x54) + *(int *)(iVar1 + 0x10) * 0x168);
        }
      }
      if (iVar5 == 0) {
        if (iVar1 == 0) {
          uVar6 = 3;
          if (apdb_warning_switch == 0) {
            return 3;
          }
          pcVar3 = "[APDB_WARNING]%s()/line %d : ap model id[0x%x] invalid.\n";
          uVar4 = 0x2b21;
        }
        else {
          uVar6 = 0;
          if (apdb_debug_switch == 0) {
            return 0;
          }
          pcVar3 = "[APDB_DEBUG]%s()/line %d : ap[0x%x] is new added.\n";
          uVar4 = 0x2b0a;
        }
      }
      else if (iVar1 == 0) {
        uVar6 = 1;
        if (apdb_debug_switch == 0) {
          return 1;
        }
        pcVar3 = "[APDB_DEBUG]%s()/line %d : ap[0x%x] is deleted.\n";
        uVar4 = 0x2b0f;
      }
      else {
        iVar1 = memcmp(param_8,param_7,0x10);
        if (iVar1 == 0) {
          uVar6 = 3;
          if (apdb_debug_switch == 0) {
            return 3;
          }
          pcVar3 = "[APDB_DEBUG]%s()/line %d : ap model id[0x%x] not change.\n";
          uVar4 = 0x2b16;
        }
        else {
          uVar6 = 2;
          if (apdb_debug_switch == 0) {
            return 2;
          }
          pcVar3 = "[APDB_DEBUG]%s()/line %d : ap model id[0x%x] update.\n";
          uVar4 = 0x2b1a;
        }
      }
      printf(pcVar3,"apdb_get_ap_update_type",uVar4,param_1);
      return uVar6;
    }
    uVar6 = 0xffffffff;
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar4 = 0x2aee;
  }
  printf(pcVar3,"apdb_get_ap_update_type",uVar4);
  return uVar6;
}

