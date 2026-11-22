// func _apdb_add_item_to_list @ 005ff16c size=844

undefined4 _apdb_add_item_to_list(int *param_1,int *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int local_20 [3];
  
  if (apdb_debug_switch == 0) {
    iVar1 = *param_1;
  }
  else {
    printf("[APDB_DEBUG]%s()/line %d : enter _apdb_add_item_to_list\n","_apdb_add_item_to_list",
           0x1d29);
    iVar1 = *param_1;
  }
  local_20[0] = 0;
  if (iVar1 != 0) {
    cJSON_Delete();
  }
  iVar1 = cJSON_CreateObject();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    if (apdb_err_switch == 0) goto LAB_005ff35c;
    __format = "[APDB_ERROR]%s()/line %d : Failed create json obj\n";
    uVar2 = 0x1d35;
  }
  else {
    if (*param_2 != 0) {
      uVar5 = __floatsidf();
      local_20[0] = cJSON_CreateNumber((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      if (local_20[0] == 0) {
        local_20[0] = 0;
        if (apdb_err_switch == 0) goto LAB_005ff35c;
        __format = "[APDB_ERROR]%s()/line %d : failed to create json\n";
        uVar2 = 0x1d40;
        goto LAB_005ff440;
      }
      cJSON_AddItemToObject(*param_1,"id",local_20[0]);
      local_20[0] = 0;
    }
    if (*(char *)(param_2 + 2) != '\0') {
      local_20[0] = cJSON_CreateString(param_2 + 2);
      if (local_20[0] == 0) {
        local_20[0] = 0;
        if (apdb_err_switch == 0) goto LAB_005ff35c;
        __format = "[APDB_ERROR]%s()/line %d : failed to create json\n";
        uVar2 = 0x1d4d;
        goto LAB_005ff440;
      }
      cJSON_AddItemToObject(*param_1,"ap_name",local_20[0]);
      local_20[0] = 0;
    }
    uVar5 = __floatsidf(param_2[1]);
    local_20[0] = cJSON_CreateNumber((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
    if (local_20[0] == 0) {
      local_20[0] = 0;
      if (apdb_err_switch == 0) goto LAB_005ff35c;
      __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
      uVar2 = 0x1d59;
    }
    else {
      cJSON_AddItemToObject(*param_1,"vendor",local_20[0]);
      local_20[0] = 0;
      local_20[0] = cJSON_CreateArray();
      if (param_2[0x14] != 0) {
        if (local_20[0] == 0) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : failed to create json\n","_apdb_add_fwid_to_list",
                   0x1cf1);
          }
          if (apdb_err_switch == 0) goto LAB_005ff35c;
          __format = "[APDB_ERROR]%s()/line %d : failed to get fwid json\n";
          uVar2 = 0x1d64;
          goto LAB_005ff440;
        }
        FUN_00408570(param_2[0x14],add_fwid_hash_node,local_20[0]);
      }
      if (local_20[0] == 0) {
        iVar1 = param_2[0x15];
      }
      else {
        cJSON_AddItemToObject(*param_1,"fwid_list");
        local_20[0] = 0;
        iVar1 = param_2[0x15];
      }
      iVar4 = param_2[0x13];
      if ((iVar1 == 0) || (iVar4 < 1)) {
LAB_005ff2cc:
        if (local_20[0] == 0) {
          return 0;
        }
        cJSON_AddItemToObject(*param_1,"ap_list");
        return 0;
      }
      if (local_20[0] != 0) {
        cJSON_Delete();
      }
      local_20[0] = cJSON_CreateArray();
      if (local_20[0] != 0) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          _apdb_add_ap_to_aplist(local_20,iVar1);
          iVar1 = iVar1 + 0x168;
        } while (iVar3 != iVar4);
        goto LAB_005ff2cc;
      }
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : failed to create json obj\n",
               "_apdb_add_apdb_list_to_item",0x1d12);
      }
      if (apdb_err_switch == 0) goto LAB_005ff35c;
      __format = "[APDB_ERROR]%s()/line %d : failed to get apdb list json\n";
      uVar2 = 0x1d73;
    }
  }
LAB_005ff440:
  printf(__format,"_apdb_add_item_to_list",uVar2);
LAB_005ff35c:
  if (local_20[0] != 0) {
    cJSON_Delete();
  }
  return 0xffffffff;
}

