// func add_fwid_hash_node @ 005fa780 size=472

void add_fwid_hash_node(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined1 auStack_40 [40];
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : enter add_fwid_hash_node\n","add_fwid_hash_node",0x1caa);
  }
  memset(auStack_40,0,0x23);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (apdb_err_switch == 0) {
      return;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : para is null!\n";
    uVar5 = 0x1cb4;
LAB_005fa898:
    printf(pcVar4,"add_fwid_hash_node",uVar5);
  }
  else {
    iVar1 = cJSON_CreateObject();
    FUN_004084f0(param_1,0x10,auStack_40);
    iVar2 = cJSON_CreateString(auStack_40);
    if (iVar2 == 0) {
      if (apdb_err_switch != 0) {
        pcVar4 = "[APDB_ERROR]%s()/line %d : failed create json obj\n";
        uVar5 = 0x1cbe;
LAB_005fa910:
        printf(pcVar4,"add_fwid_hash_node",uVar5);
      }
    }
    else {
      uVar6 = __floatsidf(*(undefined4 *)(param_1 + 0x10));
      iVar3 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      if (iVar3 != 0) {
        cJSON_AddItemToObject(iVar1,&DAT_006fc224,iVar2);
        cJSON_AddItemToObject(iVar1,"ap_index",iVar3);
        cJSON_AddItemToArray(param_2,iVar1);
        if (apdb_debug_switch == 0) {
          return;
        }
        pcVar4 = "[APDB_DEBUG]%s()/line %d : leave add_fwid_hash_node\n";
        uVar5 = 0x1ccd;
        goto LAB_005fa898;
      }
      if (apdb_err_switch != 0) {
        pcVar4 = "[APDB_ERROR]%s()/line %d : failed to create json obj\n";
        uVar5 = 0x1cc5;
        goto LAB_005fa910;
      }
    }
    if (iVar1 != 0) {
      cJSON_Delete(iVar1);
    }
    if (iVar2 != 0) {
      cJSON_Delete(iVar2);
    }
  }
  return;
}

