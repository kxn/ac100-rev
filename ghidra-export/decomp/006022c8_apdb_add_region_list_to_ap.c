// func apdb_add_region_list_to_ap @ 006022c8 size=724

undefined4 apdb_add_region_list_to_ap(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char acStack_f0 [200];
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : apdb_add_region_list_to_ap ENTER\n",
           "apdb_add_region_list_to_ap",0x19e7);
  }
  memset(acStack_f0,0,200);
  iVar3 = *(int *)(param_2 + 0x164);
  if ((param_1 == 0) || (iVar6 = 0, iVar3 == 0)) {
    uVar4 = 0xffffffff;
    if (apdb_debug_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_DEBUG]%s()/line %d : the para is null\n";
    uVar2 = 0x19f1;
  }
  else {
    for (; iVar6 < (int)(uint)*(byte *)(iVar3 + 0x15); iVar6 = iVar6 + 1) {
      iVar1 = json_object_new_object();
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[APDB_ERROR]%s()/line %d : Failed create json_region_array_item_obj.\n";
        uVar2 = 0x1a00;
        goto LAB_00602530;
      }
      iVar5 = iVar6 * 0xc3;
      memset(acStack_f0,0,200);
      snprintf(acStack_f0,200,"%d",(uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar5));
      uVar4 = json_object_new_string(acStack_f0);
      json_object_object_add(iVar1,"region_code",uVar4);
      memset(acStack_f0,0,200);
      snprintf(acStack_f0,200,"%d",(uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar5 + 1));
      uVar4 = json_object_new_string(acStack_f0);
      json_object_object_add(iVar1,"name_len",uVar4);
      memset(acStack_f0,0,200);
      snprintf(acStack_f0,200,"%d",(uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar5 + 2));
      uVar4 = json_object_new_string(acStack_f0);
      json_object_object_add(iVar1,"ch_lst_len",uVar4);
      memset(acStack_f0,0,200);
      strncpy(acStack_f0,(char *)(*(int *)(iVar3 + 0x30) + iVar5 + 3),0x40);
      uVar4 = json_object_new_string(acStack_f0);
      json_object_object_add(iVar1,"region_name",uVar4);
      memset(acStack_f0,0,200);
      strncpy(acStack_f0,(char *)(*(int *)(iVar3 + 0x30) + iVar5 + 0x43),0x80);
      uVar4 = json_object_new_string(acStack_f0);
      json_object_object_add(iVar1,"region_ch_lst",uVar4);
      json_object_array_add(param_1,iVar1);
    }
    uVar4 = 0;
    if (apdb_debug_switch == 0) {
      return 0;
    }
    __format = "[APDB_DEBUG]%s()/line %d : apdb_add_region_list_to_ap success EXIT\n";
    uVar2 = 0x1a29;
  }
LAB_00602530:
  printf(__format,"apdb_add_region_list_to_ap",uVar2);
  return uVar4;
}

