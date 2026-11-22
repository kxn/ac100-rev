// func _trans_ap_entry_to_json @ 004b3c1c size=828

int _trans_ap_entry_to_json(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int extraout_v1;
  char *pcVar3;
  undefined4 uVar4;
  char acStack_1b8 [272];
  undefined1 auStack_a8 [20];
  undefined1 auStack_94 [120];
  
  memset(auStack_a8,0,0x84);
  if (param_1 == 0) {
    if (report_err_switch != 0) {
      pcVar3 = "[REPORT_ERROR]%s()/line %d : ap_entry is NULL.\n";
      uVar4 = 0xe5;
LAB_004b3edc:
      printf(pcVar3,"_trans_ap_entry_to_json",uVar4);
      return 0;
    }
  }
  else {
    iVar1 = apmngr_db_group_get_by_id(*(undefined2 *)(param_1 + 0x12),auStack_a8);
    if (iVar1 == 0) {
      iVar1 = json_object_new_object();
      if (iVar1 == 0) {
        if (report_err_switch != 0) {
          pcVar3 = "[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n";
          uVar4 = 0xf1;
          goto LAB_004b3edc;
        }
      }
      else {
        iVar2 = json_object_new_object();
        if (iVar2 != 0) {
          snprintf(acStack_1b8,0x100,"ap_list_%d",param_2);
          json_object_object_add(iVar1,acStack_1b8,iVar2);
          uVar4 = json_object_new_string(param_1 + 0x4e);
          json_object_object_add(iVar2,"entry_name",uVar4);
          FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                       *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                       *(undefined4 *)(param_1 + 0x27c),acStack_1b8,0x100,"---");
          uVar4 = json_object_new_string(acStack_1b8);
          json_object_object_add(iVar2,&DAT_00677c24,uVar4);
          snprintf(acStack_1b8,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48)
                   ,(uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
                   (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
                   (uint)*(byte *)(param_1 + 0x4d));
          uVar4 = json_object_new_string(acStack_1b8);
          json_object_object_add(iVar2,"mac",uVar4);
          uVar4 = json_object_new_string(auStack_94);
          json_object_object_add(iVar2,"group_name",uVar4);
          if (*(int *)(param_1 + 0x20) == 1) {
            pcVar3 = "active";
          }
          else {
            pcVar3 = "inactive";
          }
          uVar4 = json_object_new_string(pcVar3);
          json_object_object_add(iVar2,"status",uVar4);
          if (*(int *)(param_1 + 0x20) != 1) {
            return iVar1;
          }
          uVar4 = wsta_db_get_ap_sta_num(*(undefined2 *)(param_1 + 0x10));
          snprintf(acStack_1b8,0x100,"%d",uVar4);
          uVar4 = json_object_new_string(acStack_1b8);
          json_object_object_add(iVar2,"sta_num",uVar4);
          FUN_00407e70();
          snprintf(acStack_1b8,0x100,"%d",extraout_v1 - *(int *)(param_1 + 0x284));
          uVar4 = json_object_new_string(acStack_1b8);
          json_object_object_add(iVar2,"online_time",uVar4);
          return iVar1;
        }
        if (report_err_switch != 0) {
          printf("[REPORT_ERROR]%s()/line %d : malloc json obj failed.\n","_trans_ap_entry_to_json",
                 0xf7);
        }
        json_object_put(iVar1);
      }
    }
    else if (report_err_switch != 0) {
      pcVar3 = "[REPORT_ERROR]%s()/line %d : ap_entry get group_entry failed.\n";
      uVar4 = 0xeb;
      goto LAB_004b3edc;
    }
  }
  return 0;
}

