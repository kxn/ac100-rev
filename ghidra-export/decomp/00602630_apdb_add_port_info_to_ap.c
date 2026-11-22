// func apdb_add_port_info_to_ap @ 00602630 size=600

undefined4 apdb_add_port_info_to_ap(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char local_40 [24];
  
  if (apdb_debug_switch == 0) {
    iVar3 = *(int *)(param_2 + 0x164);
  }
  else {
    printf("[APDB_DEBUG]%s()/line %d : apdb_add_port_info_to_ap ENTER\n","apdb_add_port_info_to_ap",
           0x1a4f);
    iVar3 = *(int *)(param_2 + 0x164);
  }
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  local_40[0x10] = '\0';
  local_40[0x11] = '\0';
  local_40[0x12] = '\0';
  local_40[0x13] = '\0';
  if ((param_1 == 0) || (iVar5 = 0, iVar3 == 0)) {
    uVar4 = 0xffffffff;
    if (apdb_debug_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_DEBUG]%s()/line %d : the para is null\n";
    uVar2 = 0x1a5a;
  }
  else {
    for (; iVar5 < (int)(uint)*(byte *)(iVar3 + 0x14); iVar5 = iVar5 + 1) {
      iVar1 = json_object_new_object();
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[APDB_ERROR]%s()/line %d : Failed create json_region_array_item_obj.\n";
        uVar2 = 0x1a6b;
        goto LAB_0060281c;
      }
      iVar6 = iVar5 * 8;
      local_40[0] = '\0';
      local_40[1] = '\0';
      local_40[2] = '\0';
      local_40[3] = '\0';
      local_40[4] = '\0';
      local_40[5] = '\0';
      local_40[6] = '\0';
      local_40[7] = '\0';
      local_40[8] = '\0';
      local_40[9] = '\0';
      local_40[10] = '\0';
      local_40[0xb] = '\0';
      local_40[0xc] = '\0';
      local_40[0xd] = '\0';
      local_40[0xe] = '\0';
      local_40[0xf] = '\0';
      local_40[0x10] = '\0';
      local_40[0x11] = '\0';
      local_40[0x12] = '\0';
      local_40[0x13] = '\0';
      snprintf(local_40,0x14,"%d",(uint)*(byte *)(*(int *)(iVar3 + 0x2c) + iVar6));
      uVar4 = json_object_new_string(local_40);
      json_object_object_add(iVar1,"phy_index",uVar4);
      local_40[0] = '\0';
      local_40[1] = '\0';
      local_40[2] = '\0';
      local_40[3] = '\0';
      local_40[4] = '\0';
      local_40[5] = '\0';
      local_40[6] = '\0';
      local_40[7] = '\0';
      local_40[8] = '\0';
      local_40[9] = '\0';
      local_40[10] = '\0';
      local_40[0xb] = '\0';
      local_40[0xc] = '\0';
      local_40[0xd] = '\0';
      local_40[0xe] = '\0';
      local_40[0xf] = '\0';
      local_40[0x10] = '\0';
      local_40[0x11] = '\0';
      local_40[0x12] = '\0';
      local_40[0x13] = '\0';
      snprintf(local_40,0x14,"%d",(uint)*(byte *)(*(int *)(iVar3 + 0x2c) + iVar6 + 1));
      uVar4 = json_object_new_string(local_40);
      json_object_object_add(iVar1,"phy_type",uVar4);
      local_40[0] = '\0';
      local_40[1] = '\0';
      local_40[2] = '\0';
      local_40[3] = '\0';
      local_40[4] = '\0';
      local_40[5] = '\0';
      local_40[6] = '\0';
      local_40[7] = '\0';
      local_40[8] = '\0';
      local_40[9] = '\0';
      local_40[10] = '\0';
      local_40[0xb] = '\0';
      local_40[0xc] = '\0';
      local_40[0xd] = '\0';
      local_40[0xe] = '\0';
      local_40[0xf] = '\0';
      local_40[0x10] = '\0';
      local_40[0x11] = '\0';
      local_40[0x12] = '\0';
      local_40[0x13] = '\0';
      snprintf(local_40,0x14,"%d",*(undefined4 *)(*(int *)(iVar3 + 0x2c) + iVar6 + 4));
      uVar4 = json_object_new_string(local_40);
      json_object_object_add(iVar1,"phy_speed",uVar4);
      json_object_array_add(param_1,iVar1);
    }
    uVar4 = 0;
    if (apdb_debug_switch == 0) {
      return 0;
    }
    __format = "[APDB_DEBUG]%s()/line %d : apdb_add_port_info_to_ap success EXIT\n";
    uVar2 = 0x1a86;
  }
LAB_0060281c:
  printf(__format,"apdb_add_port_info_to_ap",uVar2);
  return uVar4;
}

